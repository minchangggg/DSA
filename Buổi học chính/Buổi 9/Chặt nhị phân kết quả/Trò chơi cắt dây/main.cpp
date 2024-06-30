#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int a[], int n, int k, double len){
    ll cnt = 0; 
    for(int i = 0; i < n; i++) cnt += (int)(a[i]/len);
    return cnt >= k;
}

int main(){
    #ifndef DSA
    freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    int a[n]; for(int &x : a) cin >> x;

    double left = 0, right = 9e18;
    double ans = -1; 
    
    for(int i = 0; i < 100; i++){
        double mid = (left + right) / 2;
        if(check(a, n, k, mid)){
            ans = mid;
            left = mid;
        }
        else right = mid; // vì lấy số thập phân nên ko làm như thường
    }
    cout << fixed << setprecision(6) << ans << endl;
    // cout << (float) ans;
}
