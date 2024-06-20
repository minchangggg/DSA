#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef HAHA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;
    int a[n]; 
    for (int &x : a) cin >> x;

    int _k = k%n;
    while (_k > 0) {
        int temp = a[0];
        for (int i = 0; i < n-1; i++) {
            a[i] = a[i+1];
        }
        a[n-1] = temp;
        _k--;
    }

    for (int x : a) cout << x << " ";

    return 0;
}
