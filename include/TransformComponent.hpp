#pragma once

#include <string>
#include <SDL3/SDL.h>
#include "Component.hpp"

struct TransformComponent : public Component {
	TransformComponent();
	~TransformComponent();

	// ------ override ------
	void Input(float deltatime) override; 
	void Update(float deltatime) override;
	void Render(SDL_Renderer* aRenderer) override;
	ComponentType GetComponentType() override;
	// ------ override ------

	
	void SetX(float x);
	void SetY(float y);
	void SetXY(float x, float y);
	void SetW(float w);
	void SetH(float f);
	void SetWH(float w, float h);

	float GetX() const;
	float GetY() const;
	float GetW() const;
	float GetH() const;

	SDL_FRect GetRect() const;

	private:
	SDL_FRect mRect{0.f, 0.f, 30.f, 30.f}; // x, y, w, h
};
