//
//  circles.cpp
//  test
//
//  Created by Roman Mishchenko on 07.03.2018.
//  Copyright © 2018 Roman Mishchenko. All rights reserved.
//


#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "circles.hpp"
using namespace sf;
void function(float width, float height)
{
    RenderWindow window(sf::VideoMode(width, height), "lab 3");
    srand(time(0));
    CircleShape** array = new CircleShape* [10];
    float x = 0;
    float y = 0;
    for (int i = 0; i < 10; i++)
    {
        array[i] = new CircleShape[10];
        for (int j = 0; j < 10; j++)
        {
            
            array[i][j].setRadius(width/20);
            array[i][j].setFillColor(Color(rand() % 255,rand() % 255,rand() % 255));
            array[i][j].setPosition(x, y);
            y += (width/10);
        }
        x += (width/10);
        y = 0;
    }
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        for(int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                window.draw(array[i][j]);
            }
        }
          window.display();
    }
}
