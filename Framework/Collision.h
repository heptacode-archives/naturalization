#pragma once
#include "AABBCollider.h"
#include "CircleCollider.h"

namespace Collision 
{
	bool Intersected(const Collider::AABBBox& a, const Collider::AABBBox& b);
	bool Intersected(const Collider::AABBBox& a, const Collider::Circle& b);
	bool Intersected(const Collider::Circle& a, const Collider::Circle& b);
	bool Intersected(const Collider::AABBBox& a, const Vector2& b);
	bool Intersected(const Collider::Circle& a, const Vector2& b);
}

