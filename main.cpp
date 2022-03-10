#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>

#include "card.h"
#include "Deck.h"
#include "hand.h"
#include "utils.h"


using namespace std;
using namespace chrono;
//using namespace utils;

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
    helpMsg();
    Deck d1;
    hand h1(d1);
    Deck d2;
    hand h2(d2);

    card p1History[10] = {0};
    card p2History[10] = {0};
    int p1Score = 0;
    int p2Score = 0;

    for(int i = 0; i<11; i++){
        p1History[i] = genPlaceholder();
        p2History[i] = genPlaceholder();
    }

    int turnCounter = 0;
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
            p1History[turnCounter] = p1Card;
            cout << "You played "; p1Card.printStats();

            card p2Card = h2.playCard(rand()%4);
            p2History[turnCounter] = p2Card;
            int result = fight(p1Card,p2Card);

            switch(result){
                case(1):
                    cout << ". The opponent played ";  p2Card.printStats(); cout << " meaning that the player won!" << endl;
                    p1Score++;
                    break;
                case(2):
                    cout << ". The opponent played "; p2Card.printStats(); cout <<" meaning that the player lost..." << endl;
                    p2Score++;
                    break;
                case(3):
                    cout << ". The opponent played "; p2Card.printStats(); cout <<" meaning that you tied." << endl;
                    break;
                default:
                    cout << "Error comparing result = " << result;
                    break;
            }

            turnCounter++;
        }
        else if(input == "help") helpMsg();
        else if(input == "history"){
            cout << "The player recently played: " << endl;
            int counter = 0;
            while(true){
                if(p1History[counter].isPlaceholder) break;
                p1History[counter].printStats();
                counter++;
                cout << endl;
            }
            cout << "and has a score of: " << p1Score << endl;

            cout << "The computer recently played: " << endl;
            counter = 0;
            while(true){
                if(p2History[counter].isPlaceholder) break;
                p2History[counter].printStats();
                counter++;
                cout << endl;
            }
            cout << "and has a score of: " << p2Score << endl;
        }
        if(p1Score == 3){
            cout << "Congrats the player won!";
            break;
        }
        else if (p2Score == 3){
            cout << "Unfortunatly the player lost. Do better.";
            break;
        }
    }

    return 0;
}
