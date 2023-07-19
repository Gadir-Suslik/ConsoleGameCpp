#pragma once
#include <vector>
#include <windows.h>
using namespace std;

class Player
{
public:
    int directionX = 0;
    vector<int> Pos = {10, 17};
    char characterSprite = '^';
    void InputHandler(){
        if (GetAsyncKeyState(VK_RIGHT)){
            directionX = 1;
        } 
        if (GetAsyncKeyState(VK_LEFT)){
            directionX = -1;
        }
        if (GetAsyncKeyState(VK_DOWN)){
            directionX = 0;
        }
    }

public:
    void MovePlayer(int width){
       Pos[0] += directionX; 

        if (Pos[0] < 0){
            Pos[0] = width;
        }
        if (Pos[0] > width) {
            Pos[0] = 0;
        }
    }
};