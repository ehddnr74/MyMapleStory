#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaCollider2D.h"
#include "yaPlayerScript.h"
#include "yaCamera.h"
#include "yaRootaByssScene.h"
#include "yaSceneManager.h"
#include "yaHavisScript.h"
#include "yaCurSorScript.h"

namespace ya
{
	Vector3 pos = Vector3::Zero;

	void CameraScript::Update()
	{
		if (mInventory1 != nullptr && mHavisScript != nullptr)
		{
			if (mHavisScript->GetShop())
			{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 CameraPos = tr->GetPosition();

				Transform* Inventory1tr = mInventory1->GetComponent<Transform>();
				Vector3 Inventory1Pos = Inventory1tr->GetPosition();

				Inventory1tr->SetPosition(
					Vector3{
						CameraPos.x + 2.7f,
						CameraPos.y + 0.68f,
						Inventory1Pos.z
					}
				);
			}
		}

		if (mInventory1 != nullptr && mHavisScript == nullptr)
		{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 CameraPos = tr->GetPosition();

				Transform* Inventory1tr = mInventory1->GetComponent<Transform>();
				Vector3 Inventory1Pos = Inventory1tr->GetPosition();

				Inventory1tr->SetPosition(
					Vector3{
						CameraPos.x + 1.0f,
						CameraPos.y + 0.68f,
						Inventory1Pos.z
					}
				);
			}

		if (mInventory2 != nullptr && mHavisScript != nullptr)
		{
			if (mHavisScript->GetShop())
			{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 CameraPos = tr->GetPosition();

				Transform* Inventory2tr = mInventory2->GetComponent<Transform>();
				Vector3 Inventory2Pos = Inventory2tr->GetPosition();

				Inventory2tr->SetPosition(
					Vector3{
					CameraPos.x + 2.7f,
					CameraPos.y + 0.38f,
					Inventory2Pos.z
					}
				);
			}
		}

		if (mInventory2 != nullptr && mHavisScript == nullptr)
		{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 CameraPos = tr->GetPosition();

				Transform* Inventory2tr = mInventory2->GetComponent<Transform>();
				Vector3 Inventory2Pos = Inventory2tr->GetPosition();

				Inventory2tr->SetPosition(
					Vector3{
					CameraPos.x + 1.0f,
					CameraPos.y + 0.38f,
					Inventory2Pos.z
					}
				);
			}

		if (mInventory3 != nullptr && mHavisScript != nullptr)
		{
			if (mHavisScript->GetShop())
			{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 CameraPos = tr->GetPosition();

				Transform* Inventory3tr = mInventory3->GetComponent<Transform>();
				Vector3 Inventory3Pos = Inventory3tr->GetPosition();

				Inventory3tr->SetPosition(
					Vector3{
						CameraPos.x + 2.7f,
						CameraPos.y + 0.5f,
						Inventory3Pos.z
					}
				);
			}
		}

		if (mInventory3 != nullptr && mHavisScript == nullptr)
		{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 CameraPos = tr->GetPosition();

				Transform* Inventory3tr = mInventory3->GetComponent<Transform>();
				Vector3 Inventory3Pos = Inventory3tr->GetPosition();

				Inventory3tr->SetPosition(
					Vector3{
						CameraPos.x + 1.0f,
						CameraPos.y + 0.5f,
						Inventory3Pos.z
					}
				);
			}

		if (mInventoryEtc != nullptr && mHavisScript != nullptr)
		{
			if (mHavisScript->GetShop())
			{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 CameraPos = tr->GetPosition();

				Transform* InventoryEtctr = mInventoryEtc->GetComponent<Transform>();
				Vector3 InventoryEtcPos = InventoryEtctr->GetPosition();

				InventoryEtctr->SetPosition(
					Vector3{
						CameraPos.x + 2.58f,
						CameraPos.y + 1.67f,
						InventoryEtcPos.z
					}
				);
			}
		}

		if (mInventoryEtc != nullptr && mHavisScript == nullptr)
		{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 CameraPos = tr->GetPosition();

				Transform* InventoryEtctr = mInventoryEtc->GetComponent<Transform>();
				Vector3 InventoryEtcPos = InventoryEtctr->GetPosition();

				InventoryEtctr->SetPosition(
					Vector3{
						CameraPos.x + 0.88f,
						CameraPos.y + 1.67f,
						InventoryEtcPos.z
					}
				);
			}

		if (mInventoryMeso != nullptr && mHavisScript != nullptr)
		{
			if (mHavisScript->GetShop())
			{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 CameraPos = tr->GetPosition();

				Transform* InventoryMesotr = mInventoryMeso->GetComponent<Transform>();
				Vector3 InventoryMesoPos = InventoryMesotr->GetPosition();

				InventoryMesotr->SetPosition(
					Vector3{
						CameraPos.x + 2.175f,
						CameraPos.y - 0.37f,
						InventoryMesoPos.z
					}
				);
			}
		}

		if (mInventoryMeso != nullptr && mHavisScript == nullptr)
		{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 CameraPos = tr->GetPosition();

				Transform* InventoryMesotr = mInventoryMeso->GetComponent<Transform>();
				Vector3 InventoryMesoPos = InventoryMesotr->GetPosition();

				InventoryMesotr->SetPosition(
					Vector3{
						CameraPos.x + 0.475f,
						CameraPos.y - 0.37f,
						InventoryMesoPos.z
					}
				);
			}

		if (mInventoryMesoBar != nullptr && mHavisScript != nullptr)
		{
			if (mHavisScript->GetShop())
			{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 CameraPos = tr->GetPosition();

				Transform* InventoryMesoBartr = mInventoryMesoBar->GetComponent<Transform>();
				Vector3 InventoryMesoBarPos = InventoryMesoBartr->GetPosition();

				InventoryMesoBartr->SetPosition(
					Vector3{
						CameraPos.x + 2.9f,
						CameraPos.y - 0.38f,
						InventoryMesoBarPos.z
					}
				);
			}
		}

		if (mInventoryMesoBar != nullptr && mHavisScript == nullptr)
		{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 CameraPos = tr->GetPosition();

				Transform* InventoryMesoBartr = mInventoryMesoBar->GetComponent<Transform>();
				Vector3 InventoryMesoBarPos = InventoryMesoBartr->GetPosition();

				InventoryMesoBartr->SetPosition(
					Vector3{
						CameraPos.x + 1.2f,
						CameraPos.y - 0.38f,
						InventoryMesoBarPos.z
					}
				);
			}

		if (Camera::GetTarget() != nullptr && Camera::GetHeneSisScene() != nullptr)
		{
			mTarget = Camera::GetTarget();
			SceneManager::GetPlayerScript()->SetCameraScript(this);

			Transform* TargetPos = mTarget->GetComponent<Transform>();

			Vector3 TrPos = TargetPos->GetPosition();

			Vector3 pos = TargetPos->GetPosition();


			if (TrPos.x >= -8.0f && TrPos.x <= 8.0f)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(
					Vector3{
						pos.x,
						pos.y + 0.8f,
						GetOwner()->GetComponent<Transform>()->GetPosition().z
					}
				);
			}
		}

		if (Camera::GetTarget() != nullptr && Camera::GetRootaByssScene() != nullptr)
		{
			mTarget = Camera::GetTarget();
			SceneManager::GetPlayerScript()->SetCameraScript(this);

			Transform* TargetPos = mTarget->GetComponent<Transform>();

			Vector3 TrPos = TargetPos->GetPosition();

			Vector3 pos = TargetPos->GetPosition();

		    //Ypos.y = pos.y + 1.3f;

			if (TrPos.x >= -2.0f && TrPos.x <= 2.0f && TrPos.y <=-1.35f)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(
					Vector3{
						pos.x,
						pos.y + 1.3f,
						GetOwner()->GetComponent<Transform>()->GetPosition().z
					}
				);
				Transform* tr = GetOwner()->GetComponent<Transform>();
				mPrevPos = tr->GetPosition();
			}

			if (TrPos.x >= -2.0f && TrPos.x <= 2.0f && TrPos.y >= -1.35f)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(
					Vector3{
						pos.x,
						mPrevPos.y,
						GetOwner()->GetComponent<Transform>()->GetPosition().z
					}
				);
				Transform* tr = GetOwner()->GetComponent<Transform>();
				mPrevPos = tr->GetPosition();

				int a = 0;
			}

			//if (TrPos.y >= -1.299f)
			//{
			//	GetOwner()->GetComponent<Transform>()->SetPosition(
			//		Vector3{
			//			mPrevPos.x,
			//			mPrevPos.y,
			//			GetOwner()->GetComponent<Transform>()->GetPosition().z
			//		}
			//	);
			//}

			if (TrPos.x >= 2.0f && TrPos.y <= -1.35f)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(
					Vector3{
						mPrevPos.x,
						pos.y + 1.3f,
						GetOwner()->GetComponent<Transform>()->GetPosition().z
					}
				);
			}

			if (TrPos.x < -2.0f && TrPos.y >= -1.35f)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(
					Vector3{
						mPrevPos.x,
						mPrevPos.y,
						GetOwner()->GetComponent<Transform>()->GetPosition().z
					}
				);
			}


			
		}

		if (Camera::GetTarget() != nullptr && Camera::GetEastGardenScene() != nullptr)
		{
			mTarget = Camera::GetTarget();
			SceneManager::GetPlayerScript()->SetCameraScript(this);

			Transform* TargetPos = mTarget->GetComponent<Transform>();

			Vector3 TrPos = TargetPos->GetPosition();

			Vector3 pos = TargetPos->GetPosition();


			if (TrPos.x >= -4.5f && TrPos.x <= 4.5f)
			{
				mPrevPos = pos;

				GetOwner()->GetComponent<Transform>()->SetPosition(
					Vector3{
						pos.x,
						pos.y + 1.25f,
						GetOwner()->GetComponent<Transform>()->GetPosition().z
					}
				);
			}
			if (TrPos.x <= -4.5f || TrPos.x >= 4.5f)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(
					Vector3{
						mPrevPos.x,
						pos.y + 1.25f,
						GetOwner()->GetComponent<Transform>()->GetPosition().z
					}
				);
			}
		}

		if (Camera::GetTarget() != nullptr && Camera::GetBanBanScene() != nullptr)
		{
			mTarget = Camera::GetTarget();
			SceneManager::GetPlayerScript()->SetCameraScript(this);

			Transform* TargetPos = mTarget->GetComponent<Transform>();

			Vector3 TrPos = TargetPos->GetPosition();

			Vector3 pos = TargetPos->GetPosition();


			if (TrPos.x >= -1.2f && TrPos.x <= 1.2f)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(
					Vector3{
						pos.x,
						pos.y + 1.55f,
						GetOwner()->GetComponent<Transform>()->GetPosition().z
					}
				);
				//mPrevPos = GetOwner()->GetComponent<Transform>()->GetPosition();
			}
			//if (TrPos.x < -1.2f || TrPos.x > 1.2f)
			//{
			//	GetOwner()->GetComponent<Transform>()->SetPosition(
			//		Vector3{
			//			mPrevPos.x,
			//			pos.y + 1.25f,
			//			GetOwner()->GetComponent<Transform>()->GetPosition().z
			//		}
			//	);
			//}
		}
	}
}




//if (Camera::GetTarget() != nullptr)
//{
//	mTarget = Camera::GetTarget();

//	Transform* TargetPos = mTarget->GetComponent<Transform>();

//	Vector3 pos = TargetPos->GetPosition();

//	GetOwner()->GetComponent<Transform>()->SetPosition(
//		Vector3{
//			pos.x,
//			pos.y + 0.5f,
//			GetOwner()->GetComponent<Transform>()->GetPosition().z
//		}


//	);



	//Transform* tr = GetOwner()->GetComponent<Transform>();
	//Vector3 pos = tr->GetPosition();


	//if (Input::GetKey(eKeyCode::W))
	//{
	//	pos.z += 5.0f * Time::DeltaTime();
	//	tr->SetPosition(pos);
	//}
	//else if (Input::GetKey(eKeyCode::S))
	//{
	//	pos.z -= 5.0f * Time::DeltaTime();
	//	tr->SetPosition(pos);
	//}
	//else if (Input::GetKey(eKeyCode::A))
	//{
	//	pos.x -= 5.0f * Time::DeltaTime();
	//	tr->SetPosition(pos);
	//}
	//else if (Input::GetKey(eKeyCode::D))
	//{
	//	pos.x += 5.0f * Time::DeltaTime();
	//	tr->SetPosition(pos);
	//}
	//else if (Input::GetKey(eKeyCode::Q))
	//{
	//	pos.y -= 5.0f * Time::DeltaTime();
	//	tr->SetPosition(pos);
	//}
	//else if (Input::GetKey(eKeyCode::E))
	//{
	//	pos.y += 5.0f * Time::DeltaTime();
	//	tr->SetPosition(pos);
	//}


