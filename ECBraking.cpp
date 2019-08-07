#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(const int argc, const char* const argv[])

{
    if (argc < 4){
        cerr << "Error: Insufficient arguments: expecting 3 arguments"<<endl;
        return -1;
    }
    
    if(argc > 4){
        cerr << "Warning: Expecting three command-line arguments; received four; ignoring extraneous arguments." << endl;
        return -1;
    }
    
    
    float v;
    float d;
    float ad;
    
    v= atof(argv[1]);
    d= atof(argv[2]);
    ad= atof(argv[3]);
    
    if(ad<0)
    {
        cerr<<"Error: The decerleration cannot be less than 0";
    }

    
    float a;
    float t;
    float aa;
    float v2;
    float q = pow(v,2);
    float p= 2*d;
    if ( d>0 )
        a = (q/p);
    else
        a =(-1)*(q/p);
    
    if(v<0)
        t=(-1)*v/a;
    else
        t=v/a;
    
    
    if(v<0 && d<0)
        aa=pow(v,2)+2*ad*d;
    else
        aa=pow(v,2)-2*ad*d;
    
    if(v<0 && d<0)
        v2=(-1)*(sqrt(aa));
    
    else
        v2=sqrt(aa);
    
    
    float t2=(v2-v)/ad;
    
    
    if(v==0)
        cout<<"There is no possibility of collision because the car is at rest since velocity is 0."<<endl;
    
    else if (v<0 && d>0)
        cout<<"There is no possibility of collision because the car has passed the obstacle since velocity and distance are in oppsite directions."<<endl;
    
    else if(d<0 && v>0)
        cout<<"There is no possibility of collision because the car has passed the obstacle since velocity and distance are in oppsite directions."<<endl;
    
    else if(d==0)
        cout<<"crash in 0 seconds at velocity "<<v<<" m/s"<<endl;
    
    
    
    
    else{
        
        if(a<=ad){
            cout<<"Initial car velocity: "<<v<<" m/s"<<endl;
            cout<<"Distance to obstacle: "<<d<<" m"<<endl;
            cout<<"Minimum deceleration: "<<a<<" m/s/s"<< endl;
            cout<<"Maximum stopping time: "<<t<<" s"<< endl;
        }
        
        else
            cout<<"Crash will occur in "<<t2<<" seconds at velocity "<<v2<<" m/s; deploying airbags."<<endl;
        
    }
    
    return 0;
    
}
