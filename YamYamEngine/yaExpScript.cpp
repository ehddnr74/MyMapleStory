#include "yaExpScript.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaCollider2D.h"
#include "yaObject.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"

namespace ya
{
	ExpScript::ExpScript()
		: trigger_UpdateEXP(false)
		, lerpStart(0.f)
		, lerpEnd(0.f)
		, maxEXP(16.0f) //추후 정확한 값 가져오기 
		, EXP(16.0f)
		, scale(Vector3(0.0f, 0.0f, 0.0f))
	{
	}
	ExpScript::~ExpScript()
	{
	}
	void ExpScript::Initialize()
	{

	}
	void ExpScript::Update()
	{
		scale = GetOwner()->GetComponent<Transform>()->GetScale();

		if (trigger_UpdateEXP) // 이 변수가 true일 경우, 체력바의 Scale값을 줄인다.
		{
			if (scale.x >= lerpEnd) // Scale값이 목표치만큼 줄어들었다면
			{
				trigger_UpdateEXP = false; // 신호를 꺼버린다.

				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				//tr->SetPosition(pos.x + (lerpEnd-lerpStart) / 2, pos.y, pos.z);
			}

			else  // 목표치에 아직 도달하지 않았을 경우(lerpEnd값까지 안줄어들었을 경우)
			{
				scale.x += 10.0f * Time::DeltaTime(); // Scale값을 줄인다.
				GetOwner()->GetComponent<Transform>()->SetScale(scale.x, scale.y, scale.z);


				if (scale.x > 16.0f) // 줄이다가 -값이 되려할경우 0으로 고정.
				{
					scale.x = 16.0f;
					GetOwner()->GetComponent<Transform>()->SetScale(scale.x, scale.y, scale.z);
				}
			}
		}

	}

	void ExpScript::OnDamage(float damage)
	{
		//if (isDie) return;

		UpdateExpBar(EXP, EXP + damage);
		// 피격받았을경우(OnDamage 실행시), 체력바 업데이트


		EXP += damage;

		//if (hp <= 0)
		//{s
		//	hp = 0;
		//	Die();
		//}
	}

	void ExpScript::UpdateExpBar(float beforeExp, float afterExp)
	{
		trigger_UpdateEXP = true; // true일 경우에만 hp값 변동가능.
		lerpStart = beforeExp / maxEXP; // 변동 전 값. (피격 전 체력)
		lerpEnd = afterExp / maxEXP; // 변동 후의 값. (피격 후 체력)
	}


}