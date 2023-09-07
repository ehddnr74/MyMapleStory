#include "yaBallScript.h"
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
	BallScript::BallScript()
		: Right(false)
	{

	}
	BallScript::~BallScript()
	{

	}
	void BallScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> LeftBall = Resources::Load<Texture>(L"LeftBall", L"..\\Resources\\Texture\\BanBan\\LeftBall.png");
		std::shared_ptr<Texture> RightBall = Resources::Load<Texture>(L"RightBall", L"..\\Resources\\Texture\\BanBan\\RightBall.png");

		at->Create(L"LeftBall", LeftBall, Vector2(0.0f, 0.0f), Vector2(137.0f, 50.0f), 4, Vector2::Zero, 0.1f);
		at->Create(L"RightBall", RightBall, Vector2(0.0f, 0.0f), Vector2(137.0f, 50.0f), 4, Vector2::Zero, 0.1f);

		at->PlayAnimation(L"LeftBall", true);

		mBallState = BallState::LeftBall;
	}
	void BallScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		if (Right == true)
		{
			GetOwner()->AddComponent<Animator>();
			Animator* at = GetOwner()->GetComponent<Animator>();

			Right = false;
			mBallState = BallState::RightBall;
			at->PlayAnimation(L"RightBall", true);
		}

		switch (mBallState)
		{
		case BallScript::BallState::LeftBall:
			leftball();
			break;
		case BallScript::BallState::RightBall:
			rightball();
			break;
		default:
			break;
		}

	}
	void BallScript::OnCollisionEnter(Collider2D* other)
	{

	}
	void BallScript::OnCollisionStay(Collider2D* other)
	{

	}
	void BallScript::OnCollisionExit(Collider2D* other)
	{

	}
	void BallScript::leftball()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		pos.x -= 1.0f * Time::DeltaTime();
		GetOwner()->GetComponent<Transform>()->SetPosition(pos);
	}
	void BallScript::rightball()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		pos.x += 1.0f * Time::DeltaTime();
		GetOwner()->GetComponent<Transform>()->SetPosition(pos);
	}

}