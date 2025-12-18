// Qs: A_Bus_to_Pénjamo
// Time: 10:53:04

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
        ll n, rows;
        cin >> n >> rows;
        vl arr(n);
        f(0, n) cin >> arr[i];
        ll countHappy = 0, pendingPpl = 0;
        sort(arr.begin(), arr.end(), greater<int>());
        ll totalSeats = 2 * rows;
        f(0, n)
        {

            if (arr[i] % 2 == 0)
            {
                countHappy += arr[i];
                totalSeats -= arr[i];
            }
            else if (arr[i] % 2 != 0 && arr[i] > 1)
            {
                countHappy += arr[i] - 1;
                totalSeats -= (arr[i] - 1);
                pendingPpl += 1;
            }
            else if(arr[i]==1)
            {
                pendingPpl+=1;
            }
        }
        if(totalSeats>=2*pendingPpl)
        {
            countHappy+=pendingPpl;
        }
        else
        {
            countHappy+=totalSeats-pendingPpl;
        }
        cout << countHappy << nl;
    }
    return 0;
}