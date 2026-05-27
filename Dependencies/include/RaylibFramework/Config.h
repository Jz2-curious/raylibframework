#pragma once

#include <string>
#include <RaylibFramework/RaylibFramework.h>
#include <RaylibFramework/RaylibJson.h>

using std::string;

/**
 * @brief Loads and provides typed access to a named JSON configuration file.
 *
 * Config reads a JSON file by name on construction and exposes its values
 * through a typed Get() accessor. The file is loaded once via Load() and
 * cached for the lifetime of the object.
 */
class DLL Config
{
public:
	/**
	 * @brief Constructs a Config and loads the associated JSON file.
	 * @param name The name of the configuration file to load, without extension.
	 */
	explicit Config(string name);

public:
	/**
	 * @brief Retrieves a value from the configuration by key, cast to the requested type.
	 *
	 * @tparam T   The type to retrieve the value as.
	 * @param  id  The key identifying the value within the JSON file.
	 * @return     The value associated with @p id, interpreted as type T.
	 */
	template<typename T>
	T Get(const string& id);

private:
	/** @brief The name of the configuration file, without extension. */
	string m_name;

	/** @brief The parsed JSON data loaded from the configuration file. */
	Json m_json;

private:
	/**
	 * @brief Reads and parses the JSON configuration file into m_json.
	 *
	 * Called once during construction. The filename is derived from m_name.
	 */
	void Load();

};

#include "Config.inl"
