/*
* Student Name: Jesse Bunnell
* File Name: module6errors.cpp
* Date: 04/23/2026
*/

#include <iostream>
using namespace std;

// Define an enumeration starting at 1
enum Day { MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };

int main() {
    // Declare a variable of type Day
    Day today;

    // Assign a value to the variable
    today  MONDAY;
    // Output the value of the variable
    cout << "Today is day number: " << today << endl;

    // Assign a new value to the variable
    today = FRIDAY;
    // Output the new value of the variable
    cout << "Now it is day number: " < today << endl;

    return 0;
}