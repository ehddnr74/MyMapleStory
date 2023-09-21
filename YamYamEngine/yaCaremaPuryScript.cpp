#include "yaCaremaPuryScript.h"
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
	ya::CaremaPuryScript::CaremaPuryScript()
		: Leftcaremapury(false)
		, Rightcaremapury(false)
	{
	}
	CaremaPuryScript::~CaremaPuryScript()
	{
	}
	void CaremaPuryScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> KarmaPury = Resources::Load<Texture>(L"KarmaPury", L"..\\Resources\\Texture\\KarmaPury.png");

		at->Create(L"KarmaPury", KarmaPury, Vector2(0.0f, 0.0f), Vector2(613.34f, 274.0f), 26, Vector2::Zero, 0.05f);

		at->PlayAnimation(L"KarmaPury", false);

		mSkillState = SkillState::CaremaPury;
	}
	void CaremaPuryScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		switch (mSkillState)
		{
		case CaremaPuryScript::SkillState::CaremaPury:
			caremapury();
			break;
		case CaremaPuryScript::SkillState::RightCaremaPury:
			rightcaremapury();
			break;
		default:
			break;
		}

		if (Rightcaremapury == true)
		{
			GetOwner()->AddComponent<Animator>();
			Animator* at = GetOwner()->GetComponent<Animator>();

			Rightcaremapury = false;
			mSkillState = SkillState::RightCaremaPury;
			at->PlayAnimation(L"KarmaPury", false);
		}
	}

	void CaremaPuryScript::OnCollisionEnter(Collider2D* other)
	{
	}
	void CaremaPuryScript::OnCollisionStay(Collider2D* other)
	{
	}
	void CaremaPuryScript::OnCollisionExit(Collider2D* other)
	{
	}
	void CaremaPuryScript::caremapury()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
	void CaremaPuryScript::rightcaremapury()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
}
