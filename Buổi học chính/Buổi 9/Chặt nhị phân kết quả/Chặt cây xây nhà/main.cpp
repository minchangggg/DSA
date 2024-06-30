#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int a[], int n, int l, ll h){
    ll sum = 0;
    for(int i = 0; i < n; i++) 
        if(a[i] > h) sum += (a[i] - h);
    return sum >= l;
}

int main(){
    #ifndef DSA
    freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);
    #endif

    int n, l; cin >> n >> l;
    int a[n]; for(int &x : a) cin >> x;

    ll left = 0, right = *max_element(a, a + n);
    ll ans = -1;
    while(left <= right){
        ll mid = (left + right) / 2;
        if(check(a, n, l, mid)){
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << ans;
}
