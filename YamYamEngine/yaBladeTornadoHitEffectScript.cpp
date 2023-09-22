#include "yaBladeTornadoHitEffectScript.h"
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
	ya::BladeTornadoHitEffectScript::BladeTornadoHitEffectScript()
		: EffectTime(0.0f)
	{

	}
	BladeTornadoHitEffectScript::~BladeTornadoHitEffectScript()
	{

	}

	void BladeTornadoHitEffectScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> BladeTornadoHitEffect = Resources::Load<Texture>(L"BladeTornadoHitEffect", L"..\\Resources\\Texture\\BladeTornadoHitEffect.png");

		at->Create(L"BladeTornadoHitEffect", BladeTornadoHitEffect, Vector2(0.0f, 0.0f), Vector2(300.0f, 312.0f), 7, Vector2::Zero, 0.07f);

		at->PlayAnimation(L"BladeTornadoHitEffect", false);

		mHitEffectState = HitEffectState::HitEffect;
	}
	void BladeTornadoHitEffectScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		switch (mHitEffectState)
		{

		case BladeTornadoHitEffectScript::HitEffectState::HitEffect:
			hiteffect();
			break;
		default:
			break;
		}
	}

	void BladeTornadoHitEffectScript::OnCollisionEnter(Collider2D* other)
	{
	}
	void BladeTornadoHitEffectScript::OnCollisionStay(Collider2D* other)
	{
	}
	void BladeTornadoHitEffectScript::OnCollisionExit(Collider2D* other)
	{
	}
	void BladeTornadoHitEffectScript::hiteffect()
	{
		EffectTime += Time::DeltaTime();

		if (EffectTime >= 0.49f)
		{
			EffectTime = 0.0f;
			object::Destroy(GetOwner());
		}
	}

}