#include "yaHitDamageScript.h"
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

namespace ya
{
	HitDamageScript::HitDamageScript()
		: Hitdmgtime(0.0f)
		, HitDamage(0)
		, Hitdmg(false)
	{

	}
	HitDamageScript::~HitDamageScript()
	{

	}
	void HitDamageScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> HitBasic0 = Resources::Load<Texture>(L"HitBasic0", L"..\\Resources\\Texture\\Damage\\HitBasic0.png");
		std::shared_ptr<Texture> HitBasic1 = Resources::Load<Texture>(L"HitBasic1", L"..\\Resources\\Texture\\Damage\\HitBasic1.png");
		std::shared_ptr<Texture> HitBasic2 = Resources::Load<Texture>(L"HitBasic2", L"..\\Resources\\Texture\\Damage\\HitBasic2.png");
		std::shared_ptr<Texture> HitBasic3 = Resources::Load<Texture>(L"HitBasic3", L"..\\Resources\\Texture\\Damage\\HitBasic3.png");
		std::shared_ptr<Texture> HitBasic4 = Resources::Load<Texture>(L"HitBasic4", L"..\\Resources\\Texture\\Damage\\HitBasic4.png");
		std::shared_ptr<Texture> HitBasic5 = Resources::Load<Texture>(L"HitBasic5", L"..\\Resources\\Texture\\Damage\\HitBasic5.png");
		std::shared_ptr<Texture> HitBasic6 = Resources::Load<Texture>(L"HitBasic6", L"..\\Resources\\Texture\\Damage\\HitBasic6.png");
		std::shared_ptr<Texture> HitBasic7 = Resources::Load<Texture>(L"HitBasic7", L"..\\Resources\\Texture\\Damage\\HitBasic7.png");
		std::shared_ptr<Texture> HitBasic8 = Resources::Load<Texture>(L"HitBasic8", L"..\\Resources\\Texture\\Damage\\HitBasic8.png");
		std::shared_ptr<Texture> HitBasic9 = Resources::Load<Texture>(L"HitBasic9", L"..\\Resources\\Texture\\Damage\\HitBasic9.png");


		at->Create(L"HitBasic0", HitBasic0, Vector2(0.0f, 0.0f), Vector2(31.0f, 33.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"HitBasic1", HitBasic1, Vector2(0.0f, 0.0f), Vector2(31.0f, 33.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"HitBasic2", HitBasic2, Vector2(0.0f, 0.0f), Vector2(31.0f, 33.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"HitBasic3", HitBasic3, Vector2(0.0f, 0.0f), Vector2(31.0f, 33.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"HitBasic4", HitBasic4, Vector2(0.0f, 0.0f), Vector2(31.0f, 33.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"HitBasic5", HitBasic5, Vector2(0.0f, 0.0f), Vector2(31.0f, 33.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"HitBasic6", HitBasic6, Vector2(0.0f, 0.0f), Vector2(31.0f, 33.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"HitBasic7", HitBasic7, Vector2(0.0f, 0.0f), Vector2(31.0f, 33.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"HitBasic8", HitBasic8, Vector2(0.0f, 0.0f), Vector2(31.0f, 33.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"HitBasic9", HitBasic9, Vector2(0.0f, 0.0f), Vector2(31.0f, 33.0f), 1, Vector2::Zero, 0.1f);
		//at->Create(L"Basic0", Basic0, Vector2(0.0f, 0.0f), Vector2(236.0f, 133.0f), 8, Vector2::Zero, 0.1f);

		at->PlayAnimation(L"HitBasic0", false);

		mDamageState = DamageState::Basic;
	}
	void HitDamageScript::Update()
	{

		if (99 < HitDamage && HitDamage < 1000)
		{
			if (GetOwner()->GetName() == L"HitDamage1")
			{
				HitDamage = (HitDamage % 1000) / 100;
			}
			if (GetOwner()->GetName() == L"HitDamage2")
			{
				HitDamage = (HitDamage % 100) / 10;
			}
			if (GetOwner()->GetName() == L"HitDamage3")
			{
				HitDamage = HitDamage % 10;
			}
		}

		if (999 < HitDamage && HitDamage < 10000)
		{
			if (GetOwner()->GetName() == L"HitDamage1")
			{
				HitDamage = (HitDamage % 10000) / 1000;
			}
			if (GetOwner()->GetName() == L"HitDamage2")
			{
				HitDamage = (HitDamage % 1000) / 100;
			}
			if (GetOwner()->GetName() == L"HitDamage3")
			{
				HitDamage = (HitDamage % 100) / 10;
			}
			if (GetOwner()->GetName() == L"HitDamage4")
			{
				HitDamage = HitDamage % 10;
			}
		}



		if (9999 < HitDamage && HitDamage < 100000)
		{
			if (GetOwner()->GetName() == L"HitDamage1")
			{
				HitDamage = HitDamage / 10000;
			}
			if (GetOwner()->GetName() == L"HitDamage2")
			{
				HitDamage = (HitDamage % 10000) / 1000;
			}
			if (GetOwner()->GetName() == L"HitDamage3")
			{
				HitDamage = (HitDamage % 1000) / 100;
			}
			if (GetOwner()->GetName() == L"HitDamage4")
			{
				HitDamage = (HitDamage % 100) / 10;
			}
			if (GetOwner()->GetName() == L"HitDamage5")
			{
				HitDamage = HitDamage % 10;
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		switch (mDamageState)
		{
		case HitDamageScript::DamageState::Basic:
			basic();
			break;
		default:
			break;
		}
	}
	void HitDamageScript::OnCollisionEnter(Collider2D* other)
	{

	}
	void HitDamageScript::OnCollisionStay(Collider2D* other)
	{

	}
	void HitDamageScript::OnCollisionExit(Collider2D* other)
	{

	}

	void HitDamageScript::basic()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		if (Hitdmg == false)
		{
			Hitdmg = true;

			if (HitDamage == 1)
			{
				at->PlayAnimation(L"HitBasic1", false);
			}
			if (HitDamage == 2)
			{
				at->PlayAnimation(L"HitBasic2", false);
			}
			if (HitDamage == 3)
			{
				at->PlayAnimation(L"HitBasic3", false);
			}
			if (HitDamage == 4)
			{
				at->PlayAnimation(L"HitBasic4", false);
			}
			if (HitDamage == 5)
			{
				at->PlayAnimation(L"HitBasic5", false);
			}
			if (HitDamage == 6)
			{
				at->PlayAnimation(L"HitBasic6", false);
			}
			if (HitDamage == 7)
			{
				at->PlayAnimation(L"HitBasic7", false);
			}
			if (HitDamage == 8)
			{
				at->PlayAnimation(L"HitBasic8", false);
			}
			if (HitDamage == 9)
			{
				at->PlayAnimation(L"HitBasic9", false);
			}
		}


		Hitdmgtime += Time::DeltaTime();

		if (Hitdmgtime >= 1.3f)
		{
			Hitdmgtime = 0.0f;
			object::Destroy(GetOwner());
			Hitdmg = false;
		}

		pos.y += 0.1f * Time::DeltaTime();
		tr->SetPosition(pos);


	}


}