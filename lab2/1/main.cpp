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
#include "create_black.hpp"
#include "create_color.hpp"
#include "create_white.hpp"
using namespace std;

int main()
{
    image myImage;
    myImage.heigth = 1024;
    myImage.width = 1024;
    create_color(&myImage);
    
    ofstream img("color.ppm", ios::binary);
    img.write("P6", 3);
    img.write("1024", 5);
    img.write("1024", 5);
    img.write("255", 4);
    for (int y = 0; y < 1024; y++)
    {
        for (int x = 0; x < 1024; x++)
        {
            img.write(reinterpret_cast<char*>(&myImage.pixels[x][y]), sizeof(COL));
        }
    }
    img.close();
    
    image myBlack;
    myBlack.width = 1024;
    myBlack.heigth = 1024;
    create_black(&myBlack);
    
    ofstream bImg("black.ppm", ios::binary);
    bImg.write("P6", 3);
    bImg.write("1024", 5);
    bImg.write("1024", 5);
    bImg.write("255", 4);
    for (int y = 0; y < 1024; y++)
    {
        for (int x = 0; x < 1024; x++)
        {
            bImg.write(reinterpret_cast<char*>(&myBlack.pixels[x][y]), sizeof(COL));
        }
    }
    bImg.close();
    
    image myWhite;
    myWhite.width = 1024;
    myWhite.heigth = 1024;
    create_white(&myWhite);
    ofstream wImg("white.ppm", ios::binary);
    wImg.write("P6", 3);
    wImg.write("1024", 5);
    wImg.write("1024", 5);
    wImg.write("255", 4);
    cout << 1 << "\n";
    for (int y = 0; y < 1024; y++)
    {
        for (int x = 0; x < 1024; x++)
        {
            wImg.write(reinterpret_cast<char*>(&myWhite.pixels[x][y]), sizeof(COL));
        }
    }
    wImg.close();
    return 0;
}

