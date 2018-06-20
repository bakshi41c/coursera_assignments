//
// Created by Shubham Bakshi on 08/04/2018.
//

#include <iostream>


int64_t fib_naive(int64_t n) {
    if (n <= 1) {
        return n;
    } else {
        return fib_naive(n - 1) + fib_naive(n - 2);
    }
}

int64_t fib_fast(int64_t n) {
    int64_t fibs[n+1];
    fibs[0] = 0;
    fibs[1] = 1;

    if (n <= 1){
        return fibs[n];
    }

    for (int64_t i = 2; i < (n+1); i ++) {
        fibs[i] = fibs[i-1] + fibs[i-2];
    }

    return fibs[n];

}

void test() {
    int no_of_test_cases = 100;
    for (int i = 0; i < no_of_test_cases; i++) {
        int testValue = rand() % 30;
        int64_t f = fib_fast(testValue);
        int64_t n = fib_naive(testValue);
        std::cout << "Test Value: " << testValue << " Fast: " << f <<  " Naive: " << n << std::endl;
        if (f != n) {
            std::cout << "Error!";
            break;
        }
    }
}

int main() {
    int64_t input = 0;
    std::cin >> input;
    std::cout << fib_fast(input);
//    test();
    return 0;
}