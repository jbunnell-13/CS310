/*
* Student Name: Jesse Bunnell
* File Name: Ch10Exercise21.cpp
* Date: 05/14/2026
*
* Program Description:
* This program defines a base bankAccount class and two derived classes:
* checkingAccount and savingsAccount. It demonstrates deposits, withdrawals,
* posting interest, service charges, and printing account information.
*/

// Include formatting tools for money-style output
#include <iomanip>
// Include input and output tools for console printing
#include <iostream>

// Use the standard namespace so std:: is not required everywhere
using namespace std;

// Base class for a general bank account
class bankAccount
{
protected:
    // Store the account number for the customer
    int accountNumber;
    // Store the current amount of money in the account
    double balance;

public:
    // Default constructor: start with a blank account number and zero balance
    bankAccount();
    // Constructor: start with a provided account number and balance
    bankAccount(int accountNum, double accountBalance);

    // Change the account number
    void setAccountNumber(int accountNum);
    // Return the account number
    int getAccountNumber() const;
    // Return the current balance
    double getBalance() const;

    // Add money to the account
    void deposit(double amount);
    // Remove money from the account if enough funds exist
    virtual bool withdraw(double amount);
    // Display the account information
    virtual void printAccountInfo() const;

    // Virtual destructor for safe inheritance cleanup
    virtual ~bankAccount() = default;
};

// Set a default account number and zero balance
bankAccount::bankAccount() : accountNumber(0), balance(0.0)
{
}

// Store the given account number and use the balance if it is not negative
bankAccount::bankAccount(int accountNum, double accountBalance)
    : accountNumber(accountNum), balance(accountBalance >= 0.0 ? accountBalance : 0.0)
{
}

// Save a new account number in the object
void bankAccount::setAccountNumber(int accountNum)
{
    accountNumber = accountNum;
}

// Give back the stored account number
int bankAccount::getAccountNumber() const
{
    return accountNumber;
}

// Give back the current balance
double bankAccount::getBalance() const
{
    return balance;
}

// If the deposit amount is valid, add it to the balance
void bankAccount::deposit(double amount)
{
    if (amount > 0.0)
    {
        // Increase the balance by the deposit amount
        balance += amount;
    }
}

// If the withdrawal amount is valid and affordable, subtract it
bool bankAccount::withdraw(double amount)
{
    if (amount > 0.0 && amount <= balance)
    {
        // Reduce the balance by the withdrawal amount
        balance -= amount;
        // Report that the withdrawal worked
        return true;
    }

    // Report that the withdrawal failed
    return false;
}

// Print the base account details in money format
void bankAccount::printAccountInfo() const
{
    // Show decimal values as fixed-point with two digits after the decimal
    cout << fixed << setprecision(2);
    // Print the account number label and value
    cout << "Account Number: " << accountNumber << endl;
    // Print the balance label and value
    cout << "Balance: $" << balance << endl;
}

// Derived class for a checking account
class checkingAccount : public bankAccount
{
private:
    // Store the interest rate for the checking account
    double interestRate;
    // Store the minimum balance requirement
    double minimumBalance;
    // Store the service fee charged when balance rules are broken
    double serviceCharges;

public:
    // Default constructor for checking account values
    checkingAccount();
    // Constructor with all checking-specific starting values
    checkingAccount(int accountNum, double accountBalance, double rate,
        double minBalance, double charges);

    // Change the interest rate
    void setInterestRate(double rate);
    // Return the interest rate
    double getInterestRate() const;

    // Change the minimum balance requirement
    void setMinimumBalance(double minBalance);
    // Return the minimum balance requirement
    double getMinimumBalance() const;

    // Change the service charge amount
    void setServiceCharges(double charges);
    // Return the service charge amount
    double getServiceCharges() const;

    // Add earned interest to the account balance
    void postInterest();
    // Check whether the account is under the minimum balance
    bool isBelowMinimumBalance() const;
    // Treat a check as a withdrawal from the account
    bool writeCheck(double amount);
    // Override base withdrawal rules with checking account fee logic
    bool withdraw(double amount) override;
    // Print all checking account details
    void printAccountInfo() const override;
};

// Start all checking account values at zero
checkingAccount::checkingAccount()
    : bankAccount(), interestRate(0.0), minimumBalance(0.0), serviceCharges(0.0)
{
}

// Store the given checking account data and reject negative values
checkingAccount::checkingAccount(int accountNum, double accountBalance, double rate,
    double minBalance, double charges)
    : bankAccount(accountNum, accountBalance),
    interestRate(rate >= 0.0 ? rate : 0.0),
    minimumBalance(minBalance >= 0.0 ? minBalance : 0.0),
    serviceCharges(charges >= 0.0 ? charges : 0.0)
{
}

// Update the interest rate if the value is valid
void checkingAccount::setInterestRate(double rate)
{
    if (rate >= 0.0)
    {
        interestRate = rate;
    }
}

double checkingAccount::getInterestRate() const
{
    return interestRate;
}

// Update the minimum balance if the value is valid
void checkingAccount::setMinimumBalance(double minBalance)
{
    if (minBalance >= 0.0)
    {
        minimumBalance = minBalance;
    }
}

double checkingAccount::getMinimumBalance() const
{
    return minimumBalance;
}

// Update the service charge if the value is valid
void checkingAccount::setServiceCharges(double charges)
{
    if (charges >= 0.0)
    {
        serviceCharges = charges;
    }
}

double checkingAccount::getServiceCharges() const
{
    return serviceCharges;
}

// Increase the balance by the amount of interest earned
void checkingAccount::postInterest()
{
    balance += balance * interestRate;
}

// Return true when the balance is lower than the required minimum
bool checkingAccount::isBelowMinimumBalance() const
{
    return balance < minimumBalance;
}

// Process the check by using the same rules as a withdrawal
bool checkingAccount::writeCheck(double amount)
{
    return withdraw(amount);
}

// Withdraw money and apply a fee if the remaining balance drops too low
bool checkingAccount::withdraw(double amount)
{
    // Reject zero or negative withdrawal requests
    if (amount <= 0.0)
    {
        return false;
    }

    // Start with the requested withdrawal amount
    double totalAmount = amount;
    // If the withdrawal would place the account below minimum, add a fee
    if (balance - amount < minimumBalance)
    {
        totalAmount += serviceCharges;
    }

    // If enough money exists for the withdrawal plus fee, complete it
    if (totalAmount <= balance)
    {
        // Subtract the total amount from the balance
        balance -= totalAmount;
        // Report success
        return true;
    }

    // Otherwise report failure
    return false;
}

// Print the full set of checking account details
void checkingAccount::printAccountInfo() const
{
    cout << fixed << setprecision(2);
    cout << "Checking Account Information" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
    cout << "Minimum Balance: $" << minimumBalance << endl;
    cout << "Service Charges: $" << serviceCharges << endl;
}

// Derived class for a savings account
class savingsAccount : public bankAccount
{
private:
    // Store the interest rate for the savings account
    double interestRate;

public:
    // Default constructor for a savings account
    savingsAccount();
    // Constructor with starting savings account values
    savingsAccount(int accountNum, double accountBalance, double rate);

    // Change the savings interest rate
    void setInterestRate(double rate);
    // Return the savings interest rate
    double getInterestRate() const;

    // Add earned interest to the savings balance
    void postInterest();
    // Override the base withdrawal function for savings behavior
    bool withdraw(double amount) override;
    // Print all savings account details
    void printAccountInfo() const override;
};

// Start the savings account with default values
savingsAccount::savingsAccount() : bankAccount(), interestRate(0.0)
{
}

// Store the provided savings values and reject a negative rate
savingsAccount::savingsAccount(int accountNum, double accountBalance, double rate)
    : bankAccount(accountNum, accountBalance), interestRate(rate >= 0.0 ? rate : 0.0)
{
}

// Update the interest rate if it is valid
void savingsAccount::setInterestRate(double rate)
{
    if (rate >= 0.0)
    {
        interestRate = rate;
    }
}

double savingsAccount::getInterestRate() const
{
    return interestRate;
}

// Increase the savings balance by its earned interest
void savingsAccount::postInterest()
{
    balance += balance * interestRate;
}

// Use the base class withdrawal rules for a savings account
bool savingsAccount::withdraw(double amount)
{
    return bankAccount::withdraw(amount);
}

// Print the full set of savings account details
void savingsAccount::printAccountInfo() const
{
    cout << fixed << setprecision(2);
    cout << "Savings Account Information" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
}

// Test the bank account classes
int main()
{
    // Format all decimal output to look like money
    cout << fixed << setprecision(2);

    // Create one checking account with sample starting values
    checkingAccount myChecking(1001, 500.00, 0.03, 300.00, 25.00);
    // Create one savings account with sample starting values
    savingsAccount mySavings(2001, 1000.00, 0.04);

    // Show the original account information before transactions
    cout << "Initial account information:" << endl << endl;
    myChecking.printAccountInfo();
    cout << endl;
    mySavings.printAccountInfo();
    cout << endl << endl;

    // Add money to both accounts
    cout << "Depositing $150.00 into checking and $200.00 into savings..." << endl;
    myChecking.deposit(150.00);
    mySavings.deposit(200.00);

    // Attempt to write a check from the checking account
    cout << "Writing a check for $375.00 from checking..." << endl;
    if (!myChecking.writeCheck(375.00))
    {
        // Let the user know if the check could not be processed
        cout << "Check could not be processed." << endl;
    }

    // Attempt to withdraw money from the savings account
    cout << "Withdrawing $400.00 from savings..." << endl;
    if (!mySavings.withdraw(400.00))
    {
        // Let the user know if the withdrawal failed
        cout << "Savings withdrawal could not be processed." << endl;
    }

    // Apply interest to both accounts after the transactions
    cout << "Posting interest to both accounts..." << endl;
    myChecking.postInterest();
    mySavings.postInterest();

    // Show the account information after all activity is complete
    cout << endl << "Updated account information:" << endl << endl;
    myChecking.printAccountInfo();
    // Report whether the checking balance is now below its minimum
    cout << "Below minimum balance: "
        << (myChecking.isBelowMinimumBalance() ? "Yes" : "No") << endl;
    cout << endl;
    mySavings.printAccountInfo();

    // End the program successfully
    return 0;
}