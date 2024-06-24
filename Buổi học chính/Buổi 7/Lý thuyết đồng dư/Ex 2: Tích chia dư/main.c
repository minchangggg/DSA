#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll mod = 1e9+7;

int main() {
    freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);

    int n = 0; cin >> n;
    ll s = 1;

    for(ll i = 0; i < n; i++) {
        ll temp; cin >> temp;
        s *= temp%mod;
        s %= mod;
    }
    cout << s;
}
