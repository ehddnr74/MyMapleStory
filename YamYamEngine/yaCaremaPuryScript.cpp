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
#include "yaFireImpScript.h"
#include "yaBanBanScript.h"

namespace ya
{
	ya::CaremaPuryScript::CaremaPuryScript()
		: Leftcaremapury(false)
		, Rightcaremapury(false)
		, DamageView(false)
		//, DamageView2(false)
		, Stay(false)
		, Attackingtime(0.f)
	    , ta2(false)
	    , ta3(false)
	    , ta4(false)
	    , ta5(false)
	    , ta6(false)
	    , DamageView2(false)
	    , DamageView3(false)
	    , DamageView4(false)
	    , DamageView5(false)
	    , DamageView6(false)
	    , DamageView7(false)
	    , DamageView8(false)
	    , DamageView9(false)
	    , DamageView10(false)
	    , DamageView11(false)
	    , DamageView12(false)
		, DamageView13(false)

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

		if (Stay)
		{
			Attackingtime += Time::DeltaTime();

			Transform* tr = GetMushRoom()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();

			if (Attackingtime >= 0.245f && ta2 == false)
			{
				ta2 = true;
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x, pos.y + 0.2f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x, pos.y + 0.4f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x, pos.y + 0.6f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x, pos.y + 0.8f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x, pos.y + 1.0f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x, pos.y + 1.2f, pos.z));
			}
			if (Attackingtime >= 0.49f && ta3 == false)
			{
				ta3 = true;
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.05f, pos.y + 0.1f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.05f, pos.y + 0.3f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.05f, pos.y + 0.5f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.05f, pos.y + 0.7f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.05f, pos.y + 0.9f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.05f, pos.y + 1.1f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.05f, pos.y + 1.3f, pos.z));
			}

			if (Attackingtime >= 1.015f && ta3 == false)
			{
				ta3 = true;
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.1f, pos.y + 0.2f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.1f, pos.y + 0.4f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.1f, pos.y + 0.6f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.1f, pos.y + 0.8f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.1f, pos.y + 1.0f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.1f, pos.y + 1.2f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.1f, pos.y + 1.4f, pos.z));
			}

			if (Attackingtime >= 0.735f && ta4 == false)
			{
				ta4 = true;
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.15f, pos.y + 0.3f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.15f, pos.y + 0.5f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.15f, pos.y + 0.7f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.15f, pos.y + 0.9f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.15f, pos.y + 1.1f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.15f, pos.y + 1.3f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.15f, pos.y + 1.5f, pos.z));
			}
			if (Attackingtime >= 0.98f && ta5 == false)
			{
				ta5 = true;
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.2f, pos.y + 0.4f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.2f, pos.y + 0.6f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.2f, pos.y + 0.8f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.2f, pos.y + 1.0f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.2f, pos.y + 1.2f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.2f, pos.y + 1.4f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.2f, pos.y + 1.6f, pos.z));
			}
		}
	}

	void CaremaPuryScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"MushRoom" && DamageView == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreateCaremaPuryHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.2f, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp1" && DamageView2 == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreatePhantomBlowHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			FireImpScript* mFireImpScript = other->GetOwner()->GetComponent<FireImpScript>();
			mFireImpScript->SetDamage(SceneManager::GetPlayerScript()->GetAttackDamage());
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.2f, pos.z));
		}

		if (other->GetOwner()->GetName() == L"FireImp2" && DamageView3 == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreatePhantomBlowHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			FireImpScript* mFireImpScript = other->GetOwner()->GetComponent<FireImpScript>();
			mFireImpScript->SetDamage(SceneManager::GetPlayerScript()->GetAttackDamage());
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.2f, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp3" && DamageView4 == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreatePhantomBlowHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			FireImpScript* mFireImpScript = other->GetOwner()->GetComponent<FireImpScript>();
			mFireImpScript->SetDamage(SceneManager::GetPlayerScript()->GetAttackDamage());
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.2f, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp4" && DamageView5 == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreatePhantomBlowHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			FireImpScript* mFireImpScript = other->GetOwner()->GetComponent<FireImpScript>();
			mFireImpScript->SetDamage(SceneManager::GetPlayerScript()->GetAttackDamage());
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.2f, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp5" && DamageView6 == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreatePhantomBlowHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			FireImpScript* mFireImpScript = other->GetOwner()->GetComponent<FireImpScript>();
			mFireImpScript->SetDamage(SceneManager::GetPlayerScript()->GetAttackDamage());
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.2f, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp6" && DamageView7 == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreatePhantomBlowHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			FireImpScript* mFireImpScript = other->GetOwner()->GetComponent<FireImpScript>();
			mFireImpScript->SetDamage(SceneManager::GetPlayerScript()->GetAttackDamage());
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.2f, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp7" && DamageView8 == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreatePhantomBlowHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			FireImpScript* mFireImpScript = other->GetOwner()->GetComponent<FireImpScript>();
			mFireImpScript->SetDamage(SceneManager::GetPlayerScript()->GetAttackDamage());
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.2f, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp8" && DamageView9 == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreatePhantomBlowHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			FireImpScript* mFireImpScript = other->GetOwner()->GetComponent<FireImpScript>();
			mFireImpScript->SetDamage(SceneManager::GetPlayerScript()->GetAttackDamage());
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.2f, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp9" && DamageView10 == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreatePhantomBlowHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			FireImpScript* mFireImpScript = other->GetOwner()->GetComponent<FireImpScript>();
			mFireImpScript->SetDamage(SceneManager::GetPlayerScript()->GetAttackDamage());
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.2f, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp10" && DamageView11 == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreatePhantomBlowHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			FireImpScript* mFireImpScript = other->GetOwner()->GetComponent<FireImpScript>();
			mFireImpScript->SetDamage(SceneManager::GetPlayerScript()->GetAttackDamage());
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.2f, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp11" && DamageView12 == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreatePhantomBlowHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			FireImpScript* mFireImpScript = other->GetOwner()->GetComponent<FireImpScript>();
			mFireImpScript->SetDamage(SceneManager::GetPlayerScript()->GetAttackDamage());
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.2f, pos.z));
		}

		if (other->GetOwner()->GetName() == L"BanBan" && DamageView13 == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreatePhantomBlowHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			BanBanScript* mBanBanScript = other->GetOwner()->GetComponent<BanBanScript>();
			mBanBanScript->SetDamage(SceneManager::GetPlayerScript()->GetAttackDamage());
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.2f, pos.z));
		}
	}
	void CaremaPuryScript::OnCollisionStay(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"MushRoom")
		{
			Stay = true;
			SetMushRoom(other->GetOwner());
		}
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
