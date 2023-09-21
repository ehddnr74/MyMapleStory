#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class SkillScript : public Script
	{
	public:
		SkillScript();
		~SkillScript();

		enum class SkillState
		{
			PhantomBlow,
			RightPhantomBlow,
			BladePury,
			RightBladePury,
			BladeTornado,
			RightBladeTornado,
			CaremaPury,
			RightCaremaPury,
			BladeStorm,
			RightBladeStorm,
		};


		virtual void Initialize() override;
		virtual void Update() override;

		void Complete();

		void SetRightPhantomBlow(bool rpb) { Rightphantomblow = rpb; }
		void SetLeftBladeTornado(bool lbt) { Leftbladetornado = lbt; }
		void SetRightBladeTornado(bool rbt) { Rightbladetornado = rbt; }
		void SetLeftBladePury(bool lbp) { Leftbladepury = lbp; }
	    void SetRightBladePury(bool rbp) { Rightbladepury = rbp; }
		void SetLeftCaremaPury(bool lcp) { Leftcaremapury = lcp; }
		void SetRightCaremaPury(bool rcp) { Rightcaremapury = rcp; }




		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		Animator* at;
		SkillState mSkillState;
		Transform* tr;
		Vector3 pos;

		Vector3 BladePos;

	private:
		void phantomblow();
		void rightphantomblow();
		void bladepury();
		void rightbladepury();
		void bladetornado();
		void rightbladetornado();
		void caremapury();
		void rightcaremapury();
		void bladestorm();
		void rightbladestorm();




	private:
		double phantomblowTime;
		bool Rightphantomblow;

		bool Leftbladetornado;
		bool Rightbladetornado;

		double bladetornadotime1;
		bool bladetornadotime2;

		bool Leftbladepury;
		bool Rightbladepury;

		bool Leftcaremapury;
		bool Rightcaremapury;

	};
}