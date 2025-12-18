// Qs: D_For_Wizards_the_Exam_Is_Easy_but_I_Couldn_t_Handle_It
// Time: 21:06:05

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'

ll totalinversions(vl &arr)
{
    ll count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] > arr[i])
            {
                count++;
            }
        }
    }
    return count;
}

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
        vl arr(n);
        f(0, n) cin >> arr[i];
        ll inv = totalinversions(arr);
        ll ans = inv, ansl = 0, ansr = 0;
        for (int i = 0; i < n; i++)
        {
            ll greater = 0, smaller = 0;
            for (int j = i + 1; j < n; j++)
            {

                if (arr[j] > arr[i])
                {
                    greater++;
                }
                else if (arr[j] < arr[i])
                {
                    smaller++;
                }
                if (ans > inv + greater - smaller)
                {
                    ans = inv + greater - smaller;
                    ansl = i;
                    ansr = j;
                }
            }
        }
        cout << ansl + 1 << " " << ansr + 1 << nl;
    }
    return 0;
}