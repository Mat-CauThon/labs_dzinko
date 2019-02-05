//
//  main.cpp
//  work
//
//  Created by Roman Mishchenko on 22.02.2018.
//  Copyright © 2018 Roman Mishchenko. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "image.h"
#include "create_black.hpp"
using namespace std;

void writeImage(image* image, const char * PATH){
    ofstream img;
    string width = to_string(image->width);
    string heigth = to_string(image->heigth);
    img.open(PATH, ios::binary);
    img.write("P6", 3);
    img.write(width.c_str(), width.length()+1);
    img.write(heigth.c_str(), heigth.length()+1);
    img.write("255", 4);
    for (int x = 0; x < image->width; x++)
    {
        for (int y = 0; y < image->heigth; y++)
        {
            img.write(reinterpret_cast<char*>(&image->pixels[x*image->heigth + y]), sizeof(COL));
        }
    }
    img.close();
}

image readImage(const char *PATH)
{
    ifstream fin;
    fin.open(PATH, ios::binary);
    image image;
    string buffer, height, width;
    getline(fin, buffer, '\0');
    getline(fin, width, '\0');
    image.width = stoi(width);
    getline(fin, height, '\0');
    image.heigth = stoi(height);
    getline(fin, buffer, '\0');
    getline(fin, buffer, '\0');
    image.pixels = new COL[image.width * image.heigth];
    
   // fin.read();
    while (!fin.eof())
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.heigth; j++)
            {
                fin.read((char *)&(image.pixels[i * image.heigth + j]), sizeof(COL));
            }
        }
    }
    fin.close();
    return image;

}


int main()
{
  
    image myWhite;
    myWhite.width = 5;
    myWhite.heigth = 5;
    create_black(&myWhite);
    
    writeImage(&myWhite, "image1.ppm");
   image kek = readImage("image1.ppm");
    writeImage(&kek, "image2.ppm");
   
   

    return 0;
}

