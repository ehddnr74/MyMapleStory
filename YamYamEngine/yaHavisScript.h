#pragma once
//#include "MyScript.h"
#include <yaScript.h>
#include <yaAnimation.h>


namespace ya
{
	class HavisScript : public Script
	{
	public:
		HavisScript();
		~HavisScript();

		enum class HavisState
		{
			Stand,
		};

		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void SetPlayerScript(class PlayerScript* mps) { mPScript = mps; }
		PlayerScript* GetPlayerScript() { return mPScript; }

		void SetShop(GameObject* shop) { mShop = shop; }
		void SetShop2(GameObject* shop2) { mShop2 = shop2; }
		void SetShop3(GameObject* shop3) { mShop3 = shop3; }
		void SetShopHavis(GameObject* shophavis) { mShopHavis = shophavis; }
		void SetShopPlayer(GameObject* shopplayer) { mShopPlayer = shopplayer; }
		void SetShopBuy(GameObject* shopbuy) { mShopBuy = shopbuy; }
		void SetShopSell(GameObject* shopsell) { mShopSell = shopsell; }
		void SetShopExit(GameObject* shopexit) { mShopExit = shopexit; }
		void SetShopEtc(GameObject* shopetc) { mShopEtc = shopetc; }
		void SetShopEtc2(GameObject* shopetc2) { mShopEtc2 = shopetc2; }
		void SetShopRootaByssKey(GameObject* shoprootabysskey) { mRootaByssKey = shoprootabysskey; }

		void OnShop();
		void CloseShop();

		void SetLookingShop(bool look) { LookingShop = look; }

	private:
		Animator* at;
		HavisState mHavisState;
		Transform* tr;
		Vector3 pos;
		class PlayerScript* mPScript;

	private:
		void stand();

	private:
		GameObject* mShop;
		GameObject* mShop2;
		GameObject* mShop3;
		GameObject* mShopHavis;
		GameObject* mShopPlayer;
		GameObject* mShopBuy;
		GameObject* mShopSell;
		GameObject* mShopExit;
		GameObject* mShopEtc;
		GameObject* mShopEtc2;
		GameObject* mRootaByssKey;

		bool LookingShop;
	};
}

