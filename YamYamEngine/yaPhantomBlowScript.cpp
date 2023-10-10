#include "yaPhantomBlowScript.h"
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
#include "yaDamageScript.h"
#include <random>
#include "yaFireImpScript.h"
#include "yaBanBanScript.h"
#include "yaBanBanHPScript.h"



namespace ya
{
	ya::PhantomBlowScript::PhantomBlowScript()
		: phantomblowTime(0.0f)
		, Rightphantomblow(false)
		, DamageView(false)
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
		, test(0)
	{
	}
	PhantomBlowScript::~PhantomBlowScript()
	{
	}
	void PhantomBlowScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> LeftPhantomBlow = Resources::Load<Texture>(L"LeftPhantomBlow", L"..\\Resources\\Texture\\LeftPhantomBlow.png");
		std::shared_ptr<Texture> RightPhantomBlow = Resources::Load<Texture>(L"RightPhantomBlow", L"..\\Resources\\Texture\\RightPhantomBlow.png");


		at->Create(L"LeftPhantomBlow", LeftPhantomBlow, Vector2(0.0f, 0.0f), Vector2(616.0f, 300.0f), 10, Vector2::Zero, 0.08f);
		at->Create(L"RightPhantomBlow", RightPhantomBlow, Vector2(0.0f, 0.0f), Vector2(616.0f, 300.0f), 10, Vector2::Zero, 0.08f);


		at->PlayAnimation(L"LeftPhantomBlow", false);

		mSkillState = SkillState::PhantomBlow;
	}
	void PhantomBlowScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		switch (mSkillState)
		{
		case PhantomBlowScript::SkillState::PhantomBlow:
			phantomblow();
			break;
		case PhantomBlowScript::SkillState::RightPhantomBlow:
			rightphantomblow();
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
	}

	void PhantomBlowScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"MushRoom" && DamageView == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreatePhantomBlowHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
				DamageView = true;
				SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
				SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
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
		}

		if (other->GetOwner()->GetName() == L"BanBan" && DamageView13 == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreatePhantomBlowHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			BanBanScript* mBanBanScript = other->GetOwner()->GetComponent<BanBanScript>();

			if (mBanBanScript->GetBanBanHPScript() != nullptr)
			{
				mBanBanScript->SetDamage(SceneManager::GetPlayerScript()->GetAttackDamage());
				mBanBanScript->GetBanBanHPScript()->OnDamage(SceneManager::GetPlayerScript()->GetAttackDamage());
			}

			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));

			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));

			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));

			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));

			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));

		}
	}
	void PhantomBlowScript::OnCollisionStay(Collider2D* other)
	{
	}
	void PhantomBlowScript::OnCollisionExit(Collider2D* other)
	{
	}
	void PhantomBlowScript::phantomblow()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
	void PhantomBlowScript::rightphantomblow()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
}