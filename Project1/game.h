#pragma once
#include <iostream>
#include <limits>
#include <cstdio>
#include <random>
#include <ctime>
#include <string>
using namespace std;


class Player {
public:
    string name{ "³ª" };
    int hp{ 30 };
    int str{ 3 };
    int wis{ 1 };
    int intel{ 1 };

    void addStr(int v) { str += v; }
    void addHp(int v) { hp += v; }
};


class Monster {
public:
    string name{ "°Ç´Þ" };
    int hp{ 10 }; 
    int str{ 3 };
};


class Game {
public:
    Game();
    
  
    
    void intro();
    void firstChoice();
    void battleScene();   
    void afterDetour();
    void farmScene();
    void lookfoward();
    void enterCave();

private:
    Player  player;  
    Monster thug;    
    mt19937 rng; 

    int readInt();
};