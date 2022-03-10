//
// Created by 57tuc on 3/10/2022.
//

#include <iostream>
#include <chrono>
#include <thread>

#include "utils.h"

using namespace chrono;


card getRandomCard(){
    //srand((duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()));
    int val = (rand()%10);
    int type = int((double(rand()%10)/10)*3);
    card out{};
    out.value = val;
    out.type = type;

    return out;
}

card genPlaceholder(){
    card out{};
    out.isPlaceholder = true;

    return out;
}

int fight(card c1, card c2){//returns either 1, 2 or 3. 1 or 2 indicates if the first or second card won, and 3 indicates a tie.
    if(c1.type == c2.type){
        if(c1.value > c2.value){
            return 1;
        }
        else if(c1.value < c2.value){
            return 2;
        }
        else{
            return 3;
        }
    }
    //0 = snow, 1 = water, 2 = fire -- snow beats water beats fire -- snow < water < fire
    if((c1.type < c2.type)){
        cout <<"a";
        return (c2.type - c1.type); //cases: (snow, water -> snow wins, 1-0 = 1), (snow, fire -> fire wins, 2-0 = 2), (water, fire -> water wins, 2-1 = 1)
    }
    else if((c2.type < c1.type)) {
        cout <<"b";
        return (3-(c1.type - c2.type));
    }
    return -1;
}

void helpMsg(){
    cout << "hand" << endl << "history" << endl << "play card" <<
    endl << "quit" << endl << "If you would like to see this message again just type \"help\".";
}

double deceRand() {//this is neither a good sudorandom number gen nor is it efficient.
    //it does appear to be marginally better than rand() though so I'll take it
    this_thread::sleep_for(milliseconds(2));
    double out = -1;
    long long choser = (duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() % 10);
    switch(choser){
        case 0:
            out = (double(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() % 7817))/7817;
            break;
        case 1:
            out = (double(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() % 6379))/6379;
            break;
        case 2:
            out = (double(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() % 7333))/7333;
            break;
        case 3:
            out = (double(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() % 6673))/6673;
            break;
        case 4:
            out = (double(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() % 7079))/7079;
            break;
        case 5:
            out = (double(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() % 7481))/7481;
            break;
        case 6:
            out = (double(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() % 6301))/6301;
            break;
        case 7:
            out = (double(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() % 5717))/5717;
            break;
        case 8:
            out = (double(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() % 6577))/6577;
            break;
        case 9:
            out = (double(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() % 6521))/6521;
            break;
        default:
            out = -1;
    }

    return out;
}