//
//  create_black.cpp
//  work
//
//  Created by Roman Mishchenko on 24.02.2018.
//  Copyright © 2018 Roman Mishchenko. All rights reserved.
//

#include "create_black.hpp"
#include "image.h"
void create_black(image* image)
{
    COL color;
    for (int i = 0; i < image->width; i++)
    {
        image->pixels[i] = new COL[image->heigth];
        for (int j = 0; j < image->heigth; j++)
        {
            color.R = char(0);
            color.G = char(0);
            color.B = char(0);
            image->pixels[i][j] = color;
        }
    }
}
