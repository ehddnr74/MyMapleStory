#include "yaPhantomBlowSmokeScript.h"
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
	ya::PhantomBlowSmokeScript::PhantomBlowSmokeScript()
		: EffectTime(0.f)
		, Rightsmoke(false)
	{

	}
	PhantomBlowSmokeScript::~PhantomBlowSmokeScript()
	{

	}

	void PhantomBlowSmokeScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> LeftPhantomBlowSmoke = Resources::Load<Texture>(L"LeftPhantomBlowSmoke", L"..\\Resources\\Texture\\LeftPhantomBlowSmoke.png");
		std::shared_ptr<Texture> RightPhantomBlowSmoke = Resources::Load<Texture>(L"RightPhantomBlowSmoke", L"..\\Resources\\Texture\\RightPhantomBlowSmoke.png");

		at->Create(L"LeftPhantomBlowSmoke", LeftPhantomBlowSmoke, Vector2(0.0f, 0.0f), Vector2(221.0f, 105.0f), 10, Vector2::Zero, 0.08f);
		at->Create(L"RightPhantomBlowSmoke", RightPhantomBlowSmoke, Vector2(0.0f, 0.0f), Vector2(221.0f, 105.0f), 10, Vector2::Zero, 0.08f);

		at->PlayAnimation(L"LeftPhantomBlowSmoke", false);

		mSmokeState = SmokeState::LeftSmoke;
	}
	void PhantomBlowSmokeScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		switch (mSmokeState)
		{

		case PhantomBlowSmokeScript::SmokeState::LeftSmoke:
			leftsmoke();
			break;
		case PhantomBlowSmokeScript::SmokeState::RightSmoke:
			rightsmoke();
			break;
		default:
			break;
		}

		if (Rightsmoke == true)
		{
			GetOwner()->AddComponent<Animator>();
			Animator* at = GetOwner()->GetComponent<Animator>();

			Rightsmoke = false;
			mSmokeState = SmokeState::RightSmoke;
			at->PlayAnimation(L"RightPhantomBlowSmoke", false);
		}
	}

	void PhantomBlowSmokeScript::OnCollisionEnter(Collider2D* other)
	{
	}
	void PhantomBlowSmokeScript::OnCollisionStay(Collider2D* other)
	{
	}
	void PhantomBlowSmokeScript::OnCollisionExit(Collider2D* other)
	{
	}
	void PhantomBlowSmokeScript::leftsmoke()
	{
		//EffectTime += Time::DeltaTime();

		//if (EffectTime >= 0.8f)
		//{
		//	EffectTime = 0.0f;
		//	object::Destroy(GetOwner());
		//}
	}
	void PhantomBlowSmokeScript::rightsmoke()
	{
		//EffectTime += Time::DeltaTime();

		//if (EffectTime >= 0.8f)
		//{
		//	EffectTime = 0.0f;
		//	object::Destroy(GetOwner());
		//}
	}
}