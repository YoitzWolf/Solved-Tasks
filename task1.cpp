#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

const int POINTS = 10'000'000;

typedef double mFloat;


int main(){

    int SqCnt = 0;
    int CrCnt = 0;
    
    mFloat x,y;

    for(int i=0; i < POINTS; i++){
        x = (mFloat) rand() / RAND_MAX;
        y = (mFloat) rand() / RAND_MAX;
        //
        // x = (x * (x % 2 ? -1 : 1))/ RAND_MAX
        //
        if(x*x + y*y < 1) CrCnt++;
        SqCnt++;
    }

    std::cout<<"my  >"<<4 * (mFloat) CrCnt / SqCnt<<std::endl;
    std::cout<<"real>"<<M_PI;

    return 0;
}