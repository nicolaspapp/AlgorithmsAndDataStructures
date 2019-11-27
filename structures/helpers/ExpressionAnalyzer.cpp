//
// Created by Nicolas on 11/16/2019.
//

#include "ExpressionAnalyzer.h"

using namespace std;

ExpressionAnalyzer::ExpressionAnalyzer(const map<char, char> tokens) : tokens(tokens){

}

void ExpressionAnalyzer::check_syntaxis(const std::string &input_string) {
    stack.empty();

    for(int i=0; (i < input_string.length()); i++){
        for(auto/*map<char, char>::const_iterator*/ iter = tokens.begin(); iter != tokens.end(); ++iter){
            if(input_string.at(i) == iter->first){
                stack.push(iter->first);
            }

            if (input_string.at(i) == iter->second){
                if (stack.empty()){
                    throw std::invalid_argument("Invalid syntax!");
                }
                else{
                    if(stack.get_top() != iter->first)
                        throw std::invalid_argument("Invalid syntax!");
                    else
                        stack.pop();
                }
            }
        }
    }
}

int ExpressionAnalyzer::process_string(const std::string &infix_str) {
    int o1,o2;
    int error = 0;

    const std::string input_str = infix_to_polish(infix_str);
    for(int i=0; (i<input_str.length()) && (!error); i++) {
        const char d = input_str.at(i);
        if (d >= '0' && d <= '9') {
            stack.push(d - '0');
        }
        if (d == '+') {
            o2 = stack.get_top();
            stack.pop();
            o1 = stack.get_top();
            stack.pop();
            stack.push(o1 + o2);
        }
        if (d == '-') {
            o2 = stack.get_top();
            stack.pop();
            o1 = stack.get_top();
            stack.pop();
            stack.push(o1 - o2);
        }
        if (d == '*') {
            o2 = stack.get_top();
            stack.pop();
            o1 = stack.get_top();
            stack.pop();
            stack.push(o1 * o2);
        }
    }

    return (int) stack.get_top();
}

string ExpressionAnalyzer::infix_to_polish(const string &input_str) {
    char current_char,ptr_char;
    string polish_str;
    for(int j=0;j<input_str.length();j++)
    {
        current_char=input_str.at(j);
        if ( (current_char >= '0') && (current_char <= '9') ){
            polish_str.push_back(current_char);
        }
        else
        {
            while( (!stack.empty()) && ( procedence_function(stack.get_top(),current_char)) )
            {
                ptr_char=stack.get_top();
                stack.pop();
                polish_str.push_back(ptr_char);
            }
            if( (stack.empty()) || (current_char!=')') )
                stack.push(current_char);
            else
                stack.pop();
        }
    }
    while(!stack.empty())
    {
        current_char = stack.get_top();
        stack.pop();
        polish_str.push_back(current_char);
    }

    cout << "\n POLISH convertion ready: "<< polish_str <<endl;
    return polish_str;
}

int ExpressionAnalyzer::procedence_function(const char &o1, const char &o2) {
    if(o2=='(')
        if(o1==')')
            return 1;
        else
            return 0;
    if(o2==')')
        if(o1=='(')
            return 0;
        else
            return 1;
    if(o1=='(')
        return 0;

    if( (o1=='*') || (o1=='/') )
        return 1;
    if( ( (o1=='+') || (o1=='-') ) && ( (o2=='+') || (o2=='-') ) )
        return 1;
    else
        return 0;
}