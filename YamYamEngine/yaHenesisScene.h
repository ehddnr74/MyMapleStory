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

		void SetPlayerScript(class PlayerScript* mps) { mPlayerScript = mps; }
		PlayerScript* GetPlayerScript() { return mPlayerScript; }

	private:
		class PlayerScript* mPlayerScript;
		class Player* mPlayer;

	};
}