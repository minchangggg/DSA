#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef HAHA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif

    string s; cin >> s;
    if (s.size()%2) cout << s[int(s.size()/2)];
    else cout << "NOT FOUND";
}
