#include <iostream>
#include <string>
using namespace std;

class employee {
public: 
    string name;
    int id;
    int salary;
};
void merge(employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    employee* leftarr = new employee[n1];
    employee* rightarr = new employee[n2];

    for (int i = 0; i < n1; i++)
        leftarr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightarr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftarr[i].salary >= rightarr[j].salary) { 
            arr[k] = leftarr[i];
            i++;
        } else {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
    delete[] leftarr;
    delete[] rightarr;
}
void mergesort(employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main() {
    const int num_employees = 12;
    employee employees[num_employees] = {
        {"raza", 10, 84000},
        {"kinza", 323, 80000},
        {"sana", 211, 63000},
        {"ali", 191, 56000},
        {"zahid", 345, 54000},
        {"zohaib", 477, 49000},
        {"yasir", 156, 47000},
        {"moiz", 122, 39000},
        {"saba", 121, 32000},
        {"laila", 990, 28000},
        {"shama", 100, 24000},
        {"saba", 123, 12000}
    };
    mergesort(employees, 0, num_employees - 1);

    cout << "employees sorted by salary in descending order:" << endl;
    cout << "name\t\tid\tsalary" << endl;
    for (int i = 0; i < num_employees; i++) {
        cout << employees[i].name << "\t\t"
             << employees[i].id << "\t"
             << employees[i].salary << endl;
    }
    cout << "\ntop 3 highest paid employees:" << endl;
    cout << "rank\tname\t\tid\tsalary" << endl;
    for (int i = 0; i < 3; i++) {
        cout << (i + 1) << "\t"
             << employees[i].name << "\t\t"
             << employees[i].id << "\t"
             << employees[i].salary << endl;
    }
    return 0;
}
