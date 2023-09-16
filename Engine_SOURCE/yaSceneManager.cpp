#include "yaSceneManager.h"
#include "..\YamYamEngine\yaPlayerScript.h"
#include "..\YamYamEngine\yaHpScript.h"
#include "..\YamYamEngine\yaMpScript.h"
#include "..\YamYamEngine\yaCurSorScript.h"
#include "..\YamYamEngine\yaInventoryScript.h"

//#include "yaPlayScene.h"

namespace ya
{
	Scene* SceneManager::mActiveScene = nullptr;
	std::map<std::wstring, Scene*> SceneManager::mScenes;
	GameObject* SceneManager::Player = nullptr;
	PlayerScript* SceneManager::mPlayerScript = nullptr;
	HpScript* SceneManager::mHpScript = nullptr;
	MpScript* SceneManager::mMpScript = nullptr;
	ExpScript* SceneManager::mExpScript = nullptr;
	CurSorScript* SceneManager::mCursorScript = nullptr;
	InventoryScript* SceneManager::mInventoryScript = nullptr;

	void SceneManager::Initialize()
	{
	}
	void SceneManager::Update()
	{
		mActiveScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}
	void SceneManager::Render()
	{
		mActiveScene->Render();
	}

	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}

	void SceneManager::Release()
	{
		for (auto& iter : mScenes)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	//bool SceneManager::CreateScene(std::wstring name, Scene* scene)
	//{
	//	std::map<std::wstring, Scene*>::iterator iter
	//		= mScenes.find(name);

	//	if (iter != mScenes.end())
	//		return false;

	//	mScenes.insert(std::make_pair(name, scene));
	//	scene->Initialize();
	//	return true;
	//}

	Scene* SceneManager::LoadScene(std::wstring name)
	{
		std::map<std::wstring, Scene*>::iterator iter
			= mScenes.find(name);

		if (iter == mScenes.end())
			return nullptr;

		mActiveScene->OnExit();

		std::vector<GameObject*> gameObjs
			= mActiveScene->GetDontDestroyGameObjects();
		
		mActiveScene = iter->second;

		for (GameObject* obj : gameObjs)
		{
			eLayerType type = obj->GetLayerType();
			mActiveScene->AddGameObject(type, obj);
		}
		mActiveScene->OnEnter();

		return iter->second;
	}
}
