#include <bits/stdc++.h>
using namespace std;

struct Node
{
    long long val;
    int id;
    Node *prev;
    Node *next;
    int ver;
    bool alive;
};

struct Item
{
    long long val;
    int ver;
    Node *node;
};

struct Cmp
{
    bool operator()(const Item &a, const Item &b) const
    {
        if (a.val != b.val)
            return a.val > b.val;       // smaller val has higher priority
        return a.node->id > b.node->id; // tie-breaker
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
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // Create nodes
        vector<Node *> nodes(n);
        for (int i = 0; i < n; i++)
        {
            nodes[i] = new Node();
            nodes[i]->val = a[i];
            nodes[i]->id = i;
            nodes[i]->ver = 0;
            nodes[i]->alive = true;
        }

        // Link them into a circular doubly linked list
        for (int i = 0; i < n; i++)
        {
            int p = (i - 1 + n) % n;
            int nx = (i + 1) % n;
            nodes[i]->prev = nodes[p];
            nodes[i]->next = nodes[nx];
        }

        priority_queue<Item, vector<Item>, Cmp> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({nodes[i]->val, nodes[i]->ver, nodes[i]});
        }

        long long cost = 0;
        int cnt = n;           // current number of nodes
        Node *head = nodes[0]; // not really needed, but nice to keep

        // Perform exactly n - 1 merges
        while (cnt > 1)
        {
            // Get current global minimum node u
            Node *u = nullptr;
            int curVer;
            long long curVal;

            while (true)
            {
                auto top = pq.top();
                pq.pop();
                Node *node = top.node;
                if (!node->alive)
                    continue; // already removed
                if (node->ver != top.ver)
                    continue; // outdated value
                u = node;
                curVer = top.ver;
                curVal = top.val;
                break;
            }

            Node *L = u->prev;
            Node *R = u->next;

            // Choose smaller neighbour
            Node *y;
            if (L->val <= R->val)
                y = L;
            else
                y = R;

            long long newVal = max(u->val, y->val);
            cost += newVal;

            // Remove u from the circular list
            Node *A = u->prev;
            Node *B = u->next;
            A->next = B;
            B->prev = A;

            u->alive = false;
            cnt--;

            if (u == head)
                head = B; // maintain a valid head pointer

            // Merge into y: update y's value and push new version in heap
            y->val = newVal;
            y->ver++;
            pq.push({y->val, y->ver, y});
        }

        cout << cost << "\n";

        // clean up allocated memory
        for (int i = 0; i < n; i++)
        {
            delete nodes[i];
        }
    }

    return 0;
}
