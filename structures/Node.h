//
// Created by Nicolas on 11/2/2019.
//

#ifndef ALGORITHMS_NODE_H
#define ALGORITHMS_NODE_H

#include <cstdlib>
#include <iostream>
#include <iomanip>

template<class Data>
class Node {
private:
    Data data;
    Node *next;
public:
    Node(Data data){
        this->data = data;
        this->next = NULL;
    }
    void set_data(Data data){
        this->data = data;
    }
    Data get_data(){
        return data;
    }
    bool has_next(){
        return next != NULL;
    }
    Node *get_next(){
        return next;
    }
    void set_next(Node *next){
        this->next = next;
    }
};


#endif //ALGORITHMS_NODE_H
