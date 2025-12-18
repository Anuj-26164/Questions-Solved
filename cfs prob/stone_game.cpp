#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
    {
        vector<pair<int,int>> totalValues;
        for (int i = 0; i < aliceValues.size();i++)
        {
            totalValues.push_back({aliceValues[i] + bobValues[i],i});
        }
        sort(totalValues.begin(), totalValues.end(), greater<int>());
        int aScore = 0, bScore = 0;
        for (int i = 0; i < aliceValues.size(); i++)
        {
            if(i%2==0)
            {
                aScore += totalValues[i].first-bobValues[i];
            }
            else
                bScore += totalValues[i].first-aliceValues[i];
        }
        if(aScore>bScore)
            return 1;
        else if(aScore<bScore)
            return -1;
        else
            return 0;
    }
};