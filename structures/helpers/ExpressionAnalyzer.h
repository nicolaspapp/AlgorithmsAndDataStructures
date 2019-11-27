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
 * Class that holds function to analyze and transform text to mathematical operations
 */
class ExpressionAnalyzer {
private:
    const std::map<char, char> tokens;
    LinkedStack<char> stack;

    std::string  infix_to_polish(const std::string &input_str);
    int procedence_function(const char& o1, const char& o2);
public:
    /**
     * Class constructor
     * @param tokens
     *  Maps of opening and closing tokens that will be considered
     *  Example:
     *   {'{', '}'},
     *   {'(', ')'},
     *   {'[', ']'}
     */
    ExpressionAnalyzer(const std::map<char, char> tokens);

    /**
     * Assertive method to check for syntaxis
     * Throws std::exception if syntax is invalid
     * @param input_str
     */
    void check_syntaxis(const std::string &input_str);

    /**
     * Method that processes an infix str and returns the result
     * @param infix_str : infix string. Example: (2+2)*(1-3)
     * @return
     */
    int process_string(const std::string &infix_str);
};


#endif //_EXPRESSIONANALYZER_H
