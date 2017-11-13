#ifndef CREATURE_H
#define CREATURE_H
#include<cstdlib>
#include<ctime>
#include<vector>
#include<string>
#include"constant.h"
#include<iostream>
using namespace std;
class Creature{
public:
    Creature(){}
    Creature(int setx,int sety,char setType){ type = setType; _x = setx; _y = sety;}
    ~Creature(){}

    virtual void Move(Creature *cell[][height]) {}
    virtual void Breed(Creature *cell[][height]){}
    virtual void Starve(Creature *cell[][height]){}
    virtual char GetType(){throw 'N';}

    char reType(){return type;}

    int GetX(){return _x;}
    int GetY(){return _y;}

    void setMoved(){_moved = true;}
    bool getMoved(){return _moved;}
    void setBackMoved(){_moved = false;}

    void setSteps(int num){_steps = num;}
    int getSteps(){return _steps;}

    void setStarve(int num){_starve = num;}
    int getSarve(){return _starve;}

private :
    int _starve = 0;
    bool _moved = false;
    int _steps = 0;
    char type;
    int _x;
    int _y;
};

#endif // CREATURE_H
