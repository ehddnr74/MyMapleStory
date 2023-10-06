#include "yaSkillCollDownScript.h"
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
#include "yaMeshRenderer.h"
#include "yaCurSorScript.h"

namespace ya
{
	SkillCollDownScript::SkillCollDownScript()
		: KarmaPury(false)
		, tornadocooltime(0.0f)
		, purycooltime(0.0f)
	{

	}
	SkillCollDownScript::~SkillCollDownScript()
	{

	}
	void SkillCollDownScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();


		std::shared_ptr<Texture> SkillCoolTime = Resources::Load<Texture>(L"SkillCoolTime", L"..\\Resources\\Texture\\SkillCoolTime.png");

		at->Create(L"BladeTornadoSkillCoolTime", SkillCoolTime, Vector2(0.0f, 0.0f), Vector2(32.0f, 64.0f), 16, Vector2::Zero, 0.3125f);
		at->Create(L"CaremaPurySkillCoolTime", SkillCoolTime, Vector2(0.0f, 0.0f), Vector2(32.0f, 64.0f), 16, Vector2::Zero, 0.3125f);

		at->PlayAnimation(L"BladeTornadoSkillCoolTime", false);

		mSkillState = SkillState::BladeTornado;
	}
	void SkillCollDownScript::Update()
	{
		if (KarmaPury)
		{
			Animator* at = GetOwner()->GetComponent<Animator>();

			KarmaPury = false;
			at->PlayAnimation(L"CaremaPurySkillCoolTime", false);
			mSkillState = SkillState::CaremaPury;
		}


		switch (mSkillState)
		{
		case SkillCollDownScript::SkillState::BladeTornado:
			bladetornado();
			break;
		case SkillCollDownScript::SkillState::CaremaPury:
			caremapury();
			break;
		default:
			break;

		}

	}

	void SkillCollDownScript::bladetornado()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		tornadocooltime += Time::DeltaTime();

		if (tornadocooltime >= 5.0f)
		{
			tornadocooltime = 0.0f;
			object::Destroy(GetOwner());
		}

	}
	void SkillCollDownScript::caremapury()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		purycooltime += Time::DeltaTime();

		if (purycooltime >= 5.0f)
		{
			purycooltime = 0.0f;
			KarmaPury = true;
			object::Destroy(GetOwner());
		}

	}
}