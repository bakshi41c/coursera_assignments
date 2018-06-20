//
// Created by Shubham Bakshi on 19/04/2018.
//

#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>


bool compare_func(std::string &a, std::string &b)
{
   int c1 = std::stoi(a+b);
   int c2 = std::stoi(b+a);

   return c1 > c2;
}

std::string largest_number(std::vector<std::string> a) {
    //write your code here

    std::sort(a.begin(), a.end(), compare_func);

    std::stringstream ret;
    for (size_t i = 0; i < a.size(); i++) {
        ret << a[i];
    }
    std::string result;
    ret >> result;
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    std::cout << largest_number(a);
}
