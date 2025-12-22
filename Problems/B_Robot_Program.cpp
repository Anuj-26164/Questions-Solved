#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i, l, r) for (ll i = l; i < r; i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, l, r) for (ll i = r - 1; i >= l; i--)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
typedef vector<int> vi;

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);
    int _ = 1;
    cin >> _;
    while (_--)
    {
        ll N, x, K;
        cin >> N >> x >> K;
        string S;
        cin >> S;
        vi A(N + 1, x);
        REP(i, N)
        {
            A[i + 1] = A[i];
            if (S[i] == 'R')
                A[i + 1]++;
            else
                A[i + 1]--;
        }
        if (count(A.begin() + 1, A.end(), 0) == 0)
        {
            cout << 0 << endl;
            continue;
        }
        ll t = 0;
        while (A[t])
            t++;
        // if (t > K)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }
        K -= t;
        ll ans = 1;
        ll s = 1;
        while (s <= N && A[s] != x)
            s++;
        if (s > N)
            cout << 1 << endl;
        else
            cout << ans + (K / s) << endl;
    }
    return 0;
}