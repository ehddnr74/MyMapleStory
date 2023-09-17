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


		if (mCameraScript != nullptr)
		{
			Transform* tr = mCameraScript->GetOwner()->GetComponent<Transform>();
			CameraPos = tr->GetPosition();

			//Transform* OwnerTr = GetOwner()->GetComponent<Transform>();
			//Vector3 OwenrPos = OwnerTr->GetPosition();

			//Collider2D* cd = GetOwner()->GetComponent<Collider2D>();
			//cd->SetCenter(Vector2(OwenrPos.x - CameraPos.x - 1.0f, 1.3f));
			//cd->SetSize(Vector2(1.0f, 0.05f));
		}



		if (SceneManager::GetInventory3() != nullptr)
		{
			Transform* tr = SceneManager::GetInventory3()->GetComponent<Transform>();
			//Vector3 MousePos = Input::GetMouseWorldPos();
			Vector3 MousePos = Input::GetMouseWorldPos();
			Vector3 mSize = tr->GetScale();
			Vector3 mPos = tr->GetPosition();
			mLeftTop = Vector3(mPos.x - mSize.x / 2, mPos.y + mSize.y / 2, 0.996f);
			Vector3 mRightBottom = Vector3(mPos.x + mSize.x / 2, mPos.y - mSize.y / 2, mPos.z);

			std::vector<std::vector<Vector3>> mInVentoryIndex;
			std::vector<Vector3> InventoryIndex;

			mIndex1 = Vector3(mLeftTop.x + 0.16f, mLeftTop.y - 0.190f, 0.996f);
			mIndex2 = Vector3(mLeftTop.x + 0.48f, mLeftTop.y - 0.190f, 0.996f);
			mIndex3 = Vector3(mLeftTop.x + 0.80f, mLeftTop.y - 0.190f, 0.996f);
			mIndex4 = Vector3(mLeftTop.x + 1.12f, mLeftTop.y - 0.190f, 0.996f);
			mIndex5 = Vector3(mLeftTop.x + 0.16f, mLeftTop.y - 0.500f, 0.996f);
			mIndex6 = Vector3(mLeftTop.x + 0.48f, mLeftTop.y - 0.500f, 0.996f);
			mIndex7 = Vector3(mLeftTop.x + 0.80f, mLeftTop.y - 0.500f, 0.996f);
			mIndex8 = Vector3(mLeftTop.x + 1.12f, mLeftTop.y - 0.500f, 0.996f);
			mIndex9 = Vector3(mLeftTop.x + 0.16f, mLeftTop.y - 0.810f, 0.996f);
			mIndex10 = Vector3(mLeftTop.x + 0.48f, mLeftTop.y - 0.810f, 0.996f);
			mIndex11 = Vector3(mLeftTop.x + 0.80f, mLeftTop.y - 0.810f, 0.996f);
			mIndex12 = Vector3(mLeftTop.x + 1.12f, mLeftTop.y - 0.810f, 0.996f);
			mIndex13 = Vector3(mLeftTop.x + 0.16f, mLeftTop.y - 1.120f, 0.996f);
			mIndex14 = Vector3(mLeftTop.x + 0.48f, mLeftTop.y - 1.120f, 0.996f);
			mIndex15 = Vector3(mLeftTop.x + 0.80f, mLeftTop.y - 1.120f, 0.996f);
			mIndex16 = Vector3(mLeftTop.x + 1.12f, mLeftTop.y - 1.120f, 0.996f);
			mIndex17 = Vector3(mLeftTop.x + 0.16f, mLeftTop.y - 1.430f, 0.996f);
			mIndex18 = Vector3(mLeftTop.x + 0.48f, mLeftTop.y - 1.430f, 0.996f);
			mIndex19 = Vector3(mLeftTop.x + 0.80f, mLeftTop.y - 1.430f, 0.996f);
			mIndex20 = Vector3(mLeftTop.x + 1.12f, mLeftTop.y - 1.430f, 0.996f);
			mIndex21 = Vector3(mLeftTop.x + 0.16f, mLeftTop.y - 1.740f, 0.996f);
			mIndex22 = Vector3(mLeftTop.x + 0.48f, mLeftTop.y - 1.740f, 0.996f);
			mIndex23 = Vector3(mLeftTop.x + 0.80f, mLeftTop.y - 1.740f, 0.996f);
			mIndex24 = Vector3(mLeftTop.x + 1.12f, mLeftTop.y - 1.740f, 0.996f);


			//InventoryIndex.push_back(mIndex1);
			//InventoryIndex.push_back(mIndex2);
			//InventoryIndex.push_back(mIndex3);
			//InventoryIndex.push_back(mIndex4);
			//InventoryIndex.push_back(mIndex5);
			//InventoryIndex.push_back(mIndex6);
			//InventoryIndex.push_back(mIndex7);
			//InventoryIndex.push_back(mIndex8);
			//InventoryIndex.push_back(mIndex9);
			//InventoryIndex.push_back(mIndex10);
			//InventoryIndex.push_back(mIndex11);
			//InventoryIndex.push_back(mIndex12);
			//InventoryIndex.push_back(mIndex13);
			//InventoryIndex.push_back(mIndex14);
			//InventoryIndex.push_back(mIndex15);
			//InventoryIndex.push_back(mIndex16);
			//InventoryIndex.push_back(mIndex17);
			//InventoryIndex.push_back(mIndex18);
			//InventoryIndex.push_back(mIndex19);
			//InventoryIndex.push_back(mIndex20);
			//InventoryIndex.push_back(mIndex21);
			//InventoryIndex.push_back(mIndex22);
			//InventoryIndex.push_back(mIndex23);
			//InventoryIndex.push_back(mIndex24);
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
		//if (mCameraScript != nullptr)
		//{
		//	Transform* tr = GetCameraScript()->GetOwner()->GetComponent<Transform>();
		//	CameraPos = tr->GetPosition();
		//}
			{
				RootaByssKey
					= object::Instantiate<GameObject>(Vector3(mIndex1.x - CameraPos.x, mIndex1.y, mIndex1.z), eLayerType::Item);

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
	}
