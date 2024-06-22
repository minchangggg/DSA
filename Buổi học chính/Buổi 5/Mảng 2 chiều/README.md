# I. Lý Thuyết Mảng 2 Chiều C++
Mảng 2 chiều là một mảng kiến thức quan trọng trong các ngôn ngữ lập trình, bài học này các bạn sẽ học cách sử dụng mảng 2 chiều trong C++
## 1. Mảng 2 Chiều
- Mảng 2 chiều tương tự như một bảng số gồm hàng và cột, mảng 2 chiều chính là một mảng các mảng 1 chiều
- Để truy cập các phần tử trong mảng 2 chiều ta thông qua chỉ số hàng và cột được đánh số từ 0
- Chú ý để truy cập vào phần tử trong mảng 2 chiều ta luôn dùng chỉ số hàng trước, chỉ số cột sau

![image](https://github.com/minchangggg/DSA/assets/125820144/e10c765b-3b31-4c73-ab08-6228dfefa66d)

- Cú pháp khai báo : **Data_type array_name[rows][cols];**
  + Data_type : Kiểu dữ liệu của phần tử trong mảng như int, float, char, double..
  + array_name : Tên mảng 2 chiều
  + rows : Số hàng của mảng 2 chiều
  + cols : Số cột của mảng 2 chiều 
- Ví dụ mảng a[3][3]
- Khai báo mảng 2 chiều bạn có thể khai báo thủ công như sau : 

        #include <iostream>
        using namespace std;
        
        int main(){
            int a[3][4] = {
                {1, 2, 3, 1},
                {4, 1, 5, 2},
                {3, 7, 9, 0}
            };
            cout << "a[0][2] = " << a[0][2] << endl;
            cout << "a[1][3] = " << a[1][3] << endl; 
            return 0;
        }
  
> Output : 

        a[0][2] = 3
        a[1][3] = 2

- Chú ý : Trong mảng 2 chiều bạn không được truy cập vào các chỉ số hàng hay cột không hợp lệ.
- Mình thấy có nhiều bạn có thói quen dùng chỉ số hàng và cột từ 1 thay vì từ 0, việc này cũng không có vấn đề gì nếu mảng của bạn đủ lớn để các chỉ số bạn dùng là hợp lệ. Vậy nên khi sử dụng thì nên biết mình làm vậy có đúng không để khai báo kích cỡ mảng 2 chiều cho phù hợp.
## 2. Nhập Xuất Mảng 2 Chiều
- Các dạng bài tập về mảng 2 chiều đều cho các biết trước số lượng hàng và cột của mảng 2 chiều, bạn có thể khai báo mảng 2 chiều dựa vào hàng cột mà đề bài cung cấp hoặc sử dụng mảng 2 chiều có kích thước cố định đủ lớn.
- Để in ra mảng 2 chiều bạn dùng 2 vòng lặp lồng nhau, vòng lặp ngoài duyệt qua hàng, vòng for trong duyệt qua từng cột của hàng.
- Ví dụ 1 : Nhập và xuất mảng 2 chiều với kích thước cố định : 

        #include <iostream>
        using namespace std;
        
        int main(){
            int n, m; // n : hang, m : cot
            int a[205][205]; // 205 x 205
            cout << "Nhap so hang, cot : ";
            cin >> n >> m;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << "a[" << i << "][" << j << "] = ";
                    cin >> a[i][j];
                }
            }
            cout << "Mang vua nhap :\n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }
  
- Ví dụ 2 : Nhập mảng 2 chiều dựa vào số hàng, cột của đề bài

        #include <iostream>
        using namespace std;
        
        int main(){
            int n, m; // n : hang, m : cot
            cout << "Nhap so hang, cot : ";
            cin >> n >> m;
            int a[n][m];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << "a[" << i << "][" << j << "] = ";
                    cin >> a[i][j];
                }
            }
            cout << "Mang vua nhap :\n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }

## 3. Mảng 2 Chiều Và Hàm
- Mảng 2 chiều có thể làm tham số của hàm, tuy nhiên khi hàm có tham số là mảng 2 chiều thì bạn cần chỉ định số lượng cột của mảng 2 chiều.
- Khi gọi hàm thì đối số truyền vào phải có số cột giống với số cột của mảng 2 chiều trong tham số.
- Ví dụ 1: Hàm nhập và xuất mảng

        #include <iostream>
        using namespace std;
        
        void nhap(int a[][205], int n, int m){
            cout << "Nhap mang : \n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << "a[" << i << "][" << j << "] = ";
                    cin >> a[i][j];
                }
            }
        }

        void xuat(int a[][205], int n, int m){
            cout << "Mang 2 chieu : \n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }
        
        int main(){
            int n, m, a[205][205];
            cout << "Nhap so hang, cot : ";
            cin >> n >> m;
            nhap(a, n, m);
            xuat(a, n, m);
            return 0;
        }

- Ví dụ 2 : Đếm số lượng số nguyên tố trong mảng 2 chiều 

        #include <iostream>
        #include <math.h>
        
        using namespace std;
        
        bool nt(int n){
            for(int i = 2; i <= sqrt(n); i++){
                if(n % i == 0) return false;
            }
            return n > 1;
        }

        void nhap(int a[][205], int n, int m){
            cout << "Nhap mang : \n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << "a[" << i << "][" << j << "] = ";
                    cin >> a[i][j];
                }
            }
        }
        
        void xuat(int a[][205], int n, int m){
            cout << "Mang 2 chieu : \n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }
        
        int dem(int a[][205], int n, int m){
            int ans = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(nt(a[i][j])){
                        ++ans;
                    }
                }
            }
            return ans;
        }

        int main(){
            int n, m, a[205][205];
            cout << "Nhap so hang, cot : ";
            cin >> n >> m;
            nhap(a, n, m);
            xuat(a, n, m);
            cout << "So luong so nguyen to : " << dem(a, n, m) << endl;
            return 0;
        }

# II. Bài Tập Mảng 2 Chiều C++
## 1. Bài Toán Liệt Kê
- Dạng bài này thường yêu cầu bạn đếm hoặc liệt kê các phần tử trong mảng 2 chiều thỏa mãn tính chất cho trước như : số nguyên tố, thuận nghịch, hoàn hảo, fibonacci...
- Đối với dạng bài tập này bạn chỉ cần biết duyệt mảng 2 chiều là có thể làm được.
- Ví dụ 1 : Tìm phần tử nhỏ nhất, lớn nhất trong mảng 2 chiều

        #include <iostream>
        #include <math.h>
        
        using namespace std;
        
        int main(){
            int n = 4, m = 4;
            int a[4][4] = {
                {3, 1, 0, 7},
                {2, 5, 10, 3},
                {3, 7, 4, 1},
                {10, 2, 0, 3}
            };
            int min_val = INT_MAX, max_val = INT_MIN;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(a[i][j] > max_val) max_val = a[i][j];
                    if(a[i][j] < min_val) min_val = a[i][j];
                }
            }
            cout << "Gia tri nho nhat : " << min_val << endl;
            cout << "Gia tri lon nhat : " << max_val << endl;
            return 0;
        }

> Output : 

        Gia tri nho nhat : 0
        Gia tri lon nhat : 10
        
- Ví dụ 2 : Liệt kê các số Fibonacci trong mảng 2 chiều

        #include <iostream>
        #include <math.h>
        
        using namespace std;
        
        bool fibo(long long n){
            long long F[100];
            F[0] = 0; F[1] = 1;
            for(int i = 2; i <= 92; i++){
                F[i] = F[i - 1] + F[i - 2];
            }
            for(int i = 0; i <= 92; i++){
                if(n == F[i]) return true;
            }
            return false;
        }
        
        int main(){
            int n = 4, m = 4;
            int a[4][4] = {
                {3, 1, 0, 7},
                {2, 5, 10, 3},
                {3, 7, 4, 1},
                {10, 2, 0, 3}
            };
            cout << "Cac so fibonacci : \n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(fibo(a[i][j])){
                        cout << a[i][j] << " ";
                    }
                }
            }
            return 0;
        }
  
> Output : 

        Cac so fibonacci : 
        3 1 0 2 5 3 3 1 2 0 3 

## 2. Bài Toán Xét Hàng, Cột
- Dạng bài tập này thường yêu cầu các bạn xét từng hàng hoặc từng cột của mảng 2 chiều. 
- Đối với bài toán xét theo hàng bạn duyệt như bình thường còn đối với bài toán duyệt theo cột thì bạn cần để vòng for ngoài duyệt theo cột và vòng for con bên trong duyệt theo hàng. 
- Ví dụ 1 : Tính tổng từng hàng, từng cột của mảng 2 chiều

        #include <iostream>
        #include <math.h>
        
        using namespace std;
        
        int main(){
            int n = 4, m = 4;
            int a[4][4] = {
                {3, 1, 0, 7},
                {2, 5, 10, 3},
                {3, 7, 4, 1},
                {10, 2, 0, 3}
            };
            //Duyệt theo hàng, i là hàng, j là cột
            for(int i = 0; i < n; i++){
                int tong = 0;
                for(int j = 0; j < m; j++){
                    tong += a[i][j];
                }
                cout << "Tong hang " << i + 1 << " : " << tong << endl;
            }
            //Duyệt theo cột, i là cột, j là hàng
            for(int i = 0; i < m; i++){
                int tong = 0;
                for(int j = 0; j < n; j++){
                    tong += a[j][i];
                }
                cout << "Tong cot " << i + 1 << " : " << tong << endl;
            }
            return 0;
        }

> Output : 

        Tong hang 1 : 11
        Tong hang 2 : 20
        Tong hang 3 : 15
        Tong hang 4 : 15
        Tong cot 1 : 18
        Tong cot 2 : 15
        Tong cot 3 : 14
        Tong cot 4 : 14
        
- Ví dụ 2 : Tìm hàng có nhiều số nguyên tố nhất 

        #include <iostream>
        #include <math.h>
        
        using namespace std;
        
        bool nt(int n){
            for(int i = 2; i <= sqrt(n); i++){
                if(n % i == 0) return false;
            }
            return n > 1;
        }
        
        int main(){
            int n = 4, m = 4;
            int a[4][4] = {
                {3, 1, 0, 7},
                {2, 5, 10, 3},
                {3, 7, 4, 1},
                {10, 2, 0, 3}
            };
            //Duyệt theo hàng, i là hàng, j là cột
            int res = 0, hang = -1;
            for(int i = 0; i < n; i++){
                int dem = 0;
                for(int j = 0; j < m; j++){
                    if(nt(a[i][j])){
                        ++dem;
                    }
                }
                if(dem > res){
                    res = dem; hang = i;
                }
            }
            cout << "Hang " << hang << " co nhieu so nguyen to nhat\n";
            cout << "So luong so nguyen to : " << res << endl;
            return 0;
        }
  
> Output : 

        Hang 1 co nhieu so nguyen to nhat
        So luong so nguyen to : 3
        
- Ví dụ 3 : Tìm cột có nhiều số nguyên tố nhất, nếu có nhiều cột có cùng số nguyên tố thì chọn cột có số thứ tự lớn hơn

        #include <iostream>
        #include <math.h>
        
        using namespace std;
        
        bool nt(int n){
            for(int i = 2; i <= sqrt(n); i++){
                if(n % i == 0) return false;
            }
            return n > 1;
        }
        
        int main(){
            int n = 4, m = 4;
            int a[4][4] = {
                {3, 1, 0, 7},
                {2, 5, 10, 3},
                {3, 7, 4, 1},
                {10, 2, 0, 3}
            };
            //Duyệt theo hàng, i là hàng, j là cột
            int res = 0, cot = -1;
            for(int i = 0; i < m; i++){
                int dem = 0;
                for(int j = 0; j < n; j++){
                    if(nt(a[j][i])){
                        ++dem;
                    }
                }
                if(dem >= res){
                    res = dem; cot = i;
                }
            }
            cout << "Cot " << cot << " co nhieu so nguyen to nhat\n";
            cout << "So luong so nguyen to : " << res << endl;
            return 0;
        }
  
> Output : 

        Cot 3 co nhieu so nguyen to nhat
        So luong so nguyen to : 3
        
## 3. Hoán Vị Hàng, Cột
- Để hoán vị 2 hàng của mảng 2 chiều thì bạn duyệt qua từng cột còn để hoán vị 2 cột thì bạn lại duyệt qua từng hàng.
- Ví dụ 1 : Bài toán hoán vị 2 hàng

        #include <iostream>
        #include <math.h>
        
        using namespace std;
        
        int main(){
            int n = 4, m = 4;
            int a[4][4] = {
                {3, 1, 0, 7},
                {2, 5, 10, 3},
                {3, 7, 4, 1},
                {10, 2, 0, 3}
            };
            int h1 = 0, h2 = 3;
            for(int i = 0; i < m; i++){
                //a[h1][i] va a[h2][i]
                swap(a[h1][i], a[h2][i]);
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }
  
> Output : 

        10 2 0 3 
        2 5 10 3 
        3 7 4 1 
        3 1 0 7 
        
- Ví dụ 2 : Bài toán hoán vị 2 cột

        #include <iostream>
        #include <math.h>
        
        using namespace std;
        
        int main(){
            int n = 4, m = 4;
            int a[4][4] = {
                {3, 1, 0, 7},
                {2, 5, 10, 3},
                {3, 7, 4, 1},
                {10, 2, 0, 3}
            };
            int c1 = 0, c2 = 3;
            for(int i = 0; i < n; i++){
                //a[i][c1] va a[i][c2]
                swap(a[i][c1], a[i][c2]);
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }
  
> Output : 

        7 1 0 3 
        3 5 10 2 
        1 7 4 3 
        3 2 0 10 

## 4. Sắp Xếp Ma Trận Theo Hàng, Cột
- Sắp xếp theo hàng
- Sắp xếp theo hàng trên ma trận thì bạn có thể tự code một hàm sắp xếp mảng 1 chiều sau đó áp dụng với từng hàng của mảng 2 chiều.
- Như mình có nhắc ở phần lý thuyết mảng 2 chiều thì mảng 2 chiều thực chất chính là 1 mảng các mảng 1 chiều, mỗi dòng trên mảng 2 chiều chính là 1 mảng 1 chiều.
- `Cách 1 : Sắp xếp hàng bằng hàm sort()`

        #include <iostream>
        #include <algorithm>
        
        using namespace std;
        
        int main(){
            int n = 4, m = 4;
            int a[4][4] = {
                {3, 1, 0, 7},
                {2, 5, 10, 3},
                {3, 7, 4, 1},
                {10, 2, 0, 3}
            };
            for(int i = 0; i < n; i++){
                sort(a[i], a[i] + m);
            }
            cout << "Mang 2 chieu sap xep theo hang : \n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }
  
> Output : 

        Mang 2 chieu sap xep theo hang : 
        0 1 3 7 
        2 3 5 10 
        1 3 4 7 
        0 2 3 10 

# III. Ma Trận Và Mảng 2 Chiều C++
Mảng 2 chiều thường được sử dụng để lưu trữ dữ liệu cho các bài toán liên quan tới ma trận, trong bài viết này mình nhắc lại những khái niệm quan trọng với ma trận
## 1. Ma Trận
- Ma trận là một khái niệm quan trọng trong môn học đại số tuyến tính nhưng nếu bạn chưa học đại số tuyến tính thì cũng không có vấn đề gì khó khăn khi tiếp cận với ma trận.
- Ma trận là một bảng số gồm các hàng và các cột, ví dụ ma trận A có n hàng và m cột thì sẽ được ký hiệu : Anxm 
- Do đó khi cần lưu trữ ma trận trong lập trình C++ thì bạn chỉ cần sử dụng một mảng 2 chiều 
- Ma trận có số hàng và số cột bằng nhau gọi là ma trận vuông. 
## 2. Đường Chéo Chính, Phụ
- Trong ma trận vuông thì đường chéo chính chứa những phần tử có chỉ số hàng và cột bằng nhau

![image](https://github.com/minchangggg/DSA/assets/125820144/8987882d-8f2c-4061-ad30-1f1edce2b5a7)

- Ví dụ 1 : Liệt kê các số nguyên tố trên đường chéo chính  

        #include <iostream>
        #include <math.h>
        #include <algorithm>
        
        using namespace std;
        
        bool nt(int n){
            for(int i = 2; i <= sqrt(n); i++){
                if(n % i == 0) return false;
            }
            return n > 1;
        }
        
        int main(){
            int n = 4; //hang va cot deu la 4
            int a[4][4] = {
                {3, 1, 0, 7},
                {2, 5, 10, 3},
                {3, 7, 4, 1},
                {10, 2, 0, 11}
            };
            cout << "Cac so nguyen to tren duong cheo chinh : ";
            for(int i = 0; i < n; i++){
                if(nt(a[i][i])){
                    cout << a[i][i] << " ";
                }
            }
            return 0;
        }

> Output : 

        Cac so nguyen to tren duong cheo chinh : 3 5 11

- Trong ma trận vuông thì đường chéo phụ chứa các phần tử như hình dưới

![image](https://github.com/minchangggg/DSA/assets/125820144/24c52c63-55e9-4f65-8fc9-992863f7d33f)

- Ví dụ 2 : Liệt kê các số nguyên tố trên đường chéo phụ

        #include <iostream>
        #include <math.h>
        #include <algorithm>
        
        using namespace std;
        
        bool nt(int n){
            for(int i = 2; i <= sqrt(n); i++){
                if(n % i == 0) return false;
            }
            return n > 1;
        }
        
        int main(){
            int n = 4; //hang va cot deu la 4
            int a[4][4] = {
                {3, 1, 0, 7},
                {2, 5, 10, 3},
                {3, 17, 4, 1},
                {10, 2, 0, 11}
            };
            cout << "Cac so nguyen to tren duong cheo phu : ";
            for(int i = 0; i < n; i++){
                if(nt(a[i][n - i - 1])){
                    cout << a[i][n - i - 1] << " ";
                }
            }
            return 0;
        }
  
> Output : 

        Cac so nguyen to tren duong cheo phu : 7 17

## 3. Tam Giác Trên, Dưới
- Tam giác dưới chứa các phần tử từ đường chéo chính đổ xuống, các phần tử màu vàng trong hình dưới

![image](https://github.com/minchangggg/DSA/assets/125820144/5b3e38e2-3666-4078-8074-4c6200a0c813)

- Ví dụ 1 : Tính tổng các phần tử trong tam giác dưới 

        #include <iostream>
        #include <math.h>
        #include <algorithm>
        
        using namespace std;
        
        int main(){
            int n = 4; //hang va cot deu la 4
            int a[4][4] = {
                {3, 1, 0, 7},
                {2, 5, 10, 3},
                {3, 17, 4, 1},
                {10, 2, 0, 11}
            };
            int tong = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j <= i; j++){
                    tong += a[i][j];
                }
            }
            cout << "Tong cac so trong tam giac duoi : " << tong << endl;
            return 0;
        }
  
> Output : 

        Tong cac so trong tam giac duoi : 57
        
- Tam giác trên chứa các phần tử từ đường chéo chính đổ lên, các phần tử màu vàng trong hình dưới

![image](https://github.com/minchangggg/DSA/assets/125820144/0ed22852-4d43-4fdb-9ace-fa0d79f4c20c)

- Ví dụ 2 : Tính tổng các phần tử trong tam giác trên

        #include <iostream>
        #include <math.h>
        #include <algorithm>
        
        using namespace std;
        
        int main(){
            int n = 4; //hang va cot deu la 4
            int a[4][4] = {
                {3, 1, 0, 7},
                {2, 5, 10, 3},
                {3, 17, 4, 1},
                {10, 2, 0, 11}
            };
            int tong = 0;
            for(int i = 0; i < n; i++){
                for(int j = i; j < n; j++){
                    tong += a[i][j];
                }
            }
            cout << "Tong cac so trong tam giac tren : " << tong << endl;
            return 0;
        }
  
> Output : 

        Tong cac so trong tam giac tren : 45

## 4. Ma Trận Chuyển Vị
- Ma trận chuyển vị của ma trận A có n hàng và m cột là ma trận AT có m hàng và n cột, trong đó các phần tử ở hàng của ma trận A sẽ thành cột của của ma trận AT

![image](https://github.com/minchangggg/DSA/assets/125820144/d415336c-891d-4bbe-8960-a633a43e7f81)

- Ví dụ : In ra ma trận chuyển vị của ma trận A

        #include <iostream>
        #include <math.h>
        #include <algorithm>
        
        using namespace std;
        
        int main(){
            int n = 3, m = 4;
            int a[3][4] = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12}
            };
            int b[4][3];
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    b[i][j] = a[j][i];
                }
            }
            cout << "Ma tran chuyen vi : \n";
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    cout << b[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }
  
> Output : 
        
        Ma tran chuyen vi : 
        1 5 9 
        2 6 10 
        3 7 11 
        4 8 12

# IV. Cộng, Trừ, Nhân 2 Ma Trận C++
## 1. Cộng, Trừ 2 Ma Trận
- Điều kiện để 2 ma trận có thể cộng trừ với nhau đó là chúng cần có cùng số hàng và cột.
- Giả sử cần cộng 2 ma trận A và B có cùng hàng và cột để tạo ra ma trận tổng C thì C[i][j] = A[i][j] + B[i][j] 

![image](https://github.com/minchangggg/DSA/assets/125820144/0c93f1fd-3ccb-4de3-9f54-6a322dfd620b)

- Phép trừ 2 ma trận thì bạn làm tương tự
  
![image](https://github.com/minchangggg/DSA/assets/125820144/a95ea42d-d288-4bc0-ab65-02671d949e3f)

- Code : 

        #include <iostream>
        #include <math.h>
        #include <algorithm>
        
        using namespace std;
        
        int main(){
            int n = 3, m = 4;
            int a[3][4] = {
                {2, 3, 1, 4},
                {2, 2, 0, 7},
                {1, 3, 5, 1}
            };
            int b[3][4] = {
                {2, 0, 7, 8},
                {1, 3, 5, 2},
                {3, 2, 8, 1}
            };
            int tong[3][4], hieu[3][4];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    tong[i][j] = a[i][j] + b[i][j];
                    hieu[i][j] = a[i][j] - b[i][j];
                }
            }
            printf("Tong 2 ma tran : \n");
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << tong[i][j] << " ";
                }
                cout << endl;
            }
            printf("Hieu 2 ma tran : \n");
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << hieu[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }
  
> Output : 

        Tong 2 ma tran : 
        4 3 8 12 
        3 5 5 9 
        4 5 13 2 
        Hieu 2 ma tran : 
        0 3 -6 -4 
        1 -1 -5 5 
        -2 1 -3 0 

## 2. Nhân 2 Ma Trận
![image](https://github.com/minchangggg/DSA/assets/125820144/19305d8a-0ce4-4a96-bc82-fad061d3302b)

- Ví dụ : 
  + A[3][4] x B[4][2] = C[3][2]
  + A[3][4] x B[4][5] = C[3][5]
  + A[2][4] X B[2][3] = Không xảy ra

![image](https://github.com/minchangggg/DSA/assets/125820144/e5f6208c-9092-42a3-9ce5-41baa9b0d8ff)

- Để tạo ra ma trận tích C thì C[i][j] = ∑A[i][k] * B[k][j] với k chạy từ 0 tới m (p)
- Hiểu đơn giản thì khi tích phần tử C[i][j] bạn sẽ nhân lần lượt các phần tử ở hàng i của ma trận A với các phần tử ở cột j của ma trận b sau đó cộng dồn lại
- Code : 

        #include <iostream>
        #include <math.h>
        #include <algorithm>
        
        using namespace std;
        
        int main(){
            int n = 2, m = 3, q = 2;
            //a[n][m], b[m][q]
            int a[n][m] = {
                {1, 2, 3},
                {4, 5, 6}
            };
            int b[m][q] = {
                {10, 11},
                {20, 22},
                {30, 33}
            };
            int c[n][q];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < q; j++){
                    c[i][j] = 0;
                    for(int k = 0; k < m; k++){
                        c[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
            cout << "Tich 2 ma tran : \n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < q; j++){
                    cout << c[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }
  
> Output : 

        Tich 2 ma tran : 
        140 154 
        320 352 

# V. Kĩ thuật duyệt các ô liền kề
![image](https://github.com/minchangggg/DSA/assets/125820144/fc779a4e-0df6-404d-a482-2e5c68bf517e)
## 1. Duyệt 4 ô chung cạnh với ô [i][j]

        #include <bits/stdc++.h>
        using namespace std;
        
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};
        
        int main(){
          int a[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
          };
          int i = 1, j = 1;
          for(int k = 0; k < 4; k++){
            int i1 = i + dx[k], j1 = j + dy[k];
            cout << a[i1][j1] << " ";
          }
        } 

> OUTPUT:

        2 4 6 8

## 2. Duyệt 8 ô chung đỉnh với ô [i][j]
        
        #include <bits/stdc++.h>
        using namespace std;
        
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        int main(){
          int a[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
          };
          int i = 1, j = 1;
          for(int k = 0; k < 8; k++){
            int i1 = i + dx[k], j1 = j + dy[k];
            cout << a[i1][j1] << " ";
          }
        } 

> OUTPUT:

        1 2 3 4 6 7 8 9

## 3. Duyệt 8 ô xung quanh nước đi của quân mã
![image](https://github.com/minchangggg/DSA/assets/125820144/98b9a35c-7630-4295-bf62-12c9e1661c97)

        #include <bits/stdc++.h>
        using namespace std;
        
        int dx[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
        int dy[8] = {-1, +1, -2, +2, -2, +2, -1, +1};
        
        int main(){
          int a[6][6] = {
            {1, 2, 3, 4, 5, 6},
            {7, 8, 9, 1, 2, 5},
            {1, 2, 1, 0, 3, 5},
            {1, 2, 1, 3, 4, 9},
            {1, 2, 1, 3, 0, 4},
            {1, 8, 7, 6, 2, 9}
          };
          int i = 2, j = 3;
          for(int k = 0; k < 8; k++){
            int i1 = i + dx[k], j1 = j + dy[k];
            cout << a[i1][j1] << " ";
          }
        } 

> OUTPUT:

        3 5 8 5 2 9 1 0

# VI. Ma Trận Xoắn Ốc C++
## 1. Ma Trận Xoắn Ốc
- Ma trận xoáy ốc (Spiral matrix) là một ma trận vuông có N dòng và N cột, các số trong ma trận được sắp xếp như một xoáy ốc gồm các số từ 1 tới N2.
- Ma trận xoáy ốc cũng có thể là một ma trận không vuông có N dòng và M cột, các số trong ma trận được đánh số từ 1 tới N * M theo hình xoáy ốc
- Ví dụ dưới đây là một ma trận xoáy ốc cỡ 5

![image](https://github.com/minchangggg/DSA/assets/125820144/679471df-2fb8-4998-abc1-1b99695ccd65)

- Để xây dựng ma trận xoáy ốc thì ta tiến hành xây dựng từng vòng của xoáy ốc gồm 4 cạnh và lưu vào một mảng 2 chiều cỡ N x N 
- Ta duy trì 4 biến số : 
  + h1 : hàng trên của xoáy ốc
  + h2 : hàng dưới của xoáy ốc
  + c1 : cột trái của xoáy ốc
  + c2 : cột phải của xoáy ốc 
- Ví dụ khi bạn xây dựng xoáy ốc ngoài cùng này thì h1, h2, c1, c2 sẽ có giá trị như sau : 

![image](https://github.com/minchangggg/DSA/assets/125820144/e9139fc5-c6b6-493d-894a-86a066072b67)

- Sau khi xây dựng xong vòng xoáy ốc ngoài cùng, ta sẽ tăng h1, giảm h2, tăng c1, giảm c2 để xây dựng vòng xoáy ốc tiếp theo

![image](https://github.com/minchangggg/DSA/assets/125820144/f30ea115-007b-47c9-92d7-4095845464b7)

- Code : 

        #include <iostream>
        #include <math.h>
        
        using namespace std;
        
        int main(){
            int n = 5;
            int a[100][100];
            int h1 = 0, h2 = n - 1, c1 = 0, c2 = n - 1;
            int dem = 1;
            while(h1 <= h2 && c1 <= c2){
                //Xây dựng cạnh trên : hàng h1 từ cột c1 => cột c2
                for(int i = c1; i <= c2; i++){
                    a[h1][i] = dem; ++dem;
                }
                //Tăng h1 để xây dựng cạnh bên phải, cột c2 từ hàng h1 tới hàng h2
                ++h1;
                for(int i = h1; i <= h2; i++){
                    a[i][c2] = dem; ++dem;
                }
                //giảm c2 để xây dựng cạnh dưới, hàng h2 từ c2 => cột c1
                --c2;
                for(int i = c2; i >= c1; i--){
                    a[h2][i] = dem; ++dem;
                }
                //giảm h2 để xây dựng cạnh bên phải, cột c1 từ hàng h2 tới hàng h1
                --h2;
                for(int i = h2; i >= h1; i--){
                    a[i][c1] = dem; ++dem;
                }
                //tăng c1
                ++c1;
            }
            cout << "Ma tran xoay oc co 5 : \n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }
  
> Output : 

        Ma tran xoay oc co 5 : 
        1 2 3 4 5 
        16 17 18 19 6 
        15 24 25 20 7 
        14 23 22 21 8 
        13 12 11 10 9 

## 2. Ma Trận Xoắn Ốc Nguyên Tố
- Ma trận xoáy ốc nguyên tố là ma trận xoáy ốc nhưng các số xuất hiện trong ma trận sẽ là các số nguyên tố từ nhỏ tới lớn. 
- Ví dụ ma trận xoáy ốc cỡ 5 thì bạn cần 25 số nguyên tố đầu tiên
- Cách xây dựng ma trận xoáy ốc nguyên tố tương tự xây dựng ma trận xoáy ốc thường, ta cần chuẩn bị trước 1 số lượng số nguyên tố vừa đủ với số lượng phần tử trong ma trận xoáy ốc và gán lần lượt.

![image](https://github.com/minchangggg/DSA/assets/125820144/737ebf0d-63f8-4fae-929a-d08872125d61)

- Code : 

        #include <iostream>
        #include <math.h>
        
        using namespace std;
        
        bool nt(int n){
            for(int i = 2; i <= sqrt(n); i++){
                if(n % i == 0) return false;
            }
            return n > 1;
        }
        
        int main(){
            int n = 5;
            int a[100][100];
            int X[10000], idx = 0, i = 0;
            while(idx < n * n){
                if(nt(i)){
                    X[idx] = i; ++idx;
                }
                ++i;
            }
            int h1 = 0, h2 = n - 1, c1 = 0, c2 = n - 1;
            int dem = 0;
            while(h1 <= h2 && c1 <= c2){
                for(int i = c1; i <= c2; i++){
                    a[h1][i] = X[dem]; ++dem;
                }
                ++h1;
                for(int i = h1; i <= h2; i++){
                    a[i][c2] = X[dem]; ++dem;
                }
                --c2;
                for(int i = c2; i >= c1; i--){
                    a[h2][i] = X[dem]; ++dem;
                }
                --h2;
                for(int i = h2; i >= h1; i--){
                    a[i][c1] = X[dem]; ++dem;
                }
                ++c1;
            }
            cout << "Ma tran xoay oc nguyen to co 5 :\n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }
  
> Output : 

        Ma tran xoay oc nguyen to co 5 : 
        2 3 5 7 11 
        53 59 61 67 13 
        47 89 97 71 17 
        43 83 79 73 19 
        41 37 31 29 23 

## 3. Ma Trận Xoắn Ốc Fibonacci
- Ma trận xoáy ốc Fibonacci chứa các số lần lượt là các số trong dãy Fibonacci, bạn tiến hành xây dựng trước mảng các số Fibo và gán lần lượt cho ma trận xoáy ốc
- Thông thường cỡ ma trận xoáy ốc Fibonacci không quá 9

![image](https://github.com/minchangggg/DSA/assets/125820144/5b14b0e7-4a01-4335-8fd1-c28faee6de81)

- Code : 

        #include <iostream>
        #include <math.h>
        
        using namespace std;
        
        int main(){
            int n = 4;
            long long a[100][100];
            long long F[100];
            F[0] = 0; F[1] = 1;
            for(int i = 2; i < n * n; i++){
                F[i] = F[i - 1] + F[i - 2];
            }
            int h1 = 0, h2 = n - 1, c1 = 0, c2 = n - 1;
            int dem = 0;
            while(h1 <= h2 && c1 <= c2){
                for(int i = c1; i <= c2; i++){
                    a[h1][i] = F[dem]; ++dem;
                }
                ++h1;
                for(int i = h1; i <= h2; i++){
                    a[i][c2] = F[dem]; ++dem;
                }
                --c2;
                for(int i = c2; i >= c1; i--){
                    a[h2][i] = F[dem]; ++dem;
                }
                --h2;
                for(int i = h2; i >= h1; i--){
                    a[i][c1] = F[dem]; ++dem;
                }
                ++c1;
            }
            cout << "Ma tran xoay oc Fibonacci co 4 : \n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }
  
> Output : 

        Ma tran xoay oc Fibonacci co 4 : 
        0 1 1 2 
        89 144 233 3 
        55 610 377 5 
        34 21 13 8 
