#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// const int MOD = 1e9 + 7;

class Solution
{
public:
    void insertSorted(stack<int> &st, int x)
    {
        if (st.empty() || st.top() <= x)
        {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();
        insertSorted(st, x);
        st.push(temp);
    }

    void sortStack(stack<int> &st)
    {
        if (st.empty())
            return;

        int x = st.top();
        st.pop();
        sortStack(st);
        insertSorted(st, x);
    }
};
