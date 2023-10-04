//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class BladePuryScript : public Script
	{
	public:
		BladePuryScript();
		~BladePuryScript();

		enum class SkillState
		{
			BladePury,
			RightBladePury,
		};


		virtual void Initialize() override;
		virtual void Update() override;

		void SetRightBladePury(bool rbp) { Rightbladepury = rbp; }



		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		Animator* at;
		SkillState mSkillState;
		Transform* tr;
		Vector3 pos;

		Vector3 BladePos;

	private:
		void bladepury();
		void rightbladepury();




	private:
		bool Leftbladepury;
		bool Rightbladepury;

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

	};
}
