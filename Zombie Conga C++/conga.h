/*
Author: Medo
Date: 04/19/2023
Description: Conga class
*/

#ifndef CONGA
#define CONGA

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "linkedlist_Alzowaidi.hpp"
#include "zombie_Alzowaidi.h"
using namespace std;

class Conga
{

public:
    LinkedList<Zombie> list;
    int partyRunning; // variable for checking if the party is over or not

    Conga() // constructor
    {
        srand(time(0));
        partyRunning = 1;
    }
    // forward declaration of the methods
    void engine_action(Zombie);
    void caboose_action(Zombie);
    void jump_in_action(Zombie);
    void everyone_out_action(Zombie);
    void you_out_action(Zombie);
    void brains_action(Zombie);
    void rainbow_action(Zombie);
    void friends_action(Zombie);
    void display_conga();
    int getSize();
    void remove_first_last();
    void setRandom(int);
};

#endif // CONGA
