#ifndef HUNTER_H
#define HUNTER_H
#include "creature.h"

class Hunter : public Creature
{
public:
    Hunter();
    Hunter(int SetX, int SetY, char Settype);

    char GetType();

    void Move(Creature * cell[][height]);
    void Breed(Creature * cell[][height]);
    void Starve(Creature * cell[][height]);

};


Hunter::Hunter(){

}


Hunter::Hunter(int SetX, int SetY, char Settype):Creature(SetX,SetY,Settype){

}


char Hunter::GetType(){
    return Creature::reType();
}

void Hunter::Move(Creature *cell[][height]){
    if(!this->getMoved()){

        int randomNum = 0;
        vector<string> temp;

        //check around it has empty space or prey
        for(int i =0; i<4 ;i++){
            int x = 0;
            int y = 0;
            string direction;
            if(i == 0){
             x = -1;y = 0;
             direction ="left";
            }
            else if( i==1 ){
              x = 1;y = 0;
              direction ="right";
            }
            else if( i==2 ){
              x = 0;y = 1;
              direction ="up";
            }
            else{
                x= 0; y= -1;
                direction ="down";
            }

            if(cell[this->GetX()+x][this->GetY()+y] == NULL){
                temp.push_back(direction);
                randomNum ++;
            }
            else{
                //if found prey, it will eat it and stop the loop
                if(cell[this->GetX() + x][this->GetY()+y]->reType() == 'O'){
                    cell[this->GetX() + x][this->GetY()+y] = new Hunter(this->GetX() + x,this->GetY() +y,'X');
                    cell[this->GetX() + x][this->GetY()+y]->setMoved();
                    cell[this->GetX() + x][this->GetY()+y]->setSteps(this->getSteps()+1);
                    cell[this->GetX() + x][this->GetY()+y]->setStarve(0);
                    cell[this->GetX()][this->GetY()] = NULL;
                    return;
                }
            }
        }

        //if not found prey, it will random a position,then move
        if(randomNum > 0){
            int x= 0;
            int y= 0;
            int num = rand()%randomNum;
            if(temp[num] == "left"){
             x = -1;y = 0;
            }
            else if( temp[num] == "right" ){
              x = 1;y = 0;
            }
            else if( temp[num] == "up" ){
              x = 0;y = 1;
            }
            else{
                x= 0; y= -1;
            }
            cell[this->GetX() + x][this->GetY()+y] = new Hunter(this->GetX() + x,this->GetY() +y,'X');
            cell[this->GetX() + x][this->GetY()+y]->setMoved();
            cell[this->GetX() + x][this->GetY()+y]->setSteps(this->getSteps()+1);
            cell[this->GetX() + x][this->GetY()+y]->setStarve(this->getSarve() + 1);
            cell[this->GetX()][this->GetY()] = NULL;
            return;
        }
    }
}

void Hunter::Breed(Creature * cell[][height]){
    if(this->getSteps() > 8){
        int randomNum = 0;
        vector<string> temp;

        //check around it has empty space or prey
        for(int i =0; i<4 ;i++){
            int x = 0;
            int y = 0;
            string direction;
            if(i == 0){
             x = -1;y = 0;
             direction ="left";
            }
            else if( i==1 ){
              x = 1;y = 0;
              direction ="right";
            }
            else if( i==2 ){
              x = 0;y = 1;
              direction ="up";
            }
            else{
                x= 0; y= -1;
                direction ="down";
            }
            if(cell[this->GetX()+x][this->GetY()+y] == NULL){
                temp.push_back(direction);
                randomNum ++;
            }
        }

        //if does not find stop the loop
        //check the steps, then bread
        if(randomNum == 0){
            return;
        }
        else{
            int x= 0;
            int y= 0;
            int num = rand()%randomNum;
            if(temp[num] == "left"){
             x = -1;y = 0;
            }
            else if( temp[num] == "right" ){
              x = 1;y = 0;
            }
            else if( temp[num] == "up" ){
              x = 0;y = 1;
            }
            else{
                x= 0; y= -1;
            }
            cell[this->GetX() + x][this->GetY()+y] = new  Hunter(this->GetX() + x,this->GetY() +y,'X');
            cell[this->GetX()][this->GetY()]->setSteps(0);
            return;
        }
    }
}

void Hunter::Starve(Creature * cell[][height]){
    if(this->getSarve() == 3){
       cell[this->GetX()][this->GetY()] = NULL;
    }
}

#endif // HUNTER_H
