/*
 Jacob Fisher
 1/15/16
 This program reads the time of travel in seconds and the speed of travel in miles per hour.
 It outputs the time of travel in years, days, hours, minutes, and seconds, and the distance traveled in miles.
 */

#include <iostream>
using namespace std;

int main() {
    
    int time_seconds; //the time of travel, in seconds
    double time_hours; // the time of travel, in hours
    int timeLeft; //the time value that will be modified in our calculations
    int speed; //the speed of travel, in miles per hour
    int years, days, hours, minutes, seconds; //numer of each of these traveled
    double distance; //total distance traveled
    
    //constants
    const int seconds_in_minute = 60;
    const int seconds_in_hour = 3600;
    const int seconds_in_day = 86400;
    const int seconds_in_year = 31536000;
    
    //prompts for and reads in time and speed values from the user
    cout << "Please give me the time of travel in seconds. ";
    cin >> time_seconds;
    cout << "Please give me your speed in miles per hour. ";
    cin >> speed;
    
    //this sets the timeLeft variable equal to the amount of time traveled in seconds, finds how many years were traveled, updates the total time traveled remaining to exclude this, and does this for days, hours, minutes, and seconds
    timeLeft = time_seconds;
    years = timeLeft / seconds_in_year;
    timeLeft = timeLeft % seconds_in_year;
    days = timeLeft / seconds_in_day;
    timeLeft = timeLeft % seconds_in_day;
    hours = timeLeft / seconds_in_hour;
    timeLeft = timeLeft % seconds_in_hour;
    minutes = timeLeft / seconds_in_minute;
    timeLeft = timeLeft % seconds_in_minute;
    seconds = timeLeft;
    
    time_hours = (double)time_seconds / seconds_in_hour; //converts time to hours
    distance = speed * time_hours; //finds distance based on the formula "distance = rate * time"
    
    //outputs final values
    cout << "You have been traveling for: " << years << " years " << days << " days " << hours << " hours " << minutes << " minutes " << seconds << " seconds." << endl;
    cout << "Your distance traveled is: " << distance << " miles." << endl;
    
    system("pause");
    return 0;
}*/