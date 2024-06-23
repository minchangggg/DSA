#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);

    string s; 
    set <string> se;
    vector <string> v; 

    while (cin >> s) {
        if (!se.count(s)) v.push_back(s);
        se.insert(s);
    }

    for (string x : se) cout << x << ' ';
    cout << endl;
    for (string x : v) cout << x << ' ';
}
