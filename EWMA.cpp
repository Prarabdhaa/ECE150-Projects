
#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>

using namespace std;

int main(const int argc, const char* const argv[])
{
    if(argc < 4)
    {
        cerr << "Error: Insufficient arguments; Expecting at least three arguments" << endl;
        return -1;
    }
    else if (atoi(argv[2]) < 1)
    {
        cerr << "Error: Age limit must be equal to or greater than one." << endl;
        return -1;
    }
    else if (atof(argv[1]) > 1 || atof(argv[1]) < 0)
    {
        cerr << "Error: Weighting parameter must be greater than zero and less than one." << endl;
        return -1;
    }
    
    else
    {
        cout << "Sample\tValue\tMinimum\tEWMA\tMaximum" << endl;
        
        int j = 1, k = 3, min= 1, max= 1;
        
        float alpha = atof(argv[1]);
        float agelim = atof(argv[2]);
        float ewma = atof(argv[3]);
        
        float cmax = -1*FLT_MAX, cmin = FLT_MAX, y = 0;
        
        while(j <= argc-3)
        {
            y = atof(argv[k]);
            ewma = (alpha*y) + (1-alpha)*ewma;
            
            if(min == agelim || y < cmin)
            {
                min = 1;
                cmin = y;
            }
            else
                min++;
            
            if(max == agelim || y > cmax)
            {
                max = 1;
                cmax = y;
            }
            else
                max++;
            
            cout << j << "\t" << y << "\t" << cmin << "\t" << ewma << "\t" << cmax << endl;
            
            j++;
            k++;
        }
    }
    return 0;	
}
