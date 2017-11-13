#ifndef GRID_H
#define GRID_H
#include "creature.h"
#include"constant.h"
#include "wall.h"
#include"prey.h"
#include"hunter.h"
#include<iostream>


using namespace std;
class Grid
{
public:
    Grid();
    ~Grid();

    void Initialize();

    void Random_pNh();

    void Draw();

    void Step();

private:
    Creature* _grid[width][height];

};

Grid::Grid(){
    Initialize();
}

Grid::~Grid(){
    Initialize();
}

void Grid::Initialize(){
    for(int i=0; i<height;i++){

        for(int j=0 ; j<width;j++){

            if(i==0 || j==21||i==21||j==0){
                _grid[i][j] = new Wall(i,j,'w');
            }
            else{
                _grid[i][j] = NULL;
            }
        }
    }
}

void Grid::Random_pNh(){

     srand(time (NULL));

     for(int i =0; i<100 ; i++){


         int RowNum = rand()%20 +1;
         int ColNum = rand()%20 +1;

         if(_grid[RowNum][ColNum] == NULL){
             _grid[RowNum][ColNum] = new Prey(RowNum,ColNum,'O');
         }
         else{
             i--;
         }
     }

     for(int i =0; i<5 ;i++){
         int RowNum = rand()%20 +1;
         int ColNum = rand()%20 +1;

         if(_grid[RowNum][ColNum] == NULL){
             _grid[RowNum][ColNum] = new Hunter(RowNum,ColNum,'X');
         }
         else{
             i--;
         }
     }
}

void Grid::Draw(){
    for(int i =0; i<height;i++){
        for(int j=0; j<width;j++){
            if(_grid[i][j] != NULL){
                cout<<"["<<_grid[i][j]->GetType()<<"]";
            }
            else{
                cout<<"[ ]";
            }
        }
        cout<<endl;
    }
}

void Grid::Step(){
    for(int i=0 ; i< height ; i++){
        for(int j =0; j<width ; j++){
            if(_grid[i][j])
               _grid[i][j]->Move(_grid);
        }
    }
    for(int i=0 ; i< height ; i++){
        for(int j =0; j<width ; j++){
            if(_grid[i][j])
               _grid[i][j]->Breed(_grid);
        }
    }
    for(int i=0 ; i< height ; i++){
        for(int j =0; j<width ; j++){
            if(_grid[i][j])
               _grid[i][j]->Starve(_grid);
        }
    }

    for(int i=0 ; i< height ; i++){
        for(int j =0; j<width ; j++){
            if(_grid[i][j])
               _grid[i][j]->setBackMoved();
        }
    }
}

#endif // GRID_H
