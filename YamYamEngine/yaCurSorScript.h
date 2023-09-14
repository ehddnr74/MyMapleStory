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

		void SetHavisScript(class HavisScript* havis) { mHavisScript = havis; }
		HavisScript* GetHavisScript() { return mHavisScript; }

		Vector3 GetMouseWorldPos() {return MouseWorldPos;}


	private:
		void none();
		void click();

	private:
		Vector3 mPos;
		Vector3 MouseWorldPos;
		Animator* at;
		CursorState mCursorState;
		Transform* tr;

		GameObject* mCursor;
		bool CursorChange;

	private:
		class PlayerScript* mPlayerScript;
		class HavisScript* mHavisScript;

	private:
		bool havis;
		bool ShopExit;
		bool KeySelect;
		bool ShopBuy;

	};

}