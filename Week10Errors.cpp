/*
* Student Name: Jesse Bunnell
* File Name: Week10Errors.cpp
* Date: 05/21/2026
*
* Pseudocode:
*    1. Create an integer variable and store a number in it.
*    2. Create a pointer that holds the address of that integer.
*    3. Display the value stored at the pointer's address.
*    4. Display the memory address stored in the pointer.
*    5. Try to change the value through the pointer.
*    6. End the program.
*/



#include <iostream>
using namespace std;

int main() {

    int value = 10;
    int* ptr = &value;

    cout << "Value: " << *ptr << endl
    cout << "Pointer address: " << ptr << endl;

    *ptr = "twenty";

    return 0
}
