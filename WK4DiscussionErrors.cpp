/*
* Student Name: Jesse Bunnell
* File Name: WK4DiscussionErrors.cpp
* Date: 04/08/2026
*/



#include <iostream>

int main(){
    // Delcare variables for input and running total
    double runningTotal = 0;
    double numbar;

    // Print the heading and prompt
    std::cout << "+---------------------------------+" << std::endl;
    std::cout << "|     Sum the entered numbers     |" << std::endl;
    std::cout << "+---------------------------------+" << std::endl;

    while (true){
        std::cout << "Enter a number (0 to quit): ";
        // Get a double from keyboard assign double to variable
        std::cin >> number;
        // If the user types in the sentinel value 0 break the loop
        if (number == 0){
            break;
        
        // Accumulate running total
        runningTotal += number;
    }
    // Display the running total
    std::cout << "The total is: " << runningTotal << std::endl;
    return 0;    
}