#include <iostream>
#include <utility>
#include <vector>

int main()
{
    using namespace std;
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges(M);
    for (auto &&[u, v] : edges)
    {
        cin >> u >> v;
        --u; // Make indices 0-based
        --v;
    }

    int ans = M;
    // Try all 2^N ways of painting
    for (int bit = 0; bit < 1 << N; ++bit)
    {
        int delete_count = 0;
        for (const auto &[u, v] : edges)
        {                                             // Inspect each edge
            if ((1 & (bit >> u)) == (1 & (bit >> v))) // If the endpoints are painted in the same color
                ++delete_count;                       // increment the count
        }
        ans = min(ans, delete_count); // The answer is the minimum among all ways
    }
    cout << ans << endl;
    return 0;
}
