#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll n, ll x, ll y, ll time){
    time -= min(x, y); // thời gian để photo từ bản gốc ra 1 bản sao
    return (time/x + time/y) >= (n-1);
}

int main(){
    #ifndef DSA
    freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);
    #endif

    int n, x, y; cin >> n >> x >> y;

    ll left = 0, right = 1ll * min(x, y) * n;
    ll ans = -1;
    while(left <= right){
        ll mid = (left + right) / 2;
        if(check(n, x, y, mid)){
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << ans;
}
