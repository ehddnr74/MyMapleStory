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

		void SetCameraScript(class CameraScript* cs) { mCameraScript = cs; }
		CameraScript* GetCameraScript() { return mCameraScript; }

		void SetInventoryScript(class InventoryScript* is) { mInventoryScript = is; }
		InventoryScript* GetInventoryScript() { return mInventoryScript; }

		void SetShop(bool shop) { Shop = shop; }
		bool GetShop() { return Shop; }

		void SetIsBuy(bool ib) { isBuy = ib; }

		void SetShop1(GameObject* shop1) { mShop1 = shop1; }
		void SetShop2(GameObject* shop2) { mShop2 = shop2; }
		void SetShop3(GameObject* shop3) { mShop3 = shop3; }
		void SetShopHavis(GameObject* shophavis) { mShopHavis = shophavis; }
		void SetShopPlayer(GameObject* shopplayer) { mShopPlayer = shopplayer; }
		void SetShopBuy(GameObject* shopbuy) { mShopBuy = shopbuy; }
		void SetShopSell(GameObject* shopsell) { mShopSell = shopsell; }
		void SetShopExit(GameObject* shopexit) { mShopExit = shopexit; }
		void SetShopEtc(GameObject* shopetc) { mShopEtc = shopetc; }
		void SetShopEtc2(GameObject* shopetc2) { mShopEtc2 = shopetc2; }
		void SetShopMesoBox(GameObject* shopmesobox) { mShopMesoBox = shopmesobox; }
		void SetShopRootaByssKey(GameObject* shoprootabysskey) { mRootaByssKey = shoprootabysskey; }
		void SetShopPowerPortion(GameObject* shoppowerportion) { mPowerPortion = shoppowerportion; }


		void SetRootaByssKeySelect(GameObject* rk) { mRootaByssKeySelect = rk; }
		void SetSelctRootaByssKey(GameObject* srk) { mSelectRootaByssKey = srk; }
		void SetSelectRootByssKeyMeso(GameObject* srkm) { mSelectRootaByssMeso = srkm; }

		void SetPowerPortionSelect(GameObject* pp) { mPowerPortionSelect = pp; }
		void SetSelctPowerPortion(GameObject* spp) { mSelectPowerPortion = spp; }
		void SetSelectPowerPortionMeso(GameObject* sppm) { mSelectPowerPortionMeso = sppm; }

		void SetShopMeso1(GameObject* shopmeso1) { mShopMeso1 = shopmeso1; }
		void SetShopMeso2(GameObject* shopmeso2) { mShopMeso2 = shopmeso2; }

		void OnShop();
		void CloseShop();

		void Buy();

		void SetLookingShop(bool look) { LookingShop = look; }

		void RootaByssKeySelect();
		void PowerPortionSelect();

	private:
		Animator* at;
		HavisState mHavisState;
		Transform* tr;
		Vector3 pos;
		class PlayerScript* mPScript;
		class CameraScript* mCameraScript;
		class InventoryScript* mInventoryScript;

	private:
		void stand();

	private:
		GameObject* mShop1;
		GameObject* mShop2;
		GameObject* mShop3;
		GameObject* mShopHavis;
		GameObject* mShopPlayer;
		GameObject* mShopBuy;
		GameObject* mShopSell;
		GameObject* mShopExit;
		GameObject* mShopEtc;
		GameObject* mShopEtc2;
		GameObject* mShopMesoBox;

		GameObject* mShopMeso1;
		GameObject* mShopMeso2;

		GameObject* mRootaByssKey;
		GameObject* mRootaByssKeySelect;
		GameObject* mSelectRootaByssKey;
		GameObject* mSelectRootaByssMeso;

		GameObject* mPowerPortion;
		GameObject* mPowerPortionSelect;
		GameObject* mSelectPowerPortion;
		GameObject* mSelectPowerPortionMeso;


		bool Shop;

		bool LookingShop;
		bool rootabysskeyselect;
		bool powerportionselect;

		bool isBuy;
	};
}

