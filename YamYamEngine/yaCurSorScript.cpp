#include "yaCurSorScript.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaCamera.h"
#include "yaMesh.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaAnimator.h"
#include "yaCollider2D.h"
#include "yaObject.h"
#include "yaCameraScript.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaHavisScript.h"

namespace ya
{
	CurSorScript::CurSorScript()
		: CursorChange(false)
		, havis(false)
		, ShopExit(false)
		, KeySelect(false)
		, ShopBuy(false)
		, InventoryClick(false)
		, ShopToInventory(false)
	{
	}

	CurSorScript::~CurSorScript()
	{
	}

	void CurSorScript::Initialize()
	{
		GetOwner()->AddComponent<Animator>();
		Animator* at = GetOwner()->GetComponent<Animator>();

		std::shared_ptr<Texture> None = Resources::Load<Texture>(L"None", L"..\\Resources\\Texture\\Cursor.png");
		std::shared_ptr<Texture> Click = Resources::Load<Texture>(L"RightBall", L"..\\Resources\\Texture\\CursorClick.png");

		at->Create(L"None", None, Vector2(0.0f, 0.0f), Vector2(29.0f, 30.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"Click", Click, Vector2(0.0f, 0.0f), Vector2(30.0f, 28.0f), 1, Vector2::Zero, 0.1f);

		at->PlayAnimation(L"None", false);

		mCursorState = CursorState::None;
	}

	void CurSorScript::Update()
	{
		Vector2 pos = Input::GetMousePos();
		mPos = Vector3(pos.x, pos.y, -10.0f);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		MouseWorldPos = Camera::GetWorldPos(mPos);
		Input::SetMouseWorldPos(mPos);
		tr->SetPosition(Camera::GetWorldPos(mPos));

		if (havis == true)
		{
			GetHavisScript()->SetLookingShop(true);

			if (Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				havis = false;
				GetHavisScript()->OnShop();
				ShopToInventory = true;
			}
		}

		if (ShopExit == true)
		{
			if (Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				ShopExit = false;
				GetHavisScript()->CloseShop();
			}
		}

		if (KeySelect == true)
		{
			if (Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				KeySelect = false;
				GetHavisScript()->RootaByssKeySelect();
			}
		}

		if (ShopBuy == true)
		{
			if (Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				ShopBuy = false;
				GetHavisScript()->SetIsBuy(true);
				GetHavisScript()->Buy();
			}
		}

		switch (mCursorState)
		{
		case CursorState::None:
			none();
			break;
		case CursorState::Click:
			click();
			break;
		default:
			break;
		}
	}

	void CurSorScript::OnCollisionEnter(Collider2D* other)
	{
		//if (other->GetOwner()->GetName() == L"Portal3")
		//{
		//	SceneManager::LoadScene(L"BanBanScene");
		//}
		if (other->GetOwner()->GetName() == L"Havis")
		{
			havis = true;
		}

		if (other->GetOwner()->GetName() == L"RootaByssKey")
		{
			KeySelect = true;
		}

		if (other->GetOwner()->GetName() == L"ShopExit")
		{
			ShopExit = true;
		}

		if (other->GetOwner()->GetName() == L"ShopBuy")
		{
			ShopBuy = true;
		}
	}

	void CurSorScript::OnCollisionStay(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"mInventory3")
		{
			InventoryClick = true;
		}
	}

	void CurSorScript::OnCollisionExit(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Havis")
		{
			havis = false;
		}

		if (other->GetOwner()->GetName() == L"RootaByssKey")
		{
			KeySelect = false;
		}

		if (other->GetOwner()->GetName() == L"ShopExit")
		{
			ShopExit = false;
		}

		if (other->GetOwner()->GetName() == L"ShopBuy")
		{
			ShopBuy = false;
		}
	}

	void CurSorScript::none()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		if (Input::GetKey(eKeyCode::LBUTTON))
		{
			mCursorState = CursorState::Click;
			at->PlayAnimation(L"Click", false);
		}
	}

	void CurSorScript::click()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();

		if (Input::GetKeyUp(eKeyCode::LBUTTON))
		{
			mCursorState = CursorState::None;
			at->PlayAnimation(L"None", false);
		}

	}

}