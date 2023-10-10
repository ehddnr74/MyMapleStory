#pragma once
//#include "yaScene.h"
#include "..\Engine_SOURCE\yaScene.h"

namespace ya
{
	class EastGardenScene : public Scene
	{
	public:
		EastGardenScene();
		virtual ~EastGardenScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetPlayer(GameObject* player) { mPlayer = player; }
		GameObject* GetPlayer() { return mPlayer; }

		void SetPlayerScript(class PlayerScript* playerscript) { mPlayerScript = playerscript; }
		PlayerScript* GetPlayerScript() { return mPlayerScript; }

		void SetEastGarden(GameObject* bg) { EastGarden = bg; }
		GameObject* GetEastGarden() { return EastGarden; }


		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		GameObject* mPlayer;
		class PlayerScript* mPlayerScript;
		class MeshRenderer* mMesh;

		GameObject* EastGarden;

	};
}
