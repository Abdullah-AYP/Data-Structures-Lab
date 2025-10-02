#include <iostream>
using namespace std;
#define N 7

void printSolution(int sol[N][N]) {
    cout << "Path found:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int x,int y,int maze[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}
bool solveMaze(int x,int y,int sol[N][N],int maze[N][N]) {
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(x,y,maze)) {
        if (sol[x][y] == 1) {
            return false;
        }
        sol[x][y] = 1;
        if (solveMaze(x,y + 1,sol,maze)){
            return true;}
        if (solveMaze(x + 1,y,sol,maze)){
            return true;}
        if (solveMaze(x,y - 1,sol,maze)){
            return true;}
        if (solveMaze(x - 1,y,sol,maze)){
            return true;}
        sol[x][y] = 0;
        return false;
    }
    return false;
}
void Findpath(int maze[N][N]) {
    int sol[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sol[i][j] = 0;
        }
    }
    if (solveMaze(0,0,sol,maze) == false) {
        cout << "Solution doesn't exist" << endl;
        return;
    }
    printSolution(sol);
}
int main() {
    int maze[N][N] = {
        {1, 0, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 1, 1, 1, 1}
    };
    Findpath(maze);

    return 0;
}
