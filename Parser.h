#pragma once  

#ifndef _USE_MATH_DEFINES  
#define _USE_MATH_DEFINES  
#endif  

#include <cmath>  
#include <iostream>  
#include <stack>  
#include <vector>  
#include <cctype>  
#include <stdexcept>  
#include <sstream>  
#include <iomanip>  
#include <map>  
#include <limits>  

class EquationParser {
private:
    std::vector<std::string> tokens;
    std::vector<std::string> postfix;

    const std::vector<std::string> math_functions = {
        "sin", "cos", "tan", "asin", "acos", "atan",
        "sinh", "cosh", "tanh", "sqrt", "exp", "ln", "log"
    };

    const std::map<std::string, double> constants = {
        {"pi", 3.141592654}, {"e", 2.718281828}
    };

    bool isOperator(char c);
    int precedence(char op);
    bool isFunction(const std::string& token);
    bool isConstant(const std::string& token);
    void validateTokens();

    bool allow_xy; // Flag to allow both x and y in the same expression

public:
    EquationParser(); // Constructor
    bool has_x = false, has_y = false;


    // Set the flag to allow or disallow both x and y in the same expression
    void setAllowXY(bool allow);

    void parseEquation(const std::string& equation);
    void convertToPostfix();
    double evaluate(double x_value);
    double evaluate(double x_value, double y_value); // Evaluate for both x and y
    void printPostfix();
};
