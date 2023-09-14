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

namespace ya
{
	PlayerScript::PlayerScript()
		: dir(0)
		, attacktime(0.f)
		, jumptime(0.f)
		, alerttime(0.f)
		, hit(false)
		, jum(false)
		, devide(false)
		, devidetime(0.f)
		, portal(false)
		, inventory(true)
		, inventorytime(0.0f)
		, meso(100)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> LeftAnimation = Resources::Load<Texture>(L"LeftAnimation", L"..\\Resources\\Texture\\LeftAnimation.png");
		std::shared_ptr<Texture> RightAnimation = Resources::Load<Texture>(L"RightAnimation", L"..\\Resources\\Texture\\RightAnimation.png");
		std::shared_ptr<Texture> Prone = Resources::Load<Texture>(L"Prone", L"..\\Resources\\Texture\\Prone.png");
		std::shared_ptr<Texture> RightProne = Resources::Load<Texture>(L"RightProne", L"..\\Resources\\Texture\\RightProne.png");
		std::shared_ptr<Texture> LeftJump = Resources::Load<Texture>(L"LeftJump", L"..\\Resources\\Texture\\LeftJump.png");
		std::shared_ptr<Texture> RightJump = Resources::Load<Texture>(L"RightJump", L"..\\Resources\\Texture\\RightJump.png");

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

		RigidBody* mRigidBody = GetOwner()->AddComponent<RigidBody>();
		//RigidBody* rb = GetOwner()->GetComponent<RigidBody>();

		//mRigidBody->SetGround(true);

		at->PlayAnimation(L"LeftIdle", true);

		mPlayerState = PlayerState::Idle;
	}
	void PlayerScript::Update()
	{
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

		if (inventory)
		{
			if (Input::GetKeyDown(eKeyCode::I))
			{
				inventory = false;
				OnInventory();
			}
		}

		if (inventory == false)
		{
			inventorytime += Time::DeltaTime();

			if (inventorytime >=0.2f && Input::GetKeyDown(eKeyCode::I))
			{
				inventorytime = 0.0f;
				inventory = true;
				CloseInventory();
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		if (mDevide != nullptr)
		{
			devidetime += Time::DeltaTime();

			if (devidetime >= 0.75f)
			{
				devidetime = 0.0f;
				object::Destroy(mDevide);
				SetDevide(nullptr);
				SetDevideScript(nullptr);
			}
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
		case PlayerScript::PlayerState::Jump:
			jump();
			break;
		case PlayerScript::PlayerState::Alert:
			alert();
			break;
		default:
			break;
		}
	}
	void PlayerScript::Complete()
	{
		int a = 0;
	}
	void PlayerScript::CreateDevide()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* Devide
			= object::Instantiate<GameObject>(Vector3(pos.x - 0.5f, pos.y + 0.2f, 0.9991f), eLayerType::Skill);

		SetDevide(Devide);

		Devide->SetName(L"Devide");


		MeshRenderer* mr = Devide->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		Devide->GetComponent<Transform>()->SetScale(Vector3(3.0f, 3.0f, 1.0005f));

		Animator* at = Devide->AddComponent<Animator>();
		Devide->AddComponent<SkillScript>();
	}
	void PlayerScript::CreateRightDevide()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* Devide
			= object::Instantiate<GameObject>(Vector3(pos.x + 0.5f, pos.y + 0.2f, 0.9991f), eLayerType::Skill);

		SetDevide(Devide);

		Devide->SetName(L"Devide");


		MeshRenderer* mr = Devide->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		Devide->GetComponent<Transform>()->SetScale(Vector3(3.0f, 3.0f, 1.0005f));

		Animator* at = Devide->AddComponent<Animator>();
		Devide->AddComponent<SkillScript>();

		SkillScript* ss = Devide->GetComponent<SkillScript>();
		ss->SetDir(true);
	}
	void PlayerScript::OnInventory()
	{
			{
				Transform* PlayerTr = GetOwner()->GetComponent<Transform>();
				Vector3 PlayerPos = PlayerTr->GetPosition();

				mInventory1
					= object::Instantiate<GameObject>(Vector3(1.0f, 0.68f, 0.999f), eLayerType::UI);

				SetInventory1(mInventory1);

				mInventory1->SetName(L"Inventory1");

				//Collider2D* cd = Inventory->AddComponent<Collider2D>();
				//cd->SetCenter(Vector2(0.0f, 0.0f));
				//cd->SetSize(Vector2(0.22f, 0.38f));

				MeshRenderer* mr = mInventory1->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"inventory1"));

				mInventory1->GetComponent<Transform>()->SetScale(Vector3(1.5f, 2.4f, 1.0001f));
			}

			{
				Transform* PlayerTr = GetOwner()->GetComponent<Transform>();
				Vector3 PlayerPos = PlayerTr->GetPosition();

				mInventory2
					= object::Instantiate<GameObject>(Vector3(1.0f, 0.38f, 0.998f), eLayerType::UI);

				SetInventory2(mInventory2);

				mInventory2->SetName(L"mInventory2");

				//Collider2D* cd = Inventory->AddComponent<Collider2D>();
				//cd->SetCenter(Vector2(0.0f, 0.0f));
				//cd->SetSize(Vector2(0.22f, 0.38f));

				MeshRenderer* mr = mInventory2->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"inventory2"));

				mInventory2->GetComponent<Transform>()->SetScale(Vector3(1.4f, 2.75f, 1.0001f));
			}

			{
				Transform* PlayerTr = GetOwner()->GetComponent<Transform>();
				Vector3 PlayerPos = PlayerTr->GetPosition();

				mInventory3
					= object::Instantiate<GameObject>(Vector3(1.0f, 0.5f, 0.997f), eLayerType::UI);

				SetInventory3(mInventory3);

				mInventory3->SetName(L"mInventory3");

				//Collider2D* cd = Inventory->AddComponent<Collider2D>();
				//cd->SetCenter(Vector2(0.0f, 0.0f));
				//cd->SetSize(Vector2(0.22f, 0.38f));

				MeshRenderer* mr = mInventory3->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"inventory3"));

				mInventory3->GetComponent<Transform>()->SetScale(Vector3(1.38f, 2.2f, 1.0001f));

				mInventoryScript = mInventory3->AddComponent<InventoryScript>();

				SetInventoryScript(mInventoryScript);

			}

			{
				Transform* PlayerTr = GetOwner()->GetComponent<Transform>();
				Vector3 PlayerPos = PlayerTr->GetPosition();

				mInventoryEtc
					= object::Instantiate<GameObject>(Vector3(0.88f, 1.67f, 0.996f), eLayerType::UI);

				SetInventoryEtc(mInventoryEtc);

				mInventoryEtc->SetName(L"mInventoryEtc");

				//Collider2D* cd = Inventory->AddComponent<Collider2D>();
				//cd->SetCenter(Vector2(0.0f, 0.0f));
				//cd->SetSize(Vector2(0.22f, 0.38f));

				MeshRenderer* mr = mInventoryEtc->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"shopetc"));

				mInventoryEtc->GetComponent<Transform>()->SetScale(Vector3(1.6f, 0.15f, 1.0001f));
			}

			{
				Transform* PlayerTr = GetOwner()->GetComponent<Transform>();
				Vector3 PlayerPos = PlayerTr->GetPosition();

				mInventoryMeso
					= object::Instantiate<GameObject>(Vector3(0.475f, -0.37f, 0.996f), eLayerType::UI);

				SetInventoryMeso(mInventoryMeso);

				mInventoryMeso->SetName(L"mInventoryMeso");

				//Collider2D* cd = Inventory->AddComponent<Collider2D>();
				//cd->SetCenter(Vector2(0.0f, 0.0f));
				//cd->SetSize(Vector2(0.22f, 0.38f));

				MeshRenderer* mr = mInventoryMeso->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"inventorymeso"));

				mInventoryMeso->GetComponent<Transform>()->SetScale(Vector3(0.3f, 0.125f, 1.0001f));
			}

			{
				Transform* PlayerTr = GetOwner()->GetComponent<Transform>();
				Vector3 PlayerPos = PlayerTr->GetPosition();

				mInventoryMesoBar
					= object::Instantiate<GameObject>(Vector3(1.2f, -0.38f, 0.996f), eLayerType::UI);

				SetInventoryMesoBar(mInventoryMesoBar);

				mInventoryMesoBar->SetName(L"mInventoryMesoBar");

				//Collider2D* cd = Inventory->AddComponent<Collider2D>();
				//cd->SetCenter(Vector2(0.0f, 0.0f));
				//cd->SetSize(Vector2(0.22f, 0.38f));

				MeshRenderer* mr = mInventoryMesoBar->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"inventorymesobar"));

				mInventoryMesoBar->GetComponent<Transform>()->SetScale(Vector3(1.1f, 0.15f, 1.0001f));
			}
	}
	void PlayerScript::CloseInventory()
	{
		object::Destroy(mInventory1);
		object::Destroy(mInventory2);
		object::Destroy(mInventory3);
		object::Destroy(mInventoryEtc);
		object::Destroy(mInventoryMeso);
		object::Destroy(mInventoryMesoBar);
	}
	void PlayerScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"MushRoom")
		{
			hit = true;
		}

		if (other->GetOwner()->GetName() == L"FireImp")
		{
			hit = true;
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
			SceneManager::GetHpScript()->OnDamage(2576);
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

			if (Input::GetKeyDown(eKeyCode::B))
			{
				dir = 0;
				mPlayerState = PlayerState::Attack;
				at->PlayAnimation(L"LeftAttack", false);

				if (mDevide == nullptr)
				{
					CreateDevide();
					SceneManager::GetMpScript()->OnDamage(40);
				}
			}

			if (Input::GetKeyDown(eKeyCode::X))
			{
				RigidBody* mRigidBody = GetOwner()->GetComponent<RigidBody>();

				mRigidBody->SetGround(false);
				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.y += 2.0f;
				mRigidBody->SetVelocity(velocity);

				mRigidBody->SetVelocity(velocity);
				dir = 0;
				at->PlayAnimation(L"LeftJump", false);
				mPlayerState = PlayerState::Jump;
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

			if (Input::GetKeyDown(eKeyCode::B))
			{
				dir = 1;
				mPlayerState = PlayerState::Attack;
				at->PlayAnimation(L"RightAttack", false);


				if (mDevide == nullptr)
				{
					CreateRightDevide();
					SceneManager::GetMpScript()->OnDamage(40);
					SceneManager::GetExpScript()->OnDamage(32);
				}


			}
			if (Input::GetKeyDown(eKeyCode::X))
			{
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
			if (Input::GetKey(eKeyCode::B))
			{
				dir = 0;
				mPlayerState = PlayerState::Attack;
				at->PlayAnimation(L"LeftAttack", false);

				if (mDevide == nullptr)
				{
					CreateDevide();
					SceneManager::GetMpScript()->OnDamage(40);
				}
			}
			if (Input::GetKeyDown(eKeyCode::X))
			{
				RigidBody* mRigidBody = GetOwner()->GetComponent<RigidBody>();

				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.x -= 0.8f;
				velocity.y += 2.0f;
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
			if (Input::GetKey(eKeyCode::B))
			{
				dir = 1;
				mPlayerState = PlayerState::Attack;
				at->PlayAnimation(L"RightAttack", false);

				if (mDevide == nullptr)
				{
					CreateRightDevide();
					SceneManager::GetMpScript()->OnDamage(40);
				}
			}
			if (Input::GetKeyDown(eKeyCode::X))
			{
				RigidBody* mRigidBody = GetOwner()->GetComponent<RigidBody>();

				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.x += 0.8f;
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
	void PlayerScript::pronestab()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Animator* at = GetOwner()->GetComponent<Animator>();

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

		if (attacktime >= 0.6f)
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



		//jumptime += Time::DeltaTime();


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



	}
}