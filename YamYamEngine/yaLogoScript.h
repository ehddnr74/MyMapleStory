#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class LogoScript : public Script
	{
	public:
		LogoScript();
		~LogoScript();

		enum class LogoState
		{
			Wizet1,
			Wizet2,
			End,
		};

		void CreateWhiteBG();

		void CreateLogo();

		virtual void Initialize() override;
		virtual void Update() override;

		bool GetLogoEnd() { return LogoEnd; }


	private:
		Animator* at;
		LogoState mLogoState;
		Transform* tr;
		Vector3 pos;

	private:
		void wizet1();
		void wizet2();

	private:
		double wizettime;
		bool LogoEnd;
	};
}
