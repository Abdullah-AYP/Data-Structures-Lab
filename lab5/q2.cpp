#include <iostream>

#define N 5

using namespace std;

void printSolution(int sol[N][N]) {
    cout << "The Lion's path to the meat is:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << " " << sol[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}
bool solveMaze(int maze[N][N], int x, int y, int sol[N][N]) {
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(maze, x, y)) {
        sol[x][y] = 1;
        if (solveMaze(maze, x + 1, y, sol)) {
            return true;
        }
        if (solveMaze(maze, x, y + 1, sol)) {
            return true;
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}
int main() {
    int maze[N][N] = {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };
    int solution[N][N] = {0};

    cout << "--- Lion in a Maze ---" << endl;
    cout << "The Lion starts at (0,0) and needs to reach the meat at (4,4)." << endl;

    if (solveMaze(maze, 0, 0, solution)) {
        printSolution(solution);
    } else {
        cout << "No solution exists. The lion could not find the meat." << endl;
    }
    return 0;
}
