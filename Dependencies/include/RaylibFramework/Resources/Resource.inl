#pragma once

template <typename TYPE>
Resource<TYPE>::Resource(const string& path, UnloadFunc unloader)
	: ResourceBase{ path }, m_unloader{ unloader }
{}

template <typename TYPE>
Resource<TYPE>::~Resource()
{
	// Unload the resource is the asset is deleted (this only happens on application close)
	if (m_resource)
	{
		m_unloader(*m_resource);
	}
}

template <typename TYPE>
TYPE* Resource<TYPE>::Get()
{
	// Load the resource if it hasn't been already
	if (!m_resource)
	{
		Load();
	}

	return m_resource.get();
}