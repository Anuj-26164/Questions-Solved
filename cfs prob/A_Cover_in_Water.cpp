#include <bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int i=0;i<n;i++)
#define lli long long int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t; // Number of test cases
    
    while (t--) {
        int n, dotcounter = 0;
        cin >> n;
        string s;
        cin >> s; // Read the entire string directly
        
        bool found = false; // Flag to check if three consecutive dots are found
        for(int i = 0; i < n - 2; i++) {
            if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.') {
                cout << "2" << endl;
                found = true;
                break; // Exit the loop if the condition is met
            }
        }
        
        if (!found) {
            // If no three consecutive dots are found, output the count of single dots
            for(int i = 0; i < n; i++) {
                if(s[i] == '.') {
                    dotcounter++;
                }
            }
            cout << dotcounter << endl;
        }
    }
    return 0;
}
