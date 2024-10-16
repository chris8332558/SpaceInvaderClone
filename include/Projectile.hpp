#pragma once

#include <memory>
#include "GameEntity.hpp"
#include "config.hpp"

struct Projectile : public GameEntity {
	Projectile();
	~Projectile();

	void Input(float deltaTime) override;
	void Update(float deltaTime) override; 
	void Render(SDL_Renderer* aRenderer) override;
	void Launch(float x, float y, bool isToUp, float minLaunchTime=3000);	
	void SetSpeed(float aSpeed);
	
	private:
	float mSpeed{80.f};
	bool mToUp{true};
	bool mIsFlying{false};
	Uint64 timeSinceLastLaunch;
};
