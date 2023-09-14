#include "yaRigidBody.h"
#include "yaTime.h"
#include "yaGameObject.h"
#include "yaTransform.h"

namespace ya
{
	using namespace ya::math;
	RigidBody::RigidBody()
		: Component(eComponentType::RigidBody)
		, mMass(1.0f)
		, mForce(Vector2::Zero)
		, mAccelation(Vector2::Zero)
		, mVelocity(Vector2::Zero)
	{
		//mLimitedVelocity.x = 200.0f;
		//mLimitedVelocity.y = 1000.0f;
		mbGround = false;
		mGravity = Vector2(0.0f, -6.0f);
		//mFriction = 0.0f;
	}

	RigidBody::~RigidBody()
	{

	}

	void RigidBody::Initialize()
	{

	}

	void RigidBody::Update()
	{
		// F = M * A
		// A = M / F
		mAccelation = mForce / mMass;

		// �ӵ��� ���ӵ��� �����ش�.
		mVelocity += mAccelation * Time::DeltaTime();

		if (mbGround)
		{
			// ������ ������
			Vector2 gravity = mGravity;
			gravity.Normalize();

			float dot = math::Dot(mVelocity, gravity);
			mVelocity -= gravity * dot;
		}
		else
		{
			mVelocity += mGravity * Time::DeltaTime();
		}

		// �߷°��ӵ� �ִ� �ӵ� ����
		Vector2 gravity = mGravity;
		gravity.Normalize();
		float dot = math::Dot(mVelocity, gravity);
		gravity = gravity * dot;

		Vector2 sideVelocity = mVelocity - gravity;
		if (mLimitedVelocity.y < gravity.Length())
		{
			gravity.Normalize();
			gravity *= mLimitedVelocity.y;
		}

		if (mLimitedVelocity.x < sideVelocity.Length())
		{
			sideVelocity.Normalize();
			sideVelocity *= mLimitedVelocity.x;
		}

		//// ������ ���� ( ����� ���� ����, �ӵ��� 0�� �ƴ�)
		//if (!(mVelocity == Vector2::Zero))
		//{
		//	//�ӵ��� �ݴ�������� �������� ����ȴ�.
		//	Vector2 friction = -mVelocity;
		//	friction = friction.Normalize() * mFriction * mMass * Time::DeltaTime();

		//	//���������� ���� �ӵ� ���Ҵ� ���� �ӵ����� ū ���

		//	if (mVelocity.Length() < friction.Length())
		//	{
		//		mVelocity = Vector2::Zero;
		//	}
		//	else
		//	{
		//		mVelocity += friction;
		//	}
		//}

		// �ӵ��� �°Բ� ��ü�� �̵���Ų��.
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		pos = pos + mVelocity * Time::DeltaTime();

		tr->SetPosition(pos);
		//mForce.Clear();
	}

	void RigidBody::LateUpdate()
	{

	}
	void RigidBody::Render()
	{
	}
	void RigidBody::Release()
	{
	}
	void RigidBody::AddForce(Vector2 force)
	{
		mForce += force;
	}
}