#include "yaMushroomScript.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaAnimator.h"
#include "yaResources.h"

namespace ya
{
	MushroomScript::MushroomScript()
		: dir(0)
	{
	}
	MushroomScript::~MushroomScript()
	{
	}
	void MushroomScript::Initialize()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
		//at->CompleteEvent(L"Idle") = std::bind(&PlayerScript::Complete, this);

		std::shared_ptr<Texture> MushRoom = Resources::Load<Texture>(L"MushRoom", L"..\\Resources\\Texture\\MushRoom.png");

		at->Create(L"Idle", MushRoom, Vector2(0.0f, 0.0f), Vector2(300.0f, 300.0f), 2, Vector2::Zero, 0.15f);

		at->PlayAnimation(L"Idle", true);

		mMushroomState = MushroomState::Idle;
	}
	void MushroomScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		//if (Input::GetKey(eKeyCode::LEFT))
		//{
		//	pos.x -= 5.0f * Time::DeltaTime();
		//	tr->SetPosition(pos);
		//}
		//else if (Input::GetKey(eKeyCode::RIGHT))
		//{
		//	pos.x += 5.0f * Time::DeltaTime();
		//	tr->SetPosition(pos);
		//}
		//else if (Input::GetKey(eKeyCode::DOWN))
		//{
		//	pos.y -= 5.0f * Time::DeltaTime();
		//	tr->SetPosition(pos);
		//}
		//else if (Input::GetKey(eKeyCode::UP))
		//{
		//	pos.y += 5.0f * Time::DeltaTime();
		//	tr->SetPosition(pos);
		//}

		switch (mMushroomState)
		{
		case MushroomScript::MushroomState::Idle:
			Idle();
			break;
		default:
			break;
		}
	}
	void MushroomScript::Complete()
	{
		int a = 0;
	}
	void MushroomScript::OnCollisionEnter(Collider2D* other)
	{

	}
	void MushroomScript::OnCollisionStay(Collider2D* other)
	{

	}
	void MushroomScript::OnCollisionExit(Collider2D* other)
	{

	}
	void MushroomScript::Idle()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
}
