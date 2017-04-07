/*
 Jacob Fisher
 3/3/16
 Implements a phonebook application
 Demonstrates use separate compilation, classes, and vector manipulation
 */

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>
#include "phonebook.h"
using namespace std;

Person::Person() {
    name = "Person, Default";
    phone = 1234567;
}

Person::Person(string new_name, int new_phone) {
    name = new_name;
    phone = new_phone;
}

string Person::get_name() const {
    return name;
}

int Person::get_phone() const {
    return phone;
}

bool Person::operator < (Person p) const {
    return name < p.name;
}

void Person::print() const {
    cout << name << ": " << phone;
}

void add_people(vector<Person> &phone_book) {
    string name;
    int phone;
    
    cout << "Enter a name or Q to quit" << endl;
    getline(cin, name);
    
    while (name != "Q") {
        cout << "Enter a phone number" << endl;
        cin >> phone;
        string clear; getline(cin, clear); //clears a weird issue with getline after cin
        
        phone_book.push_back(Person(name, phone));
        
        cout << "Enter a name or Q to quit" << endl;
        getline(cin, name);
    }
}

void erase(vector<Person> &phone_book, string name) {
    for (int i = 0; i < phone_book.size(); i++) {
        if (phone_book[i].get_name() == name) {
            for (int n = i; n < phone_book.size() - 1; n++) {
                phone_book[n] = phone_book[n+1];
            }
            phone_book.pop_back();
        }
    }
}

void sort(vector<Person> &phone_book) {
    sort(phone_book.begin(), phone_book.end());
}

void shuffle(vector<Person> &phone_book) {
    srand((int)time(0));
    
    int i1, i2;
    
    for (int i = 0; i < 100; i++) {
        i1 = rand() % phone_book.size();
        i2 = rand() % phone_book.size();
        
        swap(phone_book[i1], phone_book[i2]);
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void reverse(vector<Person> &phone_book) {
    for (int i = 0; i < phone_book.size() / 2; i++) {
        swap(phone_book[i], phone_book[phone_book.size() - 1 - i]);
    }
}

void print(vector<Person> &phone_book) {
    for (int i = 0; i < phone_book.size(); i++) {
        phone_book[i].print();
        cout <<"\n";
    }
}

int lookup(const vector<Person> &phone_book, string name) {
    for (int i = 0; i < phone_book.size(); i++) {
        if (phone_book[i].get_name() == name) {
            return phone_book[i].get_phone();
        }
    }
    
    return -1;
}