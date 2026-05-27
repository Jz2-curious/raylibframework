#pragma once

#include <RaylibFramework/RaylibFramework.h>


/**
 * @brief Represents the OS window and its associated rendering surface.
 *
 * Window is created and owned exclusively by Application. Its private
 * constructor and frame management methods are accessible only to
 * Application via the friend declaration; external code may only query
 * and modify window properties through the public accessors.
 */
class DLL Window
{
	/**
	 * @brief An empty token type used to restrict construction to trusted callers.
	 *
	 * Passed as the first argument to the public constructor in place of a private
	 * constructor. Since PrivateKey itself is private, only friends and members of
	 * this class can instantiate it, achieving the same effect.
	 */


public:
	/**
	 * @brief Constructs and configures the window.
	 *
	 * Private; the Window is created exclusively by Application.
	 * Call Open() after construction to display the window.
	 *
	 * @param config The configuration used for this application.
	 */


public:
	/**
	 * @brief Returns the current width of the window.
	 * @return The window width in pixels.
	 */


	/**
	 * @brief Sets the width of the window.
	 * @param w The new window width in pixels.
	 */


	/**
	 * @brief Returns the current height of the window.
	 * @return The window height in pixels.
	 */


	/**
	 * @brief Sets the height of the window.
	 * @param h The new window height in pixels.
	 */


	/**
	 * @brief Returns the current window title.
	 * @return The title string displayed in the window title bar.
	 */


	/**
	 * @brief Sets the window title.
	 * @param title The new title string to display in the title bar.
	 */


	/**
	 * @brief Returns the clear colour used to wipe the framebuffer each frame.
	 * @return The current clear colour.
	 */


	/**
	 * @brief Sets the clear colour used to wipe the framebuffer each frame.
	 * @param clrColor The new clear colour.
	 */


	/**
	 * @brief Checks whether the window has been requested to close.
	 *
	 * Returns true when the user has closed the window or the OS has
	 * signalled a shutdown, indicating the game loop should exit.
	 *
	 * @return @c true if the window should close, @c false otherwise.
	 */


private:
	/** @brief The window width in pixels. */

	/** @brief The window height in pixels. */

	/** @brief The title string displayed in the title bar. */

	/** @brief The colour used to clear the framebuffer each frame. */

	/** @brief The open state of the window. */


private:
	/**
	 * @brief Opens and displays the window.
	 *
	 * Called by Application after construction. Must be called before any
	 * frame methods are invoked.
	 *
	 * @return @c true if the window was opened successfully, @c false otherwise.
	 */


	/**
	 * @brief Prepares the window for rendering a new frame.
	 *
	 * Clears the framebuffer with ClrColor() and begins the raylib drawing
	 * context. Must be paired with a corresponding call to EndFrame().
	 */


	/**
	 * @brief Finalises and presents the current frame.
	 *
	 * Ends the raylib drawing context and swaps the framebuffer. Must be
	 * called after BeginFrame() once all drawing for the frame is complete.
	 */


	/**
	 * @brief Closes the window and releases its resources.
	 *
	 * Called by Application during shutdown. No frame methods should be
	 * invoked after this call.
	 */


};