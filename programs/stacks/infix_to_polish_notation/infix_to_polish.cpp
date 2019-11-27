//
// Created by Nicolas on 11/16/2019.
//

#include "../../../structures/stacks/LinkedStack.h"
#include "../../../structures/helpers/ExpressionAnalyzer.h"
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    string input_string;
    LinkedStack<char> *stack = new LinkedStack<char>();

    cout << "Ingrese expresion= " ;
    cin >> input_string;

    const map<char, char> tokens = {
            {'{', '}'},
            {'(', ')'},
            {'[', ']'}
    };
    ExpressionAnalyzer expressionAnalyzer(tokens);

    cout << "--- Analizando expresión para: " << input_string << " ---" << endl;
    expressionAnalyzer.check_syntaxis(input_string);
    cout << "--- Evaluando --- " << endl;
    int result = expressionAnalyzer.process_string(input_string);
    cout << "--- Resultado obtenido: " << result << " ---" << endl;
    cout << endl;
    return 0;
}