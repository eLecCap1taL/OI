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
const int N=1e3+5;
int n,q;
int top[N],a[N][N];
int pre_top[N],pre_a[N][N];
int pre_use[N],use[N];
struct edge {
	int id,num;
};
bool operator<(const edge hh,const edge mm) {
	return hh.num>mm.num;
}
priority_queue<edge>q1;
void solve() {
	ll prt=0,num=0;
	while(!q1.empty()) q1.pop();
	for(int i=1; i<=n; i++) pre_use[i]=use[i]=0;
	for(int i=1; i<=n; i++)
		if(pre_top[i]==0) use[i]=1,q1.push({i,a[i][1]});
		else pre_use[i]=1,q1.push({i,pre_a[i][pre_top[i]]});
	while(!q1.empty()) {
		edge now=q1.top();
		q1.pop();
		int id=now.id,val=now.num;
//		cout<<"push_is: "<<val<<endl;
		prt=prt+num+val;
		num+=val;
//		cout<<"ans_is: "<<prt<<endl;
//		cout<<use[1]<<" "<<pre_use[1]<<endl;
		int new_id=-1,new_val;
		int rest=pre_top[id]-pre_use[id];
		int rest1=top[id]-use[id];
		if(rest>0) {
			new_id=id,new_val=pre_a[id][rest];
			pre_use[id]++;
		} else if(rest1>0) {
			new_id=id,new_val=a[id][++use[id]];
		}
		if(new_id==-1) continue;
		q1.push({new_id,new_val}); 
	}
	cout<<prt<<endl;
}
int main() {
	freopen("taki.in","r",stdin);
	freopen("taki.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>top[i];
		for(int j=1; j<=top[i]; j++)cin>>a[i][j];
	}
	solve();
	while(q--) {
		int op,x,y;
		cin>>op>>x>>y;
		if(op==0)
			pre_a[x][++pre_top[x]]=y;
		else a[x][++top[x]]=y;
		solve();
	}
	return 0;
}
/*
1 3
5 1 9 2 6 0
0 1 9
1 1 5
0 1 3
4 5
3 8 1 7
0
5 1 9 2 6 0 
6 5 7 5 7 3 3
0 3 9 
1 4 5
0 1 1 
1 2 1
0 2 7
*/
