#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    // Precompute the powers of 2 up to 2^20 (because 2^20 is a bit over 10^6).
    vector<int> powers_of_two;
    for (int i = 1; i <= 20; i++) {
        powers_of_two.push_back(1 << i);
    }
    
    while (t--) {
        int n;
        cin >> n;
        
        if (n == 1) {
            // For n = 1, output any number (e.g., 69)
            cout << 69 << endl;
        } else {
            // For n > 1, output the first n powers of two
            for (int i = 0; i < n; i++) {
                cout << powers_of_two[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
