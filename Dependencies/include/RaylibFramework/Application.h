#pragma once

#include <cassert>
#include <memory>
#include <string>
#include <type_traits>
#include <RaylibFramework/RaylibFramework.h>
#include <RaylibFramework/ExitCode.h>
#include <RaylibFramework/GameInstance.h>
#include <RaylibFramework/Window.h>


#if _DEBUG
#define _CRDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

using std::shared_ptr;
using std::string;

class Config;

/**
 * @brief Manages the lifetime of the application and its core subsystems.
 *
 * Application is a singleton that owns the Window and the active GameInstance.
 * Only one Application may exist at a time. It is created and destroyed entirely
 * within a call to Open(), which blocks until the game loop exits.
 *
 * Typical usage:
 * @code
 * int main()
 * {
 *     return (int)Application::Open<MyGame>(1280, 720, "My Game", Color::black);
 * }
 * @endcode
 *
 * Copy and move construction and assignment are deleted; the singleton must not
 * be duplicated or transferred.
 */
class DLL Application
{
	/**
	 * @brief An empty token type used to restrict construction to trusted callers.
	 *
	 * Passed as the first argument to the public constructor in place of a private
	 * constructor. Since PrivateKey itself is private, only friends and members of
	 * this class can instantiate it, achieving the same effect.
	 */


	/**
	 * @brief Custom deleter for Application's shared_ptr, allowing the destructor to remain private.
	 *
	 * Passed to shared_ptr<Application> at construction time. shared_ptr invokes
	 * operator() in place of the default delete expression when the reference
	 * count reaches zero.
	 */


public:
	/**
	 * @brief Creates the application, runs the game loop, then destroys it.
	 *
	 * Asserts that no Application instance already exists, then constructs one,
	 * instantiates @p GAME as the active GameInstance, and enters the main loop
	 * via Run(). The Application and the game instance are destroyed before this
	 * function returns.
	 *
	 * @tparam GAME A concrete type derived from GameInstance to instantiate.
	 *
	 * @return The exit code produced by the game loop.
	 *
	 * @pre  No Application instance is currently alive.
	 * @post The Application singleton is destroyed and m_instance is null.
	 */
	template<typename GAME>
	static EExitCode Open();

	/**
	 * @brief Returns a shared_ptr to the active Application singleton.
	 *
	 * The returned shared_ptr should not be stored beyond immediate use.
	 * The singleton's lifetime is controlled entirely by Open(); holding a
	 * shared_ptr past the end of that call will prevent correct destruction.
	 *
	 * @return A shared_ptr to the current Application, or nullptr if none exists.
	 */
	static shared_ptr<Application> Instance();

	/**
	 * @brief Tells the application to close down safely this frame.
	 */
	static void Quit();

public:
	/**
	 * @brief Constructs the Application and opens the window.
	 *
	 * Not intended for direct use; call Open() to create and run an Application.
	 * The PrivateKey parameter ensures only Application itself can invoke this
	 * constructor.
	 *
	 */
	Application();

	/** @brief Copy construction is disabled; only one Application may exist. */
	Application(const Application&) = delete;

	/** @brief Move construction is disabled; the singleton must not be transferred. */
	Application(Application&&) = delete;

public:
	/**
	 * @brief Returns the Window owned by this application.
	 * @return A pointer to the active Window instance.
	 */
	[[nodiscard]] shared_ptr<Window> GetWindow() const;

public:
	/** @brief Copy assignment is disabled; only one Application may exist. */
	Application& operator=(const Application&) = delete;

	/** @brief Move assignment is disabled; the singleton must not be transferred. */
	Application& operator=(Application&&) = delete;

private:
	/** @brief The singleton Application instance. nullptr when no app is running. */
	static shared_ptr<Application> m_instance;

private:
	/** @brief The global engine config for this application. */
	shared_ptr<Config> m_config;

	/** @brief The window managed by this application. */
	shared_ptr<Window> m_window;

	/** @brief The active game instance managed by this application. */
	shared_ptr<GameInstance> m_game;

private:

	/**
	 * @brief Executes the main game loop until the game signals an exit.
	 * @return The exit code indicating why the loop terminated.
	 */
	[[nodiscard]] EExitCode Run() const;

};

template <typename GAME>
EExitCode Application::Open()
{
	// Ensure GAME inherits from the GameInstance type
	static_assert(std::is_base_of_v<GameInstance, GAME>, "GAME must derive from GameInstance!");

	// Validate that the open function has not already been called
	assert(m_instance == nullptr && "Cannot create a second instance of application!");

	// If we are in a debug build, enable memory leak detection
#if _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	// Create an instance of the game and application
	m_instance = shared_ptr<Application>(new Application);
	m_instance->m_game = std::make_shared<GAME>();

	// Run the application, gathering the exit code
	const EExitCode exitCode = m_instance->Run();

	// Clean up the application instance and return the exit code
	m_instance.reset(); // <-- reset calls the destructor and cleans the memory
	return exitCode;
}