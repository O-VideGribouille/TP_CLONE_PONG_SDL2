#include "CBalle.h"

CBalle::CBalle()
{
	this->n_x = 0;
	this->n_y = 0;
	this->n_w = 0;
	this->n_h = 0;


}


CBalle::CBalle(int n_x, int n_y, int n_w, int n_h)
{
	this->n_x = n_x;
	this->n_y = n_y;
	this->n_w = n_w;
	this->n_h = n_h;

}


//destructeur
CBalle::~CBalle()
{
}


//Accesseurs
int CBalle::getX() const
{
	return n_x;
}

int CBalle::getY() const
{
	return n_y;
}

int CBalle::getW() const
{
	return n_w;
}

int CBalle::getH() const
{
	return n_h;
}



//Mutateurs
void CBalle::setX(int n_x)
{
	this->n_x = n_x;
}

void CBalle::setY(int n_y)
{
	this->n_y = n_y;
}

void CBalle::setW(int n_x)
{
	this->n_w = n_w;
}

void CBalle::setH(int n_y)
{
	this->n_h = n_h;
}

/*
void CBalle::chgmntDrect()
{
	//avec un Random
	srand(time(NULL));
	float speedX = (rand() % 5) - 2;
	float speedY = (rand() % 5) - 2;
	//rand() % 4 --> direction de 0 à 3, chiffres positifs
	//(rand() % 5) - 2 --> direction de -2 à 2, permet d'avoir des chiffres négatifs et positifs

}*/





