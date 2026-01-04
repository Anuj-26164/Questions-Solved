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
        vector<vector<string>> wordSquares(vector<string> &words)
        {
            int n = words.size();
            vector<vector<string>> ans;
            vector<string> temp;
            vector<bool> used(n, false);
            for (int first = 0; first < n; first++)
            {
                temp.push_back(words[first]);
                used[first] = true;
                for (int second = 0; second < n; second++)
                {
                    if (used[second])
                        continue;
                    else if (words[second][0] == temp[0][0])
                    {
                        temp.push_back(words[second]);
                        used[second] = true;
                        for (int third = 0; third < n; third++)
                        {
                            if (used[third])
                                continue;
                            else if (words[third][0] == temp[1][3])
                            {
                                temp.push_back(words[third]);
                                used[third] = true;
                                for (int fourth = 0; fourth < n; fourth++)
                                {
                                    if (used[fourth])
                                        continue;
                                    else if ((words[fourth][0] == temp[2][3]) && (words[fourth][3] == temp[3][3]))
                                    {
                                        temp.push_back(words[fourth]);
                                        ans.push_back(temp);
                                        temp.pop_back();
                                    }
                                }
                                used[third] = false;
                                temp.pop_back();
                            }
                        }
                        used[second] = false;
                        temp.pop_back();
                    }
                }
                used[first] = false;
                temp.pop_back();
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
    };