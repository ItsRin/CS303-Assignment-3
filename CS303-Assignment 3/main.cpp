#include <iostream>
#include <string>
#include "ExpressionManager.h"
#include "Queue.h"

using namespace std;

int main() {
    ExpressionManager expManager;
    Queue<int> queue;

    string expression;
    cout << "Enter an infix expression (EX: (1 + 2) * 3): ";
    getline(cin, expression);

    if (expManager.checkBalancedParentheses(expression)) {
        cout << "The expression is balanced.\n";
        string postfix = expManager.infixToPostfix(expression);
        cout << "Postfix expression: " << postfix << endl;
    }
    else {
        cout << "The expression is not balanced.\n";
    }

    int choice, value;
    do {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Front Element\n4. Queue Size\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            if (!queue.isEmpty()) {
                cout << "Dequeued: " << queue.dequeue() << endl;
            }
            else {
                cout << "Queue is empty.\n";
            }
            break;
        case 3:
            if (!queue.isEmpty()) {
                cout << "Front element: " << queue.front() << endl;
            }
            else {
                cout << "Queue is empty.\n";
            }
            break;
        case 4:
            cout << "Queue size: " << queue.size() << endl;
            break;
        case 5:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
