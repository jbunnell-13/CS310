/*
* Student Name: Jesse Bunnell
* File Name: Ch10Exercise21.cpp
* Date: 5/8/2026
*/


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// bankAccount class
class bankAccount {
// Private member variables    
private:
    string accountHolderName;
    int accountNumber;
    string accountType;
    double balance;
    double interestRate;
    static int nextAccountNumber;

// Public member functions
public:
    bankAccount() {
        accountHolderName = "Not Assigned";
        accountNumber = nextAccountNumber++;
        accountType = "checking";
        balance = 0.0;
        interestRate = 0.0;
    }
    // Set account information
    void setAccountInfo(const string& name, const string& type,
        double startingBalance, double rate) {
        accountHolderName = name;
        accountType = type;
        balance = startingBalance;
        interestRate = rate;
    }
    // Deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    // Withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
        else {
            cout << "Withdrawal denied for account " << accountNumber
                 << ". Insufficient funds or invalid amount." << endl;
        }
    }
    // Apply interest to the account balance
    void applyInterest() {
        balance += balance * interestRate;
    }
    // Print account information
    void printAccountInfo() const {
        cout << fixed << setprecision(2);
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Interest Rate: " << interestRate << endl;
        cout << endl;
    }
};
// Initialize static member variable
int bankAccount::nextAccountNumber = 1000;
// Main function to demonstrate the bankAccount class
int main() {
    // Create an array of bankAccount objects
    const int MAX_CUSTOMERS = 10;
    bankAccount customers[MAX_CUSTOMERS];

    // Set account information for three customers
    customers[0].setAccountInfo("Billy Bob", "checking", 1250.50, 0.01);
    customers[1].setAccountInfo("John Doe", "saving", 2400.00, 0.03);
    customers[2].setAccountInfo("Jane Doe", "checking", 980.75, 0.01);

    customers[0].deposit(200.00);
    customers[1].applyInterest();
    customers[2].withdraw(150.75);

    // Print account information
    cout << "Bank Account Summary" << endl;
    cout << "--------------------" << endl << endl;

    // Print account information for each customer
    for (int i = 0; i < 3; i++) {
        customers[i].printAccountInfo();
    }

    return 0;
}
