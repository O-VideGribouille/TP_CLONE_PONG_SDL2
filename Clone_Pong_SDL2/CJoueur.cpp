#include "CJoueur.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include <string>

using namespace std;


//constructeurs
CJoueur::CJoueur()
{
	this->n_x = 0;
	this->n_y = 0;
	this->n_w = 0;
	this->n_h = 0;
}

CJoueur::CJoueur(int n_x, int n_y, int n_w, int n_h)
{
	this->n_x = n_x;
	this->n_y = n_y;
	this->n_w = n_w;
	this->n_h = n_h;
}


//Constructeur de copie
CJoueur::CJoueur(const CJoueur& p)
{
	this->n_x = p.n_x;
	this->n_y = p.n_y;
	this->n_w = p.n_w;
	this->n_h = p.n_h;

}

//Destructeur
CJoueur::~CJoueur()
{
}


//Accesseurs

int CJoueur::getX() const
{
	return n_x;
}

int CJoueur::getY() const
{
	return n_y;
}

int CJoueur::getW() const
{
	return n_w;
}

int CJoueur::getH() const
{
	return n_h;
}


//Mutateurs
void CJoueur::setX(int n_x)
{
	this->n_x = n_x;
}

void CJoueur::setY(int n_y)
{
	this->n_y = n_y;
}

void CJoueur::setW(int n_x)
{
	this->n_w = n_w;
}

void CJoueur::setH(int n_y)
{
	this->n_h = n_h;
}
