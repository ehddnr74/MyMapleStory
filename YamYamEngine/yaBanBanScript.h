#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class BanBanScript : public Script
	{
	public:
		BanBanScript();
		~BanBanScript();

		enum class BanBanSkill
		{
			Earthquake, //2페이즈 지진
			ForceTeleport, //2페이즈 강제 순간이동 시키기  //3페이즈부턴 무의식의 영역 소환 //이 외에도 운석, 회오리(슈퍼넉백) 등 
		};


		enum class BanBanState
		{
			Zen,
			Idle,
			Move,
			Smacking,
			EnergyBolt,
			EarthQuake,
			BlinkIn,
			BlinkOut,

		};

		virtual void Initialize() override;
		virtual void Update() override;

		void SetPlayerScript(class PlayerScript* playerscript) { mPlayerScript = playerscript; }
		PlayerScript* GetPlayerScript() { return mPlayerScript; }

		void SetBallScript(class BallScript* ballscript) { mBallScript = ballscript; }
		BallScript* GetBallScript() { return mBallScript; }

		void SetLeftBall(GameObject* ball) { mBall = ball; }
		GameObject* GetLeftBall() { return mBall; }

		void SetRightBall(GameObject* ball) { mBall = ball; }
		GameObject* GetRightBall() { return mBall; }


	private:
		BanBanSkill mBanBanSkill;
		Animator* at;
		BanBanState mBanBanState;
		Transform* tr;
		Vector3 pos;

	private:
		void zen();
		void idle();
		void move();
		void smacking();
		void energybolt();
		void earthquake();
		void forceteleport();
		void blinkin();
		void blinkout();


		void CreateLeftBall();
		void CreateRightBall();


	private:
		class PlayerScript* mPlayerScript;
		class BallScript* mBallScript;
		GameObject* mBall;

		bool CreateBall;
		double ballcreatetime;
		double balllifetime;

		int dir;

		double zentime;

		bool smack;
		double smackingtime;

		bool energy;
		double energybolttime;
		double energytime;

		bool eq;
		double earthquaketime;
		double earthtime;

		bool bk;
		double blinktime;
		double btime;

		int randompos;
	};
}
