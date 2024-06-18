#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef HAHA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif

    int n; cin >> n; 
    int a[n];
    for (int &x : a) cin >> x;
  
    for (int i = 0; i < n; i++) {
        bool check = true;
        for (int j = 0; j < i; j++) {
            if (a[j] == a[i]) {
                check = false;
            }
            
        }
        if (check) cout << a[i] << ' ';
    }

    return 0;
}
