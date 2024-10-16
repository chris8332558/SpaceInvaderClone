#pragma once

#include <memory>
#include <map>
#include "Component.hpp"
#include "TextureComponent.hpp"
#include "TransformComponent.hpp"
#include "Collision2DComponent.hpp"

struct GameEntity : public std::enable_shared_from_this<GameEntity>{
	GameEntity();
	~GameEntity(); 

	// For AddComponent()
	std::shared_ptr<GameEntity> GetPtr()
    {
        return shared_from_this();
    }
	
	virtual void Input(float deltaTime); 
	virtual void Update(float deltaTime);
	virtual void Render(SDL_Renderer* aRenderer); 

	void SetRenderable(bool isRenderable); 
	bool IsIntersect(std::shared_ptr<GameEntity> aGameEntity); 
	bool IsRenderable() const;

	void AddComponent(std::shared_ptr<Component> c);
	void AddDefaultTransform();

	template <typename T>
	std::shared_ptr<T> GetComponent(ComponentType aType);

	// Specific function to get the transform component
	std::shared_ptr<TransformComponent> GetTransformComponent();
	
	void AddGameEntity(std::shared_ptr<GameEntity> aEntity);
	std::shared_ptr<GameEntity> GetGameEntityAt(size_t index);
	
	protected:
	bool mRenderable{true};
	std::map<ComponentType, std::shared_ptr<Component>> mComponents; 
	std::vector<std::shared_ptr<GameEntity>> mGameEntities;
};
