//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class BladeTornadoScript : public Script
	{
	public:
		BladeTornadoScript();
		~BladeTornadoScript();

		enum class SkillState
		{
			BladeTornado,
			RightBladeTornado,
		};


		virtual void Initialize() override;
		virtual void Update() override;

		void SetRightBladeTornado(bool rbt) { Rightbladetornado = rbt; }

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void SetMushRoom(GameObject* mr) { MushRoom = mr; }
		GameObject* GetMushRoom() { return MushRoom; }

	private:
		Animator* at;
		SkillState mSkillState;
		Transform* tr;
		Vector3 pos;

		Vector3 BladePos;

	private:
		void bladetornado();
		void rightbladetornado();



	private:
		bool Leftbladetornado;
		bool Rightbladetornado;

		double bladetornadotime1;
		bool bladetornadotime2;

		bool DamageView;
		bool DamageView2;
		bool DamageView3;
		bool DamageView4;
		bool DamageView5;
		bool DamageView6;
		bool DamageView7;
		bool DamageView8;
		bool DamageView9;
		bool DamageView10;
		bool DamageView11;
		bool DamageView12;
		bool DamageView13;

		bool Stay;

		double Attackingtime;

		GameObject* MushRoom;

		bool ta1;
		bool ta2;
		bool ta3;
		bool ta4;
		bool ta5;
		bool ta6;
	};
}
