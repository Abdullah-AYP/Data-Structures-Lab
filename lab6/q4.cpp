#include <iostream>
#include <string>
using namespace std;

class Stack {
    char data[100];
    int topPos;
public:
    Stack() { topPos = -1; }

    void push(char val) {
        data[++topPos] = val;
    }
    char pop() {
        return data[topPos--];
    }
    char top() {
        return data[topPos];
    }
    bool empty() {
        return topPos == -1;
    }
};
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
string infixToPostfix(string exp) {
    Stack stk;
    string result = "";

    for (int i = 0; i < exp.size(); i++) {
        char c = exp[i];

        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            stk.push(c);
        }
        else if (c == ')') {
            while (!stk.empty() && stk.top() != '(') {
                result += stk.pop();
            }
            if (!stk.empty()) stk.pop();
        }
        else if (isOperator(c)) {
            while (!stk.empty() && precedence(stk.top()) >= precedence(c) && c != '^') {
                result += stk.pop();
            }
            stk.push(c);
        }
    }
    while (!stk.empty()) {
        result += stk.pop();
    }
    return result;
}
int main() {
    string infixExp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Postfix: " << infixToPostfix(infixExp) << endl;
    return 0;
}
