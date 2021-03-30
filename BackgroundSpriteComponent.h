#pragma once

#include "SpriteComponent.h"
#include <vector>
#include "Math.h"
#include "Constants.h"

class BackgroundSpriteComponent : public SpriteComponent {
public:
	BackgroundSpriteComponent(class Actor* owner, int drawOrder = 10);
	BackgroundSpriteComponent(class Actor* owner, int drawOrder, math::Vector2<float> screenSize, math::Vector2<float> scrollVelocity, 
		const std::vector<SDL_Texture*> &textures);

	void Update(float delta) override;
	void Draw(SDL_Renderer *renderer) override;
	void SetBackgroundTextures(const std::vector<SDL_Texture*> &textures);

	void SetScreenSize(const math::Vector2<float> &size) {
		screenSize = size;
	}

	void SetScrollSpeed(const math::Vector2<float> &velocity) {
		scrollVelocity = velocity;
	}

	math::Vector2<float> GetScrollSpeed() const {
		return scrollVelocity;
	}
private:
	struct BackgroundTexture {
		SDL_Texture *texture;
		math::Vector2<float> offset;
	};

	std::vector<BackgroundTexture> backgroundTextures;
	math::Vector2<float> screenSize = { WINDOW_WIDTH, WINDOW_HEIGHT };
	math::Vector2<float> scrollVelocity = { 0, 0 };
};