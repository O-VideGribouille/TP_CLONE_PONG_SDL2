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

    //Integration de Sprites non-dessinés
    //IMG balle
    SDL_Surface* surfaceBall;
    SDL_Texture* textureBall;
    surfaceBall = SDL_LoadBMP("./image/balle.bmp");
    textureBall = SDL_CreateTextureFromSurface(renderer, surfaceBall);
    SDL_FreeSurface(surfaceBall);

    int scoring1 = 0;// servira pour le changement de score sans devoir créer d'autres image à la suite

    string scrlink1 = "./image/" + to_string(scoring1) + ".bmp";// convertie l'integer en chaine de caractères
    //IMG Score Joueur1
    SDL_Surface* surfaceSCR1;
    SDL_Texture* textureSCR1;
    surfaceSCR1 = SDL_LoadBMP(const_cast<char*>(scrlink1.c_str())); //permet de l'intégrer à une adresse et lire l'image
    textureSCR1 = SDL_CreateTextureFromSurface(renderer, surfaceSCR1);
    SDL_FreeSurface(surfaceSCR1);

    int scoring2 = 0;
    string scrlink2 = "./image/" + to_string(scoring2) + ".bmp";
    //IMG Score Joueur2
    SDL_Surface* surfaceSCR2;
    SDL_Texture* textureSCR2;
    surfaceSCR2 = SDL_LoadBMP(const_cast<char*>(scrlink2.c_str()));
    textureSCR2 = SDL_CreateTextureFromSurface(renderer, surfaceSCR2);
    SDL_FreeSurface(surfaceSCR2);


    //IMG Joueur1
    SDL_Surface* surfaceJ1;
    SDL_Texture* textureJ1;
    surfaceJ1 = SDL_LoadBMP("./image/Joueur1.bmp");
    textureJ1 = SDL_CreateTextureFromSurface(renderer, surfaceJ1);
    SDL_FreeSurface(surfaceJ1);
    //IMG Joueur2
    SDL_Surface* surfaceJ2;
    SDL_Texture* textureJ2;
    surfaceJ2 = SDL_LoadBMP("./image/Joueur2.bmp");
    textureJ2 = SDL_CreateTextureFromSurface(renderer, surfaceJ2);
    SDL_FreeSurface(surfaceJ2);




    //Fin
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}