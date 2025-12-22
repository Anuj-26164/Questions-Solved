#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        int arrival, departure;
        cin >> arrival >> departure;
        events.push_back({arrival, +1});
        events.push_back({departure, -1});
    }

    sort(events.begin(), events.end());

    ll maxCustomers = 0, currentCustomers = 0;
    for (auto [time, type] : events) {
        currentCustomers += type;
        maxCustomers = max(maxCustomers, currentCustomers);
    }

    cout << maxCustomers << '\n';
    return 0;
}
