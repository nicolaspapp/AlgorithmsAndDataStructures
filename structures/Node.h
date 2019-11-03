//
// Created by Nicolas on 11/2/2019.
//

#ifndef ALGORITMOSYED_NODO_H
#define ALGORITMOSYED_NODO_H

#include <cstdlib>
#include <iostream>
#include <iomanip>

template<class Data>
class Node {
private:
    Data data;
    Node *next;
public:
    Node(Data data){
        this->data = data;
        this->next = NULL;
    }
    void setData(Data data){
        this->data = data;
    }
    Data getData(){
        return data;
    }
    bool hasNext(){
        return next != NULL;
    }
    Node *getNext(){
        return next;
    }
    void setNext(Node *next){
        this->next = next;
    }
};


#endif //ALGORITMOSYED_NODO_H
