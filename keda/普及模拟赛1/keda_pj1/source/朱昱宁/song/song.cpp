#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int c, len, true_len;
int zhao(int start) {
	int res = 0;
	for (int i = start; i < len; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			res = res * 10 + (s[i] - '0');
		else
			break;
	}
	return res;
}
signed main() {
	freopen("song.in", "r", stdin);
	freopen("song.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> c;
	len = s.size();
	++c;
	for (int i = 0; i < len; ++i)
		if (s[i] >= 'a' && s[i] <= 'z') {
			int count = zhao(i + 1);
			true_len += count;
			if (c <= count) {
				cout << s[i];
				return 0;
			}
			c -= count;
		}
	c %= true_len;
	for (int i = 0; i < len; ++i)
		if (s[i] >= 'a' && s[i] <= 'z') {
			int count = zhao(i + 1);
			if (c <= count) {
				cout << s[i];
				return 0;
			}
			c -= count;
		}
	return 0;
}
