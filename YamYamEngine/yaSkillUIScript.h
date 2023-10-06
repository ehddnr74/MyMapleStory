#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class SkillUIScript : public Script
	{
	public:
		SkillUIScript();
		~SkillUIScript();

		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;



		void SetBladePuryUI(GameObject* bpu) { mBladePuryUI = bpu; }
		void SetPhantomBlowUI(GameObject* pbu) { mPhantomBlowUI = pbu; }
		void SetBladeTornadoUI(GameObject* btu) { mBladeTornadoUI = btu; }
		void SetKarmaPuryUI(GameObject* kpu) { mKarmaPuryUI = kpu; }

		void CreateBladePuryUI();
		void DestroyBladePuryUI();
		void SetBladePuryUI();

		void CreatePhantomBlowUI();
		void DestroyPhantomBlowUI();
		void SetPhantomBlowUI();

		void CreateBladeTornadoUI();
		void DestroyBladeTornadoUI();
		void SetBladeTornadoUI();

		void CreateKarmaPuryUI();
		void DestroyKarmaPuryUI();
		void SetKarmaPuryUI();
	


	private:
		Animator* at;
		Transform* tr;
		Vector3 pos;
		Vector3 CameraPos;
		Vector3 SlotPos;
		Vector3 MousePos;
		Vector3 MouseWorldPos;

		GameObject* mBladePuryUI;
		GameObject* mPhantomBlowUI;
		GameObject* mBladeTornadoUI;
		GameObject* mKarmaPuryUI;


		bool mBladePuryUIpicked;
		double pickedtime;
		bool BladePuryisSet;

		bool mPhantomBlowUIpicked;
		bool PhantomBlowisSet;

		bool mBladeTornadoUIpicked;
		bool BladeTornadoisSet;

		bool mKarmaPuryUIpicked;
		bool KarmaPuryisSet;
	};
}
