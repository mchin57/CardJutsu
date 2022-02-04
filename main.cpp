#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>


using namespace std;
using namespace chrono;

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

card getRandomCard(){
    int val = int(deceRand() * 10);
    int type = int(deceRand() * 3);
    card out{};
    out.value = val;
    out.type = type;

    return out;
}

int main() {
    card c1{};
    c1.value = 1;
    c1.type = 2;
    getRandomCard().printStats();
    return 0;
}
