
//  main.cpp
//  worked
//
//  Created by Roman Mishchenko on 19.02.2018.
//  Copyright © 2018 Roman Mishchenko. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>


int n = 3;

using namespace std;
void triangleHeight(double a, double b, double c)
{
    double mA, mB, mC;
    
    if( a > 0 && b > 0 && c > 0 && a <= (b+c) && b <= (a+c) && c <= (a+b) )
    {
        mA = 0.5 * pow((2*b*b+2*c*c-a*a), 0.5);
        mB = 0.5 * pow((2*a*a+2*c*c-b*b), 0.5);
        mC = 0.5 * pow((2*a*a+2*b*b-c*c), 0.5);
    }
    else
    {
        mA = 0.0;
        mB = 0.0;
        mC = 0.0;
    }
    
    ofstream myfileO("text.txt", ios::app);
    
    myfileO << mA << " ";
    myfileO << mB << " ";
    myfileO << mC << "\n";
    
    myfileO.close();
    // array[i][0] = mA;
    // array[i][1] = mB;
    //array[i][2] = mC;
    
    
}
bool num(char c)
{
    
    char slovar[] = "0123456789";
    for(int i = 0; i < 10; i++)
    {
        if(c == slovar[i])
        {
            return true;
        }
    }
    return false;
}

int main() {
    
    
    
    //////////
    /////////
    char * memblock;
    
    bool b = true;
    
    int array[n][3];
    char  words[] = "2 1 2 3 12 16 25";
    streampos size;
    size = 256;
    
    ofstream tab("example2.bin", ios::binary);
    
    for(int i = 0; i < sizeof(words); i++){
        tab.write((char*)&words[i], sizeof(words));
    }
    tab.close();
    
    memblock = new char[size];
    
    fstream show("example2.bin", ios::binary | ios::in);
    show.seekg(0, ios::beg);
    int length = show.tellg();
    
    for(int i = 0; i < sizeof(memblock)/2; i++){
        show.read((char*)&memblock, sizeof(memblock));
        cout << memblock[i];
        length+=sizeof(words);
        show.seekg(length);
    }
    show.close();
   
    int j = 0;
    int i = 0;
    int k = 0;
    int aI = 0;
    int aJ = 0;
    //cout << memblock[i+3] << "\n";
    char * memory = new char[size];
    // int numeric[3];
    
    while ( num(memblock[i]) )
    {
        
        
        j = i;
        while ( num(memblock[j]) )
        {
            
            memory[k] = memblock[j];
            j++;
            k++;
            
        }
        if(b)
        {
            n = atoi(memory);
            b = false;
        }
        else
        {
            
            array[aI][aJ] = atoi(memory);
            aJ++;
            if(aJ == 3)
            {
                aI++;
                aJ = 0;
            }
        }
        for(int p = 0; p < k; p++)
        {
            memory[p] = '\0';
        }
        k = 0;
        i = j + 1;
        
        
    }
   
   // myfile.close();
    
     for(int i = 0; i < n; i++)
     {
         for (int j = 0; j < 3; j++)
            {
                cout << array[i][j] << " ";
            }
         cout << "\n";
     }
     
   
    //ofstream myfileO("text.txt");
    //char string[6] = "";
    
    for(int i = 0; i < n; i++)
    {
        triangleHeight(array[i][0], array[i][1], array[i][2]);
        
    }
    //  myfileO.close();
    
    
  
     /*
     ofstream f("text.txt", ios::out); //создание фунции для ввода в файл
     f.write((char*)&array,sizeof array);    //Записали всю структуру(arra) целиком
     f.close();                              //закрытие файла
    */
    
    
    
    
    return 0;
}

