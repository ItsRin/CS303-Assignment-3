#ifndef EXPRESSIONMANAGER_H
#define EXPRESSIONMANAGER_H

#include <string>

using namespace std;

class ExpressionManager {
public:
    bool checkBalancedParentheses(const string& expression);
    string infixToPostfix(const string& infix);

private:
    int precedence(char op);
    bool isOperator(char c);
};

#endif
