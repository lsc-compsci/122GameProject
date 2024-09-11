/*
* Programmers: Sher Chhi LY, James Lee, Angel Ramirez, Ivan Quintero
* Class: CptS 122
* Instructor: Andy O' Fallon
* Description: PA 9 - Game Project (Spaces Invaders)
*/

#include "bundler.h"
#include "Wrapper.h"
#include "TestCases.h"

#include "SFML/Audio.hpp"

int main()
{
    //Test Cases;
    //Cases.testEnemyHit();
    //Cases.testGameOver();
    //Cases.testLoadImg();
    //Cases.testPlayerInput();
    //Cases.testPlayerHealth();

    system("Color A");

    sf::SoundBuffer buff;

    int run = 1; 
    Wrapper game;

    while (run != 0)
    {
        int choice = 0;

        std::cout << "  XXXXX XXXXX   XXXX     XXXXX XXXXXX  XXXXXX XXX   XX XXX     XXX  XXXX     XXXXX   XXXXXX XXXXX   XXXXXXX " << std::endl;
        std::cout << " XX     XX  XX XX  XX   XX     XX        XX   XXXX  XX  XX     XX  XX  XX    XX  XX  XX     XX  XX     XXX  " << std::endl;
        std::cout << "  XXXX  XXXXX XXXXXXXX XX      XXXXX     XX   XX XX XX   XX   XX  XXXXXXXX   XX   XX XXXXX  XXXXX     XX    " <<std::endl;
        std::cout << "     XX XX   XX      XX XX     XX        XX   XX  XXXX    XXXXX  XX      XX  XX  XX  XX     XX  XX   XXX    " << std::endl;
        std::cout << " XXXXX  XX  XX        XX XXXXX XXXXXX  XXXXXX XX   XXX     XXX  XX        XX XXXXX   XXXXXX XX   XX XXXXXXX " << std::endl;
        std::cout << "                                              --- Main Menu ---"<< std::endl;
        std::cout << "                                               (1) Play Game"<< std::endl;
        std::cout << "                                               (2) Instructions"<< std::endl;
        std::cout << "                                               (3) Exit"<< std::endl;
        std::cin >> choice;


        switch (choice)
        {
        case 1:
            game.runGame();
            system("cls");
            break;
        case 2:
            system("cls");
            std::cout << "                                        ----- How to Play -----" << std::endl;
            std::cout << "                                   MOVEMENT: Left & Right Arrow keys" << "\n" << std::endl;
            std::cout << "                                   SHOOT: Spacebar" << "\n" << std::endl;
            std::cout << "                                   GAMEPLAY: You have 3 lives" << std::endl;
            std::cout << "                                             Player loses Health when the Enemy gets past them" << std::endl;
            std::cout << "                                             Enemy Speed Will Increase As You Progress" << std::endl;
            std::cout << "                                             Lose all 3 lives and its Game Over." << "\n" << std::endl;
            std::cout << "                                             Goodluck!" << std::endl;
            system("pause");
            system("cls");
            break;
        case 3:
            std::cout << "Thanks for Playing!" << std::endl;
            run = 0;
            break;
        }
    }


	return 0;
}

