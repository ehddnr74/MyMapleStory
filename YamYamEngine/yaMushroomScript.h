#pragma once
#include <yaScript.h>
#include <yaAnimation.h>

namespace ya
{
	class MushroomScript : public Script
	{
	public:
		MushroomScript();
		~MushroomScript();

		enum class MushroomState
		{
			Idle,
		};


		virtual void Initialize() override;
		virtual void Update() override;

		void Complete();

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		Animator* at;
		MushroomState mMushroomState;
		Transform* tr;
		Vector3 pos;
		class Collider2D* cd;

		int dir; // 0 = ¿ÞÂÊ , 1 = ¿À¸¥ÂÊ

	private:
		void Idle();

	private:
	};
}