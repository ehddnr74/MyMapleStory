#include "yaHpScript.h"
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
	HpScript::HpScript()
		: trigger_UpdateHP(false)
		, lerpStart(0.f)
		, lerpEnd(0.f)
		, maxHP(2000.0f)
		, HP(2000.0f)
		, scale(Vector3(0.0f,0.0f,0.0f))
	{
	}
	HpScript::~HpScript()
	{
	}
	void HpScript::Initialize()
	{

	}
	void HpScript::Update()
	{
		scale = GetOwner()->GetComponent<Transform>()->GetScale();

		if (trigger_UpdateHP) // �� ������ true�� ���, ü�¹��� Scale���� ���δ�.
		{
			if (scale.x <= lerpEnd) // Scale���� ��ǥġ��ŭ �پ����ٸ�
			{
				trigger_UpdateHP = false; // ��ȣ�� ��������.

				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				tr->SetPosition(pos.x - (lerpStart - lerpEnd) / 2, pos.y, pos.z);
			}

			else  // ��ǥġ�� ���� �������� �ʾ��� ���(lerpEnd������ ���پ����� ���)
			{
				scale.x -= 100.0f * Time::DeltaTime(); // Scale���� ���δ�.
				GetOwner()->GetComponent<Transform>()->SetScale(scale.x,scale.y,scale.z);


				if (scale.x < 0.0f) // ���̴ٰ� -���� �Ƿ��Ұ�� 0���� ����.
				{
					scale.x = 0.0f;
					GetOwner()->GetComponent<Transform>()->SetScale(scale.x, scale.y, scale.z);
				}
			}
		}

	}

	void HpScript::OnDamage(float damage)
	{
		//if (isDie) return;

		UpdateHpBar(HP, HP - damage);
		// �ǰݹ޾������(OnDamage �����), ü�¹� ������Ʈ


		HP -= damage;

		//if (hp <= 0)
		//{
		//	hp = 0;
		//	Die();
		//}
	}

	void HpScript::UpdateHpBar(float beforeHp, float afterHp)
	{
		trigger_UpdateHP = true; // true�� ��쿡�� hp�� ��������.
		lerpStart = beforeHp / maxHP; // ���� �� ��. (�ǰ� �� ü��)
		lerpEnd = afterHp / maxHP; // ���� ���� ��. (�ǰ� �� ü��)
	}


}