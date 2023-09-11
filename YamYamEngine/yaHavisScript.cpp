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

namespace ya
{
	HavisScript::HavisScript()
		: LookingShop(false)
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
	void HavisScript::OnShop()
	{
		{
			Transform* PlayerTr = mPScript->GetOwner()->GetComponent<Transform>();

			Vector3 PlayerPos = PlayerTr->GetPosition();

			mShop
				= object::Instantiate<GameObject>(Vector3(PlayerPos.x , PlayerPos.y + 1.5f, 0.999f), eLayerType::Inventory);

			SetShop(mShop);

			mShop->SetName(L"Shop");

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShop->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shop1"));

			mShop->GetComponent<Transform>()->SetScale(Vector3(3.5f, 2.5f, 1.0001f));
		}

		{
			Transform* PlayerTr = mPScript->GetOwner()->GetComponent<Transform>();

			Vector3 PlayerPos = PlayerTr->GetPosition();

			mShop2
				= object::Instantiate<GameObject>(Vector3(PlayerPos.x, PlayerPos.y + 1.5f, 0.998f), eLayerType::Inventory);

			mShop2->SetName(L"Shop2");

			SetShop2(mShop2);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShop->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shop2"));

			mShop->GetComponent<Transform>()->SetScale(Vector3(3.4f, 2.4f, 1.0001f));
		}

		{
			Transform* PlayerTr = mPScript->GetOwner()->GetComponent<Transform>();

			Vector3 PlayerPos = PlayerTr->GetPosition();

			mShop3
				= object::Instantiate<GameObject>(Vector3(PlayerPos.x, PlayerPos.y + 1.3f, 0.997f), eLayerType::Inventory);

			mShop3->SetName(L"Shop3");

			SetShop3(mShop3);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShop3->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shop3"));

			mShop3->GetComponent<Transform>()->SetScale(Vector3(3.38f, 1.9f, 1.0001f));
		}

		{
			Transform* PlayerTr = mPScript->GetOwner()->GetComponent<Transform>();

			Vector3 PlayerPos = PlayerTr->GetPosition();

			 mShopHavis
				= object::Instantiate<GameObject>(Vector3(PlayerPos.x - 1.25f, PlayerPos.y + 2.42f, 0.996f), eLayerType::Inventory);

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
			Transform* PlayerTr = mPScript->GetOwner()->GetComponent<Transform>();

			Vector3 PlayerPos = PlayerTr->GetPosition();

			mShopPlayer
				= object::Instantiate<GameObject>(Vector3(PlayerPos.x + 0.43f, PlayerPos.y + 2.4f, 0.996f), eLayerType::Inventory);

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
			Transform* PlayerTr = mPScript->GetOwner()->GetComponent<Transform>();

			Vector3 PlayerPos = PlayerTr->GetPosition();

			mShopBuy
				= object::Instantiate<GameObject>(Vector3(PlayerPos.x - 0.3f, PlayerPos.y + 2.18f, 0.995f), eLayerType::Inventory);

			mShopBuy->SetName(L"ShopBuy");

			SetShopBuy(mShopBuy);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShopBuy->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopbuy"));

			mShopBuy->GetComponent<Transform>()->SetScale(Vector3(0.4f, 0.1f, 1.0001f));
		}

		{
			Transform* PlayerTr = mPScript->GetOwner()->GetComponent<Transform>();

			Vector3 PlayerPos = PlayerTr->GetPosition();

			mShopSell
				= object::Instantiate<GameObject>(Vector3(PlayerPos.x + 1.1f, PlayerPos.y + 2.32f, 0.996f), eLayerType::Inventory);

			mShopSell->SetName(L"ShopSell");

			SetShopSell(mShopSell);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShopSell->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopsell"));

			mShopSell->GetComponent<Transform>()->SetScale(Vector3(0.4f, 0.1f, 1.0001f));
		}

		{
			Transform* PlayerTr = mPScript->GetOwner()->GetComponent<Transform>();

			Vector3 PlayerPos = PlayerTr->GetPosition();

			mShopExit
				= object::Instantiate<GameObject>(Vector3(PlayerPos.x - 0.3f, PlayerPos.y + 2.32f, 0.996f), eLayerType::Inventory);

			mShopExit->SetName(L"ShopExit");

			SetShopExit(mShopExit);

			Collider2D* cd = mShopExit->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, 0.0f));
			cd->SetSize(Vector2(1.0f, 0.6f));

			MeshRenderer* mr = mShopExit->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopexit"));

			mShopExit->GetComponent<Transform>()->SetScale(Vector3(0.4f, 0.1f, 1.0001f));
		}

		{
			Transform* PlayerTr = mPScript->GetOwner()->GetComponent<Transform>();

			Vector3 PlayerPos = PlayerTr->GetPosition();

			mShopEtc
				= object::Instantiate<GameObject>(Vector3(PlayerPos.x - 1.21f, PlayerPos.y + 1.978f, 0.996f), eLayerType::Inventory);

			mShopEtc->SetName(L"ShopEtc");

			SetShopEtc(mShopEtc);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShopEtc->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopetc"));

			mShopEtc->GetComponent<Transform>()->SetScale(Vector3(1.4f, 0.14f, 1.0001f));
		}

		{
			Transform* PlayerTr = mPScript->GetOwner()->GetComponent<Transform>();

			Vector3 PlayerPos = PlayerTr->GetPosition();

			mShopEtc2
				= object::Instantiate<GameObject>(Vector3(PlayerPos.x + 0.522f, PlayerPos.y + 1.978f, 0.996f), eLayerType::Inventory);

			mShopEtc2->SetName(L"ShopEtc2");

			SetShopEtc2(mShopEtc2);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mShopEtc2->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"shopetc"));

			mShopEtc2->GetComponent<Transform>()->SetScale(Vector3(1.4f, 0.14f, 1.0001f));
		}

		{
			Transform* PlayerTr = mPScript->GetOwner()->GetComponent<Transform>();

			Vector3 PlayerPos = PlayerTr->GetPosition();

			mRootaByssKey
				= object::Instantiate<GameObject>(Vector3(PlayerPos.x - 1.54f, PlayerPos.y + 1.73f, 0.996f), eLayerType::Inventory);

			mRootaByssKey->SetName(L"RootaByssKey");

			SetShopRootaByssKey(mRootaByssKey);

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = mRootaByssKey->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"rootabysskey"));

			mRootaByssKey->GetComponent<Transform>()->SetScale(Vector3(0.2f, 0.2f, 1.0001f));
		}
	}
	void HavisScript::CloseShop()
	{
		object::Destroy(mShop);
		object::Destroy(mShop2);
		object::Destroy(mShop3);
		object::Destroy(mShopHavis);
		object::Destroy(mShopPlayer);
		object::Destroy(mShopBuy);
		object::Destroy(mShopSell);
		object::Destroy(mShopExit);
		object::Destroy(mShopEtc);
		object::Destroy(mShopEtc2);
		object::Destroy(mRootaByssKey);
	}
	void HavisScript::stand()
	{

	}
}
