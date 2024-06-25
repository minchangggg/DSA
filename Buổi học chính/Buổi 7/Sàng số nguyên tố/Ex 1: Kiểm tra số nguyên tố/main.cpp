#include <bits/stdc++.h>
using namespace std;

int prime (int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return n>1; // (n <= 1 thì return 0); (n > 1 thì return 1)
}

int main() {
    freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);
    int m, n; cin >> m >> n;

    if (prime(m)) cout << "YES";
    else cout << "NO";
    cout << endl;
    if (prime(n)) cout << "YES";
    else cout << "NO";
}
