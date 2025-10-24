#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
    Student* next;
};
void insertEnd(Student*& head, string name, int score) {
    Student* newNode = new Student{name, score, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Student* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}
void display(Student* head) {
    cout << "Name\tScore\n";
    cout << "----------------\n";
    while (head) {
        cout << head->name << "\t" << head->score << endl;
        head = head->next;
    }
}
int getMax(Student* head) {
    int max = 0;
    while (head) {
        if (head->score > max)
            max = head->score;
        head = head->next;
    }
    return max;
}
Student* countingSort(Student* head, int exp) {
    Student* buckets[10] = {nullptr};
    Student* bucketTails[10] = {nullptr};

    for (Student* curr = head; curr != nullptr; curr = curr->next) {
        int digit = (curr->score / exp) % 10;

        Student* newNode = new Student{curr->name, curr->score, nullptr};

        if (!buckets[digit]) {
            buckets[digit] = bucketTails[digit] = newNode;
        } else {
            bucketTails[digit]->next = newNode;
            bucketTails[digit] = newNode;
        }
    }
    Student* newHead = nullptr;
    Student* newTail = nullptr;

    for (int i = 0; i < 10; i++) {
        if (buckets[i]) {
            if (!newHead)
                newHead = buckets[i];
            else
                newTail->next = buckets[i];
            newTail = bucketTails[i];
        }
    }
    return newHead;
}
void radixSort(Student*& head) {
    int maxScore = getMax(head);

    for (int exp = 1; maxScore / exp > 0; exp *= 10)
        head = countingSort(head, exp);
}
int main() {
    Student* head = nullptr;

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cout << "Enter name and score: ";
        cin >> name >> score;
        insertEnd(head, name, score);
    }
    cout << "\nUnsorted List:\n";
    display(head);

    radixSort(head);

    cout << "\nSorted List (by score ascending):\n";
    display(head);

    return 0;
}
