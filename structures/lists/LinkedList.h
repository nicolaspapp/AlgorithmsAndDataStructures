//
// Created by Nicolas on 11/2/2019.
//

#ifndef ALGORITHMS_LINKEDLIST_H
#define ALGORITHMS_LINKEDLIST_H

#include "../helpers/Node.h"
#include "ListInterface.h"
#include <iostream>


/**
 * Estructura de una lista enlazada.
 * Aplica la interfaz de ListInterface
 * */
template<class T>
class LinkedList: public ListInterface<T> {
protected:
    Node<T>* head;
public:
    /**
     * Retorna la cabeza de la lsita
     * */
    Node <T>* get_head() const{
        return head;
    }

    /**
     * Concatenación de listas
     * @param list
     */
    virtual LinkedList<T> operator+=(const LinkedList<T> &list){
        Node<T>* aux = this->head;
        if(aux == NULL){
            this->head = list.get_head();
        }
        else{
            while(aux->get_next() != NULL){
                aux = aux->get_next();
            }
            aux->set_next(list.get_head());
        }
        return *this;
    }

    LinkedList(){
        this->head = NULL;
    }

    /**
     * Sobreescribe ListInterface::add
     * */
    void add(T data){
        Node<T> *aux;
        aux = new Node<T>(data);
        aux->set_next(this->head);
        this->head = aux;
    }

    /**
     * Sobreescribe ListInterface::empty
     * */
    virtual bool empty(){
        return (this->head == 0);
    }

    /**
     * Sobreescribe ListInterface::print
     * */
    virtual void print(){
        Node<T> *aux = this->head;
        if(empty()){
            std::cout << "Empty List!" << std::endl;
        }
        else{
            std::cout << "List is: " << std::endl;
            while(aux != NULL){
                std::cout << std::setw(4) << aux->get_data() << " ";
                aux = aux->get_next();
            }
            std::cout << std::endl;
        }
    }

    /**
     * Sobreescribe ListInterface::size
     * */
    virtual int size(){
        int len = 0;
        Node<T> *aux = this->head;
        while(aux != NULL){
            ++len;
            aux = aux->get_next();
        }
        return len;
    }
};

#endif //ALGORITHMS_LINKEDLIST_H
