//
// Created by 57tuc on 3/10/2022.
//

#include <iostream>
using namespace std;
#pragma once

class card{
public:
    int value; //1-9
    int type;//0 = snow, 1 = water , 2 = fire
    bool isPlaceholder;

    void printStats();
};