#include "HeroGameEntity.hpp"


HeroGameEntity::HeroGameEntity(SDL_Renderer* aRenderer) {
}

HeroGameEntity::~HeroGameEntity() {}

void HeroGameEntity::Input(float deltaTime) {
	for (auto& [type, theComponent] : mComponents) {
		theComponent->Input(deltaTime);
	}

	for (auto& theEntity : mGameEntities) {
		theEntity->Input(deltaTime);
	}
}

void HeroGameEntity::Update(float deltaTime) {
	for (auto& [type, theComponent] : mComponents) {
		theComponent->Update(deltaTime);
	}

	for (auto& theEntity : mGameEntities) {
		theEntity->Update(deltaTime);
	}
}

void HeroGameEntity::Render(SDL_Renderer* aRenderer) {
	for (auto& [type, theComponent] : mComponents) {
		theComponent->Render(aRenderer);
	}

	for (auto& theEntity : mGameEntities) {
		theEntity->Render(aRenderer);
	}
}

