#include <bits/stdc++.h>
using namespace std;

long long merge_and_count(vector<int> &vec, int l, int mid, int r)
{
    vector<int> temp;
    int i = l, j = mid + 1;
    long long inv = 0;

    while (i <= mid && j <= r)
    {
        if (vec[i] <= vec[j])
        {
            temp.push_back(vec[i]);
            i++;
        }
        else
        {
            temp.push_back(vec[j]);
            // All remaining elements in left part [i..mid] form inversions with vec[j]
            inv += (mid - i + 1);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(vec[i]);
        i++;
    }
    while (j <= r)
    {
        temp.push_back(vec[j]);
        j++;
    }

    // Copy back to vec
    for (int k = 0; k < (int)temp.size(); k++)
    {
        vec[l + k] = temp[k];
    }

    return inv;
}

long long countinv(vector<int> &vec, int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) / 2;
    long long inv = 0;
    inv += countinv(vec, l, mid);
    inv += countinv(vec, mid + 1, r);
    inv += merge_and_count(vec, l, mid, r);
    return inv;
}

int main()
{
    vector<int> vec = {2, 4, 1, 3, 5};
    cout << countinv(vec, 0, (int)vec.size() - 1) << '\n'; // should print 3
    return 0;
}
