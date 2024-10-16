#include "Projectile.hpp"


Projectile::Projectile() {
	timeSinceLastLaunch = SDL_GetTicks();
	SetRenderable(false);
}

Projectile::~Projectile() {}

void Projectile::Input(float deltaTime) {
	for (auto& [type, theComponent] : mComponents) {
		theComponent->Input(deltaTime);
	}
}


void Projectile::Update(float deltaTime) {
	auto theTransform = this->GetTransformComponent();
	if (mIsFlying) {
		SetRenderable(true);
		if (mToUp) {
			theTransform->SetY(theTransform->GetY() - mSpeed*deltaTime);
		} else {
			theTransform->SetY(theTransform->GetY() + mSpeed*deltaTime);
		}
	}
	if (theTransform->GetY() < 0 || theTransform->GetY() > (float)gWindow_h) {
		mIsFlying = false;
		SetRenderable(false);
	}

	for (auto& [type, theComponent] : mComponents) {
		theComponent->Update(deltaTime);
	}
}

void Projectile::Render(SDL_Renderer* aRenderer) {
	if (mRenderable) {
		for (auto& [type, theComponent] : mComponents) {
			theComponent->Render(aRenderer);
		}
	}
}

void Projectile::Launch(float x, float y, bool isToUp, float minLaunchTime) {
	if (SDL_GetTicks() - timeSinceLastLaunch > minLaunchTime) {
		auto theTransform = this->GetTransformComponent();
		theTransform->SetXY(x, y);
		mToUp = isToUp;
		mIsFlying = true;
		timeSinceLastLaunch = SDL_GetTicks();
	}
}

void Projectile::SetSpeed(float aSpeed) {
	mSpeed = aSpeed;
}

