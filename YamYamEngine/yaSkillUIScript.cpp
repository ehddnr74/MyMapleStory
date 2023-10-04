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
#include "yaSkillUIBtnScript.h"

namespace ya
{
	ya::SkillUIScript::SkillUIScript()
		: mBladePuryUIpicked(false)
		, pickedtime(0.0f)
		, BladePuryisSet(false)

		, mPhantomBlowUIpicked(false)
		, PhantomBlowisSet(false)

		, mBladeTornadoUIpicked(false)
	    , BladeTornadoisSet(false)

	    , mKarmaPuryUIpicked(false)
	    , KarmaPuryisSet(false)
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
		MousePos = Input::GetMouseWorldPos();

		if (mBladePuryUIpicked == false)
		{
			if (671.0f <= MousePos.x && MousePos.x <= 705.0f
				&& 241.0f <= MousePos.y && MousePos.y <= 273.0f)
			{
				if (Input::GetKeyDown(eKeyCode::LBUTTON))
				{
					CreateBladePuryUI();
				}
			}
		}

		if (mPhantomBlowUIpicked == false)
		{
			if (671.0f <= MousePos.x && MousePos.x <= 705.0f
				&& 290.0f <= MousePos.y && MousePos.y <= 324.0f)
			{
				if (Input::GetKeyDown(eKeyCode::LBUTTON))
				{
					CreatePhantomBlowUI();
				}
			}
		}

		if (mBladeTornadoUIpicked == false)
		{
			if (671.0f <= MousePos.x && MousePos.x <= 705.0f
				&& 340.0f <= MousePos.y && MousePos.y <= 375.0f)
			{
				if (Input::GetKeyDown(eKeyCode::LBUTTON))
				{
					CreateBladeTornadoUI();
				}
			}
		}

		if (mKarmaPuryUIpicked == false)
		{
			if (671.0f <= MousePos.x && MousePos.x <= 705.0f
				&& 389.0f <= MousePos.y && MousePos.y <= 421.0f)
			{
				if (Input::GetKeyDown(eKeyCode::LBUTTON))
				{
					CreateKarmaPuryUI();
				}
			}
		}


		////// 스킬 UI 클릭시 오브젝트 생성 

		if (mBladePuryUIpicked && mBladePuryUI != nullptr)
		{
			Transform* CameraTr = SceneManager::GetPlayerScript()->GetCameraScript()->GetOwner()->GetComponent<Transform>();
			CameraPos = CameraTr->GetPosition();
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

		if (mPhantomBlowUIpicked && mPhantomBlowUI != nullptr)
		{
			Transform* CameraTr = SceneManager::GetPlayerScript()->GetCameraScript()->GetOwner()->GetComponent<Transform>();
			CameraPos = CameraTr->GetPosition();
			Transform* tr = SceneManager::GetCursorScript()->GetOwner()->GetComponent<Transform>();
			Vector3 MouseWorldPos = tr->GetPosition();
			MouseWorldPos.x = MouseWorldPos.x - CameraPos.x - 0.05f;
			MouseWorldPos.y = MouseWorldPos.y - CameraPos.y + 0.1f;

			Transform* UItr = mPhantomBlowUI->GetComponent<Transform>();
			Vector3 UIPos = UItr->GetPosition();

			UItr->SetPosition(Vector3
				{
					MouseWorldPos.x,
					MouseWorldPos.y,
					0.99f
				});
		}

		if (mBladeTornadoUIpicked && mBladeTornadoUI != nullptr)
		{
			Transform* CameraTr = SceneManager::GetPlayerScript()->GetCameraScript()->GetOwner()->GetComponent<Transform>();
			CameraPos = CameraTr->GetPosition();
			Transform* tr = SceneManager::GetCursorScript()->GetOwner()->GetComponent<Transform>();
			Vector3 MouseWorldPos = tr->GetPosition();
			MouseWorldPos.x = MouseWorldPos.x - CameraPos.x - 0.05f;
			MouseWorldPos.y = MouseWorldPos.y - CameraPos.y + 0.1f;

			Transform* UItr = mBladeTornadoUI->GetComponent<Transform>();
			Vector3 UIPos = UItr->GetPosition();

			UItr->SetPosition(Vector3
				{
					MouseWorldPos.x,
					MouseWorldPos.y,
					0.99f
				});
		}

		if (mKarmaPuryUIpicked && mKarmaPuryUI != nullptr)
		{
			Transform* CameraTr = SceneManager::GetPlayerScript()->GetCameraScript()->GetOwner()->GetComponent<Transform>();
			CameraPos = CameraTr->GetPosition();
			Transform* tr = SceneManager::GetCursorScript()->GetOwner()->GetComponent<Transform>();
			Vector3 MouseWorldPos = tr->GetPosition();
			MouseWorldPos.x = MouseWorldPos.x - CameraPos.x - 0.05f;
			MouseWorldPos.y = MouseWorldPos.y - CameraPos.y + 0.1f;

			Transform* UItr = mKarmaPuryUI->GetComponent<Transform>();
			Vector3 UIPos = UItr->GetPosition();

			UItr->SetPosition(Vector3
				{
					MouseWorldPos.x,
					MouseWorldPos.y,
					0.99f
				});
		}
		// 클릭 후 스킬 UI 마우스 좌표 따라 오기 


		if (mBladePuryUIpicked)
		{
			pickedtime += Time::DeltaTime();

			if (930.0f <= MousePos.x && MousePos.x <= 955.0f
				&& 816.0f <= MousePos.y && MousePos.y <= 846.0f)
			{
				if (Input::GetKeyDown(eKeyCode::LBUTTON))
				{
					SetBladePuryUI();
				}
			}
			else if (pickedtime >= 0.2f && Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				DestroyBladePuryUI();
			}
		}

		if (mPhantomBlowUIpicked)
		{
			pickedtime += Time::DeltaTime();

			if (971.0f <= MousePos.x && MousePos.x <= 999.0f
				&& 816.0f <= MousePos.y && MousePos.y <= 846.0f)
			{
				if (Input::GetKeyDown(eKeyCode::LBUTTON))
				{
					SetPhantomBlowUI();
				}
			}
			else if (pickedtime >= 0.2f && Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				DestroyPhantomBlowUI();
			}
		}

		if (mBladeTornadoUIpicked)
		{
			pickedtime += Time::DeltaTime();

			if (927.0f <= MousePos.x && MousePos.x <= 956.0f
				&& 863.0f <= MousePos.y && MousePos.y <= 893.0f)
			{
				if (Input::GetKeyDown(eKeyCode::LBUTTON))
				{
					SetBladeTornadoUI();
				}
			}
			else if (pickedtime >= 0.2f && Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				DestroyBladeTornadoUI();
			}
		}

		if (mKarmaPuryUIpicked)
		{
			pickedtime += Time::DeltaTime();

			if (971.0f <= MousePos.x && MousePos.x <= 999.0f
				&& 863.0f <= MousePos.y && MousePos.y <= 893.0f)
			{
				if (Input::GetKeyDown(eKeyCode::LBUTTON))
				{
					SetKarmaPuryUI();
				}
			}
			else if (pickedtime >= 0.2f && Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				DestroyKarmaPuryUI();
			}
		}
	}
	

	// 스킬UI BTN에 Set or Destroy 결정 

	void SkillUIScript::CreateBladePuryUI()
	{
		{
			mBladePuryUIpicked = true;
			Transform* CameraTr = SceneManager::GetPlayerScript()->GetCameraScript()->GetOwner()->GetComponent<Transform>();
			CameraPos = CameraTr->GetPosition();
			Transform* tr = SceneManager::GetCursorScript()->GetOwner()->GetComponent<Transform>();
			MouseWorldPos = tr->GetPosition();
			MouseWorldPos.x = MouseWorldPos.x - CameraPos.x;
			MouseWorldPos.y = MouseWorldPos.y - CameraPos.y;
			{
				GameObject* mBladePuryUI
					= object::Instantiate<GameObject>(Vector3(MouseWorldPos.x, MouseWorldPos.y, 0.99f), eLayerType::UI);

				mBladePuryUI->SetName(L"BladePuryUI");

				SetBladePuryUI(mBladePuryUI);

				MeshRenderer* mr = mBladePuryUI->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"bladepuryui"));

				mBladePuryUI->GetComponent<Transform>()->SetScale(Vector3(0.218f, 0.22f, 1.000f));
			}
		}	
	}
	void SkillUIScript::DestroyBladePuryUI()
	{
		mBladePuryUIpicked = false;
		object::Destroy(mBladePuryUI);
		SetBladePuryUI(nullptr);
		BladePuryisSet = false;
	}
	void ya::SkillUIScript::SetBladePuryUI()
	{
		pickedtime = 0.0f;
		BladePuryisSet = true;
		mBladePuryUIpicked = false;

		Transform* UItr = mBladePuryUI->GetComponent<Transform>();
		Vector3 UIPos = UItr->GetPosition();

		UItr->SetPosition(Vector3
			{
				SceneManager::GetSkillUIBtnScript()->GetIndex1().x,
				SceneManager::GetSkillUIBtnScript()->GetIndex1().y,
				0.99f
			});
		object::DontDestroyOnLoad(mBladePuryUI);
	}
	void SkillUIScript::CreatePhantomBlowUI()
	{
		{
			mPhantomBlowUIpicked = true;
			Transform* CameraTr = SceneManager::GetPlayerScript()->GetCameraScript()->GetOwner()->GetComponent<Transform>();
			CameraPos = CameraTr->GetPosition();
			Transform* tr = SceneManager::GetCursorScript()->GetOwner()->GetComponent<Transform>();
			MouseWorldPos = tr->GetPosition();
			MouseWorldPos.x = MouseWorldPos.x - CameraPos.x;
			MouseWorldPos.y = MouseWorldPos.y - CameraPos.y;
			{
				GameObject* mPhantomBlowUI
					= object::Instantiate<GameObject>(Vector3(MouseWorldPos.x, MouseWorldPos.y, 0.99f), eLayerType::UI);

				mPhantomBlowUI->SetName(L"PhantomBlowUI");

				SetPhantomBlowUI(mPhantomBlowUI);

				MeshRenderer* mr = mPhantomBlowUI->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"phantomblowui"));

				mPhantomBlowUI->GetComponent<Transform>()->SetScale(Vector3(0.218f, 0.22f, 1.000f));
			}
		}
	}
	void SkillUIScript::DestroyPhantomBlowUI()
	{
		mPhantomBlowUIpicked = false;
		object::Destroy(mPhantomBlowUI);
		SetPhantomBlowUI(nullptr);
		PhantomBlowisSet = false;
	}
	void SkillUIScript::SetPhantomBlowUI()
	{
		pickedtime = 0.0f;
		PhantomBlowisSet = true;
		mPhantomBlowUIpicked = false;

		Transform* UItr = mPhantomBlowUI->GetComponent<Transform>();
		Vector3 UIPos = UItr->GetPosition();

		UItr->SetPosition(Vector3
			{
				SceneManager::GetSkillUIBtnScript()->GetIndex2().x,
				SceneManager::GetSkillUIBtnScript()->GetIndex2().y,
				0.99f
			});
		object::DontDestroyOnLoad(mPhantomBlowUI);
	}
	void SkillUIScript::CreateBladeTornadoUI()
	{
		{
			mBladeTornadoUIpicked = true;
			Transform* CameraTr = SceneManager::GetPlayerScript()->GetCameraScript()->GetOwner()->GetComponent<Transform>();
			CameraPos = CameraTr->GetPosition();
			Transform* tr = SceneManager::GetCursorScript()->GetOwner()->GetComponent<Transform>();
			MouseWorldPos = tr->GetPosition();
			MouseWorldPos.x = MouseWorldPos.x - CameraPos.x;
			MouseWorldPos.y = MouseWorldPos.y - CameraPos.y;
			{
				GameObject* mBladeTornadoUI
					= object::Instantiate<GameObject>(Vector3(MouseWorldPos.x, MouseWorldPos.y, 0.99f), eLayerType::UI);

				mBladeTornadoUI->SetName(L"BladeTornadoUI");

				SetBladeTornadoUI(mBladeTornadoUI);

				MeshRenderer* mr = mBladeTornadoUI->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"bladetornadoui"));

				mBladeTornadoUI->GetComponent<Transform>()->SetScale(Vector3(0.218f, 0.22f, 1.000f));
			}
		}
	}
	void SkillUIScript::DestroyBladeTornadoUI()
	{
		mBladeTornadoUIpicked = false;
		object::Destroy(mBladeTornadoUI);
		SetBladeTornadoUI(nullptr);
		BladeTornadoisSet = false;
	}
	void SkillUIScript::SetBladeTornadoUI()
	{
		pickedtime = 0.0f;
		BladeTornadoisSet = true;
		mBladeTornadoUIpicked = false;

		Transform* UItr = mBladeTornadoUI->GetComponent<Transform>();
		Vector3 UIPos = UItr->GetPosition();

		UItr->SetPosition(Vector3
			{
				SceneManager::GetSkillUIBtnScript()->GetIndex3().x,
				SceneManager::GetSkillUIBtnScript()->GetIndex3().y,
				0.99f
			});
		object::DontDestroyOnLoad(mBladeTornadoUI);
	}
	void SkillUIScript::CreateKarmaPuryUI()
	{
		{
			mKarmaPuryUIpicked = true;
			Transform* CameraTr = SceneManager::GetPlayerScript()->GetCameraScript()->GetOwner()->GetComponent<Transform>();
			CameraPos = CameraTr->GetPosition();
			Transform* tr = SceneManager::GetCursorScript()->GetOwner()->GetComponent<Transform>();
			MouseWorldPos = tr->GetPosition();
			MouseWorldPos.x = MouseWorldPos.x - CameraPos.x;
			MouseWorldPos.y = MouseWorldPos.y - CameraPos.y;
			{
				GameObject* mKarmaPuryUI
					= object::Instantiate<GameObject>(Vector3(MouseWorldPos.x, MouseWorldPos.y, 0.99f), eLayerType::UI);

				mKarmaPuryUI->SetName(L"KarmaPuryUI");

				SetKarmaPuryUI(mKarmaPuryUI);

				MeshRenderer* mr = mKarmaPuryUI->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"karmapuryui"));

				mKarmaPuryUI->GetComponent<Transform>()->SetScale(Vector3(0.218f, 0.22f, 1.000f));
			}
		}
	}
	void SkillUIScript::DestroyKarmaPuryUI()
	{
		mKarmaPuryUIpicked = false;
		object::Destroy(mKarmaPuryUI);
		SetKarmaPuryUI(nullptr);
		KarmaPuryisSet = false;
	}
	void SkillUIScript::SetKarmaPuryUI()
	{
		pickedtime = 0.0f;
		KarmaPuryisSet = true;
		mKarmaPuryUIpicked = false;

		Transform* UItr = mKarmaPuryUI->GetComponent<Transform>();
		Vector3 UIPos = UItr->GetPosition();

		UItr->SetPosition(Vector3
			{
				SceneManager::GetSkillUIBtnScript()->GetIndex4().x,
				SceneManager::GetSkillUIBtnScript()->GetIndex4().y,
				0.99f
			});
		object::DontDestroyOnLoad(mKarmaPuryUI);
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