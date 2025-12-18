#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
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
        string s, t;
        cin >> s >> t;
        bool possible = false;
        int index = -1;

        int ptr=0;
        for(int i=0;i<s.size();i++)
        {
            if(ptr<t.size() && s[i]==t[ptr]) ptr++;
        }
        if(ptr==t.size()) yes();
        else no();

    }
    return 0;
}
