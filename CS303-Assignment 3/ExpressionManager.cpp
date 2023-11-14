#include "ExpressionManager.h"
#include <stack>
#include <cctype>

using namespace std;

// Function to check if parentheses in the expression are balanced
bool ExpressionManager::checkBalancedParentheses(const string& expression) {
    stack<char> stack;
    for (char ch : expression) {
        switch (ch) {
        case '(': case '[': case '{':
            stack.push(ch);  // Push opening parentheses onto the stack
            break;
        case ')': case ']': case '}':
            if (stack.empty()) return false;  // Unmatched closing parenthesis
            // Check for mismatched pairs
            if ((ch == ')' && stack.top() != '(') ||
                (ch == ']' && stack.top() != '[') ||
                (ch == '}' && stack.top() != '{')) {
                return false;
            }
            stack.pop();  // Pop the matching opening parenthesis
            break;
        default:
            break;
        }
    }
    return stack.empty();  // True if all parentheses are balanced
}

// Determines the precedence of operators
int ExpressionManager::precedence(char op) {
    if (op == '+' || op == '-') return 1;  // Lower precedence for + and -
    if (op == '*' || op == '/' || op == '%') return 2;  // Higher precedence for *, /, %
    return 0; 
}

// Checks if a character is an operator
bool ExpressionManager::isOperator(char c) {
    return precedence(c) > 0;
}

// Converts infix expression to postfix
string ExpressionManager::infixToPostfix(const string& infix) {
    stack<char> stack;
    string postfix;

    for (char c : infix) {
        if (isspace(c)) continue;  // Ignore whitespace

        if (isOperator(c)) {
            // Pop from stack to postfix if the top has equal or higher precedence
            while (!stack.empty() && precedence(stack.top()) >= precedence(c)) {
                postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
            stack.push(c);  // Push current operator onto stack
        }
        else if (c == '(') {
            stack.push(c);  // Push '(' to stack
        }
        else if (c == ')') {
            // Pop everything until '(' to postfix
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
            stack.pop(); // Pop the '('
        }
        else {
            postfix += c;  // Add operand to postfix
            postfix += ' ';
        }
    }

    // Pop remaining operators from stack to postfix
    while (!stack.empty()) {
        postfix += stack.top();
        postfix += ' ';
        stack.pop();
    }

    return postfix;
}
