#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
string s;
char c[N+10];
int x,a[N+10],len,n;
void cs(){
	for(int i=0;i<s.size();i++){
		//cout<<i<<" "<<s[i]<<endl;
		c[n]=s[i];
		i++;
		int cnt=0;
		while('0'<=s[i]&&s[i]<='9'){
			cnt=cnt*10+s[i]-'0';
			i++;
		}
		i--;
		a[n]=cnt;
		n++;
		len+=cnt;
	}
}
int main(){
	freopen("song.in","r",stdin);
	freopen("song.out","w",stdout);
	cin>>s>>x;
	cs();
	x=x%len;
	/*
	for(int i=0;i<n;i++){
		cout<<c[i]<<" "<<a[i]<<endl;
	}
	*/
	for(int i=0;i<n;i++){
		if(x>a[i]){
			x-=a[i];
		}
		else{
			cout<<c[i];
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
/*
a4b1c2d10
100
*/
