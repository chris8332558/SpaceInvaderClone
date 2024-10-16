#include "InputComponent.hpp"
#include "GameEntity.hpp"
#include "Projectile.hpp"

InputComponent::InputComponent() {}
InputComponent::~InputComponent() {}

void InputComponent::Input(float deltaTime) {
	const Uint8* state = SDL_GetKeyboardState(nullptr);
	
	// A weak_ptr must be converted to std::shared_ptr (lock()) in order to
	// access the referenced object.
	auto ge = GetGameEntity();
	auto theTransform = ge->GetTransformComponent();
	if (state[SDL_SCANCODE_RIGHT]) {
		theTransform->SetX(theTransform->GetX() + mSpeed*deltaTime);
	} else if (state[SDL_SCANCODE_LEFT]) {
		theTransform->SetX(theTransform->GetX() - mSpeed*deltaTime);
	}
	if (state[SDL_SCANCODE_SPACE]) {
		SDL_Log("Launch!");
		std::shared_ptr<Projectile> theProjectile = std::dynamic_pointer_cast<Projectile>(ge->GetGameEntityAt(0));
		theProjectile->Launch(theTransform->GetX(), theTransform->GetY(), true);
	}
	
	
}

void InputComponent::Update(float deltaTime) {

}

void InputComponent::Render(SDL_Renderer* aRenderer) {

}

ComponentType InputComponent::GetComponentType() {
	return ComponentType::InputComponent;
}
