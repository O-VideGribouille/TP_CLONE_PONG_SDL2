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


class CJoueur {



protected:

	//accessible depuis la classe enfant
	//Raquette du joueur
	int n_x;
	int n_y;
	int n_w;
	int n_h;



public:

	//accessible depuis la classe enfant
	CJoueur();
	CJoueur(int n_x, int n_y, int n_w, int n_h);

	//Constructeur de copie
	CJoueur(const CJoueur& p);

	//Destructeur
	~CJoueur();


	//Accesseurs
	int getX()const;
	int getY()const;
	int getW()const;
	int getH()const;


	//static int getCptInstance();


	//Mutateurs
	void setX(int n_x = 9);
	void setY(int n_y = 9);
	void setW(int n_x = 9);
	void setH(int n_y = 9);




};