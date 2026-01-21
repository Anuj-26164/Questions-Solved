#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;
static const int MAXM = 200000;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int mul(long long a, long long b)
{
    return (int)((a * b) % MOD);
}

int powmod(int a, int e)
{
    int r = 1;
    while (e)
    {
        if (e & 1)
            r = mul(r, a);
        a = mul(a, a);
        e >>= 1;
    }
    return r;
}

int modinv(int a)
{
    return powmod(a, MOD - 2);
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Möbius function
    vector<int> mu(MAXM + 1, 1), prime;
    vector<bool> is_comp(MAXM + 1, false);

    mu[0] = 0;
    for (int i = 2; i <= MAXM; i++)
    {
        if (!is_comp[i])
        {
            prime.push_back(i);
            mu[i] = -1;
        }
        for (int p : prime)
        {
            if (i * p > MAXM)
                break;
            is_comp[i * p] = true;
            if (i % p == 0)
            {
                mu[i * p] = 0;
                break;
            }
            else
            {
                mu[i * p] = -mu[i];
            }
        }
    }

    int T;
    cin >> T;
    while (T--)
    {
        int M;
        cin >> M;

        int invM = modinv(M);
        int ans = 0;

        for (int d = 1; d <= M; d++)
        {
            if (mu[d] == 0)
                continue;

            int term = mul(mu[d], modinv(d));
            int prob = add(1, MOD - mul(M / d, invM));
            ans = add(ans, mul(term, prob));
        }

        cout << ans << "\n";
    }

    return 0;
}
