#include <bits/stdc++.h>
using namespace std;

#define vl vector<ll>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nkinput() \
    int n, k;     \
    cin >> n;     \
    cin >> k;
#define ninput() \
    int n;       \
    cin >> n;
#define arrinput()      \
    vl arr(n);          \
    for (auto &c : arr) \
        cin >> c;
#define forl for (int i = 0; i < n; i++)
#define nl '\n'


ll minm(ll xa, ll ya, ll xd, ll yd, ll k)
{
    ll distance = abs(xa - xd) + abs(ya - yd);
    return (distance + k - 1) / k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll xa, ya, xd, yd, k;
        cin >> xa >> ya >> xd >> yd >> k;
        cout << minm(xa, ya, xd, yd, k) << endl;
    }
    return 0;
}