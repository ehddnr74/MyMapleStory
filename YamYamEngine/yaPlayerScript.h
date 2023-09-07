#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>
#include <yaRigidBody.h>

namespace ya
{
	class RigidBody;
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		enum class PlayerState
		{
			Idle,
			Walk,
			ProneStab,
			Attack,
			Jump,
			Alert,
		};


		virtual void Initialize() override;
		virtual void Update() override;

		void Complete();

		void CreateDevide();
		void CreateRightDevide();

		void SetDevide(GameObject* dv) { mDevide = dv; }
		void SetDevideScript(class SkillScript* mScript) { mSkillScript = mScript; }

		void SetHpScript(class HpScript* hpscript) { mHpScript = hpscript; }
		HpScript* GetHpScript() { return mHpScript; }


		int GetDir() { return dir; }

		bool GetPortal() { return portal; }

		Vector3 GetPos() { return pos; }


		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		Animator* at;
		RigidBody* mRigidBody;
		PlayerState mPlayerState;
		Transform* tr;
		Vector3 pos;
		Collider2D* cd;
		int dir; // 0 = ¿ÞÂÊ , 1 = ¿À¸¥ÂÊ

	private:
		void Idle();
		void walk();
		void pronestab();
		void attack();
		void jump();
		void alert();



	private:
		double attacktime;
		double jumptime;
		double alerttime;
		double devidetime;

		bool hit;
		bool jum;
		bool devide;
		bool portal;

		GameObject* mDevide;
		class SkillScript* mSkillScript;
		class PortalScript* mPortalScript;
		class HpScript* mHpScript;


	};
}
