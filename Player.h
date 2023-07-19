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
            this->directionX = 1;
        } 
        if (GetAsyncKeyState(VK_LEFT)){
            this->directionX = -1;
        }
        if (GetAsyncKeyState(VK_DOWN)){
            this->directionX = 0;
        }
    }

public:
    void MovePlayer(int width){
       this->Pos.at(0) += this->directionX; 

        if (this->Pos.at(0) < 0){
            this->Pos.at(0) = width;
        }
        if (this->Pos.at(0) > width) {
            this->Pos.at(0) = 0;
        }
    }
};