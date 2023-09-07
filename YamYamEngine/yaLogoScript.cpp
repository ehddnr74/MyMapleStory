#include "yaAnimator.h"
#include "yaResources.h"
#include "yaObject.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaLogoScript.h"
#include "yaMeshRenderer.h"
#include "yaMesh.h"

namespace ya
{
	ya::LogoScript::LogoScript()
		: wizettime(0.0f)
	{
	}
	LogoScript::~LogoScript()
	{
	}
	void LogoScript::CreateWhiteBG()
	{
		GameObject* WhiteBG
			= object::Instantiate<GameObject>(Vector3(0.0f, 0.0f, 1.0000f), eLayerType::BG);

		//SetDevide(Devide);

		WhiteBG->SetName(L"White");


		MeshRenderer* mr = WhiteBG->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"White"));

		WhiteBG->GetComponent<Transform>()->SetScale(Vector3(8.0f, 5.0f, 1.0000f));
	}

	void LogoScript::CreateLogo()
	{
		GameObject* Logo1
			= object::Instantiate<GameObject>(Vector3(3.0f, 1.5f, 0.999f), eLayerType::Logo);

		//SetDevide(Devide);

		Logo1->SetName(L"Logo1");


		MeshRenderer* mr = Logo1->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"Lg1"));

		Logo1->GetComponent<Transform>()->SetScale(Vector3(0.8f, 0.8f, 0.999f));

		GameObject* Logo2
			= object::Instantiate<GameObject>(Vector3(2.3f, 1.4f, 0.999f), eLayerType::Logo);

		//SetDevide(Devide);

		Logo2->SetName(L"Logo2");


		MeshRenderer* mr2 = Logo2->AddComponent<MeshRenderer>();
		mr2->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr2->SetMaterial(Resources::Find<Material>(L"Lg2"));

		Logo2->GetComponent<Transform>()->SetScale(Vector3(0.6f, 0.6f, 0.999f));
	}

	void LogoScript::Initialize()
	{
		CreateWhiteBG();
		CreateLogo();

		Animator* at = GetOwner()->GetComponent<Animator>();
		//at->CompleteEvent(L"Idle") = std::bind(&PlayerScript::Complete, this);

		std::shared_ptr<Texture> Wizet = Resources::Load<Texture>(L"Wizet1", L"..\\Resources\\Texture\\Wizet.png");

		at->Create(L"Wizet1", Wizet, Vector2(0.0f, 0.0f), Vector2(456.0f, 285.0f), 24, Vector2::Zero, 0.1f);
		at->Create(L"Wizet2", Wizet, Vector2(0.0f, 285.0f), Vector2(456.0f, 285.0f), 24, Vector2::Zero, 0.1f);

		at->PlayAnimation(L"Wizet1", false);

		mLogoState = LogoState::Wizet1;
	}

	void LogoScript::Update()
	{
		switch (mLogoState)
		{
		case LogoState::Wizet1:
			wizet1();
			break;
		case LogoState::Wizet2:
			wizet2();
			break;
		default:
			break;
		}
	}
	void LogoScript::wizet1()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();


		wizettime += Time::DeltaTime();

		if (wizettime >= 3.5f)
		{
			mLogoState = LogoState::Wizet2;
			at->PlayAnimation(L"Wizet2", false);
		}
	}
	void LogoScript::wizet2()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
}