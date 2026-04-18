/*
* Student Name: Jesse Bunnell
* File Name: Ch06Exercise14.cpp
* Date: 04/17/2026
*/


#include <iostream>
using namespace std;

// Function declaration
double calculateBill(double rate, int minutes, int lowIncome);

int main() {

    // Variables to hold user input
    double hourlyRate;
    int consultingTime;
    int lowIncome;

    // Get user input for hourly rate
    cout << "Enter hourly rate: ";
    cin >> hourlyRate;


    // Get user input for consulting time
    cout << "Enter total consulting time (in minutes): ";
    cin >> consultingTime;


    // Get user input for low income status
    cout << "Enter 1 if low income, 0 otherwise: ";
    cin >> lowIncome;


    // Calculate the billing amount
    double bill = calculateBill(hourlyRate, consultingTime, lowIncome);

    // Display the billing amount
    cout << "Billing amount: $" << bill << endl;

    return 0;
}

// Function calculateBill(double rate, int minutes, int lowIncome)
double calculateBill(double rate, int minutes, int lowIncome) {

    // Declare a variable to hold the billing amount
    double bill = 0.0;

    // if else to determine the billing amount based on low income status and consulting time
    if (lowIncome == 1) {  
        if (minutes > 30) {
            bill = rate * 0.40 * ((minutes - 30) / 60.0);
        }
    }
    else {  
        if (minutes > 20) {
            bill = rate * 0.70 * ((minutes - 20) / 60.0);
        }
    }

    return bill;
}