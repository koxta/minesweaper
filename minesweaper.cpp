#include<iostream>
#include<algorithm>
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int boardSize = 8; 
vector<vector< int > > board;
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

int random(int m, int mx) { // SUPER IMPORTANT STUFF!!!
	srand(time(NULL));// SUPER IMPORTANT STUFF!!!
	int r=mx-m+1; // SUPER IMPORTANT STUFF!!!
	int num=rand()%r+m;// SUPER IMPORTANT STUFF!!!
	return num;
}

int main() {
    fillBoardWithZero();
    //printBoard();

    unsigned long j;

    srand( (unsigned)time(NULL) );

    for( j = 0; j < 100500; ++j )
    {
        printf( "%d,\t%d\n", rand(), rand() % 6 + 1 );
    }

    return 0;
}