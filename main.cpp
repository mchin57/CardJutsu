#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>

using namespace std;
using namespace chrono;

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

class card{
  public:
    int value; //1-9
    int type;//0 = snow, 1 = water , 2 = fire

    void printStats(){
        string tpe = "-1";
        switch(type){
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
};

card getRandomCard(){
    //srand((duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()));
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
            cout << endl;
        }
    }

    card playCard(int selection){
        card out = inHand[selection];
        deck.replace(out);
        inHand[selection] = deck.draw();
        return out;
    }
};

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

int main() {
    srand((duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()));
    /*for(int i = 0; i < 100; i++){
        cout<<int((double(rand()%10)/10)*3)<<endl;
    }*/
    card c1 = getRandomCard();
    card c2 = getRandomCard();
    c1.printStats();
    c2.printStats();
    cout << fight(c1,c2);

    cout << "Welcome to definitely not club penguin's card jutsu! What would you like to do?" << endl;
    cout << "hand" << endl << "history" << endl << "play card" << endl << "help" << endl << "quit";
    Deck d1;
    hand h1(d1);
    Deck d2;
    hand h2(d2);
    while(true) {
        string input;
        getline(cin,input);

        if(input == "quit"){
            break;
        }
        else if(input == "hand"){
            h1.viewHand();
        }
        else if (input == "play card"){
            int choice;
            while(true) {//begin checking loop
                cout << "What card would you like to play? (1,2,3,4)" << endl;
                cin >> choice;
                if((choice == 1) or (choice == 2) or (choice == 3) or (choice == 4)){
                    break;
                }
                else{
                    cout << "Please chose 1, 2, 3, or 4." << endl;
                }
            }//end checking loop
            card p1Card = h1.playCard(choice-1);
            cout << "You played "; p1Card.printStats();
            card p2Card = h2.playCard(rand()%4);
            int result = fight(p1Card,p2Card);
            switch(result){
                case(1):
                    cout << ". The opponent played ";  p2Card.printStats(); cout << " meaning that the player won!" << endl;
                    break;
                case(2):
                    cout << ". The opponent played "; p2Card.printStats(); cout <<" meaning that the player lost..." << endl;
                    break;
                case(3):
                    cout << ". The opponent played "; p2Card.printStats(); cout <<" meaning that you tied." << endl;
                    break;
                default:
                    cout << "Error comparing result = " << result;
                    break;
            }
        }
    }

    return 0;
}
