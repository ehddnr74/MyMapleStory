#include "yaBladeTornadoScript.h"
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
	ya::BladeTornadoScript::BladeTornadoScript()
		: Leftbladetornado(false)
		, Rightbladetornado(false)
		, bladetornadotime1(0.0f)
		, bladetornadotime2(false)

	{
	}
	BladeTornadoScript::~BladeTornadoScript()
	{
	}
	void BladeTornadoScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> LeftBladeTornado = Resources::Load<Texture>(L"LeftBladeTornado", L"..\\Resources\\Texture\\LeftBladeTornado.png");
		std::shared_ptr<Texture> RightBladeTornado = Resources::Load<Texture>(L"RightBladeTornado", L"..\\Resources\\Texture\\RightBladeTornado.png");


		at->Create(L"LeftBladeTornado", LeftBladeTornado, Vector2(0.0f, 0.0f), Vector2(592.0f, 616.0f), 21, Vector2::Zero, 0.07f);
		at->Create(L"RightBladeTornado", RightBladeTornado, Vector2(0.0f, 0.0f), Vector2(592.0f, 616.0f), 21, Vector2::Zero, 0.07f);


		at->PlayAnimation(L"LeftBladeTornado", false);

		mSkillState = SkillState::BladeTornado;
	}
	void BladeTornadoScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		switch (mSkillState)
		{
		case BladeTornadoScript::SkillState::BladeTornado:
			bladetornado();
			break;
		case BladeTornadoScript::SkillState::RightBladeTornado:
			rightbladetornado();
			break;
		default:
			break;
		}

		if (Rightbladetornado == true)
		{
			GetOwner()->AddComponent<Animator>();
			Animator* at = GetOwner()->GetComponent<Animator>();

			Rightbladetornado = false;
			mSkillState = SkillState::RightBladeTornado;
			at->PlayAnimation(L"RightBladeTornado", false);
		}
	}

	void BladeTornadoScript::OnCollisionEnter(Collider2D* other)
	{
	}
	void BladeTornadoScript::OnCollisionStay(Collider2D* other)
	{
	}
	void BladeTornadoScript::OnCollisionExit(Collider2D* other)
	{
	}

	void BladeTornadoScript::bladetornado()
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
	void BladeTornadoScript::rightbladetornado()
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
}