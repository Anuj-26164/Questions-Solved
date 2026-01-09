#include <bits/stdc++.h>
using namespace std;

int main() {
    // Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
    long long sum_of_squares = 0;
    long long square_of_sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum_of_squares += i * i;
        square_of_sum += i;
    }
    square_of_sum *= square_of_sum;
    cout << square_of_sum - sum_of_squares << "\n";
    return 0;
}