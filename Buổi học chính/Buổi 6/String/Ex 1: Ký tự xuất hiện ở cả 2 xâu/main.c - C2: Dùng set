#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);

    string S1, S2;
    getline (cin, S1);
    getline (cin, S2);

    set <char> S;
    for (char x : S1) {
        for (char y : S2) {
            if (x==y) S.insert(x);
        }
    }
    for (char x : S) cout << x;
    

    cout << endl; S.clear();
    for (char x : S1) S.insert(x);
    for (char x : S2) S.insert(x);
    for (char x : S) cout << x;

	return 0;
}
