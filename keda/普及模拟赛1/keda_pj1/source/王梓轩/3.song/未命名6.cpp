#include<bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    if (k == 1) {
        cout << 'r' << endl;
    } else {
        cout << char('a' + k % 26) << endl;
    }
    return 0;
}
