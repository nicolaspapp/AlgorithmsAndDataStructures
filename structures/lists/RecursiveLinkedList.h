//
// Created by Nicolas on 11/3/2019.
//

#ifndef RECURSIVELINKEDLIST_H
#define RECURSIVELINKEDLIST_H

#include "LinkedList.h"
#include "../helpers/Node.h"
#include <string>
#include <sstream>

/**
 * Implementacion alternativa a una lista enlazada
 * Pero planteada de forma recursiva en vez de iterativa
 * */
template<class T>
class RecursiveLinkedList: public LinkedList<T> {
private:
    /**
     * Retorna la cabeza de la lista
     * */
    Node<T>* get_head(){
        return this->head;
    }

    /**
     * Retorna el resto de la lista (lista - cabeza)
     * */
    RecursiveLinkedList* get_rest(){
        return new RecursiveLinkedList(this->head->get_next());
    }

    /**
     * Guarda recursivamente toda la lista en un string
     * @param p
     * @return
     */
    std::string recursive_print(std::string p){
        if (this->empty()) {
            return p;
        } else {
            std::ostringstream stm;
            stm << this->get_head()->get_data() <<" "<< this->get_rest()->recursive_print(p);
            return stm.str();
        }
    }

public:
    RecursiveLinkedList(Node<T>* head) {
        this->head = head;
    }

    RecursiveLinkedList() {
        this->head = NULL;
    }

    /**
     * Sobreescribe LinkedList::print
     * */
    void print(){
        std::cout << this->recursive_print("") << std::endl;
    }

    /**
     * Sobreescribe LinkedList::size
     * */
    int size(){
        if (this->empty()) {
            return 0;
        }
        return 1+this->get_rest()->size();
    }
};
#endif //RECURSIVELINKEDLIST_H
