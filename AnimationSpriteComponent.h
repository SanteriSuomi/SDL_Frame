#pragma once

#include "SpriteComponent.h"
#include <vector>

class AnimationSpriteComponent : public SpriteComponent {
public:
	AnimationSpriteComponent(class Actor *owner, int drawOrder = 100);
	AnimationSpriteComponent(class Actor *owner, int drawOrder, std::vector<SDL_Texture *> &textures, int width, int height);

	void Update(float delta) override;
	void SetAnimationTextures(const std::vector<SDL_Texture *> &textures);

	float GetAnimationFPS() const {
		return animationFPS;
	}

	void SetAnimationFPS(float fps) {
		animationFPS = fps;
	}
private:
	std::vector<SDL_Texture *> animationTextures;
	float currentFrame = 0.0F;
	float animationFPS = 24.0F;
};