#include "RaylibFramework/Resources/ResourceManager.h"

#include <filesystem>
#include <functional>
#include <iostream>
#include <RaylibFramework/Config.h>
#include <RaylibFramework/Resources/TextureResource.h>

using std::exception;
using std::function;

// Allows iteration of files and folders in a specified path
using Di = std::filesystem::directory_iterator;
// Allows iteration of files and folders in a specified path and their file tree
using Rdi = std::filesystem::recursive_directory_iterator;

using std::filesystem::directory_entry;
using std::filesystem::filesystem_error;

// Generate the list of resource factories (the things to create the resource types)
typedef function<ResourceBase* (const string&)> ResourceFactory;
static unordered_map<string, ResourceFactory> resourceFactories
{
	// first one is the id... in this case, the name of the folder "textures"
	// second one is the actual thing making the resource
	std::make_pair("textures", [](const string& path){ return new TextureResource{ path }; }),
	//std::make_pair("sounds", [](const string& path){ return new SoundResource{ path }; })
};

unordered_map<string, shared_ptr<ResourceBase>> ResourceManager::m_resources;

void ResourceManager::Load(const shared_ptr<Config>& config)
{
	// Load the main directory from the config
	const string contentDirectory = "./" + config->Get<string>("Application.ContentFolder") + "/";

	try
	{
		// Iterate over each directory in the content folder
		for (const directory_entry& resourceDirEntry : Di(contentDirectory))
		{
			// Ignore this item if it isn't a folder
			if (!resourceDirEntry.is_directory())
			{
				continue;
			}

			// Get the folder name as lower (for case sensitivity)
			string resourceFolder = resourceDirEntry.path().string().substr(contentDirectory.length());
			std::ranges::transform(resourceFolder, resourceFolder.begin(), [](const char c)
				{
					return std::tolower(c);
				});

			// Recursively iterate over each item inside this folder
			for (const directory_entry& resourceEntry : Rdi(resourceDirEntry.path().string() + "/"))
			{
				// Skip any directories
				if (resourceEntry.is_directory())
				{
					continue;
				}

				string entryPath = resourceEntry.path().string();

				try
				{
					// Attempt to generate the resource from the factories
					ResourceFactory factory = resourceFactories[resourceFolder];
					ResourceBase* resource = factory(entryPath);

					// Create the ID (as a lower string for safety)
					string id = entryPath.substr(contentDirectory.length());
					id = id.substr(0, id.find_last_of('.'));
					std::ranges::transform(id, id.begin(), [](const char c)
						{
							return std::tolower(c);
						});

					// Insert the item into the resource map
					m_resources[id] = shared_ptr<ResourceBase>(resource);
				}
				catch (const exception& e)
				{
					std::cerr << "Error: " << e.what() << "\n";
				}
			}
		}
	}
	catch (const filesystem_error& e)
	{
		// Log the error to the console.
		std::cerr << "Error: " << e.what() << "\n";
	}
}
