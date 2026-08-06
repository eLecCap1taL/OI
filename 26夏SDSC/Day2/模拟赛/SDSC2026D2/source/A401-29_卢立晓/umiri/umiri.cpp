#include<bits/stdc++.h>
using namespace std;
//#define ls (d<<1)
//#define rs ((d<<1)+1)
struct node{
	long long x,y;
}lin[1000006];
long long ans[1000006];
bool vis[1000005];
long long tree1[1000005],tree2[1000005];
//long long tree1[4000005],tree2[400005];
long long n,m;
//int lowbit(int x){
//	return x&-x;
//}
//int cha(int x){
//	long long minn=0x3f3f3f3f3f3f3f3f;
//	int z=1;
//	for(int i=x;i>=1;i-=lowbit(i)){
//		if(tree1[i]<minn||tree1[i]==minn&&tree2[i]<z){
//			minn=tree1[i];
//			z=tree2[i];
//		}
//	}
//	return z;
//}
//void xiu(int x,long long y){
//	for(int i=x;i<=n;i+=lowbit(i)){
//		
//	}
//}
bool cmp(node x,node y){
	return x.x<y.x;
}
int main(){
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	scanf("%lld %lld",&n,&m);
//	build(1,1,n);
	if(n<=100&&m<=100){
		for(int i=1;i<=m;i++){
			long long a,b;
			scanf("%lld %lld",&a,&b);
	//		int now=a;
	//		while(now){
	//			now=xiu(1,1,n,1,now,b);
	//		}
			if(a==1){
				ans[1]+=b;
				continue;
			}
			for(int j=1;j<=a;j++){
				lin[j].x=ans[j];
				lin[j].y=j;
			}
			sort(lin+1,lin+1+a,cmp);
			int l=1,r=2;
			while(r<=a){
				if(ans[lin[l].y]<ans[lin[r].y]){
					if(b>=(lin[r].x-lin[l].x)*(r-1)){
						for(int j=l;j<r;j++){
							ans[lin[j].y]+=lin[r].x-lin[l].x;
							b-=lin[r].x-lin[l].x;
						} 
					}
					else{
						for(int j=1;j<r;j++){
							ans[lin[j].y]+=b/(r-1);
							vis[lin[j].y]=0;
						}
						for(int j=1;j<=(b%(r-1));j++){
							long long minn=0x3f3f3f3f3f3f3f3f;
							for(int k=1;k<r;k++){
								if(!vis[lin[k].y]&&lin[k].y<minn){
									minn=lin[k].y;
								}
							}
							vis[minn]=1;
							ans[minn]++;
						}
						break;
					}
				}
				else{
					while(r<a&&lin[r].x==lin[r+1].x){
						r++;
					}
					if(r==a){
						for(int j=l;j<=r;j++){
							ans[lin[j].y]+=b/r;
						}
						for(int j=l;j<l+(b%r);j++){
							ans[j]++;
						}
						break;
					}
					else{
						r++;
					}
				}
			}
//			for(int i=1;i<=n;i++){
//				printf("%d ",ans[i]);
//			}
//			printf("\n");
		}
	}
	else{
//		build(1,1,n);
		int now=1;
//		for(int i=1;i<=n;i++){
//			tree2[i]=1;
//		}
		for(int i=1;i<=m;i++){
			long long a,b;
			scanf("%lld %lld",&a,&b);
//			int wei=cha(a);
//			ans[wei]++;
//			xiu(wei,ans[wei]);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
} 
