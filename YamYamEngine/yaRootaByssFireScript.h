#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class RootaByssFireScript : public Script
	{
	public:
		RootaByssFireScript();
		~RootaByssFireScript();

		enum class FireScript
		{
			Fire,
		};

		virtual void Initialize() override;
		virtual void Update() override;


	private:
		Animator* at;
		FireScript mFireScript;
		Transform* tr;
		Vector3 pos;
	};
}

