/*
 Jacob Fisher
 2/26/16
 Creates Fraction class and implements the ability to compare Fractions
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

class Fraction {
public:
    Fraction(); //constructor
    Fraction(int myNumerator, int myDenominator); //constructor
    int get_numerator() const;
    int get_denominator() const;
    double get_decimal() const; //returns the fraction in decimal form
    bool operator < (Fraction B) const;
private:
    int numerator;
    int denominator;
};

//Fraction default constructor
Fraction::Fraction() {
    numerator = (rand() % 201) - 100;
    denominator = (rand() % 100) + 1;
}

//Fraction regular constructor
Fraction::Fraction(int myNumerator, int myDenominator) {
    numerator = myNumerator;
    denominator = myDenominator;
}

int Fraction::get_numerator() const {
    return numerator;
}

int Fraction::get_denominator() const {
    return denominator;
}

double Fraction::get_decimal() const {
    return (double(numerator) / double(denominator));
}

bool Fraction::operator<(Fraction B) const {
    return (get_decimal() < B.get_decimal());
}

int main() {
    srand((int)time(0));
    
    vector<Fraction> V;
    Fraction greatest;
    
    for (int i = 0; i < 100; i++) {
        V.push_back(Fraction());
    }
    
    greatest = V[0]; //initially sets the greatest to be the first element
    
    //greatest is less than any element, that element becomes the new greatest
    for (int i = 1; i < 100; i++) {
        if (greatest < V[i]) {
            greatest = V[i];
        }
    }
    
    cout << fixed << setprecision(2);
    cout << "The largest fraction is " << greatest.get_decimal() << "." << endl;
    
    system("pause");
    return 0;
}
