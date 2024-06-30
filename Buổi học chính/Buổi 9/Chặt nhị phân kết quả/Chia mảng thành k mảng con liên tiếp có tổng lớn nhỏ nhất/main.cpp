#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int a[], int n, int k, ll sum){ // tổng dãy con không được vượt quá sum
    int cnt = 0; ll _sum = 0;
    for(int i = 0; i < n; i++){
        _sum += a[i];
        if(_sum > sum){  // tổng dãy con tạo ra mà vượt quá tổng cho phép thì tắch ra dãy con mới
            ++cnt;
            _sum = a[i];
        }
    }
    ++cnt; // sau khi kết thúc dãy con cúi cùng, tăng biến đếm lên 1 lần cho nó
    return cnt <= k; // số mảng con còn nhỏ so với k đề cho, tổng lớn nhất của mảng con chưa phải nhỏ nhất, tổng đó còn có thể giảm được
}

int main(){
    #ifndef DSA
    freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    int a[n]; ll right = 0;
    for(int &x :a) {
        cin >> x;
        right += x;
    }
    
    ll left = *max_element(a, a+n); ll ans = -1;
    while(left <= right){
        ll mid = (left + right) / 2;
        if(check(a, n, k, mid)){
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << ans;
}
