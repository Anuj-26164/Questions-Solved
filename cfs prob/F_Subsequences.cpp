#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int maxElem = *std::max_element(a.begin(), a.end());
    int minElem = *std::min_element(a.begin(), a.end());

    long long result = 0;

    // Loop through the array to check for adjacent pairs of max and min elements
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] == maxElem && a[i + 1] == minElem) || (a[i] == minElem && a[i + 1] == maxElem)) {
            // Count the number of elements between the pair
            int inBetweenCount = i < n - 1 ? n - i - 2 : 0;
            result = (result + (1LL << inBetweenCount)) % MOD;
        }
    }

    std::cout << result << std::endl;
    
    return 0;
}
