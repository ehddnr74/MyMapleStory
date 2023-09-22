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


		void CreateDamage(GameObject* Monster, Vector3 Pos);

		//void CreatePhantomBlow();
		//void CreateRightPhantomBlow();


		void SetPhantomBlow(GameObject* pb) { mPhantomBlow = pb; }
		void SetPhantomBlowSmoke(GameObject* pbsmoke) { mPhantomBlowSmoke = pbsmoke; }
		void SetBladeTornado(GameObject* bt) { mBladeTornado = bt; }
		void SetBladePury(GameObject* bp) { mBladePury = bp; }
		void SetCaremaPury(GameObject* cp) { mCaremaPury = cp; }
		void SetDoubleJump(GameObject* dj) { mDoubleJump = dj; }

		
		void SetBladePuryScript(class BladePuryScript* bps) { mBladePuryScript = bps; }
		void SetPhantomBlowScript(class PhantomBlowScript* pbs) { mPhantomBlowScript = pbs; }
		void SetPhantomBlowSmokeScript(class PhantomBlowSmokeScript* pbss) { mPhantomBlowSmokeScript = pbss; }
		void SetCaremaPuryScript(class CaremaPuryScript* cps) { mCaremaPuryScript = cps; }
		void SetBladeTornadoScript(class BladeTornadoScript* bts) { mBladeTornadoScript = bts; }
		void SetDoubleJumpScript(class DoubleJumpScript* djs) { mDoubleJumpScript = djs; }
		void SetDamageScript(class DamageScript*dms) { mDamageScript = dms; }
		

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




		int GetDir() { return dir; }

		bool GetPortal() { return portal; }

		Vector3 GetPos() { return pos; }

		void OnInventory();
		void CloseInventory();

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void SetOnShop(bool onshop) { OnShop = onshop; }
		void SetInventory(bool it) { inventory = it; }

		void SetOnInventory(bool oninventory) { Oninventory = oninventory; }
		bool GetOnInventory() { return Oninventory; }

		void SetInventory1(GameObject* inventory1) { mInventory1 = inventory1; }
		void SetInventory2(GameObject* inventory2) { mInventory2 = inventory2; }
		void SetInventory3(GameObject* inventory3) { mInventory3 = inventory3; }
		void SetInventoryEtc(GameObject* inventoryetc) { mInventoryEtc = inventoryetc; }
		void SetInventoryMeso(GameObject* inventorymeso) { mInventoryMeso = inventorymeso; }
		void SetInventoryMesoBar(GameObject* inventorymesobar) { mInventoryMesoBar = inventorymesobar; }

		//void SetDmg(int DMG) { dmg = DMG; }
		//int GetDmg() { return dmg; }

	

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

		//GameObject* mBladeStorm;
		class PhantomBlowSmokeScript* mPhantomBlowSmokeScript;
		class BladePuryScript* mBladePuryScript;
		class PhantomBlowScript* mPhantomBlowScript;
		class CaremaPuryScript* mCaremaPuryScript;
		class BladeTornadoScript* mBladeTornadoScript;
		class DoubleJumpScript* mDoubleJumpScript;
		class DamageScript* mDamageScript;
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
		GameObject* mInventory1;
		GameObject* mInventory2;
		GameObject* mInventory3;
		GameObject* mInventoryEtc;
		GameObject* mInventoryMeso;
		GameObject* mInventoryMesoBar;

		double inventorytime;

	private:
		int meso;

	};
}
