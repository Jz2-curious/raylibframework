#pragma once

#include <functional>
#include <memory>
#include <string>
#include <RaylibFramework/RaylibFramework.h>

using std::function;
using std::shared_ptr;
using std::string;

/**
 * @brief Non-templated base class for all managed resources.
 *
 * Stores the file path associated with a resource and defines the interface
 * for loading. Derived classes implement Load() to perform the actual
 * file-system read and populate their resource data.
 */
class DLL ResourceBase
{
public:
	/**
	 * @brief Constructs a ResourceBase with the given file path.
	 * @param path The file path of the resource to load.
	 */
	explicit ResourceBase(string path);

	virtual ~ResourceBase();

public:
	/**
	 * @brief Returns the file path associated with this resource.
	 * @return The path string provided at construction.
	 */
	[[nodiscard]] string Path() const;

protected:
	/**
	 * @brief Loads the resource from disk.
	 *
	 * Implemented by derived classes to read the file at Path() and
	 * populate the resource data. Called once after construction.
	 */
	virtual void Load() = 0;

private:
	/** @brief The file path of the resource on disk. */
	string m_path;

};

/**
 * @brief A typed wrapper around a managed resource of type @p TYPE.
 *
 * Extends ResourceBase with typed ownership of the loaded resource and an
 * unload callback invoked on destruction. The resource data is held in a
 * shared_ptr and accessed via Get().
 *
 * @tparam TYPE The underlying resource type (e.g. Texture2D, Sound).
 */
template<typename TYPE>
class Resource : public ResourceBase
{
public:
	/** @brief Callback type invoked with the resource value when it is unloaded. */
	typedef function<void(TYPE)> UnloadFunc;

public:
	/**
	 * @brief Constructs a Resource, loads it, and registers an unload callback.
	 * @param path     The file path of the resource to load.
	 * @param unloader A callback invoked with the resource value on destruction.
	 */
	Resource(const string& path, UnloadFunc unloader);

	/**
	 * @brief Destroys the resource, invoking the unload callback with the current value.
	 */
	~Resource() override;

public:
	/**
	 * @brief Returns a raw pointer to the loaded resource data.
	 * @return A non-owning pointer to the underlying TYPE instance, or nullptr if not loaded.
	 */
	TYPE* Get();

protected:
	/** @brief The loaded resource data, owned by this Resource. */
	shared_ptr<TYPE> m_resource;

private:
	/** @brief Callback invoked with the resource value when this object is destroyed. */
	UnloadFunc m_unloader;

};

#include "Resource.inl"
