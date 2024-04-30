/*
Author: Medo
Date: 04/19/2023
Description: Conga class
*/

#include "conga.h"
using namespace std;

void Conga::engine_action(Zombie randomZomb)
{
    list.AddToFront(randomZomb);
}

void Conga::caboose_action(Zombie randomZomb)
{
    list.AddToEnd(randomZomb);
}

void Conga::jump_in_action(Zombie randomZomb)
{
    int index = rand() % (list.Length() + 1); // get the index randomly including last element
    list.AddAtIndex(randomZomb, index);
}

void Conga::everyone_out_action(Zombie randomZomb)
{
    try
    {
        list.RemoveAllOf(randomZomb);
    }
    catch (out_of_range &)
    { // if linked list is empty party is over
        cerr << "Party is over" << '\n';
        partyRunning = 0;
    }
}

void Conga::you_out_action(Zombie randomZomb)
{
    try
    {
        list.RemoveTheFirst(randomZomb);
    }
    catch (out_of_range &)
    { // if linked list is empty party is over
        cerr << "Party is over" << '\n';
        partyRunning = 0;
    }
}

void Conga::brains_action(Zombie randomZomb)
{
    engine_action(randomZomb);
    caboose_action(randomZomb);
    int middle = list.Length() / 2;
    list.AddAtIndex(randomZomb, middle);
}

void Conga::rainbow_action(Zombie randomZomb)
{
    engine_action(randomZomb);
    const char *colors = "RYGBCM";
    for (int i = 0; i < 6; i++)
    {
        Zombie zomb(colors[i]);
        caboose_action(zomb);
    }
}

void Conga::friends_action(Zombie randomZomb)
{
    try
    {
        if (list.ElementExists(randomZomb))
        {
            Node<Zombie> *friendZomb = list.Find(randomZomb);
            if ((rand() % 2) == 0)
            {
                list.AddBefore(friendZomb, randomZomb);
            }
            else
            {
                list.AddAfter(friendZomb, randomZomb);
            }
        }
        else
        {
            caboose_action(randomZomb);
        }
    }
    catch (out_of_range &)
    { // if linked list is empty party is over
        cerr << "Party is over" << '\n';
        partyRunning = 0;
    }
}

void Conga::display_conga()
{
    list.PrintList();
}

int Conga::getSize()
{
    return list.Length();
}
// this methods removes the first and last zombie in the conga line when the rounds is divisable by 5
void Conga::remove_first_last()
{
    list.RemoveFromFront();
    list.RemoveFromEnd();
}
// set the random seed entered by the user
void Conga::setRandom(int seed)
{
    srand(seed);
}
