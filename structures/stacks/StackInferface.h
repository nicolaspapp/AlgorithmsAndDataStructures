//
// Created by Nicolas on 11/13/2019.
//

#ifndef _STACKINFERFACE_H
#define _STACKINFERFACE_H

template<class T>
class StackInterface{
    virtual void push(T element) = 0;
    virtual T get_top() = 0;
    virtual void pop() = 0;
    virtual  bool empty() = 0;
};

#endif //_STACKINFERFACE_H
