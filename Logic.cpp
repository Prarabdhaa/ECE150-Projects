#include <iostream>
#include <cstdlib>

using namespace std;

int main(const int argc, const char* const argv[])
{
  int P;
  int Q;
  P = atoi(argv[1]);     
  Q = atoi(argv[2]);

  int a= (P||Q);
  int b= (P&&Q);
  int c= (!P);
  int d= (!Q);

  cout<<"P: "<<P<<endl; 
  cout<<"Q: "<<Q<<endl;
  cout<<"P AND Q: "<<b<<endl;
  cout<<"P OR Q: "<<a<<endl;
  cout<<"NOT P: "<<c<<endl;
  cout<<"NOT Q: "<<d<<endl;

  return 0;
}
