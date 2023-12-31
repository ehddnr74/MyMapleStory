#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Layer
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Destory();

		void AddGameObject(GameObject* gameObj);
		const std::vector<GameObject*> GetGameObjects() 
		{ 
			return mGameObjects; 
		}
		std::vector<GameObject*> GetDontDestroyGameObjects();
		
	private:
		std::vector<GameObject*> mGameObjects;
		typedef const std::vector<GameObject*>& GameObjects;
		typedef std::vector<GameObject*>::iterator GameObjectIter;
	};
}
