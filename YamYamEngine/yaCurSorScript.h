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


	private:
		void none();
		void click();

	private:
		Vector3 mPos;
		Animator* at;
		CursorState mCursorState;
		Transform* tr;

		GameObject* mCursor;
		bool CursorChange;
	};

}