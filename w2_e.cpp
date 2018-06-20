//
// Created by Shubham Bakshi on 08/04/2018.
//

#include <iostream>
#include <vector>

//
//void print_vector(std::vector<int> vec){
//    for (auto const& value :  vec)
//    {
//        std::cout << value << std::endl;
//    }
//}


std::vector<int> compute_pisano(int mod) {

    std::vector<int> pisano_numbers;

    pisano_numbers.push_back(0);
    pisano_numbers.push_back(1);

    while (true) {
        int new_pisano = (pisano_numbers[pisano_numbers.size() - 1] + pisano_numbers[pisano_numbers.size() - 2]) % mod;

        if (pisano_numbers[pisano_numbers.size() - 1] == 0 && new_pisano == 1){
            break;
        }
        pisano_numbers.push_back(new_pisano);

    }

    pisano_numbers.pop_back();

    return pisano_numbers;
}

int fib_mod(long long n, int mod) {
    std::vector<int> pisano_period = compute_pisano(mod);
    unsigned long pos = n % pisano_period.size();
    return pisano_period[pos];
}

int main(){
    long long len;
    int mod;
    std::cin >> len;
    std::cin >> mod;
    std::cout << fib_mod(len, mod);
}