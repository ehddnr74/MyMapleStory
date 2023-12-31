#pragma once
//#include "yaScene.h"
#include "..\Engine_SOURCE\yaScene.h"

namespace ya
{
	class BanBanScene : public Scene
	{
	public:
		BanBanScene();
		virtual ~BanBanScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetPlayer(GameObject* player) { mPlayer = player; }
		GameObject* GetPlayer() { return mPlayer; }

		void SetPlayerScript(class PlayerScript* playerscript) { mPlayerScript = playerscript; }
		PlayerScript* GetPlayerScript() { return mPlayerScript; }


		void SetBanBanBG(GameObject* bg) { BanBanBG = bg; }
		GameObject* GetBanBanBG() { return BanBanBG; }

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		GameObject* mPlayer;
		class PlayerScript* mPlayerScript;
		class HpScript* mHpScript;
		class MpScript* mMpScript;
		class ExpScript* mExpScript;

		GameObject* BanBanBG;
	};
}
