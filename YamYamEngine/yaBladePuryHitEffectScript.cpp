#include "yaBladePuryHitEffectScript.h"
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
	ya::BladePuryHitEffectScript::BladePuryHitEffectScript()
		: EffectTime(0.0f)
	{

	}
	BladePuryHitEffectScript::~BladePuryHitEffectScript()
	{

	}

	void BladePuryHitEffectScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> BladePuryHitEffect = Resources::Load<Texture>(L"BladePuryHitEffect", L"..\\Resources\\Texture\\BladePuryHitEffect.png");

		at->Create(L"BladePuryHitEffect", BladePuryHitEffect, Vector2(0.0f, 0.0f), Vector2(249.0f, 224.0f), 8, Vector2::Zero, 0.0875f);

		at->PlayAnimation(L"BladePuryHitEffect", true);

		mHitEffectState = HitEffectState::HitEffect;
	}
	void BladePuryHitEffectScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		switch (mHitEffectState)
		{

		case BladePuryHitEffectScript::HitEffectState::HitEffect:
			hiteffect();
			break;
		default:
			break;
		}
	}

	void BladePuryHitEffectScript::OnCollisionEnter(Collider2D* other)
	{
	}
	void BladePuryHitEffectScript::OnCollisionStay(Collider2D* other)
	{
	}
	void BladePuryHitEffectScript::OnCollisionExit(Collider2D* other)
	{
	}
	void BladePuryHitEffectScript::hiteffect()
	{
		EffectTime += Time::DeltaTime();

		if (EffectTime >= 0.7f)
		{
			EffectTime = 0.0f;
			object::Destroy(GetOwner());
		}
	}

}