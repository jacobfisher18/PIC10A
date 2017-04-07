/*
 Jacob Fisher
 3/11/16
 PIC 10A Extra Credit Homework Assignment
 Objective: Given a list of ints, find the maximal sublist using an O(N) solution
 Implements a modified version of Kadane's algorithm, which computes the sum of the maximal subarray
*/

#include <iostream>
#include <list>

using namespace std;

list<int> getMaxSublist(list<int> l) {
    
    list<int> currMaxList;
    list<int> maxListSoFar;
    
    int currMaxSum = -1000000;
    int maxSumSoFar = -1000000;
    
    list<int>::iterator i;
    
    for (i = l.begin(); i != l.end(); ++i) {
        int value = *i;;
        
        if (currMaxSum < 0) {
            currMaxSum = value;
            currMaxList.clear();
            currMaxList.push_back(value);
        }
        
        else {
            currMaxSum += value;
            currMaxList.push_back(value);
        }
        
        if (currMaxSum > maxSumSoFar) {
            maxSumSoFar = currMaxSum;
            maxListSoFar = currMaxList;
        }
    }
    
    return maxListSoFar;
}

int main() {
 
    list<int> initialList;
    
    cout << "Enter a value to add to the list, or any letter to quit. ";
    
    int inputValue;
    
    while (cin >> inputValue) {
        initialList.push_back(inputValue);
        cout << "Enter a value to add to the list, or any letter to quit. ";
    }
 
    list<int> maxSublist = getMaxSublist(initialList);
    
    cout << endl << "The whole list is: " << endl;
    
    list<int>::iterator i;
    
    for (i = initialList.begin(); i != initialList.end(); ++i) {
        cout << *i << " ";
    }
    
    cout << endl << endl << "The maximal sublist is: " << endl;
    
    for (i = maxSublist.begin(); i != maxSublist.end(); ++i) {
        cout << *i << " ";
    }
    
    cout << endl;
    
    system("pause");
    return 0;
}