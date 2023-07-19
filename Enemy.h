#pragma once
#include <vector>
#include <random>
#include <time.h>
using namespace std;
class Enemy{
public:
    vector<int> Pos = {10, 0}; 
    char EnemyChar = '*';
    int score = 0;
public:
    void MoveEnemy(int height, int width, vector<int> PlayerPos){
        Pos[1] += 1;
        if (Pos[0] == PlayerPos[0] && Pos[1] == PlayerPos[1]){
            srand(time(0));
            Pos[1] = 0;
            Pos[0] = rand() % width + 1;
            score++;
        }
    }
};