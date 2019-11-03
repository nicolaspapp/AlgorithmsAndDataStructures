//
// Created by Nicolas on 11/2/2019.
//

#ifndef ALGORITMOSYED_LINKEDLIST_H
#define ALGORITMOSYED_LINKEDLIST_H

#include "../Node.h"
#include "ListInterface.h"
#include <iostream>

template<class T>
class LinkedList: public ListInterface<T> {
private:
    Node<T>* head;
public:
    LinkedList(){
        head = NULL;
    }

    void add(T data){
        Node<T> *aux;
        aux = new Node<T>(data);
        aux->setNext(this->head);
        this->head = aux;
    }


    bool empty(){
        return (head == NULL);
    }


    void print(){
        Node<T> *aux = head;
        if(empty()){
            std::cout << "Empty List!" << std::endl;
        }
        else{
            std::cout << "List is: " << std::endl;
            while(aux != NULL){
                std::cout << std::setw(4) << aux->getData() << " ";
                aux = aux->getNext();
            }
            std::cout << std::endl;
        }
    }
};

#endif //ALGORITMOSYED_LINKEDLIST_H
