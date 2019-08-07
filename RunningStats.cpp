#include <iostream>
#include <stdlib.h>
#include <float.h>
#include <iomanip>

using namespace std;

int main(const int argc, const char* const argv[])
{
    if(argc==1)
    {
        cerr<<"Unable to compute statistics over the set of data because did not enter any arguments "<<endl;
        return -1;
    
    }
    
    cout<<"Sample"<<setw(10)<<"Value"<<setw(10)<<"Minimum"<<setw(10)<<"Average"<<setw(10)<<"Maximum"<<endl;
    
    float x=0;
    float max=FLT_MAX;
    float min=-FLT_MAX;

    for(int i=1;i<argc;i++)
    {
        float z= atof(argv[i]);
        float x= x+z;
        float avg=x/i;
    
        if(z<max)
           max=z;
        
        
        if(z>min)
           min=z;
        
        cout<<i<<setw(10)<<z<<setw(10)<<max<<setw(10)<<avg<<setw(10)<<min<<endl;
        
    }
    

    return 0;




}


