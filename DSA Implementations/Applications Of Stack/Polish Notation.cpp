#include <iostream>
#include <string>
#include <stack>

using namespace std;

class ExpressionConverter {
public:
    ExpressionConverter() : top(-1) {}

    string infixToPostfix(string expression) {
        string result = "";

        for (int i = 0; i < expression.length(); i++) {
            char c = expression[i];

            if (!isOperator(c)) {
                result += c;
            } else if (closingBrackets(c)) {
                while (peek() != openingBrackets(peek()) && !isEmpty()) {
                    result += ' ';
                    result += pop();
                }
                pop();
            } else if (isOperator(c)) {
                if (precedence(c) > 0) {
                    result += ' ';
                    if (!isEmpty() && precedence(c) <= precedence(peek())) {
                        while (precedence(c) <= precedence(peek())) {
                            result += pop();
                            result += ' ';
                        }
                        push(c);
                    } else {
                        push(c);
                    }
                } else {
                    push(c);
                }
            }
        }

        while (!isEmpty()) {
            char op = pop();
            if (precedence(op) > 0) {
                result += ' ';
                result += op;
            }
        }

        return result;
    }

private:
    stack<char> stack;
    int top;

    void push(char value) {
        stack.push(value);
        top++;
    }

    char pop() {
        if (!isEmpty()) {
            char data = stack.top();
            stack.pop();
            top--;
            return data;
        }
        return '\0'; // Return null character if the stack is empty
    }

    char peek() {
        if (!isEmpty()) {
            return stack.top();
        }
        return '\0'; // Return null character if the stack is empty
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']';
    }

    int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        if (op == '^')
            return 3;
        return 0;
    }

    char openingBrackets(char c) {
        switch (c) {
            case '(':
                return '(';
            case '{':
                return '{';
            case '[':
                return '[';
            default:
                return '\0';
        }
    }

    bool closingBrackets(char c) {
        return c == ')' || c == '}' || c == ']';
    }
};

int main() {
    ExpressionConverter converter;
    string infixExpression;

    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    string postfixExpression = converter.infixToPostfix(infixExpression);
    cout << "Postfix Expression: " << postfixExpression << endl;

    return 0;
}


