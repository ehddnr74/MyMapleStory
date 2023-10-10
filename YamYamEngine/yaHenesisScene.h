#pragma once
#include "..\Engine_SOURCE\yaScene.h"

namespace ya
{
	class HenesisScene : public Scene
	{
	public:
		HenesisScene();
		virtual ~HenesisScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

		void CreateDevide();

		void SetInventoryScript(class InventoryScript* its) { mInventoryScript = its; }
		InventoryScript* GetInventoryScript() { return mInventoryScript; }

		void SetPlayerScript(class PlayerScript* mps) { mPlayerScript = mps; }
		PlayerScript* GetPlayerScript() { return mPlayerScript; }

		void SetCameraScript(class CameraScript* cs) { mCameraScript = cs; }
		CameraScript* GetCameraScript() { return mCameraScript; }

		void SetSkillSlot(GameObject* ss) { Slot = ss; }
		GameObject* GetSkillSlot() { return Slot; }

		void SetSelas(GameObject* bg) { BG = bg; }
		GameObject* GetSelas() { return BG; }

	private:
		class PlayerScript* mPlayerScript;
		class CameraScript* mCameraScript;
		class InventoryScript* mInventoryScript;
		class Player* mPlayer;

		GameObject* Slot;

		GameObject* BG;


	};
}