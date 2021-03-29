#include "AnimationSpriteComponent.h"

AnimationSpriteComponent::AnimationSpriteComponent(Actor *owner, int drawOrder) : SpriteComponent(owner, drawOrder) {

}

AnimationSpriteComponent::AnimationSpriteComponent(Actor *owner, int drawOrder, std::vector<SDL_Texture *> &textures, int width, int height) 
: SpriteComponent(owner, drawOrder, textures[0], width, height), animationTextures(textures) {

}

void AnimationSpriteComponent::Update(float delta) {
	SpriteComponent::Update(delta);
	auto animTextSize = static_cast<float>(animationTextures.size());
	if (animTextSize > 0) {
		currentFrame += animationFPS * delta;
		while (currentFrame >= animTextSize){
			currentFrame -= animTextSize;
		}
		SetTexture(animationTextures[static_cast<int>(currentFrame)]);
	}
}

void AnimationSpriteComponent::SetAnimationTextures(const std::vector<SDL_Texture *> &textures) {
	animationTextures = textures;
	if (!animationTextures.empty()) {
		// Set the active texture to first frame
		currentFrame = 0.0F;
		SetTexture(animationTextures[0]);
	}
}
