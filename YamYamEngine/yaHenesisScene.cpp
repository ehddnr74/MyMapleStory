#include "yaHenesisScene.h"
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
#include "yaPlayerScript.h"
#include "yaCollisionManager.h"
#include "yaAnimator.h"
#include "yaMushroomScript.h"
#include "yaInput.h"
#include "yaSkillScript.h"

namespace ya
{
	HenesisScene::HenesisScene()
	{
	}
	HenesisScene::~HenesisScene()
	{
	}
	void HenesisScene::Initialize()
	{
		Camera::SetRootaByssScene(nullptr);
		Camera::SetEastGardenScene(nullptr);
		Camera::SetHeneSisScene(this);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);

		{
			GameObject* BG
				= object::Instantiate<GameObject>(Vector3(8.0f, 1.0f, 1.0f), eLayerType::BG);

			BG->SetName(L"Henesis");

			//Collider2D* cd = player->AddComponent<Collider2D>();
			//cd->SetSize(Vector2(1.2f, 1.2f));

			MeshRenderer* mr = BG->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"Hene"));

			//BG->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0f));
			BG->GetComponent<Transform>()->SetScale(Vector3(35.0f, 8.5f, 1.0f));
		}

		{
			GameObject* player
				= object::Instantiate<GameObject>(Vector3(0.0f, 6.0f, 0.999f), eLayerType::Player);

			Camera::SetTarget(player);
			//SceneManager::SetPlayer(player);

			player->SetName(L"Adel");

			Collider2D* cd = player->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.008f, 0.055f));
			cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = player->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			player->GetComponent<Transform>()->SetScale(Vector3(1.6f, 1.6f, 1.0001f));

			Animator* at = player->AddComponent<Animator>();
			PlayerScript* mScript = player->AddComponent<PlayerScript>();

			//player->GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, degree));

			//Animator* at = player->AddComponent<Animator>();
		}

		{
			GameObject* Ground
				= object::Instantiate<GameObject>(Vector3(-0.6f, -1.0f, 0.998f), eLayerType::Ground);

			Ground->SetName(L"Ground");

			Transform* groundTr = Ground->GetComponent<Transform>();
			groundTr->SetScale(Vector3(20.0f, 0.5f, 1.0f));

			Collider2D* cd = Ground->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, 0.0f));
			cd->SetSize(Vector2(1.0f, 1.0f));

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

			EXP->GetComponent<Transform>()->SetScale(Vector3(8.0f, 0.08f, 1.0009f));

			SetEXP(EXP);
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

			HP->GetComponent<Transform>()->SetScale(Vector3(1.1f, 0.5f, 1.0007f));

			SetHP(HP);
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

			SlotCover->GetComponent<Transform>()->SetScale(Vector3(3.5f, 0.5f, 1.0008f));

			SetSlotCover(SlotCover);
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

			Slot->GetComponent<Transform>()->SetScale(Vector3(3.48f, 0.48f, 1.001f));

			SetSlot(Slot);
		}

		{
			GameObject* MushRoom
				= object::Instantiate<GameObject>(Vector3(-0.6f, -0.5f, 0.998f), eLayerType::Monster);

			MushRoom->SetName(L"MushRoom");

			Collider2D* cd = MushRoom->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, 0.0f));
			cd->SetSize(Vector2(0.25f, 0.25f));

			MeshRenderer* mr = MushRoom->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

			//const float pi = 3.141592f;
			//float degree = pi / 8.0f;

			//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
			MushRoom->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

			Animator* at = MushRoom->AddComponent<Animator>();
			MushRoom->AddComponent<MushroomScript>();
			//player->GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, degree));

			//std::shared_ptr<Texture> atlas
				//= Resources::Load<Texture>(L"Character1", L"..\\Resources\\Texture\\Character1.png");

			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Idle", atlas, Vector2(0.0f, 0.0f), Vector2(160.0f, 160.0f), 3, Vector2(0.f,0.f), 0.5f);

			//at->CompleteEvent(L"Idle") = std::bind();

			//at->PlayAnimation(L"Idle", true);
		}

		//{
		//	GameObject* light = new GameObject();
		//	light->SetName(L"Henesis");
		//	AddGameObject(eLayerType::Light, light);
		//	Light* lightComp = light->AddComponent<Light>();
		//	lightComp->SetType(eLightType::Point);
		//	lightComp->SetColor(Vector4(1.0f, 1.0f, 1.0f, 1.0f));
		//}

		//{
		//	GameObject* light = new GameObject();
		//	light->SetName(L"Adel");
		//	AddGameObject(eLayerType::Light, light);
		//	Light* lightComp = light->AddComponent<Light>();
		//	lightComp->SetType(eLightType::Directional);
		//	lightComp->SetColor(Vector4(1.0f, 1.0f, 1.0f, 1.0f));
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

			//camera->AddComponent<AudioListener>();
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

	void HenesisScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(L"RootaByssScene");
		}
		Scene::Update();
	}

	void HenesisScene::LateUpdate()
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

	void HenesisScene::Render()
	{
		Scene::Render();
	}
	void HenesisScene::OnEnter()
	{
		Scene::OnEnter();
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	}
	void HenesisScene::OnExit()
	{

		Scene::OnExit();

	}
}