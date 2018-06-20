//
// Created by Shubham Bakshi on 14/04/2018.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

void print_vector(std::vector<std::pair<int, double_t > >vec){
    for (auto const& value :  vec)
    {
        std::cout << value.first << ", " << value.second << "   ";
    }
    std::cout << "\n";
}

bool compare_func(std::pair<int, double_t > &a, std::pair<int, double_t > &b)
{
    return a.second > b.second;
}

double_t max_value(std::vector<int> item_weight, std::vector<int> item_value, int max_weight) {

    if (item_weight.size() != item_value.size()) {
        std::cout << "Not enough parameters" << std::endl;
        return -1;
    }

    std::vector<std::pair<int, double_t >> item_value_density_and_weight(item_weight.size());

    std::vector<double_t> sorted_weight_as_per_value(item_weight.size());

    // Calculate value per weight
    for (int i =0; i < item_weight.size(); i++){
        item_value_density_and_weight[i] = std::pair<int, double_t>{item_weight[i], (double_t) item_value[i] / item_weight[i]};  ;
    }

    std::sort(item_value_density_and_weight.begin(), item_value_density_and_weight.end(), compare_func);

//    print_vector(item_value_density_and_weight);

    double_t capacity = max_weight;
    double_t total_value = 0;

    for (int i = 0; i < item_value_density_and_weight.size(); i++) {
        if (capacity > 0) {
            double_t max_item_weight = std::min(capacity, (double_t) item_value_density_and_weight[i].first);
//           std::cout << max_item_weight << ", " << max_item_weight*item_value_density_and_weight[i].second<< "\n";
            capacity -= max_item_weight;
            total_value += max_item_weight*item_value_density_and_weight[i].second;
        } else {
            break;
        }
    }

    return total_value;

}



int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    std::vector<int> values(n);
    std::vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double_t optimal_value = max_value(weights, values, capacity);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}