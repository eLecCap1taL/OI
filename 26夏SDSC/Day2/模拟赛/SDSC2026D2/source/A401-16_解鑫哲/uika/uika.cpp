#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
const int N = 2000006;
int T,n,k,t,m,b[N],d[N];
bool isd[N];
int main(){
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&m);
		t = k/2;
		for(int i = 1;i <= m;i++)
			scanf("%d",b[i]);
		if((n-m)%(k-1) != 0)
			printf("NO\n"); 
		int j = 1,cnt = 0;
		for(int i = 1;i <= n;i++){
			d[i] = d[i-1];
			if(b[j] == i)	j++;
			else	d[i]++,isd[i] = true;
		}
		printf("YES\n");
	} 
	return 0;
}
/*
什么时候删不掉？删除量不是(k-1)的倍数时；删除条件冲突时。 
设t=k/2(下取整),则删除规则为，选定一个数字，可删除其前任意t个数字和其后任意t个数字 
看到部分分，操作最多有两次， 
*/ 
