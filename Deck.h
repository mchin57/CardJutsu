//
// Created by 57tuc on 3/10/2022.
//

#include <iostream>
#include "card.h"
using namespace std;
#pragma once


class Deck {
public:


    Deck();

    void replace(card c1);

    card draw();

private:
    card data[10];
    int Qpoint = 0;
};