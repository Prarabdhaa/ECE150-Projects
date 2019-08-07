#include <iostream>
#include <stdlib.h>

using namespace std;

int main ( const int argc, const char* const argv[] )
{
    if (argc <= 1)
    {
        cerr << "Unable to compute statistics over data set because of insufficient arguments" << endl;
    }
    
    else
    {
        float Min = atof (argv[1]);
        float Max = atof (argv[1]);
        float x = 0.0;
        float Avg = 0.0;
        
        int i = 1;
        while (i < argc)
        {
            float newnum = atof (argv[i]);
            x += newnum;
            
            if ( newnum < Min )
                Min = newnum;
            
            if ( newnum > Max )
                Max = newnum;
            
            Avg = x/(i);
            i+=1;
        }
        
        cout << "Number of floating-point numbers: " << argc-1 << endl;
        cout << "Minimum floating-point number: " << Min << endl;
        cout << "Average floating-point number: " << Avg << endl;
        cout << "Maximum floating-point number: " << Max << endl;
        
    }
    return 0;
}
