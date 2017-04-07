#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class TwoDice {
public:
    TwoDice(); // default constructor
    TwoDice(int d1, int d2); //other constructor
    int getdice1() const;
    int getdice2() const;
    void roll();
private:
    int dice1;
    int dice2;
};

//default constructor, set's random values for the dice
TwoDice::TwoDice() {
    dice1 = 1 + rand() % 6;
    dice2 = 1 + rand() % 6;
}

//other constructor, set's values to whatever is passed in the parameters
TwoDice::TwoDice(int d1, int d2) {
    dice1 = d1;
    dice2 = d1;
}

int TwoDice::getdice1() const {
    return dice1;
}

int TwoDice::getdice2() const {
    return dice2;
}

void TwoDice::roll() {
    dice1 = 1 + rand() % 6;
    dice2 = 1 + rand() % 6;
}

int main() {
    srand((int)time(0));
    
    TwoDice myDice;
    //myDice.roll();
    
    cout << myDice.getdice1() << endl;
    cout << myDice.getdice2() << endl;
    
    return 0;
}