//
// Created by Nicolas on 11/13/2019.
//

#include "../../../structures/stacks/LinkedStack.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * Read input string, analyze input tokens to know if string is balanced (Map version)
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]){

    string input_string;
    LinkedStack<char> *stack = new LinkedStack<char>();
    const map<char, char> tokens = {
            {'{', '}'},
            {'(', ')'},
            {'[', ']'}
    };
    cout << "Insert a string: ";
    cin >> input_string;

    int error=0;
    for(int i=0; (i < input_string.length()) && (!error); i++){
        for(auto/*map<char, char>::const_iterator*/ iter = tokens.begin(); iter != tokens.end(); ++iter){
            if(input_string.at(i) == iter->first){
                stack->push(iter->first);
            }

            if (input_string.at(i) == iter->second){
                if (stack->empty()){
                    error=1;
                }
                else{
                    if(stack->get_top() != iter->first)
                        error=1;
                    else
                        stack->pop();
                }
            }
        }
    }


    if( (!error) && stack->empty())
        cout << "String is balanced" << endl;
    else
        cout<< "ERROR" << endl;

    return 0;
}