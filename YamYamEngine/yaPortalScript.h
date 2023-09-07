#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class PortalScript : public Script
	{
	public:
		PortalScript();
		~PortalScript();

		enum class PortalState
		{
			Portal,
		};

		virtual void Initialize() override;
		virtual void Update() override;


	private:
		Animator* at;
		PortalState mPortalState;
		Transform* tr;
		Vector3 pos;

	private:
		void portal();


	private:
	};
}

