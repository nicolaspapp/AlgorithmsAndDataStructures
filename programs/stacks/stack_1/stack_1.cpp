//
// Created by Nicolas on 11/13/2019.
//

#include "../../../structures/stacks/LinkedStack.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * Read input string, analyze input tokens to know if string is balanced (Simple version)
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]){

    string input_string;
    LinkedStack<char> *stack = new LinkedStack<char>();
    cout << "Insert a string: ";
    cin >> input_string;

    int error=0;
    for(int i=0; (i < input_string.length()) && (!error); i++){

        if (input_string.at(i)=='{')
            stack->push('{');
        if (input_string.at(i)=='[')
            stack->push('[');
        if (input_string.at(i)=='(')
            stack->push('(');

        if (input_string.at(i) == '}'){
            if (stack->empty())
                error=1;
            else
                if(stack->get_top() !='{')
                    error=1;
                else
                    stack->pop();
        }
        if (input_string.at(i) == ']'){
            if (stack->empty())
                error=1;
            else
            if(stack->get_top() !='[')
                error=1;
            else
                stack->pop();
        }
        if (input_string.at(i) == ')'){
            if (stack->empty())
                error=1;
            else
            if(stack->get_top() !='(')
                error=1;
            else
                stack->pop();
        }
    }
    if( (!error) && stack->empty())
        cout << "String is balanced" << endl;
    else
        cout<< "ERROR" << endl;

    return 0;
}