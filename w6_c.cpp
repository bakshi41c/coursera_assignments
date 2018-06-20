//
// Created by Shubham Bakshi on 20/06/2018.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>    // std::min_element, std::max_element

using std::vector;
using std::string;
using std::max;
using std::min;

std::vector<std::vector<long long>> min_values;
std::vector<std::vector<long long>> max_values;
std::vector<char> ops;


void print2dVec(std::vector<std::vector<long long>>  grid) {

    std::cout << "Printing " << grid.size() << "x" << grid[0].size() << ":" << std::endl;
    for ( std::vector<std::vector<long long>>::size_type i = 0; i < grid.size(); i++ )
    {
        for ( std::vector<long long>::size_type j = 0; j < grid[i].size(); j++ )
        {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void printVec(std::vector<char> vec){
    for (auto const& value :  vec)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
}

void printVecll(std::vector<long long> vec){
    for (auto const& value :  vec)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
}

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        std::cout << op << std::endl;
        assert(0);
    }
}


std::pair<long long, long long> get_min_max(long long l, long long r) {

//    std::cout << "Getting min max (" << l << ", " << r << ")" << std::endl;
    long long min = 90000;
    long long max = -90000;

    for (long long i = l; i <= r-1; i++) {
        std::vector<long long> vals_max;
        std::vector<long long> vals_min;

        vals_max.push_back(eval(max_values[l][i], max_values[i+1][r], ops[i]));
        vals_min.push_back(eval(max_values[l][i], max_values[i+1][r], ops[i]));

        vals_max.push_back(eval(min_values[l][i], max_values[i+1][r], ops[i]));
        vals_min.push_back(eval(min_values[l][i], max_values[i+1][r], ops[i]));

        vals_max.push_back(eval(max_values[l][i], min_values[i+1][r], ops[i]));
        vals_min.push_back(eval(max_values[l][i], min_values[i+1][r], ops[i]));

        vals_max.push_back(eval(min_values[l][i], min_values[i+1][r], ops[i]));
        vals_min.push_back(eval(min_values[l][i], min_values[i+1][r], ops[i]));

        vals_max.push_back(max);
        max = *std::max_element( std::begin(vals_max), std::end(vals_max));
//        std::cout << "Max: " << max << std::endl;

        vals_min.push_back(min);
        min = *std::min_element( std::begin(vals_min), std::end(vals_min));
//
//        if (max == 7){
//            std::cout << "===========" << std::endl;
//            print2dVec(max_values);
//            print2dVec(min_values);
//            std::cout << max << std::endl;
//            std::cout << ops[i] << std::endl;
//            std::cout << max_values[l][i] << max_values[i+1][r] << std::endl;
//            std::cout << min_values[l][i] << max_values[i+1][r] << std::endl;
//            std::cout << max_values[l][i] << min_values[i+1][r] << std::endl;
//            std::cout << min_values[l][i] << min_values[i+1][r] << std::endl;
//            print2dVec(max_values);
//            print2dVec(min_values);
//            std::cout << "===========" << std::endl;
//        }

//        printVecll(vals);
//        std::cout << "Min: " << min << std::endl;
    }

    std::pair<long long, long long> result(min, max);
//    std::cout << "Result min:" << result.first << " max: " << result.second << std::endl;

    return result;
}


long long parse_and_populate(const string &exp) {

    long long n = (exp.size() + 1) / 2;

    for ( int i = 0 ; i < n ; i++ ) {
        max_values.push_back({});
        min_values.push_back({});
        for (int j = 0; j < n; j++) {
            max_values[i].push_back(0);
            min_values[i].push_back(0);

        }
    }


    for (int i = 0; i < exp.size(); i++){
        if (i % 2 == 0) {
            int pos = (i + 1) / 2;
            max_values[pos][pos] = int(exp[i]) - 48;
            min_values[pos][pos] = int(exp[i]) - 48;
        } else {
            ops.push_back(exp[i]);
        }
    }
//    print2dVec(max_values);
//    print2dVec(min_values);
//    printVec(ops);
    return n;
}


long long get_maximum_value(const string &exp) {
    long long n = parse_and_populate(exp);
    for (long long i = 1; i <= n-1; i++){
        for (long long j = 0; j < n-i; j++){
//            std::cout << "Getting min max (" << j << ", " << i+j << ")" << std::endl;
            auto result = get_min_max(j,i+j);
            min_values[j][i+j] = result.first;
            max_values[j][i+j] = result.second;
        }
    }
//    print2dVec(max_values);
//    print2dVec(min_values);
    return max_values[0][n-1];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
