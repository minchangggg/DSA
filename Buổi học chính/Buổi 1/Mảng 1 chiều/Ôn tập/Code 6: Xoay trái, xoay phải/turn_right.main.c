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
        int temp = a[n-1];
        for (int i = n-1; i > 0; i--) {
            a[i] = a[i-1];
        }
        a[0] = temp; 
        _k--;
    }

    for (int x : a) cout << x << " ";

    return 0;
}
