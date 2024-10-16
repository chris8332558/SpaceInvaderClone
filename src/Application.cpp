#include "Application.hpp" 

Application::Application(int argc, char* argv[]) {
	Startup();
}

Application::~Application() {
	Shutdown();
}

void Application::Startup() {
	// Initialize SDL system
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
		SDL_Log("Initilization failed: %s", SDL_GetError());
	}
	
	// Create SDL_Window and SDL_Renderer
	mWindow = SDL_CreateWindow("SDL3 Window",
			gWindow_w, gWindow_h,
			SDL_WINDOW_OPENGL);

	mRenderer = SDL_CreateRenderer(mWindow, NULL);
	if (mRenderer == nullptr) {
		SDL_Log("CreateRenderer failed: %s\n", SDL_GetError());
	}

	mScene.Startup(mRenderer);
	mScene.SetActiveStatus(true);
}

void Application::Shutdown() {
	// Notice the order matters
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Application::Input(float deltaTime) {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		if (event.type == SDL_EVENT_QUIT) {
			SDL_Log("Quit: %llu\n", event.quit.timestamp);
			mRun = false;
		}
//		else if (event.type == SDL_EVENT_KEY_DOWN) {
//			SDL_Log("Keydown: %u", event.key.keysym.sym);
//			if (event.key.keysym.sym == SDLK_0) {
//				SDL_Log("Pressed 0");
//			}
//		}

		mScene.Input(deltaTime);
	}
}

void Application::Update(float deltaTime) {
	mScene.Update(deltaTime);
}

void Application::Render() {
	mScene.Render();
}

void Application::Loop(float targetFPS) {
	Uint64 currentTime, lastTime;
	Uint64 frameElapsed{0};
	lastTime = SDL_GetTicks();
	Uint64 budget = 1000/targetFPS; // how many ticks (ms) we have for one frame 
	// Frames per second -> Second per frame -> Ticks per frame
	float deltaTime{1.0f / targetFPS}; // For normalizing the update speed
	while(mRun && mScene.IsActive()) {
		// ------ Frame ------
		Uint64 startOfFrame = SDL_GetTicks();
		Input(deltaTime);
		Update(deltaTime);
		Render();
		Uint64 elapsedTime = SDL_GetTicks() - startOfFrame;
		// ------ Frame ------

		// Delay to fillup our budget
		if (elapsedTime < budget) {
			Uint64 delay = budget - elapsedTime;
			SDL_Delay(delay);
		}
		frameElapsed++;
		
		// Time keeping
		currentTime = SDL_GetTicks();
		if (currentTime > lastTime + 1000) {
			SDL_Log("1 second elapsed\n");
			SDL_Log("FPS: %llu", frameElapsed);
			deltaTime = 1.0f / frameElapsed;
			frameElapsed=0;
			lastTime = SDL_GetTicks();
		}
	}
}


