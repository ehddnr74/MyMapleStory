#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>

namespace ya
{
	class SkillCollDownScript : public Script
	{
	public:
		SkillCollDownScript();
		~SkillCollDownScript();

		enum class SkillState
		{
			BladeTornado,
			CaremaPury,
		};

		virtual void Initialize() override;
		virtual void Update() override;

		void SetKarmaPurySkillCooltime(bool karmapury) { KarmaPury = karmapury; }

	private:
		Animator* at;
		SkillState mSkillState;
		Transform* tr;
		Vector3 pos;

	private:
		void bladetornado();
		void caremapury();

		bool KarmaPury;

		double tornadocooltime;
		double purycooltime;
	};
}

