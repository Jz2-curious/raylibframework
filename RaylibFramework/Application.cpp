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
	return {};
}
