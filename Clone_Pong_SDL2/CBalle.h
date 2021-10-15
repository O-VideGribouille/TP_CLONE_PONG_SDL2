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

//	float bX;
//	float bY;


public:

	//accessible depuis la classe enfant
	CBalle();
	//CBalle(int n_x, int n_y, int n_w, int n_h, float bX, float bY);
	CBalle(int n_x, int n_y, int n_w, int n_h);

	//Constructeur de copie
//	CBalle(const CBalle& p);

	//Destructeur
	~CBalle();


	//Accesseurs
	int getX()const;
	int getY()const;
	int getW()const;
	int getH()const;

//	float getBX()const;
//	float getBY()const;



	
//Accesseurs
	void setX(int n_x = 9);
	void setY(int n_y = 9);
	void setW(int n_w = 9);
	void setH(int n_h = 9);

/*	void setBX(float bX);
	void setBY(float bY);*/


	//Prototypes
	//Changement de la direction de la balle
//	void chgmntDrect();

};