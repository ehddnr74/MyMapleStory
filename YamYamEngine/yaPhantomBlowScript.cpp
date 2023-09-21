#include "yaPhantomBlowScript.h"
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
#include <random>



namespace ya
{
	ya::PhantomBlowScript::PhantomBlowScript()
		: phantomblowTime(0.0f)
		, Rightphantomblow(false)
		, DamageView(false)
		, test(0)
	{
	}
	PhantomBlowScript::~PhantomBlowScript()
	{
	}
	void PhantomBlowScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> LeftPhantomBlow = Resources::Load<Texture>(L"LeftPhantomBlow", L"..\\Resources\\Texture\\LeftPhantomBlow.png");
		std::shared_ptr<Texture> RightPhantomBlow = Resources::Load<Texture>(L"RightPhantomBlow", L"..\\Resources\\Texture\\RightPhantomBlow.png");


		at->Create(L"LeftPhantomBlow", LeftPhantomBlow, Vector2(0.0f, 0.0f), Vector2(616.0f, 300.0f), 10, Vector2::Zero, 0.08f);
		at->Create(L"RightPhantomBlow", RightPhantomBlow, Vector2(0.0f, 0.0f), Vector2(616.0f, 300.0f), 10, Vector2::Zero, 0.08f);


		at->PlayAnimation(L"LeftPhantomBlow", false);

		mSkillState = SkillState::PhantomBlow;
	}
	void PhantomBlowScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		switch (mSkillState)
		{
		case PhantomBlowScript::SkillState::PhantomBlow:
			phantomblow();
			break;
		case PhantomBlowScript::SkillState::RightPhantomBlow:
			rightphantomblow();
			break;
		default:
			break;
		}
		if (Rightphantomblow == true)
		{
			GetOwner()->AddComponent<Animator>();
			Animator* at = GetOwner()->GetComponent<Animator>();

			Rightphantomblow = false;
			mSkillState = SkillState::RightPhantomBlow;
			at->PlayAnimation(L"RightPhantomBlow", false);
		}
	}

	void PhantomBlowScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"MushRoom" && DamageView == false)
		{
				DamageView = true;
				Transform* tr = other->GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos));
				SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.2f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.4f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.6f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 0.8f, pos.z));
				SceneManager::GetPlayerScript()->CreateDamage(other->GetOwner(), Vector3(pos.x, pos.y + 1.0f, pos.z));
			}
	}
	void PhantomBlowScript::OnCollisionStay(Collider2D* other)
	{
	}
	void PhantomBlowScript::OnCollisionExit(Collider2D* other)
	{
	}
	void PhantomBlowScript::phantomblow()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
	void PhantomBlowScript::rightphantomblow()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();
	}
}