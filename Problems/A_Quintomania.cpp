#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        bool k = false;
        cin >> n;
        vector<int> v;
        while (n--)
        {
            int x;
            cin >> x;
            if (v.size() && abs(v.back() - x) != 5 && abs(v.back() - x) != 7)
                k = true;
            v.push_back(x);
        }
        cout << (k ? "NO" : "YES") << endl;
        k = false;
    }
    return 0;
}