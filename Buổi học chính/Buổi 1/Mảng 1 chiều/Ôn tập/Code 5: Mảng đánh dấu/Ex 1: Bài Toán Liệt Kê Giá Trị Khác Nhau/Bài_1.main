#include <iostream>
#include <math.h>
using namespace std;

int mark[1000001]; 

int main(){
    int n = 10;
    int a[10] = {3, 1, 3, 0, 2, 4, 1, 14, 12, 7};
    //đánh dấu
    int max_val = -1000000000;
    for(int i = 0; i < n; i++){
        //Lấy a[i] làm chỉ số và chuyển mark[a[i]] = 11
        mark[a[i]] = 1;
        if(a[i] > max_val){
            max_val = a[i];
        }
    }
    cout << "Cac gia tri khac nhau trong mang : ";
    for(int i = 0; i <= max_val; i++){
        if(mark[i] == 1){
            cout << i << " ";
        }
    }
    return 0;
}
