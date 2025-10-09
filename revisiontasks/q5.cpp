#include <iostream>
using namespace std;

#define N 5
int maze[N][N]={
    {1,1,1,0,1},
    {0,1,0,1,1},
    {1,1,1,1,0},
    {0,1,0,1,1},
    {1,1,1,0,1}
};
int path[69][2];
int catpath[69][2];
int Rabcount = 0, Catcount =0;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool isSafe(int x,int y){
    return (x>=0 && x<N && y>=0 && y< N && maze[x][y]==1);
}
bool findRabpath(int x,int y ,int destx,int desty){
    if(!isSafe(x,y))return false;
    maze[x][y]=0;
    path[Rabcount][0]=x;
    path[Rabcount][1]=y;
    Rabcount++;
    if(x==destx && y==desty){
        maze[x][y]=1;
        return true;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(findRabpath(nx,ny,destx,desty)){
            maze[x][y]=1;
            return true;
    }
    }
    Rabcount--;
    maze[x][y]=1;
    return false;
}
bool findCatpath(int x,int y ,int destx,int desty){
    if(!isSafe(x,y))return false;
    maze[x][y]=0;
    catpath[Catcount][0]=x;
    catpath[Catcount][1]=y;
    Catcount++;
    if(x==destx && y==desty){
        maze[x][y]=1;
        return true;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(findCatpath(nx,ny,destx,desty)){
            maze[x][y]=1;
            return true;
    }
    }
    Catcount--;
    maze[x][y]=1;
    return false;
}
int main(){
    findRabpath(0,0,2,2);
    cout << "Rabbit path:\n";
    for (int i=0;i<Rabcount;i++){
        cout << "("<< path[i][0]<<","<< path[i][1]<<") ";
    cout<<endl;}
    
    findCatpath(4,4,2,2);
    cout << "Cat path:\n";
    for(int i=0;i<Catcount;i++){
        cout << "("<< catpath[i][0]<<","<< catpath[i][1]<<") ";
        cout<<endl;
    }
    cout <<"Intersection points:\n";
    for(int i=0;i<Rabcount;i++){
        for(int j=0;j<Catcount;j++){
            if(path[i][0]==catpath[j][0] && path[i][1]==catpath[j][1]){
                cout << "("<< path[i][0]<<","<< path[i][1]<<") ";
                cout<<endl;
            }
        }
    }
    return 0;
}
