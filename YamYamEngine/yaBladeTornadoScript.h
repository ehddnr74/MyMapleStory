//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class BladeTornadoScript : public Script
	{
	public:
		BladeTornadoScript();
		~BladeTornadoScript();

		enum class SkillState
		{
			BladeTornado,
			RightBladeTornado,
		};


		virtual void Initialize() override;
		virtual void Update() override;

		void SetRightBladeTornado(bool rbt) { Rightbladetornado = rbt; }

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		Animator* at;
		SkillState mSkillState;
		Transform* tr;
		Vector3 pos;

		Vector3 BladePos;

	private:
		void bladetornado();
		void rightbladetornado();



	private:
		bool Leftbladetornado;
		bool Rightbladetornado;

		double bladetornadotime1;
		bool bladetornadotime2;
	};
}
