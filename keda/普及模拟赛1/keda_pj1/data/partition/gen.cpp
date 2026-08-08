#include<bits/stdc++.h>
using namespace std;
#define rnd(x) (1ll*rand()*rand()%(x)+1)
const int N=1e6+7;
int f[N],g[N];
void solve1(){
	int T=10;
	cout<<T<<endl;
	map<pair<int,int>,int>F;
	while(T--){
		int n=rnd(1000);
		cout<<n<<endl;
		while(n--){
			int a=rnd(1000000000),b=rnd(1000000000);
			while(F[make_pair(a,b)]) a=rnd(1000000000),b=rnd(1000000000);
			F[make_pair(a,b)]=1;
			cout<<a<<" "<<b<<endl;
		}
	}
}
void solve2(){
	int T=10;
	cout<<T<<endl;
	map<pair<int,int>,int>F;
	map<int,int>G,H;
	while(T--){
		int n=100000;
		cout<<n<<endl;
		int C=rnd(12345678);
		G.clear();
		F.clear();
		H.clear();
		cout<<1<<" "<<1<<endl;
		cout<<0<<" "<<2<<endl;
		F[make_pair(1,1)]=1;
		F[make_pair(0,2)]=1;
		n-=2;
		while(n--){
			int a=rnd(100000000),b=rnd(100000000);
			while(F[make_pair(a,b)]||G[a+b]||H[a-b]) a=rnd(100000000),b=rnd(100000000);
			G[a+b]=1;
			H[a-b]=1;
			F[make_pair(a,b)]=1;
			cout<<a<<" "<<b<<endl;
		}
	}
}
void solve3(){
	int T=10;
	cout<<T<<endl;
	map<pair<int,int>,int>F;
	map<int,int>G,H;
	while(T--){
		int n=100000;
		cout<<n<<endl;
		int C=rnd(12345678);
		G.clear();
		F.clear();
		H.clear();
		cout<<2<<" "<<0<<endl;
		cout<<3<<" "<<1<<endl;
		F[make_pair(2,0)]=1;
		F[make_pair(3,1)]=1;
		n-=2;
		while(n--){
			int a=rnd(100000000),b=rnd(100000000);
			while(F[make_pair(a,b)]||G[a+b]||H[a-b]) a=rnd(100000000),b=rnd(100000000);
			G[a+b]=1;
			H[a-b]=1;
			F[make_pair(a,b)]=1;
			cout<<a<<" "<<b<<endl;
		}
	}
}
void solve4(){
	int n=200;
	cout<<n<<endl; int x=rand()%1000+1;
	for(int i=1;i<=n/2;i++) cout<<i+x<<" ";
	for(int i=n/2+1;i<=n;i++) cout<<rand()%10000+1<<" "; cout<<endl; 
}
int main(){
	freopen("7.in","w",stdout),solve4(); 
	freopen("8.in","w",stdout),solve4(); 
	freopen("9.in","w",stdout),solve4(); 
	freopen("10.in","w",stdout),solve4(); 
}
