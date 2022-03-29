#include <iostream>
#include "./task5_1.hpp"


int main(){
    Complex<double> a = {1, 2};
    Complex<double> b = {3, -4.25};

    std::cout<<"\nCONJUGATION \n";
    std::cout<<a.to_str()<<"\n";
    //a.to_conjugate();
    std::cout<<(!a).to_str()<<"\n\n";

    std::cout<<"SUM \n";
    std::cout<<a.to_str()<<" + "<<b.to_str()<<" = ";
    std::cout<<(a+b).to_str()<<"\n\n";

    std::cout<<"DIFFERENCE \n";
    std::cout<<a.to_str()<<" - "<<b.to_str()<<" = ";
    std::cout<<(a-b).to_str()<<"\n\n";

    std::cout<<"MULTIPLICATION \n";
    std::cout<<a.to_str()<<" * "<<b.to_str()<<" = ";
    std::cout<<(a*b).to_str()<<"\n\n";

    std::cout<<"DIVISION \n";
    std::cout<<a.to_str()<<" / "<<b.to_str()<<" = ";
    std::cout<<(a/b).to_str()<<"\n\n";

    return 0;
}