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
#include "yaHpScript.h"
#include "yaAudioListener.h"
#include "yaAudioClip.h"
#include "yaAudioSource.h"

namespace ya
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
		GameObject* FireImp
			= object::Instantiate<GameObject>(Vector3(-6.0f, -0.7f, 0.998f), eLayerType::Monster);

		FireImp->SetName(L"FireImp1");

		//Collider2D* cd = FireImp->AddComponent<Collider2D>();
		//cd->SetCenter(Vector2(0.0f, 0.0f));
		//cd->SetSize(Vector2(0.25f, 0.25f));

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
	//{
	//	GameObject* FireImp2
	//		= object::Instantiate<GameObject>(Vector3(-4.8f, -0.7f, 0.998f), eLayerType::Monster);

	//	FireImp2->SetName(L"FireImp2");

	//	//Collider2D* cd = FireImp2->AddComponent<Collider2D>();
	//	//cd->SetCenter(Vector2(0.0f, 0.0f));
	//	//cd->SetSize(Vector2(0.25f, 0.25f));

	//	MeshRenderer* mr = FireImp2->AddComponent<MeshRenderer>();
	//	mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
	//	mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

	//	//const float pi = 3.141592f;
	//	//float degree = pi / 8.0f;

	//	//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
	//	FireImp2->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

	//	Animator* at = FireImp2->AddComponent<Animator>();
	//	FireImpScript* mFireImpScript = FireImp2->AddComponent<FireImpScript>();
	//	mFireImpScript->SetPlayerScript(mPlayerScript);
	//}
	//{
	//	GameObject* FireImp3
	//		= object::Instantiate<GameObject>(Vector3(-3.6f, -0.7f, 0.998f), eLayerType::Monster);

	//	FireImp3->SetName(L"FireImp3");

	//	//Collider2D* cd = FireImp3->AddComponent<Collider2D>();
	//	//cd->SetCenter(Vector2(0.0f, 0.0f));
	//	//cd->SetSize(Vector2(0.25f, 0.25f));

	//	MeshRenderer* mr = FireImp3->AddComponent<MeshRenderer>();
	//	mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
	//	mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

	//	//const float pi = 3.141592f;
	//	//float degree = pi / 8.0f;

	//	//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
	//	FireImp3->GetComponent<Transform>()->SetScale(Vector3(1.5f, 1.5f, 1.0001f));

	//	Animator* at = FireImp3->AddComponent<Animator>();
	//	FireImpScript* mFireImpScript = FireImp3->AddComponent<FireImpScript>();
	//	mFireImpScript->SetPlayerScript(mPlayerScript);
	//}
	{
		GameObject* FireImp4
			= object::Instantiate<GameObject>(Vector3(-2.4f, -0.7f, 0.998f), eLayerType::Monster);

		FireImp4->SetName(L"FireImp4");

		//Collider2D* cd = FireImp4->AddComponent<Collider2D>();
		//cd->SetCenter(Vector2(0.0f, 0.0f));
		//cd->SetSize(Vector2(0.25f, 0.25f));

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

		FireImp5->SetName(L"FireImp5");

		//Collider2D* cd = FireImp5->AddComponent<Collider2D>();
		//cd->SetCenter(Vector2(0.0f, 0.0f));
		//cd->SetSize(Vector2(0.25f, 0.25f));

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

		FireImp6->SetName(L"FireImp6");

		//Collider2D* cd = FireImp6->AddComponent<Collider2D>();
		//cd->SetCenter(Vector2(0.0f, 0.0f));
		//cd->SetSize(Vector2(0.25f, 0.25f));

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

		FireImp7->SetName(L"FireImp7");

		//Collider2D* cd = FireImp7->AddComponent<Collider2D>();
		//cd->SetCenter(Vector2(0.0f, 0.0f));
		//cd->SetSize(Vector2(0.25f, 0.25f));

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

		FireImp8->SetName(L"FireImp8");

		//Collider2D* cd = FireImp8->AddComponent<Collider2D>();
		//cd->SetCenter(Vector2(0.0f, 0.0f));
		//cd->SetSize(Vector2(0.25f, 0.25f));

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

		FireImp9->SetName(L"FireImp9");

		//Collider2D* cd = FireImp9->AddComponent<Collider2D>();
		//cd->SetCenter(Vector2(0.0f, 0.0f));
		//cd->SetSize(Vector2(0.25f, 0.25f));

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

		FireImp10->SetName(L"FireImp10");

		//Collider2D* cd = FireImp10->AddComponent<Collider2D>();
		//cd->SetCenter(Vector2(0.0f, 0.0f));
		//cd->SetSize(Vector2(0.25f, 0.25f));

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

		FireImp11->SetName(L"FireImp11");

		//Collider2D* cd = FireImp11->AddComponent<Collider2D>();
		//cd->SetCenter(Vector2(0.0f, 0.0f));
		//cd->SetSize(Vector2(0.25f, 0.25f));

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
		GameObject* Ground
			= object::Instantiate<GameObject>(Vector3(-0.6f, -1.2f, 0.999f), eLayerType::Ground);

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

		SetEastGarden(EastGarden);

		EastGarden->SetName(L"EastGarden");

		Camera::SetEastGardenScene(this);

		MeshRenderer* mr = EastGarden->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"EG"));


		EastGarden->GetComponent<Transform>()->SetScale(Vector3(17.0f, 5.0f, 1.0001f));
	}
	{
		GameObject* portal5 // 루타비스로 나가는 포탈 
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
		GameObject* portal6 // 반반넘어가는포탈
			= object::Instantiate<GameObject>(Vector3(7.67f, 0.12f, 0.999f), eLayerType::Portal);

		portal6->SetName(L"Portal6");


		Collider2D* cd = portal6->AddComponent<Collider2D>();
		cd->SetCenter(Vector2(0.0f, -0.4f));
		cd->SetSize(Vector2(0.27f, 0.65f));

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

		camera->AddComponent<AudioListener>();
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
		cameraComp->TurnLayerMask(eLayerType::SkillSlot, false);
		cameraComp->TurnLayerMask(eLayerType::Cursor, false);
		cameraComp->TurnLayerMask(eLayerType::NPC, false);
		cameraComp->TurnLayerMask(eLayerType::Inventory, false);
		cameraComp->TurnLayerMask(eLayerType::Damage, false);
		cameraComp->TurnLayerMask(eLayerType::Effect, false);

		//camera->AddComponent<CameraScript>();
	}
	Scene::Initialize();

}

void ya::EastGardenScene::Update()
{
	if (SceneManager::GetPlayerScript()->GetPortal())
	{
		if (Input::GetKeyDown(eKeyCode::UP))
		{
			AudioSource* as = GetEastGarden()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"Portal", L"..\\Resources\\Sound\\Portal.mp3"));
			as->Play();
			SceneManager::GetPlayerScript()->SetPortal(false);
			SceneManager::LoadScene(L"BanBanScene");
		}
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
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);
	CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::Portal, true);
	CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::NPC, true);
	CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::UI, true);
	CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::Shop, true);
	CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::Inventory, true);

	
	mPlayer = SceneManager::GetPlayer();
	Transform * tr = mPlayer->GetComponent<Transform>();
	Vector3 pos = tr->GetPosition();

	tr->SetPosition(-4.4f, -0.73f, pos.z);

	Camera::SetTarget(SceneManager::GetPlayer());
	Camera::SetHeneSisScene(nullptr);
	Camera::SetRootaByssScene(nullptr);
	Camera::SetEastGardenScene(this);

	AudioSource* as = GetEastGarden()->AddComponent<AudioSource>();
	as->SetClip(Resources::Load<AudioClip>(L"EastGarden", L"..\\Resources\\Sound\\TimeChaos.mp3"));
	as->SetLoop(true);
	as->Play();


	Scene::OnEnter();
}
void ya::EastGardenScene::OnExit()
{
	//AudioSource* as = GetEastGarden()->GetComponent<AudioSource>();
	//as->Stop();

	Scene::OnExit();
}
