//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <math.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY) {
    if(v < 0.0 || h < 0.0 || t < 0.0 || d < 0.0 || b < 0.0 || w < 0.0)
      return false;
    
    float g=9.8;
    double radians;
    radians=(theta*M_PI)/180.0;
    
    double x,y;
    
   
    
    if(theta == 90.0 || v == 0){
        destY=h;
        destX=0;
        return true;
    }
    
    double time;
    
   
    
      time=((2*v*sin(radians))+sqrt(4*v*v*sin(radians)*sin(radians)+8*g*h))/(2*g);
    
    x= v*cos(radians)*time;
    
    if(theta > 90){
        destY=0;
        destX=x;
        return true;
    }

    else{
        
       
        if(x<b){
          destY=0;
          destX=x;
            return true;
          
        }
            x=b;
            y=x*tan(radians)-g*x*x/(2*v*v*cos(radians)*cos(radians));
        
        
        if(fabs(y+h)<=t){
            
            destX=b;
            destY=y+h;
            return true;
        }
        
        destY=t;
        
        double a = g*x*x/(2*v*v*cos(radians)*cos(radians));
        
        destX=(tan(radians)+sqrt(tan(radians)*tan(radians)-4*a*t))/2*a;

        if(destX<(b+w)){
            
            return true;
            
        }
        
        destY=0;
        destX=v*cos(radians)*time;
        return true;
    
        
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

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....

  float h = 50;
  float v = 9.2;
  float m = 1;
  float theta = 67.89;        // Angle in degrees; will need to be converted by function
  float d = 100;
  float t = 20;
  float b = 30;
  float w = 20;

  float hitsAtX;
  float hitsAtY;

  if (projectileDestination(h,v,m,theta,d,t,b,w,hitsAtX,hitsAtY))
    cout << "Projectile hit at (" << hitsAtX << ", " << hitsAtY << ")" <<endl;
  else
    cout << "Unable to calculate where projectile hits." << endl;
  return 0;
}

#endif
