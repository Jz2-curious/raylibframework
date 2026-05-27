#pragma once

#include <sstream>
#include <vector>

using std::stringstream;
using std::vector;

template <typename T>
T Config::Get(const string& id)
{
	// Simple helper lambda function to split a string into its parts by '.'
	auto splitStr = [](const string& str) -> vector<string>
		{
			vector<string> result;
			stringstream stream(str);
			string item;

			// Iterate over each element to the next '.'
			while (std::getline(stream, item, '.'))
			{
				result.emplace_back(item);
			};

			return result;
		};

	// Start at the root of the json file
	Json json = m_json;

	// Split string into its parts and iterate over them
	for (string part : splitStr(id))
	{
		// try to get the child component
		if (json.contains(part))
		{
			json = json[part];
			continue;
		}

		// The part of the id we are looking for doesn't exist, so return default.
		return T{};
	}

	// Return the node data if it was found, otherwise the default value
	return json.is_null() ? T{} : json.get<T>();
}