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

		if (trigger_UpdateMP) // �� ������ true�� ���, ü�¹��� Scale���� ���δ�.
		{
			if (scale.x <= lerpEnd) // Scale���� ��ǥġ��ŭ �پ����ٸ�
			{
				trigger_UpdateMP = false; // ��ȣ�� ��������.

				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				tr->SetPosition(pos.x - (lerpStart - lerpEnd) / 2, pos.y, pos.z);
			}

			else  // ��ǥġ�� ���� �������� �ʾ��� ���(lerpEnd������ ���پ����� ���)
			{
				scale.x -= 1.0f * Time::DeltaTime(); // Scale���� ���δ�.
				GetOwner()->GetComponent<Transform>()->SetScale(scale.x, scale.y, scale.z);


				if (scale.x < 0.0f) // ���̴ٰ� -���� �Ƿ��Ұ�� 0���� ����.
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
		// �ǰݹ޾������(OnDamage �����), ü�¹� ������Ʈ


		MP -= damage;

		//if (hp <= 0)
		//{
		//	hp = 0;
		//	Die();
		//}
	}

	void MpScript::UpdateMpBar(float beforeMp, float afterMp)
	{
		trigger_UpdateMP = true; // true�� ��쿡�� hp�� ��������.
		lerpStart = beforeMp / maxMP; // ���� �� ��. (�ǰ� �� ü��)
		lerpEnd = afterMp / maxMP; // ���� ���� ��. (�ǰ� �� ü��)
	}


}