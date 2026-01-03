#include <bits/stdc++.h>
using namespace std;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// const int MOD = 1e9 + 7;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxHere = nums[0];
        int minHere = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(maxHere, minHere);

            maxHere = max(nums[i], nums[i] * maxHere);
            minHere = min(nums[i], nums[i] * minHere);

            ans = max(ans, maxHere);
        }
        return ans;
    }
};
