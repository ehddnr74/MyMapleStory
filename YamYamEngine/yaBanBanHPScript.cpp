#include "yaBanBanHPScript.h"
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
	BanBanHPScript::BanBanHPScript()
		: trigger_UpdateHP(false)
		, lerpStart(0.f)
		, lerpEnd(0.f)
		, maxHP(700000.0f)
		, HP(700000.0f)
		, scale(Vector3(0.0f, 0.0f, 0.0f))
	{
	}
	BanBanHPScript::~BanBanHPScript()
	{
	}
	void BanBanHPScript::Initialize()
	{

	}
	void BanBanHPScript::Update()
	{
		scale = GetOwner()->GetComponent<Transform>()->GetScale();

		if (trigger_UpdateHP) // �� ������ true�� ���, ü�¹��� Scale���� ���δ�.
		{
			if (scale.x -3.28f <= lerpEnd) // Scale���� ��ǥġ��ŭ �پ����ٸ�
			{
				trigger_UpdateHP = false; // ��ȣ�� ��������.

				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				tr->SetPosition(pos.x - (lerpStart - lerpEnd) / 2, pos.y, pos.z);
			}

			else  // ��ǥġ�� ���� �������� �ʾ��� ���(lerpEnd������ ���پ����� ���)
			{
				scale.x -= 2.0f * Time::DeltaTime(); // Scale���� ���δ�.
				GetOwner()->GetComponent<Transform>()->SetScale(scale.x, scale.y, scale.z);


				if (scale.x < 0.0f) // ���̴ٰ� -���� �Ƿ��Ұ�� 0���� ����.
				{
					scale.x = 0.0f;
					GetOwner()->GetComponent<Transform>()->SetScale(scale.x, scale.y, scale.z);
				}
			}
		}

	}

	void BanBanHPScript::OnDamage(float damage)
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

	void BanBanHPScript::UpdateHpBar(float beforeHp, float afterHp)
	{
		trigger_UpdateHP = true; // true�� ��쿡�� hp�� ��������.
		lerpStart = beforeHp / maxHP; // ���� �� ��. (�ǰ� �� ü��)
		lerpEnd = afterHp / maxHP; // ���� ���� ��. (�ǰ� �� ü��)
	}


}