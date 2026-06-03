#pragma once

#include <algorithm>

template <typename RESOURCE>
shared_ptr<RESOURCE> ResourceManager::Find(string id)
{
	static_assert(std::is_base_of_v<ResourceBase, RESOURCE>, "RESOURCE is not a valid resource type. ");

	// Convert the id to a lower string, making sure that all slashes are consistent
	std::ranges::replace(id, '\\', '/');
	std::ranges::transform(id, id.begin(), [](const char c)
		{
			return std::tolower(c);
		});

	// Validate this id is valid
	const auto it = m_resources.find(id);
	if (it != m_resources.end())
	{
		// Return the casted resource
		return std::dynamic_pointer_cast<RESOURCE>(it->second);
	}

	// No valid resource found, so return nullptr
	return nullptr;
}