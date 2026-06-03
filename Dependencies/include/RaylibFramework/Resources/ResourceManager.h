#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <RaylibFramework/RaylibFramework.h>

using std::shared_ptr;
using std::string;
using std::unordered_map;

class Config;
class ResourceBase;

/**
 * @brief Manages loading and retrieval of shared resources by identifier.
 *
 * ResourceManager is a static singleton populated by Application during startup
 * via Load(). Resources are keyed by string identifier and retrieved by type
 * through Find(). All resources are shared; repeated calls to Find() with the
 * same id return the same underlying instance.
 */
class DLL ResourceManager
{
	friend class Application;

public:
	/**
	 * @brief Retrieves a resource by identifier, cast to the requested type.
	 *
	 * @tparam RESOURCE The concrete Resource type to retrieve. Must derive from ResourceBase.
	 * @param  id       The string identifier of the resource to find.
	 * @return          A shared_ptr to the resource, or nullptr if not found or the
	 *                  cast fails.
	 */
	template<typename RESOURCE>
	static shared_ptr<RESOURCE> Find(string id);

private:
	/** @brief All loaded resources, keyed by their string identifier. */
	static unordered_map<string, shared_ptr<ResourceBase>> m_resources;

private:
	/**
	 * @brief Loads all resources in the folder described by the given configuration file.
	 *
	 * Called once by Application during startup. 
	 *
	 * @param config The configuration describing the location of the resources.
	 */
	static void Load(const shared_ptr<Config>& config);

};

#include "ResourceManager.inl"
