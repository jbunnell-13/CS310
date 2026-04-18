#include <iostream>

int square(int x);

int main() {
    int num = 6;

    int result = square(num);

    std::cout << "Result: " << result << std::endl;

    return 0;
}

int square(int x) {
    return x * x;
}