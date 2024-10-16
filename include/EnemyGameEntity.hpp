#pragma once

#include <memory>
#include "GameEntity.hpp"
#include "TextureComponent.hpp"
#include "Projectile.hpp"

struct EnemyGameEntity : public GameEntity {
	EnemyGameEntity(SDL_Renderer* aRenderer);
	~EnemyGameEntity();

	void Update(float deltaTime) override; 
	void Render(SDL_Renderer* aRenderer) override;

	private:
	bool toRight{true};
	float mSpeed{100.f};
	float offset{0.f};
	float minLaunchTime{0.f};
};
