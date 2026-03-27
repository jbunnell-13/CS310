/*
* Student Name: Jesse Bunnell
* File Name: Ch03Exercise07.cpp
* Date: 03/27/2026
*/



# include <iostream>
# include <iomanip>
# include <locale>

int main()
{
    // Declare variables to store netBalance, payment, D1, D2 and interest rate per month
    double netBalance;
    double payment;
    double D1;
    double D2;
    double interest;
    
    // Ask the user to input the net balance
    std::cout << "Enter the net balance: $";
    std::cin >> netBalance;

    // Ask the user to input the payment
    std::cout << "Enter the payment: $";
    std::cin >> payment;

    // Ask the user to input the number of days in the billing cycle
    std::cout << "Enter the number of days in the billing cycle: ";
    std::cin >> D1;
    if (D1 == 0) {
        std::cout << "Error: Number of days in billing cycle cannot be 0." << std::endl;
        return 1;
    }
    
    // Ask the user to input number of days payment is made before the end of the billing cycle
    std::cout << "Enter the number of days payment is made before the end of the billing cycle: ";
    std::cin >> D2;

    // Figure the averageDailyBalance
    double averageDailyBalance = (netBalance * D1 - payment * D2) / D1;

    // Calculate the interest rate per month
    interest = averageDailyBalance * 0.0152;

    // format the output to two decimal places with the thousands separator
    std::cout << std::fixed << std::setprecision(2); // set the decimal to two places.
    // std::locale loc(""); // for the thousands separator 
    // std::cout.imbue(loc); // for the thousands separator

    // Display the result to the user
    std::cout << "The interest for the month is: $" << interest << std::endl;

    return 0;
}