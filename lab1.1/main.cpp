//
//  main.cpp
//  dzLab1
//
//  Created by Roman Mishchenko on 12.02.2018.
//  Copyright © 2018 Roman Mishchenko. All rights reserved.
//

#include <iostream>
#include <cmath>
void triangleHeight(double a, double b, double c)
{
    if(a <= 0 || b <= 0 || c <= 0)
    {
        printf("Треугольник не существует");
        printf("\n");
    }
    else if( a >= (b+c) || b >= (a+c) || c >= (a+b))
    {
        printf("Треугольник не существует");
        printf("\n");
    }
    else
    {
        double mA, mB, mC;
        
        mA = 0.5 * pow((2*b*b+2*c*c-a*a), 0.5);
        mB = 0.5 * pow((2*a*a+2*c*c-b*b), 0.5);
        mC = 0.5 * pow((2*a*a+2*b*b-c*c), 0.5);
        printf("Медиана проведенная к стороне а %f", mA);
        printf("\n");
        printf("Медиана проведенная к стороне b %f", mB);
        printf("\n");
        printf("Медиана проведенная к стороне c %f", mC);
        printf("\n");
    }
}

int main() {
  
   
    const double a = 6;
    const double b = 4;
    const double c = 9;
    
    triangleHeight(a, b, c);
    //////////
    /////////

    
    
    
    
    return 0;
}
