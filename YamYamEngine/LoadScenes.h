#pragma once
#include "..\Engine_SOURCE\yaSceneManager.h"
#include "yaPlayScene.h"
#include "yaLogoScene.h"
#include "yaHenesisScene.h"
#include "yaRootaByssScene.h"
#include "yaEastGardenScene.h"
#include "yaBanBanScene.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\YamYamEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\YamYamEngine.lib")
#endif



//#include "..\YamYamEngine\\yaPlayScene.h"
//#include "yaSceneManager.h"
namespace ya
{
	void InitializeScenes()
	{
		PlayScene* playScene = new PlayScene();
		SceneManager::CreateScene<BanBanScene>(L"BanBanScene");
		SceneManager::CreateScene<EastGardenScene>(L"EastGardenScene");
		SceneManager::CreateScene<RootaByssScene>(L"RootaByssScene");
		SceneManager::CreateScene<HenesisScene>(L"HenesisScene");
		SceneManager::CreateScene<LogoScene>(L"LogoScene");
	}
}