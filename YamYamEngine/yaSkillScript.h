#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class SkillScript : public Script
	{
	public:
		SkillScript();
		~SkillScript();

		enum class SkillState
		{
			Devide,
			RightDevide,
		};


		virtual void Initialize() override;
		virtual void Update() override;

		void Complete();
		void SetDir(bool right) { Right = right; }

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		Animator* at;
		SkillState mSkillState;
		Transform* tr;
		Vector3 pos;

	private:
		void devide();
		void rightdevide();



	private:
		double DevideTime;
		bool Right;
	};
}