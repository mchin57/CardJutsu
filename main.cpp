#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>


using namespace std;
using namespace chrono;

double deceRand(){//this is neither a good sudorandom number gen nor is it efficient.
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

class card{
  public:
    int value; //1-9
    int type;//0 = ice, 1 = earth , 2 = fire

    void printStats(){
        string tpe = "-1";
        switch(type){
            case 0:
                tpe = "ice";
                break;
            case 1:
                tpe = "earth";
                break;
            case 2:
                tpe = "fire";
                break;
        }
        cout << "This is a " << tpe << " card with a value of " << value << endl;
    }
};

card getRandomCard(){
    srand((duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()));
    int val = (rand()%10);
    int type = int((double(rand()%10)/10)*3);
    card out{};
    out.value = val;
    out.type = type;

    return out;
}


class Deck{//is an implimentation of a que designed specificailly for the card class
public:
    card data[10];
    int Qpoint = 0;

    Deck(){
        for(int i = 0; i<10; i++){
            replace(getRandomCard());
        }
    }

    void replace(card c1){
        data[Qpoint] = c1;
        Qpoint++;
    }

    card draw(){
        card out = data[0];
        for(int i = 1; i<Qpoint; i++){
            data[i-1] = data[i];
        }
        Qpoint--;
        return out;
    }

};

class hand{
public:
    Deck deck;
    card inHand[4];

    hand(Deck deck){//constructor
        deck = deck;
        for(int i = 0; i <4; i++){
            inHand[i] = deck.draw();
        }
    }

    void viewHand(){
        for(int i = 0; i<4; i++){
            inHand[i].printStats();
        }
    }

};

int main() {
    //srand((duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()));
    /*for(int i = 0; i < 100; i++){
        cout<<int((double(rand()%10)/10)*3)<<endl;
    }*/
    Deck d1;
    hand h1(d1);
    h1.viewHand();
    return 0;
}
