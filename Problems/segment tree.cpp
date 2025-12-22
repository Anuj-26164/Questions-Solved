#include <bits/stdc++.h>
using namespace std;

struct SegTreeSum {
    int n;
    vector<long long> st;
    SegTreeSum(int _n=0){ if(_n) init(_n); }
    void init(int _n){
        n = _n;
        st.assign(4*n, 0);
    }
    void build(int node, int l, int r, const vector<long long>& a){
        if(l==r){
            st[node] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(node<<1, l, m, a);
        build(node<<1|1, m+1, r, a);
        st[node] = st[node<<1] + st[node<<1|1];
    }
    void build(const vector<long long>& a){
        init((int)a.size());
        if(n) build(1, 0, n-1, a);
    }
    void update(int node, int l, int r, int idx, long long val){
        if(l==r){
            st[node] = val;
            return;
        }
        int m = (l + r) >> 1;
        if(idx <= m) update(node<<1, l, m, idx, val);
        else update(node<<1|1, m+1, r, idx, val);
        st[node] = st[node<<1] + st[node<<1|1];
    }
    void update(int idx, long long val){ update(1, 0, n-1, idx, val); }
    long long query(int node, int l, int r, int ql, int qr){
        if(ql>r || qr<l) return 0;
        if(ql<=l && r<=qr) return st[node];
        int m = (l + r) >> 1;
        return query(node<<1, l, m, ql, qr) + query(node<<1|1, m+1, r, ql, qr);
    }
    long long rangeSum(int l, int r){ return query(1, 0, n-1, l, r); }
};

// Usage:
// vector<long long> a = { ... };
// SegTreeSum st; st.build(a);
// st.update(pos, newVal);
// long long s = st.rangeSum(l, r);