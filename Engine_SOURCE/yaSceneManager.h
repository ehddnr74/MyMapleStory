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
	class SkillUIScript;
	class SkillUIBtnScript;
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

		static void SetSkillSlot(GameObject* ss) { SkillSlot = ss; }
		static GameObject* GetSkillSlot() { return SkillSlot; }

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

		static void SetSkillUIScript(SkillUIScript* sus) { mSkillUIScript = sus; }
		static SkillUIScript* GetSkillUIScript() { return mSkillUIScript; }

		static void SetSkillUIBtnScript(SkillUIBtnScript* subs) { mSkillUIBtnScript = subs; }
		static SkillUIBtnScript* GetSkillUIBtnScript() { return mSkillUIBtnScript; }

	private:
		static Scene* mActiveScene;
		static std::map<std::wstring, Scene*> mScenes;
		static GameObject* Player;
		static GameObject* SkillSlot;


		static class PlayerScript* mPlayerScript;
		static class HpScript* mHpScript;
		static class MpScript* mMpScript;
		static class ExpScript* mExpScript;
		static class CurSorScript* mCursorScript;
		static class InventoryScript* mInventoryScript;
		static class SkillUIScript* mSkillUIScript;
		static class SkillUIBtnScript* mSkillUIBtnScript;

	};
}
