#include <iostream>
using namespace std;

int main() {

    int num1, num2;
    double result;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    result = num1 / num2;

    cout << "The result of dividing " << num1 << " by " << num2
        << " is: " << result << endl;

    return 0;
}