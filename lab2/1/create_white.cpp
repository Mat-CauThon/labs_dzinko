//
//  create_white.cpp
//  work
//
//  Created by Roman Mishchenko on 24.02.2018.
//  Copyright © 2018 Roman Mishchenko. All rights reserved.
//

#include "create_white.hpp"
#include "image.h"
void create_white(image* image)
{
    COL color;
    for (int i = 0; i < image->width; i++)
    {
        image->pixels[i] = new COL[image->heigth];
        for (int j = 0; j < image->heigth; j++)
        {
            color.R = char(255);
            color.G = char(255);
            color.B = char(255);
            image->pixels[i][j] = color;
        }
    }
}
