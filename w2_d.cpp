//
// Created by Shubham Bakshi on 08/04/2018.
//

#include <iostream>
#include <algorithm>

long long lcm_naive(int a, int b) {
    long long max = (long long) a*b;
    for (long long i = 1; i <= max; i++) {
        if ((i % a == 0) && (i % b == 0)) {
            return i;
        }
    }
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


long long lcm_fast(int a, int b) {
    // lcm = larger number * the unique factors from smaller number
    // so naive multiple will have all the factors from both number, we just need to take out the common ones i.e. gcd
    auto naive_multiple = (long long) a*b;
    int gcd = gcd_fast(a,b);
    return naive_multiple / gcd;
}


void test() {
    int number_of_tests = 1000;

    for (int i = 0; i < number_of_tests; i++) {
        int input_a = rand() % 100 + 1;
        int input_b = rand() % 100 + 1;
        long long f = lcm_fast(input_a, input_b);
        long long n = lcm_naive(input_a, input_b);
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
//    std::cout << lcm_naive(input_a, input_b);
    std::cout << lcm_fast(input_a, input_b);
//    test();
    return 0;
}