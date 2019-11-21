#pragma once
#include "Renderer.h"
#include "Animation.h"


class AnimationRenderer :
	public Renderer
{
public:
	AnimationRenderer();
	virtual ~AnimationRenderer();
public:
	int currentState;
	Animation* currentAnimation;
	std::vector<Animation*> animations;
public:

	void Render(ID2D1HwndRenderTarget& renderTarget, Transform& transform);
	void ChangeAnim(int state);
	void PushBackAnimation(Animation* anim);
	Animation* FindAnimationByState(int state);
};

