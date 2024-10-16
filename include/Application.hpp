#pragma once

#include <SDL3/SDL.h>
#include <cstdlib>
#include <vector>

#include "Scene.hpp"

struct Application {
	Application(int argc, char* argv[]); 
	~Application(); 

	void Startup();
	void Shutdown();
	void Input(float deltaTime);
	void Update(float deltaTime);
	void Render();
	void Loop(float targetFPS);

private:
	bool mRun{true};
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Scene mScene;
};


