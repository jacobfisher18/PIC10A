/*
 Jacob Fisher
 1/22/16
 This program reads in quantities of two objects and outputs their ratios in a neat column format.
 */

#include <iostream>
#include <string>
#include <iomanip> // this is neccesary for output formatting

using namespace std;

int main() {
    
    //variablels involving the first quantity inputted
    int first_quantity;
    string first_object_plural;
    string first_object_singular;
    
    //variablels involving the second quantity inputted
    int second_quantity;
    string second_object_plural;
    string second_object_singular;
    
    //variables involving the first ratio
    double ratio1;
    string ratioString1;
    
    //variables involving the second ratio
    double ratio2;
    string ratioString2;
    
    //the width (in number of characters) of the first column
    int lineWidth;
    
    cout << "How many in the first category? ";
    cin >> first_quantity;
    cin >> first_object_plural;
    cout << "How many in the second category? ";
    cin >> second_quantity;
    cin >> second_object_plural;
    cout << "\n";
    
    //sets the singular version of the objects by taking a substring that includes everything but the final characer of the string
    first_object_singular = first_object_plural.substr(0, first_object_plural.length()-1);
    second_object_singular = second_object_plural.substr(0, second_object_plural.length()-1);
    
    //sets the strings that label the two ratios
    ratioString1 = first_object_singular + "-to-" + second_object_singular + " ratio";
    ratioString2 = second_object_singular + "-to-" + first_object_singular + " ratio";
    
    lineWidth = int(ratioString1.length());
    
    //calculates both ratios
    ratio1 = double(first_quantity) / double(second_quantity);
    ratio2 = double(second_quantity) / double(first_quantity);
    
    //formatting
    cout << fixed;
    cout << setprecision(2);
    
    //outputs everything in neat columns
    cout << setw(lineWidth) << first_object_plural << setw(10) << first_quantity << endl;
    cout << setw(lineWidth) << second_object_plural << setw(10) << second_quantity << endl;
    cout << ratioString1 << setw(10) << ratio1 << endl;
    cout << ratioString2 << setw(10) << ratio2 << endl;
    
    system("pause");
    return 0;
}