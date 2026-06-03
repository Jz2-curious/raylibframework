#include "RaylibFramework/Window.h"

#include "RaylibFramework/Config.h"

Window::Window(PrivateKey ,const shared_ptr<Config>& config)
	: m_isOpen{ false }
{
	m_width = config->Get<int>("Window.Width");
	m_height = config->Get<int>("Window.Height");
	m_title = config->Get<string>("Application.Title");
	m_clrColor = config->Get<Color>("Window.ClrColor");
}

float Window::Width() const
{
	return static_cast<float>(m_width);
}

void Window::SetWidth(int w)
{
	m_width = w;
	SetWindowSize(m_width, m_height);
}

float Window::height() const
{
	return static_cast<float>(m_height);
}

void Window::SetHeight(int h)
{
	m_height = h;
	SetWindowSize(m_width, m_height);
}

string Window::Title() const
{
	return m_title;
}

void Window::SetTitle(const string& title)
{
	m_title = title;
	SetWindowTitle(m_title.c_str());
}

Color Window::ClrColor() const
{
	return m_clrColor;
}

void Window::SetClrColor(const Color& clrColor)
{
	m_clrColor = clrColor;
}

bool Window::IsOpen() const
{
	return !WindowShouldClose() && m_isOpen;
}

bool Window::Open()
{
	// Attempt to open the window with the correct title, width and height.
	InitWindow(m_width, m_height, m_title.c_str());

	// Store the ready state of the window
	m_isOpen = IsWindowReady();
	return m_isOpen;
}

void Window::BeginFrame() const
{
	// Start the draw loop and clear the screen with the clrColor.
	BeginDrawing();
	ClearBackground(m_clrColor);
}

void Window::EndFrame() const
{
	EndDrawing();
}

void Window::Close()
{
	// Mark the window as closed and then close it.
	m_isOpen = false;
	CloseWindow();
}
