#include<iostream>
#include<set>
#include<algorithm>
#include<queue> 
#define MOD 998244353
#define N 500010 
#define INF 1145141919810000
using namespace std;
long long n,a[N],ans;
queue<long long>q;
int main(){
	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		long long k;
		cin>>k;
		q.push(k);
	}
	long long tk=1;
	while(q.size()>1){
		if(q.front()==tk){
			q.pop();
			q.pop();
			++ans;
		}
		else{
			q.pop();
			++tk;
		}
	}
	cout<<ans;
	return 0;
} 
/*
3
4 4
1 1 1 1 2 0 2 3 1 3 4 2 4 1 0
4 4
1 1 1 1 2 0 2 3 1 3 1 2 4 1 0 
2 1
1 0 0 1 2 1
*/
