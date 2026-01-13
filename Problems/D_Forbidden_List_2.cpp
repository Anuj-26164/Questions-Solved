#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // Function to count how many numbers <= t are missing from A
    auto missing_count = [&](long long t)
    {
        long long present = upper_bound(A.begin(), A.end(), t) - A.begin();
        return t - present;
    };

    while (Q--)
    {
        long long X, Y;
        cin >> X >> Y;

        long long base = missing_count(X - 1);

        long long left = X, right = X + Y + N*2;
        while (left < right)
        {
            long long mid = (left + right) / 2;
            if (missing_count(mid) >= base + Y)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        cout << left << '\n';
    }

    return 0;
}
