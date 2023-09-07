#pragma once
#include "..\Engine_SOURCE\yaScene.h"

namespace ya
{
	class RootaByssScene : public Scene
	{
	public:
		RootaByssScene();
		virtual ~RootaByssScene();



		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetPlayer(GameObject* player) { mPlayer = player; }
		GameObject* GetPlayer() { return mPlayer; }

		void SetPlayerScript(class PlayerScript* mps) { mPScript = mps; }
		PlayerScript* GetPlayerScript() { return mPScript; }

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		class PlayerScript* mPScript;
		GameObject* mPlayer;

	};
}