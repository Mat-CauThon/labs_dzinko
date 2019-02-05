//
//  image.h
//  work
//
//  Created by Roman Mishchenko on 24.02.2018.
//  Copyright © 2018 Roman Mishchenko. All rights reserved.
//

#pragma once
union COL {
    struct
    {
        char R,G,B;
    };
    //char T;
};

struct image
{
    unsigned int width;
    unsigned int heigth;
    COL **pixels = new COL *[width];
};

