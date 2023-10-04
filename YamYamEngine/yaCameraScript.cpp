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
#include "yaInventoryScript.h"

namespace ya
{
	Vector3 pos = Vector3::Zero;

	void CameraScript::Update()
	{
		if (mSkillSlot != nullptr)
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 CameraPos = tr->GetPosition();

			Transform* SkillSlotTr = mSkillSlot->GetComponent<Transform>();
			Vector3 SkillSlotPos = SkillSlotTr->GetPosition();

			SkillSlotTr->SetPosition(
				Vector3{
				CameraPos.x + 2.25f,
				CameraPos.y - 1.93f,
				SkillSlotPos.z
				});
		}


		if (mInventory != nullptr)
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 CameraPos = tr->GetPosition();

			Transform* InventoryTr = mInventory->GetComponent<Transform>();
			Vector3 InventoryPos = InventoryTr->GetPosition();

			InventoryTr->SetPosition(
				Vector3{
				CameraPos.x + 2.8f,
				CameraPos.y + 0.5f,
				InventoryPos.z
				});
		}

		if (Camera::GetTarget() != nullptr && Camera::GetHeneSisScene() != nullptr)
		{
			SceneManager::GetCursorScript()->SetCameraScript(this);
			SceneManager::GetInventoryScript()->SetCameraScript(this);
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
			SceneManager::GetCursorScript()->SetCameraScript(this);

			//SceneManager::GetInventoryScript()->SetCameraScript(this);

			mTarget = Camera::GetTarget();
			SceneManager::GetPlayerScript()->SetCameraScript(this);

			Transform* TargetPos = mTarget->GetComponent<Transform>();

			Vector3 TrPos = TargetPos->GetPosition();

			Vector3 pos = TargetPos->GetPosition();

			//Ypos.y = pos.y + 1.3f;

			if (TrPos.x >= -2.0f && TrPos.x <= 2.0f && TrPos.y <= -1.35f)
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
			}

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
			SceneManager::GetCursorScript()->SetCameraScript(this);
			mTarget = Camera::GetTarget();
			SceneManager::GetPlayerScript()->SetCameraScript(this);

			Transform* TargetPos = mTarget->GetComponent<Transform>();

			Vector3 TrPos = TargetPos->GetPosition();

			Vector3 pos = TargetPos->GetPosition();


			if (TrPos.x >= -4.5f && TrPos.x <= 4.5f && TrPos.y <= -0.725f)
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

			if (TrPos.x >= -4.5f && TrPos.x <= 4.5f && TrPos.y >= -0.725f)
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
			}

			if (TrPos.x >= 4.5f && TrPos.y <= -0.728f)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(
					Vector3{
						mPrevPos.x,
						pos.y + 1.3f,
						GetOwner()->GetComponent<Transform>()->GetPosition().z
					}
				);
			}

			if (TrPos.x < -4.5f && TrPos.y >= -0.728f)
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

		if (Camera::GetTarget() != nullptr && Camera::GetBanBanScene() != nullptr)
		{
			SceneManager::GetCursorScript()->SetCameraScript(this);
			mTarget = Camera::GetTarget();
			SceneManager::GetPlayerScript()->SetCameraScript(this);

			Transform* TargetPos = mTarget->GetComponent<Transform>();

			Vector3 TrPos = TargetPos->GetPosition();

			Vector3 pos = TargetPos->GetPosition();


			if (TrPos.x >= -1.2f && TrPos.x <= 1.2f && TrPos.y <= -1.05f)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(
					Vector3{
						pos.x,
						pos.y + 1.5f,
						GetOwner()->GetComponent<Transform>()->GetPosition().z
					}
				);
				Transform* tr = GetOwner()->GetComponent<Transform>();
				mPrevPos = tr->GetPosition();
			}

			if (TrPos.x >= -1.2f && TrPos.x <= 1.2f && TrPos.y >= -1.05f)
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
			}

			if (TrPos.x >= -1.2f && TrPos.y <= -1.05f)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(
					Vector3{
						mPrevPos.x,
						pos.y + 1.5f,
						GetOwner()->GetComponent<Transform>()->GetPosition().z
					}
				);
			}

			if (TrPos.x < -1.2f && TrPos.y >= -1.05f)
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


