#include "yaPortalScript.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaAnimator.h"
#include "yaResources.h"


namespace ya
{

}

ya::PortalScript::PortalScript()
{
}

ya::PortalScript::~PortalScript()
{
}

void ya::PortalScript::Initialize()
{
	Animator* at = GetOwner()->GetComponent<Animator>();

	Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
	//at->CompleteEvent(L"Idle") = std::bind(&PlayerScript::Complete, this);

	std::shared_ptr<Texture> Portal = Resources::Load<Texture>(L"Portal", L"..\\Resources\\Texture\\Portal.png");

	at->Create(L"Portal", Portal, Vector2(0.0f, 0.0f), Vector2(89.0f, 257.0f), 8, Vector2::Zero, 0.1f);

	at->PlayAnimation(L"Portal", true);

	mPortalState = PortalState::Portal;
}

void ya::PortalScript::Update()
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

	switch (mPortalState)
	{
	case PortalScript::PortalState::Portal:
		portal();
		break;
	default:
		break;
	}
}

void ya::PortalScript::portal()
{
}
