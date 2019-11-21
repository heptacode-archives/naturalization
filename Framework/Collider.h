#pragma once
#include "Transform.h"


class Collider :
	public Component
{
public:
	struct AABBBox //center값은 transform.position을 원점으로한 거리입니다.
	{
		Vector2 leftTop;
		Vector2 rightBottom;

		AABBBox();
		AABBBox(const AABBBox& box);
		AABBBox(const Vector2& size);
		AABBBox(float width, float height);
		AABBBox(const Vector2& leftTop, const Vector2& rightBottom);
		AABBBox(float left, float top, float right, float bottom);
	};
	struct Circle //center값은 transform.position을 원점으로한 거리입니다.
	{
		Vector2 center;
		float radius;

		Circle();
		Circle(const Circle& circle);
		Circle(float radius);
		Circle(const Vector2& center, float radius);
		Circle(float x, float y, float radius);
	};
public:
	Collider(Transform& transform);
public:
	Transform& transform;

public:
	virtual bool Intersected(Collider& col) = 0;
	virtual bool Intersected(const AABBBox& box) = 0;
	virtual bool Intersected(const Circle& circle) = 0;
	virtual bool Intersected(const Vector2& vector) = 0;
};