#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef HAHA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif

    set <string> se;
    string s;
    while (cin>>s) {
        se.insert(s);
    }

    cout << se.size() << endl;
    cout << *se.begin() << ' ' << *se.rbegin() << endl;
}
