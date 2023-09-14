#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaCollider2D.h"
#include "yaPlayerScript.h"
#include "yaCamera.h"

namespace ya
{
	Vector3 pos = Vector3::Zero;

	void CameraScript::Update()
	{
		if (Camera::GetTarget() != nullptr && Camera::GetHeneSisScene() != nullptr)
		{
			mTarget = Camera::GetTarget();

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

			Transform* TargetPos = mTarget->GetComponent<Transform>();

			Vector3 TrPos = TargetPos->GetPosition();

			Vector3 pos = TargetPos->GetPosition();


			if (TrPos.x >= -2.0f && TrPos.x <= 2.0f)
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
			if (TrPos.x < -2.0f)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(
					Vector3{
						mPrevPos.x,
						pos.y + 1.3f,
						GetOwner()->GetComponent<Transform>()->GetPosition().z
					}
				);
			}
			if (TrPos.x >= 2.0f)
			{
				GetOwner()->GetComponent<Transform>()->SetPosition(
					Vector3{
						mPrevPos.x,
						pos.y + 1.3f,
						GetOwner()->GetComponent<Transform>()->GetPosition().z
					}
				);
			}
			
		}

		if (Camera::GetTarget() != nullptr && Camera::GetEastGardenScene() != nullptr)
		{
			mTarget = Camera::GetTarget();

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


