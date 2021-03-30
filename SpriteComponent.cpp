#include "SpriteComponent.h"
#include "Actor.h"
#include "Game.h"
#include "Math.h"

SpriteComponent::SpriteComponent(Actor *owner, int drawOrder) : Component(owner), drawOrder(drawOrder) {
	owner->GetGame()->AddSprite(this);
}

SpriteComponent::SpriteComponent(Actor *owner, int drawOrder, SDL_Texture *texture, int width, int height) : Component(owner), texture(texture),
drawOrder(drawOrder), width(width), height(height) {
	owner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent() {
	owner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw(SDL_Renderer *renderer) {
	if (texture) {
		SDL_Rect rect;
		rect.w = static_cast<int>((float)width * owner->GetScale());
		rect.h = static_cast<int>((float)height * owner->GetScale());
		rect.x = static_cast<int>(owner->GetPosition().x - (float)rect.w / 2);
		rect.y = static_cast<int>(owner->GetPosition().y - (float)rect.h / 2);
		SDL_RenderCopyEx(renderer,
			texture,
			nullptr,
			&rect,
			-math::ToDegrees(owner->GetRotation()),
			nullptr,
			SDL_FLIP_NONE);
	}
}

void SpriteComponent::SetTexture(SDL_Texture *t) {
	texture = t;
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}
