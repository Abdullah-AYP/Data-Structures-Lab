#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;
class IntStack {
    int top_index;
public:
    int a[MAX]; 

    IntStack(){ top_index = -1; }
    bool push(int x){
        if (top_index >= (MAX - 1)){
            cout << "Stack Overflow";
            return false;
        } else {
            a[++top_index] = x;
            return true;
        }
    }
    int pop(){
        if (top_index < 0) {
            cout << "Stack Underflow";
            return 0;
        } else{
            int x = a[top_index--];
            return x;
        }
    }
    int top(){
        if (top_index < 0){
            cout << "Stack is Empty";
            return 0;
        } else{
            int x = a[top_index];
            return x;
        }
    }
    bool isEmpty(){
        return (top_index < 0);
    }
};
bool my_isdigit(char c){
    return c >= '0' && c <= '9';
}
int evaluate(string exp){
    IntStack s;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (my_isdigit(c)) {
            s.push(c - '0');
        } 
        else {
            int val2 = s.pop();
            int val1 = s.pop();
            int result;

            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }
            s.push(result);
        }
    }
    return s.pop();
}
int main() {
    string expression = "23*54*+9-";
    cout << "Postfix Evaluation:" << endl;
    cout << "Expression: " << expression << endl;
    int result = evaluate(expression);
    cout << "Result: " << result << endl;

    return 0;
}
