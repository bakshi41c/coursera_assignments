//
// Created by Shubham Bakshi on 19/04/2018.
//

#include <iostream>
#include <vector>
#include <cmath>


std::vector<int> optimal_summands_greedy(int n) {
    std::vector<int> summands;
    int a = 1;
    while (n > 0) {
        if (n >= (2*a + 1)) {
            summands.push_back(a);
            n -= a;
            a++;
        } else{
            summands.push_back(n);
            n = 0;
        }

    }
    return summands;
}


std::vector<int> optimal_summands_formula(int n) {
    std::vector<int> summands;

    double a = 1;
    double b = 3;
    double c = 2 - (2*n);

    int k;
    double kc1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    double kc2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

//    std::cout << kc1 << " " << kc2 << std::endl;

    if (kc1 > 0) {
        k = (int) floor(kc1 + 1);
    } else {
        k = (int) floor(kc2 + 1);
    }

    for (int i = 1; i < k; i++){
        summands.push_back(i);
    }

    int leftover = n - ((k*(k+1)) / 2);
    summands.push_back(k+leftover);

    return summands;
}

void print_vector(std::vector<int> vec){
    for (auto const& value :  vec)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
}



void sanity_test(){
    int no_of_test_cases = 100;
    for (int i = 0; i < no_of_test_cases; i++) {
        int testValue = (rand() % 10000) + 1;
        std::vector<int> f = optimal_summands_formula(testValue);
        std::vector<int> g = optimal_summands_greedy(testValue);
        std::cout << "Test Value: " << testValue << std::endl;

        if (f.size() != g.size()){
            std::cout << "Wrong! Answer" << std::endl;
            print_vector(f);
            print_vector(g);
        }

    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> summands = optimal_summands_greedy(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
