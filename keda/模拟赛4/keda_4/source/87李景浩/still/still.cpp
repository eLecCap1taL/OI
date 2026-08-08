#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 455;
const ll INF = (1LL << 62);
int n;
ll A[N];
int ls[N], rs[N], sz[N];
ll dp[N][N][2];
void dfs(int u){
    sz[u] = 1;
    if (ls[u]){
        dfs(ls[u]);
        sz[u] += sz[ls[u]];
    }
    if (rs[u]){
        dfs(rs[u]);
        sz[u] += sz[rs[u]];
    }
    for (int b = 0; b <= 1; ++b){
        ll c[N];
        for (int i = 0; i <= sz[u]; ++i) c[i] = INF;
        int iz = (b == 0 ? 1 : 0);
        c[iz] = 0;
        int now = 1;
        if (ls[u]){
            ll nxt[N];
            for (int i = 0; i <= sz[u]; ++i) nxt[i] = INF;
            int v = ls[u];
            int sv = sz[v];
            for (int k0 = 0; k0 <= now; ++k0){
                if (c[k0] >= INF / 2) continue;
                for (int kv = 0; kv <= sv; ++kv){
                    for (int bv = 0; bv <= 1; ++bv){
                        ll val = dp[v][kv][bv];
                        if (val >= INF / 2) continue;
                        ll add = (bv != b) ? A[v] : 0;
                        ll can = c[k0] + val + add;
                        int nk = k0 + kv;
                        if (can < nxt[nk]) nxt[nk] = can;
                    }
                }
            }
            for (int i = 0; i <= sz[u]; ++i) c[i] = nxt[i];
            now += sv;
        }
        if (rs[u]){
            ll nxt[N];
            for (int i = 0; i <= sz[u]; ++i) nxt[i] = INF;
            int v = rs[u];
            int sv = sz[v];
            for (int k0 = 0; k0 <= now; ++k0){
                if (c[k0] >= INF / 2) continue;
                for (int kv = 0; kv <= sv; ++kv){
                    for (int bv = 0; bv <= 1; ++bv){
                        ll val = dp[v][kv][bv];
                        if (val >= INF / 2) continue;
                        ll add = (bv != b) ? A[v] : 0;
                        ll can = c[k0] + val + add;
                        int nk = k0 + kv;
                        if (can < nxt[nk]) nxt[nk] = can;
                    }
                }
            }
            for (int i = 0; i <= sz[u]; ++i) c[i] = nxt[i];
            now += sv;
        }
        for (int k = 0; k <= sz[u]; ++k){
            dp[u][k][b] = c[k];
        }
    }
}

int main(){
    freopen("still.in",  "r", stdin);
    freopen("still.out",  "w", stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i)scanf("%lld", A + i);
    for (int i = 1; i <= n; ++i){
        if (2 * i <= n) ls[i] = 2 * i;
        if (2 * i + 1 <= n) rs[i] = 2 * i + 1;
    }
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= n; ++j){
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    } dfs(1);
    ll sumA = 0;
    for (int i = 2; i <= n; ++i) sumA += A[i];
    ll ans = sumA - min(dp[1][n / 2][0], dp[1][n / 2][1]);
    printf("%lld", ans);
    return 0;
}