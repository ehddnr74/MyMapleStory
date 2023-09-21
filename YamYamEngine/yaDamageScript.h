#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class DamageScript : public Script
	{
	public:
		DamageScript();
		~DamageScript();

		enum class DamageState
		{
			Basic,
			Critical,
		};


		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;


	private:
		Animator* at;
		DamageState mDamageState;
		Transform* tr;
		Vector3 pos;

	private:
		void basic();
		void critical();


	private:
		int Damage;
		bool dmg;
		double dmgtime;

	};
}
