//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class PhantomBlowSmokeScript : public Script
	{
	public:
		PhantomBlowSmokeScript();
		~PhantomBlowSmokeScript();

		enum class SmokeState
		{
			LeftSmoke,
			RightSmoke,
		};

		virtual void Initialize() override;
		virtual void Update() override;

		void SetRightPhantomBlowSmoke(bool rs) { Rightsmoke = rs; }

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		void leftsmoke();
		void rightsmoke();

	private:
		Animator* at;
		SmokeState mSmokeState;
		Transform* tr;
		Vector3 pos;

		double EffectTime;

		bool Rightsmoke;
	};
}

