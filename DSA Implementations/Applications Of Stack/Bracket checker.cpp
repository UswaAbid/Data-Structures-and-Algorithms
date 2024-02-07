#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BracketChecker {
public:
    BracketChecker() {}

    void push(char bracket) {
        s.push(bracket);
    }

    void pop() {
        if (!s.empty()) {
            s.pop();
        }
    }

    char top() const {
        if (!s.empty()) {
            return s.top();
        }
        return ' ';
    }

    bool isEmpty() const {
        return s.empty();
    }

    bool areBracketsBalanced(const string& expression) {
        for (int i = 0; i < expression.length(); i++) {
            char bracket = expression[i];
            if (isOpenBracket(bracket)) {
                push(bracket);
            } else if (isCloseBracket(bracket)) {
                if (isEmpty()) {
                    return false;
                }

                char topBracket = top();
                pop();

                if (!areMatchingBrackets(topBracket, bracket)) {
                    return false;
                }
            }
        }

        return isEmpty();
    }

private:
    stack<char> s;

    bool isOpenBracket(char bracket) {
        return (bracket == '(' || bracket == '{' || bracket == '[');
    }

    bool isCloseBracket(char bracket) {
        return (bracket == ')' || bracket == '}' || bracket == ']');
    }

    bool areMatchingBrackets(char openBracket, char closeBracket) {
        return ((openBracket == '(' && closeBracket == ')') ||
                (openBracket == '{' && closeBracket == '}') ||
                (openBracket == '[' && closeBracket == ']'));
    }
};

int main() {
    BracketChecker bracketChecker;
    string expression;

    cout << "Enter an expression: ";
    getline(cin, expression);  // Read the entire expression including spaces

    if (bracketChecker.areBracketsBalanced(expression)) {
        cout << "Brackets are balanced." << endl;
    } else {
        cout << "Brackets are not balanced." << endl;
    }

    return 0;
}

