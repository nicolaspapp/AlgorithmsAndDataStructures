//
// Created by Nicolas on 11/3/2019.
//

#ifndef ALGORITHMS_LISTINTERFACE_H
#define ALGORITHMS_LISTINTERFACE_H

template<class T>
class ListInterface{
public:
    /**
     * Inserta un nodo al principio de una lista
     * @param data
     */
    virtual void add(T data) = 0;

    /**
     * Retorna si la lista es o no vacia
     * @return
     */
    virtual bool empty() = 0;

    /**
     * Imprime la estructura de datos
     */
    virtual void print() = 0;

    /**
     * Retorna la cantidad de elementos de la lista
     */
    virtual int size() = 0;
};

#endif //ALGORITHMS_LISTINTERFACE_H
