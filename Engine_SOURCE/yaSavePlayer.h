#pragma once
#include "yaGameObject.h"

namespace ya 
{
	class SavePlayer : public GameObject
	{
	public:
		SavePlayer();
		~SavePlayer();


		static void SetPlayer(GameObject* mplayer) { mPlayer = mplayer; }
		static GameObject* GetPlayer() { return mPlayer; }


	private:
		static GameObject* mPlayer;


	};
}

