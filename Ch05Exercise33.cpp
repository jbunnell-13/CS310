/*
* Student Name: Jesse Bunnell
* File Name: Ch05Exercise33.cpp
* Date: 04/10/2026
*/


#include <iostream>
using namespace std;

int main() {

    // Label the variables
    int a, b, t;

    // Prompt the user for time for the first dish and assign to variable a
    cout << "Enter time for first dish: ";
    cin >> a;


    // Create a while loop to allow user continue to enter time for other dishes
    while (a > 0) {
        // Prompt the user for the increase in time per dish and assign to variable b
        cout << "Enter time for next dish (or 0 to stop): ";
        cin >> b;
        // if statement to break out of the loop
        if (b == 0) {
            break;
        }
        // Update variable a to be the time for the next dish
        a += b;
    }

    // Enter total available time and assign to variable t
    cout << "Enter total available time: ";
    cin >> t;

    
    // if statement to determine if the total time is sufficient
    if (a <= t) {
        cout << "Bianca can prepare all the dishes. " << t - a << " time left over." << endl;
    }
    // else statement to determine how much more time is needed
    else {
        cout << "Bianca cannot prepare all the dishes. " << "You would need " << a - t << " more minutes." << endl;
    }

    return 0;

}