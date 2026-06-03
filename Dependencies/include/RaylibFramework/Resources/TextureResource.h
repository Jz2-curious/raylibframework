#pragma once

#include <raylib/raylib.h>
#include <RaylibFramework/RaylibFramework.h>
#include <RaylibFramework/Resources/Resource.h>

/**
 * @brief A Resource specialisation for loading and managing Texture2D assets.
 *
 * Implements the Load() interface to read an image file from disk using
 * the path provided at construction.
 */
class DLL TextureResource : public Resource<Texture2D>
{
public:
	/**
	 * @brief Constructs a TextureResource and loads the texture from the given path.
	 * @param path The file path of the image asset to load.
	 */
	TextureResource(const string& path);

protected:
	/**
	 * @brief Loads the texture from disk and stores it in m_resource.
	 *
	 * Reads the file at Path() and populates m_resource with the resulting
	 * Texture2D. Called once during construction.
	 */
	void Load() override;

};