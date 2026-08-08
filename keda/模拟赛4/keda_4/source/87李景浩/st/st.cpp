#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int m1 = 1000000007;
const int m2 = 1000000009;
const int N = 1000005;
int pri[N], cntP;
bool isp[N];
void init(){
    for (int i = 2; i < N; ++i){
        if (!isp[i]) pri[++cntP] = i;
        for (int j = 1; j <= cntP && i * pri[j] < N; ++j){
            isp[i * pri[j]] = true;
            if (i % pri[j] == 0) break;
        }
    }
}
int main(){
    freopen("st.in", "r", stdin);
    freopen("st.out", "w", stdout);
    init();
    int T;
    scanf("%d",&T);
    while (T--){
        int n, m;
        scanf("%d%d",&n,&m);
        if (m == 1){
            for (int i = 1; i <= n; ++i){int x; scanf("%d",&x);}
            puts("0");
            continue;
        }
        vector<int> p1(m + 1), p2(m + 1);
        ll sum1 = 0, sum2 = 0;
        for (int v = 2; v <= m; ++v){
            int idx = v - 1;
            p1[v] = pri[idx] % m1;
            p2[v] = pri[idx] % m2;
            sum1 = (sum1 + p1[v]) % m1;
            sum2 = (sum2 + p2[v]) % m2;
        }
        vector<pair<int, int>> hash;
        hash.reserve(n + 1);
        hash.emplace_back(0, 0);
        int h1 = 0, h2 = 0;
        for (int i = 1; i <= n; ++i){
            int x;
            cin >> x;
            if (x == 1){
                h1 = (h1 - sum1) % m1;
                h2 = (h2 - sum2) % m2;
                if (h1 < 0) h1 += m1;
                if (h2 < 0) h2 += m2;
            }
            else {
                h1 += p1[x];
                h2 += p2[x];
                if (h1 >= m1) h1 -= m1;
                if (h2 >= m2) h2 -= m2;
            }
            hash.emplace_back(h1, h2);
        }
        sort(hash.begin(), hash.end());
        ll ans = 0;
        ll cnt = 1;
        for (int i = 1; i < (int)hash.size(); ++i){
            if (hash[i] == hash[i - 1]){
                ++cnt;
            }
            else {
                ans += cnt * (cnt - 1) / 2;
                cnt = 1;
            }
        }
        ans += cnt * (cnt - 1) / 2;
        printf("%lld", ans);
    }

    return 0;
}