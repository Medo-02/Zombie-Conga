
#ifndef ZOMBIE_ALZOWAIDI
#define ZOMBIE_ALZOWAIDI

#include <iostream>
#include <stdlib.h>
#include "termcolor.hpp"
using namespace std;

class Zombie
{
private:
    char type;

public:
    Zombie();
    Zombie(char type);
    char getType();
    bool operator==(const Zombie &);
    friend std::ostream &operator<<(std::ostream &, const Zombie &);
};

#endif // ZOMBIE_ALZOWAIDI