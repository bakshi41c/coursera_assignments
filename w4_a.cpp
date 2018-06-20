//
// Created by Shubham Bakshi on 29/04/2018.
//

#include <iostream>
#include <cassert>
#include <vector>

int binary_search(const std::vector<int> &a, int x, int left, int right) {
    int mid = (left + right) / 2;

//    std::cout << left << " " << mid << " " << right << std::endl;

    if (a.at(mid) == x) {
//        std::cout << "Found the element at mid: " << mid << std::endl;
        return mid;
    }

    if (left == right || left > right) {
//        std::cout << "Reached the end, going back up" << std::endl;
        return -1;
    }

    if (a.at(mid) < x) {
//        std::cout << "Searching right: " << mid+1 << " " << right << std::endl;
        return binary_search(a, x, mid+1, right);
    } else {
//        std::cout << "Searching left: " << left << " " << mid-1 << std::endl;
        return binary_search(a, x, left, mid-1);
    }
}

int linear_search(const std::vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}


void print_vector(std::vector<int> vec){
    for (auto const& value :  vec)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
}

void test(){
    int no_of_test_cases = 10000;
    for (int i = 0; i < no_of_test_cases; i++) {
        // Populate test_array
        int arraySize = (rand() % 1000) + 1;
        int startNumber = (rand() % 10);
        std::vector<int> test_array(arraySize);
        for (int i = 0; i< test_array.size(); i++){
            startNumber += (rand() % 3);
            test_array[i] = startNumber;
        }

        int random_element = test_array[(rand() % (arraySize - 1))];

        int l = linear_search(test_array, random_element);
        int b = binary_search(test_array, random_element, 0, test_array.size()-1);

        std::cout << "search: " << random_element << " L: " << l << " B: " << b << std::endl;

        if (test_array[l] != test_array[b]) {
            std::cout << "Error!" << std::endl;
            print_vector(test_array);
        }

    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cout << binary_search(a, b[i], 0 , a.size()-1) << ' ';
    }
//    test();
}
