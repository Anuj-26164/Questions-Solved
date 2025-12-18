#include <iostream>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int s = 0;
    int d = 30;
    while (d >= 0) {
        if ((a & (1 << d)) == (b & (1 << d))) {
            if (a & (1 << d)) {
                s += (1 << d);
            }
        } else {
            break;
        }
        d--;
    }
    if (b > s + (1 << d)) {
        cout << (s + (1 << d) - 1) << " " << (s + (1 << d)) << " " << (s + (1 << d) + 1) << endl;
    } else {
        cout << (s + (1 << d) - 2) << " " << (s + (1 << d) - 1) << " " << (s + (1 << d)) << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        t--;
        solve();
    }
    return 0;
}