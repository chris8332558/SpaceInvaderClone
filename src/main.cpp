// clang++ -std=c++20 ./src/main.cpp ./src/Application.cpp -I./include/ -o prog `pkg-config --libs --cflags sdl3`
#include "Application.hpp"

int main(int argc, char* argv[]) {
	Application app{argc, argv};
	app.Loop(120.f); // pass in the targetFPS
	return 0;
}
