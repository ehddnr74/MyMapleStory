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
	void InventoryScript::OnInventory()
	{
		{
			GameObject* Inventory
				= object::Instantiate<GameObject>(Vector3(0.0f, 0.0f, 0.999f), eLayerType::Inventory);

			Inventory->SetName(L"Inventory");

			//Collider2D* cd = Inventory->AddComponent<Collider2D>();
			//cd->SetCenter(Vector2(0.0f, 0.0f));
			//cd->SetSize(Vector2(0.22f, 0.38f));

			MeshRenderer* mr = Inventory->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"Inven"));

			//Inventory->GetComponent<Transform>()->SetScale(Vector3(4.0f, 4.0f, 1.0001f));
		}
	}
}
