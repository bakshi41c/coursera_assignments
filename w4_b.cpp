//
// Created by Shubham Bakshi on 29/04/2018.
//

#include <algorithm>
#include <iostream>
#include <vector>

int get_majority_element(std::vector<int> &a, int left, int right) {
    if (left == right) return a[left];
    int mid = (left + right) / 2;
    int maj_elem_l = get_majority_element(a, left, mid);
    int maj_elem_r = get_majority_element(a, mid+1, right);

    if (maj_elem_l == maj_elem_r){
        return maj_elem_r;
    }

    int count_maj_elem_l = 0;
    int count_maj_elem_r = 0;
    for (int i = left; i <= right; i++){
        if (a[i] == maj_elem_l) {
            count_maj_elem_l++;
        }

        if (a[i] == maj_elem_r) {
            count_maj_elem_r++;
        }
    }

    if (count_maj_elem_l > ((right-left) + 1) / 2) {
        return maj_elem_l;
    }

    if (count_maj_elem_r > ((right-left) + 1) / 2) {
        return maj_elem_r;
    }

    return -1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
//    std::cout << get_majority_element(a, 0, a.size()-1) << '\n';
    std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
