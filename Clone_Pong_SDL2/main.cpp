#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include <string>


#include "CJoueur.h"
#include "CBalle.h"

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
    surfaceBall = SDL_LoadBMP("./Sprite/balle.bmp");
    textureBall = SDL_CreateTextureFromSurface(renderer, surfaceBall);
    SDL_FreeSurface(surfaceBall);

    int scoring1 = 0;// servira pour le changement de score sans devoir créer d'autres image à la suite
    int *Pscoring1 = &scoring1;// servira pour le changement de score sans devoir créer d'autres image à la suite

    string scrlink1 = "./Sprite/" + to_string(*Pscoring1) + ".bmp";// convertie l'integer en chaine de caractères
    //IMG Score Joueur1
    SDL_Surface* surfaceSCR1;
    SDL_Texture* textureSCR1;
    surfaceSCR1 = SDL_LoadBMP(const_cast<char*>(scrlink1.c_str())); //permet de l'intégrer à une adresse et lire l'image
    textureSCR1 = SDL_CreateTextureFromSurface(renderer, surfaceSCR1);
    SDL_FreeSurface(surfaceSCR1);

    int scoring2 = 0;
    int *Pscoring2 = &scoring2;
    string scrlink2 = "./Sprite/" + to_string(*Pscoring2) + ".bmp";
    //IMG Score Joueur2
    SDL_Surface* surfaceSCR2;
    SDL_Texture* textureSCR2;
    surfaceSCR2 = SDL_LoadBMP(const_cast<char*>(scrlink2.c_str()));
    textureSCR2 = SDL_CreateTextureFromSurface(renderer, surfaceSCR2);
    SDL_FreeSurface(surfaceSCR2);


    //IMG Joueur1
    SDL_Surface* surfaceJ1;
    SDL_Texture* textureJ1;
    surfaceJ1 = SDL_LoadBMP("./Sprite/Joueur1.bmp");
    textureJ1 = SDL_CreateTextureFromSurface(renderer, surfaceJ1);
    SDL_FreeSurface(surfaceJ1);
    //IMG Joueur2
    SDL_Surface* surfaceJ2;
    SDL_Texture* textureJ2;
    surfaceJ2 = SDL_LoadBMP("./Sprite/Joueur2.bmp");
    textureJ2 = SDL_CreateTextureFromSurface(renderer, surfaceJ2);
    SDL_FreeSurface(surfaceJ2);


    bool quit = false; // Lier à la présence de la fenêtre
    //bool endplay = false; //sert pour la fin de partie

    //Initialisation emplacement et taille


    //init Score Joueur1
    SDL_Rect Score1;
    Score1.x = 300;
    Score1.y = 30;
    Score1.w = Score1.h = 32;


    //init Score Joueur2
    SDL_Rect Score2;
    Score2.x = 450;
    Score2.y = 30;
    Score2.w = Score2.h = 32;


    //Init raquette Joueur1
    CJoueur Raquette1(760, (600 / 2) - (100 / 2), 32, 100);
    SDL_Rect playerPadle1;
    playerPadle1.x = Raquette1.getX();
    playerPadle1.y = Raquette1.getY(); 
    playerPadle1.w = Raquette1.getW();
    playerPadle1.h = Raquette1.getH();



    //Init raquette Joueur2
    CJoueur Raquette2(10, (600 / 2) - (100 / 2), 32, 100 );
    SDL_Rect playerPadle2;
    playerPadle2.x = Raquette2.getX();
    playerPadle2.y = Raquette2.getY();
    playerPadle2.w = Raquette2.getW();
    playerPadle2.h = Raquette2.getH();

    //Init Balle
    srand(time(NULL));
    CBalle cBalle(((800 / 2) - (20 / 2)), ((600 / 2) - (20 / 2)), 32, 32, 0, 0);
    //rand() % 4 --> direction de 0 à 3, chiffres positifs
    //(rand() % 5) - 2 --> direction de -2 à 2, permet d'avoir des chiffres négatifs et positifs

       SDL_Rect ball;
       ball.x = cBalle.getX();
       ball.y = cBalle.getY();
       ball.w = cBalle.getW();
       ball.h = cBalle.getH();

       cBalle.setspeedX((rand() % 5) - 2);
       cBalle.setspeedY((rand() % 5) - 2);



       //Sert au déplacement de la balle
       float bX = ball.x;
       float bY = ball.y;


      

       // Jeu
    while (!quit) {

         //Event
        while (SDL_PollEvent(&e) > 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            else if (e.type == SDL_KEYDOWN) {

                //Déplacement Joueur1;                
                if (e.key.keysym.sym == SDLK_UP) {//Vers le haut;
                    playerPadle1.y -= 50;
                }
                else if (e.key.keysym.sym == SDLK_DOWN) { //Vers le bas;
                    playerPadle1.y += 50;
                }
                //Limitation du déplacement des raquettes
                //Evite le hors écran
                if (playerPadle1.y < 0) {
                    playerPadle1.y = 0;
                }
                else if (playerPadle1.y > 600 - playerPadle1.h) {
                    playerPadle1.y = 600 - playerPadle1.h;
                }

                //Déplacement Joueur2
                if (e.key.keysym.sym == SDLK_z) {//Vers le haut;
                    playerPadle2.y -= 50;
                }
                else if (e.key.keysym.sym == SDLK_s) { //Vers le bas;
                    playerPadle2.y += 50;
                }

                //Limitation du déplacement des raquettes
                //Evite le hors écran
                if (playerPadle2.y < 0) {
                    playerPadle2.y = 0;
                }
                else if (playerPadle2.y > 600 - playerPadle2.h) {
                    playerPadle2.y = 600 - playerPadle2.h;
                }



            }

        }
             // Update

             //déplacement de la balle
             cBalle.DplcmntB();

             

             ball.x += cBalle.getspeedX(); //sert à la direction/déplacement de la balle
             ball.y += cBalle.getspeedY();


             //Rebond parrois
           //  cBalle.CllsnandRbd(bX, bY, ball, playerPadle1, playerPadle2);
            // cBalle.CllsnandRbd1(ball, playerPadle1, playerPadle2, Pscoring1, Pscoring2, surfaceSCR1, surfaceSCR2, textureSCR1, textureSCR2, scrlink1, scrlink2, renderer);

             textureSCR1 = cBalle.CllsnandRbd1(ball,  Pscoring1,  surfaceSCR1,  textureSCR1,  scrlink1, renderer);
             textureSCR2 = cBalle.CllsnandRbd2(ball, Pscoring2,surfaceSCR2, textureSCR2, scrlink2, renderer);

             cBalle.CllsnandRbd3(ball, playerPadle1, playerPadle2);





             // Renderer et dessin
             SDL_SetRenderDrawColor(renderer, 0, 27, 27, 27);// Color le fond en noir
             SDL_RenderClear(renderer); // Efface l'écran et les couleur disposées;


               //écriture du score
              SDL_RenderCopy(renderer, textureSCR1, NULL, &Score1);
               SDL_RenderCopy(renderer, textureSCR2, NULL, &Score2);

              //dessiner les raquettes de joueurs
              SDL_RenderCopy(renderer, textureJ1, NULL, &playerPadle1);
              SDL_RenderCopy(renderer, textureJ2, NULL, &playerPadle2);

        
             //dessiner la balle
              SDL_RenderCopy(renderer, textureBall, NULL, &ball);






              //Text replay + recommencer une partie
              if (scoring1 >= 3 || scoring2 >= 3) {

                  //endplay = true;

                  SDL_RenderClear(renderer); // Efface l'écran et les couleur disposées;


                  //Mise en place du texte Replay
                  //IMG Titre Replay
                  SDL_Surface* surfaceTexte1;
                  SDL_Texture* textureTexte1;
                  surfaceTexte1 = SDL_LoadBMP("./Sprite/strgReplay.bmp");
                  textureTexte1 = SDL_CreateTextureFromSurface(renderer, surfaceTexte1);
                  SDL_FreeSurface(surfaceTexte1);


                  SDL_Rect Texte1;
                  Texte1.x = 400;
                  Texte1.y = 200;
                  Texte1.w = 180;
                  Texte1.h = 152;

                  SDL_Surface* surfaceTexte2;
                  SDL_Texture* textureTexte2;
                  surfaceTexte2 = SDL_LoadBMP("./Sprite/touch.bmp");
                  textureTexte2 = SDL_CreateTextureFromSurface(renderer, surfaceTexte2);
                  SDL_FreeSurface(surfaceTexte2);


                  SDL_Rect Texte2;
                  Texte2.x = 500;
                  Texte2.y = 250;
                  Texte2.w = 180;
                  Texte2.h = 32;

                  SDL_Surface* surfaceTexte3;
                  SDL_Texture* textureTexte3;
                  surfaceTexte3 = SDL_LoadBMP("./Sprite/any.bmp");
                  textureTexte3 = SDL_CreateTextureFromSurface(renderer, surfaceTexte3);
                  SDL_FreeSurface(surfaceTexte3);


                  SDL_Rect Texte3;
                  Texte3.x = 500;
                  Texte3.y = 300;
                  Texte3.w = 180;
                  Texte3.h = 32;

                  SDL_Surface* surfaceTexte4;
                  SDL_Texture* textureTexte4;
                  surfaceTexte4 = SDL_LoadBMP("./Sprite/button.bmp");
                  textureTexte4 = SDL_CreateTextureFromSurface(renderer, surfaceTexte4);
                  SDL_FreeSurface(surfaceTexte4);


                  SDL_Rect Texte4;
                  Texte4.x = 500;
                  Texte4.y = 350;
                  Texte4.w = 180;
                  Texte4.h = 32;


                  SDL_RenderCopy(renderer, textureTexte1, NULL, &Texte1);
                  SDL_RenderCopy(renderer, textureTexte2, NULL, &Texte2);
                  SDL_RenderCopy(renderer, textureTexte3, NULL, &Texte3);
                  SDL_RenderCopy(renderer, textureTexte4, NULL, &Texte4);


                  // Rejouer une partie






              }



          //}

            // Affiche le nouveau contenu
            SDL_RenderPresent(renderer);

            SDL_Delay(1000 / 60);
     }






        //Si quit = true

        //Fin
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

	return 0;
}