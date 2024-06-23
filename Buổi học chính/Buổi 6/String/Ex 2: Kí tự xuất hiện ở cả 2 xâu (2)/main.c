#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);

    string S1, S2; cin >> S1 >> S2;
    int cnt1[256] = {0}, cnt2[256] = {0};

    for (char x : S1) cnt1[x] = 1;
    for (char x : S2) cnt2[x] = 1;

    for (int i = 0; i < 256; i++) {
        if (cnt1[i] && cnt2[i] == 0) cout << (char) i;
    }
    cout << endl; 
    
    for (int i = 0; i < 256; i++) {
        if (cnt1[i] == 0 && cnt2[i]) cout << (char) i;
    }

	return 0;
}
