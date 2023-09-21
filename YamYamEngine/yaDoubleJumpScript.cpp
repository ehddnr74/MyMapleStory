#include "yaDoubleJumpScript.h"
#include "yaPlayerScript.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaCollider2D.h"
#include "yaObject.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"

namespace ya
{
	DoubleJumpScript::DoubleJumpScript()
		: Right(false)
		, Effecttime(0.0f)
	{

	}
	DoubleJumpScript::~DoubleJumpScript()
	{

	}
	void DoubleJumpScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> LeftDoubleJump = Resources::Load<Texture>(L"LeftDoubleJump", L"..\\Resources\\Texture\\LeftDoubleJump.png");
		std::shared_ptr<Texture> RightDoubleJump = Resources::Load<Texture>(L"RightDoubleJump", L"..\\Resources\\Texture\\RightDoubleJump.png");

		at->Create(L"LeftDoubleJump", LeftDoubleJump, Vector2(0.0f, 0.0f), Vector2(236.0f, 133.0f), 8, Vector2::Zero, 0.1f);
		at->Create(L"RightDoubleJump", RightDoubleJump, Vector2(0.0f, 0.0f), Vector2(236.0f, 133.0f), 8, Vector2::Zero, 0.1f);

		at->PlayAnimation(L"LeftDoubleJump", false);

		mDoubleJumpState = DoubleJumpState::LeftJump;
	}
	void DoubleJumpScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		if (Right == true)
		{
			GetOwner()->AddComponent<Animator>();
			Animator* at = GetOwner()->GetComponent<Animator>();

			Right = false;
			mDoubleJumpState = DoubleJumpState::RightJump;
			at->PlayAnimation(L"RightDoubleJump", false);
		}

		switch (mDoubleJumpState)
		{
		case DoubleJumpScript::DoubleJumpState::LeftJump:
			leftjump();
			break;
		case DoubleJumpScript::DoubleJumpState::RightJump:
			rightjump();
			break;
		default:
			break;
		}

	}
	void DoubleJumpScript::OnCollisionEnter(Collider2D* other)
	{

	}
	void DoubleJumpScript::OnCollisionStay(Collider2D* other)
	{

	}
	void DoubleJumpScript::OnCollisionExit(Collider2D* other)
	{

	}
	void DoubleJumpScript::leftjump()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
	void DoubleJumpScript::rightjump()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();
	}

}