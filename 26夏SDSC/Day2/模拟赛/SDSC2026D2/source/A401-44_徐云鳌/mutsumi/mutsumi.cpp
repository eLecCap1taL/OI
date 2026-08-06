#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 810;
int f[maxn][maxn],dp[maxn],n,a[maxn];

signed main()
{
	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	memset(f,0x3f,sizeof(f));
	for(int len = 2;len <= n;len += 2)
		for(int l = 1;l + len - 1 <= n;l++)
		{
			int r = l+ len-1;
			if(a[l] > l || (l -a[l]) & 1) continue;
			int val = (l -a[l])/2;
			
			// 考虑实际上转移不止前面一种
			// 你可以删掉两个端点
			if(f[l+1][r-1] <= val) f[l][r] = val; 
			
			if(len == 2) f[l][r] = val;
			for(int k= l+1;k <= r-1;k +=2) f[l][r] = min(f[l][r],max({val,f[l][k],f[k+1][r] - (k - l + 1) / 2}));
		}
		
	for(int i = 1;i<=n;i++) 
	{
		dp[i] = max(dp[i],dp[i -1]);
		for(int o = 1;i - 2*o + 1 > 0;o++)
		{
			int ql = i- 2*o;
			if(dp[ql] >= f[ql+1][i]) dp[i] =max(dp[i],dp[ql]+o);
		}
	}
	cout << dp[n];
	return 0;
}

// 考虑删除的形式实际上类似一段区间
// 你发现你希望删除 i,j，那么要求中间全部删掉
// 并且你需要前缀 i - a[i]来把你这个 i 减小
// 考虑设 f[l][r] 表示说你删空这个区间前缀最少要删多少个，设一个 dp[i] 表示 i 前缀能删最多多少个数
// 统计答案是好做的，你只需要对 dp 做转移，每次枚举一个后缀 check 能不能删掉这个后缀
// 那你怎么转移 f
// 枚举 r 和哪个一起删掉，那么贡献实际上shi
// (l - a[l]) / 2
// f[l][k]
// f[k+1][r] - k-l+1/2

// 然后是不是就做完了

// 哦他妈的糖丸了，为什么还有端点会转移啊 
