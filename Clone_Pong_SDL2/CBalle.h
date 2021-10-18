#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include <string>

using namespace std;


class CBalle {



protected:

	//accessible depuis la classe enfant
	//Raquette du joueur
	int n_x;
	int n_y;
	int n_w;
	int n_h;

	float speedX;
	float speedY;


public:

	//accessible depuis la classe enfant
	CBalle();
	CBalle(int n_x, int n_y, int n_w, int n_h, float speedX, float speedY);

	//Destructeur
	~CBalle();


	//Accesseurs
	int getX()const;
	int getY()const;
	int getW()const;
	int getH()const;

	float getspeedX()const;
	float getspeedY()const;



	
//Accesseurs
	void setX(int n_x = 9);
	void setY(int n_y = 9);
	void setW(int n_w = 9);
	void setH(int n_h = 9);

	void setspeedX(float speedX);
	void setspeedY(float speedY);


	//Prototypes
	//Changement de la direction de la balle
	void DplcmntB();

	//void CllsnandRbd(float bX, float bY, SDL_Rect ball, SDL_Rect playerPadle1, SDL_Rect playerPadle2, );
	SDL_Texture* CllsnandRbd1(SDL_Rect &ball, int * Pscoring1, SDL_Surface *surfaceSCR1,SDL_Texture *textureSCR1, string scrlink1, SDL_Renderer* renderer);
	SDL_Texture* CllsnandRbd2(SDL_Rect &ball, int *Pscoring2, SDL_Surface *surfaceSCR2, SDL_Texture *textureSCR2, string scrlink2, SDL_Renderer* renderer);

	void CllsnandRbd3(SDL_Rect &ball, SDL_Rect playerPadle1, SDL_Rect playerPadle2);

};