#pragma once

#include <raylib/raylib.h>
#include <RaylibFramework/RaylibFramework.h>
#include <RaylibFramework/Resources/Resource.h>

/**
 * @brief A Resource specialisation for loading and managing Font assets.
 *
 * Implements the Load() interface to read a font file from disk using
 * the path provided at construction.
 */
class DLL FontResource : public Resource<Font>
{
public:
	/**
	 * @brief Constructs a FontResource and loads the font from the given path.
	 * @param path The file path of the font asset to load.
	 */


protected:
	/**
	 * @brief Loads the font from disk and stores it in m_resource.
	 *
	 * Reads the file at Path() and populates m_resource with the resulting
	 * Font. Called once during construction.
	 */


};
