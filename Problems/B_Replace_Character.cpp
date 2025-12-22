#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define lli long long int
#define forl for (int i = 0; i < n; i++)
#define nl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int arr[26] = {0};

        for (int i = 0; i < n; i++)
        {
            arr[s[i] - 'a']++;
        }

        int maxoccurance = *max_element(arr, arr + 26);
        char maxChar = 'a' + distance(arr, max_element(arr, arr + 26));

        int minoccurance = INT_MAX;
        char minChar = '\0';
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] > 0 && arr[i] <= minoccurance)
            {
                minoccurance = arr[i];
                minChar = 'a' + i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == minChar)
            {
                s[i] = maxChar;
                break;
            }
        }

        cout << s << nl;
    }
    return 0;
}
