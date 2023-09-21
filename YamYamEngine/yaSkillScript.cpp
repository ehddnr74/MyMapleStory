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
		: phantomblowTime(0.0f)
		, Rightphantomblow(false)
		, Leftbladetornado(false)
		, Rightbladetornado(false)
		, bladetornadotime1(0.0f)
		, bladetornadotime2(false)
		, Leftcaremapury(false)
	    , Rightcaremapury(false)
		, Leftbladepury(false)
	    , Rightbladepury(false)
	{
	}
	SkillScript::~SkillScript()
	{
	}
	void SkillScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> LeftPhantomBlow = Resources::Load<Texture>(L"LeftPhantomBlow", L"..\\Resources\\Texture\\LeftPhantomBlow.png");
		std::shared_ptr<Texture> RightPhantomBlow = Resources::Load<Texture>(L"RightPhantomBlow", L"..\\Resources\\Texture\\RightPhantomBlow.png");
		std::shared_ptr<Texture> LeftBladeTornado = Resources::Load<Texture>(L"LeftBladeTornado", L"..\\Resources\\Texture\\LeftBladeTornado.png");
		std::shared_ptr<Texture> RightBladeTornado = Resources::Load<Texture>(L"RightBladeTornado", L"..\\Resources\\Texture\\RightBladeTornado.png");
		std::shared_ptr<Texture> LeftBladePury = Resources::Load<Texture>(L"LeftBladePury", L"..\\Resources\\Texture\\LeftBladePury.png");
		std::shared_ptr<Texture> RightBladePury = Resources::Load<Texture>(L"RightBladePury", L"..\\Resources\\Texture\\RightBladePury.png");
		std::shared_ptr<Texture> KarmaPury = Resources::Load<Texture>(L"KarmaPury", L"..\\Resources\\Texture\\KarmaPury.png");

		at->Create(L"LeftPhantomBlow", LeftPhantomBlow, Vector2(0.0f, 0.0f), Vector2(616.0f, 300.0f), 10, Vector2::Zero, 0.08f);
		at->Create(L"RightPhantomBlow", RightPhantomBlow, Vector2(0.0f, 0.0f), Vector2(616.0f, 300.0f), 10, Vector2::Zero, 0.08f);
		at->Create(L"LeftBladeTornado", LeftBladeTornado, Vector2(0.0f, 0.0f), Vector2(592.0f, 616.0f), 21, Vector2::Zero, 0.06f);
		at->Create(L"RightBladeTornado", RightBladeTornado, Vector2(0.0f, 0.0f), Vector2(592.0f, 616.0f), 21, Vector2::Zero, 0.06f);
		at->Create(L"LeftBladePury", LeftBladePury, Vector2(0.0f, 0.0f), Vector2(712.0f, 586.0f), 14, Vector2::Zero, 0.05f);
		at->Create(L"RightBladePury", RightBladePury, Vector2(0.0f, 0.0f), Vector2(712.0f, 586.0f), 14, Vector2::Zero, 0.05f);
		at->Create(L"KarmaPury", KarmaPury, Vector2(0.0f, 0.0f), Vector2(613.34f, 274.0f), 26, Vector2::Zero, 0.05f);


		at->PlayAnimation(L"LeftPhantomBlow", false);

		mSkillState = SkillState::PhantomBlow;
	}
	void SkillScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		switch (mSkillState)
		{
		case SkillScript::SkillState::PhantomBlow:
			phantomblow();
			break;
		case SkillScript::SkillState::RightPhantomBlow:
			rightphantomblow();
			break;
		case SkillScript::SkillState::BladePury:
			bladepury();
			break;
		case SkillScript::SkillState::RightBladePury:
			rightbladepury();
			break;
		case SkillScript::SkillState::BladeTornado:
			bladetornado();
			break;
		case SkillScript::SkillState::RightBladeTornado:
			rightbladetornado();
			break;
		case SkillScript::SkillState::CaremaPury:
			caremapury();
			break;
		case SkillScript::SkillState::RightCaremaPury:
			rightcaremapury();
			break;
		case SkillScript::SkillState::BladeStorm:
			bladestorm();
			break;
		case SkillScript::SkillState::RightBladeStorm:
			rightbladestorm();
			break;
		default:
			break;
		}
		if (Rightphantomblow == true)
		{
			GetOwner()->AddComponent<Animator>();
			Animator* at = GetOwner()->GetComponent<Animator>();

			Rightphantomblow = false;
			mSkillState = SkillState::RightPhantomBlow;
			at->PlayAnimation(L"RightPhantomBlow", false);
		}

		if (Leftbladetornado == true)
		{
			GetOwner()->AddComponent<Animator>();
			Animator* at = GetOwner()->GetComponent<Animator>();

			Leftbladetornado = false;
			mSkillState = SkillState::BladeTornado;
			at->PlayAnimation(L"LeftBladeTornado", false);
		}

		if (Rightbladetornado == true)
		{
			GetOwner()->AddComponent<Animator>();
			Animator* at = GetOwner()->GetComponent<Animator>();

			Rightbladetornado = false;
			mSkillState = SkillState::RightBladeTornado;
			at->PlayAnimation(L"RightBladeTornado", false);
		}

		if (Leftbladepury == true)
		{
			GetOwner()->AddComponent<Animator>();
			Animator* at = GetOwner()->GetComponent<Animator>();

			Leftbladepury = false;
			mSkillState = SkillState::BladePury;
			at->PlayAnimation(L"LeftBladePury", false);
		}

		if (Rightbladepury == true)
		{
			GetOwner()->AddComponent<Animator>();
			Animator* at = GetOwner()->GetComponent<Animator>();

			Rightbladepury = false;
			mSkillState = SkillState::RightBladePury;
			at->PlayAnimation(L"RightBladePury", false);
		}

		if (Leftcaremapury == true)
		{
			GetOwner()->AddComponent<Animator>();
			Animator* at = GetOwner()->GetComponent<Animator>();

			Leftcaremapury = false;
			mSkillState = SkillState::CaremaPury;
			at->PlayAnimation(L"KarmaPury", false);
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
	void SkillScript::phantomblow()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
	void SkillScript::rightphantomblow()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
	void SkillScript::bladepury()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
	void SkillScript::rightbladepury()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
	void SkillScript::bladetornado()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		BladePos = tr->GetPosition();

		if (bladetornadotime2)
		{
			BladePos.x -= 3.5f * Time::DeltaTime();
		}

		tr->SetPosition(BladePos);


		if (bladetornadotime1 <= 0.6f && bladetornadotime2 == false)
		{
			bladetornadotime1 += Time::DeltaTime();
		}

		if (bladetornadotime1 >= 0.6f && bladetornadotime2 == false)
		{
			bladetornadotime1 = 0.0f;
			bladetornadotime2 = true;
		}

	}
	void SkillScript::rightbladetornado()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		BladePos = tr->GetPosition();

		if (bladetornadotime2)
		{
			BladePos.x += 3.5f * Time::DeltaTime();
		}

		tr->SetPosition(BladePos);


		if (bladetornadotime1 <= 0.6f && bladetornadotime2 == false)
		{
			bladetornadotime1 += Time::DeltaTime();
		}

		if (bladetornadotime1 >= 0.6f && bladetornadotime2 == false)
		{
			bladetornadotime1 = 0.0f;
			bladetornadotime2 = true;
		}
	}
	void SkillScript::caremapury()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
	void SkillScript::rightcaremapury()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
	void SkillScript::bladestorm()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
	void SkillScript::rightbladestorm()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
}