#include "RaylibFramework/Resources/TextureResource.h"

TextureResource::TextureResource(const string& path)
	: Resource{ path, UnloadTexture }
{
}

void TextureResource::Load()
{
	m_resource = std::make_shared<Texture2D>(LoadTexture(Path().c_str()));
}
