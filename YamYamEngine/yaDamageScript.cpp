#include "yaDamageScript.h"
#include "yaPlayerScript.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaCollider2D.h"
#include "yaObject.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include <random>

std::mt19937_64 rng3(0);
std::uniform_int_distribution<__int64> dist3(50000, 99999);

namespace ya
{
	DamageScript::DamageScript()
		: dmgtime(0.0f)
		, Damage(0)
		, dmg(false)
	{

	}
	DamageScript::~DamageScript()
	{

	}
	void DamageScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> Basic0 = Resources::Load<Texture>(L"Basic0", L"..\\Resources\\Texture\\Damage\\Basic0.png");
		std::shared_ptr<Texture> Basic1 = Resources::Load<Texture>(L"Basic1", L"..\\Resources\\Texture\\Damage\\Basic1.png");
		std::shared_ptr<Texture> Basic2 = Resources::Load<Texture>(L"Basic2", L"..\\Resources\\Texture\\Damage\\Basic2.png");
		std::shared_ptr<Texture> Basic3 = Resources::Load<Texture>(L"Basic3", L"..\\Resources\\Texture\\Damage\\Basic3.png");
		std::shared_ptr<Texture> Basic4 = Resources::Load<Texture>(L"Basic4", L"..\\Resources\\Texture\\Damage\\Basic4.png");
		std::shared_ptr<Texture> Basic5 = Resources::Load<Texture>(L"Basic5", L"..\\Resources\\Texture\\Damage\\Basic5.png");
		std::shared_ptr<Texture> Basic6 = Resources::Load<Texture>(L"Basic6", L"..\\Resources\\Texture\\Damage\\Basic6.png");
		std::shared_ptr<Texture> Basic7 = Resources::Load<Texture>(L"Basic7", L"..\\Resources\\Texture\\Damage\\Basic7.png");
		std::shared_ptr<Texture> Basic8 = Resources::Load<Texture>(L"Basic8", L"..\\Resources\\Texture\\Damage\\Basic8.png");
		std::shared_ptr<Texture> Basic9 = Resources::Load<Texture>(L"Basic9", L"..\\Resources\\Texture\\Damage\\Basic9.png");
		

		at->Create(L"Basic0", Basic0, Vector2(0.0f, 0.0f), Vector2(37.0f, 39.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"Basic1", Basic1, Vector2(0.0f, 0.0f), Vector2(37.0f, 39.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"Basic2", Basic2, Vector2(0.0f, 0.0f), Vector2(37.0f, 39.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"Basic3", Basic3, Vector2(0.0f, 0.0f), Vector2(37.0f, 39.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"Basic4", Basic4, Vector2(0.0f, 0.0f), Vector2(37.0f, 39.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"Basic5", Basic5, Vector2(0.0f, 0.0f), Vector2(37.0f, 39.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"Basic6", Basic6, Vector2(0.0f, 0.0f), Vector2(37.0f, 39.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"Basic7", Basic7, Vector2(0.0f, 0.0f), Vector2(37.0f, 39.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"Basic8", Basic8, Vector2(0.0f, 0.0f), Vector2(37.0f, 39.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"Basic9", Basic9, Vector2(0.0f, 0.0f), Vector2(37.0f, 39.0f), 1, Vector2::Zero, 0.1f);
		//at->Create(L"Basic0", Basic0, Vector2(0.0f, 0.0f), Vector2(236.0f, 133.0f), 8, Vector2::Zero, 0.1f);

		at->PlayAnimation(L"Basic0", false);

		mDamageState = DamageState::Basic;
	}
	void DamageScript::Update()
	{
		Damage = dist3(rng3);

			if (GetOwner()->GetName() == L"Damage1")
			{
				Damage = Damage / 10000;
			}
			if (GetOwner()->GetName() == L"Damage2")
			{
				Damage = (Damage % 10000) / 1000;
			}
			if (GetOwner()->GetName() == L"Damage3")
			{
				Damage = (Damage % 1000) / 100;
			}
			if (GetOwner()->GetName() == L"Damage4")
			{
				Damage = (Damage % 100) / 10;
			}
			if (GetOwner()->GetName() == L"Damage5")
			{
				Damage = Damage % 10;
			}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		switch (mDamageState)
		{
		case DamageScript::DamageState::Basic:
			basic();
			break;
		case DamageScript::DamageState::Critical:
			critical();
			break;
		default:
			break;
		}
	}
	void DamageScript::OnCollisionEnter(Collider2D* other)
	{

	}
	void DamageScript::OnCollisionStay(Collider2D* other)
	{

	}
	void DamageScript::OnCollisionExit(Collider2D* other)
	{

	}

	void DamageScript::basic()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		if (dmg == false)
		{
			dmg = true;

			if (Damage == 1)
			{
				at->PlayAnimation(L"Basic1", false);
			}
			if (Damage == 2)
			{
				at->PlayAnimation(L"Basic2", false);
			}
			if (Damage == 3)
			{
				at->PlayAnimation(L"Basic3", false);
			}
			if (Damage == 4)
			{
				at->PlayAnimation(L"Basic4", false);
			}
			if (Damage == 5)
			{
				at->PlayAnimation(L"Basic5", false);
			}
			if (Damage == 6)
			{
				at->PlayAnimation(L"Basic6", false);
			}
			if (Damage == 7)
			{
				at->PlayAnimation(L"Basic7", false);
			}
			if (Damage == 8)
			{
				at->PlayAnimation(L"Basic8", false);
			}
			if (Damage == 9)
			{
				at->PlayAnimation(L"Basic9", false);
			}
		}


		dmgtime += Time::DeltaTime();

		if (dmgtime >= 1.0f)
		{
			dmgtime = 0.0f;
			object::Destroy(GetOwner());
			dmg = false;
		}

		pos.y += 0.1f * Time::DeltaTime();
		tr->SetPosition(pos);


	}

	void DamageScript::critical()
	{
	}

}