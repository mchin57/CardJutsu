//
// Created by 57tuc on 3/10/2022.
//

#include <iostream>
using namespace std;
#include "card.h"
#include "Deck.h"
#pragma once


class hand {
public:
    hand(Deck deck);

    void viewHand();

    card playCard(int selection);
private:
    Deck deck;
    card inHand[4];
};