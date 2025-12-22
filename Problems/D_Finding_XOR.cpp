#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long result = 0;
    for (int i = 0; i < 20; ++i)
    {
        int x = (1 << i);

        cout << "? " << x << endl;
        cout.flush();

        int sum;
        cin >> sum;
        if (sum % 2 == 1) 
        {
            result |= (1 << i);
        }
    }

    cout << "! " << result << endl;
    cout.flush();
    return 0;
}


