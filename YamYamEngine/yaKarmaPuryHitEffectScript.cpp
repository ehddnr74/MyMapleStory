#include "yaKarmaPuryHitEffectScript.h"
#include "yaPlayerScript.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaMushroomScript.h"
#include "yaCollider2D.h"
#include "yaObject.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"

namespace ya
{
	ya::KarmaPuryHitEffectScript::KarmaPuryHitEffectScript()
		: EffectTime(0.0f)
	{

	}
	KarmaPuryHitEffectScript::~KarmaPuryHitEffectScript()
	{

	}

	void KarmaPuryHitEffectScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> KarmaPuryHitEffect = Resources::Load<Texture>(L"KarmaPuryHitEffect", L"..\\Resources\\Texture\\KarmaPuryHitEffect.png");

		at->Create(L"KarmaPuryHitEffect", KarmaPuryHitEffect, Vector2(0.0f, 0.0f), Vector2(419.0f, 305.0f), 14, Vector2::Zero, 0.0928571428571429f);

		at->PlayAnimation(L"KarmaPuryHitEffect", true);

		mHitEffectState = HitEffectState::HitEffect;
	}
	void KarmaPuryHitEffectScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		switch (mHitEffectState)
		{

		case KarmaPuryHitEffectScript::HitEffectState::HitEffect:
			hiteffect();
			break;
		default:
			break;
		}
	}

	void KarmaPuryHitEffectScript::OnCollisionEnter(Collider2D* other)
	{
	}
	void KarmaPuryHitEffectScript::OnCollisionStay(Collider2D* other)
	{
	}
	void KarmaPuryHitEffectScript::OnCollisionExit(Collider2D* other)
	{
	}
	void KarmaPuryHitEffectScript::hiteffect()
	{
		EffectTime += Time::DeltaTime();

		if (EffectTime >= 1.3f)
		{
			EffectTime = 0.0f;
			object::Destroy(GetOwner());
		}
	}

}