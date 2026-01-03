#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    unordered_map<int, int> count; 

    int limit = sqrt(N);
    
    for (int x = 1; x <= limit; x++)
    {
        for (int y = x + 1; y <= limit && (x * x + y * y <= N); y++)
        {
            int n = x * x + y * y;
            count[n]++;
        }
    }
    set<int> ans;
    for (auto &[n, c] : count)
    {
        if (c == 1)
            ans.insert(n);
    }
    cout << ans.size()<<endl;
    for(auto x:ans)
        cout << x << " ";
    return 0;
}
