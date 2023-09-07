#pragma once
#include "yaComponent.h"


namespace ya
{
	class RigidBody : public Component
	{
	public:
		RigidBody();
		~RigidBody();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Release();

		void SetMass(float mass) { mMass = mass; }
		void AddForce(Vector2 force);
		void SetGround(bool ground) { mbGround = ground; }
		bool GetGround() { return mbGround; }
		void SetVelocity(Vector2 velocity) { mVelocity = velocity; }
		Vector2 GetVelocity() { return mVelocity; }
		void SetGravity(Vector2 gravity) { mGravity = gravity; }
		Vector2 GetGravity() { return mGravity; }
		void SetFriction(float mfriction) { mFriction = mfriction; }
		float GetFriction() { return mFriction; }


	private:
		float mMass;
		Vector2 mForce;
		Vector2 mAccelation;
		Vector2 mVelocity;
		Vector2 mLimitedVelocity;

		Vector2 mGravity;
		float mFriction;
		bool mbGround;

		//float mStaticFriction; ����������
		//float mKineticFriction; ������� 
		//float mCoefficientFriction; �����°�� 
		//float mNormalForce; 
	};
}

