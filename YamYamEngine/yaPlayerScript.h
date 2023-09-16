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

		void SetMpScript(class MpScript* mp) { mMpScript = mp; }
		MpScript* GetMpScript() { return mMpScript; }

		void SetExpScript(class ExpScript* exp) { mExpScript = exp; }
		ExpScript* GetExpScript() { return mExpScript; }

		void SetInventoryScript(class InventoryScript* is) { mInventoryScript = is; }
		InventoryScript* GetInventoryScript() { return mInventoryScript; }


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
		class MpScript* mMpScript;
		class ExpScript* mExpScript;
		class InventoryScript* mInventoryScript;

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
