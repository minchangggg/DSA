#include <bits/stdc++.h>
using namespace std;

bool cmp (string a, string b) {
    // sort theo chìu dài tăng dần
    return a.size() < b.size();
}

bool isTN (string s) { // kiểm tra str có thuận nghịch ko
    int l = 0, r = s.size() - 1;
    while (l <= r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

int main() {
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s; vector <string> v; set <string> se; 
    while (cin >> s) {
        if ((se.count(s) == 0) && isTN(s)) v.push_back(s);
        se.insert(s);
    }

    stable_sort (v.begin(), v.end(), cmp);
    for (string x : v) cout << x << ' ';
    cout << endl;
}
