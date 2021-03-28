#pragma once

#include "SDL.h"
#include "Component.h"

class SpriteComponent : public Component {
public:
	SpriteComponent(class Actor *owner, int drawOrder = 100);
	SpriteComponent(class Actor *owner, int drawOrder, SDL_Texture *texture, int width, int height);
	~SpriteComponent() override;

	virtual void Draw(SDL_Renderer* renderer);
	virtual void SetTexture(SDL_Texture* texture);

	int GetDrawOrder() const {
		return drawOrder;
	}

	int GetWidth() const {
		return width;
	}

	int GetHeight() const {
		return height;
	}
protected:
	SDL_Texture *texture = nullptr;
	int drawOrder = 0;
	int width = 0;
	int height = 0;
};