//
//  create_white.cpp
//  work
//
//  Created by Roman Mishchenko on 24.02.2018.
//  Copyright © 2018 Roman Mishchenko. All rights reserved.
//
#include <iostream>
#include "pool_delete.hpp"
#include "image.h"

void pool_delete(image** pool, int i)
{
    delete [] pool[i];
    
}
