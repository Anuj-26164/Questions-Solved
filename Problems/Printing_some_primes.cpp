#include <bits/stdc++.h>
using namespace std;

const int N = 100000000;
const int BLOCK = 100000; // segment size

vector<int> primes;

void precompute()
{
    int limit = sqrt(N) + 1;
    vector<bool> isprime(limit + 1, true);
    isprime[0] = isprime[1] = false;

    for (int i = 2; i * i <= limit; i++)
        if (isprime[i])
            for (int j = i * i; j <= limit; j += i)
                isprime[j] = false;

    for (int i = 2; i <= limit; i++)
        if (isprime[i])
            primes.push_back(i);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int cnt = 0;

    for (int L = 2; L <= N; L += BLOCK)
    {
        int R = min(L + BLOCK - 1, N);
        vector<char> isprime(R - L + 1, 1);

        for (int p : primes)
        {
            if (1LL * p * p > R)
                break;

            int start = max(p * p, ((L + p - 1) / p) * p);
            for (int j = start; j <= R; j += p)
                isprime[j - L] = 0;
        }

        for (int i = L; i <= R; i++)
        {
            if (i >= 2 && isprime[i - L])
            {
                cnt++;
                if (cnt % 100 == 1)
                    cout << i << '\n';
            }
        }
    }
    return 0;
}
