#include <bits/stdc++.h>
using namespace std;

/*
 Segment tree where:
 - Leaves = individual cows
 - Internal nodes = fights
 - v[node] = XOR of its subtree
 While updating one cow, we replay all fights it participates in
 and count how many cows end up above it.
*/
struct SegTree
{
    vector<int> v;
    int N; // total number of cows (power of 2)

    // Initialize segment tree with size >= n
    void init(int n)
    {
        N = 1;
        while (N < n)
            N <<= 1;
        v.assign(2 * N - 1, 0);
    }

    /*
     Update position i with value val.
     lx, rx = current segment range
     node = current tree index
     depth = current depth (0 at root)
     totalDepth = n (tree height)
     Returns number of cows BELOW this cow.
    */
    int update(int lx, int rx, int node, int i, int val, int depth, int totalDepth)
    {
        // Leaf node (single cow)
        if (rx - lx == 1)
        {
            v[node] = val;
            return 0;
        }

        int mid = (lx + rx) / 2;
        int ans = 0;

        // Recurse into the child containing index i
        if (i < mid)
            ans = update(lx, mid, 2 * node + 1, i, val, depth + 1, totalDepth);
        else
            ans = update(mid, rx, 2 * node + 2, i, val, depth + 1, totalDepth);

        // Recompute XOR after update
        int left = v[2 * node + 1];
        int right = v[2 * node + 2];
        v[node] = left ^ right;

        // Size of opponent subtree at this level
        int opponentSize = 1 << (totalDepth - 1 - depth);

        // If cow is in left subtree
        if (i < mid)
        {
            // Left wins if left >= right (tie goes left)
            if (left >= right)
                ans += opponentSize;
        }
        // If cow is in right subtree
        else
        {
            // Right wins only if right > left
            if (right > left)
                ans += opponentSize;
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        int totalCows = 1 << n;
        vector<int> a(totalCows);
        for (int i = 0; i < totalCows; i++)
            cin >> a[i];

        SegTree st;
        st.init(totalCows);

        // Build tree with initial values
        for (int i = 0; i < totalCows; i++)
            st.update(0, totalCows, 0, i, a[i], 0, n);

        while (q--)
        {
            int id, x;
            cin >> id >> x;
            id--; // convert to 0-index

            // Apply potion
            int below = st.update(0, totalCows, 0, id, x, 0, n);

            // Total cows above = (totalCows - 1) - below
            cout << (totalCows - 1 - below) << '\n';

            // Restore original value
            st.update(0, totalCows, 0, id, a[id], 0, n);
        }
    }

    return 0;
}
