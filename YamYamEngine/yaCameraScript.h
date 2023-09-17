#pragma once
//#include "yaScript.h"
#include <yaScript.h>

namespace ya
{
	class CameraScript : public Script
	{
	public:
		virtual void Update() override;

		//virtual void OnCollisionEnter(Collider2D* other) override;
		//virtual void OnCollisionStay(Collider2D* other) override;
		//virtual void OnCollisionExit(Collider2D* other) override;

		void SetHavisScript(class HavisScript* hs) { mHavisScript = hs; }
		HavisScript* GetHavisScript() { return mHavisScript; }

		void SetInventory1(GameObject* i1) { mInventory1 = i1; }
		GameObject* GetInventory1() { return mInventory1; }

		void SetInventory2(GameObject* i2) { mInventory2 = i2; }
		GameObject* GetInventory2() { return mInventory2; }

		void SetInventory3(GameObject* i3) { mInventory3 = i3; }
		GameObject* GetInventory3() { return mInventory3; }

		void SetInventoryEtc(GameObject* etc) { mInventoryEtc = etc; }
		GameObject* GetInventoryEtc() { return mInventoryEtc; }

		void SetInventoryMeso(GameObject* inventorymeso) { mInventoryMeso = inventorymeso; }
		GameObject* GetInventoryMeso() { return mInventoryMeso; }

		void SetInventoryMesoBar(GameObject* inventorymesobar) { mInventoryMesoBar = inventorymesobar; }
		GameObject* GetInventoryMesoBar() { return mInventoryMesoBar; }


	private:
		class HavisScript* mHavisScript;
		GameObject* mTarget;
		GameObject* mInventory1;
		GameObject* mInventory2;
		GameObject* mInventory3;
		GameObject* mInventoryEtc;
		GameObject* mInventoryMeso;
		GameObject* mInventoryMesoBar;
	
		Vector3 mPrevPos;
		Vector3 Ypos;
	};
}
