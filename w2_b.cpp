//
// Created by Shubham Bakshi on 08/04/2018.
//

#include <iostream>

int64_t fib_last_digit_naive_accurate_on_small(int64_t n) {
    int64_t fibs[n+1];
    fibs[0] = 0;
    fibs[1] = 1;

    if (n <= 1){
        return fibs[n];
    }

    for (int64_t i = 2; i < (n+1); i ++) {
        fibs[i] = (fibs[i-1] + fibs[i-2]);
    }

    return fibs[n] % 10;

}

int64_t fib_last_digit(int64_t n) {
    int64_t fibs[n+1];
    fibs[0] = 0;
    fibs[1] = 1;

    if (n <= 1){
        return fibs[n];
    }

    for (int64_t i = 2; i < (n+1); i ++) {
        fibs[i] = (fibs[i-1] + fibs[i-2]) % 10;
    }

    return fibs[n];

}

void test_small(){
    int no_of_test_cases = 30;
    for (int i = 0; i < no_of_test_cases; i++) {
        int64_t n = fib_last_digit_naive_accurate_on_small(i);
        int64_t f = fib_last_digit(i);
        std::cout << "Test Value: " << i << " Fast: " << f <<  " Naive: " << n << std::endl;
        if (f != n) {
            std::cout << "Error!";
            break;
        }
    }
}

int main() {
    int64_t input = 0;
    std::cin >> input;
    std::cout << fib_last_digit(input);
//    test_small();
}