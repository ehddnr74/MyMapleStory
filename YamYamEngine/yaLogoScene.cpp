#include "yaLogoScene.h"
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
#include "yaLogoScript.h"
#include "yaPlayerScript.h"
#include "yaTime.h"
namespace ya
{
	LogoScene::LogoScene()
		: LoadSceneTime(0.0f)
	{
	}
	LogoScene::~LogoScene()
	{
	}
	void LogoScene::Initialize()
	{
		{
			GameObject* Wizet
				= object::Instantiate<GameObject>(Vector3(0.0f, 0.4f, 0.999f), eLayerType::Logo);

			Wizet->SetName(L"Wizet");

			MeshRenderer* mr = Wizet->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));


			Wizet->GetComponent<Transform>()->SetScale(Vector3(5.0f, 5.0f, 0.999f));

			Animator* at = Wizet->AddComponent<Animator>();
			LogoScript* mLogoScript = Wizet->AddComponent<LogoScript>();
			SetLogoScript(mLogoScript);
		}

		//Main Camera
		Camera* cameraComp = nullptr;
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::Player, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
			cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::UI, false);
			//camera->AddComponent<CameraScript>();
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
			//camera->AddComponent<CameraScript>();
		}

		Scene::Initialize();
	}
	void LogoScene::Update()
	{
		if (GetLogoScript()->GetLogoEnd())
		{
			LoadSceneTime += Time::DeltaTime();

			if (LoadSceneTime >= 0.5f)
			{
				SceneManager::LoadScene(L"HenesisScene");
			}
		}
		Scene::Update();
	}
	void LogoScene::LateUpdate()
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
	void LogoScene::Render()
	{
		Scene::Render();
	}
}