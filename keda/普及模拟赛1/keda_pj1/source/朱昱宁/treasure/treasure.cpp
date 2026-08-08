#include <bits/stdc++.h>
using namespace std;
int n, m, mp[110][110], len;
string str;
int ans;
int hx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, hy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int pd(bool used, int type, int x, int y, int pos) {
	if(pos == len - 1)
		return 1;
	int res = 0;
	int nxtpos = pos + 1;
	int nx = x + hx[type];
	int ny = y + hy[type];
	if(nx >= 1 && nx <= n && ny >= 1 && ny <= m)
		if(mp[nx][ny] == str[nxtpos])
			res += pd(used, type, nx, ny, nxtpos);
	if(!used)
		for(int d = 0; d < 8; d++) {
			if(hx[type] * hx[d] + hy[type] * hy[d] != 0) continue;
			int nx2 = x + hx[d];
			int ny2 = y + hy[d];
			if(nx2 >= 1 && nx2 <= n && ny2 >= 1 && ny2 <= m)
				if(mp[nx2][ny2] == str[nxtpos])
					res += pd(true, d, nx2, ny2, nxtpos);
		}
	return res;
}
int main() {
	freopen("treasure.in", "r", stdin);
	freopen("treasure.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> str >> n >> m;
	len = str.size();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ) {
			char ch = getchar();
			if (ch >= 'A' && ch <= 'Z')
				mp[i][j++] = ch;
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (mp[i][j] == str[0]) {
				for (int l = 0; l < 8; ++l) {
					int nx = i + hx[l];
					int ny = j + hy[l];
					if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
					if(mp[nx][ny] == str[1]) {
						ans += pd(false, l, nx, ny, 1);
					}
				}
			}
	cout << ans;
	return 0;
}
