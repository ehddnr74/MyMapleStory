#include "yaRootaByssScene.h"
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
#include "yaCurSorScript.h"

namespace ya
{
	RootaByssScene::RootaByssScene()
	{
	}
	RootaByssScene::~RootaByssScene()
	{
	}
	void RootaByssScene::Initialize()
	{

		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);
		CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::Portal, true);


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
			GameObject* portal
				= object::Instantiate<GameObject>(Vector3(-3.2f, -0.75f, 0.999f), eLayerType::Portal);

			portal->SetName(L"Portal");

			Collider2D* cd = portal->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, -0.4f));
			cd->SetSize(Vector2(0.27f, 0.45f));

			MeshRenderer* mr = portal->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			//const float pi = 3.141592f;
			//float degree = pi / 8.0f;

			//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
			portal->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));

			Animator* at = portal->AddComponent<Animator>();
			portal->AddComponent<PortalScript>();
		}



		{
			GameObject* portal2
				= object::Instantiate<GameObject>(Vector3(-0.88f, -0.75f, 0.999f), eLayerType::Portal);

			portal2->SetName(L"Portal2");


			Collider2D* cd = portal2->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, -0.4f));
			cd->SetSize(Vector2(0.27f, 0.45f));

			MeshRenderer* mr = portal2->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			//const float pi = 3.141592f;
			//float degree = pi / 8.0f;

			//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
			portal2->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));

			Animator* at = portal2->AddComponent<Animator>();
			portal2->AddComponent<PortalScript>();
		}

		{
			GameObject* portal3
				= object::Instantiate<GameObject>(Vector3(1.61f, -0.75f, 0.999f), eLayerType::Portal);

			portal3->SetName(L"Portal3");


			Collider2D* cd = portal3->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, -0.4f));
			cd->SetSize(Vector2(0.27f, 0.45f));

			MeshRenderer* mr = portal3->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			//const float pi = 3.141592f;
			//float degree = pi / 8.0f;

			//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
			portal3->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));

			Animator* at = portal3->AddComponent<Animator>();
			portal3->AddComponent<PortalScript>();
		}

		{
			GameObject* portal4
				= object::Instantiate<GameObject>(Vector3(3.92f, -0.75f, 0.999f), eLayerType::Portal);

			portal4->SetName(L"Portal4");


			Collider2D* cd = portal4->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, -0.4f));
			cd->SetSize(Vector2(0.27f, 0.45f));

			MeshRenderer* mr = portal4->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			//const float pi = 3.141592f;
			//float degree = pi / 8.0f;

			//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
			portal4->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));

			Animator* at = portal4->AddComponent<Animator>();
			portal4->AddComponent<PortalScript>();
		}


		{
			GameObject* player
				= object::Instantiate<GameObject>(Vector3(0.0f, 6.0f, 0.999f), eLayerType::Player);

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
			PlayerScript* mPScript = player->AddComponent<PlayerScript>();
			SetPlayerScript(mPScript);
			//player->GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, degree));

			//std::shared_ptr<Texture> atlas
				//= Resources::Load<Texture>(L"Character1", L"..\\Resources\\Texture\\Character1.png");

			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Idle", atlas, Vector2(0.0f, 0.0f), Vector2(160.0f, 160.0f), 3, Vector2(0.f,0.f), 0.5f);

			//at->CompleteEvent(L"Idle") = std::bind();

			//at->PlayAnimation(L"Idle", true);
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
				= object::Instantiate<GameObject>(Vector3(-0.6f, -1.8f, 0.999f), eLayerType::Ground);

			Ground->SetName(L"Ground");

			Transform* groundTr = Ground->GetComponent<Transform>();
			groundTr->SetScale(Vector3(20.0f, 0.5f, 1.0f));

			Collider2D* cd = Ground->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, 0.0f));
			cd->SetSize(Vector2(1.0f, 1.0f));

		}

		{
			GameObject* RootaByss
				= object::Instantiate<GameObject>(Vector3(0.0f, 0.8f, 1.0001), eLayerType::BG);

			Camera::SetRootaByssScene(this);

			RootaByss->SetName(L"RootaByss");

			MeshRenderer* mr = RootaByss->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"Roota"));


			RootaByss->GetComponent<Transform>()->SetScale(Vector3(12.0f, 6.0f, 1.0001f));
		}

		{
			GameObject* Fire1
				= object::Instantiate<GameObject>(Vector3(-3.82f, -0.3f, 0.999f), eLayerType::Player);

			Fire1->SetName(L"Fire1");

			MeshRenderer* mr = Fire1->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			std::shared_ptr<Texture> FireSprite
				= Resources::Load<Texture>(L"Fire1", L"..\\Resources\\Texture\\Fire1.png");

			Animator* at = Fire1->AddComponent<Animator>();
			at->Create(L"Fire1", FireSprite, Vector2(0.0f, 0.0f), Vector2(59.0f, 84.0f), 6, Vector2::Zero, 0.1f);

			at->PlayAnimation(L"Fire1", true);

			Fire1->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 0.999f));
		}

		{
			GameObject* Fire1
				= object::Instantiate<GameObject>(Vector3(-2.6f, -0.3f, 0.999f), eLayerType::Player);

			Fire1->SetName(L"Fire1");

			MeshRenderer* mr = Fire1->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			std::shared_ptr<Texture> FireSprite
				= Resources::Load<Texture>(L"Fire1", L"..\\Resources\\Texture\\Fire1.png");

			Animator* at = Fire1->AddComponent<Animator>();
			at->Create(L"Fire1", FireSprite, Vector2(0.0f, 0.0f), Vector2(59.0f, 84.0f), 6, Vector2::Zero, 0.1f);

			at->PlayAnimation(L"Fire1", true);

			Fire1->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 0.999f));
		}

		{
			GameObject* Fire2
				= object::Instantiate<GameObject>(Vector3(-1.47f, -0.5f, 0.999f), eLayerType::Player);

			Fire2->SetName(L"Fire2");

			MeshRenderer* mr = Fire2->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			std::shared_ptr<Texture> FireSprite
				= Resources::Load<Texture>(L"Fire2", L"..\\Resources\\Texture\\Fire2.png");

			Animator* at = Fire2->AddComponent<Animator>();
			at->Create(L"Fire2", FireSprite, Vector2(0.0f, 0.0f), Vector2(53.0f, 77.0f), 6, Vector2::Zero, 0.1f);

			at->PlayAnimation(L"Fire2", true);

			Fire2->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 0.999f));
		}

		{
			GameObject* Fire2
				= object::Instantiate<GameObject>(Vector3(-0.38f, -0.5f, 0.999f), eLayerType::Player);

			Fire2->SetName(L"Fire2");

			MeshRenderer* mr = Fire2->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			std::shared_ptr<Texture> FireSprite
				= Resources::Load<Texture>(L"Fire2", L"..\\Resources\\Texture\\Fire2.png");

			Animator* at = Fire2->AddComponent<Animator>();
			at->Create(L"Fire2", FireSprite, Vector2(0.0f, 0.0f), Vector2(53.0f, 77.0f), 6, Vector2::Zero, 0.1f);

			at->PlayAnimation(L"Fire2", true);

			Fire2->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 0.999f));
		}

		{
			GameObject* Fire3
				= object::Instantiate<GameObject>(Vector3(1.1f, -0.5f, 0.999f), eLayerType::Player);

			Fire3->SetName(L"Fire3");

			MeshRenderer* mr = Fire3->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			std::shared_ptr<Texture> FireSprite
				= Resources::Load<Texture>(L"Fire3", L"..\\Resources\\Texture\\Fire3.png");

			Animator* at = Fire3->AddComponent<Animator>();
			at->Create(L"Fire3", FireSprite, Vector2(0.0f, 0.0f), Vector2(53.0f, 77.0f), 6, Vector2::Zero, 0.1f);

			at->PlayAnimation(L"Fire3", true);

			Fire3->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 0.999f));
		}

		{
			GameObject* Fire3
				= object::Instantiate<GameObject>(Vector3(2.2f, -0.5f, 0.999f), eLayerType::Player);

			Fire3->SetName(L"Fire3");

			MeshRenderer* mr = Fire3->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			std::shared_ptr<Texture> FireSprite
				= Resources::Load<Texture>(L"Fire3", L"..\\Resources\\Texture\\Fire3.png");

			Animator* at = Fire3->AddComponent<Animator>();
			at->Create(L"Fire3", FireSprite, Vector2(0.0f, 0.0f), Vector2(53.0f, 77.0f), 6, Vector2::Zero, 0.1f);

			at->PlayAnimation(L"Fire3", true);

			Fire3->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 0.999f));
		}

		{
			GameObject* Fire4
				= object::Instantiate<GameObject>(Vector3(3.37f, -0.3f, 0.999f), eLayerType::Player);

			Fire4->SetName(L"Fire4");

			MeshRenderer* mr = Fire4->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			std::shared_ptr<Texture> FireSprite
				= Resources::Load<Texture>(L"Fire4", L"..\\Resources\\Texture\\Fire4.png");

			Animator* at = Fire4->AddComponent<Animator>();
			at->Create(L"Fire4", FireSprite, Vector2(0.0f, 0.0f), Vector2(59.0f, 77.0f), 6, Vector2::Zero, 0.1f);

			at->PlayAnimation(L"Fire4", true);

			Fire4->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 0.999f));
		}

		{
			GameObject* RootaByssGate1
				= object::Instantiate<GameObject>(Vector3(5.2f, -0.95f, 0.999f), eLayerType::Portal);

			RootaByssGate1->SetName(L"RootaByssGate1");

			MeshRenderer* mr = RootaByssGate1->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			std::shared_ptr<Texture> RootaByssGateSprite
				= Resources::Load<Texture>(L"RootaByssGate1", L"..\\Resources\\Texture\\RootaByssGate.png");

			Animator* at = RootaByssGate1->AddComponent<Animator>();
			at->Create(L"RootaByssGate1", RootaByssGateSprite, Vector2(0.0f, 0.0f), Vector2(94.0f, 133.0f), 14, Vector2::Zero, 0.1f);

			at->PlayAnimation(L"RootaByssGate1", true);

			RootaByssGate1->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));
		}


		{
			GameObject* RootaByssGate2
				= object::Instantiate<GameObject>(Vector3(-4.63f, -0.95f, 0.999f), eLayerType::Portal);

			RootaByssGate2->SetName(L"RootaByssGate2");

			MeshRenderer* mr = RootaByssGate2->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			std::shared_ptr<Texture> RootaByssGateSprite
				= Resources::Load<Texture>(L"RootaByssGate2", L"..\\Resources\\Texture\\RightRootaByssGate.png");

			Animator* at = RootaByssGate2->AddComponent<Animator>();
			at->Create(L"RootaByssGate2", RootaByssGateSprite, Vector2(0.0f, 0.0f), Vector2(94.0f, 133.0f), 14, Vector2::Zero, 0.1f);

			at->PlayAnimation(L"RootaByssGate2", true);

			RootaByssGate2->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 0.999f));
		}

		{
			GameObject* Fire4
				= object::Instantiate<GameObject>(Vector3(4.58f, -0.3f, 0.999f), eLayerType::Player);

			Fire4->SetName(L"Fire4");

			MeshRenderer* mr = Fire4->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			std::shared_ptr<Texture> FireSprite
				= Resources::Load<Texture>(L"Fire4", L"..\\Resources\\Texture\\Fire4.png");

			Animator* at = Fire4->AddComponent<Animator>();
			at->Create(L"Fire4", FireSprite, Vector2(0.0f, 0.0f), Vector2(59.0f, 77.0f), 6, Vector2::Zero, 0.1f);

			at->PlayAnimation(L"Fire4", true);

			Fire4->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 0.999f));
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
			cameraComp->TurnLayerMask(eLayerType::Cursor, false);
			//camera->AddComponent<CameraScript>();
		}

		//{
		//	GameObject* grid = new GameObject();
		//	grid->SetName(L"Grid");
		//	AddGameObject(eLayerType::Grid, grid);
		//	MeshRenderer* mr = grid->AddComponent<MeshRenderer>();
		//	mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//	mr->SetMaterial(Resources::Find<Material>(L"GridMaterial"));
		//	GridScript* gridSc = grid->AddComponent<GridScript>();
		//	gridSc->SetCamera(cameraComp);
		//}


		//GameObject* player2 = new GameObject();
		//AddGameObject(eLayerType::Player, player2);
		//player2->AddComponent<MeshRenderer>();

		//Transform* tr = player->GetComponent<Transform>();
		//tr->SetPosition(Vector3(0.5f, 0.5f, 0.0f));
		Scene::Initialize();

	}
	void RootaByssScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(L"LoadScene");
		}

		if (GetPlayerScript()->GetPortal())
		{
			if (Input::GetKeyDown(eKeyCode::UP))
				SceneManager::LoadScene(L"EastGardenScene");
		}


		Scene::Update();
	}
	void RootaByssScene::LateUpdate()
	{
		Vector3 pos(800, 450, 0.0f);
		Vector3 pos2(800, 450, 1000.0f);
		Viewport viewport;
		viewport.width = 1600.0f;
		viewport.height = 900.0f;
		viewport.x = 0;
		viewport.y = 0;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		pos = viewport.Unproject(pos, Camera::GetGpuProjectionMatrix(), Camera::GetGpuViewMatrix(), Matrix::Identity);
		pos2 = viewport.Unproject(pos2, Camera::GetGpuProjectionMatrix(), Camera::GetGpuViewMatrix(), Matrix::Identity);

		Scene::LateUpdate();
	}
	void RootaByssScene::Render()
	{
		Scene::Render();
	}
	void RootaByssScene::OnEnter()
	{
		Camera::SetTarget(mPlayer);
		Camera::SetHeneSisScene(nullptr);
		Camera::SetEastGardenScene(nullptr);
		Camera::SetRootaByssScene(this);
		Scene::OnEnter();
	}
	void RootaByssScene::OnExit()
	{
		Scene::OnExit();
	}
}