#pragma once

#include <SDL3/SDL.h>
#include <memory>


// Forward declaration to prevent circular dependency
// The compiler only knows GameEneity is a type here, so forward declaration is allowed iff when using the pointer to GameEntity
// Because a pointer has a fixed size, the compiller needs to know how many memory to allocate when compilling
struct GameEntity;

enum class ComponentType{TextureComponent, 
						TransformComponent,
						Collision2DComponent,
						InputComponent};

struct Component {
	Component() {}
	virtual ~Component() {}

	virtual void Input(float deltaTime) {}
	virtual void Update(float deltaTime) {}
	virtual void Render(SDL_Renderer* aRenderer) {}

	virtual ComponentType GetComponentType() = 0;
	
	void SetGameEntity(std::shared_ptr<GameEntity> aGameEntity) {
		std::weak_ptr<GameEntity> aWeakPtr(aGameEntity);
		mGameEntity = aWeakPtr;
	}
	
	std::shared_ptr<GameEntity> GetGameEntity() {
		return mGameEntity.lock(); 
	}

	private:
	// The compoenets might need to communicate with other components, so we need to know the GameEntity
	// Using weak pointer since we don't want the component to extend the GameEntity's life
	std::weak_ptr<GameEntity> mGameEntity;
};
