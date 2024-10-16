#pragma once

#include <memory>
#include "GameEntity.hpp"
#include "TextureComponent.hpp"
#include "Projectile.hpp"

// We actually don't need this, it's just a GameEntity
struct HeroGameEntity : public GameEntity {
	HeroGameEntity(SDL_Renderer* aRenderer); 
	~HeroGameEntity(); 

	void Input(float deltaTime) override; 	
	void Update(float deltaTime) override; 
	void Render(SDL_Renderer* aRenderer) override; 

	private:
	float mSpeed{1000.0f};
	float minLaunchTime{2000.f};
};

