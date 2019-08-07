#include <iostream>
#include <stdlib.h>


using namespace std;

int main(const int argc,const char *const argv[])
{
    
    if (argc < 4) {
        cerr << "Error: Unable to compute Nth root because of insufficient arguments." << endl;
        return -1;
    }
    
    if (argc > 4) {
        cerr << "Warning: Expecting three command-line arguments; ignoring extraneous arguments.";
    }
    
    float num = atof(argv[1]);
    float p = atof(argv[3]);
    int root = atoi(argv[2]);
    
    if ((num < 0) && (root % 2 == 0))
    {
        cerr << "Error: Unable to compute Nth root because cannot root negative number with even root." << endl;
        return 1;
    }
    
    if (p <= 0)
    {
        cerr << "Error: Unable to compute Nth root because precision is less than or equal to zero." << endl;
        return  1;
    }
    
    if (root <= 1)
    {
        cerr << "Error: Unable to compute Nth root because root is less than or equal to one." << endl;
        return 1;
    }
    

    
    float n = 1;
    float t = num/root;
    float curr = p+1;
    
    while (curr > p || curr < -1*p) {
        n=1;
        for(int i=0; i<root-1; i++)
        {
            n*=t;
        }
        t = (root-1)*t/root + num/(root*n);
        n=1;
        for(int i=0; i<root; i++)
        {
            n*=t;
        }
        if((num - n) / num == curr)
        {
            break;
        }
        curr = (num - n) / num;
    }
    if(curr<0)
        curr*=-1;
    cout << "ROOT(" << num << "," << root << ")" << " = " << t << endl;
    cout << "(with precision " << curr << ")" << endl;
    
    
    return 0;
}

