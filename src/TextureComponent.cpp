#include "TextureComponent.hpp"
#include "ResourceManager.hpp"
#include "GameEntity.hpp" // We forward declare the GameEntity in Component.hpp, here we need to include the GameEntity.hpp to get the implementation, or we would get imcomplete type error.

TextureComponent::TextureComponent() = default;
TextureComponent::~TextureComponent() = default; 

void TextureComponent::CreateTextureComponent(SDL_Renderer* aRenderer, std::string filepath) {
	// Upload the image to the GPU
	ResourceManager* theManager = ResourceManager::Instance();
	mTexture = theManager->LoadTexture(aRenderer, filepath);
}


// ------ override ------
void TextureComponent::Input(float deltatime) {}

void TextureComponent::Update(float deltatime) {}

void TextureComponent::Render(SDL_Renderer* aRenderer) {
	auto theGameEntity = GetGameEntity();
	auto theRect = theGameEntity->GetTransformComponent()->GetRect();
	if (mTexture == nullptr) {
		SDL_RenderRect(aRenderer, &theRect);
	}
	else {
		SDL_RenderTexture(aRenderer, mTexture, nullptr, &theRect);
	}
}

ComponentType TextureComponent::GetComponentType() {
	return ComponentType::TextureComponent;
}
// ------ override ------

