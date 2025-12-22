#include <bits/stdc++.h>
using namespace std;
// B
 
string s, t;
int n, m;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s >> t;
	n = s.size();
	m = t.size();
	int sok=(1<<29);
	int ls[26] = {0};
	int lt[26] = {0};
	for (int i = 0; i < 26; ++i) {
		ls[i] = lt[i] = sok;
	}
	for (int i = 1; i < n; ++i) {
		int c = s[i] - 'a';
		if (ls[c] == sok) {
			ls[c] = i;
		}
	}
	for (int i = m - 2; i >= 0; --i) {
		int c = t[i] - 'a';
		if (lt[c] == sok) {
			lt[c] = m - i;
		}
	}
	int mnm = 2*sok;
	for (int i = 0; i < 26; ++i) {
		mnm = min(mnm, ls[i] + lt[i]);
	}
	if (mnm >= sok) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < 26; ++i) {
		if (ls[i] + lt[i] == mnm) {
			string ans1 = "";
			string ans2 = "";
			ans1 += s[0];
			ans2 += t.back();
			for (int j = 1; s[j] - 'a' != i; ++j) {
				ans1 += s[j];
			}
			for (int j = m - 2; t[j] - 'a' != i; --j) {
				ans2 += t[j];
			}
			reverse(ans2.begin(), ans2.end());
			cout << ans1 << (char)('a' + i) << ans2 << "\n";
			return 0;
		}
	}
}
 
 