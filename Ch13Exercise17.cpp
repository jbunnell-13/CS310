/*
* Student Name: Jesse Bunnell
* File Name: Ch13Exercise17.cpp
* Date: 05/21/2026
*
*   PSEUDOCODE
*   1. Create a random number engine and a distribution from 10 to 100.
*   2. Generate 25 real numbers.
*   3. For each number, use try/catch to test a condition.
*   4. If the condition is met, throw and catch an exception.
*   5. Print all generated numbers and any exception messages.
*/

#include <iomanip>
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

using namespace std;

double generateRandomReal(mt19937& engine, uniform_real_distribution<double>& dist)
{
    return dist(engine);
}

void checkPreferredRange(double value)
{
    // Demonstrate exception handling when a generated value lands
    // in a smaller "restricted" band inside the valid 10-100 range.
    if (value >= 45.0 && value <= 55.0)
    {
        throw runtime_error("Value landed in the restricted range [45.0, 55.0].");
    }
}

int main()
{
    const int TOTAL_NUMBERS = 25;
    random_device rd;
    mt19937 engine(rd());
    uniform_real_distribution<double> dist(10.0, 100.0);
    vector<double> numbers;

    cout << fixed << setprecision(2);
    cout << "Generating 25 real numbers between 10.00 and 100.00\n\n";

    for (int i = 0; i < TOTAL_NUMBERS; ++i)
    {
        double value = generateRandomReal(engine, dist);
        numbers.push_back(value);

        try
        {
            checkPreferredRange(value);
            cout << "Number " << (i + 1) << ": " << value << '\n';
        }
        catch (const runtime_error& ex)
        {
            cout << "Number " << (i + 1) << ": " << value
                 << " -> Exception caught: " << ex.what() << '\n';
        }
    }

    cout << "\nAll generated values:\n";
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        cout << setw(8) << numbers[i];

        if ((i + 1) % 5 == 0)
        {
            cout << '\n';
        }
    }

    if (numbers.size() % 5 != 0)
    {
        cout << '\n';
    }

    return 0;
}
