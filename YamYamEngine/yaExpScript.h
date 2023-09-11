#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class ExpScript : public Script
	{
	public:
		ExpScript();
		~ExpScript();

		virtual void Initialize() override;
		virtual void Update() override;

		void OnDamage(float damage);
		void UpdateExpBar(float beforeHp, float afterHp);

	private:
		Animator* at;
		Transform* tr;
		Vector3 pos;

	private:
		bool trigger_UpdateEXP;
		float lerpStart;
		float lerpEnd;
		float maxEXP;
		float EXP;
		Vector3 scale;

	};
}
