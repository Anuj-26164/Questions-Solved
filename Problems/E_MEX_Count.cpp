#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        map<ll, ll> mp;
        for (auto e : arr)
            mp[e]++;
        ll mex = -1;
        vector<vector<ll>> ranges;
        for (int i = 0; i <= n; i++)
        {
            if (i == mex + 1)
            {
                ll left = mp[i];
                ll right = n - (mex + 1);
                if (mp[i])
                    mex++;
                ranges.push_back({left, right});
            }
            else
            {
                break;
            }
        }
        vector<ll> count(n + 2, 0);
        for (auto e : ranges)
        {
            count[e[0]]++;
            count[e[1] + 1]--;
        }
        for (int i = 1; i <= n; i++)
        {
            count[i] += count[i - 1];
        }
        for (int i = 0; i <= n; i++)
        {
            cout << count[i] << " ";
        }
        cout << endl;
    }
}