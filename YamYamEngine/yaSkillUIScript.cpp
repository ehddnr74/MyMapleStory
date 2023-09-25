#include "yaSkillUIScript.h"
#include "yaPlayerScript.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaMushroomScript.h"
#include "yaCollider2D.h"
#include "yaObject.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaMeshRenderer.h"
#include "yaCurSorScript.h"

namespace ya
{
	ya::SkillUIScript::SkillUIScript()
		: mBladePuryUIpicked(false)
		, pickedtime(0.0f)
	{
	}
	SkillUIScript::~SkillUIScript()
	{
	}
	void SkillUIScript::Initialize()
	{

	}
	void SkillUIScript::Update()
	{
		Vector3 MousePos = Input::GetMouseWorldPos();

		if (mBladePuryUIpicked && mBladePuryUI != nullptr)
		{
			Transform* CameraTr = SceneManager::GetPlayerScript()->GetCameraScript()->GetOwner()->GetComponent<Transform>();
			Vector3 CameraPos = CameraTr->GetPosition();
			Transform* tr = SceneManager::GetCursorScript()->GetOwner()->GetComponent<Transform>();
			Vector3 MouseWorldPos = tr->GetPosition();
			MouseWorldPos.x = MouseWorldPos.x - CameraPos.x - 0.05f;
			MouseWorldPos.y = MouseWorldPos.y - CameraPos.y + 0.1f;

			Transform* UItr = mBladePuryUI->GetComponent<Transform>();
			Vector3 UIPos = UItr->GetPosition();

			UItr->SetPosition(Vector3
				{
					MouseWorldPos.x,
					MouseWorldPos.y,
					0.99f
				});




		}

		if (mBladePuryUIpicked)
		{
			pickedtime += Time::DeltaTime();

			if (925.0f <= MousePos.x && MousePos.x <= 955.0f
				&& 812.0f <= MousePos.y && MousePos.y <= 848.0f)
			{
				if (Input::GetKeyDown(eKeyCode::LBUTTON))
				{
					mBladePuryUIpicked = false;
					Transform* CameraTr = SceneManager::GetPlayerScript()->GetCameraScript()->GetOwner()->GetComponent<Transform>();
					Vector3 CameraPos = CameraTr->GetPosition();
					Transform* tr = SceneManager::GetCursorScript()->GetOwner()->GetComponent<Transform>();
					Vector3 MouseWorldPos = tr->GetPosition();
					MouseWorldPos.x = MouseWorldPos.x - CameraPos.x - 0.05f;
					MouseWorldPos.y = MouseWorldPos.y - CameraPos.y + 0.1f;

					Transform* UItr = mBladePuryUI->GetComponent<Transform>();
					Vector3 UIPos = UItr->GetPosition();

					UItr->SetPosition(Vector3
						{
							MouseWorldPos.x,
							MouseWorldPos.y,
							0.99f
						});
				}

			}
			else if (pickedtime >= 0.2f && Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				mBladePuryUIpicked = false;
				object::Destroy(mBladePuryUI);
				SetBladePuryUI(nullptr);
			}
		}



		
		
		if (671.0f <= MousePos.x && MousePos.x <= 705.0f
			&& 241.0f <= MousePos.y && MousePos.y <= 273.0f)
		{
			if (Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				mBladePuryUIpicked = true;
				Transform* CameraTr = SceneManager::GetPlayerScript()->GetCameraScript()->GetOwner()->GetComponent<Transform>();
				Vector3 CameraPos = CameraTr->GetPosition();
				Transform* tr = SceneManager::GetCursorScript()->GetOwner()->GetComponent<Transform>();
				Vector3 MouseWorldPos = tr->GetPosition();
				MouseWorldPos.x = MouseWorldPos.x - CameraPos.x;
				MouseWorldPos.y = MouseWorldPos.y - CameraPos.y;
				{
					GameObject* mBladePuryUI
						= object::Instantiate<GameObject>(Vector3(MouseWorldPos.x, MouseWorldPos.y, 0.99f), eLayerType::UI);

					mBladePuryUI->SetName(L"BladePuryUI");

					SetBladePuryUI(mBladePuryUI);

					//SetBladePuryUI(mBladePuryUI);

					MeshRenderer* mr = mBladePuryUI->AddComponent<MeshRenderer>();
					mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
					mr->SetMaterial(Resources::Find<Material>(L"bladepuryui"));

					mBladePuryUI->GetComponent<Transform>()->SetScale(Vector3(0.225f, 0.225f, 1.000f));
				}
			}
		}
	}
	void SkillUIScript::OnCollisionEnter(Collider2D* other)
	{

	}
	void SkillUIScript::OnCollisionStay(Collider2D* other)
	{

	}
	void SkillUIScript::OnCollisionExit(Collider2D* other)
	{

	}

}