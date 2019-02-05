//
//  main.cpp
//  work
//
//  Created by Roman Mishchenko on 22.02.2018.
//  Copyright © 2018 Roman Mishchenko. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "image.h"
#include "create_white.hpp"
#include "pool_new.hpp"
#include "pool_delete.hpp"
using namespace std;
image** memoryPool = new image*[100];


int main()
{
    
    
    image myWhite;
    myWhite.width = 5;
    myWhite.heigth = 5;
    create_white(&myWhite);
    ofstream wImg("white.ppm", ios::binary);
    wImg.write("P6", 3);
    wImg.write("5", 2);
    wImg.write("5", 2);
    wImg.write("255", 3);
    
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            wImg.write(reinterpret_cast<char*>(&myWhite.pixels[x][y]), sizeof(COL));
        }
    }
    wImg.close();
    
    
   image *index = pool_new(myWhite, *memoryPool, 0);
    cout << index << endl;
   pool_delete(memoryPool, 0);
    cout << &memoryPool[0][0];
    return 0;
}

