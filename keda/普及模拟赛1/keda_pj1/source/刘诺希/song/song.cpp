#include<bits/stdc++.h>
using namespace std;
string s;
long long c;
struct node{
	char ch;
	long long cnt;
};
node a[200005];
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>c;
	int n=0;
	char ch;
	long long num=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z'){
			if(num>0){
				a[n].cnt=num;
				n++;
				num=0;
			}
			ch=s[i];
			a[n].ch=ch;
		}
		else{
			num=num*10+(s[i]-'0');
		}
	}
	a[n].cnt=num;
	n++;
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i].cnt;
	}
	c=c%sum;
	for(int i=0;i<n;i++){
		if(c<a[i].cnt){
			cout<<a[i].ch;
			return 0;
		}
		c-=a[i].cnt;
	}
	return 0;
}

