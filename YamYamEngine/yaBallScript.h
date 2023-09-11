#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class BallScript : public Script
	{
	public:
		BallScript();
		~BallScript();

		enum class BallState
		{
			LeftBall,
			RightBall,
		};


		virtual void Initialize() override;
		virtual void Update() override;

		//void Complete();
		//void SetDir(bool right) { Right = right; }

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		BallState GetBallState() { return mBallState; }
		void SetBallState(BallState ballstate) { mBallState = ballstate; }

		void SetDir(bool right) { Right = right; }

	private:
		Animator* at;
		BallState mBallState;
		Transform* tr;
		Vector3 pos;

	private:
		void leftball();
		void rightball();

	private:
		bool Right;
	};
}
