#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class HitDamageScript : public Script
	{
	public:
		HitDamageScript();
		~HitDamageScript();

		enum class DamageState
		{
			Basic,
		};


		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void SetHitDamage(int hitdam) { HitDamage = hitdam; }
		int GetHitDamage() { return HitDamage; }

	private:
		Animator* at;
		DamageState mDamageState;
		Transform* tr;
		Vector3 pos;

	private:
		void basic();


	private:
		int HitDamage;
		bool Hitdmg;
		double Hitdmgtime;

	};
}
