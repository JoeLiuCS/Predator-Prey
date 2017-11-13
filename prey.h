#ifndef PREY_H
#define PREY_H
#include "creature.h"
#include"hunter.h"

class Prey : public Creature
{

public:
    Prey();
    Prey(int SetX,int SetY,char SetTpye);
    char GetType();

    void Move(Creature * cell[][height]);
    void Breed(Creature * cell[][height]);

};


Prey::Prey(){

}

Prey::Prey(int SetX, int SetY, char SetTpye):Creature(SetX,SetY,SetTpye){

}

char Prey::GetType(){
    return Creature::reType();
}

void Prey::Move(Creature * cell[][height]){
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

            //check the prey does have any hunter around it, if yes, move the hunter to this position(eat)
            if(cell[this->GetX()+x][this->GetY()+y] == NULL){
                temp.push_back(direction);
                randomNum ++;
            }
            else{
                if(cell[this->GetX()+x][this->GetY()+y]->reType() == 'X' ){
                    cell[this->GetX()][this->GetY()] = new Hunter (this->GetX(),this->GetY(),'X');
                    cell[this->GetX()][this->GetY()]->setSteps(cell[this->GetX()+x][this->GetY()+y]->getSteps() + 1);
                    cell[this->GetX()+x][this->GetY()+y] = NULL;
                    return;
                }
            }
        }
        //if has a empty space, it will move
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
            cell[this->GetX() + x][this->GetY()+y] = new  Prey(this->GetX() + x,this->GetY() +y,'O');
            cell[this->GetX() + x][this->GetY()+y]->setMoved();
            cell[this->GetX() + x][this->GetY()+y]->setSteps(this->getSteps()+1);
//            cout<<cell[this->GetX() + x][this->GetY()+y]->getSteps()<<endl;
            cell[this->GetX()][this->GetY()] = NULL;
            return;
        }
        else{
            return;
        }
    }
}

void Prey::Breed(Creature * cell[][height]){
    //check the steps first
    if(this->getSteps() > 3){

        int randomNum = 0;
        vector<string> temp;

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

        //if no space stop the loop, if has space it will breed
        if(randomNum == 0){
            cell[this->GetX()][this->GetY()]->setSteps(0);
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
            cell[this->GetX() + x][this->GetY()+y] = new  Prey(this->GetX() + x,this->GetY() +y,'O');
            cell[this->GetX()][this->GetY()]->setSteps(0);
            cell[this->GetX()+x][this->GetY()+y]->setSteps(0);
            return;
        }
    }
}

#endif // PREY_H
