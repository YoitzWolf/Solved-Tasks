#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
//#include <>

typedef double Real;

const Real STDSTEP = 1e-6;

//void split_squared(Real (*f)(Real), Real[] *);     // Create splitting for squared
//Real summarize(Real*[], Real);


int split_squared(Real a, Real b, Real *list, Real step=STDSTEP){
    if (a == b) return -1;
    //if (a > b) std::swap(a, b);
    int i = 0;
    Real l, r;
    l = a;
    while (l < b && l != INFINITY){
        
        r = l + step;
        //std::cout<<i<<" > "<<l<< " "<<r<<"\n";
        if(r == INFINITY) break;
        list[i] = (r+l)/2;
        l = r;
        i++;
    }
    //std::cout<<i<<" AFTER > "<<l<< " "<<r<<"\n";
    return i;
}

void count_split(Real (*f)(Real), Real *list, int mx){
    for(int i=0; i<mx; i++) list[i] = f(list[i]); 
}

Real summarize(Real *list, int mx, Real step=STDSTEP){
    Real sum = 0;
    for(int i=0; i<mx; i++) sum += list[i]; 
    return sum*step;
}
    
Real f(Real x){
    return 1;//(Real) 1 / (Real) sqrt((Real)1-x*x); 
}


int main(){
    Real a, b;
    std::cout<<"Enter a and b for integral: \n";
    std::cin>>a;
    std::cin>>b;
    int N = (b-a)/STDSTEP + 1;
    Real *arr = new Real[N];
    
    int n = split_squared(a, b, arr);
    count_split(&f, arr, n);
    Real ans = summarize(arr, n);
    std::cout<<"Value: "<<ans;

    return 0;
}


