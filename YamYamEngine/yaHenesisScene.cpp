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
#include "yaSavePlayer.h"
#include "yaHpScript.h"
#include "yaMpScript.h"
#include "yaExpScript.h"
#include "yaCurSorScript.h"
#include "yaInventoryScript.h"

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
			GameObject* Cursor = new GameObject();
			Cursor->SetName(L"Cursor");
			AddGameObject(eLayerType::Cursor, Cursor);

			Collider2D* cd = Cursor->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(-0.06f, 0.08f));
			cd->SetSize(Vector2(0.05f, 0.025f));

			MeshRenderer* mr = Cursor->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
			Cursor->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.999f));
			Cursor->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 0.999f));
			CurSorScript* mCursorScript = Cursor->AddComponent<CurSorScript>();
			SceneManager::SetCursorScript(mCursorScript);
			object::DontDestroyOnLoad(Cursor);
		}


		{
			GameObject* BG
				= object::Instantiate<GameObject>(Vector3(8.0f, 1.0f, 1.001f), eLayerType::BG);

			BG->SetName(L"Henesis");

			MeshRenderer* mr = BG->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"Hene"));

			BG->GetComponent<Transform>()->SetScale(Vector3(35.0f, 8.5f, 1.0f));
		}

		{
			GameObject* player = new GameObject();
			player->SetName(L"Adel");
			AddGameObject(eLayerType::Player, player);
			MeshRenderer* mr = player->AddComponent<MeshRenderer>();

			Camera::SetTarget(player);

			Collider2D* cd = player->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.008f, 0.065f));
			cd->SetSize(Vector2(0.18f, 0.28f));

		    mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		    mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
			player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.999f));
			player->GetComponent<Transform>()->SetScale(Vector3(1.6f, 1.6f, 0.999f));
			PlayerScript* mPlayerScript = player->AddComponent<PlayerScript>();
			SceneManager::SetPlayer(player);
			SceneManager::SetPlayerScript(mPlayerScript);
			InventoryScript* mInventoryScript = player->AddComponent<InventoryScript>();
			SceneManager::SetInventoryScript(mInventoryScript);
			object::DontDestroyOnLoad(player);
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
			GameObject* Exp = new GameObject();
			Exp->SetName(L"EXP");
			AddGameObject(eLayerType::UI, Exp);

			MeshRenderer* mr = Exp->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"EXP"));

			Exp->GetComponent<Transform>()->SetPosition(Vector3(0.0f, -2.21f, 0.999f));
			Exp->GetComponent<Transform>()->SetScale(Vector3(8.0f, 0.08f, 1.0009f));
			object::DontDestroyOnLoad(Exp);
		}

		{
			GameObject* ExpFrontBar = new GameObject();
			ExpFrontBar->SetName(L"ExpFrontBar");
			AddGameObject(eLayerType::UI, ExpFrontBar);

			MeshRenderer* mr = ExpFrontBar->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"ExpFront"));

			ExpFrontBar->GetComponent<Transform>()->SetPosition(Vector3(-4.0f, -2.21f, 1.000f));
			ExpFrontBar->GetComponent<Transform>()->SetScale(Vector3(0.0f, 0.05f, 1.000f));
			ExpScript* mExpScript = ExpFrontBar->AddComponent<ExpScript>();
			SceneManager::SetExpScript(mExpScript);
			object::DontDestroyOnLoad(ExpFrontBar);
		}

		{
			GameObject* HP = new GameObject();
			HP->SetName(L"HP");
			AddGameObject(eLayerType::UI, HP);

			MeshRenderer* mr = HP->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"HP"));

			HP->GetComponent<Transform>()->SetPosition(Vector3(-0.15f, -1.95f, 0.999f));
			HP->GetComponent<Transform>()->SetScale(Vector3(1.18f, 0.5f, 1.0007f));
			object::DontDestroyOnLoad(HP);
		}

		{
			GameObject* HPFrontBar = new GameObject();
			HPFrontBar->SetName(L"HPFrontBar");
			AddGameObject(eLayerType::UI, HPFrontBar);

			MeshRenderer* mr = HPFrontBar->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"HpFront"));

			HPFrontBar->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -1.95f, 1.000f));
			HPFrontBar->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));
			HpScript* mHpScript = HPFrontBar->AddComponent<HpScript>();
			SceneManager::SetHpScript(mHpScript);
			object::DontDestroyOnLoad(HPFrontBar);
		}

		{
			GameObject* MpFrontBar = new GameObject();
			MpFrontBar->SetName(L"MpFrontBar");
			AddGameObject(eLayerType::UI, MpFrontBar);

			MeshRenderer* mr = MpFrontBar->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"MpFront"));

			MpFrontBar->GetComponent<Transform>()->SetPosition(Vector3(-0.11f, -2.05f, 1.000f));
			MpFrontBar->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));
			MpScript* mMpScript = MpFrontBar->AddComponent<MpScript>();
			SceneManager::SetMpScript(mMpScript);
			object::DontDestroyOnLoad(MpFrontBar);
		}

		{
			GameObject* SlotCover = new GameObject();
			SlotCover->SetName(L"SlotCover");
			AddGameObject(eLayerType::UI, SlotCover);

			MeshRenderer* mr = SlotCover->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SlotCover"));

			SlotCover->GetComponent<Transform>()->SetPosition(Vector3(2.25f, -1.93f, 0.998f));
			SlotCover->GetComponent<Transform>()->SetScale(Vector3(3.5f, 0.5f, 1.0008f));
			object::DontDestroyOnLoad(SlotCover);
		}

		{
			GameObject* Slot = new GameObject();
			Slot->SetName(L"Slot");
			AddGameObject(eLayerType::UI, Slot);

			MeshRenderer* mr = Slot->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"Slot"));

			Slot->GetComponent<Transform>()->SetPosition(Vector3(2.25f, -1.93f, 0.999f));
			Slot->GetComponent<Transform>()->SetScale(Vector3(3.48f, 0.48f, 1.001f));
			object::DontDestroyOnLoad(Slot);
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

			MushRoom->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

			Animator* at = MushRoom->AddComponent<Animator>();
			MushRoom->AddComponent<MushroomScript>();

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
			cameraComp->TurnLayerMask(eLayerType::Cursor, false);
			cameraComp->TurnLayerMask(eLayerType::Inventory, false);
			//camera->AddComponent<CameraScript>();
		}
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
	}
	void HenesisScene::OnExit()
	{

		Scene::OnExit();

	}
}