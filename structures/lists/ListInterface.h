//
// Created by Nicolas on 11/3/2019.
//

#ifndef ALGORITHMS_LISTINTERFACE_H
#define ALGORITHMS_LISTINTERFACE_H

template<class T>
class ListInterface{
public:
    /**
     * Insert a node in front of the LinkedList
     * @param data
     */
    virtual void add(T data) = 0;

    /**
     * Check if LinkedList is empty
     * @return
     */
    virtual bool empty() = 0;

    /**
     * Print LinkedList
     */
    virtual void print() = 0;

    /**
     * Return list size
     */
    virtual int size() = 0;
};

#endif //ALGORITHMS_LISTINTERFACE_H
