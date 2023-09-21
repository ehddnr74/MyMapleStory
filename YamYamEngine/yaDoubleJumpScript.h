#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class DoubleJumpScript : public Script
	{
	public:
		DoubleJumpScript();
		~DoubleJumpScript();

		enum class DoubleJumpState
		{
			LeftJump,
			RightJump,
		};


		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void SetRightDoubleJump(bool right) { Right = right; }

	private:
		Animator* at;
		DoubleJumpState mDoubleJumpState;
		Transform* tr;
		Vector3 pos;

	private:
		void leftjump();
		void rightjump();

	private:
		bool Right;
		double Effecttime;
	};
}
