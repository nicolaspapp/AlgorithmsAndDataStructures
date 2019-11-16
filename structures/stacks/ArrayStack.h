//
// Created by Nicolas on 11/13/2019.
//

#ifndef _ARRAYSTACK_H
#define _ARRAYSTACK_H

#include "StackInferface.h"
#include <stdexcept>

template<class T>
class ArrayStack:  public StackInterface<T>{
private:
    const int capacity;
    int top_ptr;
    T *buffer;
public:
    ArrayStack(const int capacity): capacity(capacity), top_ptr(0) {
        // Initialization list allows us to initiate values of const in clases

        // Buffer initialization
        buffer = new T[capacity];
    }

    void push(T element) {
        if(top_ptr == capacity){
            throw std::out_of_range("Stack beyond capacity!");
        }
        buffer[top_ptr++] = element;
    }

    T get_top() {
        if(top_ptr){
            return buffer[top_ptr-1];
        }
        else{
            throw std::out_of_range("Stack is empty");
        }
    }

    void pop() {
        if(top_ptr == 0){
            throw std::out_of_range("Cannot pop on empty stack!");
        }
        --top_ptr;
    }

    bool empty() {
        return top_ptr == 0;
    }
};

#endif //_ARRAYSTACK_H
