#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool checkNT (ll n) {
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return n>1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    
    int n; 
    cin >> n;
    int a[n];
    for (int i = 0; i<n; i++) {
        cin >> a[i];
    }
    
    for (int i=0; i<n; i++) {
        if (checkNT(a[i])) cout << a[i] << ' ';
    }
}
