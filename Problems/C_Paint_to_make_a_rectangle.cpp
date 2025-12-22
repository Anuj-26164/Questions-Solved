#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool possible = true;
    int h, w;
    cin >> h >> w;
    vector<string> rect(h);
    for (auto &c : rect) {
        cin >> c;
    }

    vector<pair<int, int>> idxmax(h, {-1, -1});
    for (int j = 0; j < h; j++) {
        int k = 0;
        for (int i = 0; i < w; i++) {
            if (rect[j][i] == '#') {
                if (k == 0)
                    idxmax[j].first = i; 
                else
                    idxmax[j].second = i;
                k++;
            }
        }
    }

    int z = -1, y = -1;
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < h; i++) {
        if (idxmax[i].first != -1) {
            z = (z == -1 ? i : z); 
            y = i;                 
            mini = min(mini, idxmax[i].first);
            maxi = max(maxi, idxmax[i].second);
        }
    }

    for (int i = z; i <= y; i++) {
        for (int j = mini; j <= maxi; j++) {
            if (rect[i][j] == '.') {
                possible = false;
                break;
            }
        }
        if (!possible) {
            break;
        }
    }

    cout << (possible ? "Yes" : "No");

    return 0;
}
