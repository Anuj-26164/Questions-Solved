#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define forl for (int i = 0; i < n; i++)
#define input(x, y) \
    int x, y;       \
    cin >> x;       \
    cin >> y;
#define ninput() \
    int n;       \
    cin >> n;
#define arrinput()      \
    vl arr(n);          \
    for (auto &c : arr) \
        cin >> c;
#define forl for (int i = 0; i < n; i++)
#define nl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vl arr(n), sol(n, -1);  // Initialize sol with -1 as default (in case no greater element exists)
    for (auto &c : arr)
        cin >> c;
    
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        while (!s.empty() && arr[s.top()] < x)
        {
            sol[s.top()] = x;  // Store the next greater element at the index popped from the stack
            s.pop();
        }
        s.push(i);  // Store the index of the current element in the stack
    }

    for (auto c : sol)
        cout << c << " " << nl;
    return 0;
}
