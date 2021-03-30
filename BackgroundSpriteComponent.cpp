#include "BackgroundSpriteComponent.h"
#include "Actor.h"
#include "Math.h"

// TO-DO: improve so scroll velocity works both in X and Y axis simultaneously

BackgroundSpriteComponent::BackgroundSpriteComponent(Actor *owner, int drawOrder) : SpriteComponent(owner, drawOrder) {

}

BackgroundSpriteComponent::BackgroundSpriteComponent(Actor *owner, int drawOrder, math::Vector2<float> screenSize, math::Vector2<float> scrollVelocity, 
	const std::vector<SDL_Texture *> &textures) : SpriteComponent(owner, drawOrder), screenSize(screenSize), scrollVelocity(scrollVelocity) {
	SetBackgroundTextures(textures);
}

void BackgroundSpriteComponent::Update(float delta) {
	SpriteComponent::Update(delta);
	if (!math::Compare<float>(scrollVelocity.x, 0.0F) || !math::Compare<float>(scrollVelocity.y, 0.0F)) {
		for (auto &bg : backgroundTextures) {
			bg.offset.x += scrollVelocity.x * delta;
			bg.offset.y += scrollVelocity.y * delta;
			if (bg.offset.x < -screenSize.x) {
				bg.offset.x = (static_cast<float>(backgroundTextures.size() - 1)) * screenSize.x - 1;
			}
 			if (bg.offset.y < -screenSize.y) {
				bg.offset.y = (static_cast<float>(backgroundTextures.size() - 1)) * screenSize.y - 1;
			}
		}
	}
}

void BackgroundSpriteComponent::Draw(SDL_Renderer *renderer) {
	for (auto &bg : backgroundTextures) {
		SDL_Rect rect;
		rect.w = static_cast<int>(screenSize.x * owner->GetScale());
		rect.h = static_cast<int>(screenSize.y * owner->GetScale());
		rect.x = static_cast<int>(owner->GetPosition().x - (float)rect.w / 2 + bg.offset.x);
		rect.y = static_cast<int>(owner->GetPosition().y - (float)rect.h / 2 + bg.offset.y);
		SDL_RenderCopy(renderer,
			bg.texture,
			nullptr,
			&rect
		);
	}
}

void BackgroundSpriteComponent::SetBackgroundTextures(const std::vector<SDL_Texture *> &textures) {
	int count = 0;
	for (const auto &t : textures) {
		BackgroundTexture temp;
		temp.texture = t;
		temp.offset = { 0, -((float)count * screenSize.y), };
		backgroundTextures.emplace_back(temp);
		count++;
	}
}
