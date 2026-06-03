#include "TestGameInstance.h"

#include <raylib/raylib.h>

#include "RaylibFramework/Application.h"
#include "RaylibFramework/Resources/ResourceManager.h"
#include "RaylibFramework/Resources/TextureResource.h"

shared_ptr<TextureResource> crateTexture;

void TestGameInstance::Init()
{
	crateTexture = ResourceManager::Find<TextureResource>("textures/crate");
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
	Texture2D* texture = crateTexture->Get();

	DrawTexture(*texture, 0, 0, WHITE);
	DrawTexture(*texture, 255, 255, WHITE);
}
