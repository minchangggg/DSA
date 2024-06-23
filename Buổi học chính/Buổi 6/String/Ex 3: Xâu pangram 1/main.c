#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);

    string S; cin >> S;
    int cnt[256] = {0};

    for (char x : S) cnt[tolower(x)] = 1;
    
    for (int i = (int)'a'; i < (int)'z'; i++) {
        if (!cnt[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
