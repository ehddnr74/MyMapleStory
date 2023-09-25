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

		void SetCursorScript(class CursorScript* cs) { mCursorScript = cs; }
		CursorScript* GetCursorScript() { return mCursorScript; }

		void SetHavisScript(class HavisScript* hs) { mHavisScript = hs; }
		HavisScript* GetHavisScript() { return mHavisScript; }

		void SetInventoryScript(class InventoryScript* is) { mInventoryScript = is; }
		InventoryScript* GetInventoryScript() { return mInventoryScript; }


		void SetInventory(GameObject* it) { mInventory = it; }
		void SetInventoryBtn1(GameObject* ib1) { mInventoryBtn1 = ib1; }

	private:
		class HavisScript* mHavisScript;
		class InventoryScript* mInventoryScript;
		class CursorScript* mCursorScript;
		GameObject* mTarget;


		GameObject* mInventory;
		GameObject* mInventoryBtn1;
	
		Vector3 mPrevPos;
		Vector3 Ypos;
	};
}
