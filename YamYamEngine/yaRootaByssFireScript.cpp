#include "yaRootaByssFireScript.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaAnimator.h"
#include "yaResources.h"


namespace ya
{
	RootaByssFireScript::RootaByssFireScript()
	{
	}
	RootaByssFireScript::~RootaByssFireScript()
	{
	}
	void RootaByssFireScript::Initialize()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> Fire1 = Resources::Load<Texture>(L"Fire1", L"..\\Resources\\Texture\\Fire1.png");
		std::shared_ptr<Texture> Fire2 = Resources::Load<Texture>(L"Fire2", L"..\\Resources\\Texture\\Fire2.png");
		std::shared_ptr<Texture> Fire3 = Resources::Load<Texture>(L"Fire3", L"..\\Resources\\Texture\\Fire3.png");
		std::shared_ptr<Texture> Fire4 = Resources::Load<Texture>(L"Fire4", L"..\\Resources\\Texture\\Fire4.png");
		std::shared_ptr<Texture> Fire5 = Resources::Load<Texture>(L"Fire5", L"..\\Resources\\Texture\\Fire5.png");
		std::shared_ptr<Texture> Fire6 = Resources::Load<Texture>(L"Fire6", L"..\\Resources\\Texture\\Fire6.png");
		std::shared_ptr<Texture> Fire7 = Resources::Load<Texture>(L"Fire7", L"..\\Resources\\Texture\\Fire7.png");
		std::shared_ptr<Texture> Fire8 = Resources::Load<Texture>(L"Fire8", L"..\\Resources\\Texture\\Fire8.png");

		at->Create(L"Fire1", Fire1, Vector2(0.0f, 0.0f), Vector2(89.0f, 257.0f), 8, Vector2::Zero, 0.1f);
		at->Create(L"Fire2", Fire2, Vector2(0.0f, 0.0f), Vector2(89.0f, 257.0f), 8, Vector2::Zero, 0.1f);
		at->Create(L"Fire3", Fire3, Vector2(0.0f, 0.0f), Vector2(89.0f, 257.0f), 8, Vector2::Zero, 0.1f);
		at->Create(L"Fire4", Fire4, Vector2(0.0f, 0.0f), Vector2(89.0f, 257.0f), 8, Vector2::Zero, 0.1f);
		at->Create(L"Fire5", Fire5, Vector2(0.0f, 0.0f), Vector2(89.0f, 257.0f), 8, Vector2::Zero, 0.1f);
		at->Create(L"Fire6", Fire6, Vector2(0.0f, 0.0f), Vector2(89.0f, 257.0f), 8, Vector2::Zero, 0.1f);
		at->Create(L"Fire7", Fire7, Vector2(0.0f, 0.0f), Vector2(89.0f, 257.0f), 8, Vector2::Zero, 0.1f);
		at->Create(L"Fire8", Fire8, Vector2(0.0f, 0.0f), Vector2(89.0f, 257.0f), 8, Vector2::Zero, 0.1f);


		//at->PlayAnimation(L"Fire1", true);
	}
	void RootaByssFireScript::Update()
	{
	}
}

