#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include <string>

using namespace std;

int main(int argc, char** argv) {

    //Début et initialisation
    SDL_Init(SDL_INIT_EVERYTHING);

    //Création d'une fenêtre
    SDL_Window* window = SDL_CreateWindow("1. Pong C++ SDL2", 50, 50, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Event e;
    //Texture de background
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);






    //Fin
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}