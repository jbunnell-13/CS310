/*
* Student Name: Jesse Bunnell
* File Name: Ch08Exercise07.cpp
* Date: 05/01/2026
*/



// #INCLUDE
#include <iomanip>
#include <iostream>
#include <string>

// Namespace
using namespace std;


// Main program
int main() {
    // Declare variables
    const int candidateCount = 5;
    string candidateNames[candidateCount];
    int votes[candidateCount];
    int totalVotes = 0;
    int winnerIndex = 0;

    // Ask for user input
    cout << "Enter the last name and votes received for five candidates.\n";

    // Loop to get candidate names and votes
    for (int i = 0; i < candidateCount; ++i) {
        cout << "\nCandidate " << (i + 1) << " last name: ";
        cin >> candidateNames[i];

        cout << "Votes received: ";
        cin >> votes[i];

        totalVotes += votes[i];

        if (votes[i] > votes[winnerIndex]) {
            winnerIndex = i;
        }
    }

    // Display election results
    cout << "\nElection Results\n";
    cout << left << setw(15) << "Candidate"
         << right << setw(12) << "Votes"
         << setw(15) << "Percent" << '\n';

    // Format output
    cout << fixed << setprecision(2);

    // Loop to display results
    for (int i = 0; i < candidateCount; ++i) {
        double percentOfVotes = 0.0;

        // Calculate percentage of votes
        if (totalVotes > 0) {
            percentOfVotes = static_cast<double>(votes[i]) / totalVotes * 100.0;
        }

        // Display results for each candidate
        cout << left << setw(15) << candidateNames[i]
             << right << setw(12) << votes[i]
             << setw(14) << percentOfVotes << "%" << '\n';
    }

    // Display total votes and winner
    cout << "\nTotal Votes: " << totalVotes << '\n';
    cout << "Winner of the election: " << candidateNames[winnerIndex] << '\n';

    return 0;
}