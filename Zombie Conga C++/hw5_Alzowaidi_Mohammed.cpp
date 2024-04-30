/*
Author: Medo
Date: 04/19/2023
Description: zombie conga line implement linkedlist and zombie class and conga class
iterate to create a conga line and randomly generate zombies with action to step in or out of the line
usage: [-s seed]
*/

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <time.h>
#include "conga.h"

Zombie generateZombie();

int main(int argc, char **argv)
{
    // command line interface and program usage
    int randomSeed = -1;
    if (argc != 1 && argc != 3)
    {
        std::cout << "usage: exe [-s seed]" << endl;
        return 0;
    }
    if (argc == 3)
    {
        if (!(isdigit(*argv[2])) || strcmp(argv[1], "-s") != 0)
        {
            std::cout << "usage: exe [-s seed]" << endl;
            return 0;
        }
        else
        {
            randomSeed = atoi(argv[2]);
        }
    }

    // initial setup for conga line
    Conga conga;
    if (randomSeed == -1) // if user has entered seed set the random
    {
        srand(time(0));
    }
    else
    {
        srand(randomSeed);
        conga.setRandom(randomSeed);
    }

    Zombie z1(generateZombie());
    conga.rainbow_action(z1);
    for (int i = 0; i < 3; i++)
    {
        conga.brains_action(generateZombie());
    }
    // intial setup for conga line finished
    //-------------------------------------

    // running the iteration to display rounds
    //----------------------------------------
    int rounds = 0;
    rounds++;
    char ans = '\0';

    std::cout << "How many rounds do you want to run?: ";
    std::cin >> rounds;

    while (conga.partyRunning == 1) // Keep looping until user exits or conga line has no zombies
    {
        for (int i = 0; i < rounds; i++)
        {
            // if party is over break the loop
            if (conga.partyRunning != 1)
            {
                break;
            }
            // remove first and last zombie
            if (i % 5 == 0)
            {
                conga.remove_first_last();
            }
            int choice = rand() % 8;
            Zombie randZomb = generateZombie();
            std::cout << "Round: " << i << endl;
            std::cout << "Size: " << conga.getSize() << " :: ";
            conga.display_conga();
            std::cout << "New BaseZombie : " << randZomb << " -- ";
            switch (choice) // print the conga line actions randomly
            {
            case 0:
                conga.engine_action(randZomb);
                std::cout << "Action: [Engine!]" << endl;
                break;
            case 1:
                conga.caboose_action(randZomb);
                std::cout << "Action: [Caboose!]" << endl;
                break;
            case 2:
                conga.jump_in_action(randZomb);
                std::cout << "Action: [Jump in the Line!]" << endl;
                break;
            case 3:
                conga.everyone_out_action(randZomb);
                cout << "Action: [Everyone Out!]" << endl;
                break;
            case 4:
                conga.you_out_action(randZomb);
                std::cout << "Action: [You Out!]" << endl;
                break;
            case 5:
                conga.brains_action(randZomb);
                std::cout << "Action: [Brains!]" << endl;
                break;
            case 6:
                conga.rainbow_action(randZomb);
                std::cout << "Action: [Rainbow Brains!]" << endl;
                break;
            case 7:
                conga.friends_action(randZomb);
                std::cout << "Action: [Making New Frineds!]" << endl;
                break;
            default:
                break;
            } // print the new conga line
            std::cout << "The conga line is now:" << endl;
            std::cout << "Size: " << conga.getSize() << " :: ";
            conga.display_conga();
            std::cout << "**************************************************\n"
                      << endl;
        } // if party is over exist the loop
        if (conga.partyRunning != 1)
        {
            break;
        } // check if the user want to continue the party
        std::cout << "Do you want to continue the party? (y/n): ";
        std::cin >> ans;
        if (ans == 'n') // if not repeat the conga line rounds
        {
            break;
        }
        std::cout << "How many rounds do you want to run?: ";
        std::cin >> rounds;
    }

    std::cout << "Party has ended" << endl;
    return 0;
}

// function responsible for generating a random zombie
Zombie generateZombie()
{
    const char *colors = "RYGBCM";
    char randomCol = colors[rand() % 6];
    Zombie randomZomb(randomCol);

    return randomZomb;
}