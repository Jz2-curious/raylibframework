#include <RaylibFramework/Application.h>
#include "TestGameInstance.h"

int main()
{
	return static_cast<int>(Application::Open<TestGameInstance>());
}
