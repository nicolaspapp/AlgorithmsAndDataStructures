//
// Created by Nicolas on 11/3/2019.
//

#ifndef RECURSIVELINKEDLIST_H
#define RECURSIVELINKEDLIST_H

#include "LinkedList.h"
#include "../Node.h"

template<class T>
class RecursiveLinkedList: public LinkedList<T> {
private:
    Node<T>* get_head(){
        return this->head;
    }

    RecursiveLinkedList* get_rest(){
        return new RecursiveLinkedList(this->head->get_next());
    }

    /**
     * Stores recursivly the entire list data into a String
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

    void print(){
        std::cout << this->recursive_print("") << std::endl;
    }

    int size(){
        if (this->empty()) {
            return 0;
        }
        return 1+this->get_rest()->size();
    }
};
#endif //RECURSIVELINKEDLIST_H
