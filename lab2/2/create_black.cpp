//
//  create_white.cpp
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
    image->pixels = new COL[image->width * image->heigth];
    for (int i = 0; i < image->width; i++)
    {
        for (int j = 0; j < image->heigth; j++)
        {
            color.R = 0;
            color.G = 0;
            color.B = 0;
            image->pixels[i * image->width + j] = color;
        }
    }
}
