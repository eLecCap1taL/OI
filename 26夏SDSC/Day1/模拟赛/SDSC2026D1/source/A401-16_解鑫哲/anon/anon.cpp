#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
const int N = 505;
int n,k;
int a[N][N],ans[N][N],num;
int cnt[N] = {0};
int main(){
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int t = 1;t <= n;t++){
		//(1,t) 
		memset(cnt,0,sizeof cnt);
		num = 0;
		int len = 1;
		bool len_p = false;	//len_postpone
		cnt[a[1][t]]++;
		num++;
		for(int w = 0;w <= n-t;w++){
			//(1+w,t+w)
			//上一个就是(w,t+w-1) 
			//并且到达了(w+len-1,t+w+len-2) 
			//如果有postpone,那么就又要+1 
			if(w != 0){
				//清理被移出框架的内容
				//但是(w,t+w+1)不应该被清理两次,故第一个循环从w+1开始 
				for(int i = w+1;i <= w+len-1+len_p;i++){
					cnt[a[i][t+w-1]]--;
					if(cnt[a[i][t+w-1]] == 0)
						num--;
//					if(cnt[a[i][t+w-1]] < 0)
//						printf("Wrong!\n");
				}
				for(int i = t+w-1;i <= t+w+len-2+len_p;i++){
					cnt[a[w][i]]--;
					if(cnt[a[w][i]] == 0)
						num--;
//					if(cnt[a[w][i]] < 0)
//						printf("Wrong!\n");
				}
				len--;
			}
			if(num <= k && len_p){
				len_p = false;
				len++;
			}
			//每一轮向外扩张一圈
			while(num <= k && w+len < n && t+w+len-1 < n){
				//扩张前我们的边界分别为
				//(1+w,t+w) -> (w+len,t+w+len-1)
				//因此我们的扩张为(1+w,t+w+len) -> (..+1,t+w+len)和(w+len+1,t+w) -> (w+len+1,..+1),同样注意重复
				//还有一点,如果在扩张途中遇见了num>k,进行一个标记,正常完成之后再使得len+1,这样防止重复遍历消耗时间 
				for(int i = 1+w;i <= w+len+1;i++){
					cnt[a[i][t+w+len]]++;
					if(cnt[a[i][t+w+len]] == 1)
						num++;
				}
				for(int i = t+w;i <= t+w+len-1;i++){
					cnt[a[w+len+1][i]]++;
					if(cnt[a[w+len+1][i]] == 1)
						num++;
				}
				if(num > k)
					len_p = true;
				else
					len++;
			}
			ans[1+w][t+w] = len;
//			printf("Cnt : ");
//			for(int r = 1;r <= n;r++){
//				printf("%d ",cnt[r]);
//			}
//			printf("\n(%d,%d) = %d [postpone=%d,num=%d]\n",1+w,t+w,len,len_p,num);
		}
	}
	for(int t = 1;t <= n;t++){
		//(t,1) 
		memset(cnt,0,sizeof cnt);
		num = 0;
		int len = 1;
		bool len_p = false;
		cnt[a[t][1]]++;
		num++;
		for(int w = 0;w <= n-t;w++){
			//所有的都反过来了 
			if(w != 0){
				for(int i = w+1;i <= w+len-1+len_p;i++){
					cnt[a[t+w-1][i]]--;
					if(cnt[a[t+w-1][i]] == 0)
						num--;
//					if(cnt[a[t+w-1][i]] < 0)
//						printf("Wrong!\n");
				}
				for(int i = t+w-1;i <= t+w+len-2+len_p;i++){
					cnt[a[i][w]]--;
					if(cnt[a[i][w]] == 0)
						num--;
//					if(cnt[a[i][w]] < 0)
//						printf("Wrong!\n");
				}
				len--;
			}
			if(num <= k && len_p){
				len_p = false;
				len++;
			}
			while(num <= k && w+len < n && t+w+len-1 < n){
				for(int i = 1+w;i <= w+len+1;i++){
					cnt[a[t+w+len][i]]++;
					if(cnt[a[t+w+len][i]] == 1)
						num++;
				}
				for(int i = t+w;i <= t+w+len-1;i++){
					cnt[a[i][w+len+1]]++;
					if(cnt[a[i][w+len+1]] == 1)
						num++;
				}
				if(num > k)
					len_p = true;
				else
					len++;
			}
			ans[t+w][1+w] = len;
//			printf("(%d,%d) = %d [postpone=%d,num=%d]\n",t+w,1+w,len,len_p,num);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
//2*n*2*(n*n)=4*125*1000000=5*10^8
