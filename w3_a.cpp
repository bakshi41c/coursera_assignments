//
// Created by Shubham Bakshi on 14/04/2018.
//

#include <iostream>
#include <vector>

std::vector<int> change(int money) {
    auto coins = std::vector<int> {10, 5, 1};
    auto change = std::vector<int> {};

    while (money > 0) {
        for (auto coin : coins){
            if ((money - coin) < 0) {
                continue;
            } else {
                change.push_back(coin);
                money -= coin;
                break;
            }
        }

    }

    return change;

}

void print_vector(std::vector<int> vec){
    for (auto const& value :  vec)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
}

int main() {
    int money_to_change;
    std::cin >> money_to_change;
    std::vector<int> coins = change(money_to_change);
//    print_vector(coins);
    std::cout << coins.size();
    return 0;
}

