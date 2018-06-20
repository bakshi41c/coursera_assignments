//
// Created by Shubham Bakshi on 08/04/2018.
//

#include <iostream>
#include <vector>

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


//void print_vector(std::vector<int> vec){
//    for (auto const& value :  vec)
//    {
//        std::cout << value << " ";
//    }
//    std::cout << "\n";
//}

unsigned long long compute_last_digit_fibonacci_sum(unsigned long long input){

    std::vector<int> pisano_10 =  compute_pisano(10);
//    print_vector(pisano_10);

    unsigned long long period_repeats = input / pisano_10.size();
    unsigned long long period_remainder = input % pisano_10.size();

    int pisano_full_sum = 0;
    int pisano_partial_sum = 0;
    for (int i =0; i < pisano_10.size(); i++) {
        pisano_full_sum = (pisano_full_sum + pisano_10[i]) % 10;
        if (i == period_remainder) {
            pisano_partial_sum = pisano_full_sum;
        }
    }

//    std::cout << period_repeats << std::endl;
//    std::cout << period_remainder << std::endl;
//    std::cout << pisano_full_sum << std::endl;
//    std::cout << pisano_partial_sum << std::endl;

    return ((period_repeats*pisano_full_sum) + pisano_partial_sum) % 10;

}

int main(){
    unsigned long long input;
    std::cin >> input;

    std::cout << compute_last_digit_fibonacci_sum(input);

    return 0;

}