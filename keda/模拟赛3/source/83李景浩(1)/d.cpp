#include <bits/stdc++.h>
using namespace std; 
#define ll long long
const int N=1e5+5;
#define eps 1e-3
int n;
ll k;
int x[N],y[N]; 
double p[N],q[N];
bool cmp(double a,double b){
	return a < b;
} 
int check(double v){
    ll tot = 0;
	for(int i = 1;i <= n;i++){
		double a = x[i] * 1.0 * y[i],b = v * x[i]; 
		p[i] = a - b;	q[i] = -p[i];
	    if(q[i] - p[i] < eps) tot--;//(精度ex 
	}
	sort(p + 1, p + n + 1, cmp);
	sort(q + 1, q + n + 1, cmp);
	for(int i = 1,j=0;i <= n;i++){
		while((q[j+1] - p[i]) < eps && j + 1 <= n) j++;
		tot += j;
	}
	return (tot / 2< k);//老师我不想凹精度
}

int main(){
	scanf("%d%lld", &n, &k);
	for(int i = 1;i <= n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	double l = 1,r = 1000000000,mid;
	while((r - l) > eps){
		mid = (l + r) /2;
		if(check(mid)){
			r = mid;
		}else{
			l = mid;
		}
	}
	printf("%.3f\n", l);
	return 0;
}
