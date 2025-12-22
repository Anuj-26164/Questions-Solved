#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    long long ans = 0;
    int l = 0;
    int cntB = 0;
    deque<int> posA; // stores positions of 'a' in current window

    for (int r = 0; r < N; r++)
    {
        // expand window to the right
        if (S[r] == 'a')
        {
            posA.push_back(r);
        }
        else
        {
            cntB++;
        }

        // shrink window until count(b) < B
        while (cntB >= B)
        {
            if (S[l] == 'a')
            {
                posA.pop_front();
            }
            else
            {
                cntB--;
            }
            l++;
        }

        // now cntB < B is satisfied
        if (posA.size() >= A)
        {
            // position of the A-th 'a' from the left
            int idx = posA[posA.size() - A];
            ans += (idx - l + 1);
        }
    }

    cout << ans << "\n";
    return 0;
}
