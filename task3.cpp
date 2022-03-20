#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>


typedef double Real;

const Real STDSTEP = 1e-8;

Real squared(Real);
Real trapezoid(Real);
Real simpson(Real);

Real f(Real x){
    return (Real) 1 / (Real) sqrt((Real)1-x*x); 
}

Real squared(Real step=STDSTEP){
    Real sum = 0;
    Real l = -1;
    Real r;
    while(l < 1){
        r = l + step;
        if (abs((l+r)/2) != 1.0)
            sum += step * f((r+l)/2); 

        l = r;
    }

    return sum;
}

Real trapezoid(Real step=STDSTEP){
    Real sum = 0;
    Real l = -1; + step/10000;
    Real r;
    while(l < 1){
        r = l + step;
        if (abs(l) != 1.0 && abs(r) != 1.0)
            sum += (f(r) + f(l))/2 * step;
        
    
        l = r;
    }

    return sum;
}

Real simpson(Real step=STDSTEP){
    Real sum = 0;
    Real l = -1;// + step/10000;
    Real r;
    
    while (l < 1){
        r = l + step;
        if(abs(l) != 1.0 && abs(r) != 1.0 && abs((l+r)/2) != 1.0)
            sum += (r - l)/6 * (f(l) + 4*f( (r+l)/2 ) + f(r));
        l = r;
    }

    return sum;
}

int main(){
    std::cout<<squared()<<std::endl;
    std::cout<<trapezoid()<<std::endl;
    std::cout<<simpson()<<std::endl;
    std::cout<<M_PI<<" < This is real PI !!11!!"<<std::endl;
    return 0;
}


