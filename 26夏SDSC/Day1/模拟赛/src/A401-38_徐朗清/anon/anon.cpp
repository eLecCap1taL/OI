#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<stdio.h>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
#define ll long long
using namespace std;
const int N=5e2+5;
int n,m,uni,tot;
int a[N][N],ans[N][N];
int vis[N],cnt[N];
void change(int sx,int sy,int s1x,int e1x,int s1y,int e1y,int add) {
//	cout<<sx<<" "<<sy<<" "<<s1x<<" "<<e1x<<" "<<s1y<<" "<<e1y<<" "<<add<<endl;
	for(int i=sx; i<=s1x-1; i++)
		for(int j=s1y; j<=e1y; j++) {
			int now=a[i][j];
			if(add==1) {
				if(vis[now]!=uni) cnt[now]=1,tot++;
				else cnt[now]+=add;
				vis[now]=uni;
			} else {
				cnt[now]+=add;
				if(cnt[now]==0) vis[now]=0,tot--;
			}
		}
	for(int i=s1x; i<=e1x; i++)
		for(int j=sy; j<=e1y; j++) {
			int now=a[i][j];
			if(add==1) {
				if(vis[now]!=uni) cnt[now]=1,tot++;
				else cnt[now]+=add;
				vis[now]=uni;
			} else {
				cnt[now]+=add;
				if(cnt[now]==0) vis[now]=0,tot--;
			}
		}
}
void solve(int x,int y) {
	int pre_x=x,pre_y=y;
	uni++,tot=1;
	cnt[a[x][y]]=1,vis[a[x][y]]=uni;
	int l=0,r=n,mid,ret=0;
//	cout<<"solve: "<<x<<" "<<y<<endl;
//	cout<<"uni_is: "<<uni<<endl;
	while(l<=r) {
		mid=(l+r)>>1;
//		cout<<"mid_is: "<<mid<<endl;
//		cout<<"ans_is: "<<ret<<endl;
		if(x+mid>n||y+mid>n) {
			r=mid-1;
			continue;
		}
		int new_x=x+mid,new_y=y+mid;
		if(pre_x>new_x)change(x,y,new_x+1,pre_x,new_y+1,pre_y,-1);
		else 		   change(x,y,pre_x+1,new_x,pre_y+1,new_y,1);
		pre_x=new_x,pre_y=new_y;
//		cout<<tot<<endl;
		if(tot<=m) ret=mid,l=mid+1;
		else r=mid-1;
//		cout<<"stat_is:"<<endl;
//		for(int i=1;i<=n;i++) cout<<vis[i]<<' ';
//		cout<<endl;
//		for(int i=1;i<=n;i++) cout<<cnt[i]<<' ';
//		cout<<endl;
//		cout<<endl;
	}
	ans[x][y]=ret;
}
int main() {
//	freopen("anon.in","r",stdin);
//	freopen("anon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>a[i][j];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			solve(i,j);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			cout<<ans[i][j]+1<<" ";
		cout<<endl;
	}
	return 0;
}
/*
5 4
1 2 3 3 2
4 5 1 3 1
2 3 5 5 5
5 3 1 2 3
3 3 3 1 2
*/
