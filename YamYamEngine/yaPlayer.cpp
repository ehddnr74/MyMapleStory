#include "yaPlayer.h"
#include "yaMesh.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaRigidBody.h"
#include "yaPlayerScript.h"


namespace ya
{
	Player::Player()
	{
	}
	Player::~Player()
	{
	}

	void Player::Initialize()
	{
		SetName(L"Adel");
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		GetComponent<Transform>()->SetPosition(Vector3(0.0f, 6.0f, 0.999f));
		GetComponent<Transform>()->SetScale(Vector3(1.6f, 1.6f, 0.999f));

		Collider2D* col = AddComponent<Collider2D>();
		col->SetSize(Vector2(0.5f, 0.8f));
		RigidBody* rb = AddComponent<RigidBody>();
		rb->SetMass(1.0f);


		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render()
	{
		GameObject::Render();
	}

}