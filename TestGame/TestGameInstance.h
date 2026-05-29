#pragma once

#include <RaylibFramework/GameInstance.h>

class TestGameInstance : public GameInstance
{
public:
	TestGameInstance() = default;

public:
	void Init() override;
	void Shutdown() override;
	void Tick(float dt) override;
	void Render() override;

};