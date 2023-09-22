//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class BladePuryHitEffectScript : public Script
	{
	public:
		BladePuryHitEffectScript();
		~BladePuryHitEffectScript();

		enum class HitEffectState
		{
			HitEffect,
		};

		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		void hiteffect();


	private:
		Animator* at;
		HitEffectState mHitEffectState;
		Transform* tr;
		Vector3 pos;

		double EffectTime;
	};
}
