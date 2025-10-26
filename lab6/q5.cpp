#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class IntStack {
    int top_index;
    int a[MAX]; 
public:
    IntStack() { top_index = -1; }

    bool push(int x) {
        if (top_index >= (MAX - 1)) {
            cout << "Stack Overflow";
            return false;
        }
        a[++top_index] = x;
        return true;
    }
    int pop() {
        if (top_index < 0) {
            cout << "Stack underflow";
            return 0;
        }
        return a[top_index--];
    }
    int top() {
        if (top_index < 0) {
            cout << "Stack is empty";
            return 0;
        }
        return a[top_index];
    }

    bool isEmpty() {
        return (top_index < 0);
    }
};
bool my_isdigit(char c) {
    return c >= '0' && c <= '9';
}
int my_pow(int base, int exp) {
    if (exp < 0) return 0; 
    if (exp == 0) return 1;
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}
int evaluatePrefix(string exp) {
    IntStack s;

    for (int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];

        if (my_isdigit(c)) {
            s.push(c - '0'); 
        } 
        else {
            int val1 = s.pop();
            int val2 = s.pop();
            int result;

            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': result = my_pow(val1, val2); break;
            }
            s.push(result);
        }
    }
    return s.top(); 
}
int main() {
    string expression = "-+*2354";
    
    int result = evaluatePrefix(expression);
    
    cout << result << endl;

    return 0;
}
