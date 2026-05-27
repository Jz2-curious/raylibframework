#pragma once

#include <RaylibFramework/RaylibFramework.h>


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
public:
	/**
	 * @brief Retrieves a resource by identifier, cast to the requested type.
	 *
	 * @tparam RESOURCE The concrete Resource type to retrieve. Must derive from ResourceBase.
	 * @param  id       The string identifier of the resource to find.
	 * @return          A shared_ptr to the resource, or nullptr if not found or the
	 *                  cast fails.
	 */


private:
	/** @brief All loaded resources, keyed by their string identifier. */


private:
	/**
	 * @brief Loads all resources described by the given configuration file.
	 *
	 * Called once by Application during startup. Populates m_resources from
	 * the entries defined in @p config.
	 *
	 * @param config The configuration describing which resources to load.
	 */


};

#include "ResourceManager.inl"