#include "yaEastGardenScene.h"
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
#include "yaPortalScript.h"
#include "yaFireImpScript.h"
#include "yaCurSorScript.h"

namespace My
{

}

ya::EastGardenScene::EastGardenScene()
{
}

ya::EastGardenScene::~EastGardenScene()
{
}

void ya::EastGardenScene::Initialize()
{
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);


	{
		GameObject* Mouse
			= object::Instantiate<GameObject>(Vector3(0.0f, 0.0f, 0.999f), eLayerType::Player);

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
			= object::Instantiate<GameObject>(Vector3(-4.5f, 6.0f, 0.999f), eLayerType::Player);

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
		GameObject* FireImp
			= object::Instantiate<GameObject>(Vector3(-6.0f, -0.7f, 0.998f), eLayerType::Monster);

		FireImp->SetName(L"FireImp");

		Collider2D* cd = FireImp->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(0.25f, 0.25f));

		MeshRenderer* mr = FireImp->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		//const float pi = 3.141592f;
		//float degree = pi / 8.0f;

		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		FireImp->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

		Animator* at = FireImp->AddComponent<Animator>();
		FireImpScript* mFireImpScript = FireImp->AddComponent<FireImpScript>();
		mFireImpScript->SetPlayerScript(mPlayerScript);
	}
	{
		GameObject* FireImp2
			= object::Instantiate<GameObject>(Vector3(-4.8f, -0.7f, 0.998f), eLayerType::Monster);

		FireImp2->SetName(L"FireImp");

		Collider2D* cd = FireImp2->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(0.25f, 0.25f));

		MeshRenderer* mr = FireImp2->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		//const float pi = 3.141592f;
		//float degree = pi / 8.0f;

		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		FireImp2->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

		Animator* at = FireImp2->AddComponent<Animator>();
		FireImpScript* mFireImpScript = FireImp2->AddComponent<FireImpScript>();
		mFireImpScript->SetPlayerScript(mPlayerScript);
	}
	{
		GameObject* FireImp3
			= object::Instantiate<GameObject>(Vector3(-3.6f, -0.7f, 0.998f), eLayerType::Monster);

		FireImp3->SetName(L"FireImp");

		Collider2D* cd = FireImp3->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(0.25f, 0.25f));

		MeshRenderer* mr = FireImp3->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		//const float pi = 3.141592f;
		//float degree = pi / 8.0f;

		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		FireImp3->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

		Animator* at = FireImp3->AddComponent<Animator>();
		FireImpScript* mFireImpScript = FireImp3->AddComponent<FireImpScript>();
		mFireImpScript->SetPlayerScript(mPlayerScript);
	}
	{
		GameObject* FireImp4
			= object::Instantiate<GameObject>(Vector3(-2.4f, -0.7f, 0.998f), eLayerType::Monster);

		FireImp4->SetName(L"FireImp");

		Collider2D* cd = FireImp4->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(0.25f, 0.25f));

		MeshRenderer* mr = FireImp4->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		//const float pi = 3.141592f;
		//float degree = pi / 8.0f;

		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		FireImp4->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

		Animator* at = FireImp4->AddComponent<Animator>();
		FireImpScript* mFireImpScript = FireImp4->AddComponent<FireImpScript>();
		mFireImpScript->SetPlayerScript(mPlayerScript);
	}
	{
		GameObject* FireImp5
			= object::Instantiate<GameObject>(Vector3(-1.2f, -0.7f, 0.998f), eLayerType::Monster);

		FireImp5->SetName(L"FireImp");

		Collider2D* cd = FireImp5->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(0.25f, 0.25f));

		MeshRenderer* mr = FireImp5->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		//const float pi = 3.141592f;
		//float degree = pi / 8.0f;

		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		FireImp5->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

		Animator* at = FireImp5->AddComponent<Animator>();
		FireImpScript* mFireImpScript = FireImp5->AddComponent<FireImpScript>();
		mFireImpScript->SetPlayerScript(mPlayerScript);
	}
	{
		GameObject* FireImp6
			= object::Instantiate<GameObject>(Vector3(0.0f, -0.7f, 0.998f), eLayerType::Monster);

		FireImp6->SetName(L"FireImp");

		Collider2D* cd = FireImp6->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(0.25f, 0.25f));

		MeshRenderer* mr = FireImp6->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		//const float pi = 3.141592f;
		//float degree = pi / 8.0f;

		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		FireImp6->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

		Animator* at = FireImp6->AddComponent<Animator>();
		FireImpScript* mFireImpScript = FireImp6->AddComponent<FireImpScript>();
		mFireImpScript->SetPlayerScript(mPlayerScript);
	}
	{
		GameObject* FireImp7
			= object::Instantiate<GameObject>(Vector3(1.2f, -0.7f, 0.998f), eLayerType::Monster);

		FireImp7->SetName(L"FireImp");

		Collider2D* cd = FireImp7->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(0.25f, 0.25f));

		MeshRenderer* mr = FireImp7->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		//const float pi = 3.141592f;
		//float degree = pi / 8.0f;

		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		FireImp7->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

		Animator* at = FireImp7->AddComponent<Animator>();
		FireImpScript* mFireImpScript = FireImp7->AddComponent<FireImpScript>();
		mFireImpScript->SetPlayerScript(mPlayerScript);
	}
	{
		GameObject* FireImp8
			= object::Instantiate<GameObject>(Vector3(2.4f, -0.7f, 0.998f), eLayerType::Monster);

		FireImp8->SetName(L"FireImp");

		Collider2D* cd = FireImp8->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(0.25f, 0.25f));

		MeshRenderer* mr = FireImp8->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		//const float pi = 3.141592f;
		//float degree = pi / 8.0f;

		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		FireImp8->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

		Animator* at = FireImp8->AddComponent<Animator>();
		FireImpScript* mFireImpScript = FireImp8->AddComponent<FireImpScript>();
		mFireImpScript->SetPlayerScript(mPlayerScript);
	}
	{
		GameObject* FireImp9
			= object::Instantiate<GameObject>(Vector3(3.6f, -0.7f, 0.998f), eLayerType::Monster);

		FireImp9->SetName(L"FireImp");

		Collider2D* cd = FireImp9->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(0.25f, 0.25f));

		MeshRenderer* mr = FireImp9->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		//const float pi = 3.141592f;
		//float degree = pi / 8.0f;

		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		FireImp9->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

		Animator* at = FireImp9->AddComponent<Animator>();
		FireImpScript* mFireImpScript = FireImp9->AddComponent<FireImpScript>();
		mFireImpScript->SetPlayerScript(mPlayerScript);
	}
	{
		GameObject* FireImp10
			= object::Instantiate<GameObject>(Vector3(4.8f, -0.7f, 0.998f), eLayerType::Monster);

		FireImp10->SetName(L"FireImp");

		Collider2D* cd = FireImp10->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(0.25f, 0.25f));

		MeshRenderer* mr = FireImp10->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		//const float pi = 3.141592f;
		//float degree = pi / 8.0f;

		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		FireImp10->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

		Animator* at = FireImp10->AddComponent<Animator>();
		FireImpScript* mFireImpScript = FireImp10->AddComponent<FireImpScript>();
		mFireImpScript->SetPlayerScript(mPlayerScript);
	}
	{
		GameObject* FireImp11
			= object::Instantiate<GameObject>(Vector3(6.0f, -0.7f, 0.998f), eLayerType::Monster);

		FireImp11->SetName(L"FireImp");

		Collider2D* cd = FireImp11->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(0.25f, 0.25f));

		MeshRenderer* mr = FireImp11->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		//const float pi = 3.141592f;
		//float degree = pi / 8.0f;

		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		FireImp11->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

		Animator* at = FireImp11->AddComponent<Animator>();
		FireImpScript* mFireImpScript = FireImp11->AddComponent<FireImpScript>();
		mFireImpScript->SetPlayerScript(mPlayerScript);
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
			= object::Instantiate<GameObject>(Vector3(-0.6f, -1.31f, 0.999f), eLayerType::Ground);

		Ground->SetName(L"Ground");

		Transform* groundTr = Ground->GetComponent<Transform>();
		groundTr->SetScale(Vector3(20.0f, 0.5f, 1.0f));

		Collider2D* cd = Ground->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, 0.0f));
		cd->SetSize(Vector2(1.0f, 1.0f));

	}
	{
		GameObject* EastGarden
			= object::Instantiate<GameObject>(Vector3(0.0f, 0.8f, 1.0001), eLayerType::BG);

		EastGarden->SetName(L"EastGarden");

		Camera::SetEastGardenScene(this);

		MeshRenderer* mr = EastGarden->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"EG"));


		EastGarden->GetComponent<Transform>()->SetScale(Vector3(17.0f, 5.0f, 1.0001f));
	}
	{
		GameObject* portal5
			= object::Instantiate<GameObject>(Vector3(-7.55f, -0.2f, 0.999f), eLayerType::Portal);

		portal5->SetName(L"Portal5");


		Collider2D* cd = portal5->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, -0.4f));
		cd->SetSize(Vector2(0.27f, 0.45f));

		MeshRenderer* mr = portal5->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		//const float pi = 3.141592f;
		//float degree = pi / 8.0f;

		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		portal5->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));

		Animator* at = portal5->AddComponent<Animator>();
		portal5->AddComponent<PortalScript>();
	}
	{
		GameObject* portal6
			= object::Instantiate<GameObject>(Vector3(7.67f, 0.12f, 0.999f), eLayerType::Portal);

		portal6->SetName(L"Portal6");


		Collider2D* cd = portal6->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, -0.4f));
		cd->SetSize(Vector2(0.27f, 0.45f));

		MeshRenderer* mr = portal6->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		//const float pi = 3.141592f;
		//float degree = pi / 8.0f;

		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		portal6->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));

		Animator* at = portal6->AddComponent<Animator>();
		portal6->AddComponent<PortalScript>();
	}

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
		//camera->AddComponent<CameraScript>();
	}
	Scene::Initialize();

}

void ya::EastGardenScene::Update()
{
	if (GetPlayerScript()->GetPortal())
	{
		if (Input::GetKeyDown(eKeyCode::UP))
			SceneManager::LoadScene(L"BanBanScene");
	}

	Scene::Update();
}

void ya::EastGardenScene::LateUpdate()
{
	Scene::LateUpdate();
}

void ya::EastGardenScene::Render()
{
	Scene::Render();
}
void ya::EastGardenScene::OnEnter()
{
	Camera::SetTarget(mPlayer);
	Camera::SetHeneSisScene(nullptr);
	Camera::SetRootaByssScene(nullptr);
	Camera::SetEastGardenScene(this);
	Scene::OnEnter();
}
void ya::EastGardenScene::OnExit()
{
	Scene::OnExit();
}
