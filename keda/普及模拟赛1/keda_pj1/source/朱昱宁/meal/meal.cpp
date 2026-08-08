#include <bits/stdc++.h>
using namespace std;
int n;
struct ren {
	int a, b;
}a[510];
bool cmp(ren A, ren B) { return A.b > B.b; }
deque< pair<int, int> > q1, q2;
int c1, c2, chi, ans;
int main() {
	freopen("meal.in", "r", stdin);
	freopen("meal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i].a >> a[i].b;
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		if (c2 >= c1) {
			c1 += a[i].a;
			q1.push_back({a[i].a, a[i].b});
		} else {
			c2 += a[i].a;
			q2.push_back({a[i].a, a[i].b});
		}
	}
	while (!q1.empty() || !q2.empty()) {
		int tmp;
		if (!q1.empty() && !q2.empty()) {
			if (q1.front().first == q2.front().first) {
				tmp = q1.front().first;
				ans += tmp;
				chi = max(0, chi - tmp);
				chi = max(chi, max(q1.front().second, q2.front().second));
				q1.pop_front();
				q2.pop_front();
			} else if (q1.front().first < q2.front().first) {
				tmp = q1.front().first;
				ans += tmp;
				chi = max(0, chi - tmp);
				chi = max(chi, q1.front().second);
				q1.pop_front();
				int p1 = q2.front().first - tmp, p2 = q2.front().second;
				q2.pop_front();
				q2.push_front({p1, p2});
			} else {
				tmp = q2.front().first;
				ans += tmp;
				chi = max(0, chi - tmp);
				chi = max(chi, q2.front().second);
				q2.pop_front();
				int p1 = q1.front().first - tmp, p2 = q1.front().second;
				q1.pop_front();
				q1.push_front({p1, p2});
			}
		} else if (!q1.empty()) {
			tmp = q1.front().first;
			ans += tmp;
			chi = max(0, chi - tmp);
			chi = max(chi, q1.front().second);
			q1.pop_front();
		} else {
			tmp = q2.front().first;
			ans += tmp;
			chi = max(0, chi - tmp);
			chi = max(chi, q2.front().second);
			q2.pop_front();
		}
	}
	ans += chi;
	cout << ans;
	return 0;
}
