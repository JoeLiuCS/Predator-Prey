#ifndef WALL_H
#define WALL_H
#include "creature.h"


class Wall : public Creature
{
public:
    Wall();
    Wall(int SetX,int SetY,char SetType);
    char GetType();
};

Wall::Wall(){

}

Wall::Wall(int SetX, int SetY, char SetType):Creature(SetX,SetY,SetType){

}

char Wall::GetType(){
   return Creature::reType();
}

#endif // WALL_H
