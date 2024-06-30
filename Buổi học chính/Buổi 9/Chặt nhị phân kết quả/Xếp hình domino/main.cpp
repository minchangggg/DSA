#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    #ifndef DSA
    freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);
    #endif

    int a, b, n; cin >> a >> b >> n;
    ll left = 0, right = max(a,b) * n;
    ll ans = -1; // độ dài cạnh hình vuông
    while(left <= right){
        ll mid = (left + right) / 2;
        if((mid/a) * (mid/b) >= n){
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << ans;
}
