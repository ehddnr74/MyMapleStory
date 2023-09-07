#include "yaSkillScript.h"
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
	ya::SkillScript::SkillScript()
		: DevideTime(0.f)
		, Right(false)
	{
	}
	SkillScript::~SkillScript()
	{
	}
	void SkillScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> LeftDevide = Resources::Load<Texture>(L"LeftDevide", L"..\\Resources\\Texture\\LeftDevide.png");

		std::shared_ptr<Texture> RightDevide = Resources::Load<Texture>(L"RightDevide", L"..\\Resources\\Texture\\RightDevide.png");


		at->Create(L"LeftDevide", LeftDevide, Vector2(0.0f, 0.0f), Vector2(695.0f, 501.0f), 10, Vector2::Zero, 0.08f);
		at->Create(L"RightDevide", RightDevide, Vector2(0.0f, 0.0f), Vector2(695.0f, 501.0f), 10, Vector2::Zero, 0.08f);


		at->PlayAnimation(L"LeftDevide", false);

		mSkillState = SkillState::Devide;
	}
	void SkillScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		switch (mSkillState)
		{
		case SkillScript::SkillState::Devide:
			devide();
			break;
		case SkillScript::SkillState::RightDevide:
			rightdevide();
			break;
		default:
			break;
		}
		if (Right == true)
		{
			GetOwner()->AddComponent<Animator>();
			Animator* at = GetOwner()->GetComponent<Animator>();

			Right = false;
			mSkillState = SkillState::RightDevide;
			at->PlayAnimation(L"RightDevide", false);
		}
	}
	void SkillScript::Complete()
	{
	}
	void SkillScript::OnCollisionEnter(Collider2D* other)
	{
	}
	void SkillScript::OnCollisionStay(Collider2D* other)
	{
	}
	void SkillScript::OnCollisionExit(Collider2D* other)
	{
	}
	void SkillScript::devide()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
	void SkillScript::rightdevide()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
}