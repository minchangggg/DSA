#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Các biến toàn cục và hàm khởi tạo cấu hình đầu tiên
int n, a[100]; // lưu cấu hình
bool final = false; // check cấu hình cuối

void init(){
    for(int i = 1; i <= n; i++) a[i] = 0;
}

// Hàm sinh cấu hình kế tiếp:
void sinh(){
    int i = n; // bắt đầu từ bit cuối cùng
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        --i;
    }
    (i == 0) 
        ? final = true  // đây là cấu hình cuối cùng
        : a[i] = 1; // còn sinh được cấu hình sau nó 
}

int main(){
    n = 3;
    init();
    while(!final){
        for(int i = 1; i <= n; i++){
            (a[i] == 0) ? cout << "B" : cout << "A";
        }
        cout << endl;
        sinh();
    }
}
