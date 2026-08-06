#include<bits/stdc++.h>
using namespace std;
int n , m , ans[100005];
long long t[100005];
struct temp{
	__int128 num;
	int id;
}c[100005];
bool cmp1(temp a , temp b) {
	if(a.num == b.num) return a.id < b.id;
	return a.num < b.num;
}
bool cmp2(temp a , temp b) {
	return a.id < b.id;
}
priority_queue<int , vector<int> , greater<int> > q[100005]; 
struct node{
	int left , right;
	int value;
}tree[400005];
void build(int root , int l , int r) {
	tree[root].left = l , tree[root].right = r;
	if(l == r) {
		tree[root].value = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(2 * root , l , mid);
	build(2 * root + 1 , mid + 1 , r);
	tree[root].value = min(tree[2 * root].value , tree[2 * root + 1].value);
}
void update(int root , int l , int r) {
	if(tree[root].left >= l && tree[root].right <= r) {
		tree[root].value ++;
		return;
	}
	int mid = (tree[root].left + tree[root].right) / 2;
	if(l <= mid) update(2 * root , l , r);
	if(r > mid) update(2 * root + 1 , l , r);
	tree[root].value = min(tree[2 * root].value , tree[2 * root + 1].value); 
}
int query(int root , int l , int r) {
	if(tree[root].left >= l && tree[root].right <= r) {
		return tree[root].value;
	}
	int mid = (tree[root].left + tree[root].right) / 2;
	int ans = 0x3f3f3f3f;
	if(l <= mid) ans = min(ans , query(2 * root , l , r));
	if(r > mid) ans = min(ans , query(2 * root + 1 , l , r));
	return ans;
}
int main() {
	freopen("umiri.in" , "r" , stdin);
	freopen("umiri.out" , "w" , stdout);
	cin >> n >> m;
	if(n <= 100 && m <= 100) {
		while(m--) {
			__int128 sum = 0;
			int a , tmp = 0;
			long long b;
			cin >> a >> b;
			for(int i = 1 ; i <= a ; i++) {
				c[i].num = t[i];
				c[i].id = i;
			}
			sort(c + 1 , c + a + 1 , cmp1);
			for(int i = 1 ; i <= a ; i++) {
				sum = sum + c[a].num - c[i].num;
			}
			for(int i = a - 1 ; i >= 1 ; i--) {
				if((__int128)b >= sum) {
					tmp = i;
					break;
				}
				sum = sum - (c[i + 1].num - c[i].num) * i;
			}
			if(tmp == 0) {
				t[c[1].id] += b;
				continue;
			}
			for(int i = 1 ; i <= tmp ; i++) {
				t[c[i].id] = c[tmp + 1].num;
			}
			sort(c + 1 , c + tmp + 2 , cmp2);
			long long res = b - sum;
			long long p = res / (tmp + 1) , r = res % (tmp + 1);
			for(int i = 1 ; i <= tmp + 1 ; i++) {
				t[c[i].id] += p;
				if(i <= r) t[c[i].id]++;
			}
		}
		for(int i = 1 ; i <= n ; i++) {
			cout << t[i] << "\n";
		}
	}
	else{
		build(1 , 1 , n);
		for(int i = 1 ; i <= n ; i++) q[0].push(i);
		while(m--) {
			int a , b;
			cin >> a >> b;
			int num = query(1 , 1 , a);
			int x = q[num].top();
			update(1 , x , x);
			q[num + 1].push(x);
			q[num].pop();
		} 
		for(int i = 1 ; i <= 100000 ; i++) {
			while(!q[i].empty()) {
				ans[q[i].top()] = i;
				q[i].pop();
			}
		}
		for(int i = 1 ; i <= n ; i++) {
			cout << ans[i] << "\n";
		}
	}
	return 0;
}
