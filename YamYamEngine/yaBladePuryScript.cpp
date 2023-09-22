#include "yaBladePuryScript.h"
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

namespace ya
{
	ya::BladePuryScript::BladePuryScript()
		: Leftbladepury(false)
		, Rightbladepury(false)
		, DamageView(false)
	{

	}
	BladePuryScript::~BladePuryScript()
	{

	}

	void BladePuryScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> LeftBladePury = Resources::Load<Texture>(L"LeftBladePury", L"..\\Resources\\Texture\\LeftBladePury.png");
		std::shared_ptr<Texture> RightBladePury = Resources::Load<Texture>(L"RightBladePury", L"..\\Resources\\Texture\\RightBladePury.png");
		


		at->Create(L"LeftBladePury", LeftBladePury, Vector2(0.0f, 0.0f), Vector2(712.0f, 586.0f), 14, Vector2::Zero, 0.05f);
		at->Create(L"RightBladePury", RightBladePury, Vector2(0.0f, 0.0f), Vector2(712.0f, 586.0f), 14, Vector2::Zero, 0.05f);


		at->PlayAnimation(L"LeftBladePury", false);

		mSkillState = SkillState::BladePury;
	}
	void BladePuryScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		switch (mSkillState)
		{

		case BladePuryScript::SkillState::BladePury:
			bladepury();
			break;
		case BladePuryScript::SkillState::RightBladePury:
			rightbladepury();
			break;
		default:
			break;
		}
		if (Rightbladepury == true)
		{
			GetOwner()->AddComponent<Animator>();
			Animator* at = GetOwner()->GetComponent<Animator>();

			Rightbladepury = false;
			mSkillState = SkillState::RightBladePury;
			at->PlayAnimation(L"RightBladePury", false);
		}
	}

	void BladePuryScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"MushRoom" && DamageView == false)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			SceneManager::GetPlayerScript()->CreateBladePuryHitEffect(other->GetOwner(), Vector3(pos.x - 0.5f, pos.y + 0.1f, 0.997f));
			DamageView = true;
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
			SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
		}
	}
	void BladePuryScript::OnCollisionStay(Collider2D* other)
	{
	}
	void BladePuryScript::OnCollisionExit(Collider2D* other)
	{
	}
	void BladePuryScript::bladepury()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
	void BladePuryScript::rightbladepury()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
}