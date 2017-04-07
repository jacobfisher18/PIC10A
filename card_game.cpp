/*
 Jacob Fisher
 2/22/16
 Implements a betting card game
 Demonstrates use of custom classes
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//represents a card and stores data and functions involving its rank and suite
class Card {
public:
    Card(); //constructor
    int get_rank() const;
    string get_rank_string() const;
    string get_suite_string() const;
private:
    int rank;
    int suite;
};

//Card constructor, set's random values for the rank and suite
Card::Card() {
    rank = 1 + rand() % 13;
    suite = 1 + rand() % 4;
}

int Card::get_rank() const {
    return rank;
}

string Card::get_rank_string() const {
    switch (rank) {
        case 1:
            return "Ace";
            break;
        case 2:
            return "Two";
            break;
        case 3:
            return "Three";
            break;
        case 4:
            return "Four";
            break;
        case 5:
            return "Five";
            break;
        case 6:
            return "Six";
            break;
        case 7:
            return "Seven";
            break;
        case 8:
            return "Eight";
            break;
        case 9:
            return "Nine";
            break;
        case 10:
            return "Ten";
            break;
        case 11:
            return "Jack";
            break;
        case 12:
            return "Queen";
            break;
        case 13:
            return "King";
            break;
        default:
            return "Error: Rank Out of Bounds";
    }
}

string Card::get_suite_string() const {
    switch (suite) {
        case 1:
            return "Diamonds";
            break;
        case 2:
            return "Hearts";
            break;
        case 3:
            return "Spades";
            break;
        case 4:
            return "Clubs";
            break;
        default:
            return "Error: Suite Out of Bounds";
    }
}

//represents the player and includes functions and data involving their name and money
class Player {
public:
    Player(string given_name, int given_starting_money); //constructor
    string get_name() const;
    int get_current_money() const;
    int get_starting_money() const;
    void change_money(int amount);
private:
    string name;
    int starting_money;
    int current_money;
};

//Player constructor
Player::Player(string given_name, int given_starting_money) {
    name = given_name;
    starting_money = given_starting_money;
    current_money = starting_money;
}

string Player::get_name() const {
    return name;
}

int Player::get_current_money() const {
    return current_money;
}

int Player::get_starting_money() const {
    return starting_money;
}

//changes the amount of money the player has, whether increasing or decreasing
void Player::change_money(int amount) {
    current_money += amount;
}

//returns the full string name of a card including "of"
string getCardName(Card myCard) {
    return myCard.get_rank_string() + " of " + myCard.get_suite_string();
}

//returns true if card3 has a rank in between card1 and card2
bool inBetween(Card card1, Card card2, Card card3) {
    int c1 = card1.get_rank();
    int c2 = card2.get_rank();
    int c3 = card3.get_rank();
    
    if (c1 == c2) {
        return false;
    }
    
    else if (c1 < c2) {
        if ((c3 > c1) && (c3 < c2)) {
            return true;
        }
        
        else {
            return false;
        }
    }
    
    else if (c2 < c1) {
        if ((c3 > c2) && (c3 < c1)) {
            return true;
        }
        
        else {
            return false;
        }
    }
    
    else {
        cout << "Error: inBetween function" << endl;
        return false;
    }
}

int main() {
    srand((int)time(0)); //sets the seed for rand, ensures rand will generate different numbers each time
    
    string name;
    int starting_money;
    
    cout << "What is your name? ";
    getline(cin, name);
    cout << "How much money would you like to start with? ";
    cin >> starting_money;
    
    Player myPlayer(name, starting_money);
    
    //the game keeps going if the player's money is greater than 0 and less than 10 times it's starting value
    while ((myPlayer.get_current_money() > 0) && (myPlayer.get_current_money() < 10 * myPlayer.get_starting_money())) {
        Card card1;
        Card card2;
        Card card3;
        int bet;
        
        cout << myPlayer.get_name() << ", you have $" << myPlayer.get_current_money() << "." << endl;
        
        cout << "You got a " + getCardName(card1) + " and a " + getCardName(card2) + "." << endl;
        
        cout << "How much do you want to bet the next card is in between? ";
        cin >> bet;
        
        //keeps asking for a new bet if the player tries to bet more than they have
        while (bet > myPlayer.get_current_money()) {
            cout << "You don't have that much money. Place a lower bet. ";
            cin >> bet;
        }
        
        cout << "You draw a " + getCardName(card3) + "." << endl;
        
        if (inBetween(card1, card2, card3)) {
            cout << "YES!! " + myPlayer.get_name() + " you win $" << bet << "!" << endl;
            myPlayer.change_money(bet);
        }
        
        else {
            cout << "TOO BAD " + myPlayer.get_name() + "!! You lose $" << bet << "." << endl;
            myPlayer.change_money(-bet);
        }
        
        cout << endl;
    }
    
    if (myPlayer.get_current_money() <= 0) {
        cout << "You lose. You have $0 left." << endl;
    }
    
    else {
        cout << "You win! You have $" << myPlayer.get_current_money() << "!" << endl;
    }
    
    system("pause");
    return 0;
}
