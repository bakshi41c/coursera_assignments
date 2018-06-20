#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::max;
using std::allocator;

int64_t MaxPairwiseProductFast(const std::vector<int64_t>& numbers) {
    int n = numbers.size();

    int idxl = 0;
    int idxl2 = 0;


    for (int i = 1; i < n; i++) {
        if (numbers[i] > numbers[idxl]) {
            idxl2 = idxl;
            idxl = i;
        }
    };


    if (idxl == 0) { // If index 0 is the largest number, set our assumption to index 1
        idxl2 = 1;
    }

    for (int i = idxl2; i < n; i++) {

        if (i == idxl) { // skip already large number
            continue;
        }

        if (numbers[i] > numbers[idxl2]) {
            idxl2 = i;
        }
    };

    int64_t product = numbers[idxl] * numbers[idxl2];
    return product;
}

int main() {
    int n;
    cin >> n;

    if (n > 2*100000) {
        cout << "too many input\n";
        return 0;
    }

    std::vector<int64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    int64_t product = MaxPairwiseProductFast(numbers);
    cout << product << "\n";
    return 0;
}