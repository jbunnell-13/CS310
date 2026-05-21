/*
* Student Name: Jesse Bunnell
* File Name: Ch12Exercise03.cpp
* Date: 05/21/2026
*
* Program Description:
* This program asks the user for the number of candidates in an election,
* stores each candidate's last name and vote total in dynamic arrays,
* calculates the total number of votes and each candidate's percentage,
* and displays the winner of the election.
*/

// Include formatting tools for aligned columns and decimal precision
#include <iomanip>
// Include input and output tools for console interaction
#include <iostream>
// Include string support for candidate last names
#include <string>

// Use the standard namespace so std:: is not required everywhere
using namespace std;

int main() {
    // Store how many candidates the user wants to enter
    int candidateCount = 0;

    // Ask the user for the number of candidates in the election
    cout << "Enter the number of candidates: ";
    cin >> candidateCount;

    // Stop the program if the user enters an invalid amount
    if (candidateCount <= 0) {
        cout << "Number of candidates must be greater than 0." << endl;
        return 1;
    }

    // Create a dynamic array to store each candidate's last name
    string* candidateNames = new string[candidateCount];
    // Create a dynamic array to store the votes for each candidate
    int* votesReceived = new int[candidateCount];

    // Keep track of the total votes from all candidates
    int totalVotes = 0;
    // Keep track of which candidate currently has the most votes
    int winnerIndex = 0;

    // Repeat once for each candidate to gather names and vote totals
    for (int i = 0; i < candidateCount; i++) {
        // Ask for the candidate's last name and store it in the array
        cout << "Enter the last name of candidate " << (i + 1) << ": ";
        cin >> candidateNames[i];

        // Ask for the number of votes received and store it in the array
        cout << "Enter the votes received by " << candidateNames[i] << ": ";
        cin >> votesReceived[i];

        // Stop the program if a negative vote total is entered
        if (votesReceived[i] < 0) {
            cout << "Votes cannot be negative." << endl;
            delete[] candidateNames;
            delete[] votesReceived;
            return 1;
        }

        // Add this candidate's votes to the running total
        totalVotes += votesReceived[i];

        // If this candidate has more votes than the current leader,
        // update the winner index
        if (votesReceived[i] > votesReceived[winnerIndex]) {
            winnerIndex = i;
        }
    }

    // Print the heading row for the election results table
    cout << endl;
    cout << left << setw(15) << "Candidate"
         << right << setw(18) << "Votes Received"
         << setw(20) << "% of Total Votes" << endl;

    // Show vote percentages with exactly two decimal places
    cout << fixed << setprecision(2);

    // Repeat once for each candidate to show name, votes, and percentage
    for (int i = 0; i < candidateCount; i++) {
        // Start each percentage at zero in case no votes were entered
        double votePercentage = 0.0;

        // If the total votes are greater than zero, calculate the percentage
        if (totalVotes > 0) {
            votePercentage =
                static_cast<double>(votesReceived[i]) / totalVotes * 100.0;
        }

        // Display this candidate's results in the output table
        cout << left << setw(15) << candidateNames[i]
             << right << setw(18) << votesReceived[i]
             << setw(20) << votePercentage << endl;
    }

    // Show the total number of votes cast in the election
    cout << left << setw(15) << "Total" << right << setw(18) << totalVotes
         << endl;

    // Display the candidate with the highest number of votes
    cout << "The Winner of the Election is "
         << candidateNames[winnerIndex] << "." << endl;

    // Free the dynamic arrays now that the program is finished using them
    delete[] candidateNames;
    delete[] votesReceived;

    // End the program successfully
    return 0;
}
