/*
 * file: module10_debug.cpp
 * author: Hugo Ramirez
 * Date: 5/21/2026
 */
#include <iostream>
using namespace std;

int main() {
    int number = 42;
    int* ptr = &number;

    cout << "Value: " << *ptr << endl;

    int secondNumber = 100;
    int* uninitPtr = &secondNumber;
    cout << "Initialized pointer value: " << *uninitPtr << endl;

    return 0;
}
