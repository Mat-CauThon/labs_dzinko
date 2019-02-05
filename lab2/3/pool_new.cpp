//
//  create_white.cpp
//  work
//
//  Created by Roman Mishchenko on 24.02.2018.
//  Copyright © 2018 Roman Mishchenko. All rights reserved.
//
#include <iostream>
#include "pool_new.hpp"
#include "image.h"

image* pool_new(image images, image* pool, int i)
{
   
   if(i < 100)
   {
    pool = new image[10];
    pool[i].pixels = images.pixels;
    pool[i].width = images.width;
    pool[i].heigth = images.heigth;
       return &pool[i];
   }
    else
    {
        return nullptr;
    }
}
