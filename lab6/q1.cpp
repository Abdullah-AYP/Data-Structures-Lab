#include <iostream>
#include <string>
using namespace std;

class CallRecord {
public:
    string name;
    string number;
    int duration;

    CallRecord(string n = "",string num = "",int dur = 0){
        name = n;
        number = num;
        duration = dur;
    }
};
const int MAX_CALLS = 10;
class CallStack{
private:
    int top_index; 
    CallRecord a[MAX_CALLS];
public:
    CallStack(){
        top_index = -1;
    }
    bool push(CallRecord x){
        if (top_index >= (MAX_CALLS - 1)){
            cout << "Stack Overflow" << endl;
            return false;
        } else{
            a[++top_index] = x;
            return true;
        }
    }
    CallRecord pop(){
        if (top_index < 0){
            return CallRecord(); 
        } else {
            return a[top_index--];
        }
    }
    CallRecord top(){
        if (top_index < 0){
            return CallRecord();
        } else{
            return a[top_index];
        }
    }
    bool isEmpty(){
        return (top_index < 0);
    }
};
void displayCallLog(CallStack s){
    if (s.isEmpty()){
        cout << "Call log is empty." << endl;
        return;
    }
    cout << "Call Log (Most recent is first):" << endl;
    while (!s.isEmpty()) {
        CallRecord call = s.pop();
        cout << "Name: " << call.name << ", Number: " << call.number << ", Duration: " << call.duration << " min" << endl;
    }
}
int main() {
    CallStack history;

    history.push(CallRecord("Abdullah", "03334567890", 1));
    history.push(CallRecord("Rameel", "03374677407", 2));
    history.push(CallRecord("Irfan", "03352045678", 3));
    displayCallLog(history);
    CallRecord lastCall = history.top();
    cout << "Last call was with: " << lastCall.name << endl;
    history.pop();
    displayCallLog(history);
    cout << "Is history empty? " << (history.isEmpty() ? "Yes" : "No") << endl;
    history.pop();
    history.pop();
    cout << "Is history empty now? " << (history.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
