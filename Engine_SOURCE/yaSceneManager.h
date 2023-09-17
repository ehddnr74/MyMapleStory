#pragma once
#include "yaScene.h"

namespace ya
{
	class MpScript;
	class HpScript;
	class PlayerScript;
	class ExpScript;
	class CurSorScript;
	class InventoryScript;
	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render();
		static void Destroy();
		static void Release();
		
		template <typename T>
		static bool CreateScene(std::wstring name)
		{
			T* scene = new T();

			std::map<std::wstring, Scene*>::iterator iter
				= mScenes.find(name);

			if (iter != mScenes.end())
				return false;

			mScenes.insert(std::make_pair(name, scene));
			mActiveScene = scene;
			scene->Initialize();
			return true;
		}
		static Scene* LoadScene(std::wstring name);
		static Scene* GetActiveScene() { return mActiveScene; }

		static void SetPlayer(GameObject* player) { Player = player; }
		static GameObject* GetPlayer() { return Player; }

		static void SetInventory3(GameObject* it3) { Inventory3 = it3; }
		static GameObject* GetInventory3() { return Inventory3; }

		static void SetPlayerScript(PlayerScript* playerscript) { mPlayerScript = playerscript; }
		static PlayerScript* GetPlayerScript() { return mPlayerScript; }

		static void SetHpScript(HpScript* hpscript) { mHpScript = hpscript; }
		static HpScript* GetHpScript() { return mHpScript; }

		static void SetMpScript(MpScript* mpscript) { mMpScript = mpscript; }
		static MpScript* GetMpScript() { return mMpScript; }

		static void SetExpScript(ExpScript* expscript) { mExpScript = expscript; }
		static ExpScript* GetExpScript() { return mExpScript; }

		static void SetCursorScript(CurSorScript* cursorscript) { mCursorScript = cursorscript; }
		static CurSorScript* GetCursorScript() { return mCursorScript; }

		static void SetInventoryScript(InventoryScript* inventoryscript) { mInventoryScript = inventoryscript; }
		static InventoryScript* GetInventoryScript() { return mInventoryScript; }

	private:
		static Scene* mActiveScene;
		static std::map<std::wstring, Scene*> mScenes;
		static GameObject* Player;
		static GameObject* Inventory3;

		static class PlayerScript* mPlayerScript;
		static class HpScript* mHpScript;
		static class MpScript* mMpScript;
		static class ExpScript* mExpScript;
		static class CurSorScript* mCursorScript;
		static class InventoryScript* mInventoryScript;

	};
}
