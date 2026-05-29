#include "RaylibFramework/Application.h"
#include "RaylibFramework/Config.h"


shared_ptr<Application> Application::m_instance;

shared_ptr<Application> Application::Instance()
{
	return m_instance;
}

void Application::Quit()
{
	// Force the close flag on the window to false
	m_instance->m_window->m_isOpen = false;
}

Application::Application()
	: m_config{ std::make_shared<Config>("Engine") }, m_game{ nullptr }
{
	m_window = std::make_shared<Window>(m_config);
}

shared_ptr<Window> Application::GetWindow() const
{
	return m_window;
}

EExitCode Application::Run() const
{
	// Attempt to open window, returning fail code if it does not succeed
	if (!m_window->Open())
	{
		return EExitCode::WindowFailedToOpen;
	}

	// Initialise the game instance
	m_game->Init();

	while (m_window->IsOpen())
	{
		// Tick the game with the current frame time
		const float dt = GetFrameTime();
		m_game->Tick(dt);

		m_window->BeginFrame();

		// Render the game
		m_game->Render();

		m_window->EndFrame();
	}

	// Shutdown the game instance and close the window
	m_game->Shutdown();
	m_window->Close();

	// Return success as the whole gameplay loop ran successfully.
	return EExitCode::Success;
}
