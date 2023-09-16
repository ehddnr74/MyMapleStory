#include "yaHavisScript.h"
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
#include "yaMesh.h"
#include "yaMeshRenderer.h"
#include "yaFontWrapper.h"
#include "yaCamera.h"
#include "yaInventoryScript.h"

namespace ya
{
	HavisScript::HavisScript()
		: LookingShop(false)
		, rootabysskeyselect(false)
		, isBuy(false)
	{
	}
	HavisScript::~HavisScript()
	{
	}
	void HavisScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> Havis = Resources::Load<Texture>(L"Havis", L"..\\Resources\\Texture\\BanBan\\Havis.png");

		at->Create(L"Havis", Havis, Vector2(0.0f, 0.0f), Vector2(73.0f, 82.0f), 9, Vector2::Zero, 0.3f);

		at->PlayAnimation(L"Havis", true);

		mHavisState = HavisState::Stand;

	}
	void HavisScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		if (LookingShop == true)
		{
			if (Input::GetKeyDown(eKeyCode::ESC))
			{
				LookingShop = false;
				CloseShop();
			}
		}


		switch (mHavisState)
		{
		case HavisScript::HavisState::Stand:
			stand();
			break;
		default:
			break;
		}
	}
	void HavisScript::OnCollisionEnter(Collider2D* other)
	{

	}
	void HavisScript::OnCollisionStay(Collider2D* other)
	{
	}
	void HavisScript::OnCollisionExit(Collider2D* other)
	{
	}
	void HavisScript::OnShop() // 아이템창 켠 상태로 상점 클릭 시 전의 아이템창 Delete 해줘야함!!
	{
		if (SceneManager::GetPlayerScript()->GetOnInventory())
		{
			SceneManager::GetPlayerScript()->SetOnInventory(false);
			SceneManager::GetPlayerScript()->CloseInventory();
		}
		SceneManager::GetPlayerScript()->OnInventory();
		SceneManager::GetPlayerScript()->SetOnShop(true);
		SceneManager::GetPlayerScript()->SetInventory(true);
		{
			mShop1
				= object::Instantiate<GameObject>(Vector3(0.0f , 0.3f, 0.999f), eLayerType::Shop);

			SetShop1(mShop1);

			mShop1->SetName(L"Shop");

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShop1->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shop1"));

			mShop1->GetComponent<Transform>()->SetScale(Vector3(3.8f, 3.5f, 1.0001f));
		}

		{
			mShop2
				= object::Instantiate<GameObject>(Vector3(0.0f,0.3f, 0.998f), eLayerType::Shop);

			SetShop2(mShop2);

			mShop2->SetName(L"Shop2");

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShop2->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shop2"));

			mShop2->GetComponent<Transform>()->SetScale(Vector3(3.7f, 3.4f, 1.0001f));
		}

		{
			mShop3
				= object::Instantiate<GameObject>(Vector3(0.0f, -0.08f, 0.997f), eLayerType::Shop);

			mShop3->SetName(L"Shop3");

			SetShop3(mShop3);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShop3->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shop3"));

			mShop3->GetComponent<Transform>()->SetScale(Vector3(3.68f, 2.6f, 1.0001f));
		}

		{
			 mShopHavis
				= object::Instantiate<GameObject>(Vector3(-1.42f, 1.7f, 0.996f), eLayerType::Shop);

			 mShopHavis->SetName(L"ShopHavis");

			 SetShopHavis(mShopHavis);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShopHavis->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shophavis"));

			mShopHavis->GetComponent<Transform>()->SetScale(Vector3(0.5f, 0.5f, 1.0001f));
		}

		{
			mShopPlayer
				= object::Instantiate<GameObject>(Vector3(0.585f, 1.68f, 0.996f), eLayerType::Shop);

			mShopPlayer->SetName(L"ShopPlayer");

			SetShopPlayer(mShopPlayer);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShopPlayer->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopplayer"));

			mShopPlayer->GetComponent<Transform>()->SetScale(Vector3(0.3f, 0.45f, 1.0001f));
		}

		{
			mShopBuy
				= object::Instantiate<GameObject>(Vector3(- 0.15f, 1.5f, 0.995f), eLayerType::Shop);

			mShopBuy->SetName(L"ShopBuy");

			SetShopBuy(mShopBuy);

			Collider2D* cd = mShopBuy->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, 0.0f));
			cd->SetSize(Vector2(1.0f, 0.7f));

			MeshRenderer* mr = mShopBuy->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopbuy"));

			mShopBuy->GetComponent<Transform>()->SetScale(Vector3(0.5f, 0.13f, 1.0001f));
		}

		{
			mShopSell
				= object::Instantiate<GameObject>(Vector3(1.57f, 1.5f, 0.996f), eLayerType::Shop);

			mShopSell->SetName(L"ShopSell");

			SetShopSell(mShopSell);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShopSell->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopsell"));

			mShopSell->GetComponent<Transform>()->SetScale(Vector3(0.5f, 0.13f, 1.0001f));
		}

		{
			mShopExit
				= object::Instantiate<GameObject>(Vector3(- 0.15f, 1.85f, 0.996f), eLayerType::Shop);

			mShopExit->SetName(L"ShopExit");

			SetShopExit(mShopExit);

			Collider2D* cd = mShopExit->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, 0.0f));
			cd->SetSize(Vector2(1.0f, 0.7f));

			MeshRenderer* mr = mShopExit->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopexit"));

			mShopExit->GetComponent<Transform>()->SetScale(Vector3(0.5f, 0.13f, 1.0001f));
		}

		{
			mShopEtc
				= object::Instantiate<GameObject>(Vector3(-1.3f, 1.292f, 0.996f), eLayerType::Shop);
		
			mShopEtc->SetName(L"ShopEtc");

			SetShopEtc(mShopEtc);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShopEtc->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopetc"));

			mShopEtc->GetComponent<Transform>()->SetScale(Vector3(1.6f, 0.14f, 1.0001f));
		}

		{
			mShopEtc2
				= object::Instantiate<GameObject>(Vector3(0.745f, 1.292f, 0.996f), eLayerType::Shop);

			mShopEtc2->SetName(L"ShopEtc2");

			SetShopEtc2(mShopEtc2);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShopEtc2->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopetc"));

			mShopEtc2->GetComponent<Transform>()->SetScale(Vector3(1.6f, 0.14f, 1.0001f));
		}

		{
			mShopMesoBox
				= object::Instantiate<GameObject>(Vector3(1.4f, 1.64f, 0.996f), eLayerType::Shop);

			mShopMesoBox->SetName(L"mShopMesoBox");

			SetShopMesoBox(mShopMesoBox);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShopMesoBox->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopmesobox"));

			mShopMesoBox->GetComponent<Transform>()->SetScale(Vector3(0.85f, 0.12f, 1.0001f));
		}

		{
			mRootaByssKey
				= object::Instantiate<GameObject>(Vector3(- 1.69f, 1.06f, 0.996f), eLayerType::Shop);

			mRootaByssKey->SetName(L"RootaByssKey");

			SetShopRootaByssKey(mRootaByssKey);

			Collider2D* cd = mRootaByssKey->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.78f, 0.0f));
			cd->SetSize(Vector2(9.0f, 1.1f));

			MeshRenderer* mr = mRootaByssKey->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"rootabysskey"));

			mRootaByssKey->GetComponent<Transform>()->SetScale(Vector3(0.2f, 0.2f, 1.0001f));
		}

		{
			mShopMeso1
				= object::Instantiate<GameObject>(Vector3(- 1.475f,1.007f, 0.996f), eLayerType::Shop);

			mShopMeso1->SetName(L"mShopMeso1");

			SetShopMeso1(mShopMeso1);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShopMeso1->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopmeso"));

			mShopMeso1->GetComponent<Transform>()->SetScale(Vector3(0.1f, 0.1f, 1.0001f));
		}
	}
	void HavisScript::CloseShop()
	{
		object::Destroy(mShop1);
		object::Destroy(mShop2);
		object::Destroy(mShop3);
		object::Destroy(mShopHavis);
		object::Destroy(mShopPlayer);
		object::Destroy(mShopBuy);
		object::Destroy(mShopSell);
		object::Destroy(mShopExit);
		object::Destroy(mShopEtc);
		object::Destroy(mShopEtc2);
		object::Destroy(mShopMesoBox);
		object::Destroy(mRootaByssKey);
		object::Destroy(mShopMeso1);

		if (rootabysskeyselect)
		{
			object::Destroy(mRootaByssKeySelect);
			object::Destroy(mSelectRootaByssKey);
			object::Destroy(mSelectRootaByssMeso);

		}
	}
	void HavisScript::Buy()
	{
		if (rootabysskeyselect == true && isBuy == true)
		{
			isBuy = false;
			mInventoryScript = SceneManager::GetPlayerScript()->GetInventoryScript();
			SetInventoryScript(mInventoryScript);
			
			mInventoryScript->Buying();
		}
		

	}
	void HavisScript::RootaByssKeySelect()
	{
		rootabysskeyselect = true;
		{
			mRootaByssKeySelect
				= object::Instantiate<GameObject>(Vector3(-0.905f, 1.065f, 0.995f), eLayerType::Shop);

			mRootaByssKeySelect->SetName(L"mRootaByssKeySelect");

			SetRootaByssKeySelect(mRootaByssKeySelect);

			//Collider2D* cd = mRootaByssKey->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.78f, 0.0f));
			//cd->SetSize(Vector2(9.0f, 1.1f));

			MeshRenderer* mr = mRootaByssKeySelect->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopselect"));

			mRootaByssKeySelect->GetComponent<Transform>()->SetScale(Vector3(1.83f, 0.23f, 1.0001f));
		}

		{
			mSelectRootaByssKey
				= object::Instantiate<GameObject>(Vector3(-1.69f, 1.06f, 0.994f), eLayerType::Shop);

			SetSelctRootaByssKey(mSelectRootaByssKey);

			Collider2D* cd = mSelectRootaByssKey->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.78f, 0.0f));
			cd->SetSize(Vector2(9.0f, 1.1f));

			MeshRenderer* mr = mSelectRootaByssKey->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"rootabysskey"));

			mSelectRootaByssKey->GetComponent<Transform>()->SetScale(Vector3(0.2f, 0.2f, 1.0001f));
		}

		{
			mSelectRootaByssMeso
				= object::Instantiate<GameObject>(Vector3(-1.475f, 1.007f, 0.994f), eLayerType::Shop);

			mSelectRootaByssMeso->SetName(L"mShopMeso1");

			SetSelectRootByssKeyMeso(mSelectRootaByssMeso);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mSelectRootaByssMeso->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopmeso"));

			mSelectRootaByssMeso->GetComponent<Transform>()->SetScale(Vector3(0.1f, 0.1f, 1.0001f));
		}
	}
	void HavisScript::stand()
	{

	}
}
