#pragma once
#include <vector>
#include <random>

class Enemy{
public:
    std::vector<int> Pos = {10, 0}; 
    char EnemyChar = '*';
    int score = 0;
public:
    void MoveEnemy(int height, int width, std::vector<int> PlayerPos){
        this->Pos.at(1) += 1;
        if (this->Pos[0] == PlayerPos[0] && this->Pos[1] == PlayerPos[1]){
            this->Pos.at(1) = 0;
            this->Pos.at(0) = rand() % width + 1;
            score++;
        }
    }
};