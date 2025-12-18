#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ll long long int
#define nl '\n'

bool canReachDestination(int n, int targetX, int targetY, const string& path) {
    // Store the net movement after one complete iteration of the path
    int netX = 0, netY = 0;
    for (char c : path) {
        switch (c) {
            case 'N': netY++; break;
            case 'S': netY--; break;
            case 'E': netX++; break;
            case 'W': netX--; break;
        }
    }
    
    // Check positions during first iteration
    int currX = 0, currY = 0;
    for (int i = 0; i < n; i++) {
        switch (path[i]) {
            case 'N': currY++; break;
            case 'S': currY--; break;
            case 'E': currX++; break;
            case 'W': currX--; break;
        }
        if (currX == targetX && currY == targetY) return true;
    }
    
    // If we have no net movement in either direction, and we didn't reach the target
    // in the first iteration, we never will
    if (netX == 0 && netY == 0) return false;
    
    // Check if target is reachable considering net movements
    // We need to consider both positive and negative net movements
    // and check if target coordinates are along the path
    if (netX != 0) {
        if ((targetX - currX) % netX != 0) return false;
        ll iterations = (targetX - currX) / netX;
        if (iterations < 0) return false;
        ll finalY = currY + iterations * netY;
        if (finalY == targetY) return true;
    }
    
    if (netY != 0) {
        if ((targetY - currY) % netY != 0) return false;
        ll iterations = (targetY - currY) / netY;
        if (iterations < 0) return false;
        ll finalX = currX + iterations * netX;
        if (finalX == targetX) return true;
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        
        cout << (canReachDestination(n, a, b, s) ? "YES" : "NO") << nl;
    }
    return 0;
}