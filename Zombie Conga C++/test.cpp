
#include <iostream>
#include <stdlib.h>
#include "linkedlist_Alzowaidi.hpp"
using namespace std;

int main(int argc, char **argv)
{
    LinkedList<int> list;
    for (int i = 40; i > 0; i--)
    {
        list.AddToFront(i);
    }
    list.PrintList();
    cout << "\n\n\n\n";
    for (int i = 41; i < 81; i++)
    {
        list.AddToEnd(i);
    }
    list.PrintList();
    cout << "\n\n\n\n";
    for (int i = 81; i < 121; i++)
    {
        list.AddAtIndex(i, i - 1);
    }
    list.PrintList();
    cout << "\n\n\n\n";

    cout << list.Length() << endl;

    for (int i = 1; i < 61; i++)
    {
        list.AddBefore(list.Find(i), i);
    }
    list.PrintList();
    cout << "\n\n\n\n";
    for (int i = 120; i > 60; i--)
    {
        list.AddAfter(list.Find(i), i * 2);
    }
    list.PrintList();
    cout << "\n\n\n\n";
    cout << list.Find(list.RetrieveFront()) << endl;
    cout << list.Find(list.RetrieveEnd()) << endl;

    list.AddToEnd(700);
    list.RemoveFromEnd();
    cout << list.Find(list.RetrieveEnd()) << endl;
    cout << list.Length();
    cout << "\n\n\n\n";

    for (int i = 1; i < 61; i++)
    {
        list.RemoveAfter(list.Find(i * 2));
    }
    list.PrintList();
    cout << "\n\n\n\n";

    for (int i = 1; i < 61; i++)
    {
        list.RemoveBefore(list.Find(i));
    }
    list.PrintList();
    cout << "\n\n\n\n";
    cout << list.Find(list.RetrieveFront()) << endl;
    cout << list.Find(list.RetrieveEnd()) << endl;
    cout << "\n\n\n\n";

    for (int i = 1; i < 11; i++)
    {
        list.AddAtIndex(i, i);
    }
    for (int i = 1; i < 11; i++)
    {
        cout << i << " " << list.ElementExists(i) << endl;
    }
    list.PrintList();
    cout << "\n\n\n\n";
    cout << "700 " << list.ElementExists(700) << endl;
    cout << "214 " << list.IndexOf(214) << endl;
    return 0;
}