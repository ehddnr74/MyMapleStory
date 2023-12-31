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
#include "yaFireImpScript.h"
#include "yaBanBanScript.h"
#include "yaBanBanHPScript.h"
#include "yaAudioListener.h"
#include "yaAudioClip.h"
#include "yaAudioSource.h"

namespace ya
{
	ya::BladeTornadoScript::BladeTornadoScript()
		: Leftbladetornado(false)
		, Rightbladetornado(false)
		, bladetornadotime1(0.0f)
		, bladetornadotime2(false)
		, Stay(false)
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
		, Attackingtime(0.f)
		, ta1(false)
		, ta2(false)
		, ta3(false)
		, ta4(false)
		, ta5(false)
		, ta6(false)

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

		if (Stay)
		{
			Attackingtime += Time::DeltaTime();

			Transform* tr = GetMushRoom()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();

			if (Attackingtime >= 0.245f && ta1 == false)
			{
				ta1 = true;
				SceneManager::GetPlayerScript()->CreateBladeTornadoHitEffect(GetMushRoom(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x, pos.y + 0.2f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x, pos.y + 0.4f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x, pos.y + 0.6f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x, pos.y + 0.8f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x, pos.y + 1.0f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x, pos.y + 1.2f, pos.z));
			}
			if (Attackingtime >= 0.49f && ta2 == false)
			{
				ta2 = true;
				SceneManager::GetPlayerScript()->CreateBladeTornadoHitEffect(GetMushRoom(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.05f, pos.y + 0.1f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.05f, pos.y + 0.3f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.05f, pos.y + 0.5f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.05f, pos.y + 0.7f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.05f, pos.y + 0.9f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.05f, pos.y + 1.1f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.05f, pos.y + 1.3f, pos.z));
			}

			if (Attackingtime >= 0.735f && ta3 == false)
			{
				ta3 = true;
				SceneManager::GetPlayerScript()->CreateBladeTornadoHitEffect(GetMushRoom(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.1f, pos.y + 0.2f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.1f, pos.y + 0.4f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.1f, pos.y + 0.6f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.1f, pos.y + 0.8f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.1f, pos.y + 1.0f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.1f, pos.y + 1.2f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.1f, pos.y + 1.4f, pos.z));
			}

			if (Attackingtime >= 0.98f && ta4 == false)
			{
				ta4 = true;
				SceneManager::GetPlayerScript()->CreateBladeTornadoHitEffect(GetMushRoom(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.15f, pos.y + 0.3f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.15f, pos.y + 0.5f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.15f, pos.y + 0.7f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.15f, pos.y + 0.9f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.15f, pos.y + 1.1f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.15f, pos.y + 1.3f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.15f, pos.y + 1.5f, pos.z));
			}
			if (Attackingtime >= 1.225f && ta5 == false)
			{
				ta5 = true;
				SceneManager::GetPlayerScript()->CreateBladeTornadoHitEffect(GetMushRoom(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.2f, pos.y + 0.4f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.2f, pos.y + 0.6f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.2f, pos.y + 0.8f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.2f, pos.y + 1.0f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.2f, pos.y + 1.2f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.2f, pos.y + 1.4f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.2f, pos.y + 1.6f, pos.z));
			}
			if (Attackingtime >= 1.46f && ta6 == false)
			{
				Attackingtime = 0.0f;			
				ta6 = true;
				SceneManager::GetPlayerScript()->CreateBladeTornadoHitEffect(GetMushRoom(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.25f, pos.y + 0.5f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.25f, pos.y + 0.7f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.25f, pos.y + 0.9f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.25f, pos.y + 1.1f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.25f, pos.y + 1.3f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.25f, pos.y + 1.5f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(GetMushRoom(), Vector3(pos.x + 0.25f, pos.y + 1.7f, pos.z));
			}
		}
	}

	void BladeTornadoScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"MushRoom" && DamageView == false)
		{
			AudioSource* as = GetOwner()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"BladeTornadoHit", L"..\\Resources\\Sound\\BladeTornadoHit.mp3"));
			as->Play();

			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreateBladeTornadoHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
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
			AudioSource* as = GetOwner()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"BladeTornadoHit", L"..\\Resources\\Sound\\BladeTornadoHit.mp3"));
			as->Play();

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
			AudioSource* as = GetOwner()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"BladeTornadoHit", L"..\\Resources\\Sound\\BladeTornadoHit.mp3"));
			as->Play();

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
			AudioSource* as = GetOwner()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"BladeTornadoHit", L"..\\Resources\\Sound\\BladeTornadoHit.mp3"));
			as->Play();

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
			AudioSource* as = GetOwner()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"BladeTornadoHit", L"..\\Resources\\Sound\\BladeTornadoHit.mp3"));
			as->Play();

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
			AudioSource* as = GetOwner()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"BladeTornadoHit", L"..\\Resources\\Sound\\BladeTornadoHit.mp3"));
			as->Play();

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
			AudioSource* as = GetOwner()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"BladeTornadoHit", L"..\\Resources\\Sound\\BladeTornadoHit.mp3"));
			as->Play();

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
			AudioSource* as = GetOwner()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"BladeTornadoHit", L"..\\Resources\\Sound\\BladeTornadoHit.mp3"));
			as->Play();

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
			AudioSource* as = GetOwner()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"BladeTornadoHit", L"..\\Resources\\Sound\\BladeTornadoHit.mp3"));
			as->Play();

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
			AudioSource* as = GetOwner()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"BladeTornadoHit", L"..\\Resources\\Sound\\BladeTornadoHit.mp3"));
			as->Play();

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
			AudioSource* as = GetOwner()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"BladeTornadoHit", L"..\\Resources\\Sound\\BladeTornadoHit.mp3"));
			as->Play();

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
			AudioSource* as = GetOwner()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"BladeTornadoHit", L"..\\Resources\\Sound\\BladeTornadoHit.mp3"));
			as->Play();

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
			AudioSource* as = GetOwner()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"BladeTornadoHit", L"..\\Resources\\Sound\\BladeTornadoHit.mp3"));
			as->Play();

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

			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.2f, pos.z));

		}
	}
	void BladeTornadoScript::OnCollisionStay(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"MushRoom")
		{
			Stay = true;
			SetMushRoom(other->GetOwner());
		}

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