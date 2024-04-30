/*
Author: Medo
Date: 04/19/2023
Description: zombie class
*/

#ifndef ZOMBIE
#define ZOMBIE

#include "zombie_Alzowaidi.h"
Zombie::Zombie()
{
    this->type = '\0';
}
Zombie::Zombie(char type)
{
    this->type = type;
}

char Zombie::getType()
{
    return type;
}

bool Zombie::operator==(const Zombie &z)
{
    return type == z.type;
}

ostream &operator<<(ostream &os, const Zombie &z)
{
    cout << termcolor::colorize;
    char zombieType = z.type;
    switch (zombieType)
    {
    case 'R':
        os << termcolor::red << "[" << z.type << "]" << termcolor::reset;
        break;
    case 'Y':
        os << termcolor::yellow << "[" << z.type << "]" << termcolor::reset;
        break;
    case 'G':
        os << termcolor::green << "[" << z.type << "]" << termcolor::reset;
        break;
    case 'B':
        os << termcolor::blue << "[" << z.type << "]" << termcolor::reset;
        break;
    case 'C':
        os << termcolor::cyan << "[" << z.type << "]" << termcolor::reset;
        break;
    case 'M':
        os << termcolor::magenta << "[" << z.type << "]" << termcolor::reset;
        break;
    default:
        break;
    }
    return os;
}

#endif // ZOMBIE
