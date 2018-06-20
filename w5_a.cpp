//
// Created by Shubham Bakshi on 17/06/2018.
//

#include <iostream>
#include <vector>

int get_change(int m) {

    std::vector<int> coins;
    coins.push_back(1);
    coins.push_back(3);
    coins.push_back(4);

    std::vector<int> min_no_coins;
    min_no_coins.push_back(0);

    for (int i = 1 ;i <= m; i++){
        int min = -1;
        for (int coin : coins) {
            if (min == -1) {
                min = min_no_coins[i - coin] + 1;
            } else {
                if (i - coin >= 0 && min_no_coins[i - coin] + 1 < min){
                    min = min_no_coins[i - coin] + 1;
                }
            }
        }
        min_no_coins.push_back(min);
    }

    return min_no_coins[m];
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
