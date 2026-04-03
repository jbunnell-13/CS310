/*
* Student Name: Jesse Bunnell
* File Name: Week2Errors.cpp
* Date: 04/02/2026
*/


# include <iostream>

int main(){
    // Constants for prize levels
    const int FIVE_TICKETS {5};
    const int TEN_TICKETS {10};
    const int FIFTY_TICKETS {50};
    
    // Store the number of tickets the user has
    int tickets;

    // Prompt the user and get the number of tickets
    std::cout << "How many tickets do you wish to purchase [5, 10, 50]: ";
    std::cin >> tickets

    // Determine and display the prize based on the number of tickets
    if (tickets == FIVE_TICKETS){
        std::cout << "Not enough tickets - keep trying!";
    }
    
    // Second condition
    else if (tickets == TEN_TICKETS){
        std::cout << "You win a slinky! Congratulations!";
    }

    // Third condition
    else if (tickets == FIFTY_TICKETS)
        std::cout << "You win a vacuum cleaner! Congratulations!";
    }

    // The user chose a different number than they were prompted for
    else {
        std::cout << "Apparently you can't follow directions, you lose.";
    }
    return 0;
}