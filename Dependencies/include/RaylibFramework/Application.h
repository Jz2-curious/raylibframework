#pragma once

#include <RaylibFramework/RaylibFramework.h>

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


	/**
	 * @brief Returns a shared_ptr to the active Application singleton.
	 *
	 * The returned shared_ptr should not be stored beyond immediate use.
	 * The singleton's lifetime is controlled entirely by Open(); holding a
	 * shared_ptr past the end of that call will prevent correct destruction.
	 *
	 * @return A shared_ptr to the current Application, or nullptr if none exists.
	 */


	/**
	 * @brief Tells the application to close down safely this frame.
	 */


public:
	/**
	 * @brief Constructs the Application and opens the window.
	 *
	 * Not intended for direct use; call Open() to create and run an Application.
	 * The PrivateKey parameter ensures only Application itself can invoke this
	 * constructor.
	 *
	 */


	/** @brief Copy construction is disabled; only one Application may exist. */


	/** @brief Move construction is disabled; the singleton must not be transferred. */


public:
	/**
	 * @brief Returns the Window owned by this application.
	 * @return A pointer to the active Window instance.
	 */


public:
	/** @brief Copy assignment is disabled; only one Application may exist. */


	/** @brief Move assignment is disabled; the singleton must not be transferred. */


private:
	/** @brief The singleton Application instance. nullptr when no app is running. */


private:
	/** @brief The global engine config for this application. */


	/** @brief The window managed by this application. */


	/** @brief The active game instance managed by this application. */


private:

	/**
	 * @brief Executes the main game loop until the game signals an exit.
	 * @return The exit code indicating why the loop terminated.
	 */


};