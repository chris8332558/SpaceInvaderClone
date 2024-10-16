#include "EnemyGameEntity.hpp"

EnemyGameEntity::EnemyGameEntity(SDL_Renderer* aRenderer) {
	minLaunchTime = std::rand() % 10000 + 6000;
}

EnemyGameEntity::~EnemyGameEntity() {}

void EnemyGameEntity::Update(float deltaTime) {
	if (offset < -120) {
		toRight = true;	
	}
	if (offset > 128) {
		toRight = false;
	}

	auto theTransform = this->GetTransformComponent();
	if (toRight) {
		theTransform->SetX(theTransform->GetX() + mSpeed*deltaTime); // Multiply deltaTime to normalize the speed
		offset += mSpeed * deltaTime; // Keep the objects in bound
	} else { 
		theTransform->SetX(theTransform->GetX() - mSpeed*deltaTime); 
		offset -= mSpeed * deltaTime;
	}

	if (mRenderable) {
		std::shared_ptr<Projectile> theProjectile = std::dynamic_pointer_cast<Projectile>(GetGameEntityAt(0));
		theProjectile->Launch(theTransform->GetX(), theTransform->GetY(), false, minLaunchTime);
	}

	for (auto& [type, theComponent] : mComponents) {
		theComponent->Update(deltaTime);
	}

	for (auto& theEntity : mGameEntities) {
		theEntity->Update(deltaTime);
	}
}

void EnemyGameEntity::Render(SDL_Renderer* aRenderer) {
	if (mRenderable) {
		for (auto& [type, theComponent] : mComponents) {
			theComponent->Render(aRenderer);
		}

		for (auto& theEntity : mGameEntities) {
			theEntity->Render(aRenderer);
		}
	}
}

