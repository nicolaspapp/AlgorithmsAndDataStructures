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
    cout << endl;

    cout << "List length: " << l.size() << endl;

    LinkedList<int> r;
    r.add(1);
    r.add(2);
    r.add(3);
    r.print();

    LinkedList<int> p;
    p += l;
    p.print();
    p += r;
    p.print();
    return EXIT_SUCCESS;
}