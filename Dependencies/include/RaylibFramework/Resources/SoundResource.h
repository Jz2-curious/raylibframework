#pragma once

#include <raylib/raylib.h>
#include <RaylibFramework/RaylibFramework.h>
#include <RaylibFramework/Resources/Resource.h>

/**
 * @brief A Resource specialisation for loading and managing Sound assets.
 *
 * Implements the Load() interface to read a sound file from disk using
 * the path provided at construction.
 */
class DLL SoundResource : public Resource<Sound>
{
public:
	/**
	 * @brief Constructs a SoundResource and loads the sound from the given path.
	 * @param path The file path of the sound asset to load.
	 */


protected:
	/**
	 * @brief Loads the sound from disk and stores it in m_resource.
	 *
	 * Reads the file at Path() and populates m_resource with the resulting
	 * Sound. Called once during construction.
	 */


};

