#include "yaFadeIn.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaLight.h"
#include "yaObject.h"
#include "yaSceneManager.h"
#include "yaMeshRenderer.h"
#include "yaMesh.h"


namespace ya
{
	FadeIn::FadeIn()
		: Alpha(1.0f)
		, Fade(false)
	{

	}
	FadeIn::~FadeIn()
	{

	}
	void FadeIn::Initialize()
	{
		{
			GameObject* FadeIn
				= object::Instantiate<GameObject>(Vector3(0.0f, 0.0f, 1.0002f), eLayerType::Light);

			SetFadeIn(FadeIn);

			FadeIn->SetName(L"FadeIn");

			MeshRenderer* mr = FadeIn->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"fadein"));

			FadeIn->GetComponent<Transform>()->SetScale(Vector3(10.5f, 5.0f, 1.0001f));

			Light* lightComp = FadeIn->AddComponent<Light>();
			lightComp->SetType(eLightType::Point);
			lightComp->SetColor(Vector4(1.0f, 1.0f, 1.0f, 0.0f));
		}
	}
	void FadeIn::Update()
	{
		//	if (FadingIn != nullptr)
		//	{
		//		Alpha -= Time::DeltaTime();

		//		Light* lightComp = FadingIn->GetComponent<Light>();
		//		lightComp->SetColor(Vector4(1.0f, 1.0f, 1.0f, Alpha));
		//	}

		//	if (Alpha <= 0.0f && Fade == false)
		//	{
		//		Fade = true;
		//		object::Destroy(FadingIn);
		//		SetFadeIn(nullptr);
		//	}
	}
}

