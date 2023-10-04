#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class PhantomBlowScript : public Script
	{
	public:
		PhantomBlowScript();
		~PhantomBlowScript();

		enum class SkillState
		{
			PhantomBlow,
			RightPhantomBlow,
		};


		virtual void Initialize() override;
		virtual void Update() override;

		void SetRightPhantomBlow(bool rpb) { Rightphantomblow = rpb; }

		void CreatePhantomBlowHitEffect();

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void SetMushroom(GameObject* mr) { MushRoom = mr; }
		GameObject* GetMushroom() { return MushRoom; }

	private:
		Animator* at;
		SkillState mSkillState;
		Transform* tr;
		Vector3 pos;

		GameObject* MushRoom;

	private:
		void phantomblow();
		void rightphantomblow();



	private:
		double phantomblowTime;
		bool Rightphantomblow;
		bool DamageView;
		bool DamageView2;
		bool DamageView3;
		bool DamageView4;
		bool DamageView5;
		bool DamageView6;
		bool DamageView7;
		bool DamageView8;
		bool DamageView9;
		bool DamageView10;
		bool DamageView11;
		bool DamageView12;
		bool DamageView13;

		int test;
	};
}
