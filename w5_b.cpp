//
// Created by Shubham Bakshi on 17/06/2018.
//

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

std::vector<int> optimal_sequence(int n) {
    std::vector<int> sequence;
    while (n >= 1) {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

std::vector<int> optimal_sequence_dp(int n) {
    std::vector<int> optimal_steps;
    std::vector<int> prev_optimal_array;
    optimal_steps.push_back(0);
    prev_optimal_array.push_back(0);

    for (int i = 1 ;i <= n; i++){
        int min = -1;
        int prev_val = i;

        min = optimal_steps[i-1] + 1;
        prev_val = i-1;

        if (i % 3 == 0 && (optimal_steps[i/2] + 1) < min) {
            min = optimal_steps[i/3] + 1;
            prev_val = i/3;
        }

        if (i % 2 == 0 && (optimal_steps[i/2] + 1) < min){
            min = optimal_steps[i/2] + 1;
            prev_val = i/2;
        }

        optimal_steps.push_back(min);
        prev_optimal_array.push_back(prev_val);
    }

    // Backtrack to see how we got here
    std::vector<int> sequence;
    auto index = n;
    while (index != 0) {
        sequence.push_back(index);
        index = prev_optimal_array[index];
    }

    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> sequence = optimal_sequence_dp(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
}
