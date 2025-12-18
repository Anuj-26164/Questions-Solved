#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define lli long long int
#define forl for (int i = 0; i < n; i++)
#define nl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k = 3, count = 0, sum = 1;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << nl;
        }
        else if (n <= 4)
        {
            cout << 2 << nl;
        }
        else

        {
            while (1)
            {
                sum += k;
                k *= 2;
                count++;
                if (sum >= n)
                {
                    count++;
                    cout << count << nl;
                    break;
                }
            }
        }
    }
    return 0;
}