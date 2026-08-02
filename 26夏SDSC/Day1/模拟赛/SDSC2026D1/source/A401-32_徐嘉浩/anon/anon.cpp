#include <iostream>

using std::cin;
using std::cout;
const int N = 510;

int tot;
int cnt[N];
int a[N][N];
int ans[N][N];

int main()
{
	freopen("anon.in", "r", stdin);
	freopen("anon.out", "w", stdout);
	int n, K;
	cin >> n >> K;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	}
	for (int i = 1; i <= n; ++i)
	{
		int k = 1;
		int j = 1;
		for (int j = 1; j <= n; ++j)
			cnt[j] = 0;
		cnt[a[i][j]]++;
		tot = 1;
		while (i + k - 1 < n && j + k - 1 < n && tot <= K)
		{
			k++;
			for (int l = j; l <= j + k - 2; ++l)
				tot += (!(cnt[a[i + k - 1][l]]++));
			for (int l = i; l <= i + k - 1; ++l)
				tot += (!(cnt[a[l][j + k - 1]]++));
		}
		if (tot > K)
		{
			for (int l = j; l <= j + k - 2; ++l)
				tot -= (!(--cnt[a[i + k - 1][l]]));
			for (int l = i; l <= i + k - 1; ++l)
				tot -= (!(--cnt[a[l][j + k - 1]]));
			ans[i][j] = --k;
		}
		else
			ans[i][j] = k;
		for (int j = 2; j <= n; ++j)
		{
			for (int l = j; l <= j - 1 + k - 1; ++l)
				tot -= (!(--cnt[a[i + k - 1][l]]));
			for (int l = i; l <= i + k - 1; ++l)
				tot -= (!(--cnt[a[l][j - 1]]));
			k--;
			while (i + k - 1 < n && j + k - 1 < n && tot <= K)
			{
				k++;
				for (int l = j; l <= j + k - 2; ++l)
					tot += (!(cnt[a[i + k - 1][l]]++));
				for (int l = i; l <= i + k - 1; ++l)
					tot += (!(cnt[a[l][j + k - 1]]++));
			}
			if (tot > K)
			{
				for (int l = j; l <= j + k - 2; ++l)
					tot -= (!(--cnt[a[i + k - 1][l]]));
				for (int l = i; l <= i + k - 1; ++l)
					tot -= (!(--cnt[a[l][j + k - 1]]));
				ans[i][j] = --k;
			}
			else
				ans[i][j] = k;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
/*
6 5
3 3 5 1 2 3
1 5 6 3 1 4
1 3 6 2 3 5
3 5 6 5 3 6
5 3 6 5 5 2
3 2 6 3 2 1
*/
