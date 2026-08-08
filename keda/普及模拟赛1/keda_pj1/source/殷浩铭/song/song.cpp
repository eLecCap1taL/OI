#include<bits/stdc++.h>
using namespace std;
struct node{
	char ch;
	long long num;
}a[200010];
string s;
long long c,t,cnt;
int main()
{
	freopen("song.in","r",stdin);
	freopen("song.out","w",stdout);
	cin>>s>>c;
	int i=0;
	while(i<s.size()){
		char ch=s[i];
		i++;
		long long sum=0;
		while(i<s.size()&&s[i]>='0'&&s[i]<='9'){
			sum=sum*10+(s[i]-'0');
			i++;
		}
		a[cnt].ch=ch;
		a[cnt].num=sum;
		cnt++;
		t+=sum;
	}	
	long long p=c%t;
	for(int j=0;j<cnt;j++)
	{
		if(p<a[j].num)
		{
			cout<<a[j].ch<<endl;
			return 0;
		}
		p-=a[j].num;
	}
	return 0;
}
