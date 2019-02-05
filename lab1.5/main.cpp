//
//  main.cpp
//  lab1
//
//  Created by Roman Mishchenko on 18.02.2018.
//  Copyright © 2018 Roman Mishchenko. All rights reserved.
//

#include <iostream>
#include "func.hpp"
#include <fstream>
using namespace std;
int main() {
   
    
    const double writeArray[] = {2, 1, 2, 3, 15, 12, 10};
    ofstream out("example.bin", ios::binary);
    out.write((char*)writeArray, sizeof(writeArray));
    out.close();
    
    double readArray[sizeof(writeArray)/sizeof(double)];
    ifstream in("example.bin",ios::binary);
    in.read((char*)readArray, sizeof(readArray));
    in.close();
    
    int n = readArray[0];
    double array[n][3];
    int aJ = 0;
    int aI = 0;
    int i = 1;
    
    while (i < sizeof(readArray)/sizeof(double)) {
        
        array[aI][aJ] = readArray[i];
        aJ++;
        i++;
        
        if(aJ == 3)
        {
            aI++;
            aJ = 0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        triangleHeight(array[i][0], array[i][1], array[i][2]);
    }
    
    return 0;
}
