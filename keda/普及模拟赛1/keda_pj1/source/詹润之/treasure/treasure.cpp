#include<bits/stdc++.h>
using namespace std;
const int N=100;
string s;
char c[N+10][N+10],s1[2*N+10];
int n,m,ans;
int dx[8]={1,1,1,0,-1,-1,-1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};
void check1(int x,int y,int z,int pi){
	//cout<<x<<" "<<y<<" "<<z<<" "<<pi<<endl;
	while(c[x][y]==s[pi]){
		pi++;
		if(pi==s.size()){
			//cout<<x<<" "<<y<<" "<<z<<endl;
			ans++;
			return ;
		}
		x+=dx[z];
		y+=dy[z];
		if(x>n||y>m||x<1||y<1){
			break;
		}
	}
}
void check(int x,int y,int z){
	int pi=0;
	while(c[x][y]==s[pi]){
		if(pi>=1&&pi<s.size()-1){
			check1(x,y,(z+2)%8,pi);
			check1(x,y,(z+6)%8,pi);
		}
		pi++;
		if(pi==s.size()){
			//cout<<x<<" "<<y<<" "<<z<<endl;
			ans++;
			return ;
		}
		if(x+dx[z]>n||y+dy[z]>m||x+dx[z]<1||y+dy[z]<1){
			break;
		}
		x+=dx[z];
		y+=dy[z];
	}
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	cin>>s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==s[0]){
				for(int k=0;k<8;k++){
					//cout<<i<<" "<<j<<" "<<k<<" "<<ans<<" ";
					check(i,j,k);
					//cout<<ans<<endl;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
/*
MENU
5
7
F T R U B L K
P M N A X C U
A E R C N E O
M N E U A R M
M U N E M N S
NATURE
6 9
NATSFEGQN
SAIBMRHFA
CFTJCUCLT
KBHUPTANU
DPRRRJDIR
IEEKMEGBE
*/
