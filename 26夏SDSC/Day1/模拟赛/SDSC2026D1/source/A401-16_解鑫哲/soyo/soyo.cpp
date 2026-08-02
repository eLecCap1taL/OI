#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
const int N = 300005;
const int mod = 998244353;
int n;
ll f[N][2];	//chain的动规 
ll ans = 0;
bool vis[N];
int minn[N],maxx[N];
vector<PII>edge[N];
void dfs(int i){
	printf("Now it's %d,minn=%d,maxx=%d\n",i,minn[i],maxx[i]);
	if(i == n+1){
		ans = (ans+1)%mod;
		printf("%d ended.\n",i);
		printf("Ans++;\n");
		return;
	}
	vis[i] = true;
	//首先让它完全内敛 
	queue<int>lm;	//last_minn
	int sim = 0;	//start_i_minn
	for(int t = 0;t < edge[i].size();t++){
		PII ti = edge[i][t];
		int num = ti.x;
		int j = ti.y;
		lm.push(minn[j]);
		if(minn[j] == 0)
			minn[j] = num;
		minn[j] = min(minn[j],num);
		if(maxx[j] != 0 && minn[j] >= maxx[j])
			sim = num;
	}
	if(minn[i] == 0){
		printf(" - line 0\n");
		dfs(i+1);
	}
	//然后从最小边开始逐渐开放向外,vis标记的不会造成影响 
	//每开放一个,意味着被指者的向外出边是有限制了的,获得一个maxx,到达这个maxx就停止 
	//直到达到自身的限制 
	//自身所获得的入边被进入maxx,于是不可能到达maxx即所有入边被保护
	//但是问题在于那些入边本身对其他节点也有影响,即强制成为出边
	//强制成为出边,如果大于了其maxx,就是失败的,必须到这个地方才可以开始
	//如果没有大于其maxx,也是有问题的,我们或许有必要设置一个minn,表示强制开启的出边位置 
	queue<int>lmax;	//last_maxx
	for(int t = 0;t < edge[i].size();t++){
		PII ti = edge[i][t];
		int num = ti.x;
		int j = ti.y;
		minn[j] = lm.front();
		lm.pop();
		if(num < minn[i] || num <= sim)
			continue;
		if(maxx[i] != 0 && num >= maxx[i])
			continue;	//为了还原minn 
		printf(" - line %d\n",num);
		lmax.push(maxx[j]);
		maxx[j] = max(maxx[j],num);
		dfs(i+1);
	}
	for(int t = 0;t < edge[i].size();t++){
		PII ti = edge[i][t];
		int num = ti.x;
		int j = ti.y;
		if(num < minn[i] || num < sim)
			continue;
		if(maxx[i] != 0 && num >= maxx[i])
			continue; 
		maxx[j] = lmax.front();
		lmax.pop();
	}
	vis[i] = false;
	printf("%d ended.\n",i);
	return;
}
int main(){
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	bool is_flower = true;
	bool is_chain = true;
	scanf("%d",&n);
	for(int i = 1;i < n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x != n && y != n)
			is_flower = false;
		if((x != i && y != i) || (x != i+1 && y != i+1))
			is_chain = false;
		edge[x].push_back({i,y});
		edge[y].push_back({i,x});
	}
	for(int i = 1;i <= n;i++){
		sort(edge[i].begin(),edge[i].end());
	}
	if(is_flower){
		printf("%d",n);
		return 0;
	} 
	if(is_chain){
		f[1][0] = f[1][1] = 1;
		for(int i = 2;i <= n-1;i++){
			f[i][0] = (f[i-1][0] + f[i-1][1])%mod;
			f[i][1] = f[i-1][0];
			//0:i+1->i,1:i->i+1
		}
		printf("%lld",(f[n-1][0]+f[n-1][1])%mod);
		return 0;
		//我们是不是也可以树上dp呢？但是不大会想 
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
/*
4
1 3
1 2
3 4
*/
