#include <bits/stdc++.h>
using namespace std;

int mark[1000001]; 

int main() {
    #ifndef HAHA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif

    int n = 10;
    int a[10] = {3, 1, 3, 0, 2, 4, 1, 14, 12, 7};

    //đánh dấu
    for(int i = 0; i < n; i++){
        mark[a[i]] = 1;
    }
    cout << "Gia tri khac nhau trong mang : ";
    for(int i = 0; i < n; i++){
        if(mark[a[i]] == 1){
            cout << a[i] << " ";
            //Bỏ đánh dấu
            mark[a[i]] = 0;
        }
    }
    return 0;
}
