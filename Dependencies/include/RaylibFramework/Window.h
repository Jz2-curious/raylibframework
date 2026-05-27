#pragma once

#include <memory>
#include <string>
#include <raylib/raylib.h>
#include <RaylibFramework/RaylibFramework.h>

using std::shared_ptr;
using std::string;

class Config;

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
	Window(const shared_ptr<Config>& config);

public:
	/**
	 * @brief Returns the current width of the window.
	 * @return The window width in pixels.
	 */
	[[nodiscard]] float Width() const;

	/**
	 * @brief Sets the width of the window.
	 * @param w The new window width in pixels.
	 */
	void SetWidth(int w);

	/**
	 * @brief Returns the current height of the window.
	 * @return The window height in pixels.
	 */
	[[nodiscard]] float height() const;

	/**
	 * @brief Sets the height of the window.
	 * @param h The new window height in pixels.
	 */
	void SetHeight(int h);

	/**
	 * @brief Returns the current window title.
	 * @return The title string displayed in the window title bar.
	 */
	[[nodiscard]] string Title() const;

	/**
	 * @brief Sets the window title.
	 * @param title The new title string to display in the title bar.
	 */
	void SetTitle(const string& title);

	/**
	 * @brief Returns the clear colour used to wipe the framebuffer each frame.
	 * @return The current clear colour.
	 */
	[[nodiscard]] Color ClrColor() const;

	/**
	 * @brief Sets the clear colour used to wipe the framebuffer each frame.
	 * @param clrColor The new clear colour.
	 */
	void SetClrColor(const Color& clrColor);

	/**
	 * @brief Checks whether the window has been requested to close.
	 *
	 * Returns false when the user has closed the window or the OS has
	 * signalled a shutdown, indicating the game loop should exit.
	 *
	 * @return @c false if the window should close, @c true otherwise.
	 */
	[[nodiscard]] bool IsOpen() const;

private:
	/** @brief The window width in pixels. */
	int m_width;
	/** @brief The window height in pixels. */
	int m_height;
	/** @brief The title string displayed in the title bar. */
	string m_title;
	/** @brief The colour used to clear the framebuffer each frame. */
	Color m_clrColor;
	/** @brief The open state of the window. */
	bool m_isOpen;

	// TODO: Change this back to private
public:
	/**
	 * @brief Opens and displays the window.
	 *
	 * Called by Application after construction. Must be called before any
	 * frame methods are invoked.
	 *
	 * @return @c true if the window was opened successfully, @c false otherwise.
	 */
	[[nodiscard]] bool Open();

	/**
	 * @brief Prepares the window for rendering a new frame.
	 *
	 * Clears the framebuffer with ClrColor() and begins the raylib drawing
	 * context. Must be paired with a corresponding call to EndFrame().
	 */
	void BeginFrame() const;

	/**
	 * @brief Finalises and presents the current frame.
	 *
	 * Ends the raylib drawing context and swaps the framebuffer. Must be
	 * called after BeginFrame() once all drawing for the frame is complete.
	 */
	void EndFrame() const;

	/**
	 * @brief Closes the window and releases its resources.
	 *
	 * Called by Application during shutdown. No frame methods should be
	 * invoked after this call.
	 */
	void Close();

};