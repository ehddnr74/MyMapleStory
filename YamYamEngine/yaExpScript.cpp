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
		, maxEXP(16.0f) //���� ��Ȯ�� �� �������� 
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

		if (trigger_UpdateEXP) // �� ������ true�� ���, ü�¹��� Scale���� ���δ�.
		{
			if (scale.x >= lerpEnd) // Scale���� ��ǥġ��ŭ �پ����ٸ�
			{
				trigger_UpdateEXP = false; // ��ȣ�� ��������.

				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				//tr->SetPosition(pos.x + (lerpEnd-lerpStart) / 2, pos.y, pos.z);
			}

			else  // ��ǥġ�� ���� �������� �ʾ��� ���(lerpEnd������ ���پ����� ���)
			{
				scale.x += 10.0f * Time::DeltaTime(); // Scale���� ���δ�.
				GetOwner()->GetComponent<Transform>()->SetScale(scale.x, scale.y, scale.z);


				if (scale.x > 16.0f) // ���̴ٰ� -���� �Ƿ��Ұ�� 0���� ����.
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
		// �ǰݹ޾������(OnDamage �����), ü�¹� ������Ʈ


		EXP += damage;

		//if (hp <= 0)
		//{s
		//	hp = 0;
		//	Die();
		//}
	}

	void ExpScript::UpdateExpBar(float beforeExp, float afterExp)
	{
		trigger_UpdateEXP = true; // true�� ��쿡�� hp�� ��������.
		lerpStart = beforeExp / maxEXP; // ���� �� ��. (�ǰ� �� ü��)
		lerpEnd = afterExp / maxEXP; // ���� ���� ��. (�ǰ� �� ü��)
	}


}