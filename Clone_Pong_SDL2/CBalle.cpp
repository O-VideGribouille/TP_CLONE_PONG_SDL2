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

	//speedX += (speedX/abs(speedX))/1000;
	//speedY += (speedY / abs(speedY))/1000;





}

//void CBalle::CllsnandRbd(float bX, float bY, SDL_Rect ball, SDL_Rect playerPadle1, SDL_Rect playerPadle2)

//ces deux fonction permette le changement de texture sans difficulté
SDL_Texture* CBalle::CllsnandRbd1(SDL_Rect &ball, int* Pscoring1, SDL_Surface* surfaceSCR1, SDL_Texture* textureSCR1, string scrlink1, SDL_Renderer* renderer)
{

	//gauche + collision
	if (ball.x <= 0.0f) {
		ball.x = 0.0f;
		speedX *= -1.0f;


		*Pscoring1 += 1;


		/*ball.x = getX();
		ball.y = getY();*/
		
		ball.x = (800 / 2) - (20 / 2);
		ball.y = (600 / 2) - (20 / 2);

		setspeedX((rand() % 5) - 2);
		setspeedY((rand() % 5) - 2);


	}

	scrlink1 = "./Sprite/" + to_string(*Pscoring1) + ".bmp";
	surfaceSCR1 = SDL_LoadBMP(const_cast<char*>(scrlink1.c_str()));
	//textureSCR1 = SDL_CreateTextureFromSurface(renderer, surfaceSCR1); // problème avec la texture, ne fait pas le changement
	//SDL_FreeSurface(surfaceSCR1);

	return SDL_CreateTextureFromSurface(renderer, surfaceSCR1);

}

SDL_Texture* CBalle::CllsnandRbd2(SDL_Rect &ball, int* Pscoring2, SDL_Surface* surfaceSCR2, SDL_Texture* textureSCR2, string scrlink2, SDL_Renderer* renderer)
{


	//droite + collision
	if (ball.x >= 800.0f - ball.w) {
		ball.x = 800.0f - ball.w;
		speedX *= -1.0f;


		*Pscoring2 += 1;

		ball.x = (800 / 2) - (20 / 2);
		ball.y = (600 / 2) - (20 / 2);

		setspeedX((rand() % 5) - 2);
		setspeedY((rand() % 5) - 2);


	}

	scrlink2 = "./Sprite/" + to_string(*Pscoring2) + ".bmp";
	surfaceSCR2 = SDL_LoadBMP(const_cast<char*>(scrlink2.c_str()));
	//textureSCR2 = SDL_CreateTextureFromSurface(renderer, surfaceSCR2); // problème avec la texture, ne fait pas le changement
	//SDL_FreeSurface(surfaceSCR2);

	return SDL_CreateTextureFromSurface(renderer, surfaceSCR2);



}

void CBalle::CllsnandRbd3(SDL_Rect &ball, SDL_Rect playerPadle1, SDL_Rect playerPadle2)
{
	
	//haut
	if (ball.y <= 0.0f) {
		ball.y = 0.0f;
		speedY *= -1.0f;


	}

	//bas
	if (ball.y >= 600.0f - ball.h) {
		ball.y = 600.0f - ball.h;
		speedY *= -1.0f;

	}




	/*//Collision raquettre Joueur1
	//la colision se fait du côté droit
	if (ball.x + ball.w >= playerPadle1.x
		&& ball.x + ball.w < playerPadle1.x + playerPadle1.w
		&& ball.y >= playerPadle1.y
		&& ball.y < playerPadle1.y + playerPadle1.h) {
		ball.x = playerPadle1.x - ball.w;
		speedX = -abs(speedX)*1.01;

	}

	//Collision raquettre Joueur2
	//la colision se fait du côté droit
	if (ball.x >= playerPadle2.x
		&& ball.x < playerPadle2.x + playerPadle2.w
		&& ball.y >= playerPadle2.y
		&& ball.y < playerPadle2.y + playerPadle2.h) {
		ball.x = playerPadle2.x + playerPadle2.w;
		speedX = abs(speedX)*1.01;

	}*/

	//Collision raquettre Joueur1
	//la colision se fait du côté droit
	/*if ((ball.x + ball.w >= playerPadle1.x
		&& ball.x + ball.w < playerPadle1.x + playerPadle1.w
		&& ball.y >= playerPadle1.y
		&& ball.y < playerPadle1.y + playerPadle1.h)
		||
		(ball.x >= playerPadle2.x
		&& ball.x < playerPadle2.x + playerPadle2.w
		&& ball.y >= playerPadle2.y
		&& ball.y < playerPadle2.y + playerPadle2.h)) {

		speedX = -speedX * 1.01;

		if (ball.x + ball.w >= playerPadle1.x
			&& ball.x + ball.w < playerPadle1.x + playerPadle1.w
			&& ball.y >= playerPadle1.y
			&& ball.y < playerPadle1.y + playerPadle1.h) {

			ball.x = playerPadle1.x - ball.w;
		} else {
			ball.x = playerPadle2.x + playerPadle2.w;
		}
	}*/


	if (ball.x + ball.w >= playerPadle1.x
		&& ball.x + ball.w < playerPadle1.x + playerPadle1.w
		&& ball.y >= playerPadle1.y
		&& ball.y < playerPadle1.y + playerPadle1.h) {
		ball.x = playerPadle1.x - ball.w;
		//speedX *= -1.0f;
		
		//speedX = -abs(speedX) * 1.01;

		speedX = -speedX * 1.01;

	}

	//Collision raquettre Joueur2
	//la colision se fait du côté droit
	if (ball.x >= playerPadle2.x
		&& ball.x < playerPadle2.x + playerPadle2.w
		&& ball.y >= playerPadle2.y
		&& ball.y < playerPadle2.y + playerPadle2.h) {
		ball.x = playerPadle2.x + playerPadle2.w;
		//speedX *= -1.0f;
		
		//speedX = abs(speedX) * 1.01;


		speedX = -speedX * 1.06; // augmentation de SpedX, sinon la vitesse diminue
	}

}





