// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
// #include <bits/stdc++.h>
// using namespace std;

class Solution
{
public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // code here
        double totalVal = 0;
        int n = val.size();
        vector<pair<double, int>> vp;
        for (int i = 0; i < n;i++)
        {
            vp.push_back({double(val[i]) / double(wt[i]), i});
        }
        sort(vp.begin(), vp.end(), greater<>());
        for(auto c:vp)
        {
            if(wt[c.second]<=capacity)
            {
                totalVal += val[c.second];
                capacity -= wt[c.second];
            }
            else
            {
                totalVal += (val[c.second] * capacity / wt[c.second]);
                break;
            }
        }
        return totalVal;
    }
};
