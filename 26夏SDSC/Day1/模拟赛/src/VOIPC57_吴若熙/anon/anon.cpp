#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ft first
#define sd second
using namespace std;
const ll N=505;
mt19937_64 rd(time(0));
ll n,ans,shu[N][N],sum[N],a[N][N],k,sh[N][N],zo[N][N];
void solve(ll i,ll l,ll r){
	for(int p=l;p<=r;p++){
		sum[a[i][p]]++;
		if(sum[a[i][p]]==1)ans++;
	}
}
void solve2(ll i,ll l,ll r){
	for(int p=l;p<=r;p++){
		sum[a[p][i]]++;
		if(sum[a[p][i]]==1)ans++;
	}
}
void shanha(ll i,ll l,ll r){
	for(int p=l;p<=r;p++){
		sum[a[i][p]]--;
		if(sum[a[i][p]]==0)ans--;
	}
}
void shanlie(ll i,ll l,ll r){
	for(int p=l;p<=r;p++){
		sum[a[p][i]]--;
		if(sum[a[p][i]]==0)ans--;
	}
}
void sub1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sh[i][j]=sh[i-1][j];
			if(a[i][j]==1)sh[i][j]++;
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			zo[i][j]=zo[i][j-1];
			if(a[i][j]==1)zo[i][j]++;
		}
	}ans=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ll se=a[i][j];ans=1;
			for(int p=1;p<=n;p++){
				ll ha=i+p-1,li=j+p-1;
				if(ha>n||li>n)break;
				if(k==1){
					ll x=sh[ha][li]-sh[i-1][li];
					if((se==1&&x!=ha-i+1)||(se==2&&x))ans=k+1;
					x=zo[ha][li]-zo[ha][j-1];
					if((se==1&&x!=li-j+1)||(se==2&&x))ans=k+1;
				}
				if(ans>k)break;
				shu[i][j]=p;
			}
			cout<<shu[i][j]<<' ';
		}
		cout<<endl;
	}
}
int main(){
 	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>n>>k;ll bo=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]>2)bo=1;
		}
	}
	if(!bo){
		sub1();
		return 0;
	}
	for(int i=1;i<=n;i++){
		ll r=0;
		for(int j=1;j<=1;j++){
			for(int p=1;p<=n;p++)sum[p]=0;ans=0;
			for(int p=1;p<=n;p++){
				ll ha=i+p-1,li=j+p-1;
				if(ha>n||li>n)break;
				solve(ha,j,li-1);
				solve2(li,i,ha);
				if(ans>k){
					shanha(ha,j,li-1);
					shanlie(li,i,ha);
					break;
				}
				shu[i][j]=p;r=p;
			}
			cout<<shu[i][j]<<' ';
		}
		for(int j=2;j<=n;j++){
			if(j+r-1>n){
				shanlie(j-1,i,i+r-1);
				shanha(i+r-1,j,j+r-2);
				shu[i][j]=--r;
				cout<<shu[i][j]<<' ';continue;
			}
			shanlie(j-1,i,i+r-1);
			solve2(j+r-1,i,i+r-1);
			if(ans>k){
				shanha(i+r-1,j,j+r-2);
				shanlie(j+r-1,i,i+r-1);
				shu[i][j]=--r;
				cout<<shu[i][j]<<' ';
				continue;
			}
			while(1){
				r++;
				if(i+r-1>n||j+r-1>n)break;
				solve(i+r-1,j,j+r-1);
				solve2(j+r-1,i,i+r-2);
				if(ans>k){
					shanha(i+r-1,j,j+r-1);
					shanlie(j+r-1,i,i+r-2);
					break;
				}
			}
			shu[i][j]=--r;cout<<shu[i][j]<<' ';
		}
		cout<<endl;
	}
    return 0;
}

