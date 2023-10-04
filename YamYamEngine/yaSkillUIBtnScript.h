#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class SkillUIBtnScript : public Script
	{
	public:
		SkillUIBtnScript();
		~SkillUIBtnScript();

		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		Vector3 GetIndex1() { return mIndex1; }
		Vector3 GetIndex2() { return mIndex2; }
		Vector3 GetIndex3() { return mIndex3; }
		Vector3 GetIndex4() { return mIndex4; }
		Vector3 GetIndex5() { return mIndex5; }


		void test();


	private:
		Animator* at;
		Transform* tr;
		Vector3 CameraPos;
		Vector3 SlotPos;
		Vector3 mSize;
		Vector3 LeftTop;

		Vector3 mIndex1;
		Vector3 mIndex2;
		Vector3 mIndex3;
		Vector3 mIndex4;
		Vector3 mIndex5;


		bool testing;
	};
}
