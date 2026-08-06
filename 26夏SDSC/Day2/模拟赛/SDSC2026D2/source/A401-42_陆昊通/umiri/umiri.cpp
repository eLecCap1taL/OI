#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
using namespace std;
const ll N=1e6+5,mod=998244353,INF=0x3f3f3f3f3f3f3f3f;
ll n,m,k,ans,T;
struct dat{
	ll l,r,x;
	bool operator<(const dat &s) const{
		return l<s.l;
	}
};
set<dat> h;
ll a[N],b[N];
vector<dat> er,cr; 
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("umiri.in","r",stdin);
//	freopen("rand.in","r",stdin);
	freopen("umiri.out","w",stdout);
	cin>>n>>T;
	h.insert({1,n,0});
	while(T--){
		ll a,b;
		cin>>a>>b;
		er.clear();cr.clear();
		auto it=h.upper_bound({a,0,0});
		it--;
		auto qj=(*it);
		if(qj.r>a){
			cr.pb({a+1,qj.r,qj.x});
			qj.r=a;
		} 
//		cout<<qj.l<<" "<<qj.r<<endl;
		er.pb((*it));
		ll cnt=0;
		dat qqj={0,0,0};
		while(it!=h.begin()){
			auto iit=it;
			iit--;
			if( ((*iit).x-qj.x)*(qj.r-qj.l+1)<=b ){
				b-=((*iit).x-qj.x)*(qj.r-qj.l+1);
				it--;er.pb((*it));
				qj.l=(*iit).l,qj.x=(*iit).x;
			}
			else{
				qj.x+=b/(qj.r-qj.l+1);
				b%=(qj.r-qj.l+1);
				if(b){
					cnt=1;
					qqj.l=qj.l+b;qqj.r=qj.r,qqj.x=qj.x;
					qj.r=qj.l+b-1,qj.x++;
				}
				b=0;break;
			}
		}
		qj.x+=b/(qj.r-qj.l+1);
		b%=(qj.r-qj.l+1);
		if(b){
			cnt=1;
			qqj.l=qj.l+b;qqj.r=qj.r,qqj.x=qj.x;
			qj.r=qj.l+b-1,qj.x++;
		}
		cr.pb(qj);
		if(cnt) cr.pb(qqj);
		for(auto j:er){
			h.erase(j);
//			cout<<j.l<<" "<<j.r<<" "<<j.x<<endl;
		} 
//		cout<<endl;
		for(auto j:cr){
			h.insert(j);
//			cout<<j.l<<" "<<j.r<<" "<<j.x<<endl;
		} 
//		for(auto it=h.begin();it!=h.end();it++){
//			for(int i=1;i<=(*it).r-(*it).l+1;i++) cout<<(*it).x<<' ';
//		}
//		cout<<endl;
	}
	for(auto it=h.begin();it!=h.end();it++){
		for(int i=1;i<=(*it).r-(*it).l+1;i++) cout<<(*it).x<<endl;
	}
	return 0;
}

