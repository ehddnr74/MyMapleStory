#include "yaBanBanScript.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaPlayerScript.h"
#include <random>
#include "yaObject.h"
#include "yaMesh.h"
#include "yaMeshRenderer.h"
#include "yaBallScript.h"
#include "yaHpScript.h"
#include "yaBanBanHPScript.h"


std::mt19937_64 rng2(0);
std::uniform_real_distribution<float> dist2(-1, 1);

namespace ya
{
	BanBanScript::BanBanScript()
		: HP(1500000)
		, damage(0)
		, dir(0)
		, randompos(dist2(rng2))
		, zentime(0.0f)
		, smack(true)
		, smackingtime(0.0f)
		, energy(true)
		, energybolttime(0.0f)
		, energytime(0.0f)
		, CreateBall(false)
		, ballcreatetime(0.0f)
		, balllifetime(0.0f)
		, eq(true)
		, earthquaketime(0.0f)
		, earthtime(0.0f)
		, bk(true)
		, blinktime(0.0f)
		, btime(0.0f)
		, earthhit(true)
		, hittime(0.0f)
		, dietime(0.0f)
		, DieCheck(false)
	{
	}
	BanBanScript::~BanBanScript()
	{
	}
	void BanBanScript::Initialize()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		Collider2D* cd = GetOwner()->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.1f, 0.0f));
		cd->SetSize(Vector2(0.3f, 0.5f));

		std::shared_ptr<Texture> BanBanZen = Resources::Load<Texture>(L"BanBanZen", L"..\\Resources\\Texture\\BanBan\\BanBanZen.png");
		std::shared_ptr<Texture> LeftIdle = Resources::Load<Texture>(L"LeftIdle", L"..\\Resources\\Texture\\BanBan\\LeftIdle.png");
		std::shared_ptr<Texture> RightIdle = Resources::Load<Texture>(L"RightIdle", L"..\\Resources\\Texture\\BanBan\\RightIdle.png");
		std::shared_ptr<Texture> LeftMove = Resources::Load<Texture>(L"LeftMove", L"..\\Resources\\Texture\\BanBan\\LeftMove.png");
		std::shared_ptr<Texture> RightMove = Resources::Load<Texture>(L"RightMove", L"..\\Resources\\Texture\\BanBan\\RightMove.png");
		std::shared_ptr<Texture> LeftEnergyBolt = Resources::Load<Texture>(L"LeftEnergyBolt", L"..\\Resources\\Texture\\BanBan\\LeftEnergyBolt.png");
		std::shared_ptr<Texture> RightEnergyBolt = Resources::Load<Texture>(L"RightEnergyBolt", L"..\\Resources\\Texture\\BanBan\\RightEnergyBolt.png");
		std::shared_ptr<Texture> LeftBall = Resources::Load<Texture>(L"LeftBall", L"..\\Resources\\Texture\\BanBan\\LeftBall.png");
		std::shared_ptr<Texture> RightBall = Resources::Load<Texture>(L"RightBall", L"..\\Resources\\Texture\\BanBan\\RightBall.png");
		std::shared_ptr<Texture> LeftHit = Resources::Load<Texture>(L"LeftHit", L"..\\Resources\\Texture\\BanBan\\BanBanLeftHit.png");
		std::shared_ptr<Texture> RightHit = Resources::Load<Texture>(L"RightHit", L"..\\Resources\\Texture\\BanBan\\BanBanRightHit.png");
		std::shared_ptr<Texture> LeftDie = Resources::Load<Texture>(L"LeftDie", L"..\\Resources\\Texture\\BanBan\\BanBanLeftDie.png");
		std::shared_ptr<Texture> RightDie = Resources::Load<Texture>(L"RightDie", L"..\\Resources\\Texture\\BanBan\\BanBanRightDie.png");

		std::shared_ptr<Texture> LeftSmacking = Resources::Load<Texture>(L"LeftSmacking", L"..\\Resources\\Texture\\BanBan\\LeftSmacking.png");
		std::shared_ptr<Texture> RightSmacking = Resources::Load<Texture>(L"RightSmacking", L"..\\Resources\\Texture\\BanBan\\RightSmacking.png");
		std::shared_ptr<Texture> LeftEarthQuake = Resources::Load<Texture>(L"LeftEarthQuake", L"..\\Resources\\Texture\\BanBan\\LeftEarthQuake.png");
		std::shared_ptr<Texture> RightEarthQuake = Resources::Load<Texture>(L"RightEarthQuake", L"..\\Resources\\Texture\\BanBan\\RightEarthQuake.png");
		std::shared_ptr<Texture> BlinkIn = Resources::Load<Texture>(L"BlinkIn", L"..\\Resources\\Texture\\BanBan\\BlinkIn.png");
		std::shared_ptr<Texture> BlinkOut = Resources::Load<Texture>(L"BlinkOut", L"..\\Resources\\Texture\\BanBan\\BlinkOut.png");


		at->Create(L"BanBanZen", BanBanZen, Vector2(0.0f, 0.0f), Vector2(321.0f, 523.0f), 17, Vector2::Zero, 0.1f);
		at->Create(L"LeftIdle", LeftIdle, Vector2(0.0f, 0.0f), Vector2(130.0f, 164.0f), 6, Vector2::Zero, 0.1f);
		at->Create(L"RightIdle", RightIdle, Vector2(0.0f, 0.0f), Vector2(130.0f, 164.0f), 6, Vector2::Zero, 0.1f);
		at->Create(L"LeftMove", LeftMove, Vector2(0.0f, 0.0f), Vector2(128.0f, 163.0f), 6, Vector2::Zero, 0.15f);
		at->Create(L"RightMove", RightMove, Vector2(0.0f, 0.0f), Vector2(128.0f, 163.0f), 6, Vector2::Zero, 0.15f);

		at->Create(L"LeftSmacking", LeftSmacking, Vector2(0.0f, 0.0f), Vector2(207.0f, 237.0f), 14, Vector2::Zero, 0.1f);
		at->Create(L"RightSmacking", RightSmacking, Vector2(0.0f, 0.0f), Vector2(207.0f, 237.0f), 14, Vector2::Zero, 0.1f);
		at->Create(L"LeftEnergyBolt", LeftEnergyBolt, Vector2(0.0f, 0.0f), Vector2(343.0f, 287.0f), 23, Vector2::Zero, 0.1f);
		at->Create(L"RightEnergyBolt", RightEnergyBolt, Vector2(0.0f, 0.0f), Vector2(343.0f, 287.0f), 23, Vector2::Zero, 0.1f);
		at->Create(L"LeftBall", LeftBall, Vector2(0.0f, 0.0f), Vector2(137.0f, 50.0f), 4, Vector2::Zero, 0.1f);
		at->Create(L"RightBall", RightBall, Vector2(0.0f, 0.0f), Vector2(137.0f, 50.0f), 14, Vector2::Zero, 0.1f);
		at->Create(L"LeftEarthQuake", LeftEarthQuake, Vector2(0.0f, 0.0f), Vector2(413.0f, 358.0f), 16, Vector2::Zero, 0.1f);
		at->Create(L"RightEarthQuake", RightEarthQuake, Vector2(0.0f, 0.0f), Vector2(413.0f, 358.0f), 16, Vector2::Zero, 0.1f);
		at->Create(L"BlinkIn", BlinkIn, Vector2(0.0f, 0.0f), Vector2(64.0, 165.0f), 5, Vector2::Zero, 0.07f);
		at->Create(L"BlinkOut", BlinkOut, Vector2(0.0f, 0.0f), Vector2(64.0, 165.0f), 5, Vector2::Zero, 0.07f);

		at->Create(L"BanBanLeftHit", LeftHit, Vector2(0.0f, 0.0f), Vector2(189.0f, 173.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"BanBanLeftDie", LeftDie, Vector2(0.0f, 0.0f), Vector2(302.0f, 304.0f), 6, Vector2::Zero, 0.25f);
		at->Create(L"BanBanRightHit", RightHit, Vector2(0.0f, 0.0f), Vector2(189.0f, 173.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"BanBanRightDie", RightDie, Vector2(0.0f, 0.0f), Vector2(302.0f, 304.0f), 6, Vector2::Zero, 0.25f);


		at->PlayAnimation(L"BanBanZen", false);

		mBanBanState = BanBanState::Zen;
	}
	void BanBanScript::Update()
	{

		//HP = HP;

		if (mBanBanState == BanBanState::Zen)
		{
			Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, 0.0f));
			cd->SetSize(Vector2(0.01f, 0.01f));
		}
		else if (mBanBanState == BanBanState::EnergyBolt)
		{
			Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, 0.0f));
			cd->SetSize(Vector2(0.0f, 0.2f));
		}
		else if (mBanBanState == BanBanState::EarthQuake)
		{
			Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, 0.0f));
			cd->SetSize(Vector2(0.01f, 0.01f));
		}
		else 
		{
			Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, 0.0f));
			cd->SetSize(Vector2(0.3f, 0.5f));
		}

		srand(time(NULL));

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		Transform* Playertr = SceneManager::GetPlayerScript()->GetOwner()->GetComponent<Transform>();
		Vector3 Playerpos = Playertr->GetPosition();

		if (dir == 0 && smack == true)
		{
			if (mBanBanState == BanBanState::Move || mBanBanState == BanBanState::Idle)
			{
				if (-0.5f <= Playerpos.x - pos.x && Playerpos.x - pos.x <= 0.0f)
				{
					Animator* at = GetOwner()->GetComponent<Animator>();

					smack = false;
					mBanBanState = BanBanState::Smacking;
					at->PlayAnimation(L"LeftSmacking", false);
				}
			}
		}

		if (dir == 1 && smack == true)
		{
			if (mBanBanState == BanBanState::Move || mBanBanState == BanBanState::Idle)
			{
				if (0.0f <= Playerpos.x - pos.x && Playerpos.x - pos.x <= 0.5f)
				{
					Animator* at = GetOwner()->GetComponent<Animator>();

					smack = false;
					mBanBanState = BanBanState::Smacking;
					at->PlayAnimation(L"RightSmacking", false);
				}
			}
		}

		if (energybolttime >= 5.0f && energy == true && dir == 0 && smack != false)
		{
			if (mBanBanState == BanBanState::Move || mBanBanState == BanBanState::Idle)
			{
				if (-2.5f <= Playerpos.x - pos.x && Playerpos.x - pos.x <= 0.0f)
				{
					Animator* at = GetOwner()->GetComponent<Animator>();

					if (CreateBall == true)
					{
						CreateBall = false;
					}

					energybolttime = 0.0f;
					energy = false;
					mBanBanState = BanBanState::EnergyBolt;
					at->PlayAnimation(L"LeftEnergyBolt", true);
				}
			}
		}

		if (energybolttime >= 5.0f && energy == true && dir == 1 && smack != false)
		{
			if (mBanBanState == BanBanState::Move || mBanBanState == BanBanState::Idle)
			{
				if (0.0f < Playerpos.x - pos.x && Playerpos.x - pos.x < 2.5f)
				{
					Animator* at = GetOwner()->GetComponent<Animator>();

					if (CreateBall == true)
					{
						CreateBall = false;
					}

					energybolttime = 0.0f;
					energy = false;
					mBanBanState = BanBanState::EnergyBolt;
					at->PlayAnimation(L"RightEnergyBolt", true);
				}
			}
		}

		if (eq == true && earthquaketime >= 9.0f && dir == 0 && smack != false && energy == true)
		{
			if (mBanBanState == BanBanState::Move || mBanBanState == BanBanState::Idle)
			{
				Animator* at = GetOwner()->GetComponent<Animator>();

				earthquaketime = 0.0f;
				eq = false;
				mBanBanState = BanBanState::EarthQuake;
				at->PlayAnimation(L"LeftEarthQuake", true);
			}
		}

		if (eq == true && earthquaketime >= 9.0f && dir == 1 && smack != false && energy == true)
		{
			if (mBanBanState == BanBanState::Move || mBanBanState == BanBanState::Idle)
			{
				Animator* at = GetOwner()->GetComponent<Animator>();

				earthquaketime = 0.0f;
				eq = false;
				mBanBanState = BanBanState::EarthQuake;
				at->PlayAnimation(L"RightEarthQuake", true);
			}
		}

		if (blinktime >= 7.0f && bk == true && eq == true && smack != false && energy == true)
		{
			if (mBanBanState == BanBanState::Move || mBanBanState == BanBanState::Idle)
			{
				Animator* at = GetOwner()->GetComponent<Animator>();

				blinktime = 0.0f;
				bk = false;
				mBanBanState = BanBanState::BlinkIn;
				at->PlayAnimation(L"BlinkIn", false);
			}
		}

		if (GetLeftBall() != nullptr)
		{
			Transform* tr = GetLeftBall()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();

			if (pos.x <= -5.0f)
			{
				object::Destroy(GetLeftBall());
				SetLeftBall(nullptr);
			}
		}

		if (GetRightBall() != nullptr)
		{
			Transform* tr = GetLeftBall()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();

			if (pos.x >= 5.0f)
			{
				object::Destroy(GetRightBall());
				SetRightBall(nullptr);
			}
		}

		if (DieCheck == false && HP <= 0 && dir == 0)
		{
			DieCheck = true;
			Animator* at = GetOwner()->GetComponent<Animator>();
			GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));
			mBanBanState = BanBanState::Die;
			at->PlayAnimation(L"BanBanLeftDie", false);
		}
		if (DieCheck == false && HP <= 0 && dir == 1)
		{
			DieCheck = true;
			Animator* at = GetOwner()->GetComponent<Animator>();
			GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));
			mBanBanState = BanBanState::Die;
			at->PlayAnimation(L"BanBanRightDie", false);
		}


		switch (mBanBanState)
		{
		case BanBanScript::BanBanState::Zen:
			zen();
			break;
		case BanBanScript::BanBanState::Idle:
			idle();
			break;
		case BanBanScript::BanBanState::Move:
			move();
			break;
		case BanBanScript::BanBanState::Smacking:
			smacking();
			break;
		case BanBanScript::BanBanState::EnergyBolt:
			energybolt();
			break;
		case BanBanScript::BanBanState::EarthQuake:
			earthquake();
			break;
		case BanBanScript::BanBanState::BlinkIn:
			blinkin();
			break;
		case BanBanScript::BanBanState::BlinkOut:
			blinkout();
			break;
		case BanBanScript::BanBanState::Hit:
			hit();
			break;
		case BanBanScript::BanBanState::Die:
			die();
			break;
		default:
			break;
		}

	}
	void BanBanScript::OnCollisionEnter(Collider2D* other)
	{
		/*if (other->GetOwner()->GetName() == L"LeftPhantomBlow")
		{
			if (dir == 0)
			{
				Animator* at = GetOwner()->GetComponent<Animator>();
				at->PlayAnimation(L"BanBanLeftHit", false);
				mBanBanState = BanBanState::Hit;
			}
			if (dir == 1)
			{
				Animator* at = GetOwner()->GetComponent<Animator>();
				at->PlayAnimation(L"BanBanRightHit", false);
				mBanBanState = BanBanState::Hit;
			}
		}
		if (other->GetOwner()->GetName() == L"RightPhantomBlow")
		{
			if (dir == 0)
			{
				Animator* at = GetOwner()->GetComponent<Animator>();
				at->PlayAnimation(L"BanBanLeftHit", false);
				mBanBanState = BanBanState::Hit;
			}
			if (dir == 1)
			{
				Animator* at = GetOwner()->GetComponent<Animator>();
				at->PlayAnimation(L"BanBanRightHit", false);
				mBanBanState = BanBanState::Hit;
			}
		}*/
	}
	void BanBanScript::OnCollisionStay(Collider2D* other)
	{
	}
	void BanBanScript::OnCollisionExit(Collider2D* other)
	{
	}
	void BanBanScript::SetDamage(int damage)
	{
		HP -= damage;
	}
	void BanBanScript::zen()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		zentime += Time::DeltaTime();

		if (zentime >= 2.5f)
		{
			zentime = 0.0f;
			mBanBanState = BanBanState::Idle;
			at->PlayAnimation(L"LeftIdle", true);
			GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(pos.x, -0.8f, 0.999f));
			GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));

			CreateBanBanHP();
		}
	}
	void BanBanScript::idle()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(pos.x, -0.8f, 0.999f));
		GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));

		if (dir == 0)
		{
			GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(pos.x, -0.8f, 0.999f));
			mBanBanState = BanBanState::Move;
			at->PlayAnimation(L"LeftMove", true);
		}

		if (dir == 1)
		{
			GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(pos.x, -0.8f, 0.999f));
			mBanBanState = BanBanState::Move;
			at->PlayAnimation(L"RightMove", true);
		}
	}
	void BanBanScript::move()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		energybolttime += Time::DeltaTime();
		earthquaketime += Time::DeltaTime();
		blinktime += Time::DeltaTime();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		Transform* Playertr = SceneManager::GetPlayerScript()->GetOwner()->GetComponent<Transform>();
		Vector3 Playerpos = Playertr->GetPosition();

		if (dir == 0)
		{
			if (Playerpos.x >= pos.x)
			{
				dir = 1;
				at->PlayAnimation(L"RightMove", true);
			}

			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();

			pos.x -= 0.2f * Time::DeltaTime();
			GetOwner()->GetComponent<Transform>()->SetPosition(pos);
		}
		if (dir == 1)
		{
			if (Playerpos.x <= pos.x)
			{
				dir = 0;
				at->PlayAnimation(L"LeftMove", true);
			}

			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();

			pos.x += 0.2f * Time::DeltaTime();
			GetOwner()->GetComponent<Transform>()->SetPosition(pos);
		}
	}
	void BanBanScript::smacking()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(pos.x, -0.55f, 0.999f));
		GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));

		smackingtime += Time::DeltaTime();

		if (dir == 0 && smackingtime >= 0.8f)
		{
			Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
			cd->SetCenter(Vector2(-0.3f, -0.3f));
			cd->SetSize(Vector2(0.5f, 0.5f));
		}
		if (dir == 1 && smackingtime >= 0.8f)
		{
			Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
			cd->SetCenter(Vector2(0.3f, -0.3f));
			cd->SetSize(Vector2(0.5f, 0.5f));
		}
		if (smackingtime >= 2.2f)
		{
			if (dir == 0)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(pos.x + 0.1f, -0.8f, 0.999f));
				mBanBanState = BanBanState::Idle;
				at->PlayAnimation(L"LeftIdle", true);
				smackingtime = 0.0f;
				smack = true;
			}

			if (dir == 1)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(pos.x - 0.1f, -0.8f, 0.999f));
				mBanBanState = BanBanState::Idle;
				at->PlayAnimation(L"RightIdle", true);
				smackingtime = 0.0f;
				smack = true;
			}
		}
	}
	void BanBanScript::energybolt()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(pos.x, -0.55f, 0.999f));
		GetOwner()->GetComponent<Transform>()->SetScale(Vector3(4.0f, 4.0f, 0.999f));

		if (dir == 0 && CreateBall == false)
		{
			ballcreatetime += Time::DeltaTime();

			if (ballcreatetime >= 1.7f)
			{
				ballcreatetime = 0.0;
				CreateBall = true;
				CreateLeftBall();
			}
		}

		if (dir == 1 && CreateBall == false)
		{
			ballcreatetime += Time::DeltaTime();

			if (ballcreatetime >= 1.7f)
			{
				ballcreatetime = 0.0;
				CreateBall = true;
				CreateRightBall();
			}
		}

		energytime += Time::DeltaTime();

		if (energytime >= 2.3f)
		{
			if (dir == 0)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(pos.x + 0.1f, -0.8f, 0.999f));
				mBanBanState = BanBanState::Idle;
				at->PlayAnimation(L"LeftIdle", true);
				energytime = 0.0f;
				energybolttime = 0.0f;
				energy = true;
			}

			if (dir == 1)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(pos.x - 0.1f, -0.8f, 0.999f));
				mBanBanState = BanBanState::Idle;
				at->PlayAnimation(L"RightIdle", true);
				energytime = 0.0f;
				energybolttime = 0.0f;
				energy = true;
			}
		}
	}
	void BanBanScript::earthquake()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(pos.x, -0.4f, 0.999f));
		GetOwner()->GetComponent<Transform>()->SetScale(Vector3(4.0f, 4.0f, 0.999f));

		earthtime += Time::DeltaTime();

		if (SceneManager::GetPlayerScript()->GetDieCheck() == false && earthhit && earthtime >= 1.0f && earthtime >= 1.1f)
		{
			earthhit = false;
			if (SceneManager::GetPlayerScript()->GetOwner()->GetComponent<RigidBody>()->GetGround())
			{
				SceneManager::GetPlayerScript()->SetEarthQuake(true);
				Transform* tr = SceneManager::GetPlayerScript()->GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();

				SceneManager::GetPlayerScript()->CreateHitDamage(GetOwner(), Vector3(pos.x - 0.1f, pos.y, pos.z));

			}
		}

		if (earthtime >= 1.6f)
		{
			if (dir == 0)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(pos.x, -0.8f, 0.999f));
				mBanBanState = BanBanState::Idle;
				at->PlayAnimation(L"LeftIdle", true);
				earthtime = 0.0f;
				earthhit = true;
				eq = true;
			}

			if (dir == 1)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(pos.x, -0.8f, 0.999f));
				mBanBanState = BanBanState::Idle;
				at->PlayAnimation(L"RightIdle", true);
				earthtime = 0.0f;
				earthhit = true;
				eq = true;
			}
		}
	}
	void BanBanScript::forceteleport()
	{
	}
	void BanBanScript::blinkin()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		btime += Time::DeltaTime();
		if (btime >= 0.35f)
		{
			btime = 0.0f;
			randompos = dist2(rng2);

			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(pos.x + randompos, -0.8f, 0.999f));
			mBanBanState = BanBanState::BlinkOut;
			at->PlayAnimation(L"BlinkOut", false);
		}
	}
	void BanBanScript::blinkout()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		btime += Time::DeltaTime();
		if (btime >= 0.35f)
		{
			btime = 0.0f;
			if (dir == 0)
			{
				mBanBanState = BanBanState::Idle;;
				at->PlayAnimation(L"LeftIdle", false);
				bk = true;
			}
			if (dir == 1)
			{
				mBanBanState = BanBanState::Idle;;
				at->PlayAnimation(L"RightIdle", false);
				bk = true;
			}
		}
	}
	void BanBanScript::hit()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		hittime += Time::DeltaTime();

		if (hittime >= 0.5f && dir == 0)
		{
			hittime = 0.0f;
			at->PlayAnimation(L"LeftIdle", true);
			mBanBanState = BanBanState::Idle;
		}

		if (hittime >= 0.5f && dir == 1)
		{
			hittime = 0.0f;
			at->PlayAnimation(L"RightIdle", true);
			mBanBanState = BanBanState::Idle;
		}

	}
	void BanBanScript::die()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		dietime += Time::DeltaTime();

		if (dir == 0 && dietime >= 1.5f)
		{
			dietime = 0.0f;
			object::Destroy(GetOwner());
			object::Destroy(BanBanHP);
		}

		if (dir == 1 && dietime >= 1.5f)
		{
			dietime = 0.0f;
			object::Destroy(GetOwner());
			object::Destroy(BanBanHP);
		}
	}
	void BanBanScript::CreateLeftBall()
	{
		//Collider2D* cd = player->AddComponent<Collider2D>();
		//cd->SetCenter(Vector2(0.008f, 0.055f));
		//cd->SetSize(Vector2(0.22f, 0.38f));

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		GameObject* LeftBall
			= object::Instantiate<GameObject>(Vector3(pos.x - 0.8f, pos.y - 0.2f, 0.999f), eLayerType::Monster);

		SetLeftBall(LeftBall);

		LeftBall->SetName(L"LeftBall");


		MeshRenderer* mr = LeftBall->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		LeftBall->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));

		Animator* at = LeftBall->AddComponent<Animator>();
		LeftBall->AddComponent<BallScript>();


		//mBallScript->SetBallState(BallScript::BallState::LeftBall);
	}
	void BanBanScript::CreateRightBall()
	{

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		{
			GameObject* RightBall
				= object::Instantiate<GameObject>(Vector3(pos.x + 0.8F, pos.y - 0.2f, 0.999f), eLayerType::Monster);

			SetRightBall(RightBall);

			RightBall->SetName(L"RightBall");


			MeshRenderer* mr = RightBall->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			RightBall->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));

			Animator* at = RightBall->AddComponent<Animator>();
			BallScript* bs = RightBall->AddComponent<BallScript>();
			bs->SetDir(true);
		}
	}
	void BanBanScript::CreateBanBanHP()
	{
		{
			GameObject* BanBanHP
				= object::Instantiate<GameObject>(Vector3(0.0f, 2.1f, 0.97f), eLayerType::UI);

			SetBanBanHP(BanBanHP);

			BanBanHP->SetName(L"BanBanHP");

			MeshRenderer* mr = BanBanHP->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"banbanhp"));

			BanBanHP->GetComponent<Transform>()->SetScale(Vector3(4.5f, 0.25f, 0.999f));

			Animator* at = BanBanHP->AddComponent<Animator>();
		}

		{
			GameObject* BanBanHPFront
				= object::Instantiate<GameObject>(Vector3(0.1f, 2.16f, 0.971f), eLayerType::UI);

			BanBanHPFront->SetName(L"BanBanHPFront");

			MeshRenderer* mr = BanBanHPFront->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"banbanhpfrontbar"));

			BanBanHPFront->GetComponent<Transform>()->SetScale(Vector3(4.28f, 0.08f, 1.000f));
			bhs = BanBanHPFront->AddComponent<BanBanHPScript>();
			SetBanBanHPScript(bhs);
		}
	}
}