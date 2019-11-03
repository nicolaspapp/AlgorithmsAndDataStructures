//
// Created by Nicolas on 11/3/2019.
//
#include "../../../structures/lists/LinkedList.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    LinkedList<int> l;
    l.print();
    l.add(5);
    l.add(9);
    l.add(-3);
    l.print();
    cout << endl << endl;
    return EXIT_SUCCESS;
}