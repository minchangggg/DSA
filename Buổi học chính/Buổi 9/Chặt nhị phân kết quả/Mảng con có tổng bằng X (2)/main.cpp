#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// bool check(int a[], int n, int k, double len){
//     ll cnt = 0; 
//     for(int i = 0; i < n; i++) cnt += (int)(a[i]/len);
//     return cnt >= k;
// }

int main(){
    #ifndef DSA
    freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);
    #endif

    int n, x; cin >> n >> x; 
    int a[n]; for(int &x : a) cin >> x;

    ll sum = 0, ans = 0; 
    map<ll, int> mp; // tổng nào đã suất hiện, tính từ phần tử chỉ số 0 tới các phần tử khác trong mảng
       
    for(int i = 0; i < n; i++){
        sum += a[i]; 
        // TH1(TH đặc biệt): dãy con bắt đầu từ 0 và kết thúc ở i có tổng bằng sum
        if(sum == x) ++ans; 
        // TH2: muốn biết dãy con có tổng bằng x hay không
        if(mp.count(sum - x)) ++ans; 

        mp[sum]++; // map dùng để đếm thay vì đánh dấu như bài trước
    }
    cout << ans;
    // cout << (float) ans;
}
