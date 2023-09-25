#include "yaInventoryScript.h"
#include "yaPlayerScript.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaCollider2D.h"
#include "yaObject.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaMesh.h"
#include "yaMeshRenderer.h"
#include "yaCamera.h"
#include "yaCurSorScript.h"


namespace ya
{
	InventoryScript::InventoryScript()
		: mLeftTop(Vector3(0.0f, 0.0f, 0.0f))
	{

	}
	InventoryScript::~InventoryScript()
	{

	}
	void InventoryScript::Initialize()
	{
	}
	void InventoryScript::Update()
	{
		Vector3 MousePos = Input::GetMouseWorldPos();

		if (912.0f <= MousePos.x && MousePos.x <= 941.0f
			&& 178.0f <= MousePos.y && MousePos.y <= 208.0f)
		{
			int a = 0;
		}

		//switch (mInventoryState)
		//{
		//case InventoryScript::InventoryState::OnInventory:
		//	oninventory();
		//	break;
		//case InventoryScript::InventoryState::CloseInventory:
		//	closeinventory();
		//	break;
		//default:
		//	break;
		//}

		if (mInventory != nullptr)
		{
			if (mCameraScript != nullptr)
			{
				Transform* tr = GetCameraScript()->GetOwner()->GetComponent<Transform>();
				CameraPos = tr->GetPosition();
			}

			Transform* tr = mInventory->GetComponent<Transform>();
			Vector3 mSize = tr->GetScale();
			InventoryPos = tr->GetPosition();

			InventoryPos.x = InventoryPos.x - CameraPos.x;
			InventoryPos.y = InventoryPos.y - CameraPos.y;
			InventoryPos.z = InventoryPos.z;

			mLeftTop = Vector3(InventoryPos.x - mSize.x / 2, InventoryPos.y + mSize.y / 2, 0.996f);
			Vector3 mRightBottom = Vector3(InventoryPos.x + mSize.x / 2, InventoryPos.y - mSize.y / 2, InventoryPos.z);

			std::vector<std::vector<Vector3>> mInVentoryIndex;
			std::vector<Vector3> InventoryIndex;

			mIndex1 = Vector3(mLeftTop.x + 0.335f, mLeftTop.y - 0.51f, 0.996f);
			mIndex2 = Vector3(mLeftTop.x + 0.645f, mLeftTop.y - 0.51f, 0.996f);
			mIndex3 = Vector3(mLeftTop.x + 0.955f, mLeftTop.y - 0.51f, 0.996f);
			mIndex4 = Vector3(mLeftTop.x + 1.265f, mLeftTop.y - 0.51f, 0.996f);
			mIndex5 = Vector3(mLeftTop.x + 0.335f, mLeftTop.y - 0.81f, 0.996f);
			mIndex6 = Vector3(mLeftTop.x + 0.645f, mLeftTop.y - 0.81f, 0.996f);
			mIndex7 = Vector3(mLeftTop.x + 0.955f, mLeftTop.y - 0.81f, 0.996f);
			mIndex8 = Vector3(mLeftTop.x + 1.265f, mLeftTop.y - 0.81f, 0.996f);
			mIndex9 = Vector3(mLeftTop.x + 0.335f, mLeftTop.y - 1.1f, 0.996f);
			mIndex10 = Vector3(mLeftTop.x + 0.645f, mLeftTop.y - 1.1f, 0.996f);
			mIndex11 = Vector3(mLeftTop.x + 0.955f, mLeftTop.y - 1.1f, 0.996f);
			mIndex12 = Vector3(mLeftTop.x + 1.265f, mLeftTop.y - 1.1f, 0.996f);
			mIndex13 = Vector3(mLeftTop.x + 0.335f, mLeftTop.y - 1.4f, 0.996f);
			mIndex14 = Vector3(mLeftTop.x + 0.645f, mLeftTop.y - 1.4f, 0.996f);
			mIndex15 = Vector3(mLeftTop.x + 0.955f, mLeftTop.y - 1.4f, 0.996f);
			mIndex16 = Vector3(mLeftTop.x + 1.265f, mLeftTop.y - 1.4f, 0.996f);
			mIndex17 = Vector3(mLeftTop.x + 0.335f, mLeftTop.y - 1.69f, 0.996f);
			mIndex18 = Vector3(mLeftTop.x + 0.645f, mLeftTop.y - 1.69f, 0.996f);
			mIndex19 = Vector3(mLeftTop.x + 0.955f, mLeftTop.y - 1.69f, 0.996f);
			mIndex20 = Vector3(mLeftTop.x + 1.265f, mLeftTop.y - 1.69f, 0.996f);
			mIndex21 = Vector3(mLeftTop.x + 0.335f, mLeftTop.y - 1.98f, 0.996f);
			mIndex22 = Vector3(mLeftTop.x + 0.645f, mLeftTop.y - 1.98f, 0.996f);
			mIndex23 = Vector3(mLeftTop.x + 0.955f, mLeftTop.y - 1.98f, 0.996f);
			mIndex24 = Vector3(mLeftTop.x + 1.265f, mLeftTop.y - 1.98f, 0.996f);


			InventoryIndex.push_back(mIndex1);
			InventoryIndex.push_back(mIndex2);
			InventoryIndex.push_back(mIndex3);
			InventoryIndex.push_back(mIndex4);
			InventoryIndex.push_back(mIndex5);
			InventoryIndex.push_back(mIndex6);
			InventoryIndex.push_back(mIndex7);
			InventoryIndex.push_back(mIndex8);
			InventoryIndex.push_back(mIndex9);
			InventoryIndex.push_back(mIndex10);
			InventoryIndex.push_back(mIndex11);
			InventoryIndex.push_back(mIndex12);
			InventoryIndex.push_back(mIndex13);
			InventoryIndex.push_back(mIndex14);
			InventoryIndex.push_back(mIndex15);
			InventoryIndex.push_back(mIndex16);
			InventoryIndex.push_back(mIndex17);
			InventoryIndex.push_back(mIndex18);
			InventoryIndex.push_back(mIndex19);
			InventoryIndex.push_back(mIndex20);
			InventoryIndex.push_back(mIndex21);
			InventoryIndex.push_back(mIndex22);
			InventoryIndex.push_back(mIndex23);
			InventoryIndex.push_back(mIndex24);
		}
		//mRightBottom += Vector3(-25.0f, 84.0f, mPos.z);
	}
	void InventoryScript::OnCollisionEnter(Collider2D* other)
	{

	}
	void InventoryScript::OnCollisionStay(Collider2D* other)
	{

	}
	void InventoryScript::OnCollisionExit(Collider2D* other)
	{

	}

	void InventoryScript::Buying()
	{
		if (mCameraScript != nullptr)
		{
			Transform* tr = GetCameraScript()->GetOwner()->GetComponent<Transform>();
			CameraPos = tr->GetPosition();
		}
			{
				RootaByssKey
					= object::Instantiate<GameObject>(Vector3(mIndex1.x , mIndex1.y, mIndex9.z), eLayerType::Item);

				RootaByssKey->SetName(L"RootaByssKey");

				//Collider2D* cd = Inventory->AddComponent<Collider2D>();
				//cd->SetCenter(Vector2(0.0f, 0.0f));
				//cd->SetSize(Vector2(0.22f, 0.38f));

				MeshRenderer* mr = RootaByssKey->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"rootabysskey"));

				RootaByssKey->GetComponent<Transform>()->SetScale(Vector3(0.2f, 0.2f, 1.0001f));
			}
	}

	void InventoryScript::OnInventory()
	{
		if (mCameraScript != nullptr)
		{
			mCameraScript = SceneManager::GetPlayerScript()->GetCameraScript();
			Transform* tr = mCameraScript->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			GameObject* mInventory
				= object::Instantiate<GameObject>(Vector3(2.8f, 0.5f, 0.999f), eLayerType::Inventory);

			mInventory->SetName(L"Inventory");

			SetInventory(mInventory);
			mCameraScript->SetInventory(mInventory);

			MeshRenderer* mr = mInventory->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"Inven"));

			mInventory->GetComponent<Transform>()->SetScale(Vector3(1.7f, 3.0f, 1.0001f));
		}
	}

	void InventoryScript::CloseInventory()
	{
		mCameraScript->SetInventory(nullptr);
	    object::Destroy(mInventory);
		SetInventory(nullptr);
	}
}
