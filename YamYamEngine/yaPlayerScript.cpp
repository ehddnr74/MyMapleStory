#include "yaPlayerScript.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaRigidBody.h"
#include "yaMushroomScript.h"
#include "yaCollider2D.h"
#include "yaObject.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaSkillScript.h"
#include "yaMeshRenderer.h"
#include "yaMesh.h"
#include "yaHpScript.h"
#include "yaMpScript.h"
#include "yaExpScript.h"
#include "yaInventoryScript.h"	
#include "yaPhantomBlowScript.h"
#include "yaBladePuryScript.h"
#include "yaBladeTornadoScript.h"
#include "yaCaremaPuryScript.h"
#include "yaDoubleJumpScript.h"
#include "yaDamageScript.h"
#include "yaPhantomBlowSmokeScript.h"
#include "yaPhantomBlowHitEffectScript.h"
#include "yaBladePuryHitEffectScript.h"
#include "yaKarmaPuryHitEffectScript.h"
#include "yaBladeTornadoHitEffectScript.h"
#include "yaSkillUIScript.h"
#include <random>
#include "yaFireImpScript.h"
#include "yaHitDamageScript.h"
#include "yaCollisionManager.h"

std::mt19937_64 rng4(0);
std::uniform_int_distribution<__int64> dist4(50000, 99999);

std::mt19937_64 rng5(0);
std::uniform_int_distribution<__int64> dist5(100, 999);

std::mt19937_64 rng6(0);
std::uniform_int_distribution<__int64> dist6(1000, 9999);

std::mt19937_64 rng7(0);
std::uniform_int_distribution<__int64> dist7(10000,20000);

namespace ya
{
	PlayerScript::PlayerScript()
		: dir(0)
		, attacktime(0.f)
		, jumptime(0.f)
		, alerttime(0.f)
		, hit(false)
		, jum(false)
		, isjump(false)
		, jumpdouble(false)
		, pbtime(0.0f)
		, bptime(0.0f)
		, bttime(0.0f)
		, cptime(0.0f)
		, djtime(0.0f)
		, pbstime(0.0f)
		, portal(false)
		, inventory(false)
		, OnShop(false)
		, Oninventory(false)
		, skillui(false)
		, skilluitime(0.0f)
		, inventorytime(0.0f)
		, AttackDamage(0)
		, HitDamage(0)
		, HitMushroom(false)
		, meso(100)
		, HitFireImp(false)
		, HitBanBan(false)
		, EarthQuake(false)
		, DieCheck(false)
		, dietime(0.0f)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		Collider2D* cd = GetOwner()->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.008f, 0.065f));
		cd->SetSize(Vector2(0.18f, 0.28f));

		std::shared_ptr<Texture> LeftAnimation = Resources::Load<Texture>(L"LeftAnimation", L"..\\Resources\\Texture\\LeftPlayerFsm.png");
		std::shared_ptr<Texture> RightAnimation = Resources::Load<Texture>(L"RightAnimation", L"..\\Resources\\Texture\\RightPlayerFsm.png");
		std::shared_ptr<Texture> Prone = Resources::Load<Texture>(L"Prone", L"..\\Resources\\Texture\\Prone.png");
		std::shared_ptr<Texture> RightProne = Resources::Load<Texture>(L"RightProne", L"..\\Resources\\Texture\\RightProne.png");
		std::shared_ptr<Texture> LeftJump = Resources::Load<Texture>(L"LeftJump", L"..\\Resources\\Texture\\LeftJump.png");
		std::shared_ptr<Texture> RightJump = Resources::Load<Texture>(L"RightJump", L"..\\Resources\\Texture\\RightJump.png");
		std::shared_ptr<Texture> LeftPlayerDie = Resources::Load<Texture>(L"LeftPlayerDie", L"..\\Resources\\Texture\\LeftDie.png");
		std::shared_ptr<Texture> RightPlayerDie = Resources::Load<Texture>(L"RightPlayerDie", L"..\\Resources\\Texture\\RightDie.png");

		at->Create(L"LeftIdle", LeftAnimation, Vector2(0.0f, 0.0f), Vector2(300.0f, 300.0f), 3, Vector2::Zero, 0.5f);
		at->Create(L"RightIdle", RightAnimation, Vector2(0.0f, 0.0f), Vector2(300.0f, 300.0f), 3, Vector2::Zero, 0.5f);

		at->Create(L"LeftWalk", LeftAnimation, Vector2(0.0f, 300.0f), Vector2(300.0f, 300.0f), 4, Vector2::Zero, 0.2f);
		at->Create(L"RightWalk", RightAnimation, Vector2(0.0f, 300.0f), Vector2(300.0f, 300.0f), 4, Vector2::Zero, 0.2f);

		at->Create(L"Prone", Prone, Vector2(0.0f, 0.0f), Vector2(300.0f, 300.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"RightProne", RightProne, Vector2(0.0f, 0.0f), Vector2(300.0f, 300.0f), 1, Vector2::Zero, 0.1f);

		at->Create(L"LeftAttack", LeftAnimation, Vector2(0.0f, 600.0f), Vector2(300.0f, 300.0f), 3, Vector2::Zero, 0.15f);
		at->Create(L"RightAttack", RightAnimation, Vector2(0.0f, 600.0f), Vector2(300.0f, 300.0f), 3, Vector2::Zero, 0.15f);

		at->Create(L"LeftJump", LeftJump, Vector2(0.0f, 0.0f), Vector2(300.0f, 300.0f), 1, Vector2::Zero, 0.15f);
		at->Create(L"RightJump", RightJump, Vector2(0.0f, 0.0f), Vector2(300.0f, 300.0f), 1, Vector2::Zero, 0.15f);

		at->Create(L"Alert", LeftAnimation, Vector2(0.0f, 900.0f), Vector2(300.0f, 300.0f), 3, Vector2::Zero, 0.3f);
		at->Create(L"RightAlert", RightAnimation, Vector2(0.0f, 900.0f), Vector2(300.0f, 300.0f), 3, Vector2::Zero, 0.3f);

		at->Create(L"LeftPlayerDie", LeftPlayerDie, Vector2(0.0f, 0.0f), Vector2(43.0f, 68.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"RightPlayerDie", RightPlayerDie, Vector2(0.0f, 0.0f), Vector2(43.0f, 68.0f), 1, Vector2::Zero, 0.1f);

		RigidBody* mRigidBody = GetOwner()->AddComponent<RigidBody>();
		//RigidBody* rb = GetOwner()->GetComponent<RigidBody>();

		//mRigidBody->SetGround(true);

		at->PlayAnimation(L"LeftIdle", true);

		mPlayerState = PlayerState::Idle;
	}
	void PlayerScript::Update()
	{

		Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
		cd->SetCenter(Vector2(0.008f, 0.065f));
		cd->SetSize(Vector2(0.18f, 0.28f));

		if (mPlayerState == PlayerState::Die)
		{
			Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, 0.0f));
			cd->SetSize(Vector2(0.0f, 0.0f));
		}
		//if (mPlayerState == PlayerState::Attack)
		//{
		//	Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
		//	cd->SetCenter(Vector2(0.0f, 0.0f));
		//	cd->SetSize(Vector2(1.0f, 1.0f));
		//}
		//else
		//{
		//	Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
		//	cd->SetCenter(Vector2(0.008f, 0.055f));
		//	cd->SetSize(Vector2(0.22f, 0.38f));
		//}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		if (skillui == false)
		{
			if (Input::GetKeyDown(eKeyCode::K))
			{
				skillui = true;
				CreateSkillUI();
			}
		}

		if (skillui)
		{
			skilluitime += Time::DeltaTime();

			if (skilluitime >= 0.2f && Input::GetKeyDown(eKeyCode::K))
			{
				skilluitime = 0.0f;
				skillui = false;
				CloseSkillUI();
			}
		}

		if (inventory == false && OnShop == false)
		{
			if (Input::GetKeyDown(eKeyCode::I))
			{
				inventory = true;
				SceneManager::GetInventoryScript()->OnInventory();
				Oninventory = true;
			}
		}

		//if (inventory && OnShop)
		//{
		//	inventorytime += Time::DeltaTime();

		//	if (inventorytime >= 0.2f && Input::GetKeyDown(eKeyCode::I))
		//	{
		//		inventorytime = 0.0f;
		//		inventory = false;
		//		OnShop = false;
		//		SceneManager::GetInventoryScript()->CloseInventory();
		//	}
		//}

		if (inventory == true && OnShop == false)
		{
			inventorytime += Time::DeltaTime();

			if (inventorytime >= 0.2f && Input::GetKeyDown(eKeyCode::I))
			{
				inventorytime = 0.0f;
				inventory = false;
				SceneManager::GetInventoryScript()->CloseInventory();
			}
		}

		if (mPhantomBlow != nullptr)
		{
			pbtime += Time::DeltaTime();

			if (pbtime >= 0.75f)
			{
				pbtime = 0.0f;
				object::Destroy(mPhantomBlow);
				SetPhantomBlow(nullptr);
				SetCaremaPuryScript(nullptr);
			}
		}

		if (mBladeTornado != nullptr)
		{
			bttime += Time::DeltaTime();
			if (bttime >= 1.47f)
			{
				bttime = 0.0f;
				object::Destroy(mBladeTornado);
				SetBladeTornado(nullptr);
				SetBladeTornadoScript(nullptr);
			}
		}

		if (mBladePury != nullptr)
		{
			bptime += Time::DeltaTime();
			if (bptime >= 0.7f)
			{
				bptime = 0.0f;
				object::Destroy(mBladePury);
				SetBladePury(nullptr);
				SetBladePuryScript(nullptr);
			}
		}

		if (mCaremaPury != nullptr)
		{
			cptime += Time::DeltaTime();
			if (cptime >= 1.3f)
			{
				cptime = 0.0f;
				object::Destroy(mCaremaPury);
				SetCaremaPury(nullptr);
				SetCaremaPuryScript(nullptr);
			}
		}

		if (mDoubleJump != nullptr)
		{
			djtime += Time::DeltaTime();
			if (GetOwner()->GetComponent<RigidBody>()->GetGround())//djtime >= 0.75f
			{
				//djtime = 0.0f;
				object::Destroy(mDoubleJump);
				SetDoubleJump(nullptr);
				SetDoubleJumpScript(nullptr);
			}
		}

		if (mPhantomBlowSmoke != nullptr)
		{
			pbstime += Time::DeltaTime();
			if (pbstime >= 0.75f)
			{
				pbstime = 0.0f;
				object::Destroy(mPhantomBlowSmoke);
				SetPhantomBlowSmoke(nullptr);
				SetPhantomBlowSmokeScript(nullptr);
			}
		}

		if (DieCheck == false && SceneManager::GetHpScript()->GetHp() <= 0 && dir ==0)
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			tr->SetPosition(Vector3(pos.x, pos.y + 0.1f, pos.z));

			DieCheck = true;
			Animator* at = GetOwner()->GetComponent<Animator>();
			at->PlayAnimation(L"LeftPlayerDie", false);
			mPlayerState =  PlayerState::Die;
			CreateDeathPhrases();
		}

		if (DieCheck == false && SceneManager::GetHpScript()->GetHp() <= 0 && dir == 1)
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			tr->SetPosition(Vector3(pos.x, pos.y + 0.1f, pos.z));

			DieCheck = true;
			Animator* at = GetOwner()->GetComponent<Animator>();
			at->PlayAnimation(L"RightPlayerDie", false);
			mPlayerState = PlayerState::Die;
			CreateDeathPhrases();
		}


		switch (mPlayerState)
		{
		case PlayerScript::PlayerState::Idle:
			Idle();
			break;
		case PlayerScript::PlayerState::Walk:
			walk();
			break;
		case PlayerScript::PlayerState::ProneStab:
			pronestab();
			break;
		case PlayerScript::PlayerState::Attack:
			attack();
			break;
		case PlayerScript::PlayerState::BladePury:
			bladepury();
			break;
		case PlayerScript::PlayerState::BladeTornado:
			bladetornado();
			break;
		case PlayerScript::PlayerState::KarmaPury:
			karmapury();
			break;
		case PlayerScript::PlayerState::PhantomBlow:
			phantomblow();
			break;
		case PlayerScript::PlayerState::Jump:
			jump();
			break;
		case PlayerScript::PlayerState::DoubleJump:
			doublejump();
			break;
		case PlayerScript::PlayerState::Alert:
			alert();
			break;
		case PlayerScript::PlayerState::Die:
			die();
			break;
		default:
			break;
		}
	}
	void PlayerScript::CreateLeftDoubleJump()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* mDoubleJump
			= object::Instantiate<GameObject>(Vector3(pos.x + 0.5f, pos.y, 0.998f), eLayerType::Skill);

		SetDoubleJump(mDoubleJump);

		mDoubleJump->SetName(L"LeftDoubleJump");


		MeshRenderer* mr = mDoubleJump->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		mDoubleJump->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 1.0005f));

		Animator* at = mDoubleJump->AddComponent<Animator>();
		mDoubleJump->AddComponent<DoubleJumpScript>();
	}
	void PlayerScript::CreateRightDoubleJump()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* mDoubleJump
			= object::Instantiate<GameObject>(Vector3(pos.x - 0.5f, pos.y, 0.998f), eLayerType::Skill);

		SetDoubleJump(mDoubleJump);

		mDoubleJump->SetName(L"RightDoubleJump");


		MeshRenderer* mr = mDoubleJump->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		mDoubleJump->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 1.0005f));

		Animator* at = mDoubleJump->AddComponent<Animator>();
		mDoubleJump->AddComponent<DoubleJumpScript>();

		DoubleJumpScript* ds = mDoubleJump->GetComponent<DoubleJumpScript>();
		ds->SetRightDoubleJump(true);
	}
	void PlayerScript::CreatePhantomBlow()
	{
		SceneManager::GetMpScript()->OnDamage(40);
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* mPhantomBlow
			= object::Instantiate<GameObject>(Vector3(pos.x - 0.9f, pos.y + 0.15f, 0.999f), eLayerType::Skill);

		SetPhantomBlow(mPhantomBlow);

		mPhantomBlow->SetName(L"LeftPhantomBlow");

		Collider2D* cd = mPhantomBlow->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(0.5f, 0.2f));

		MeshRenderer* mr = mPhantomBlow->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		mPhantomBlow->GetComponent<Transform>()->SetScale(Vector3(4.0f, 4.0f, 1.0005f));

		Animator* at = mPhantomBlow->AddComponent<Animator>();
		mPhantomBlow->AddComponent<PhantomBlowScript>();
	}
	void PlayerScript::CreatePhantomBlowSmoke()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* mPhantomBlowSmoke
			= object::Instantiate<GameObject>(Vector3(pos.x + 0.5f, pos.y, 0.999f), eLayerType::Skill);

		SetPhantomBlowSmoke(mPhantomBlowSmoke);

		mPhantomBlowSmoke->SetName(L"LeftPhantomBlowSmoke");

		MeshRenderer* mr = mPhantomBlowSmoke->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		mPhantomBlowSmoke->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 1.0005f));

		Animator* at = mPhantomBlowSmoke->AddComponent<Animator>();
		mPhantomBlowSmoke->AddComponent<PhantomBlowSmokeScript>();
	}
	void PlayerScript::CreateRightPhantomBlow()
	{
		SceneManager::GetMpScript()->OnDamage(40);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* mPhantomBlow
			= object::Instantiate<GameObject>(Vector3(pos.x + 0.9f, pos.y + 0.15f, 0.999f), eLayerType::Skill);

		SetPhantomBlow(mPhantomBlow);

		mPhantomBlow->SetName(L"RightPhantomBlow");

		Collider2D* cd = mPhantomBlow->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(0.5f, 0.2f));

		MeshRenderer* mr = mPhantomBlow->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		mPhantomBlow->GetComponent<Transform>()->SetScale(Vector3(4.0f, 4.0f, 1.0005f));

		Animator* at = mPhantomBlow->AddComponent<Animator>();
		mPhantomBlow->AddComponent<PhantomBlowScript>();

		PhantomBlowScript* ps = mPhantomBlow->GetComponent<PhantomBlowScript>();
		ps->SetRightPhantomBlow(true);
	}
	void PlayerScript::CreateRightPhantomBlowSmoke()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* mPhantomBlowSmoke
			= object::Instantiate<GameObject>(Vector3(pos.x - 0.9f, pos.y, 0.998f), eLayerType::Skill);

		SetPhantomBlowSmoke(mPhantomBlowSmoke);

		mPhantomBlowSmoke->SetName(L"RightPhantomBlowSmoke");

		MeshRenderer* mr = mPhantomBlowSmoke->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		mPhantomBlowSmoke->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 1.0005f));

		Animator* at = mPhantomBlowSmoke->AddComponent<Animator>();
		mPhantomBlowSmoke->AddComponent<PhantomBlowSmokeScript>();

		PhantomBlowSmokeScript* pbss = mPhantomBlowSmoke->GetComponent<PhantomBlowSmokeScript>();
		pbss->SetRightPhantomBlowSmoke(true);
	}
	void PlayerScript::CreatePhantomBlowHitEffect(GameObject* Monster, Vector3(pos))
	{
		Transform* tr = Monster->GetComponent<Transform>();
		pos = tr->GetPosition();

		GameObject* mPhantomBlowHitEffect
			= object::Instantiate<GameObject>(Vector3(pos.x - 0.15f, pos.y + 0.1, 0.997f), eLayerType::Effect);

		mPhantomBlowHitEffect->SetName(L"PhantomBlowHitEffect");

		MeshRenderer* mr = mPhantomBlowHitEffect->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		mPhantomBlowHitEffect->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 1.0005f));

		Animator* at = mPhantomBlowHitEffect->AddComponent<Animator>();
		mPhantomBlowHitEffect->AddComponent<PhantomBlowHitEffectScript>();
	}
	void PlayerScript::CreateBladeTornado()
	{
		SceneManager::GetMpScript()->OnDamage(40);
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* mBladeTornado
			= object::Instantiate<GameObject>(Vector3(pos.x, pos.y + 1.45f, 0.999f), eLayerType::Skill);

		SetBladeTornado(mBladeTornado);

		mBladeTornado->SetName(L"LeftBladeTornado");

		Collider2D* cd = mBladeTornado->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, -0.45f));
		cd->SetSize(Vector2(0.45f, 0.6f));


		MeshRenderer* mr = mBladeTornado->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		mBladeTornado->GetComponent<Transform>()->SetScale(Vector3(4.2f, 4.5f, 1.0005f));

		Animator* at = mBladeTornado->AddComponent<Animator>();
		mBladeTornado->AddComponent<BladeTornadoScript>();

	}
	void PlayerScript::CreateRightBladeTornado()
	{
		SceneManager::GetMpScript()->OnDamage(40);
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* mBladeTornado
			= object::Instantiate<GameObject>(Vector3(pos.x, pos.y + 1.45f, 0.999f), eLayerType::Skill);

		SetBladeTornado(mBladeTornado);

		mBladeTornado->SetName(L"RightBladeTornado");

		Collider2D* cd = mBladeTornado->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, -0.45f));
		cd->SetSize(Vector2(0.45f, 0.6f));

		MeshRenderer* mr = mBladeTornado->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		mBladeTornado->GetComponent<Transform>()->SetScale(Vector3(4.2f, 4.5f, 1.0005f));

		Animator* at = mBladeTornado->AddComponent<Animator>();
		mBladeTornado->AddComponent<BladeTornadoScript>();

		BladeTornadoScript* bs = mBladeTornado->GetComponent<BladeTornadoScript>();
		bs->SetRightBladeTornado(true);
	}
	void PlayerScript::CreateBladeTornadoHitEffect(GameObject* Monster, Vector3(pos))
	{
		Transform* tr = Monster->GetComponent<Transform>();
		pos = tr->GetPosition();

		GameObject* mBladeTornadoHitEffect
			= object::Instantiate<GameObject>(Vector3(pos.x - 0.15f, pos.y + 0.1, 0.9975f), eLayerType::Effect);

		mBladeTornadoHitEffect->SetName(L"BladeTornadoHitEffect");

		MeshRenderer* mr = mBladeTornadoHitEffect->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		mBladeTornadoHitEffect->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

		Animator* at = mBladeTornadoHitEffect->AddComponent<Animator>();
		mBladeTornadoHitEffect->AddComponent<BladeTornadoHitEffectScript>();
	}
	void PlayerScript::CreateBladePury()
	{
		SceneManager::GetMpScript()->OnDamage(40);
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* mBladePury
			= object::Instantiate<GameObject>(Vector3(pos.x - 0.2f, pos.y + 0.5f, 0.9991f), eLayerType::Skill);

		SetBladePury(mBladePury);

		mBladePury->SetName(L"LeftBladePury");

		Collider2D* cd = mBladePury->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.1f, -0.25f));
		cd->SetSize(Vector2(0.6f, 0.3f));

		MeshRenderer* mr = mBladePury->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		mBladePury->GetComponent<Transform>()->SetScale(Vector3(4.0f, 4.0f, 1.0005f));

		Animator* at = mBladePury->AddComponent<Animator>();
		mBladePury->AddComponent<BladePuryScript>();
	}
	void PlayerScript::CreateRightBladePury()
	{
		SceneManager::GetMpScript()->OnDamage(40);
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* mBladePury
			= object::Instantiate<GameObject>(Vector3(pos.x + 0.2f, pos.y + 0.5f, 0.9991f), eLayerType::Skill);

		SetBladePury(mBladePury);

		mBladePury->SetName(L"RightBladePury");

		Collider2D* cd = mBladePury->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.1f, -0.25f));
		cd->SetSize(Vector2(0.6f, 0.3f));

		MeshRenderer* mr = mBladePury->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		mBladePury->GetComponent<Transform>()->SetScale(Vector3(4.0f, 4.0f, 1.0005f));

		Animator* at = mBladePury->AddComponent<Animator>();
		mBladePury->AddComponent<BladePuryScript>();

		BladePuryScript* bs = mBladePury->GetComponent<BladePuryScript>();
		bs->SetRightBladePury(true);
	}
	void PlayerScript::CreateBladePuryHitEffect(GameObject* Monster, Vector3(pos))
	{
		Transform* tr = Monster->GetComponent<Transform>();
		pos = tr->GetPosition();

		GameObject* mBladePuryHitEffect
			= object::Instantiate<GameObject>(Vector3(pos.x - 0.15f, pos.y + 0.1, 0.997f), eLayerType::Effect);

		mBladePuryHitEffect->SetName(L"BladePuryHitEffect");

		MeshRenderer* mr = mBladePuryHitEffect->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		mBladePuryHitEffect->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 1.0005f));

		Animator* at = mBladePuryHitEffect->AddComponent<Animator>();
		mBladePuryHitEffect->AddComponent<BladePuryHitEffectScript>();
	}
	void PlayerScript::CreateCaremaPury()
	{
		SceneManager::GetMpScript()->OnDamage(40);
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* KarmaPury
			= object::Instantiate<GameObject>(Vector3(pos.x + 0.2f, pos.y + 0.8f, 0.999f), eLayerType::Skill);

		SetCaremaPury(KarmaPury);

		KarmaPury->SetName(L"LeftKarmaPury");

		Collider2D* cd = KarmaPury->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, -0.5f));
		cd->SetSize(Vector2(1.0f, 0.6f));

		MeshRenderer* mr = KarmaPury->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		KarmaPury->GetComponent<Transform>()->SetScale(Vector3(9.0f, 9.0f, 1.0005f));

		Animator* at = KarmaPury->AddComponent<Animator>();
		KarmaPury->AddComponent<CaremaPuryScript>();
	}
	void PlayerScript::CreateRightCaremaPury()
	{
		SceneManager::GetMpScript()->OnDamage(40);
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* KarmaPury
			= object::Instantiate<GameObject>(Vector3(pos.x + 0.2f, pos.y + 0.8f, 0.999f), eLayerType::Skill);

		SetCaremaPury(KarmaPury);

		KarmaPury->SetName(L"RightKarmaPury");

		Collider2D* cd = KarmaPury->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, -0.5f));
		cd->SetSize(Vector2(1.0f, 0.6f));

		MeshRenderer* mr = KarmaPury->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		KarmaPury->GetComponent<Transform>()->SetScale(Vector3(9.0f, 9.0f, 1.0005f));

		Animator* at = KarmaPury->AddComponent<Animator>();
		KarmaPury->AddComponent<CaremaPuryScript>();

		CaremaPuryScript* cs = KarmaPury->GetComponent<CaremaPuryScript>();
		cs->SetRightCaremaPury(true);
	}
	void PlayerScript::CreateCaremaPuryHitEffect(GameObject* Monster, Vector3(pos))
	{
		Transform* tr = Monster->GetComponent<Transform>();
		pos = tr->GetPosition();

		GameObject* mKarmaPuryHitEffect
			= object::Instantiate<GameObject>(Vector3(pos.x - 0.15f, pos.y + 0.1, 0.997f), eLayerType::Effect);

		mKarmaPuryHitEffect->SetName(L"KarmaPuryHitEffect");

		MeshRenderer* mr = mKarmaPuryHitEffect->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		mKarmaPuryHitEffect->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 1.0005f));

		Animator* at = mKarmaPuryHitEffect->AddComponent<Animator>();
		mKarmaPuryHitEffect->AddComponent<KarmaPuryHitEffectScript>();
	}
	void PlayerScript::CreateSkillUI()
	{
		{
			GameObject* mSkillUI
				= object::Instantiate<GameObject>(Vector3(0.3f, 0.6f, 1.0f), eLayerType::UI);

			mSkillUI->SetName(L"SkillUI");

			SetSkillUI(mSkillUI);

			MeshRenderer* mr = mSkillUI->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"skillui"));

			mSkillUI->GetComponent<Transform>()->SetScale(Vector3(2.3f, 2.3f, 1.000f));

			SkillUIScript* sus = mSkillUI->AddComponent<SkillUIScript>();
			//SceneManager::SetSkillUIScript(sus);
		}

		{
			GameObject* mBladePuryUI
				= object::Instantiate<GameObject>(Vector3(-0.65f, 1.055f, 0.99f), eLayerType::UI);

			mBladePuryUI->SetName(L"BladePuryUI");

			SetBladePuryUI(mBladePuryUI);

			MeshRenderer* mr = mBladePuryUI->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"bladepuryui"));

			mBladePuryUI->GetComponent<Transform>()->SetScale(Vector3(0.225f, 0.225f, 1.000f));
		}

		{
			GameObject* mPhantomBlowUI
				= object::Instantiate<GameObject>(Vector3(-0.65f, 0.81f, 0.99f), eLayerType::UI);

			mPhantomBlowUI->SetName(L"PhantomBlowUI");

			SetPhantomBlowUI(mPhantomBlowUI);

			MeshRenderer* mr = mPhantomBlowUI->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"phantomblowui"));

			mPhantomBlowUI->GetComponent<Transform>()->SetScale(Vector3(0.225f, 0.225f, 1.000f));
		}

		{
			GameObject* mBladeTornadoUI
				= object::Instantiate<GameObject>(Vector3(-0.65f, 0.565f, 0.99f), eLayerType::UI);

			mBladeTornadoUI->SetName(L"BladeTornadoUI");

			SetBladeTornadoUI(mBladeTornadoUI);

			MeshRenderer* mr = mBladeTornadoUI->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"bladetornadoui"));

			mBladeTornadoUI->GetComponent<Transform>()->SetScale(Vector3(0.225f, 0.225f, 1.000f));
		}

		{
			GameObject* mKarmaPuryUI
				= object::Instantiate<GameObject>(Vector3(-0.65f, 0.32f, 0.99f), eLayerType::UI);

			mKarmaPuryUI->SetName(L"KarmaPuryUI");

			SetKarmaPuryUI(mKarmaPuryUI);

			MeshRenderer* mr = mKarmaPuryUI->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"karmapuryui"));

			mKarmaPuryUI->GetComponent<Transform>()->SetScale(Vector3(0.225f, 0.225f, 1.000f));
		}
	}
	void PlayerScript::CloseSkillUI()
	{
		object::Destroy(mSkillUI);
		object::Destroy(mBladePuryUI);
		object::Destroy(mPhantomBlowUI);
		object::Destroy(mBladeTornadoUI);
		object::Destroy(mKarmaPuryUI);
	}

	void PlayerScript::CreateDamage(GameObject* Monster, Vector3 Pos)
	{
		AttackDamage = dist4(rng4);

		{
			GameObject* mDamage
				= object::Instantiate<GameObject>(Vector3(Pos.x - 0.3f, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

			mDamage->SetName(L"Damage1");

			MeshRenderer* mr = mDamage->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			mDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

			Animator* at = mDamage->AddComponent<Animator>();
			DamageScript* mDamageScript = mDamage->AddComponent<DamageScript>();
			mDamageScript->SetDamage(AttackDamage);
		}
		{
			GameObject* mDamage
				= object::Instantiate<GameObject>(Vector3(Pos.x - 0.15f, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

			mDamage->SetName(L"Damage2");

			MeshRenderer* mr = mDamage->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			mDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

			Animator* at = mDamage->AddComponent<Animator>();
			DamageScript* mDamageScript = mDamage->AddComponent<DamageScript>();
			mDamageScript->SetDamage(AttackDamage);

		}
		{
			GameObject* mDamage
				= object::Instantiate<GameObject>(Vector3(Pos.x, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

			mDamage->SetName(L"Damage3");

			MeshRenderer* mr = mDamage->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			mDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

			Animator* at = mDamage->AddComponent<Animator>();
			DamageScript* mDamageScript = mDamage->AddComponent<DamageScript>();
			mDamageScript->SetDamage(AttackDamage);
		}
		{
			GameObject* mDamage
				= object::Instantiate<GameObject>(Vector3(Pos.x + 0.15f, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

			mDamage->SetName(L"Damage4");

			MeshRenderer* mr = mDamage->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			mDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

			Animator* at = mDamage->AddComponent<Animator>();
			DamageScript* mDamageScript = mDamage->AddComponent<DamageScript>();
			mDamageScript->SetDamage(AttackDamage);
		}
		{
			GameObject* mDamage
				= object::Instantiate<GameObject>(Vector3(Pos.x + 0.3f, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

			mDamage->SetName(L"Damage5");

			MeshRenderer* mr = mDamage->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			mDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

			Animator* at = mDamage->AddComponent<Animator>();
			DamageScript* mDamageScript = mDamage->AddComponent<DamageScript>();
			mDamageScript->SetDamage(AttackDamage);
		}

	}

	void PlayerScript::CreateHitDamage(GameObject* Monster, Vector3 Pos)
	{
		if (HitMushroom)
		{
			HitMushroom = false;
			HitDamage = dist5(rng5);
			SceneManager::GetHpScript()->OnDamage(HitDamage);
		}

		if (HitFireImp)
		{
			HitFireImp = false;
			HitDamage = dist6(rng6);
			SceneManager::GetHpScript()->OnDamage(HitDamage);
		}

		if (HitBanBan)
		{
			HitBanBan = false;
			HitDamage = dist7(rng7);
			SceneManager::GetHpScript()->OnDamage(HitDamage);
		}

		if (HitBall)
		{
			HitBall = false;
			HitDamage = 99999;
			SceneManager::GetHpScript()->OnDamage(HitDamage);
		}

		if (EarthQuake)
		{
			EarthQuake = false;
			HitDamage = 99999;
			SceneManager::GetHpScript()->OnDamage(HitDamage);
		}

		if (99 < HitDamage && HitDamage < 1000)
		{
			{
				GameObject* mHitDamage
					= object::Instantiate<GameObject>(Vector3(Pos.x - 0.15f, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

				mHitDamage->SetName(L"HitDamage1");

				MeshRenderer* mr = mHitDamage->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

				mHitDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

				Animator* at = mHitDamage->AddComponent<Animator>();
				HitDamageScript* mHitDamageScript = mHitDamage->AddComponent<HitDamageScript>();
				mHitDamageScript->SetHitDamage(HitDamage);
			}
			{
				GameObject* mHitDamage
					= object::Instantiate<GameObject>(Vector3(Pos.x , Pos.y + 0.3f, 0.997f), eLayerType::Damage);

				mHitDamage->SetName(L"HitDamage2");

				MeshRenderer* mr = mHitDamage->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

				mHitDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

				Animator* at = mHitDamage->AddComponent<Animator>();
				HitDamageScript* mHitDamageScript = mHitDamage->AddComponent<HitDamageScript>();
				mHitDamageScript->SetHitDamage(HitDamage);

			}
			{
				GameObject* mHitDamage
					= object::Instantiate<GameObject>(Vector3(Pos.x + 0.15f, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

				mHitDamage->SetName(L"HitDamage3");

				MeshRenderer* mr = mHitDamage->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

				mHitDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

				Animator* at = mHitDamage->AddComponent<Animator>();
				HitDamageScript* mHitDamageScript = mHitDamage->AddComponent<HitDamageScript>();
				mHitDamageScript->SetHitDamage(HitDamage);
			}
		}

		if (999 < HitDamage && HitDamage < 10000)
		{
			{
				GameObject* mHitDamage
					= object::Instantiate<GameObject>(Vector3(Pos.x - 0.15f, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

				mHitDamage->SetName(L"HitDamage1");

				MeshRenderer* mr = mHitDamage->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

				mHitDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

				Animator* at = mHitDamage->AddComponent<Animator>();
				HitDamageScript* mHitDamageScript = mHitDamage->AddComponent<HitDamageScript>();
				mHitDamageScript->SetHitDamage(HitDamage);
			}
			{
				GameObject* mHitDamage
					= object::Instantiate<GameObject>(Vector3(Pos.x, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

				mHitDamage->SetName(L"HitDamage2");

				MeshRenderer* mr = mHitDamage->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

				mHitDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

				Animator* at = mHitDamage->AddComponent<Animator>();
				HitDamageScript* mHitDamageScript = mHitDamage->AddComponent<HitDamageScript>();
				mHitDamageScript->SetHitDamage(HitDamage);

			}
			{
				GameObject* mHitDamage
					= object::Instantiate<GameObject>(Vector3(Pos.x + 0.15f, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

				mHitDamage->SetName(L"HitDamage3");

				MeshRenderer* mr = mHitDamage->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

				mHitDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

				Animator* at = mHitDamage->AddComponent<Animator>();
				HitDamageScript* mHitDamageScript = mHitDamage->AddComponent<HitDamageScript>();
				mHitDamageScript->SetHitDamage(HitDamage);
			}
			{
				GameObject* mHitDamage
					= object::Instantiate<GameObject>(Vector3(Pos.x + 0.3f, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

				mHitDamage->SetName(L"HitDamage4");

				MeshRenderer* mr = mHitDamage->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

				mHitDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

				Animator* at = mHitDamage->AddComponent<Animator>();
				HitDamageScript* mHitDamageScript = mHitDamage->AddComponent<HitDamageScript>();
				mHitDamageScript->SetHitDamage(HitDamage);
			}
		}


		if (9999 < HitDamage && HitDamage < 100000)
		{
			{
				GameObject* mHitDamage
					= object::Instantiate<GameObject>(Vector3(Pos.x - 0.3f, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

				mHitDamage->SetName(L"HitDamage1");

				MeshRenderer* mr = mHitDamage->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

				mHitDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

				Animator* at = mHitDamage->AddComponent<Animator>();
				HitDamageScript* mHitDamageScript = mHitDamage->AddComponent<HitDamageScript>();
				mHitDamageScript->SetHitDamage(HitDamage);
			}
			{
				GameObject* mHitDamage
					= object::Instantiate<GameObject>(Vector3(Pos.x - 0.15f, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

				mHitDamage->SetName(L"HitDamage2");

				MeshRenderer* mr = mHitDamage->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

				mHitDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

				Animator* at = mHitDamage->AddComponent<Animator>();
				HitDamageScript* mHitDamageScript = mHitDamage->AddComponent<HitDamageScript>();
				mHitDamageScript->SetHitDamage(HitDamage);

			}
			{
				GameObject* mHitDamage
					= object::Instantiate<GameObject>(Vector3(Pos.x, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

				mHitDamage->SetName(L"HitDamage3");

				MeshRenderer* mr = mHitDamage->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

				mHitDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

				Animator* at = mHitDamage->AddComponent<Animator>();
				HitDamageScript* mHitDamageScript = mHitDamage->AddComponent<HitDamageScript>();
				mHitDamageScript->SetHitDamage(HitDamage);
			}
			{
				GameObject* mHitDamage
					= object::Instantiate<GameObject>(Vector3(Pos.x + 0.15f, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

				mHitDamage->SetName(L"HitDamage4");

				MeshRenderer* mr = mHitDamage->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

				mHitDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

				Animator* at = mHitDamage->AddComponent<Animator>();
				HitDamageScript* mHitDamageScript = mHitDamage->AddComponent<HitDamageScript>();
				mHitDamageScript->SetHitDamage(HitDamage);
			}
			{
				GameObject* mHitDamage
					= object::Instantiate<GameObject>(Vector3(Pos.x + 0.3f, Pos.y + 0.3f, 0.997f), eLayerType::Damage);

				mHitDamage->SetName(L"HitDamage5");

				MeshRenderer* mr = mHitDamage->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

				mHitDamage->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0005f));

				Animator* at = mHitDamage->AddComponent<Animator>();
				HitDamageScript* mHitDamageScript = mHitDamage->AddComponent<HitDamageScript>();
				mHitDamageScript->SetHitDamage(HitDamage);
			}
		}
	}

	void PlayerScript::CreateDeathPhrases()
	{
		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector3 pos = tr->GetPosition();

		{
			GameObject* DeathPhrases
				= object::Instantiate<GameObject>(Vector3(0.0f, 0.9f, 0.997f), eLayerType::UI);

			DeathPhrases->SetName(L"DeathPhrases");

			SetDeathPhrases(DeathPhrases);

			MeshRenderer* mr = DeathPhrases->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"deathphrases"));

			DeathPhrases->GetComponent<Transform>()->SetScale(Vector3(1.7f, 1.0f, 1.0005f));
		}
		//{
		//	GameObject* DeathPhrasesOK
		//		= object::Instantiate<GameObject>(Vector3(pos.x + 0.15f, pos.y + 1.2f, 0.997f), eLayerType::Player);

		//	DeathPhrasesOK->SetName(L"DeathPhrasesOK");

		//	MeshRenderer* mr = DeathPhrasesOK->AddComponent<MeshRenderer>();
		//	mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//	mr->SetMaterial(Resources::Find<Material>(L"deathphrasesok"));

		//	DeathPhrasesOK->GetComponent<Transform>()->SetScale(Vector3(1.0f, 1.0f, 1.0005f));
		//}
	}
	
	void PlayerScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"MushRoom")
		{
			hit = true;
			HitMushroom = true;
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();

			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp1")
		{
			hit = true;
			HitFireImp = true;
			//FireImpScript* mFireImpScript = other->GetOwner()->GetComponent<FireImpScript>();
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp2")
		{
			hit = true;
			HitFireImp = true;
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp3")
		{
			hit = true;
			HitFireImp = true;
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp4")
		{
			hit = true;
			HitFireImp = true;
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp5")
		{
			hit = true;
			HitFireImp = true;
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp6")
		{
			hit = true;
			HitFireImp = true;
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp7")
		{
			hit = true;
			HitFireImp = true;
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp8")
		{
			hit = true;
			HitFireImp = true;
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp9")
		{
			hit = true;
			HitFireImp = true;
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp10")
		{
			hit = true;
			HitFireImp = true;
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}
		if (other->GetOwner()->GetName() == L"FireImp11")
		{
			hit = true;
			HitFireImp = true;
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}

		if (other->GetOwner()->GetName() == L"Ground")
		{
			RigidBody* rb = GetOwner()->GetComponent<RigidBody>();
			rb->SetGround(true);
		}

		if (other->GetOwner()->GetName() == L"Portal3")
		{
			portal = true;
		}

		if (other->GetOwner()->GetName() == L"Portal6")
		{
			portal = true;
		}

		if (other->GetOwner()->GetName() == L"BanBan")
		{
			hit = true;
			HitBanBan = true;
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}

		if (other->GetOwner()->GetName() == L"LeftBall")
		{
			hit = true;
			HitBall = true;
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}

		if (other->GetOwner()->GetName() == L"RightBall")
		{
			hit = true;
			HitBall = true;
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			CreateHitDamage(other->GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));
		}

	}
	void PlayerScript::OnCollisionStay(Collider2D* other)
	{


	}
	void PlayerScript::OnCollisionExit(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Portal")
		{
			portal = false;
		}
	}
	void PlayerScript::Idle()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Animator* at = GetOwner()->GetComponent<Animator>();
		//Animator* at = GetOwner()->GetComponent<Animator>();

		if (dir == 0)
		{
			if (hit == true)
			{
				at->PlayAnimation(L"Alert", true);
				mPlayerState = PlayerState::Alert;
				hit = false;
			}
		}
		if (dir == 0)
		{
			if (Input::GetKey(eKeyCode::LEFT))
			{
				dir = 0;
				at->PlayAnimation(L"LeftWalk", true);
				mPlayerState = PlayerState::Walk;
			}

			if (Input::GetKey(eKeyCode::RIGHT))
			{
				dir = 1;
				at->PlayAnimation(L"RightWalk", true);
				mPlayerState = PlayerState::Walk;
			}

			if (Input::GetKey(eKeyCode::DOWN))
			{
				dir = 0;
				at->PlayAnimation(L"Prone", false);
				mPlayerState = PlayerState::ProneStab;
			}

			if (Input::GetKeyDown(eKeyCode::Z))
			{
				SceneManager::GetHpScript()->SetHP(99999);
				SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -1.95f, 1.000f));
				SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));

				SceneManager::GetMpScript()->SetMP(2000);
				SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -2.05f, 1.000f));
				SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));
			}


			if (Input::GetKeyDown(eKeyCode::V))
			{
				dir = 0;
				mPlayerState = PlayerState::BladePury;
				at->PlayAnimation(L"LeftAttack", false);

				if (mBladePury == nullptr)
				{
					CreateBladePury();
					
				}
			}

			if (Input::GetKeyDown(eKeyCode::B))
			{
				dir = 0;
				mPlayerState = PlayerState::PhantomBlow;
				at->PlayAnimation(L"LeftAttack", false);

				if (mPhantomBlow == nullptr)
				{
					CreatePhantomBlow();
					CreatePhantomBlowSmoke();
				}
			}

			if (Input::GetKeyDown(eKeyCode::D))
			{
				dir = 0;
				mPlayerState = PlayerState::Attack;
				at->PlayAnimation(L"LeftAttack", false);

				if (mBladeTornado == nullptr && mCaremaPury == nullptr)
				{
					CreateBladeTornado();
				}
			}

			if (Input::GetKeyDown(eKeyCode::F))
			{
				dir = 0;
				mPlayerState = PlayerState::Attack;
				at->PlayAnimation(L"LeftAttack", false);

				if (mCaremaPury == nullptr && mBladeTornado == nullptr)
				{
					CreateCaremaPury();
				}
			}

			if (Input::GetKeyDown(eKeyCode::X))
			{
				isjump = true;
				RigidBody* mRigidBody = GetOwner()->GetComponent<RigidBody>();

				mRigidBody->SetGround(false);
				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.y += 2.0f;
				mRigidBody->SetVelocity(velocity);
				dir = 0;
				at->PlayAnimation(L"LeftJump", false);
				mPlayerState = PlayerState::Jump;
			}
		}


		if (dir == 1)
		{
			if (hit == true)
			{
				at->PlayAnimation(L"RightAlert", true);
				mPlayerState = PlayerState::Alert;
				hit = false;
			}
		}
		if (dir == 1)
		{
			if (Input::GetKey(eKeyCode::LEFT))
			{
				dir = 0;
				at->PlayAnimation(L"LeftWalk", true);
				mPlayerState = PlayerState::Walk;
			}

			if (Input::GetKey(eKeyCode::RIGHT))
			{
				dir = 1;
				at->PlayAnimation(L"RightWalk", true);
				mPlayerState = PlayerState::Walk;
			}

			if (Input::GetKey(eKeyCode::DOWN))
			{
				dir = 1;
				at->PlayAnimation(L"RightProne", false);
				mPlayerState = PlayerState::ProneStab;
			}

			if (Input::GetKeyDown(eKeyCode::Z))
			{
				SceneManager::GetHpScript()->SetHP(99999);
				SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -1.95f, 1.000f));
				SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));

				SceneManager::GetMpScript()->SetMP(2000);
				SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -2.05f, 1.000f));
				SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));
			}

			if (Input::GetKeyDown(eKeyCode::D))
			{
				dir = 1;
				mPlayerState = PlayerState::Attack;
				at->PlayAnimation(L"RightAttack", false);

				if (mBladeTornado == nullptr && mCaremaPury == nullptr)
				{
					CreateRightBladeTornado();
				}
			}

			if (Input::GetKeyDown(eKeyCode::V))
			{
				dir = 1;
				mPlayerState = PlayerState::BladePury;
				at->PlayAnimation(L"RightAttack", false);

				if (mBladePury == nullptr)
				{
					CreateRightBladePury();
				}
			}

			if (Input::GetKeyDown(eKeyCode::F))
			{
				dir = 1;
				mPlayerState = PlayerState::Attack;
				at->PlayAnimation(L"RightAttack", false);

				if (mCaremaPury == nullptr && mBladeTornado == nullptr)
				{
					CreateRightCaremaPury();
				}
			}

			if (Input::GetKeyDown(eKeyCode::B))
			{
				dir = 1;
				mPlayerState = PlayerState::PhantomBlow;
				at->PlayAnimation(L"RightAttack", false);

				if (mPhantomBlow == nullptr)
				{
					CreateRightPhantomBlow();
					CreateRightPhantomBlowSmoke();
				}
			}
			if (Input::GetKeyDown(eKeyCode::X))
			{
				isjump = true;
				RigidBody* mRigidBody = GetOwner()->GetComponent<RigidBody>();

				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.y += 2.0f;
				mRigidBody->SetVelocity(velocity);
				mRigidBody->SetGround(false);

				mRigidBody->SetVelocity(velocity);
				dir = 1;
				at->PlayAnimation(L"RightJump", false);
				mPlayerState = PlayerState::Jump;
			}
		}
	}
	void PlayerScript::walk()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Animator* at = GetOwner()->GetComponent<Animator>();

		if (dir == 0)
		{
			if (hit == true)
			{
				RigidBody* mRigidBody = GetOwner()->GetComponent<RigidBody>();
				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.x += 0.4f;
				velocity.y += 0.8f;
				mRigidBody->SetVelocity(velocity);
				mRigidBody->SetGround(false);

				at->PlayAnimation(L"Alert", true);
				mPlayerState = PlayerState::Alert;
				hit = false;
			}
			if (Input::GetKey(eKeyCode::LEFT))
			{
				pos.x -= 1.2f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
			if (Input::GetKeyUp(eKeyCode::LEFT))
			{
				dir = 0;
				mPlayerState = PlayerState::Idle;
				at->PlayAnimation(L"LeftIdle", true);
			}
			if (Input::GetKey(eKeyCode::RIGHT))
			{
				dir = 1;
				at->PlayAnimation(L"RightWalk", true);
				pos.x += 1.2f * Time::DeltaTime();
				tr->SetPosition(pos);
			}

			if (Input::GetKeyDown(eKeyCode::Z))
			{
				SceneManager::GetHpScript()->SetHP(99999);
				SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -1.95f, 1.000f));
				SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));

				SceneManager::GetMpScript()->SetMP(2000);
				SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -2.05f, 1.000f));
				SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));
			}

			if (Input::GetKeyDown(eKeyCode::V))
			{
				dir = 0;
				mPlayerState = PlayerState::BladePury;
				at->PlayAnimation(L"LeftAttack", false);

				if (mBladePury == nullptr)
				{
					CreateBladePury();
				}
			}

			if (Input::GetKeyDown(eKeyCode::B))
			{
				dir = 0;
				mPlayerState = PlayerState::PhantomBlow;
				at->PlayAnimation(L"LeftAttack", false);

				if (mPhantomBlow == nullptr)
				{
					CreatePhantomBlow();
					CreatePhantomBlowSmoke();
				}
			}

			if (Input::GetKeyDown(eKeyCode::D))
			{
				dir = 0;
				mPlayerState = PlayerState::Attack;
				at->PlayAnimation(L"LeftAttack", false);

				if (mBladeTornado == nullptr && mCaremaPury == nullptr)
				{
					CreateBladeTornado();
				}
			}

			if (Input::GetKeyDown(eKeyCode::F))
			{
				dir = 0;
				mPlayerState = PlayerState::Attack;
				at->PlayAnimation(L"LeftAttack", false);

				if (mCaremaPury == nullptr && mBladeTornado == nullptr)
				{
					CreateCaremaPury();
				}
			}

			if (Input::GetKeyDown(eKeyCode::X))
			{
				isjump = true;
				RigidBody* mRigidBody = GetOwner()->GetComponent<RigidBody>();

				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.x -= 1.0f;
				velocity.y += 2.5f;
				mRigidBody->SetVelocity(velocity);
				mRigidBody->SetGround(false);

				mRigidBody->SetVelocity(velocity);
				dir = 0;
				at->PlayAnimation(L"LeftJump", false);
				mPlayerState = PlayerState::Jump;
			}
		}

		if (dir == 1)
		{
			if (hit == true)
			{
				RigidBody* mRigidBody = GetOwner()->GetComponent<RigidBody>();
				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.x -= 0.4f;
				velocity.y += 0.8f;
				mRigidBody->SetVelocity(velocity);
				mRigidBody->SetGround(false);

				at->PlayAnimation(L"RightAlert", true);
				mPlayerState = PlayerState::Alert;
				hit = false;
			}
			if (Input::GetKey(eKeyCode::LEFT))
			{
				dir = 0;
				at->PlayAnimation(L"LeftWalk", true);
				pos.x -= 1.2f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
			if (Input::GetKey(eKeyCode::RIGHT))
			{
				pos.x += 1.2f * Time::DeltaTime();
				tr->SetPosition(pos);
			}
			if (Input::GetKeyUp(eKeyCode::RIGHT))
			{
				dir = 1;
				mPlayerState = PlayerState::Idle;
				at->PlayAnimation(L"RightIdle", true);
			}

			if (Input::GetKeyDown(eKeyCode::Z))
			{
				SceneManager::GetHpScript()->SetHP(99999);
				SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -1.95f, 1.000f));
				SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));

				SceneManager::GetMpScript()->SetMP(2000);
				SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -2.05f, 1.000f));
				SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));
			}

			if (Input::GetKeyDown(eKeyCode::D))
			{
				dir = 1;
				mPlayerState = PlayerState::Attack;
				at->PlayAnimation(L"RightAttack", false);

				if (mBladeTornado == nullptr && mCaremaPury == nullptr)
				{
					CreateRightBladeTornado();
				}
			}

			if (Input::GetKeyDown(eKeyCode::V))
			{
				dir = 1;
				mPlayerState = PlayerState::BladePury;
				at->PlayAnimation(L"RightAttack", false);

				if (mBladePury == nullptr)
				{
					CreateRightBladePury();
				}
			}

			if (Input::GetKeyDown(eKeyCode::F))
			{
				dir = 1;
				mPlayerState = PlayerState::Attack;
				at->PlayAnimation(L"RightAttack", false);

				if (mCaremaPury == nullptr && mBladeTornado == nullptr)
				{
					CreateRightCaremaPury();
				}
			}

			if (Input::GetKeyDown(eKeyCode::B))
			{
				dir = 1;
				mPlayerState = PlayerState::PhantomBlow;
				at->PlayAnimation(L"RightAttack", false);

				if (mPhantomBlow == nullptr)
				{
					CreateRightPhantomBlow();
					CreateRightPhantomBlowSmoke();
				}
			}

			if (Input::GetKeyDown(eKeyCode::X))
			{
				isjump = true;
				RigidBody* mRigidBody = GetOwner()->GetComponent<RigidBody>();

				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.x += 1.0f;
				velocity.y += 2.5f;
				mRigidBody->SetVelocity(velocity);
				mRigidBody->SetGround(false);

				mRigidBody->SetVelocity(velocity);
				dir = 1;
				at->PlayAnimation(L"RightJump", false);
				mPlayerState = PlayerState::Jump;
			}
		}
	}
	void PlayerScript::pronestab()
	{
		Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
		cd->SetCenter(Vector2(0.008f, -0.05f));
		cd->SetSize(Vector2(0.18f, 0.14f));

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Animator* at = GetOwner()->GetComponent<Animator>();

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			SceneManager::GetHpScript()->SetHP(99999);
			SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -1.95f, 1.000f));
			SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));

			SceneManager::GetMpScript()->SetMP(2000);
			SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -2.05f, 1.000f));
			SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));
		}

		if (dir == 0)
		{
			if (Input::GetKeyUp(eKeyCode::DOWN))
			{
				dir = 0;
				mPlayerState = PlayerState::Idle;
				at->PlayAnimation(L"LeftIdle", true);
			}
		}
		if (dir == 1)
		{
			if (Input::GetKeyUp(eKeyCode::DOWN))
			{
				dir = 1;
				mPlayerState = PlayerState::Idle;
				at->PlayAnimation(L"RightIdle", false);
			}
		}
	}
	void PlayerScript::attack()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Animator* at = GetOwner()->GetComponent<Animator>();

		attacktime += Time::DeltaTime();

		if (mBladeTornado != nullptr && mCaremaPury == nullptr)
		{
			if (Input::GetKeyDown(eKeyCode::F))
			{
				CreateCaremaPury();
			}
		}

		if (attacktime >= 0.6f)
		{
			attacktime = 0.0f;
			mPlayerState = PlayerState::Idle;
			if (dir == 0)
			{
				at->PlayAnimation(L"LeftIdle", true);
			}
			if (dir == 1)
			{
				at->PlayAnimation(L"RightIdle", true);
			}
		}
	}
	void PlayerScript::bladepury()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Animator* at = GetOwner()->GetComponent<Animator>();

		attacktime += Time::DeltaTime();

		if (attacktime >= 0.7f)
		{
			mPlayerState = PlayerState::Idle;
			attacktime = 0.0f;
			if (dir == 0)
			{
				at->PlayAnimation(L"LeftIdle", true);
			}
			if (dir == 1)
			{
				at->PlayAnimation(L"RightIdle", true);
			}
		}
	}
	void PlayerScript::bladetornado()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Animator* at = GetOwner()->GetComponent<Animator>();

		attacktime += Time::DeltaTime();

		if (attacktime >= 1.47f)
		{
			mPlayerState = PlayerState::Idle;
			attacktime = 0.0f;
			if (dir == 0)
			{
				at->PlayAnimation(L"LeftIdle", true);
			}
			if (dir == 1)
			{
				at->PlayAnimation(L"RightIdle", true);
			}
		}
	}
	void PlayerScript::karmapury()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Animator* at = GetOwner()->GetComponent<Animator>();

		attacktime += Time::DeltaTime();

		if (attacktime >= 1.3f)
		{
			mPlayerState = PlayerState::Idle;
			attacktime = 0.0f;
			if (dir == 0)
			{
				at->PlayAnimation(L"LeftIdle", true);
			}
			if (dir == 1)
			{
				at->PlayAnimation(L"RightIdle", true);
			}
		}
	}
	void PlayerScript::phantomblow()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Animator* at = GetOwner()->GetComponent<Animator>();

		attacktime += Time::DeltaTime();

		if (attacktime >= 0.75f)
		{
			mPlayerState = PlayerState::Idle;
			attacktime = 0.0f;
			if (dir == 0)
			{
				at->PlayAnimation(L"LeftIdle", true);
			}
			if (dir == 1)
			{
				at->PlayAnimation(L"RightIdle", true);
			}
		}
	}
	void PlayerScript::jump()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Animator* at = GetOwner()->GetComponent<Animator>();

		RigidBody* mRigidBody = GetOwner()->GetComponent<RigidBody>();



		jumptime += Time::DeltaTime();

		if (jumptime >= 0.15f && isjump == true && mRigidBody->GetGround() == false)
		{
			if (Input::GetKeyDown(eKeyCode::X))
			{
				if (dir == 0)
				{
					jumptime = 0.0f;
					isjump = false;
					jumpdouble = true;
					CreateLeftDoubleJump();
					mPlayerState = PlayerState::DoubleJump;
					at->PlayAnimation(L"LeftJump", true);
				}
				if (dir == 1)
				{
					jumptime = 0.0f;
					isjump = false;
					jumpdouble = true;
					CreateRightDoubleJump();
					mPlayerState = PlayerState::DoubleJump;
					at->PlayAnimation(L"RightJump", true);
				}
			}
		}

		//if (dir == 0)
		//{
		//	if (Input::GetKeyDown(eKeyCode::D))
		//	{
		//		dir = 0;
		//		mPlayerState = PlayerState::Attack;
		//		at->PlayAnimation(L"LeftAttack", false);

		//		if (mBladeTornado == nullptr && mCaremaPury == nullptr)
		//		{
		//			CreateBladeTornado();
		//			SceneManager::GetMpScript()->OnDamage(40);
		//		}
		//	}

			//if (Input::GetKeyDown(eKeyCode::F))
			//{
			//	dir = 0;
			//	mPlayerState = PlayerState::Attack;
			//	at->PlayAnimation(L"LeftAttack", false);

			//	if (mCaremaPury == nullptr && mBladeTornado == nullptr)
			//	{
			//		CreateCaremaPury();
			//		SceneManager::GetMpScript()->OnDamage(40);
			//	}
			//}
	//}
		if (Input::GetKeyDown(eKeyCode::Z))
		{
			SceneManager::GetHpScript()->SetHP(99999);
			SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -1.95f, 1.000f));
			SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));

			SceneManager::GetMpScript()->SetMP(2000);
			SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -2.05f, 1.000f));
			SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));
		}

		if (mRigidBody->GetGround() == true)
		{
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
			mPlayerState = PlayerState::Idle;
			//jumptime = 0.0f;
			if (dir == 0)
			{
				at->PlayAnimation(L"LeftIdle", true);
			}
			if (dir == 1)
			{
				at->PlayAnimation(L"RightIdle", true);
			}
		}
	}
	void PlayerScript::doublejump()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();
		RigidBody* mRigidBody = GetOwner()->GetComponent<RigidBody>();

		if (dir == 0 && jumpdouble)
		{
			jumpdouble = false;
			RigidBody* mRigidBody = GetOwner()->GetComponent<RigidBody>();
			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x -= 1.7f;
			velocity.y += 0.3f;
			mRigidBody->SetVelocity(velocity);
		}
		if (dir == 1 && jumpdouble)
		{
			jumpdouble = false;
			RigidBody* mRigidBody = GetOwner()->GetComponent<RigidBody>();
			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x += 1.7f;
			velocity.y += 0.3f;
			mRigidBody->SetVelocity(velocity);
		}

		if (mRigidBody->GetGround() == true)
		{
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
			mPlayerState = PlayerState::Idle;
			//jumptime = 0.0f;
			if (dir == 0)
			{
				at->PlayAnimation(L"LeftIdle", true);
			}
			if (dir == 1)
			{
				at->PlayAnimation(L"RightIdle", true);
			}
		}

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			SceneManager::GetHpScript()->SetHP(99999);
			SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -1.95f, 1.000f));
			SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));

			SceneManager::GetMpScript()->SetMP(2000);
			SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -2.05f, 1.000f));
			SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));
		}
	}
	void PlayerScript::alert()
	{
		RigidBody* mRigidBody = GetOwner()->GetComponent<RigidBody>();
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Animator* at = GetOwner()->GetComponent<Animator>();

		alerttime += Time::DeltaTime();

		if (mRigidBody->GetGround() == true)
		{
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
			if (dir == 0)
			{
				if (alerttime >= 0.6f)
				{
					at->PlayAnimation(L"LeftIdle", true);
					mPlayerState = PlayerState::Idle;
					alerttime = 0.0f;
				}
			}
			if (dir == 1)
			{
				if (alerttime >= 0.6f)
				{
					at->PlayAnimation(L"RightIdle", true);
					mPlayerState = PlayerState::Idle;
					alerttime = 0.0f;
				}
			}

		}

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			SceneManager::GetHpScript()->SetHP(99999);
			SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -1.95f, 1.000f));
			SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));

			SceneManager::GetMpScript()->SetMP(2000);
			SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -2.05f, 1.000f));
			SceneManager::GetMpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));
		}



	}
	void PlayerScript::die()
	{
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, false);

		Animator* at = GetOwner()->GetComponent<Animator>();

		dietime += Time::DeltaTime();

		if (dietime >= 5.0f)
		{
			if (mDeathPhrases != nullptr)
			{
				object::Destroy(mDeathPhrases);
			}

			if (dir == 0)
			{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				tr->SetPosition(Vector3(pos.x, pos.y - 0.1f, pos.z));

				SceneManager::GetHpScript()->SetHP(99999);
				SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -1.95f, 1.000f));
				SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));
				DieCheck = false;
				dietime = 0.0f;
				at->PlayAnimation(L"LeftIdle", true);
				mPlayerState = PlayerState::Idle;
				CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
			}

			if (dir == 1)
			{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				tr->SetPosition(Vector3(pos.x, pos.y - 0.1f, pos.z));

				SceneManager::GetHpScript()->SetHP(99999);
				SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -1.95f, 1.000f));
				SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));
				DieCheck = false;
				dietime = 0.0f;
				at->PlayAnimation(L"RightIdle", true);
				mPlayerState = PlayerState::Idle;
				CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
			}

		}


	}
}