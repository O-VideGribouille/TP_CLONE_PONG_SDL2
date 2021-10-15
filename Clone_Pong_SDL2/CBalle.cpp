#include "CBalle.h"

CBalle::CBalle()
{
	this->n_x = 0;
	this->n_y = 0;
	this->n_w = 0;
	this->n_h = 0;

	this->speedX = 0;
	this->speedY = 0;


}


CBalle::CBalle(int n_x, int n_y, int n_w, int n_h, float speedX, float speedY)
{
	this->n_x = n_x;
	this->n_y = n_y;
	this->n_w = n_w;
	this->n_h = n_h;

	this->speedX = speedX;
	this->speedY = speedY;

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

float CBalle::getspeedX() const
{
	return speedX;
}

float CBalle::getspeedY() const
{
	return speedY;
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

void CBalle::setspeedX(float speedX)
{
	this->speedX = speedX;
}

void CBalle::setspeedY(float speedY)
{
	this->speedY = speedY;
}


void CBalle::DplcmntB()
{
	

	//Accélération de la balle

	if (speedX >= -0.01f && speedX <= 0.01f) {
		speedX = 1.0f;
	}
	if (speedY >= -0.01f && speedY <= 0.01f) {
		speedY = -1.0f;
	}

	speedX /= 20.0f;
	speedY /= 20.0f;





}






