#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    #ifndef DSA
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, q; cin >> n >> q;
    int a[n]; for(int &x : a) cin >> x;
 
    int temp[n+5] = {0}; // tương tự t/c mảng hiệu
    while(q--){
        int l, r; cin >> l >> r;
        --l; --r; // vì 0 <= L <= R <= N
        temp[l] += 1;
        temp[r+1] -= 1;
    }

    int F[n]; // xem tần suất phần tử được truy vấn 
    F[0] = temp[0];
    for(int i = 1; i < n; i++) F[i] = F[i-1] + temp[i]; // 0 2 2 2 1 0
   
    sort(F, F+n, greater<int>()); // sx phần tử nào đc truy vấn nhìu nhất
    sort(a, a+n, greater<int>()); // sx phần tử nào có giá trị lớn nhất

    ll res = 0;
    for(int i = 0; i<n; i++) res += 1ll * a[i] * F[i]; // nhân 2 cái trên với nhau đc res
    cout << res;
}
