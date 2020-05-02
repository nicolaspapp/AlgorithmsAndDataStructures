//
// Created by Nicolas on 11/16/2019.
//

#ifndef _EXPRESSIONANALYZER_H
#define _EXPRESSIONANALYZER_H

#include "../stacks/LinkedStack.h"

#include <string>
#include <map>
#include <stdexcept>

/**
 * Clase que contiene las funciones para analizar y transformar texto a operaciones matemáticas
 */
class ExpressionAnalyzer {
private:
    const std::map<char, char> tokens;
    LinkedStack<char> stack;

    std::string  infix_to_polish(const std::string &input_str);
    int procedence_function(const char& o1, const char& o2);
public:
    /**
     * Constructor
     * @param tokens
     *  Mapa que contiene el token que abre y que cierra para tener en cuenta
     *  Ejemplo:
     *   {'{', '}'},
     *   {'(', ')'},
     *   {'[', ']'}
     */
    ExpressionAnalyzer(const std::map<char, char> tokens);

    /**
     * Método utilizado para verificar la sintaxis de un string
     * Arroja std::exception si la sintaxis es inválida
     * @param input_str string a ser analizado
     */
    void check_syntaxis(const std::string &input_str);

    /**
     * Método que procesa un string en entrefijo y retorna el resultado
     * @param infix_str : string en entrefijo. Ejemplo: (2+2)*(1-3)
     * @return
     */
    int process_string(const std::string &infix_str);
};


#endif //_EXPRESSIONANALYZER_H
