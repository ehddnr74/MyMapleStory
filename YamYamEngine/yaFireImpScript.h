#pragma once
#include <yaScript.h>
#include <yaAnimation.h>

namespace ya
{
	class FireImpScript : public Script
	{
	public:
		FireImpScript();
		~FireImpScript();

		enum class FireImpState
		{
			Idle,
			Move,
			Attack,
			Hit,
			Die,
		};


		virtual void Initialize() override;
		virtual void Update() override;

		void Complete();

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void SetPlayerScript(class PlayerScript* playerscript) { mPlayerScript = playerscript; }
		PlayerScript* GetPlayerScript() { return mPlayerScript; }

		void Rand();

	private:
		Animator* at;
		FireImpState mFireImpState;
		Transform* tr;
		Vector3 pos;
		class Collider2D* cd;

	private:
		void RandDir();

		void Idle();
		void move();
		void attack();
		void hit();
		void die();

	private:
		class PlayerScript* mPlayerScript;

		double attacktime;
		double idletime;
		double movetime;
		double imptime;

		double randdirtime;



		double hittime;
		int dir; // 0 = ¿ÞÂÊ , 1 = ¿À¸¥ÂÊ


	};
}
