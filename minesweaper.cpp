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
vector<vector< char > > board;
vector<Bomb> bombs;
bool game = true;

int charToInt(char c){
    return c-48;
}

char intToChar(int i){
    return i+48;
}

void fillBoardWithZero(){
    board.reserve(boardSize);
    for (int i = 0; i < boardSize; i++)
    {
        board[i].reserve(boardSize);
        for (int j = 0; j < boardSize; j++)
        {
            board[i][j] = '0';
        }
    }
}

void printBoard(){
    char horizontal = 'A';
    char vertical = '1';

    cout<<"   ";
    for(int i=0;i<boardSize;i++){
        cout<<vertical++<<" ";
    }
    cout<<endl;
    cout<<"   ";
    for(int i=0;i<boardSize;i++){
        cout<<"-"<<" ";
    }
    cout<<endl;


    for (int i = 0; i < boardSize; i++)
    {   
        cout<<horizontal++<<"| ";
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
        bool push = true;
        b.x = random(0,boardSize-1);
        b.y = random(0,boardSize-1);
        for (int j = 0; j < bombs.size(); j++)
        {
           Bomb oldBomb = bombs[j];
           if(b.x == oldBomb.x && b.y == oldBomb.y){
               i--;
               push = false;
               break;
           }
        }

        if (push)
        {
            board[b.x][b.y] = '*';
            bombs.push_back(b);
        }
    }
}

void fillBoard(){
    for (int i = 0; i < bombs.size(); i++)
    {
        Bomb b = bombs[i];

        int x = b.x;
        int y = b.y;

        if(x-1>=0){
            board[x-1][y]++; // left
        }

        if(x-1>=0 && y-1>=0){
            board[x-1][y-1]++; // upper left
        }

        if(y-1 >=0){
            board[x][y-1]++; // up
        }

        if(x+1<boardSize && y-1>=0){
            board[x+1][y-1]++; // upper right
        }

        if(x+1<boardSize){
            board[x+1][y]++; // right
        }

        if(x+1<boardSize && y+1 < boardSize){
            board[x+1][y+1]++; // lower right
        }

        if(y+1<boardSize){
            board[x][y+1]++; // down
        }

        if(x-1>=0 && y+1 < boardSize){
            board[x-1][y+1]++; // lower left
        }
    }
    
    for (int i = 0; i < bombs.size(); i++)
    {
        Bomb b = bombs[i];
        board[b.x][b.y] = '*';
    }
}

void startGame(){
    while(game){
        printBoard();
        cout<<endl;
        char c;
        int n;
        cout<<"shemoitane koordinatebi: ";
        cin>>c>>n;
        int y = c-65;
        int x = n-1;

        cout<<endl<<x<<" "<<y<<endl;
        cout<<endl<<board[y][x]<<endl;
    }
}





int main() {
    srand( (unsigned)time(NULL) );
    fillBoardWithZero();
    generateBombs();
    fillBoard();
    startGame();    



    return 0;
}