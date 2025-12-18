// Qs: C_Creating_Keys_for_StORages_Has_Become_My_Main_Skill
// Time: 23:16:42

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'
#define vin(v, n) \
    vl v(n);      \
    for (0, n)    \
        cin >> v[i];

void yes()
{
    cout << "YES" << endl;
}

void no()
{
    cout << "NO" << endl;
}

#define msb(mask) (63 - __builtin_clzll(mask)) /// 0 -> -1
#define lsb(mask) __builtin_ctzll(mask)        /// 0 -> 64
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask, bit) ((mask >> bit) & 1ll)
#define onbit(mask, bit) ((mask) | (1LL << (bit)))
#define offbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^ (1LL << bit))

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, ans = 0, mex = 0;
        cin >> n >> k;
        if (n == 1)
            cout << k << nl;
        else
        {
            vl solutionArr(n, 0);
            for (int i = 0; i < n - 1; i++)
            {
                if ((k & i) == i)
                {
                    ans = (ans | i);
                    solutionArr[i] = i;
                    mex++;
                }
                if ((mex | ans) == k)
                    solutionArr[n - 1] = mex;
                else
                    solutionArr[n - 1] = k;
            }
            for (auto c : solutionArr)
            {
                cout << c << " ";
            }
            cout << nl;
        }
    }
    return 0;
}