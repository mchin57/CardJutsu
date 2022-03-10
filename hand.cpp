//
// Created by 57tuc on 3/10/2022.
//

#include "hand.h"
#include "card.h"
#include "Deck.h"


    hand::hand(Deck deck){//constructor
        deck = deck;
        for(int i = 0; i <4; i++){
            inHand[i] = deck.draw();
        }
    }

    void hand::viewHand(){
        for(int i = 0; i<4; i++){
            inHand[i].printStats();
            cout << endl;
        }
    }

    card hand::playCard(int selection){
        card out = inHand[selection];
        deck.replace(out);
        inHand[selection] = deck.draw();
        return out;
    }