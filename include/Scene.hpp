#pragma once

#include <SDL3/SDL.h>
#include <cstdlib>
#include <vector>

#include "GameEntity.hpp"
#include "EnemyGameEntity.hpp"
#include "InputComponent.hpp"


struct Scene {
	Scene(); 
	~Scene(); 

	void Startup(SDL_Renderer* aRenderer);
	void Shutdown();
	void Input(float deltaTime);
	void Update(float deltaTime);
	void Render();

	void SetActiveStatus(bool status);
	bool IsActive();

private:
	bool mIsActive{false};
	int mPoints{0};
	SDL_Renderer* mRenderer;
	std::vector<std::shared_ptr<EnemyGameEntity>> enemies;
	std::shared_ptr<GameEntity> hero;
};


