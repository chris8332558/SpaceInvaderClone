#pragma once

#include <string>
#include <SDL3/SDL.h>
#include "Component.hpp"

struct TextureComponent : public Component {
	TextureComponent();
	~TextureComponent();

	void CreateTextureComponent(SDL_Renderer* aRenderer, std::string filepath);

	// ------ override ------
	void Input(float deltatime) override; 

	void Update(float deltatime) override;

	void Render(SDL_Renderer* aRenderer) override;

	ComponentType GetComponentType() override;
	// ------ override ------

	private:
	SDL_Texture* mTexture;
};
