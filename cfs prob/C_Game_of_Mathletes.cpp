#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
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
        vl arr(n);
        for (auto &c : arr)
        {
            cin >> c;
        }

        unordered_map<ll, ll> freq;
        for (const auto &num : arr)
        {
            freq[num]++;
        }

        ll pairs = 0;
        for (const auto &num : arr)
        {
            ll complement = k - num;
            if (freq[num] > 0 && freq[complement] > 0)
            {
                if (num == complement)
                {
                    pairs += freq[num] / 2;
                    freq[num] = 0;
                }
                else
                {
                    ll count = min(freq[num], freq[complement]);
                    pairs += count;
                    freq[num] -= count;
                    freq[complement] -= count;
                }
            }
        }

        cout << pairs << nl;
    }
    return 0;
}
