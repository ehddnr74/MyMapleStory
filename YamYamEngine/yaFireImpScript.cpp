#include "yaFireImpScript.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaPlayerScript.h"
#include "yaObject.h"
#include <random>
#include "yaSceneManager.h"

std::mt19937_64 rng1(0);
std::uniform_int_distribution<__int64> dist1(0, 1);

namespace ya
{
	FireImpScript::FireImpScript()
		: dir(dist1(rng1))
		, hittime(0.0f)
		, imptime(0.0f)
		, randdirtime(0.0f)
		, idletime(0.0f)
		, movetime(0.0f)
		, attacktime(0.0f)
		, HP(50000)
		, damage(0)
		, diecheck(false)
		, collidertime(0.0f)
		, Attack(0.0f)
		, OnHit(false)
	{

	}
	FireImpScript::~FireImpScript()
	{

	}
	void FireImpScript::Initialize()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		Collider2D* cd = GetOwner()->AddComponent<Collider2D>();
		//cd->SetCenter(Vector2(0.0f, 0.0f));
		//cd->SetSize(Vector2(0.01f, 0.01f));
		//cd->SetCenter(Vector2(0.0f, 0.0f));
		//cd->SetSize(Vector2(0.0f, 0.0f));
		//at->CompleteEvent(L"Idle") = std::bind(&PlayerScript::Complete, this);

		std::shared_ptr<Texture> FireImpLeftIdle = Resources::Load<Texture>(L"FireImpLeftIdle", L"..\\Resources\\Texture\\FireImp\\FireImpLeftIdle.png");
		std::shared_ptr<Texture> FireImpLeftMove = Resources::Load<Texture>(L"FireImpLeftMove", L"..\\Resources\\Texture\\FireImp\\FireImpLeftMove.png");
		std::shared_ptr<Texture> FireImpLeftAttack = Resources::Load<Texture>(L"FireImpLeftAttack", L"..\\Resources\\Texture\\FireImp\\FireImpLeftAttack.png");
		std::shared_ptr<Texture> FireImpLeftHit = Resources::Load<Texture>(L"FireImpLeftHit", L"..\\Resources\\Texture\\FireImp\\FireImpLeftHit.png");
		std::shared_ptr<Texture> FireImpLeftDie = Resources::Load<Texture>(L"FireImpLeftDie", L"..\\Resources\\Texture\\FireImp\\FireImpLeftDie.png");

		std::shared_ptr<Texture> FireImpRightIdle = Resources::Load<Texture>(L"FireImpRightIdle", L"..\\Resources\\Texture\\FireImp\\FireImpRightIdle.png");
		std::shared_ptr<Texture> FireImpRightMove = Resources::Load<Texture>(L"FireImpRightMove", L"..\\Resources\\Texture\\FireImp\\FireImpRightMove.png");
		std::shared_ptr<Texture> FireImpRightAttack = Resources::Load<Texture>(L"FireImpRightAttack", L"..\\Resources\\Texture\\FireImp\\FireImpRightAttack.png");
		std::shared_ptr<Texture> FireImpRightHit = Resources::Load<Texture>(L"FireImpRightHit", L"..\\Resources\\Texture\\FireImp\\FireImpRightHit.png");
		std::shared_ptr<Texture> FireImpRightDie = Resources::Load<Texture>(L"FireImpRightDie", L"..\\Resources\\Texture\\FireImp\\FireImpRightDie.png");


		at->Create(L"FireImpLeftIdle", FireImpLeftIdle, Vector2(0.0f, 0.0f), Vector2(84.0f, 99.0f), 12, Vector2::Zero, 0.15f);
		at->Create(L"FireImpLeftMove", FireImpLeftMove, Vector2(0.0f, 0.0f), Vector2(84.0f, 100.0f), 6, Vector2::Zero, 0.15f);
		at->Create(L"FireImpLeftAttack", FireImpLeftAttack, Vector2(0.0f, 0.0f), Vector2(185.0f, 150.0f), 11, Vector2::Zero, 0.15f);
		at->Create(L"FireImpLeftHit", FireImpLeftHit, Vector2(0.0f, 0.0f), Vector2(86.0f, 96.0f), 2, Vector2::Zero, 0.1f);
		at->Create(L"FireImpLeftDie", FireImpLeftDie, Vector2(0.0f, 0.0f), Vector2(165.0f, 193.0f), 9, Vector2::Zero, 0.15f);


		at->Create(L"FireImpRightIdle", FireImpRightIdle, Vector2(0.0f, 0.0f), Vector2(84.0f, 99.0f), 12, Vector2::Zero, 0.15f);
		at->Create(L"FireImpRightMove", FireImpRightMove, Vector2(0.0f, 0.0f), Vector2(84.0f, 100.0f), 6, Vector2::Zero, 0.15f);
		at->Create(L"FireImpRightAttack", FireImpRightAttack, Vector2(0.0f, 0.0f), Vector2(185.0f, 150.0f), 11, Vector2::Zero, 0.15f);
		at->Create(L"FireImpRightHit", FireImpRightHit, Vector2(0.0f, 0.0f), Vector2(86.0f, 96.0f), 2, Vector2::Zero, 0.1f);
		at->Create(L"FireImpRightDie", FireImpRightDie, Vector2(0.0f, 0.0f), Vector2(165.0f, 193.0f), 9, Vector2::Zero, 0.15f);



		at->PlayAnimation(L"FireImpLeftIdle", true);

		mFireImpState = FireImpState::Idle;
	}
	void FireImpScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		Transform* Playertr = SceneManager::GetPlayerScript()->GetOwner()->GetComponent<Transform>();
		Vector3 PlayerPos = Playertr->GetPosition();

		if (mFireImpState == FireImpState::Attack)
		{
			collidertime += Time::DeltaTime();

			if (collidertime >= 1.55f)
			{
				if (-0.5f <= PlayerPos.x - pos.x && PlayerPos.x - pos.x <= 0.0f)
				{
					if (dir == 0 && SceneManager::GetPlayerScript()->GetDir() == 0
						|| dir == 0 && SceneManager::GetPlayerScript()->GetDir() == 1
						|| dir == 1 && SceneManager::GetPlayerScript()->GetDir() == 0
						|| dir == 1 && SceneManager::GetPlayerScript()->GetDir() == 1)
					{
						Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
						cd->SetCenter(Vector2(0.0f, 0.0f));
						cd->SetSize(Vector2(0.6f, 0.5f));
					}
				}
			}
		}

				
			if (mFireImpState == FireImpState::Attack)
			{
				collidertime += Time::DeltaTime();

				if (collidertime >= 1.55f)
				{
					if (0.0f <= PlayerPos.x - pos.x && PlayerPos.x - pos.x <= 0.5f)
					{
						if (dir == 0 && SceneManager::GetPlayerScript()->GetDir() == 0
							|| dir == 0 && SceneManager::GetPlayerScript()->GetDir() == 1
							|| dir == 1 && SceneManager::GetPlayerScript()->GetDir() == 0
							|| dir == 1 && SceneManager::GetPlayerScript()->GetDir() == 1)
						{
							Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
							cd->SetCenter(Vector2(0.0f, 0.0f));
							cd->SetSize(Vector2(0.6f, 0.5f));
						}
					}
				}
			}
			
				if(mFireImpState != FireImpState::Attack)
				{
					collidertime = 0.0f;
					Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
					cd->SetCenter(Vector2(0.0f, 0.0f));
					cd->SetSize(Vector2(0.25f, 0.25f));
				}

			srand(time(NULL));
			RandDir();

			if (diecheck == false && HP <= 0 && dir == 0)
			{
				diecheck = true;
				Animator* at = GetOwner()->GetComponent<Animator>();
				mFireImpState = FireImpState::Die;
				at->PlayAnimation(L"FireImpLeftDie", false);
			}
			if (diecheck == false && HP <= 0 && dir == 1)
			{
				diecheck = true;
				Animator* at = GetOwner()->GetComponent<Animator>();
				mFireImpState = FireImpState::Die;
				at->PlayAnimation(L"FireImpRightDie", false);
			}



			switch (mFireImpState)
			{
			case FireImpScript::FireImpState::Idle:
				Idle();
				break;
			case FireImpScript::FireImpState::Move:
				move();
				break;
			case FireImpScript::FireImpState::Attack:
				attack();
				break;
			case FireImpScript::FireImpState::Hit:
				hit();
				break;
			case FireImpScript::FireImpState::Die:
				die();
				break;
			default:
				break;
			}
		}

	void FireImpScript::OnCollisionEnter(Collider2D* other)
	{
		if (mFireImpState != FireImpState::Attack && mFireImpState != FireImpState::Die &&other->GetOwner()->GetName() == L"Adel")
		{
			if (dir == 0)
			{
				Animator* at = GetOwner()->GetComponent<Animator>();
				at->PlayAnimation(L"FireImpLeftHit", false);
				mFireImpState = FireImpState::Hit;
			}
			if (dir == 1)
			{
				Animator* at = GetOwner()->GetComponent<Animator>();
				at->PlayAnimation(L"FireImpRightHit", false);
				mFireImpState = FireImpState::Hit;
			}
		}
	}
	void FireImpScript::OnCollisionStay(Collider2D* other)
	{

	}
	void FireImpScript::OnCollisionExit(Collider2D* other)
	{
	}
	void FireImpScript::Rand()
	{

	}
	void FireImpScript::SetDamage(int damage)
	{
		HP -= damage;
	}
	void FireImpScript::RandDir()
	{
		randdirtime += Time::DeltaTime();

		if (randdirtime >= 7.0f)
		{
			dir = dist1(rng1);
			randdirtime = 0.0f;
		}
	}
	void FireImpScript::Idle()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();
		idletime += Time::DeltaTime();

		if (dir == 0 && idletime >= 2.0f)
		{
			idletime = 0.0f;
			mFireImpState = FireImpState::Move;
			at->PlayAnimation(L"FireImpLeftMove", true);
		}
		if (dir == 1 && idletime >= 2.0f)
		{
			idletime = 0.0f;
			mFireImpState = FireImpState::Move;
			at->PlayAnimation(L"FireImpRightMove", true);
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		Transform* Playertr = SceneManager::GetPlayerScript()->GetOwner()->GetComponent<Transform>();
		Vector3 PlayerPos = Playertr->GetPosition();

		if (0.0f <= PlayerPos.x - pos.x && PlayerPos.x - pos.x <= 0.5f)
		{
			if (dir == 0 && SceneManager::GetPlayerScript()->GetDir() == 0)
			{
				dir = 1;
				idletime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpRightAttack", true);
			}

			if (dir == 0 && SceneManager::GetPlayerScript()->GetDir() == 1)
			{
				idletime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpRightAttack", true);
			}

			if (dir == 1 && SceneManager::GetPlayerScript()->GetDir() == 0)
			{
				idletime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpRightAttack", true);
			}

			if (dir == 1 && SceneManager::GetPlayerScript()->GetDir() == 1)
			{
				idletime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpRightAttack", true);
			}
		}

		if (-0.5f <= PlayerPos.x - pos.x && PlayerPos.x - pos.x <= 0.0f)
		{
			if (dir == 0 && SceneManager::GetPlayerScript()->GetDir() == 0)
			{
				dir = 1;
				movetime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpLeftAttack", true);
			}

			if (dir == 0 && SceneManager::GetPlayerScript()->GetDir() == 1)
			{
				movetime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpLeftAttack", true);
			}

			if (dir == 1 && SceneManager::GetPlayerScript()->GetDir() == 0)
			{
				movetime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpLeftAttack", true);
			}

			if (dir == 1 && SceneManager::GetPlayerScript()->GetDir() == 1)
			{
				movetime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpLeftAttack", true);
			}
		}

	}
	void FireImpScript::move()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		Transform* Playertr = SceneManager::GetPlayerScript()->GetOwner()->GetComponent<Transform>();
		Vector3 PlayerPos = Playertr->GetPosition();

		if (0.0f <= PlayerPos.x - pos.x && PlayerPos.x - pos.x <= 0.5f)
		{
			if (dir == 0 && SceneManager::GetPlayerScript()->GetDir() == 0)
			{
				dir = 1;
				movetime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpRightAttack", true);
			}

			if (dir == 0 && SceneManager::GetPlayerScript()->GetDir() == 1)
			{
				movetime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpRightAttack", true);
			}

			if (dir == 1 && SceneManager::GetPlayerScript()->GetDir() == 0)
			{
				movetime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpRightAttack", true);
			}

			if (dir == 1 && SceneManager::GetPlayerScript()->GetDir() == 1)
			{
				movetime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpRightAttack", true);
			}
		}

		if (-0.5f <= PlayerPos.x - pos.x && PlayerPos.x - pos.x <= 0.0f)
		{
			if (dir == 0 && SceneManager::GetPlayerScript()->GetDir() == 0)
			{
				dir = 1;
				movetime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpLeftAttack", true);
			}

			if (dir == 0 && SceneManager::GetPlayerScript()->GetDir() == 1)
			{
				movetime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpLeftAttack", true);
			}

			if (dir == 1 && SceneManager::GetPlayerScript()->GetDir() == 0)
			{
				movetime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpLeftAttack", true);
			}

			if (dir == 1 && SceneManager::GetPlayerScript()->GetDir() == 1)
			{
				movetime = 0.0f;
				mFireImpState = FireImpState::Attack;
				at->PlayAnimation(L"FireImpLeftAttack", true);
			}
		}

		movetime += Time::DeltaTime();

		if (movetime >= 5.0f)
		{
			if (dir == 0)
			{
				movetime = 0.0f;
				mFireImpState = FireImpState::Idle;
				at->PlayAnimation(L"FireImpLeftIdle", true);
			}
			if (dir == 1)
			{
				movetime = 0.0f;
				mFireImpState = FireImpState::Idle;
				at->PlayAnimation(L"FireImpRightIdle", true);
			}
		}

		if (dir == 0)
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			pos.x -= 0.15f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (dir == 1)
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			pos.x += 0.15f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

	}
	void FireImpScript::attack()
	{
		Attack = true;
		Animator* at = GetOwner()->GetComponent<Animator>();

		attacktime += Time::DeltaTime();

		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector3 pos = tr->GetPosition();

		//Transform* Playertr = GetPlayerScript()->GetOwner()->GetComponent<Transform>();
		//Vector3 PlayerPos = Playertr->GetPosition();

		if (attacktime > 1.65f)
		{
			if (dir == 0)
			{
				Attack = false;
				mFireImpState = FireImpState::Idle;
				at->PlayAnimation(L"FireImpLeftIdle", true);
				attacktime = 0.0f;
				randdirtime = 0.0f;
			}

			if (dir == 1)
			{
				Attack = false;
				mFireImpState = FireImpState::Idle;
				at->PlayAnimation(L"FireImpRightIdle", true);
				attacktime = 0.0f;
				randdirtime = 0.0f;
			}
		}
	}
	void FireImpScript::hit()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		hittime += Time::DeltaTime();

		if (hittime >= 0.5f)
		{
			hittime = 0.0f;
			at->PlayAnimation(L"FireImpLeftIdle", true);
			mFireImpState = FireImpState::Idle;
		}
	}
	void FireImpScript::die()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		dietime += Time::DeltaTime();

		if (dietime >= 1.35f)
		{
			dietime = 0.0f;
			object::Destroy(GetOwner());
		}
	}
}