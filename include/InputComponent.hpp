#pragma once

#include "Component.hpp"

struct InputComponent : public Component {
	public:

	InputComponent(); 
	~InputComponent();

	void Input(float deltaTime) override;
	void Update(float deltaTime) override;
	void Render(SDL_Renderer* aRenderer) override;

	ComponentType GetComponentType() override;
	

	private:
	float mSpeed{1000.f};

};
