#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef HAHA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif

    int n; cin >> n; 
    int a[n];
    
    set <int> se;
    for (int &x : a) {
        cin >> x;
        se.insert(x);
    }

    int q; cin >> q; 
    while (q--) {
        int x; cin >> x;
        if (se.find(x) != se.end()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
