// Qs: Eko
// Time: 13:25:46

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
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

ll n, reqdwood;
ll N = 1e6 + 10;
vl wood(N);
bool iswoodsuff(int h)
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {

        if (wood[i] >= h)
        {
            sum += wood[i] - h;
        }
    }
    if (sum >= reqdwood)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> reqdwood;
    for (int i = 0; i < n; i++)
    {
        cin >> wood[i];
    }
    ll lo = 0, hi = 1e9, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (iswoodsuff(mid) == true)
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    if (iswoodsuff(hi) == true)
    {
        cout << hi;
    }
    else
    {
        cout << lo;
    }

    return 0;
}