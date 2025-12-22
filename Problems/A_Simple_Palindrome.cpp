// Qs: A_Simple_Palindrome
// Time: 17:33:59

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'

void yes()
{
    cout << "YES" << endl;
}

void no()
{
    cout << "NO" << endl;
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
        ll n;
        cin >> n;
        string s;
        for (int i = 0; i < n; i++)
        {
            if (i % 5 == 1)
                s = s + "a";
            if (i % 5 == 2)
                s = s + "e";
            if (i % 5 == 3)
                s = s + "i";
            if (i % 5 == 4)
                s = s + "o";
            if (i % 5 == 0)
                s = s + "u";
        }
        sort(s.begin(), s.end());
        cout << s << nl;
    }
    return 0;
}