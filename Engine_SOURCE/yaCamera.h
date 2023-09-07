#pragma once
#include "yaComponent.h"
#include "yaGraphics.h"
#include "yaScene.h"

namespace ya
{
	class Camera : public Component
	{
	public:
		enum class eProjectionType
		{
			Perpective,
			OrthoGraphic,
			None,
		};

		static Matrix& GetGpuViewMatrix() { return View; }
		static void SetGpuViewMatrix(Matrix view) { View = view; }
		static Matrix& GetGpuProjectionMatrix() { return Projection; }
		static void SetGpuProjectionMatrix(Matrix projection) { Projection = projection; }

		Camera();
		~Camera();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		static void SetTarget(GameObject* target) { mTarget = target; }
		static GameObject* GetTarget() { return mTarget; }

		static void SetRootaByssScene(Scene* rootabyssscene) { mRootaByssScene = rootabyssscene; }
		static Scene* GetRootaByssScene() { return mRootaByssScene; }

		static void SetEastGardenScene(Scene* eastgardenscene) { mEastGardenScene = eastgardenscene; }
		static Scene* GetEastGardenScene() { return mEastGardenScene; }

		static void SetHeneSisScene(Scene* henesisscene) { mHeneSisScene = henesisscene; }
		static Scene* GetHeneSisScene() { return mHeneSisScene; }

		static void SetBanBanScene(Scene* banbanscene) { mBanBanScene = banbanscene; }
		static Scene* GetBanBanScene() { return mBanBanScene; }

		bool CreateViewMatrix();
		bool CreateProjectionMatrix(eProjectionType type);
		void RegisterCameraInRenderer();

		void TurnLayerMask(eLayerType type, bool enable = true);
		void EnableLayerMasks() { mLayerMask.set(); }
		void DisableLayerMasks() { mLayerMask.reset(); }

		void AlphaSortGameObjects();
		void ZSortTransparencyGameObjects();
		void DivideAlphaBlendGameObjects(const std::vector<GameObject*> gameObjs);
		void RenderOpaque();
		void RenderCutOut();
		void RenderTransparent();

		void EnableDepthStencilState();
		void DisableDepthStencilState();

		float GetSize() { return mSize; }
		Matrix& GetViewMatrix() { return mView; }
		Matrix& GetProjectionMatrix() { return mProjection; }

		static Vector3 GetWorldPos(Vector3 pos);

	private:
		static Matrix View;
		static Matrix Projection;

		Matrix mView;
		Matrix mProjection;

		eProjectionType mType;
		float mAspectRatio;
		float mNear;
		float mFar;
		float mSize;

		std::bitset<(UINT)eLayerType::End> mLayerMask;
		std::vector<GameObject*> mOpaqueGameObjects;
		std::vector<GameObject*> mCutOutGameObjects;
		std::vector<GameObject*> mTransparentGameObjects;

		static class GameObject* mTarget;
		static class Scene* mRootaByssScene;
		static class Scene* mEastGardenScene;
		static class Scene* mHeneSisScene;
		static class Scene* mBanBanScene;
	};
}
