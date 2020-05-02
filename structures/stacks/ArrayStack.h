//
// Created by Nicolas on 11/13/2019.
//

#ifndef _ARRAYSTACK_H
#define _ARRAYSTACK_H

#include "StackInferface.h"
#include <stdexcept>

/**
 * Implementación de una pila basada en un arreglo
 * con un tamaño máximo
 * */
template<class T>
class ArrayStack:  public StackInterface<T>{
private:
    const int capacity;
    int top_ptr;
    T *buffer;
public:

    /**
     * Constructor
     * @param capacity tamaño máximo de la pila
     * 
     * */
    ArrayStack(const int capacity): capacity(capacity), top_ptr(0) {
        // Initialization list allows us to initiate values of const in clases

        // Buffer initialization
        buffer = new T[capacity];
    }

    /**
     * Sobreescribe StackInterface::push
     * */
    void push(T element) {
        if(top_ptr == capacity){
            throw std::out_of_range("Stack beyond capacity!");
        }
        buffer[top_ptr++] = element;
    }

    /**
     * Sobreescribe StackInterface::get_top
     * */
    T get_top() {
        if(top_ptr){
            return buffer[top_ptr-1];
        }
        else{
            throw std::out_of_range("Stack is empty");
        }
    }

    /**
     * Sobreescribe StackInterface::pop
     * */
    void pop() {
        if(top_ptr == 0){
            throw std::out_of_range("Cannot pop on empty stack!");
        }
        --top_ptr;
    }


    /**
     * Sobreescribe StackInterface::empty
     * */
    bool empty() {
        return top_ptr == 0;
    }
};

#endif //_ARRAYSTACK_H
