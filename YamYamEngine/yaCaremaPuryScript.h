#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>

namespace ya
{
	class CaremaPuryScript : public Script
	{
	public:
		CaremaPuryScript();
		~CaremaPuryScript();

		enum class SkillState
		{
			CaremaPury,
			RightCaremaPury,
		};


		virtual void Initialize() override;
		virtual void Update() override;

		void SetRightCaremaPury(bool rcp) { Rightcaremapury = rcp; }

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void SetMushRoom(GameObject* mr) { MushRoom = mr; }
		GameObject* GetMushRoom() { return MushRoom; }

	private:
		Animator* at;
		SkillState mSkillState;
		Transform* tr;
		Vector3 pos;

	private:
		void caremapury();
		void rightcaremapury();

	private:
		bool Leftcaremapury;
		bool Rightcaremapury;

		bool DamageView;
		//bool DamageView2;

		bool Stay;

		double Attackingtime;

		GameObject* MushRoom;

		bool ta2;
		bool ta3;
		bool ta4;
		bool ta5;
		bool ta6;
	};
}
