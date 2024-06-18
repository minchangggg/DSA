#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef HAHA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif

    int n, k; cin >> n; 
    int a[n];
    for (int &x : a) cin >> x;
    cin >> k;

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == k) ++res;
        }
    }
    cout << res;
    return 0;
}
