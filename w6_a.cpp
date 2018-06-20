//
// Created by Shubham Bakshi on 19/06/2018.
//

#include <iostream>
#include <vector>

using std::vector;


void print2dVec(std::vector<std::vector<int>>  grid) {

    std::cout << "Printing " << grid.size() << "x" << grid[0].size() << ":" << std::endl;
    for ( std::vector<std::vector<int>>::size_type i = 0; i < grid.size(); i++ )
    {
        for ( std::vector<int>::size_type j = 0; j < grid[i].size(); j++ )
        {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int optimal_weight(int W, const std::vector<int> &bars) {
    std::vector<std::vector<int>> val;

    for (size_t i = 0; i <= bars.size(); ++i) {
        val.push_back({});
        for (int c = 0; c <= W; ++c) {

            if (i == 0 || c == 0){
                val[i].push_back(0);
                continue;
            }

            int optimal_weight = 0;

            // If We dont include the bar - So use value with same capacity but without this item (so one row up)
            if (i - 1 >= 0 && val[i-1][c] > optimal_weight){
                optimal_weight = val[i-1][c];
            }

            // If We include the bar - So use optimal value from capacity without this item + value of this item
            if (i - 1 >= 0 && (c - bars[i-1]) >= 0 &&  (val[i-1][c - bars[i-1]] + bars[i-1]) > optimal_weight){
                optimal_weight = val[i-1][c - bars[i-1]] + bars[i-1];
            }

//            std::cout << i-1 << std::endl;
//            std::cout << c << std::endl;
//            std::cout << bars[i-1] << std::endl;
//            std::cout << val[i-1][c - bars[i-1]] + bars[i-1] << std::endl;
//            std::cout << optimal_weight << std::endl;
//            print2dVec(val);
            val[i].push_back(optimal_weight);
        }
    }
    return val[bars.size()][W];
}


int main() {
    int n, W;
    std::cin >> W >> n;
    std::vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}
