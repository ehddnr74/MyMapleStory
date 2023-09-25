#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class InventoryScript : public Script
	{
	public:
		InventoryScript();
		~InventoryScript();

		struct ItemInfo {
			std::string name = "";
			int price;
			int cnt;

		};

		//enum class InventoryState
		//{
		//	OnInventory,
		//	CloseInventory,
		//};

		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;


		void SetPlayerScript(class PlayerScript* playerscript) { mPlayerScript = playerscript; }
		PlayerScript* GetPlayerScript() { return mPlayerScript; }

		void SetCameraScript(class CameraScript* cs) { mCameraScript = cs; }
		CameraScript* GetCameraScript() { return mCameraScript; }

		void Buying();

		void SetInventory(GameObject* it) { mInventory = it; }
		GameObject* GetInventory() { return mInventory; }


		void OnInventory();
		void CloseInventory();

	private:
		class PlayerScript* mPlayerScript;
		class CursorScript* mCursorScript;
		class CameraScript* mCameraScript;
		//Collider2D* cd;
		//InventoryState mInventoryState;
		Animator* at;
		Transform* tr;
		Vector3 pos;
		Vector3 InventoryPos;
		Vector3 CameraPos;
		Vector3 FinalPos;


		GameObject* mInventory;

		GameObject* RootaByssKey;
		

		Vector3 mLeftTop;
		//Vector3 OwnerPos;
		//Vector2 RealPos;

		std::vector<std::vector<Vector3>> mInventoryIndex;

		Vector3 mIndex1;
		Vector3 mIndex2;
		Vector3 mIndex3;
		Vector3 mIndex4;
		Vector3 mIndex5;
		Vector3 mIndex6;
		Vector3 mIndex7;
		Vector3 mIndex8;
		Vector3 mIndex9;
		Vector3 mIndex10;
		Vector3 mIndex11;
		Vector3 mIndex12;
		Vector3 mIndex13;
		Vector3 mIndex14;
		Vector3 mIndex15;
		Vector3 mIndex16;
		Vector3 mIndex17;
		Vector3 mIndex18;
		Vector3 mIndex19;
		Vector3 mIndex20;
		Vector3 mIndex21;
		Vector3 mIndex22;
		Vector3 mIndex23;
		Vector3 mIndex24;

	};
}

