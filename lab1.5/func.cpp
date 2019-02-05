//
//  func.cpp
//  lab1
//
//  Created by Roman Mishchenko on 18.02.2018.
//  Copyright © 2018 Roman Mishchenko. All rights reserved.
//

#include "func.hpp"
#include <cmath>
#include <fstream>

using namespace std;

void triangleHeight(double a, double b, double c)
{
    double mA, mB, mC;
    
    if( a > 0 && b > 0 && c > 0 && a <= (b+c) && b <= (a+c) && c <= (a+b) )
    {
        mA = 0.5 * pow((2*b*b+2*c*c-a*a), 0.5);
        mB = 0.5 * pow((2*a*a+2*c*c-b*b), 0.5);
        mC = 0.5 * pow((2*a*a+2*b*b-c*c), 0.5);
    }
    else
    {
        mA = 0.0;
        mB = 0.0;
        mC = 0.0;
    }
    
    ofstream myfileO("text.txt");
    
    myfileO << mA << " ";
    myfileO << mB << " ";
    myfileO << mC << "\n";
    
    myfileO.close();
}
