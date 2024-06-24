#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef HAHA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif

    map <int,int> mp;
    int n; cin >> n; 
    int a[n];
    
    for (int &x : a) cin >> x;
    
    while (n--) mp[a[n]]++;
    
    for (auto it : mp) cout << it.first << ' ' << it.second << endl;
}
