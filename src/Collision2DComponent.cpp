#include "Collision2DComponent.hpp"
#include "GameEntity.hpp"

Collision2DComponent::Collision2DComponent() = default;
Collision2DComponent::~Collision2DComponent() = default; 

// ------ override ------
void Collision2DComponent::Input(float deltatime) {}

void Collision2DComponent::Update(float deltatime) {
	// Default behavior is to follow the TransformCompoennt
	// We might want to have more control later
	auto theTranform = GetGameEntity()->GetTransformComponent();
	// We can see the collision component and the transform component are different
	SetWH(theTranform->GetW()+4, theTranform->GetH()+4);
	SetXY(theTranform->GetX()-2, theTranform->GetY()-2);
}

void Collision2DComponent::Render(SDL_Renderer* aRenderer) {
	// Good for debugging
	SDL_RenderRect(aRenderer, &mRect);
}

ComponentType Collision2DComponent::GetComponentType() {
	return ComponentType::Collision2DComponent;
}
// ------ override ------


void Collision2DComponent::SetX(float x) {
	mRect.x = x;
}

void Collision2DComponent::SetY(float y) {
	mRect.y = y;
}

void Collision2DComponent::SetXY(float x, float y) {
	mRect.x = x;
	mRect.y = y;
}

void Collision2DComponent::SetW(float w) {
	mRect.w = w;
}

void Collision2DComponent::SetH(float h) {
	mRect.h = h;
}

void Collision2DComponent::SetWH(float w, float h) {
	mRect.w = w;
	mRect.h = h;
}


float Collision2DComponent::GetX() const {
	return mRect.x;
}

float Collision2DComponent::GetY() const {
	return mRect.y;
}

float Collision2DComponent::GetW() const {
	return mRect.w;
}

float Collision2DComponent::GetH() const {
	return mRect.h;
}

SDL_FRect Collision2DComponent::GetRect() const {
	return this->mRect;
} 
