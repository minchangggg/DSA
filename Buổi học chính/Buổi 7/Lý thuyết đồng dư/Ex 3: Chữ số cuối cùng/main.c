#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);

    int N, M, K; cin >> N >> M >> K;
    ll mod = pow(10, K);
    ll s = 1;

    for(ll i = 0; i < M; i++) {
        s *= N%mod;
        s %= mod;
    }
    cout << s;
}
