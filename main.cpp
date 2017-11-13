#include <iostream>
#include <vector>
#include "grid.h"
using namespace std;

int main()
{
    Grid  test;
    test.Random_pNh();
    char answer ;
    while(answer != 'a'){

        test.Step();
        test.Draw();
        cout<<endl<<endl;
         answer = cin.get();

    }
    return 0;
}

