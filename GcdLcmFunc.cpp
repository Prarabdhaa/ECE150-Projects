//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

int greatestCommonDenominator(const int, const int);
int leastCommonMultiple(const int, const int);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

int greatestCommonDenominator(const int a, const int b) {
    
    if(a <=0 || b <=0)
    {
        return -1;
    }
    
    else{
        
        int max;
        int min;
        int r;
        
        
        
        if(a>b)
        {
            max=a;
            min=b;
        }
        else
        {
            max=b;
            min=a;
        }
        
        r=max%min;
        
        while(r>0)
        {
            
            
            max=min;
            min=r;
            r=max%min;
        }
        
        if(min>0)
            return min;
        else
            return -1;
        
        
    }
        
    
  
}

int leastCommonMultiple (const int a, const int b) {
    
    if(a <=0 || b <=0)
    {
        return -1;
    }
    
    else{
        
        int max;
        int min;
        int r;
        int lcm;
        
        
        if(a>b)
        {
            max=a;
            min=b;
        }
        else
        {
            max=b;
            min=a;
        }
        
        r=max%min;
        
        while(r>0)
        {
            
            
            max=min;
            min=r;
            r=max%min;
        }
        
        
        lcm=(a/min)*b;
        
        if(lcm>0)
            return lcm;
//        else if (lcm>INT_MAX)
//            return -2;
        else
            return -1;
    }
    

  
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

int main(const int argc, const char* const argv[]) {

  if (argc < 3) {
    cerr << "Error: Usage: " << argv[0] << "<num1> <num2>; exiting" << endl;
    return -1;
  }

  int gcd = greatestCommonDenominator(atoi(argv[1]),atoi(argv[2]));
  if (gcd < 0)
    cerr << "Unable to compute GCD(" << argv[1] << "," << argv[2] << ")" << endl;
  else
    cout << "GCD(" << argv[1] << "," << argv[2] << ") = " << gcd << endl;

  int lcm = leastCommonMultiple(atoi(argv[1]),atoi(argv[2]));
  if (lcm < 0)
    cerr << "Unable to compute LCM(" << argv[1] << "," << argv[2] << ")" << endl;
  else
    cout << "LCM(" << argv[1] << "," << argv[2] << ") = " << lcm << endl;


  return 0;
}

#endif
