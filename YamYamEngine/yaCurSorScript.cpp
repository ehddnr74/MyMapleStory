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
#include "yaInventoryScript.h"
#include "yaAudioListener.h"
#include "yaAudioClip.h"
#include "yaAudioSource.h"

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
		, PortionSelect(false)
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
		std::shared_ptr<Texture> Click = Resources::Load<Texture>(L"CursorClick", L"..\\Resources\\Texture\\CursorClick.png");

		at->Create(L"None", None, Vector2(0.0f, 0.0f), Vector2(29.0f, 30.0f), 1, Vector2::Zero, 0.1f);
		at->Create(L"CursorClick", Click, Vector2(0.0f, 0.0f), Vector2(30.0f, 28.0f), 1, Vector2::Zero, 0.1f);

		at->PlayAnimation(L"None", false);

		mCursorState = CursorState::None;
	}

	void CurSorScript::Update()
	{
		if (mCameraScript != nullptr)
		{
			Vector2 pos = Input::GetMousePos();
			mPos = Vector3(pos.x, pos.y, -10.0f);

			Transform* Cameratr = mCameraScript->GetOwner()->GetComponent<Transform>();
			Vector3 CameraPos = Cameratr->GetPosition();

			Transform* tr = GetOwner()->GetComponent<Transform>();
			MouseWorldPos = Camera::GetWorldPos(mPos);
			Input::SetMouseWorldPos(mPos);

			tr->SetPosition(
				Vector3
				{ CameraPos.x + MouseWorldPos.x,
				 CameraPos.y + MouseWorldPos.y,
				 mPos.z
				});


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

			if (PortionSelect == true)
			{
				if (Input::GetKeyDown(eKeyCode::LBUTTON))
				{
					PortionSelect = false;
					GetHavisScript()->PowerPortionSelect();
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

			//if (InventoryClick == true)
			//{
			//	if (Input::GetKey(eKeyCode::LBUTTON))
			//	{
			//		Transform* tr = GetOwner()->GetComponent<Transform>();
			//		Vector3 Pos = tr->GetPosition();

			//		Transform* InvenTr = SceneManager::GetInventoryScript()->GetOwner()->GetComponent<Transform>();
			//		Vector3 InvenPos = InvenTr->GetPosition();

			//		InvenTr->SetPosition(
			//			Vector3(Pos.x,
			//				Pos.y,
			//				InvenPos.z
			//			));
			//	}
			//	if (Input::GetKeyUp(eKeyCode::LBUTTON))
			//	{
			//		InventoryClick = false;
			//	}
			//}




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

		if (other->GetOwner()->GetName() == L"PowerPortion")
		{
			PortionSelect = true;
		}

		if (other->GetOwner()->GetName() == L"ShopExit")
		{
			ShopExit = true;
		}

		if (other->GetOwner()->GetName() == L"ShopBuy")
		{
			ShopBuy = true;
		}

		if (other->GetOwner()->GetName() == L"Slot")
		{
			int a = 0;
		}
	}

	void CurSorScript::OnCollisionStay(Collider2D* other)
	{
		//if (other->GetOwner()->GetName() == L"mInventoryClickCol")
		//{
		//	InventoryClick = true;
		//}
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
		if (other->GetOwner()->GetName() == L"PowerPortion")
		{
			PortionSelect = false;
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
			AudioSource* as = GetOwner()->AddComponent<AudioSource>();
			as->SetClip(Resources::Load<AudioClip>(L"BtMouseClick", L"..\\Resources\\Sound\\BtMouseClick.mp3"));
			as->Play();
			mCursorState = CursorState::Click;
			at->PlayAnimation(L"CursorClick", false);
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