#include <bits/stdc++.h>
using namespace std;

#define read(x) scanf("%lld", &x)
#define read2(x, y) scanf("%lld %lld", &x, &y)
#define print(x) printf("%lld\n", x)
#define ll long long int

void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

int main()
{
    ll t;
    read(t);
    while (t--)
    {
        ll n;
        read(n);
        string s, t;
        cin >> s >> t;

        if (s[0] == '1') {
            yes();
            continue;
        }

        ll idx = -1;
        for (ll i = 0; i < n; i++) {
            if (s[i] == '1') {
                idx = i;
                break;
            }
        }

        if (idx == -1) {  
            bool all_zero = true;
            for (ll i = 0; i < n; i++) {
                if (t[i] == '1') {
                    no();
                    all_zero = false;
                    break;
                }
            }
            if (all_zero) yes();
        }
        else {
            bool valid = true;
            for (ll i = 0; i < idx; i++) {
                if (t[i] == '1') {
                    no();
                    valid = false;
                    break;
                }
            }
            if (valid) yes();
        }
    }
    return 0;
}
