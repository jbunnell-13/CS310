/*
* Student Name: Jesse Bunnell
* File Name: Ch07Exercise04.cpp
* Date: 04/24/2026
*/

// Include directives
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


// Declare function isVowel(ch : character) : boolean
bool isVowel(char ch)
{
    // Convert character to lowercase
    ch = tolower(ch);

    // Check if character is a vowel
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Declare function removeVowels(str : string) : string
string removeVowels(string str)
{
    // Loop through string and remove vowels
    for (int i = 0; i < str.length(); )
    {
        // Check if current character is a vowel
        if (isVowel(str.substr(i, 1)[0]))
        {
            // Remove current character
            str.erase(i, 1);
        }
        // If not a vowel move to next character
        else
        {
            i++;
        }
    }

    return str;
}

// Main function
int main()
{
    // Declare variables
    string str;

    // Get user input
    cout << "Enter a string: ";
    getline(cin, str);

    // Remove vowels from string
    str = removeVowels(str);

    // Output string
    cout << "String after removing vowels: " << str << endl;

    return 0;
}
