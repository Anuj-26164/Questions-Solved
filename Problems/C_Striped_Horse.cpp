#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N, W; 
        cin >> N >> W;

        int M = 2 * W;
        vector<long long> bucket(M, 0);

        for (int i = 1; i <= N; i++)
        {
            long long c;
            cin >> c;
            bucket[i % M] += c;
        }

        // Duplicate array to handle circular sliding window
        vector<long long> arr(2 * M);
        for (int i = 0; i < M; i++)
        {
            arr[i] = bucket[i];
            arr[i + M] = bucket[i];
        }

        long long currentSum = 0;
        // Initial window
        for (int i = 0; i < W; i++)
        {
            currentSum += arr[i];
        }

        long long answer = currentSum;
        // Slide the window
        for (int i = W; i < M + W; i++)
        {
            currentSum += arr[i];
            currentSum -= arr[i - W];
            answer = min(answer, currentSum);
        }

        cout << answer << '\n';
    }

    return 0;
}
