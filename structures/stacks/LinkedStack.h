//
// Created by Nicolas on 11/13/2019.
//

#ifndef LISTS_1_LINKEDSTACK_H
#define LISTS_1_LINKEDSTACK_H

#include "../lists/LinkedList.h"
#include "../helpers/Node.h"
#include "StackInferface.h"

/**
 * Implementación de una pila de manera enlzada
 * usando la clase LinkedList como base
 * y la interfaz StackInterface
 */
 template<class T>
class LinkedStack: private LinkedList<T>, public StackInterface<T>{
public:
    /**
     * Empuja un elemento al tope de la pila
     * Sobreescribe StackInterface::push
     * */
    void push(T element){
        this->add(element);
    }

    /**
     * Devuelve el top de la pila
     * Sobreescribe StackInterface::get_top
     * */
    T get_top(){
        return this->get_head()->get_data();
    }

    /**
     * Retira el último elemento del tope de la pila
     * Sobreescribe StackInterface::pop
     * */
    void pop(){
        if (this->get_head()) {
            Node<T> *aux;
            aux = this->get_head();
            this->head = this->get_head()->get_next();
            delete aux;
        }
    }

    /**
     * Da visibilidad a un método privado
     * @return
     */
    bool empty(){
        return LinkedList<T>::empty();
    }
};

#endif //LISTS_1_LINKEDSTACK_H
