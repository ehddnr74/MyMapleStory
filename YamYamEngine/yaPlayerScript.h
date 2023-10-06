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
			BladePury,
			BladeTornado,
			KarmaPury,
			PhantomBlow,
			Jump,
			DoubleJump,
			Alert,
			Die,
		};

		virtual void Initialize() override;
		virtual void Update() override;
;
		void CreateLeftDoubleJump();
		void CreateRightDoubleJump();
		void CreatePhantomBlow();
		void CreatePhantomBlowSmoke();
		void CreateRightPhantomBlow();
		void CreateRightPhantomBlowSmoke();
		void CreatePhantomBlowHitEffect(GameObject* Monster, Vector3(pos));
		void CreateBladeTornado();
		void CreateRightBladeTornado();
		void CreateBladeTornadoHitEffect(GameObject* Monster, Vector3(pos));
		void CreateBladePury();
		void CreateRightBladePury();
		void CreateBladePuryHitEffect(GameObject* Monster, Vector3(pos));
		void CreateCaremaPury();
		void CreateRightCaremaPury();
		void CreateCaremaPuryHitEffect(GameObject* Monster, Vector3(pos));
		void CreateSkillUI();
		void CloseSkillUI();

		void CreateBladeTornadoSkillCooltime();
		void CreateKarmaPurySkillCooltime();

		void CreateDamage(GameObject* Monster, Vector3 Pos);
		void CreateHitDamage(GameObject* Monster, Vector3 Pos);

		void CreateDeathPhrases();

		//void CreatePhantomBlow();
		//void CreateRightPhantomBlow();


		void SetPhantomBlow(GameObject* pb) { mPhantomBlow = pb; }
		void SetPhantomBlowSmoke(GameObject* pbsmoke) { mPhantomBlowSmoke = pbsmoke; }
		void SetBladeTornado(GameObject* bt) { mBladeTornado = bt; }
		void SetBladePury(GameObject* bp) { mBladePury = bp; }
		void SetCaremaPury(GameObject* cp) { mCaremaPury = cp; }
		void SetDoubleJump(GameObject* dj) { mDoubleJump = dj; }
		void SetSkillUI(GameObject* ss) { mSkillUI = ss; }
		void SetBladePuryUI(GameObject* bpu) { mBladePuryUI = bpu; }
		void SetPhantomBlowUI(GameObject* pbu) { mPhantomBlowUI = pbu; }
		void SetBladeTornadoUI(GameObject* btu) { mBladeTornadoUI = btu; }
		void SetKarmaPuryUI(GameObject* kpu) { mKarmaPuryUI = kpu; }
		
		void SetDeathPhrases(GameObject* deathphrases) { mDeathPhrases = deathphrases; }


		void SetBladePuryScript(class BladePuryScript* bps) { mBladePuryScript = bps; }
		void SetPhantomBlowScript(class PhantomBlowScript* pbs) { mPhantomBlowScript = pbs; }
		void SetPhantomBlowSmokeScript(class PhantomBlowSmokeScript* pbss) { mPhantomBlowSmokeScript = pbss; }
		void SetCaremaPuryScript(class CaremaPuryScript* cps) { mCaremaPuryScript = cps; }
		void SetBladeTornadoScript(class BladeTornadoScript* bts) { mBladeTornadoScript = bts; }
		void SetDoubleJumpScript(class DoubleJumpScript* djs) { mDoubleJumpScript = djs; }
		//void SetDamageScript(class DamageScript*dms) { mDamageScript = dms; }
		

		void SetHpScript(class HpScript* hpscript) { mHpScript = hpscript; }
		HpScript* GetHpScript() { return mHpScript; }

		void SetMpScript(class MpScript* mp) { mMpScript = mp; }
		MpScript* GetMpScript() { return mMpScript; }

		void SetExpScript(class ExpScript* exp) { mExpScript = exp; }
		ExpScript* GetExpScript() { return mExpScript; }

		void SetInventoryScript(class InventoryScript* is) { mInventoryScript = is; }
		InventoryScript* GetInventoryScript() { return mInventoryScript; }

		void SetCameraScript(class CameraScript* cs) { mCameraScript = cs; }
		CameraScript* GetCameraScript() { return mCameraScript; }

		void SetDamageScript(class DamageScript* ds) { mDamageScript = ds; }
		DamageScript* GetDamageScript() { return mDamageScript; }

		void SetHitDamageScript(class HitDamageScript* hs) { mHitDamageScript = hs; }
		HitDamageScript* GetHitDamageScript() { return mHitDamageScript; }

		void SetAttackDamage(int ad) {AttackDamage = ad; }
		int GetAttackDamage() {return AttackDamage;}

		void SetHitDamage(int hd) { HitDamage = hd; }
		int GetHitDamage() { return HitDamage; }

		//void SetHitDamage()

		int GetDir() { return dir; }

		bool GetPortal() { return portal; }
		void SetPortal(bool port) { portal = port; }

		Vector3 GetPos() { return pos; }


		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void SetOnShop(bool onshop) { OnShop = onshop; }

		//void SetDmg(int DMG) { dmg = DMG; }
		//int GetDmg() { return dmg; }

		void SetHit(bool playerhit) { hit = playerhit; }

		void SetEarthQuake(bool earthquake) { EarthQuake = earthquake; }
		bool GetDieCheck() { return DieCheck; }

		void BladeTornadoUI(bool tornadoui) { TornadoUI = tornadoui; }
		void KarmaPuryUI(bool puryui) { PuryUI = puryui; }

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
		void bladepury();
		void bladetornado();
		void karmapury();
		void phantomblow();
		void jump();
		void doublejump();
		void alert();
		void die();



	private:
		double attacktime;
		double jumptime;
		double alerttime;
		double pbtime;
		double bptime;
		double bttime;
		double cptime;
		double djtime;
		double dmgtime;
		double pbstime;

		bool hit;
		bool jum;
		bool isjump;
		bool jumpdouble;
		bool devide;
		bool portal;

		
		GameObject* mPhantomBlowSmoke;
		GameObject* mDoubleJump;
		GameObject* mPhantomBlow;
		GameObject* mBladeTornado;
		GameObject* mBladePury;
		GameObject* mCaremaPury;
		GameObject* mSkillUI;
		GameObject* mBladePuryUI;
		GameObject* mPhantomBlowUI;
		GameObject* mBladeTornadoUI;
		GameObject* mKarmaPuryUI;
		GameObject* mDeathPhrases;

		//GameObject* mBladeStorm;
		class PhantomBlowSmokeScript* mPhantomBlowSmokeScript;
		class BladePuryScript* mBladePuryScript;
		class PhantomBlowScript* mPhantomBlowScript;
		class CaremaPuryScript* mCaremaPuryScript;
		class BladeTornadoScript* mBladeTornadoScript;
		class DoubleJumpScript* mDoubleJumpScript;
		class DamageScript* mDamageScript;
		class HitDamageScript* mHitDamageScript;
		class PortalScript* mPortalScript;
		class HpScript* mHpScript;
		class MpScript* mMpScript;
		class ExpScript* mExpScript;
		class InventoryScript* mInventoryScript;
		class CameraScript* mCameraScript;
		

	private:
		bool inventory;
		bool OnShop;
		bool Oninventory;
		bool skillui;
		double skilluitime;
		bool TornadoUI;
		bool PuryUI;


		bool tornado;
		bool pury;
		double bladeTornadocooltime;
		double karmapurycooltime;
		GameObject* mInventory;

		double inventorytime;

	private:
		int meso;



		private:
			int AttackDamage;
			int HitDamage;

			double dietime;

			bool HitMushroom;
			bool HitFireImp;
			bool HitBanBan;
			bool HitBall;
			bool EarthQuake;

			bool DieCheck;

	};
}
