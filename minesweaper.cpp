#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

struct Bomb
{
    int x;
    int y;
};

int boardSize = 8; 
vector<vector< int > > board;
vector<Bomb> bombs;

void fillBoardWithZero(){
    board.reserve(boardSize);
    for (int i = 0; i < boardSize; i++)
    {
        board[i].reserve(boardSize);
        for (int j = 0; j < boardSize; j++)
        {
            board[i][j] = 0;
        }
    }
}

void printBoard(){
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

int random(int from, int to) {
	return rand() % (to+1) + from;
}

void printBomb(Bomb b){
    cout<<b.x<<","<<b.y<<endl;
}

void generateBombs(){
    for (int i = 0; i < boardSize; i++)
    {
        Bomb b;
        b.x = random(0,boardSize-1);
        b.y = random(0,boardSize-1);
        for (int j = 0; j < bombs.size(); j++)
        {
           Bomb oldBomb = bombs[j];
           if(b.x == oldBomb.x && b.y == oldBomb.y){
               i--;
               break;
           }
        }
        
        bombs.push_back(b);
    }
}

void fillBoard(){
    for (int i = 0; i < bombs.size(); i++)
    {
        Bomb b = bombs[i];

        int x = b.x;
        int y = b.y;

        if(x-1>=0){
            board[x-1][y]++;
        }

        if(x-1>=0 && y-1>=0){
            board[x-1][y-1]++;
        }

        board[x][y-1]++;
        board[x+1][y+1]++;
        board[x+1][y]++;
        board[x+1][y+1]++;
        board[x][y+1]++;
        board[x-1][x+1]++;
    }
    
    for (int i = 0; i < bombs.size(); i++)
    {
        Bomb b = bombs[i];
        board[b.x][b.y] = 9;
    }
}

int main() {
    srand( (unsigned)time(NULL) );
    fillBoardWithZero();
    generateBombs();
    //fillBoard();

    printBoard();


    return 0;
}