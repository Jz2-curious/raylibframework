#include "TestGameInstance.h"

#include <raylib/raylib.h>

#include "RaylibFramework/Application.h"

void TestGameInstance::Init()
{
}

void TestGameInstance::Shutdown()
{
}

void TestGameInstance::Tick(float dt)
{
	if (IsKeyPressed(KEY_SPACE))
	{
		Application::Quit();
	}
}

void TestGameInstance::Render()
{
	DrawRectangle(0, 0, 50, 50, RED);
}
