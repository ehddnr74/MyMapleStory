#include "yaBanBanScene.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaMesh.h"
#include "yaCameraScript.h"
#include "yaCamera.h"
#include "yaSceneManager.h"
#include "yaGridScript.h"
#include "yaObject.h"
#include "yaRenderer.h"
#include "yaCollider2D.h"
#include "yaCollisionManager.h"
#include "yaAnimator.h"
#include "yaInput.h"
#include "yaPlayerScript.h"
#include "yaBanBanScript.h"
#include "yaCurSorScript.h"
#include "yaHpScript.h"
#include "yaMpScript.h"
#include "yaExpScript.h"

namespace ya
{

}

ya::BanBanScene::BanBanScene()
{
}

ya::BanBanScene::~BanBanScene()
{
}

void ya::BanBanScene::Initialize()
{
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);

	{
		GameObject* Mouse
			= object::Instantiate<GameObject>(Vector3(0.0f, 0.0f, 0.999f), eLayerType::Cursor);

		Mouse->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 1.0001f));

		Mouse->SetName(L"Cursor");

		Collider2D* cd = Mouse->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));

		cd->SetSize(Vector2(0.1f, 0.1f));

		MeshRenderer* mr = Mouse->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		Mouse->AddComponent<CurSorScript>();
	}

	{
		GameObject* player
			= object::Instantiate<GameObject>(Vector3(-1.0f, 6.0f, 0.999f), eLayerType::Player);

		SetPlayer(player);

		Camera::SetTarget(player);
		//SceneManager::SetPlayer(player);

		player->SetName(L"Adel");

		Collider2D* cd = player->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.008f, 0.055f));
		cd->SetSize(Vector2(0.22f, 0.38f));

		MeshRenderer* mr = player->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		//const float pi = 3.141592f;
		//float degree = pi / 8.0f;

		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		player->GetComponent<Transform>()->SetScale(Vector3(1.6f, 1.6f, 1.0001f));

		Animator* at = player->AddComponent<Animator>();
		PlayerScript* mPlayerScript = player->AddComponent<PlayerScript>();
		SetPlayerScript(mPlayerScript);
		//player->GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, degree));

		//std::shared_ptr<Texture> atlas
			//= Resources::Load<Texture>(L"Character1", L"..\\Resources\\Texture\\Character1.png");

		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Idle", atlas, Vector2(0.0f, 0.0f), Vector2(160.0f, 160.0f), 3, Vector2(0.f,0.f), 0.5f);

		//at->CompleteEvent(L"Idle") = std::bind();

		//at->PlayAnimation(L"Idle", true);
	}

	{
		GameObject* BanBan
			= object::Instantiate<GameObject>(Vector3(0.5f, 0.2f, 0.999f), eLayerType::Monster);

		BanBan->SetName(L"BanBan");

		Collider2D* cd = BanBan->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(0.22f, 0.38f));

		MeshRenderer* mr = BanBan->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));


		BanBan->GetComponent<Transform>()->SetScale(Vector3(4.0f, 4.0f, 1.0001f));

		Animator* at = BanBan->AddComponent<Animator>();
		BanBanScript* mBanBanScript = BanBan->AddComponent<BanBanScript>();
		mBanBanScript->SetPlayerScript(mPlayerScript);

	}
	{
		GameObject* EXP
			= object::Instantiate<GameObject>(Vector3(0.0f, -2.21f, 0.999f), eLayerType::UI);

		EXP->SetName(L"EXP");

		//Collider2D* cd = player->AddComponent<Collider2D>();
		//cd->SetSize(Vector2(1.2f, 1.2f));

		MeshRenderer* mr = EXP->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"EXP"));

		EXP->GetComponent<Transform>()->SetScale(Vector3(8.0f, 0.08f, 0.999f));

		//SetEXP(EXP);
	}

	{
		GameObject* HP
			= object::Instantiate<GameObject>(Vector3(-0.1f, -1.95f, 0.999f), eLayerType::UI);

		HP->SetName(L"HP");

		//Collider2D* cd = player->AddComponent<Collider2D>();
		//cd->SetSize(Vector2(1.2f, 1.2f));

		MeshRenderer* mr = HP->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"HP"));

		HP->GetComponent<Transform>()->SetScale(Vector3(1.1f, 0.5f, 0.999f));

		//SetHP(HP);
	}

	{
		GameObject* HpFrontBar
			= object::Instantiate<GameObject>(Vector3(-0.06f, -1.95f, 1.000f), eLayerType::UI);

		HpFrontBar->SetName(L"HpFrontBar");

		//Collider2D* cd = player->AddComponent<Collider2D>();
		//cd->SetSize(Vector2(1.2f, 1.2f));

		MeshRenderer* mr = HpFrontBar->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"HpFront"));

		HpFrontBar->GetComponent<Transform>()->SetScale(Vector3(0.92f, 0.1f, 1.000f));

		mHpScript = HpFrontBar->AddComponent<HpScript>();

		GetPlayerScript()->SetHpScript(mHpScript);

	}

	{
		GameObject* MpFrontBar
			= object::Instantiate<GameObject>(Vector3(-0.06f, -2.05f, 1.000f), eLayerType::UI);

		MpFrontBar->SetName(L"HpFrontBar");

		//Collider2D* cd = player->AddComponent<Collider2D>();
		//cd->SetSize(Vector2(1.2f, 1.2f));

		MeshRenderer* mr = MpFrontBar->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"MpFront"));

		MpFrontBar->GetComponent<Transform>()->SetScale(Vector3(0.92f, 0.1f, 1.000f));

		mMpScript = MpFrontBar->AddComponent<MpScript>();

		GetPlayerScript()->SetMpScript(mMpScript);
	}

	{
		GameObject* ExpFrontBar
			= object::Instantiate<GameObject>(Vector3(-4.0f, -2.21f, 1.001f), eLayerType::UI);

		ExpFrontBar->SetName(L"ExpFrontBar");

		//Collider2D* cd = player->AddComponent<Collider2D>();
		//cd->SetSize(Vector2(1.2f, 1.2f));

		MeshRenderer* mr = ExpFrontBar->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"ExpFront"));

		ExpFrontBar->GetComponent<Transform>()->SetScale(Vector3(0.0f, 0.05f, 1.000f));

		mExpScript = ExpFrontBar->AddComponent<ExpScript>();

		GetPlayerScript()->SetExpScript(mExpScript);
	}

	{
		GameObject* SlotCover
			= object::Instantiate<GameObject>(Vector3(2.25f, -1.93f, 0.999f), eLayerType::UI);

		SlotCover->SetName(L"SlotCover");

		//Collider2D* cd = player->AddComponent<Collider2D>();
		//cd->SetSize(Vector2(1.2f, 1.2f));

		MeshRenderer* mr = SlotCover->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SlotCover"));

		SlotCover->GetComponent<Transform>()->SetScale(Vector3(3.5f, 0.5f, 0.999f));

		//SetSlotCover(SlotCover);
	}
	{
		GameObject* Slot
			= object::Instantiate<GameObject>(Vector3(2.25f, -1.93f, 0.999f), eLayerType::UI);

		Slot->SetName(L"Slot");

		//Collider2D* cd = player->AddComponent<Collider2D>();
		//cd->SetSize(Vector2(1.2f, 1.2f));

		MeshRenderer* mr = Slot->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"Slot"));

		Slot->GetComponent<Transform>()->SetScale(Vector3(3.48f, 0.48f, 0.999f));

		//SetSlot(Slot);
	}
	{
		GameObject* Ground
			= object::Instantiate<GameObject>(Vector3(-0.6f, -1.6f, 0.999f), eLayerType::Ground);

		Ground->SetName(L"Ground");

		Transform* groundTr = Ground->GetComponent<Transform>();
		groundTr->SetScale(Vector3(20.0f, 0.5f, 1.0f));

		Collider2D* cd = Ground->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(1.0f, 1.0f));

	}
	{
		GameObject* BanBanBG
			= object::Instantiate<GameObject>(Vector3(0.0f, 0.8f, 1.0001), eLayerType::BG);

		BanBanBG->SetName(L"BanBanBG");

		Camera::SetBanBanScene(this);

		MeshRenderer* mr = BanBanBG->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"BanBan"));


		BanBanBG->GetComponent<Transform>()->SetScale(Vector3(10.5f, 5.0f, 1.0001f));
	}

	//{
	//	GameObject* BanBanPortal
	//		= object::Instantiate<GameObject>(Vector3(0.5f, 0.0f, 0.999f), eLayerType::Portal);

	//	BanBanPortal->SetName(L"BanBanPortal");

	//	MeshRenderer* mr = BanBanPortal->AddComponent<MeshRenderer>();
	//	mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
	//	mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

	//	std::shared_ptr<Texture> BanBan
	//		= Resources::Load<Texture>(L"BanBanPortal", L"..\\Resources\\Texture\\BanBanPortal.png");

	//	Animator* at = BanBanPortal->AddComponent<Animator>();
	//	at->Create(L"BanBanPortal", BanBan, Vector2(0.0f, 0.0f), Vector2(129.0f, 178.0f), 14, Vector2::Zero, 0.1f);

	//	at->PlayAnimation(L"BanBanPortal", true);

	//	BanBanPortal->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));
	//}

	//Main Camera
	Camera* cameraComp = nullptr;
	{
		GameObject* camera = new GameObject();
		AddGameObject(eLayerType::Player, camera);
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		cameraComp = camera->AddComponent<Camera>();
		cameraComp->TurnLayerMask(eLayerType::UI, false);
		camera->AddComponent<CameraScript>();
		renderer::cameras.push_back(cameraComp);
		renderer::mainCamera = cameraComp;
	}
	//UI Camera
	{
		GameObject* camera = new GameObject();
		AddGameObject(eLayerType::Player, camera);
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		cameraComp->TurnLayerMask(eLayerType::BG, false);
		cameraComp->TurnLayerMask(eLayerType::Player, false);
		cameraComp->TurnLayerMask(eLayerType::Monster, false);
		cameraComp->TurnLayerMask(eLayerType::Skill, false);
		cameraComp->TurnLayerMask(eLayerType::Portal, false);
		cameraComp->TurnLayerMask(eLayerType::Cursor, false);
		//camera->AddComponent<CameraScript>();
	}
	Scene::Initialize();

}

void ya::BanBanScene::Update()
{
	Scene::Update();
}

void ya::BanBanScene::LateUpdate()
{
	Scene::LateUpdate();
}

void ya::BanBanScene::Render()
{
	Scene::Render();
}

void ya::BanBanScene::OnEnter()
{
	Camera::SetTarget(mPlayer);
	Camera::SetHeneSisScene(nullptr);
	Camera::SetRootaByssScene(nullptr);
	Camera::SetEastGardenScene(nullptr);
	Camera::SetBanBanScene(this);
	Scene::OnEnter();
}

void ya::BanBanScene::OnExit()
{
	Scene::OnExit();
}
