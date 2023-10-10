#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>

namespace ya
{
	class FadeIn : public Script
	{
	public:
		FadeIn();
		~FadeIn();

		virtual void Initialize() override;
		virtual void Update() override;


	private:
		Animator* at;
		Transform* tr;
		Vector3 pos;
	};
}
