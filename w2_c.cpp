//
// Created by Shubham Bakshi on 08/04/2018.
//

#include <iostream>

int gcd_naive(int a, int b) {
    int best = 1;
    for (int i = 2; i < a+b; i++){
        if (a == 1 || b == 1){
            return 1;
        }

        if (a == 0 || b == 0){
            return a+b;
        }

        if ((a % i) == 0 && (b % i) == 0) {
            best = i;
        }
    }
    return best;
}

int gcd_fast(int a, int b) {
//    a = a % b + b*q;
//    std::cout << "gcd(" << a << ", " << b << ")\n";
    if (a == 1 || b == 1){
        return 1;
    }

    if (a == 0 || b == 0){
        return a+b;
    }

    return gcd_fast(b, a%b);
}

void test() {
    int test_cases = 1000;

    for (int i = 0; i < test_cases; i++){
        int input_a = rand() % 100 + 1;
        int input_b = rand() % 100 + 1;

        int f = gcd_fast(input_a, input_b);
        int n = gcd_naive(input_a, input_b);

        std::cout << input_a << " " << input_b << " Naive: " << n << ", Fast: " << f << std::endl;

        if (f != n) {
            std::cout << "Error!" << std::endl;
            break;
        }

    }

}

int main() {
    int input_a;
    int input_b;
    std::cin >> input_a;
    std::cin >> input_b;
//    std::cout << gcd_naive(input_a, input_b) << std::endl;
    std::cout << gcd_fast(input_a, input_b) << std::endl;
//    test();
    return 0;
}