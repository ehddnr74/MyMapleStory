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

		void SetHavisScript(class HavisScript* hs) { mHavisScript = hs; }
		HavisScript* GetHavisScript() { return mHavisScript; }


		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		GameObject* mPlayer;
		class HavisScript* mHavisScript;

	};
}