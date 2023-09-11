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

		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void OnInventory();

	private:
		Animator* at;
		Transform* tr;
		Vector3 pos;
	};
}

