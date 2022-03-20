#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

typedef double mFloat;

mFloat get_Pi(int);

mFloat get_Pi(int POINTS = 10'000'000){
    int SqCnt = 0;
    int CrCnt = 0;
    
    mFloat x,y;

    for(int i=0; i < POINTS; i++){
        x = (mFloat) rand() / RAND_MAX;
        y = (mFloat) rand() / RAND_MAX;
        if(x*x + y*y < 1) CrCnt++;
        SqCnt++;
    }

    return 4 * (mFloat) CrCnt / SqCnt;
}

int main(){

    std::cout<<"my  >"<<get_Pi()<<std::endl;
    std::cout<<"real>"<<M_PI;

    return 0;
}