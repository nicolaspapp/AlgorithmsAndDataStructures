//
// Created by Nicolas on 11/13/2019.
//

#ifndef _STACKINFERFACE_H
#define _STACKINFERFACE_H

template<class T>
class StackInterface{
    /**
     * Empuja un elemento al tope de la pila
     * */
    virtual void push(T element) = 0;
    /**
     * Retorna el tope de la pila
     * */
    virtual T get_top() = 0;
    /**
     * Retira el elemento del tope de la pila
     * */
    virtual void pop() = 0;
    /**
     * Retorna si la lista es o no vacía
     * */
    virtual  bool empty() = 0;
};

#endif //_STACKINFERFACE_H
