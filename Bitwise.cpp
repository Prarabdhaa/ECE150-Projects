#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main( const int argc, const char* const argv[])
{
	int N;
	int S;
       
       N = atoi(argv[1]);
       S = atoi(argv[2]);

       int N1result = N*(pow(2,S));
       int N2result = N/(pow(2,S));


       cout<<"N: "<<N<< endl;
       cout<<"S: "<<S<< endl;

       cout<<"Left-shift of N by S bits is: "<< (N << S)<<endl;
       cout<<"Right-shift of N by S bits is: "<< (N >> S) << endl;
       cout<<"The equivalent math operation of left-shift N by S bits is: N*(pow(2,S)"<<endl;
       cout<<"And the result of that operation is: "<<N1result<<endl;
       cout<<"The equivalent math operation of right-shift N by S bits is: N/(pow(2,S)"<<endl;
       cout<<"And the result of that operation is: "<<N2result<<endl;
    
    return 0;



}
