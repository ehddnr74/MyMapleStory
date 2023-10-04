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
#include "yaHavisScript.h"

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
		GameObject* BanBan
			= object::Instantiate<GameObject>(Vector3(0.5f, 0.2f, 0.999f), eLayerType::Monster);

		BanBan->SetName(L"BanBan");

		//Collider2D* cd = BanBan->AddComponent<Collider2D>();
		//cd->SetCenter(Vector2(0.0f, 0.0f));
		//cd->SetSize(Vector2(0.22f, 0.38f));

		MeshRenderer* mr = BanBan->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));


		BanBan->GetComponent<Transform>()->SetScale(Vector3(4.0f, 4.0f, 1.0001f));

		Animator* at = BanBan->AddComponent<Animator>();
		BanBanScript* mBanBanScript = BanBan->AddComponent<BanBanScript>();
		mBanBanScript->SetPlayerScript(mPlayerScript);

	}

	{
		GameObject* Ground
			= object::Instantiate<GameObject>(Vector3(-0.6f, -1.53f, 0.999f), eLayerType::Ground);

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
		cameraComp->TurnLayerMask(eLayerType::SkillSlot, false);
		cameraComp->TurnLayerMask(eLayerType::Portal, false);
		cameraComp->TurnLayerMask(eLayerType::Inventory, false);
		cameraComp->TurnLayerMask(eLayerType::Damage, false);
		cameraComp->TurnLayerMask(eLayerType::Effect, false);
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
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);
	CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::Portal, true);
	CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::NPC, true);
	CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::UI, true);
	CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::Shop, true);
	CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::Inventory, true);

	//SceneManager::GetHpScript()->GetOwner()->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.1f, 1.000f));
	//SceneManager::GetHpScript()->SetHP(99999.0f);

	mPlayer = SceneManager::GetPlayer();
	Transform* tr = mPlayer->GetComponent<Transform>();
	Vector3 pos = tr->GetPosition();

	tr->SetPosition(-1.1f, -1.06f, pos.z);

	Camera::SetTarget(SceneManager::GetPlayer());
	Camera::SetHeneSisScene(nullptr);
	Camera::SetRootaByssScene(nullptr);
	Camera::SetEastGardenScene(nullptr);
	Camera::SetBanBanScene(this);
	Scene::OnEnter();
}

void ya::BanBanScene::OnExit()
{
	Camera::SetBanBanScene(nullptr);
	Scene::OnExit();
}
