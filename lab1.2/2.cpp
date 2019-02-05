//
//  2.cpp
//  dzLab1
//
//  Created by Roman Mishchenko on 12.02.2018.
//  Copyright © 2018 Roman Mishchenko. All rights reserved.
//
#include <stdio.h>
//#include <iostream>
#include <cmath>
void triangleHeight(double a, double b, double c)
{
    double mA = 0.0, mB = 0.0, mC = 0.0;
    
    if( a > 0 && b > 0 && c > 0 && a < (b+c) && b < (a+c) && c < (a+b) )
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
    printf("%f", mA);
    printf(" ");
    printf("%f", mB);
    printf(" ");
    printf("%f", mC);
    printf("\n");
}

int main() {
    
    
    
    //////////
    /////////
    
    const int n = 5;
    const double array[n][3] = {
        {1,2,3},
        {2,3,4},
        {9,2,3},
        {2,3,4},
        {9,0,11}
    };
    
    for(int i = 0; i < n; i++)
    {
        triangleHeight(array[i][0], array[i][1], array[i][2]);
    }
    
    return 0;
}

