#pragma once


namespace ya::enums
{
	enum class eComponentType
	{
		None,
		Transform,
		Mesh,
		Collider2D,
		Particle,
		MeshRenderer,
		Animator,
		RigidBody,
		Script,
		Light,
		Camera,
		AudioListener,
		AudioSource,
		End,
	};

	enum class eLayerType
	{
		Grid,
		BG,
		Cursor,
		Logo,
		Ground,
		NPC,
		Monster,
		Player,
		Skill,
		Damage,
		Effect,
		Portal,
		Light,
		Inventory,
		Shop,
		SkillSlot,
		UI,
		Item,
		Camera,
		End = 32,
	};

	enum class eResourceType
	{
		Texture,
		Shader,
		Material,
		Mesh,
		Animation,
		ComputeShader,
		AudioClip,
		End,
	};

	enum class eColliderType
	{
		Rect,
		Circle,
		Sphere,
		Cube,
		End,
	};

	enum class eLightType
	{
		Directional,
		Point,
		Spot,
		End,
	};
}