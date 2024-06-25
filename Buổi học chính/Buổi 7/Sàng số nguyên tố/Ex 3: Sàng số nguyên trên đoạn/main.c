#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void sieve(ll L, ll  R){
    //Bước 1 : Coi tất cả các số từ 0 tới N là số ng/uyên tố
    vector<bool> isPrime(R - L + 1, true);

    //Bước 2 : Sàng
    for (ll i = 2; i * i <= R; ++i) {
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) { // (L + i - 1) / i * i là bội nhỏ nhất của L ≥ i * i
            isPrime[j - L] = false;
        }
    }

    // Xuất các số nguyên tố trong đoạn từ L đến R
    for(ll i = max(2ll, L); i <= R; i++){ // 2LL là số 2 dạng long long. Nếu ko có LL, nó sẽ có mặc định kiểu int
        if(isPrime[i - L]) cout << i << ' ';
    }
}

int main(){
    freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);
    int m1, m2, n1, n2; cin >> m1 >> m2 >> n1 >> n2;
    sieve(m1, m2);
    cout << endl;
    sieve(n1, n2);
}
