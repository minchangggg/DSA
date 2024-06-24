#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef HAHA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif

    int n; cin >> n; 
    int a[n];
    for (int &x : a) cin >> x;
    
    set <int> se;
    for (int x: a) {
        if (se.find(x) == se.end()) {
            cout << x << ' ';
            se.insert(x);
        }
    }
}
