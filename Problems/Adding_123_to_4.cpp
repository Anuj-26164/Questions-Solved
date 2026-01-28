#include <bits/stdc++.h>
using namespace std;

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int X, Y, Z;
        cin >> X >> Y >> Z;

        int pairs13 = min(X, Z);
        int pairs22 = Y / 2;

        cout << pairs13 + pairs22 << '\n';
    }
    return 0;
}
