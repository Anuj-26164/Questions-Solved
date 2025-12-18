#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define ll long long int
#define nl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vl vec1(n);
        for (ll &c : vec1)
            cin >> c;

        vl indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return vec1[a] > vec1[b]; 
        });

        ll sum = 0;
        for (int i = 0; i <= k; i++)
            sum += vec1[indices[i]];

        cout << sum << nl;
    }
    return 0;
}
