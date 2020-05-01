//
// Created by Nicolas on 11/13/2019.
//

#ifndef LISTS_1_LINKEDSTACK_H
#define LISTS_1_LINKEDSTACK_H

#include "../lists/LinkedList.h"
#include "../helpers/Node.h"
#include "StackInferface.h"

/**
 * Stack implementation using a LinkedList as a base
 * Inherits private from LinkedList: We want to hide all methods that do not correspond to
 * a stack
 */
 template<class T>
class LinkedStack: private LinkedList<T>, public StackInterface<T>{
public:
    void push(T element){
        this->add(element);
    }

    T get_top(){
        return this->get_head()->get_data();
    }

    void pop(){
        if (this->get_head()) {
            Node<T> *aux;
            aux = this->get_head();
            this->head = this->get_head()->get_next();
            delete aux;
        }
    }

    /**
     * Add visibitlity to a method that its otherwise private
     * @return
     */
    bool empty(){
        return LinkedList<T>::empty();
    }
};

#endif //LISTS_1_LINKEDSTACK_H
