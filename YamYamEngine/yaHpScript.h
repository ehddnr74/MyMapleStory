#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class HpScript : public Script
	{
	public:
		HpScript();
		~HpScript();

		virtual void Initialize() override;
		virtual void Update() override;

		void OnDamage(float damage);
		void UpdateHpBar(float beforeHp, float afterHp);

		void SetHP(float hp) { HP = hp; }
		float GetHp() { return HP; }

	private:
		Animator* at;
		Transform* tr;
		Vector3 pos;

	private:
		bool trigger_UpdateHP;
		float lerpStart;
		float lerpEnd;
		float maxHP;
		float HP;
		Vector3 scale;
		
	};
}

