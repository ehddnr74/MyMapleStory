#pragma once
#include "..\Engine_SOURCE\yaScene.h"

namespace ya
{
	class HenesisScene : public Scene
	{
	public:
		HenesisScene();
		virtual ~HenesisScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

		void CreateDevide();

		void SetHP(GameObject* hp) { HP = hp; }
		void SetEXP(GameObject* exp) { EXP = exp; }
		void SetSlot(GameObject* slot) { Slot = slot; }
		void SetSlotCover(GameObject* slotcover) { SlotCover = slotcover; }

	private:
		GameObject* HP;
		GameObject* EXP;
		GameObject* Slot;
		GameObject* SlotCover;

	};
}