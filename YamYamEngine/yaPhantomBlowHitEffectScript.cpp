#include "yaPhantomBlowHitEffectScript.h"
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
	ya::PhantomBlowHitEffectScript::PhantomBlowHitEffectScript()
		: EffectTime(0.0f)
	{

	}
	PhantomBlowHitEffectScript::~PhantomBlowHitEffectScript()
	{

	}

	void PhantomBlowHitEffectScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> PhantomBlowHitEffect = Resources::Load<Texture>(L"PhantomBlowHitEffect", L"..\\Resources\\Texture\\PhantomBlowHitEffect.png");

		at->Create(L"PhantomBlowHitEffect", PhantomBlowHitEffect, Vector2(0.0f, 0.0f), Vector2(252.0f, 148.0f), 5, Vector2::Zero, 0.05f);

		at->PlayAnimation(L"PhantomBlowHitEffect", true);

		mHitEffectState = HitEffectState::HitEffect;
	}
	void PhantomBlowHitEffectScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		switch (mHitEffectState)
		{

		case PhantomBlowHitEffectScript::HitEffectState::HitEffect:
			hiteffect();
			break;
		default:
			break;
		}
	}

	void PhantomBlowHitEffectScript::OnCollisionEnter(Collider2D* other)
	{
	}
	void PhantomBlowHitEffectScript::OnCollisionStay(Collider2D* other)
	{
	}
	void PhantomBlowHitEffectScript::OnCollisionExit(Collider2D* other)
	{
	}
	void PhantomBlowHitEffectScript::hiteffect()
	{
		EffectTime += Time::DeltaTime();

		if (EffectTime >= 0.75f)
		{
			EffectTime = 0.0f;
			object::Destroy(GetOwner());
		}
	}

}