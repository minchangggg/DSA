#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Các biến toàn cục và hàm khởi tạo cấu hình đầu tiên
int n, k, a[100]; // lưu cấu hình
bool final = false; // check cấu hình cuối
vector<vector<int>> res;

void init(){ 
    for(int i = 1; i <= k; i++) a[i] = i;
}

// Hàm sinh cấu hình kế tiếp:
void sinh(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i){ // cực đại tại a[i] bất kì là n-k+i
        --i;
    }
    if(i == 0) final = true; //  đây là cấu hình cuối cùng
    else{
        a[i]++;
        for(int j = i + 1; j <= k; j++){
            a[j] = a[j - 1] + 1;
        }
    }
}

int main(){
    #ifndef HAHA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif

    cin >> n >> k;
    int x[100];
    for(int i = 0; i < k; i++) cin >> x[i];
    init();
    while(!final){
        vector<int> tmp(a + 1, a + k + 1);
        res.push_back(tmp);
        sinh();
    }

    for(int i = res.size()-1; i >= 0; i--){
        bool check = true;
        for(int j = 0; j < k; j++){
            if(x[j] != res[i][j]){
                check = false;
                break;
            }
        }
        if(check){
            cout << res.size() - i;
            return 0;
        }
    }
}
