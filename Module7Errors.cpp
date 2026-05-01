#include <iostream>
using namespace std;

int main() {

    // 2D array (3x3)
    int numbers[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

   

    // Loop through the 2D array
    for (int i = 0; i <= 3; i++) {   
        for (int j = 0; j < 3; j++) {
            cout << numbers[i][j] << " ";
        }
        cout << endl;
    }

    // Print the 2D array
    cout << "Done printing array" << endl;
    cout << number[0][0];  // 

    return 0;
}