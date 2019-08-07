//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <math.h>
#include <stdlib.h>


//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//


#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

#define NaN std::numeric_limits<float>::quiet_NaN()
#define isNaN(X) (X != X) // NaN is the only float that is not equal to itself

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove

bool hitTargetGivenVelocity (const float h, const float v, const float m,
                             const float d, const float t, const float b,
                             const float w, float& theta);

bool hitTargetGivenAngle (const float h, const float m, const float theta,
                          const float d, const float t, const float b,
                          const float w, float& v);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

bool hitTargetGivenVelocity (const float h, const float v, const float m,
                             const float d, const float t, const float b,
                             const float w, float& theta) {
    
   
    if(h<0 || v<0 || d*b<0 || w<0)
        return false;
    
    float g;
    g=9.8;
    float Pi = 3.141592;
    
    float var1 = g*((g*d*d) + (2*(t-h)*v*v));
    float var2 = v*v*v*v;
    float var3 = v*v;
    float var4 = g*d;
    float theta1 = atan((var3 + sqrt(var2 - var1))/var4);
    float theta2 = atan((var3 - sqrt(var2 - var1))/var4);
    theta1 = (theta1*180)/Pi;
    theta2 = (theta2*180)/Pi;
    
    if(theta1>0&&theta1<90)
    {
        theta = theta1;
        
        return true;
    }
   
    else if (theta2>0&&theta1<90)
    {
        theta = theta2;
        
        return true;
    }
    
    return false;
    
}

bool hitTargetGivenAngle (const float h, const float m, const float theta,
                          const float d, const float t, const float b,
                          const float w, float& v) {
   
    if(h<=0 || b*d<0 || w<=0 || theta>=90||theta<=0)
        return false;
   
    float g = 9.8;
    float Pi = 3.141592;
    float v1 = sqrt((d*d*g)/((d*sin(2*(theta*Pi/180)))-(2*(t-h)*cos(theta*Pi/180)*cos((theta*Pi)/180))));
   
    if(v1<=0)
        return false;
    
    v = v1;
    return true;
    
}



#ifndef MARMOSET_TESTING
int main() {
    
    // Some test driver code here ....
    
    float h = 50;
    float d = 65;
    float b = 0;
    float t = 0;
    float w = 10;
    float m = 1;
    
    float theta = 45; // Angle in degrees;
    float v = 45.21;
    
    cout << "Given angle: " << theta << endl;
    cout << "Target at (" << d << "," << t << ")" << endl;
    if (hitTargetGivenAngle (h, m, theta, d, t, b, w, v)) {
        cout << "required initial velocity: " << v << endl << endl;
    }
    else {
        cout << "cannot calculate the velocity\n\n";
    }
    
    cout << "Given initial velocity: " << v << endl;
    cout << "Target at (" << d << "," << t << ")" << endl;
    if (hitTargetGivenVelocity (h, v, m, d, t, b, w, theta)) {
        cout << "required angle: " << theta << endl << endl;
    }
    else {
        cout << "cannot calculate the angle\n\n";  
    }
    
    return 0;
}
#endif
