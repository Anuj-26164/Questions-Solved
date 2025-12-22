// Qs: leetcode
// Time: 20:30:57

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k,n) for(int i=k;i<n;i++)
#define nl '\n'
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            ll lo=0,hi=nums.size()-1,mid;
            while(hi-lo>1)
            {
                mid=lo+(hi-lo)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target)
                {
                    hi=mid;
                }
                else
                {
                    lo=mid;
                }
            }
            if(nums[hi]==target) return hi;
            if(nums[lo]==target) return lo;
            else return -1;
            
        }
    };