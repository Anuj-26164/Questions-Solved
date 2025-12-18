#include <bits/stdc++.h>
using namespace std;

#define read(x) scanf("%lld", &x)
#define read2(x, y) scanf("%lld %lld", &x, &y)
#define print(x) printf("%.10lf\n", x)
#define vl vector<long long>
#define ll long long

int main()
{
    ll n, d;
    read2(n, d);
    vl arr(n);
    for (auto &c : arr)
        cin >> c;
    sort(arr.begin(), arr.end());
    double max_gap = max((double)arr[0], (double)(d - arr[n - 1]));
    for (int i = 1; i < n; i++)
    {
        double gap = (arr[i] - arr[i - 1]) / 2.0;
        max_gap = max(max_gap, gap);
    }
    print(max_gap);
    return 0;
}
