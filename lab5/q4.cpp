#include <iostream>
using namespace std;

void printBoard(int n,char* board) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i * n + j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}
bool isSafe(int row,int col,int n,char* board) {
    for (int j = 0; j < col; j++) {
        if (board[row * n + j] == 'Q') return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i * n + j] == 'Q') return false;
    }
    for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i * n + j] == 'Q') return false;
    }
    return true;
}
void solve(int col,int n,char* board,int& count) {
    if (col >= n) {
        if (count == 0) {
            cout << "One valid board configuration:\n";
            printBoard(n, board);
        }
        count++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isSafe(i,col,n,board)) {
            board[i * n + col] = 'Q'; 
            solve(col + 1, n, board, count);
            board[i * n + col] = '.'; 
        }
    }
}
int main() {
    int n;
    cout << "Enter the value of N for the N-Queens problem: ";
    cin >> n;

    if (n <= 0) {
        cout << "N must be a positive integer." << endl;
        return 1;
    }
    char* board = new char[n * n];
    for (int i = 0; i < n * n; i++) {
        board[i] = '.'; 
    }
    int solutionCount = 0;
    solve(0,n,board,solutionCount);

    if (solutionCount == 0) {
        cout << "No solution exists for N= " << n << endl;
    } else {
        cout << "Total number of different solutions for N = " << n << " is: " << solutionCount << endl;
    }
    delete[] board;

    return 0;
}
