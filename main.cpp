#include <iostream>
#include <windows.h>
#include "Player.h"
#include "Enemy.h"

using namespace std;

const int width = 20;
const int height = 20;
Player player1;
Enemy EnemyObj;
bool gameOver = false;

void DrawMap(){
    cout << "Down arrow to stand" << endl;
    for (int i = 0; i < width; i++){
        cout << "_";
    } cout << endl;
    for (int i = 0; i < height - 2; i++){
        for (int j = 0; j < width ; j++){
            if (i == player1.Pos.at(1) && j == player1.Pos.at(0)){
                cout << player1.characterSprite;
            }
            else if(i == EnemyObj.Pos.at(1) && j == EnemyObj.Pos.at(0)) {
                cout << EnemyObj.EnemyChar;
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width; i++){
        cout << "_";
    } cout << endl;
    cout << EnemyObj.score;
}

bool GameCheck(){
    if (EnemyObj.Pos[1] > height){
        return false;
    }
    return true;
}

int main(){
    while (!gameOver)
    {      
        system("CLS");
        player1.InputHandler();
        player1.MovePlayer(width);
        EnemyObj.MoveEnemy(height, width, player1.Pos);
        DrawMap();
        Sleep(200);
        gameOver = !GameCheck();
    }
    system("CLS");
    cout << "your score:  " << EnemyObj.score;
    Sleep(2000);
    return 0;
}