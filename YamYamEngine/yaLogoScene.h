#pragma once
//#include "yaScene.h"
#include "..\Engine_SOURCE\yaScene.h"

namespace ya
{
	class LogoScene : public Scene
	{
	public:
		LogoScene();
		virtual ~LogoScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetLogoScript(class LogoScript* logoscript) { mLogoScript = logoscript; }
		class LogoScript* GetLogoScript() { return mLogoScript; }
	private:
		class LogoScript* mLogoScript;

		double LoadSceneTime;


	};
}