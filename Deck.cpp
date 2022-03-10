//
// Created by 57tuc on 3/10/2022.
//

#include "Deck.h"
#include "card.h"
#include "utils.h"

Deck::Deck(){
    for(int i = 0; i<10; i++){
        replace(getRandomCard());
    }
}

void Deck::replace(card c1){
    data[Qpoint] = c1;
    Qpoint++;
}

card Deck::draw(){
    card out = data[0];
    for(int i = 1; i<Qpoint; i++){
        data[i-1] = data[i];
    }
    Qpoint--;
    return out;
}
