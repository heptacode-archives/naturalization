#include "stdafx.h"
#include "Transform.h"
Transform::Transform(Vector2 position, float angle, Vector2 scale)
	:Component(), position(position), rotatingAngle(angle), scale(scale),
	positioningCenter(Vector2()), rotatingCenter(Vector2()), scalingCenter(Vector2())
{
	positioningCenter.x = 0.0f;
	positioningCenter.y = 0.0f;
	rotatingCenter.x = 0.0f;
	rotatingCenter.y = 0.0f;
	scalingCenter.x = 0.0f;
	scalingCenter.y = 0.0f;
}

Transform::~Transform()
{
}

void Transform::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

void Transform::SetPosition(Vector2& v)
{
	position.x = v.x;
	position.y = v.y;
}

void Transform::SetRotation(float angle)
{
	rotatingAngle = angle;
}

void Transform::SetScale(float x, float y)
{
	scale.x = x;
	scale.y = y;
}

void Transform::SetScale(Vector2& v)
{
	scale.x = v.x;
	scale.y = v.y;
}
