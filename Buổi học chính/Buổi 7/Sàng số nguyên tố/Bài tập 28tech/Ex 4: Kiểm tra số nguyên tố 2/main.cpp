#include <bits/stdc++.h>
using namespace std;

int N = 1000000; bool mark [1000001];

void sieve(int N){
    for (bool &x : mark) x = true;
    mark[0] = mark[1] = false;
    
    for(int i = 2; i*i <= N; i++){
        if(mark[i]){
            for(int j = i*i; j <= N; j += i){
                mark[j] = false;
            }
        }
    }
}

int main(){
    freopen("input.TXT", "r", stdin);
    freopen("output.TXT", "w", stdout);
    sieve (N);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (mark[n]) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
