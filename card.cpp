//
// Created by 57tuc on 3/10/2022.
//

#include "card.h"

void card::printStats() {
    string tpe = "-1";
    switch (type) {
        case 0:
            tpe = "snow";
            break;
        case 1:
            tpe = "water";
            break;
        case 2:
            tpe = "fire";
            break;
    }
    cout << "a " << tpe << " card with a value of " << value;
}