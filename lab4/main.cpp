
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "enemyClass.hpp"
#include "findVel.h"
using namespace sf;





int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1680, 1680), "Tower Defence");

    Texture mapTexture;
    if(!mapTexture.loadFromFile("map.png"))
    {
        std::cout<<"ERROR: Can't load texture :( \n";
    }

    Sprite mapBack;
    mapBack.setTexture(mapTexture);
    
    Texture traceTexture;
    if(!traceTexture.loadFromFile("trace.png"))
    {
        std::cout<<"ERROR: Can't load texture :( \n";
    }
    
    Sprite base;
    Texture baseTexture;
    if(!baseTexture.loadFromFile("base.png"))
    {
        std::cout<<"ERROR: Can't load texture :( \n";
    }
    base.setTexture(baseTexture);
    
    base.setPosition(scale*18, scale*18);
    
    
    
    Sprite ***mapSprite = new Sprite**[enemyNumber];
    for (int i = 0; i < enemyNumber; i++)
    {
        mapSprite[i] = new Sprite*[mapSize];
        for (int j = 0; j < mapSize; j++)
        {
            mapSprite[i][j] = new Sprite[mapSize];
        }
    }

    vector<Texture> textureVector;
    Texture textureAnim;
    
    if(!textureAnim.loadFromFile("animOne.png"))
    {
        std::cout<<"ERROR: Can't load texture :( \n";
    }
    textureVector.push_back(textureAnim);
    
    if(!textureAnim.loadFromFile("animTwo.png"))
    {
        std::cout<<"ERROR: Can't load texture :( \n";
    }
    textureVector.push_back(textureAnim);
    
    if(!textureAnim.loadFromFile("animThree.png"))
    {
        std::cout<<"ERROR: Can't load texture :( \n";
    }
    textureVector.push_back(textureAnim);
    
    
    
    gameMapClass mapObject;
    
    enemyClass* enemyOne = new enemyClass;
    enemyClass* enemyTwo = new enemyClass;
    enemyClass* enemyThree = new enemyClass;
    
    enemyOne->x = scale;
    enemyOne->y = scale;
    
    enemyTwo->x = scale*18;
    enemyTwo->y = 0;
    
    enemyThree->x = scale;
    enemyThree->y = scale*18;
    
    enemyOne->model.setPosition(scale, scale);
    enemyTwo->model.setPosition(scale*18,0);
    enemyThree->model.setPosition(scale,scale*18);
    
    sf::Texture enemyTexture;
    if(!enemyTexture.loadFromFile("enemy2.png"))
    {
        std::cout<<"ERROR: Can't load texture :( \n";
    }
    enemyOne->model.setTexture(enemyTexture);
    enemyTwo->model.setTexture(enemyTexture);
    enemyThree->model.setTexture(enemyTexture);
    
    xAy* point = new xAy;
    xAy* pointTwo = new xAy;
    xAy* pointThree = new xAy;
    
    placeVelToEnemy(*enemyOne, *point, 0, mapObject);
    placeVelToEnemy(*enemyTwo, *pointTwo, 1, mapObject);
    placeVelToEnemy(*enemyThree, *pointThree, 2, mapObject);
    
    
    array<Sprite, preferedNumber> preferedPoint;
    int iP = 0;

    int time = 0;
    while (window.isOpen())
    {
      
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        window.draw(mapBack);
        
        for (int j = 0; j < preferedNumber; j++)
        {
            window.draw(preferedPoint[j]);
        }
        
//animation preferedNumber points
        time--;

        if(time <= 0 )
        {
            iP++;
            if(iP == 3)
            {
                iP = 1;
            }
            
            for (int j = 0; j < preferedNumber; j++)
            {
                preferedPoint[j].setPosition(mapObject.preferPoint[j].x, mapObject.preferPoint[j].y);
                preferedPoint[j].setTexture(textureVector[iP]);
            }
            time = 30;
        }
   
            for (int i = 0; i < enemyNumber; i++)
            {
                for (int j = 0; j < mapSize; j++)
                {
                    for (int k = 0; k < mapSize; k++)
                    {
                        //if(enemyOne.isAlive || enemyTwo.isAlive || enemyThree.isAlive)
                       // {
                           window.draw(mapSprite[i][j][k]);
                       // }
                        
                    }
                }
            }
       
//moving enemy and creating trace
        if(enemyOne->isAlive)
        {
            enemyMove(finalPoint, *enemyOne, *point, 0, mapObject);
            mapSprite[0][point->x/scale][point->y/scale].setTexture(traceTexture);
            mapSprite[0][point->x/scale][point->y/scale].setPosition(enemyOne->x, enemyOne->y);
            window.draw(enemyOne->model);
        }
        
        if(enemyTwo->isAlive)
        {
            enemyMove(finalPoint, *enemyTwo, *pointTwo, 1, mapObject);
            mapSprite[1][pointTwo->x/scale][pointTwo->y/scale].setTexture(traceTexture);
            mapSprite[1][pointTwo->x/scale][pointTwo->y/scale].setPosition(enemyTwo->x, enemyTwo->y);
            window.draw(enemyTwo->model);
        }
        if(enemyThree->isAlive)
        {
            enemyMove(finalPoint, *enemyThree, *pointThree, 2, mapObject);
            mapSprite[2][pointThree->x/scale][pointThree->y/scale].setTexture(traceTexture);
            mapSprite[2][pointThree->x/scale][pointThree->y/scale].setPosition(enemyThree->x, enemyThree->y);
            window.draw(enemyThree->model);
        }
        window.draw(base);
        window.display();
      
    }
    //
    for (int i = 0; i < enemyNumber; i++)
    {
        for (int j = 0; j < mapSize; j++)
        {
            delete [] mapSprite[i][j];
        }
        delete [] mapSprite[i];
    }
    delete[] mapSprite;
    delete enemyOne;
    delete enemyTwo;
    delete enemyThree;
    delete point;
    delete pointTwo;
    delete pointThree;
    
    return EXIT_SUCCESS;
}
