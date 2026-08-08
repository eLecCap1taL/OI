#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> pri;
void init(int maxVal){
    int start = pri.empty() ? 2 : pri.back() + 1;
    for (int x = start; x <= maxVal; ++x){
        bool ok = true;
        for (int d = 2; d * d <= x; ++d){
            if (x % d == 0){ok = false; break;}
        }
        if (ok) pri.push_back(x);
    }
}
void gen(int sum, int idx, vector<int>& c, vector<vector<int>>& now){
    if (sum == 0){
        now.push_back(c);
        return;
    }
    for (int i = idx; i < (int)pri.size(); ++i){
        int p = pri[i];
        if (p > sum) break;
        c.push_back(p);
        gen(sum - p, i, c, now);
        c.pop_back();
    }
}
bool cmp(vector<int>a, vector<int>b){
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}
int main(){
    freopen("dabiao.in",  "r", stdin);
    freopen("dabiao.out",  "w", stdout);
    ll l, r;
    cin >> l >> r;
    string nowtr =  "";
    int sum = 2;
    while (true){
        init(sum);
        vector<vector<int>> now;
        vector<int> c;
        gen(sum, 0, c, now);
        sort(now.begin(), now.end(), cmp);
        for (auto & seq : now){
            string s =  "{";
                for (int i = 0; i < (int)seq.size(); ++i){
                    if (i) s +=  ',';
                    s += to_string(seq[i]);
                }
                s +=  '}';
            if (nowtr.empty()) nowtr = s;
            else nowtr +=  ',' + s;
            if ((ll)nowtr.size() >= r) break;
        }
        if ((ll)nowtr.size() >= r) break;
        ++sum;
    }
    string Ans =  "vector<vector<int>>ans={" + nowtr +  "};";
    string ans = Ans.substr((size_t)l - 1, (size_t)(r - l + 1));
    cout << ans <<  '\n';

    return 0;
}