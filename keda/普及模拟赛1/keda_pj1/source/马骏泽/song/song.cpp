#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
unordered_map<char,int> a;
string s;
ll n,m,ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i+=2){
		a[s[i]]=s[i+1]-48;	
	}
	cin>>n;
	ll len=s.size();
	for(int i=1;i<=len/2;i++){
		if(n-=a[s[i]]<0){
			cout<<s[i];
			return 0;
		}
		n-=a[s[i]];
	}
	return 0;
}
