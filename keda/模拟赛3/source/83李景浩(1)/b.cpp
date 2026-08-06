#include <bits/stdc++.h>
using namespace std;

string s, t;
#define fi first
#define se second
vector<vector<pair<string, string>>> dp(55, vector<pair<string, string>>(55));

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> s >> t;
    int n = s.size(); 
    dp[0][0] = {"", ""};

    for (int i = 1; i <= n; i++) {
        dp[i][0] = {"", ""};
        char nows = s[i-1], nowt = t[i-1];

        for (int k = 1; k <= i; k++) {
            bool can = (k <= i-1);
            pair<string, string> now1;
            if (can) {
                now1 = dp[i-1][k];
            }
            pair<string, string> now2 = dp[i-1][k-1];
            now2.fi += nows;
            now2.se += nowt;

            if (can) {
                string tp = now1.fi + now1.se;
                string te = now2.fi + now2.se;
                dp[i][k] = (tp > te) ? now1 : now2;
            } else {
                dp[i][k] = now2;
            }
        }
    }

    string ans = "";
    for (int k = 0; k <= n; k++) {
        string cur = dp[n][k].fi + dp[n][k].se;
        if (cur > ans) {
            ans = cur;
        }
    }
    cout << ans << endl;
    return 0;
}