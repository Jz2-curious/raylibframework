#include "RaylibFramework/Resources/Resource.h"

ResourceBase::ResourceBase(string path)
	: m_path{ std::move(path) }
{
}

ResourceBase::~ResourceBase() = default;

string ResourceBase::Path() const
{
	return m_path;
}
