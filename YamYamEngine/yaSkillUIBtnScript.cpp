#include "yaSkillUIBtnScript.h"
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
	ya::SkillUIBtnScript::SkillUIBtnScript()
		: testing(false)
	{
	}
	SkillUIBtnScript::~SkillUIBtnScript()
	{
	}
	void SkillUIBtnScript::Initialize()
	{

	}
	void SkillUIBtnScript::Update()
	{
		if (SceneManager::GetPlayerScript()->GetCameraScript() != nullptr)
		{
			SceneManager::GetPlayerScript()->GetCameraScript()->SetSkillSlot(GetOwner());
		}

		Transform* CameraTr = SceneManager::GetPlayerScript()->GetCameraScript()->GetOwner()->GetComponent<Transform>();
		CameraPos = CameraTr->GetPosition();
		Transform* OwnerTr = GetOwner()->GetComponent<Transform>();
		SlotPos = OwnerTr->GetPosition();
		mSize = OwnerTr->GetScale();
		SlotPos.x = SlotPos.x - CameraPos.x;
		SlotPos.y = SlotPos.y - CameraPos.y;
		LeftTop = Vector3(SlotPos.x - mSize.x / 2, SlotPos.y + mSize.y / 2, 0.9998f);

		mIndex1 = Vector3(LeftTop.x + 0.112f, LeftTop.y - 0.125f, 0.9998f);
		mIndex2 = Vector3(LeftTop.x + 0.33f, LeftTop.y - 0.125f, 0.9998f);
		mIndex3 = Vector3(LeftTop.x + 0.112f, LeftTop.y - 0.357f, 0.9998f);
		mIndex4 = Vector3(LeftTop.x + 0.33f, LeftTop.y - 0.357f, 0.9998f);
		mIndex5 = Vector3(LeftTop.x + 0.548f, LeftTop.y - 0.125f, 0.9998f);


		if (testing == false && Input::GetKeyDown(eKeyCode::T))
		{
			testing = true;
			test();
		}

		
	}
	void SkillUIBtnScript::OnCollisionEnter(Collider2D* other)
	{

	}
	void SkillUIBtnScript::OnCollisionStay(Collider2D* other)
	{

	}
	void SkillUIBtnScript::OnCollisionExit(Collider2D* other)
	{

	}

	void SkillUIBtnScript::test()
	{
		{
			GameObject* mBladePuryUI
				= object::Instantiate<GameObject>(Vector3(mIndex4.x, mIndex4.y, 0.99f), eLayerType::UI);

			mBladePuryUI->SetName(L"BladePuryUI");

			//SetBladePuryUI(mBladePuryUI);

			//SetBladePuryUI(mBladePuryUI);

			MeshRenderer* mr = mBladePuryUI->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"bladepuryui"));

			mBladePuryUI->GetComponent<Transform>()->SetScale(Vector3(0.2188f, 0.22f, 1.000f));
		}

	}

}