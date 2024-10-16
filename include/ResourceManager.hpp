#pragma once

#include <SDL3/SDL.h>
#include <unordered_map>
#include <string>

struct ResourceManager {
	static ResourceManager* Instance() {
		if (mInstance == nullptr) {
			mInstance = new ResourceManager;
			SDL_Log("Create a new ResourceManager");
		}
		return mInstance;
	}

	~ResourceManager() {
		for (auto& [k, v] : mTextureCache) {
			SDL_DestroyTexture(v);
		}
	}
	
	SDL_Texture* LoadTexture(SDL_Renderer* aRenderer, std::string filepath) {
		if (!mTextureCache.contains(filepath)) {
			SDL_Surface* pixels = SDL_LoadBMP(filepath.c_str());
			SDL_SetSurfaceColorKey(pixels, SDL_TRUE, SDL_MapRGB(pixels->format, 0xFF, 0, 0xFF));

			SDL_Texture* pTexture;
			pTexture = SDL_CreateTextureFromSurface(aRenderer, pixels);
			if (pTexture == nullptr) {
				SDL_Log("Create Texture failed: %s\n", SDL_GetError());
			}

			mTextureCache.insert({filepath, pTexture});
			SDL_Log("Insert %s to cache", filepath.c_str());
			SDL_DestroySurface(pixels);
		} else {
			SDL_Log("Reuse %s", filepath.c_str());
		}
		
		return mTextureCache[filepath]; 
	}

	private:
	ResourceManager() {}

	private:
	static ResourceManager* mInstance; 
	std::unordered_map<std::string, SDL_Texture*> mTextureCache;
};

// We have to initialize the static member varible after defining the class
ResourceManager* ResourceManager::mInstance = nullptr; 

