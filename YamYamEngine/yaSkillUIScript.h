#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class SkillUIScript : public Script
	{
	public:
		SkillUIScript();
		~SkillUIScript();

		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void SetBladePuryUI(GameObject* bpu) { mBladePuryUI = bpu; }



	private:
		Animator* at;
		Transform* tr;
		Vector3 pos;
		Vector3 CameraPos;
		Vector3 MousePos;
		Vector3 MouseWorldPos;

		GameObject* mBladePuryUI;

		bool mBladePuryUIpicked;
		double pickedtime;
	};
}
