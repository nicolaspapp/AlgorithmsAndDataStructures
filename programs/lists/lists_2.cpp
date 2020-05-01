//
// Created by Nicolas on 11/3/2019.
//
#include "../../../structures/lists/RecursiveLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    RecursiveLinkedList<int> *l=new RecursiveLinkedList<int>();
    RecursiveLinkedList<int> *r=new RecursiveLinkedList<int>();
    RecursiveLinkedList<int> *l2=new RecursiveLinkedList<int>();
    l->add(11);
    l->add(22);
    l->add(33);
    r->add(1);
    r->add(2);
    l->print();
    r->print();
    //cout<< "suma:"<<l->suma(0)<<endl;
    cout << "List l size: " << l->size() << endl;
    cout << "List r size: " << r->size() << endl;
    system("PAUSE");
    return EXIT_SUCCESS;

}