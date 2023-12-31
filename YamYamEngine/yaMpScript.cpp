#include "yaMpScript.h"
#include "yaCollider2D.h"
#include "yaObject.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"

namespace ya
{
	MpScript::MpScript()
		: trigger_UpdateMP(false)
		, lerpStart(0.f)
		, lerpEnd(0.f)
		, maxMP(2000.0f)
		, MP(2000.0f)
		, scale(Vector3(0.0f, 0.0f, 0.0f))
	{
	}
	MpScript::~MpScript()
	{
	}
	void MpScript::Initialize()
	{

	}
	void MpScript::Update()
	{
		scale = GetOwner()->GetComponent<Transform>()->GetScale();

		if (trigger_UpdateMP) // 이 변수가 true일 경우, 체력바의 Scale값을 줄인다.
		{
			if (scale.x <= lerpEnd) // Scale값이 목표치만큼 줄어들었다면
			{
				trigger_UpdateMP = false; // 신호를 꺼버린다.

				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				tr->SetPosition(pos.x - (lerpStart - lerpEnd) / 2, pos.y, pos.z);
			}

			else  // 목표치에 아직 도달하지 않았을 경우(lerpEnd값까지 안줄어들었을 경우)
			{
				scale.x -= 0.1f * Time::DeltaTime(); // Scale값을 줄인다.
				GetOwner()->GetComponent<Transform>()->SetScale(scale.x, scale.y, scale.z);


				if (scale.x < 0.0f) // 줄이다가 -값이 되려할경우 0으로 고정.
				{
					scale.x = 0.0f;
					GetOwner()->GetComponent<Transform>()->SetScale(scale.x, scale.y, scale.z);
				}
			}
		}

	}

	void MpScript::OnDamage(float damage)
	{
		//if (isDie) return;

		UpdateMpBar(MP, MP - damage);
		// 피격받았을경우(OnDamage 실행시), 체력바 업데이트


		MP -= damage;

		//if (hp <= 0)
		//{
		//	hp = 0;
		//	Die();
		//}
	}

	void MpScript::UpdateMpBar(float beforeMp, float afterMp)
	{
		trigger_UpdateMP = true; // true일 경우에만 hp값 변동가능.
		lerpStart = beforeMp / maxMP; // 변동 전 값. (피격 전 체력)
		lerpEnd = afterMp / maxMP; // 변동 후의 값. (피격 후 체력)
	}


}