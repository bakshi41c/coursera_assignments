//
// Created by Shubham Bakshi on 29/04/2018.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

int partition2(std::vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[l], a[j]);
    return j;
}


void print_vector(std::vector<int> vec){
    for (auto const& value :  vec)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
}

std::pair<int,int> partition3(std::vector<int> &a, int l, int r) {
    int x = a[l];
//    std::cout << "Pivot: " << x << " Left: " << l << " Right: " << r << '\n';
    int m1 = l; // should point to first of equal
    int m2 = l; // should point to last of equal
//    print_vector(a);
    for (int i = l + 1; i <= r; i++) {
//        print_vector(a);
        if (a[i] < x) {
            m2++;
            std::swap(a[i], a[m2]); // m2 points to the new left element
            std::swap(a[m1], a[m2]); // m1 points to the last of the left element, m2 points to last of same element
            m1++; // m1 now points to first of same element

        } else if (a[i] == x) {
            m2++;
            std::swap(a[i], a[m2]);
        }
    }

//    std::swap(a[l], a[m1]);
    std::pair<int,int> result;
    result.first = m1;
    result.second = m2;
//    print_vector(a);

//    std::cout << "======" << '\n';
    return result;
}
//
//void randomized_quick_sort(std::vector<int> &a, int l, int r) {
//    if (l >= r) {
//        return;
//    }
//
//    int k = l + rand() % (r - l + 1);
//    std::swap(a[l], a[k]);
//    int m = partition2(a, l, r);
//
//    randomized_quick_sort(a, l, m - 1);
//    randomized_quick_sort(a, m + 1, r);
//}

void randomized_quick_sort(std::vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    std::swap(a[l], a[k]);
    auto m = partition3(a, l, r);

    randomized_quick_sort(a, l, m.first - 1);
    randomized_quick_sort(a, m.second + 1, r);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}
