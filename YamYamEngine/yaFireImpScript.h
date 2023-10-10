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


		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void SetPlayerScript(class PlayerScript* playerscript) { mPlayerScript = playerscript; }
		PlayerScript* GetPlayerScript() { return mPlayerScript; }

		bool GetFireImpAttack() { return Attack; }

		void Rand();

		void SetDamage(int damage);

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
		int HP;
		class PlayerScript* mPlayerScript;

		double attacktime;
		double idletime;
		double movetime;
		double imptime;

		double randdirtime;

		int damage;

		bool Attack;
		bool diecheck;

		bool OnHit;

		double hittime;
		double dietime;

		double collidertime;
		bool attacksound;
		int dir; // 0 = ¿ÞÂÊ , 1 = ¿À¸¥ÂÊ


	};
}
