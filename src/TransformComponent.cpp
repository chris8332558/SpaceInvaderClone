#include "TransformComponent.hpp"

TransformComponent::TransformComponent() = default;
TransformComponent::~TransformComponent() = default; 

// ------ override ------
void TransformComponent::Input(float deltatime) {}

void TransformComponent::Update(float deltatime) {}

void TransformComponent::Render(SDL_Renderer* aRenderer) {
	// Good for debugging
	SDL_RenderRect(aRenderer, &mRect);
}

ComponentType TransformComponent::GetComponentType() {
	return ComponentType::TransformComponent;
}
// ------ override ------


void TransformComponent::SetX(float x) {
	mRect.x = x;
}

void TransformComponent::SetY(float y) {
	mRect.y = y;
}

void TransformComponent::SetXY(float x, float y) {
	mRect.x = x;
	mRect.y = y;
}

void TransformComponent::SetW(float w) {
	mRect.w = w;
}

void TransformComponent::SetH(float h) {
	mRect.h = h;
}

void TransformComponent::SetWH(float w, float h) {
	mRect.w = w;
	mRect.h = h;
}


float TransformComponent::GetX() const {
	return mRect.x;
}

float TransformComponent::GetY() const {
	return mRect.y;
}

float TransformComponent::GetW() const {
	return mRect.w;
}

float TransformComponent::GetH() const {
	return mRect.h;
}

SDL_FRect TransformComponent::GetRect() const {
	return this->mRect;
} 
