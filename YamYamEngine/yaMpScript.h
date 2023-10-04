#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class MpScript : public Script
	{
	public:
		MpScript();
		~MpScript();

		virtual void Initialize() override;
		virtual void Update() override;

		void OnDamage(float damage);
		void UpdateMpBar(float beforeHp, float afterHp);

		void SetMP(float mp) { MP = mp; }

	private:
		Animator* at;
		Transform* tr;
		Vector3 pos;

	private:
		bool trigger_UpdateMP;
		float lerpStart;
		float lerpEnd;
		float maxMP;
		float MP;
		Vector3 scale;

	};
}
