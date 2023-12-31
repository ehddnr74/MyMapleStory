#pragma once
#include "yaGameObject.h"
#include <yaScript.h>
#include <yaAnimation.h>

namespace ya
{
	class CurSorScript : public Script
	{
	public:
		CurSorScript();
		~CurSorScript();

		enum class CursorState
		{
			None,
			Click,
		};

		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void SetPlayerScript(class PlayerScript* playerscript) { mPlayerScript = playerscript; }
		PlayerScript* GetPlayerScript() { return mPlayerScript; }

		void SetCameraScript(class CameraScript* cs) { mCameraScript = cs; }
		CameraScript* GetCameraScript() { return mCameraScript; }

		void SetHavisScript(class HavisScript* havis) { mHavisScript = havis; }
		HavisScript* GetHavisScript() { return mHavisScript; }

		void SetShopToInventory(bool shoptoinventory) {ShopToInventory = shoptoinventory;}
		bool GetShopToInventory() { return ShopToInventory; }

		Vector3 GetMouseWorldPos() {return MouseWorldPos;}

		//bool GetInventoryClick() {return InventoryClick	;}


	private:
		void none();
		void click();

	private:
		Vector3 mPos;
		Vector3 MouseWorldPos;
		Vector3 FinalPos;
		Animator* at;
		CursorState mCursorState;
		Transform* tr;

		GameObject* mCursor;
		bool CursorChange;


	private:
		class PlayerScript* mPlayerScript;
		class CameraScript* mCameraScript;
		class HavisScript* mHavisScript;

	private:
		bool InventoryClick;
		bool havis;
		bool ShopToInventory;
		bool ShopExit;
		bool KeySelect;
		bool PortionSelect;
		bool ShopBuy;

		

	};

}