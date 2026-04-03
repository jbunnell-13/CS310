/*
* Student Name: Jesse Bunnell
* File Name: Ch04Exercise16.cpp
* Date: 04/03/2026
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Constants for royalty options
    const double Option_1 = 25000.0;    

    const double Option_2 = 0.125;

    const double Option_3_Rate_1 = 0.10;
    const double Option_3_Rate_2 = 0.14;
    const int Option_3_Copies = 4000;

    // Variables
    double netPrice;
    int copiesSold;
    double option_2Royalty;
    double option_3Royalty;

    // Get user input for net price and copies sold
    // Set in a while loop to ensure valid input for net price greater than 0
    while (true) {
    cout << "\n\nEnter the net price of each copy: $";
    cin >> netPrice;

    if (netPrice > 0) {
        break; 
    } else {
        cout << "Invalid input.  Net price must be greater than 0.\n";
    }
}

    // Get user input for estimated copies sold
    // Set in a while loop to ensure valid input for copies sold greater than 0
    while (true) {
    cout << "Enter the estimated number of copies sold: ";
    cin >> copiesSold;

    if (copiesSold > 0) {
        break; 
    } else {
        cout << "Invalid input. Copies sold must be greater than 0.\n";
    }
}

    // Option 2 calculation
    option_2Royalty = Option_2 * netPrice * copiesSold;

    // Option 3 calculation
    // If the number of copies is less than or equal to Option_3_Copies
    if (copiesSold <= Option_3_Copies) {
        option_3Royalty = Option_3_Rate_1 * netPrice * copiesSold;
    } 
    // Else use Rate 1 for the first 4000 copies and Rate 2 for the remaining copies
    else {
        option_3Royalty = (Option_3_Rate_1 * netPrice * Option_3_Copies) +
                         (Option_3_Rate_2 * netPrice * (copiesSold - Option_3_Copies));
    }

    // Set output to two decimal places
    cout << fixed << setprecision(2);

    // Display payment for each option
    cout << "\nPayment for each option:\n";
    cout << "Option 1: $" << Option_1 << endl;
    cout << "Option 2: $" << option_2Royalty << endl;
    cout << "Option 3: $" << option_3Royalty << endl;

    // Determine and display the best option
    cout << "\nBest option: ";

    // If Option 1 is the best option (<= 10005 @ $19.99)
    if (Option_1 >= option_2Royalty && Option_1 >= option_3Royalty) {
        cout << "Option 1";
    } 
    // Else if Option 2 is the best option (> 10006 <= 10666 @ $19.99)
    else if (option_2Royalty >= Option_1 && option_2Royalty >= option_3Royalty) {
        cout << "Option 2";
    } 
    // Else Option 3 is the best option (> 10667 @ $19.99)
    else {
        cout << "Option 3";
    }

    return 0;
}