#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define lli long long int
#define forl for (int i = 0; i < n; i++)
#define nl '\n'

bool isEven(int n)
{
    return (n & 1) == 0;
}

bool isSorted(const vi &vec)
{
    for (size_t i = 0; i < vec.size() - 1; ++i)
    {
        if (vec[i] > vec[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool isprime(int n)
{
    if (n <= 1)
        return false; // 0 and 1 are not prime
    if (n <= 3)
        return true; // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int power(int N, int M)
{
    int power = N, sum = 1;
    if (N == 0)
        sum = 0;
    while (M > 0)
    {
        if ((M & 1) == 1)
        {
            sum *= power;
        }
        power = power * power;
        M = M >> 1;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, o;
        bool possible = false;
        cin >> n;
        n+=1;
        for (int i = 1; i < n; i += 2)
        {
            if (possible == false)
            {
                for (int j = 2; j < n; j += 2)
                {
                    if (!isprime(i + j))
                    {
                        m = i;
                        o = j;
                        possible = true;
                        break;
                    }
                }
            }
        }
        if (possible)
        {
            for (int i = 1; i < n; i += 2)
            {
                if (i == m)
                {
                    continue;
                }
                else
                {
                    cout << i << " ";
                }
            }
            cout << m << " " << o << " ";
            for (int i = 2; i < n; i += 2)
            {
                if (i == o)
                {
                    continue;
                }
                else
                {
                    cout << i << " ";
                }
            }
            cout << nl;
        }
        else
        {
            cout << -1 << nl;
        }
    }

    return 0;
}