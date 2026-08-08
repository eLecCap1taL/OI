#include<bits/stdc++.h>
#define ll long long
#define u64 unsigned long long

using namespace std;
string s;
ll cnl[200010],cnr[200010],tp,lin;
ll c;
char ch[200010];
ll getnumber(int x){
	ll sum=s[x]-'0';
	while(x<lin&&'0'<=s[x+1]&&s[x+1]<='9'){
		x++;
		sum=sum*10+s[x]-'0';
	}
	return sum;
}

int main(){
	freopen("song.in","r",stdin);
	freopen("song.out","w",stdout);
	cin>>s;
	lin=s.size();
	int r=1;
	for(int i=0;i<lin;i++){
		if('a'<=s[i]&&s[i]<='z'){
			ch[++tp]=s[i];
			cnl[tp]=r;
			cnr[tp]=r+getnumber(i+1)-1;
			r=cnr[tp]+1;
		//	cout<<cnl[tp]<<' '<<cnr[tp]<<' '<<ch[tp]<<endl;
		}
	}
	cin>>c;
	c++; 
	c%=cnr[tp];
	for(int i=1;i<=tp;i++){
		if(cnl[i]<=c&&c<=cnr[i]){
			cout<<ch[i];
			return 0;
		}
	}
	return 0;
}

