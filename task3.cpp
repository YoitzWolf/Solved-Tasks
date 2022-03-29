#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>


typedef double Real;

const Real STDSTEP = 1e-8;

Real squared(Real L, Real R, Real step=STDSTEP);
Real trapezoid(Real L, Real R, Real step=STDSTEP);
Real simpson(Real L, Real R, Real step=STDSTEP);

Real f(Real x){
    if (abs(x) == 1.0) return 0;// * (abs(x) == x ? 1 : -1);
    return (Real) 1 / (Real) sqrt((Real)1-x*x); 
}

Real squared(Real L, Real R, Real step){
    Real sum = 0;
    Real l = L;
    Real r;
    while(l < R){
        r = l + step;
        
        sum += step * f((r+l)/2); 

        l = r;
    }

    return sum;
}

Real trapezoid(Real L, Real R, Real step){
    Real sum = 0;
    Real l = L;// + step/10000;
    Real r;
    while(l < R){
        r = l + step;
        //if (abs(l) != 1.0 && abs(r) != 1.0)
        sum += (f(r) + f(l))/2 * step;
    
        l = r;
    }

    return sum;
}

Real simpson(Real L, Real R, Real step){
    Real sum = 0;
    Real l = L;// + step/10000;
    Real r;
    
    while (l < R){
        r = l + step;
        //if(abs(l) != 1.0 && abs(r) != 1.0 && abs((l+r)/2) != 1.0)
        sum += (r - l)/6 * (f(l) + 4*f( (r+l)/2 ) + f(r));
        l = r;
    }

    return sum;
}

int main(){
    std::cout<<squared(-1, 1)<<std::endl;
    std::cout<<trapezoid(-1, 1)<<std::endl;
    std::cout<<simpson(-1, 1)<<std::endl;
    std::cout<<M_PI<<" < This is real PI !!11!!"<<std::endl;
    return 0;
}


