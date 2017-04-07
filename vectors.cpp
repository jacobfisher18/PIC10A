/*
 Jacob Fisher
 2/26/16
 Demonstrates use of vectors
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//function that returns true if a given vector contains a given integer at least once
bool vectorContains(vector<int> V, int number) {
    for (int i=0; i < V.size(); i++) {
        if (V[i] == number) {
            return true;
        }
    }
    
    return false;
}

void printVector(vector<int> V) {
    for (int i=0; i < V.size(); i++) {
        cout << V[i] << " ";
    }
}

int main() {
    srand((int)time(0));
    
    vector<int> V1(10);
    vector<int> V2(10);
    vector<int> common;
    vector<int> V1Exclusive;
    vector<int> V2Exclusive;
    vector<int> V3;
    
    //fill V1 with random ints
    for (int i=0; i < V1.size(); i++) {
        V1[i] = (rand() % 21) - 10; //random number between -10 and 10
    }
    
    //fill V2 with random ints
    for (int i=0; i < V2.size(); i++) {
        V2[i] = (rand() % 21) - 10; //random number between -10 and 10
    }
    
    cout << "Vector V1 contents: ";
    printVector(V1);
    
    cout << endl << "Vector V2 contents: ";
    printVector(V2);
    
    //for all the elements in V1, if it is in V2 and not already in the common vector, add to the common vector
    for (int i=0; i < V1.size(); i++) {
        if (vectorContains(V2, V1[i]) && !vectorContains(common, V1[i])) {
            common.push_back(V1[i]);
        }
    }
    
    cout << endl << "Elements that are common to both vectors: ";
    printVector(common);
    
    //for all elements in V1, if they are not in V2, add to V1Exclusive
    for (int i=0; i < V1.size(); i++) {
        if (!vectorContains(V2, V1[i])) {
            V1Exclusive.push_back(V1[i]);
        }
    }
    
    //for all elements in V2, if they are not in V1, add to V2Exclusive
    for (int i=0; i < V2.size(); i++) {
        if (!vectorContains(V1, V2[i])) {
            V2Exclusive.push_back(V2[i]);
        }
    }
    
    cout << endl << "Elements that are in V1, but not V2: ";
    printVector(V1Exclusive);
    
    cout << endl << "Elements that are in V2, but not V1: ";
    printVector(V2Exclusive);
    
    //add all elements of V1 to V3 unless they are already in V3
    for (int i=0; i < V1.size(); i++) {
        if (!vectorContains(V3, V1[i])) {
            V3.push_back(V1[i]);
        }
    }
    
    //add all elements of V2 to V3 unless they are already in V3
    for (int i=0; i < V2.size(); i++) {
        if (!vectorContains(V3, V2[i])) {
            V3.push_back(V2[i]);
        }
    }
    
    cout << endl << "Unique elements of V1 and V2: ";
    printVector(V3);
    
    cout << endl;
    
    system("pause");
    return 0;
}