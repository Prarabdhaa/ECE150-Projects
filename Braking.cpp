#include <iostream>
#include <cmath>
#include <stdlib.h>


using namespace std;

int main(const int argc, const char* const argv[]) {

    float v;
    float d;
    float a;

    v= atof(argv[1]);
    d= atof(argv[2]);

    float q = pow(v,2);
    float p= 2*d;
    a= q/p;
    float t=v/a;


    cout<<"Initial car velocity: "<<v<<"m/s"<<endl;
    cout<<"Distance to obstacle: "<<d<<"m"<<endl;
    cout<<"Minimum deceleration: "<<a<<"m/s/s"<< endl;
    cout<<"Maximum stopping time: "<<t<<"s"<< endl;
    

return 0;



}
