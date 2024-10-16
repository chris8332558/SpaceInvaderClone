#include "GameEntity.hpp"


GameEntity::GameEntity() {}
GameEntity::~GameEntity() {}

void GameEntity::Input(float deltaTime) {
	for (auto& [type, theComponent] : mComponents) {
		theComponent->Input(deltaTime);
	}

	for (auto& theEntity : mGameEntities) {
		theEntity->Input(deltaTime);
	}
}

void GameEntity::Update(float deltaTime) {
	for (auto& [type, theComponent] : mComponents) {
		theComponent->Update(deltaTime);
	}

	for (auto& theEntity : mGameEntities) {
		theEntity->Update(deltaTime);
	}
}

void GameEntity::Render(SDL_Renderer* aRenderer) {
	for (auto& [type, theComponent] : mComponents) {
		theComponent->Render(aRenderer);
	}

	for (auto& theEntity : mGameEntities) {
		theEntity->Render(aRenderer);
	}
}

void GameEntity::SetRenderable(bool isRenderable) {
	mRenderable = isRenderable;
}

bool GameEntity::IsIntersect(std::shared_ptr<GameEntity> aGameEntity) {
	auto theTransform1 = this->GetComponent<Collision2DComponent>(ComponentType::Collision2DComponent);
	auto theTransform2 = aGameEntity->GetComponent<Collision2DComponent>(ComponentType::Collision2DComponent);
	SDL_FRect theIntersectResult;
	SDL_FRect theRect1 = theTransform1->GetRect();
	SDL_FRect theRect2 = theTransform2->GetRect();
	return SDL_GetRectIntersectionFloat(&theRect1, &theRect2, &theIntersectResult);  
}


bool GameEntity::IsRenderable() const {
	return mRenderable;
}

void GameEntity::AddComponent(std::shared_ptr<Component> c) {
	c->SetGameEntity(this->GetPtr());
	mComponents[c->GetComponentType()] = c;
}

void GameEntity::AddDefaultTransform() {
	// Every GameEntity has a TransformComponent
	std::shared_ptr<TransformComponent> tc = std::make_shared<TransformComponent>();
	AddComponent(tc);
}

template <typename T>
std::shared_ptr<T> GameEntity::GetComponent(ComponentType aType) {
	auto found = mComponents.find(aType);
	if (found != mComponents.end()) {
		return dynamic_pointer_cast<T>(found->second);
	}
	SDL_Log("Error: Component not found");
	return nullptr;
}


std::shared_ptr<TransformComponent> GameEntity::GetTransformComponent() {
	return GetComponent<TransformComponent>(ComponentType::TransformComponent);
}

void GameEntity::AddGameEntity(std::shared_ptr<GameEntity> aEntity) {
	mGameEntities.push_back(aEntity);
}

std::shared_ptr<GameEntity> GameEntity::GetGameEntityAt(size_t index) {
	return mGameEntities[index];
}
