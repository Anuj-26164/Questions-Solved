#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> s;
        FOR(i, 1, n)
        s.insert(i);
        vi a(n + 1);
        int po2 = 1;
        while (po2 * 2 <= n)
            po2 *= 2;
        if (n & 1)
        {
            cout << n << endl;
            int low = n & (-n);
            a[n - 3] = low, a[n - 2] = low + (low == 1 ? 2 : 1), a[n - 1] = n - low, a[n] = n;
        }
        else
        {
            cout << po2 * 2 - 1 << endl;
            if (n == po2)
            {
                a[n - 4] = 1, a[n - 3] = 3, a[n - 2] = n - 2, a[n - 1] = n - 1, a[n] = n;
            }
            else
            {
                a[n - 2] = n, a[n - 1] = n - 1, a[n] = po2 - 1;
            }
        }
        FOR(i, 1, n + 1)
        s.erase(a[i]);
        FOR(i, 1, n + 1)
        if (!a[i]) a[i] = *s.begin(),
                   s.erase(a[i]);
        FOR(i, 1, n + 1)
            cout << a[i] << " ";
        cout << endl;
    }
}