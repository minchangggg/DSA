> https://200lab.io/blog/de-quy-la-gi/
>
> https://viblo.asia/p/de-quy-va-giai-thuat-de-quy-gGJ5969JKX2
>
> https://www.geeksforgeeks.org/introduction-to-recursion-2/
>
> https://topdev.vn/blog/de-quy-la-gi/
>
> https://howkteam.vn/course/cau-truc-du-lieu-va-giai-thuat/de-quy-4281

Bài tập ví dụ:

> https://viblo.asia/p/nhung-bai-tap-ap-dung-de-quy-thuong-gap-trong-c-gwd43jZAVX9
>
> https://viettruong92.blogspot.com/2011/12/bai-tap-e-quy.html
>
> https://www.dammio.com/2023/10/08/10-vi-du-bang-c-su-dung-de-quy

Sự khác nhau giữa đệ quy và quay lui.

> https://www.youtube.com/watch?v=nootqR6fz6k
# I. Hàm Đệ Quy
## 1. Cấu trúc dữ liệu ngăn xếp
### a. Stack
- Ngăn xếp (stack) là một cấu trúc dữ liệu có quan hệ mật thiết với cơ chế hoạt động của đệ quy. Để hiểu được cách hàm đệ quy hoạt động, ta cần nắm được cách hoạt động của cấu trúc dữ liệu ngăn xếp.
- Ngăn xếp là một cấu trúc dữ liệu hỗ trợ 2 thao tác push và pop. Trong đó push giúp thêm 1 phần tử vào đỉnh ngăn xếp, pop giúp xóa 1 phần tử khỏi đỉnh ngăn xếp. Cả 2 thao tác này đều được thực hiện ở đỉnh ngăn xếp.
- Ngăn xếp hoạt động theo nguyên tắc viết tắt là LIFO (Last In First Out) nghĩa là vào cuối thì ra đầu. Các phần tử vào cuối cùng sẽ được ra đầu tiên
  
![image](https://github.com/minchangggg/DSA/assets/125820144/290f58ca-cf51-44d7-ad1d-472cf48768ec)

- Trong chương trình tồn tại một bộ nhớ là bộ nhớ ngăn xếp, cách hoạt động của bộ nhớ này tương tự như cách hoạt động của cấu trúc dữ liệu ngăn xếp.
### b. Stack frame
![image](https://github.com/minchangggg/DSA/assets/125820144/e6797f82-2d9c-4e80-9705-f9d46826e96e)

- Những thành phần của stack frame có thể kể đến như biến cục bộ, đối số, địa chỉ trả về của một chương trình con. Mỗi khi một lời gọi hàm được thực hiện, stack frame chứa thông tin của hàm đó được đẩy vào bộ nhớ stack và khi hàm đó kết thúc thì stack frame này được loại bỏ khỏi bộ nhớ stack.

## 2. Định Nghĩa Hàm Đệ Quy
### a. Định nghĩa
- Hàm đệ quy được định nghĩa là hàm gọi lại chính nó. Có rất nhiều thuật toán và cấu trúc dữ liệu dựa trên kỹ thuật đệ quy này : Quick sort, Merge sort, DFS, Cây Phân Đoạn...
  
![image](https://github.com/minchangggg/DSA/assets/125820144/f21f4665-b67e-4a31-b663-b84b076435c3)

### b. Thành phần của một hàm đệ quy
- Một hàm đệ quy gồm 2 phần:
  + Phần cơ sở: Điều kiện để thoát khỏi đệ quy. Nếu như không có phần này, hàm đệ quy sẽ thực hiện mãi mãi gây ra tràn bộ nhớ Stack.
  + Phần đệ quy: Thân hàm có chứa phần gọi đệ quy, thực hiện cho đến khi thỏa mãn điều kiện ở phần cơ sở.
    
- Ví dụ : 

        #include <bits/stdc++.h>
        using namespace std;
        
        void recursive(int n){
           if(n > 0){ // Điều kiện 
              cout << n;
              recursive(n - 1);
           }
        }
        
        int main(){
           recursive(4);
           return 0;
        }

> Output : 

        4 3 2 1
### c. Nhận xét đệ quy
  + Ưu điểm: Thuận lợi cho việc biểu diễn bài toán, như ở ví dụ trên, nhìn vào hàm là chúng ta có thể thấy ngay nó biểu diễn dãy số fibonacci, hay tính giai thừa.
  + Nhược điểm: Tốn nhiều bộ nhớ, nếu không phần cơ sở (điểm dừng) thì sẽ gây ra việc tràn bộ nhớ stack. Bên cạnh đó việc sử dụng đệ quy tốn nhiều thời gian hơn vòng lặp.
## 2. Ví Dụ Về Đệ Quy
### a. Ví dụ 1 : 

        #include <bits/stdc++.h>
        using namespace std;
        
        void dequy(int n){
            if(n > 0){
                cout << "Loi goi ham khi n = " << n << endl;
                dequy(n - 1);
            }
            cout << "Ham khi n = " << n << " ket thuc !" << endl;
        }
        
        int main(){
            dequy(4);
            return 0;
        }

> Output : 

        Loi goi ham khi n = 4
        Loi goi ham khi n = 3
        Loi goi ham khi n = 2
        Loi goi ham khi n = 1
        Ham khi n = 0 ket thuc !
        Ham khi n = 1 ket thuc !
        Ham khi n = 2 ket thuc !
        Ham khi n = 3 ket thuc !
        Ham khi n = 4 ket thuc !

- Giải thích :

<1> dequy(4) được gọi trong main, hàm dequy với n = 4 được gọi, kiểm tra n > 0 nên sẽ thực hiện câu lệnh thứ 1 trong if và in ra nội dung : "Loi goi ham khi n = 4". Sau đó thực hiện câu lệnh dequy(n - 1) tương đương với dequy(3). Hàm dequy(3) sẽ chạy, dequy(4) sẽ đợi dequy(3) chạy xong để tiếp tục thực hiện câu lệnh bên dưới của if và kết thúc

<2> dequy(3) được chạy, kiểm tra n > 0 nên sẽ in ra nội dung "Loi goi ham khi n = 3". Sau đó xuống câu lệnh dequy(n - 1) tương đương với dequy(2). 

<3> dequy(2) được chạy, kiểm tra n > 0 nên sẽ in ra nội dung "Loi goi ham khi n = 2". Sau đó xuống câu lệnh dequy(n - 1) tương đương với dequy(1). 

<4> dequy(1) được chạy, kiểm tra n > 0 nên sẽ in ra nội dung "Loi goi ham khi n = 1". Sau đó xuống câu lệnh dequy(n - 1) tương đương với dequy(0). 

<5> dequy(2) được chạy, kiểm tra n > 0 không đúng nên 2 câu lệnh trong if của hàm dequy(0) không được thực hiện mà thực hiện câu lệnh cuối cùng trong hàm dequy(0) và in ra "Ham khi n = 0 ket thuc !"

<6> Sau khi dequy(0) chạy xong, quay lại bước thứ 4, khi hàm dequy(1) gọi dequy(0) ở câu lệnh thứ 2 trong if, hàm dequy(0) vừa chạy xong nên câu lệnh này cũng sẽ chạy xong, hàm dequy(1) sẽ thực hiện câu lệnh cuối cùng và in ra "Ham khi n = 1 ket thuc !"

<7> Sau khi dequy(1) chạy xong, quay lại bước thứ 3, hàm dequy(2) gọi dequy(1) ở câu lệnh thứ 2 trong if, hàm dequy(1) vừa chạy xong nên dequy(2) cũng thực hiện câu lệnh cuối cùng và in ra "Ham khi n = 2 ket thuc !"

<8> Hàm dequy(2) kết thúc, ở bước 2 dequy(3) gọi dequy(2) ở câu lệnh thứ 2 trong if giờ đã chạy xong, dequy(3) cũng thực hiện câu lệnh cuối cùng và in ra "Ham khi n = 3 ket thuc !"

<9> Hàm dequy(3) kết thúc, ở bước 1 dequy(4) gọi dequy(3) ở câu lệnh thứ 2 trong if giờ đã chạy xong, dequy(4) cũng thực hiện câu lệnh cuối cùng và in ra "Ham khi n = 4 ket thuc !"

### Ví dụ 2 : Tính tổng tự nhiên từ 1 tới N bằng đệ quy 

        #include <bits/stdc++.h>
        using namespace std;
        
        int sum(int n){
            if(n == 0) return 0;
            else return n + sum(n - 1);
        }
        
        int main(){
            cout << sum(3);
            return 0;
        }

> Output :

        6

- Giải thích : 

![image](https://github.com/minchangggg/DSA/assets/125820144/dcae0c4d-b04d-407a-994a-58f65b32cc24)

<1> Hàm sum(3) được gọi, khi đó n = 3, nên hàm sum(3) được thực hiện câu lệnh return n + sum(n - 1) tương ứng với 3 + sum(2). Vậy thì hàm sum(3) sẽ chưa kết thúc được ngay vì nó cần phải có giá trị của sum(2) rồi mới trả về được giá trị 

<2> Hàm sum(2) được gọi, khi đó n = 2, nên hàm sum(2) được thực hiện câu lệnh return n + sum(n - 1) tương ứng với 2 + sum(1)

<3> Hàm sum(1) được gọi, khi đó n = 1, nên hàm sum(1) được thực hiện câu lệnh return n + sum(n - 1) tương ứng với 1 + sum(0)

<4> Hàm sum(0) được gọi, khi đó n = 0 nên hàm sum(0) được return giá trị 0 và kết thúc 

<5> Trong bước 3, sum(0) sau khi được tính xong sẽ được + thêm 1 và trả về giá trị cho hàm sum(1), vì thế sum(1) kết thúc với giá trị trả về là 1

<6> Trong bước 2, sum(2) được return 2 + sum(1), sum(1) vừa được tính xong bằng 1 nên sum(2) kết thúc với trả về giá trị là 2 + 1 = 3

<7> Trong bước 1, sum(3) được return 3 + sum(2), sum(2) vừa chạy xong và có kết quả là 3 nên sum(3) kết thúc với giá trị trả về là 3 + 3 = 6

## 3. Công Thức Truy Hồi
- Có thể hiểu đơn giản công thức truy hồi giúp xác định giá trị của phần tử hay kết quả của 1 bài toán lớn hơn thông qua bài toán con nhỏ hơn đã biết trước kết quả.
- Ví dụ khi bạn cần tìm số Fibonacci thứ 10 bạn có thể sử dụng số Fibonacci thứ 8 và 9. Và công thức truy hồi của dãy Fibonacci là : Fn = Fn-1 và Fn-2
- Vậy khi sử dụng đệ quy để tính toán kết quả của các bài toán bạn cần xác định cho mình :
  + Bài toán cơ sở - bài toán con nhỏ nhất mà bạn đã biết giá trị -> làm điểm dừng cho hàm đệ quy
  + Công thức truy hồi -> tìm ra lời giải của bài toán lớn hơn thông qua đáp án của bài toán nhỏ hơn.
- Khi code đệ quy bạn chỉ cần kiểm tra xem lời gọi đệ quy của bạn đã gọi tới bài toán cơ sở chưa, đây sẽ là điểm dừng cho lời gọi đệ quy. Nếu chưa phải bài toán con nhỏ nhất thì bạn sẽ trả về công thức truy hồi thông qua lời gọi đệ quy
- Lưu ý: Nếu đệ quy không có điểm dừng, khi số lượng hàm đệ quy gọi đủ lớn sẽ làm bộ nhớ stack bị tràn.
### Ví dụ 1 : Tìm số Fibonacci bằng đệ quy
- Bài toán cơ sở : F0 = 0, F1 = 1
- Công thức truy hồi : Fn = (Fn-1) + (Fn-2) với n > 1
- Lưu ý là code này chạy rất chậm nếu n lớn
- Code :

        #include <bits/stdc++.h>
        using namespace std;
        
        int F(int n){
            if(n == 0 || n == 1) return n;
            else return F(n - 1) + F(n - 2);
        }
        
        int main(){
            cout << F(10);
            return 0;
        }
        
> Output :
        
        55

### Ví dụ 2 : Tính giai thừa bằng đệ quy
- Bài toán cơ sở : 0! = 1
- Công thức truy hồi : N! = N * (N - 1)! với n > 0
- Code : 

        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        
        ll factorial(int n){
            if(n == 0) return 1;
            else return n * factorial(n - 1);
        }
        
        int main(){
            cout << factorial(10);
            return 0;
        }

> Output :
        
        3628800

### Ví dụ 3 : Tính tổng chữ số của số tự nhiên N
- Gọi Sum(N) là hàm tính tổng chữ số của N
- Bài toán cơ sở : Sum(N) = N nếu N < 10
- Công thức truy hồi : Sum(N) = N % 10 + Sum(N / 10) với N ≥ 10
- Code :
  
        #include <bits/stdc++.h>
        using namespace std;
                
        int sum(int n){
            if(n < 10) // nếu số đó chữ có 1 chữ số 
                return n;
            else
                return n % 10 + sum(n / 10);
        }
        
        int main(){
            cout << sum(12345);
            return 0;
        }

> Output :
        
        15

## 4. Stack Overflow
- Stack Overflow hay tràn bộ nhớ ngăn xếp là một tình trạng hay xảy ra khi bạn code đệ quy, bản chất của đệ quy là sinh ra các lời gọi hàm và mỗi lần lời gọi hàm được gọi thì nó sẽ chiếm 1 chỗ trong bộ nhớ ngăn xếp.
- Nếu bộ nhớ ngăn xếp không được giải phóng thì tới một lúc nào đó nó sẽ bị tràn và làm chương trình của các bạn bị dừng đột ngột.
- Ví dụ sau sẽ gây tràn bộ nhớ ngăn xếp : 

        #include <stdio.h>
        
        void stackoverflow(){
           printf("28tech\n");
           stackoverflow();
           printf("end\n");
        }
        
        int main(){
           stackoverflow();
           return 0;
        }

- Trong ví dụ, hàm stackoverflow() sẽ chỉ thực hiện được câu lệnh đầu tiên in ra 28tech, sau đó nó lại gọi hàm stackoverflow(), quá trình này lặp đi lặp lại nhưng không có lời gọi hàm stackoverflow() nào được kết thúc để các lời gọi ban đầu được thực hiện câu lệnh thứ 3 và kết thúc hàm. 
- Đây như là một quá trình gọi hàm liên tục và không có hồi kết cho tới khi bộ nhớ ngăn xếp không đủ để lưu thông tin các lời gọi hàm đã được gọi.

# II. Bài Tập Đệ Quy
## 1. Số Fibonacci, Tổ Hợp
### a. Số Fibonacci 
- Số Fibonacci có thể tính bằng hàm đệ quy dựa trên bài toán cơ sở và công thức truy hồi : 
  + Bài toán cơ sở : F0 = 0, F1 = 1
  + Công thức truy hồi : Fn = Fn-1 + Fn-2, n > 1
- Code :
  
        #include <bits/stdc++.h>
        using namespace std;
        
        int F(int n){
            if(n == 0 || n == 1) return n;
            else return F(n - 1) + F(n - 2);
        }
        
        int main(){
            cout << F(12);
            return 0;
        }

> Output :

        144

### b. Tổ hợp chập K của N 
- Tổ hợp chập K của N (C(n, k)) được tính đệ quy dựa vào bài toán cơ sở và công thức truy hồi sau :
  + Bài toán cơ sở : C(n, 0) = 1 và C(n, n) = 1
  + Công thức truy hồi : C(n, k) = C(n - 1, k - 1) + C(n - 1, k) 
- Code : 

        #include <bits/stdc++.h>
        using namespace std;
        
        int C(int n, int k){
           if(n == k || k == 0) return 1;
           else return C(n - 1, k - 1) + C(n - 1, k);
        }
        
        int main(){
           cout << C(12, 2);
           return 0;
        }

> Output :
        
        66
## 2. Chuyển Đổi Cơ Số
### a. Hệ nhị phân
- Hệ nhị phân biểu diễn số dưới 2 bit là 0 và 1, khi chuyển từ số thập phân N sang số nhị phân bạn thực hiện quá trình chia N cho 2 cho tới khi N = 0, viết ngược lại các số dư của N trong quá trình chia cho 2 đó sẽ được biểu diễn dưới dạng nhị phân.
- Ví dụ N = 37 thì biểu diễn nhị phân của N sẽ là 100101
  
![image](https://github.com/minchangggg/DSA/assets/125820144/1730b327-774e-4260-82d2-0587e08fb0cc)

- Code : 

        #include <bits/stdc++.h>
        using namespace std;
        
        void dec_to_bin(long long n){
           if(n < 2)
              cout << n;
           else{
              dec_to_bin(n / 2);
              cout << n % 2; 
           }
        }
        
        int main(){
           dec_to_bin(37);
           cout << endl;
           dec_to_bin(282828282828);
           return 0;
        }

> Output :

        100101
        100000111011001111000010001101111001100

### b. Hệ thập lục phân
- Hệ thập lục phân hay hệ 16 biểu diễn số thông qua 16 ký tự gồm các chữ số từ 0 tới 9, các số từ 10 tới 15 được thay thế thành các chữ cái từ A tới F. 
- Tương tự như chuyển từ hệ thập phân sang hệ 16 thì ta thực hiện chia cho 16 và lưu lại số dư trong quá trình chia, viết ngược lại số dư trong quá trình chia ta được biểu diễn dưới hệ số 16
- Ví dụ N = 762 thì biểu diễn hệ 16 là 2FA

![image](https://github.com/minchangggg/DSA/assets/125820144/a76a2324-b4fb-4b4a-8c76-8c8da6ebdcec)

- Code : 

        #include <bits/stdc++.h>
        using namespace std;
        
        void dec_to_hex(long long n){
            if(n < 16){
                if(n < 10) cout << n;
                else cout << (char)(55 + n);
            }
            else{
                dec_to_hex(n / 16);
                int r = n % 16;
                if(r < 10) cout << r;
                else cout << (char)(55 + r);
            }
        }
        
        int main(){
            dec_to_hex(762);
            cout << endl;
            dec_to_hex(282828282828);
            return 0;
        }

> Output : 

        2FA
        41D9E11BCC

## 3.Các Bài Toán Liên Quan Tới Chữ Số
### Bài 1. Đếm số chữ số của số N
- Bài toán cơ sở : D(N) = 1 nếu N < 10
- Công thức truy hồi : D(N) = 1 + D(N / 10) nếu N ≥ 10
- Code : 

        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        
        int D(ll n){
            if(n < 10) return 1;
            else return 1 + D(n / 10);
        }
        
        int main(){
            ll n = 28282828;
            cout << D(n);
            return 0;
        }

> Output :
        
        8

### Bài 2 : Tính tổng chữ số của số N
- Bài toán cơ sở : S(N) = N nếu N < 10
- Công thức truy hồi : S(N) = N % 10 + S(N / 10) nếu N ≥ 10
- Code : 

        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        
        int S(ll n){
            if(n < 10) return n;
            else return n % 10 + S(n / 10);           
        }
        
        int main(){
            ll n = 28282828;
            cout << S(n);
            return 0;
        }

> Output :

        40

### Bài 3. Tính tổng chữ số chẵn (lẻ) của N
- Bài toán cơ sở : S(N) = 0 nếu N lẻ, N nếu N chẵn với N < 10
- Công thức truy hồi : S(N) = S(N / 10) nếu N lẻ, N % 10 + S(N / 10) nếu N chẵn với N ≥ 10
- Code : 

        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        
        int S(ll n){
            if(n < 10){
                if (n % 2) return 0;
                else return n;
            }
            else{
                if (n % 2) return S(n / 10);
                else return n % 10 + S(n / 10);
            }
        }
        
        int main(){
            ll n = 12345678;
            cout << S(n);
            return 0;
        }

> Output : 
        
        20

### Bài 4. Tìm chữ số lớn nhất (nhỏ nhất) của N
- Bài toán cơ sở : F(N) = N nếu N < 10
- Công thức truy hồi : F(N) = max(N % 10, F(N / 10)) với N ≥ 10
- Code : 

        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        
        int F(ll n){
            if(n < 10) return n;
            else{
                ll tmp = F(n / 10);
                return max(n % 10, tmp);
            }
        }
        
        int main(){
            ll n = 12349567;
            cout << F(n);
            return 0;
        }

> Output : 
        
        9
        
## 4. Các Bài Toán Liên Quan Tới Tổng Dãy Số
### Bài 1. Tổng tự nhiên liên tiếp S(n) = 1 + 2 + 3 + ... + n
- Bài toán cơ sở : S(n) = 1 nếu n = 1
- Công thức truy hồi : S(n) = n + S(n - 1) với n > 1
- Code : 

        #include <stdio.h>
        
        int S(int n){
           if(n == 1){
              return 1;
           }
           else{
              return n + S(n - 1);
           }
        }
        
        int main(){
           int n = 10;
           printf("%d", S(n));
           return 0;
        }

> Output : 
        
        55

### Bài 2. Tổng bình phương liên tiếp S(n) = 12 + 22 + 32 + ... + n2
- Bài toán cơ sở : S(n) = 1 nếu n = 1
- Công thức truy hồi : S(n) = n2 + S(n - 1) với n > 1
- Code : 

        #include <stdio.h>
        
        int S(int n){
           if(n == 1){
              return 1;
           }
           else{
              return n * n + S(n - 1);
           }
        }
        
        int main(){
           int n = 10;
           printf("%d", S(n));
           return 0;
        }

> Output : 
        
        385

### Bài 3. Tổng bình phương liên tiếp S(n) = 1/1 + 1/2 + 1/3 + .... + 1/n
- Bài toán cơ sở : S(n) = 1 nếu n = 1
- Công thức truy hồi : S(n) = 1/n + S(n - 1) với n > 1
- Code : 

        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        
        double S(int n){
            if(n == 1)
                return 1;
            else
                return (double) 1/n + S(n - 1);
        }
        
        int main(){
            int n = 10;
            cout << S(n);
            return 0;
        }

> Output :
        
        2.92897
## 5. Các Bài Toán Liên Quan Tới Mảng
### Bài 1. Tính tổng các số chẵn trong mảng 
- Code : 

        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        
        int even_sum(int a[], int n){
            if(n == 0) return 0;
            else{
                if(a[n - 1] % 2)
                    return even_sum(a, n - 1);
                else
                    return a[n - 1] + even_sum(a, n - 1);
            }
        }
        
        int main(){
            int n = 6;
            int a[] = {1, 2, 3, 4, 5, 6};
            cout << even_sum(a, n);
            return 0;
        }

> Output :
        
        12

### Bài 2 . Kiểm tra mảng đối xứng
- Code : 

        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        
        int doixung(int a[], int left, int right){
            if(left > right)
                return 1;
            else{
                if(a[left] != a[right])
                    return 0;
                else
                    return doixung(a, left + 1, right - 1);
            }
        }
        
        int main(){
            int n = 6;
            int a[] = {1, 2, 3, 3, 2, 1};
            (doixung(a, 0, n - 1)) ? cout << "Xau doi xung" : cout << "Xau khong doi xung";
            return 0;
        }

> Output : 

        Xau doi xung

### Bài 3. In ra mảng từ trái qua phải
- Code : 

        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        
        void left_to_right(int a[], int n){
            if(n > 0){
                left_to_right(a, n - 1);
                cout << a[n - 1];
            }
        }
        
        int main(){
            int n = 6;
            int a[] = {1, 2, 3, 4, 5, 6};
            left_to_right(a, 6);
            return 0;
        }

> Output : 
        
        1 2 3 4 5 6

### Bài 4. In ra mảng từ phải qua trái
- Code : 

        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        
        void right_to_left(int a[], int n){
            if(n > 0){
                cout << a[n - 1] << ' ';
                right_to_left(a, n - 1);
            }
        }
        
        int main(){
            int n = 6;
            int a[] = {1, 2, 3, 4, 5, 6};
            right_to_left(a, n);
            return 0;
        }

> Output : 
        
        6 5 4 3 2 1


## 5. Bài toán “Tháp Hà Nội” (Tower of Ha Noi)
> https://200lab.io/blog/bai-toan-thap-ha-noi/
> 
> https://www.youtube.com/watch?v=1bzO9aqEx9c

- Đây là một bài toán rất nổi tiếng và kinh điển, rất thích hợp để minh họa cho thuật toán đệ quy. Sau đây là nội dung bài toán : Có 3 chiếc cọc được đánh dấu lần lượt là A, B, C và n chiếc đĩa. Các đĩa này có kích thước khác nhau và mỗi đĩa đều có một lỗ ở giữa để cắm vào cọc. Ban đầu, các đĩa đều nằm ở cọc A, trong đó, đĩa nhỏ luôn nằm trên đĩa lớn hơn.

![image](https://github.com/minchangggg/DSA/assets/125820144/7cad5932-e425-4200-9d1b-541ff15a7a3f)

- Yêu cầu : chuyển n đĩa từ cọc A sang cọc đích C với các điều kiện sau :
  + Mỗi lần chỉ chuyển được 1 đĩa
  + Trong quá trình chuyển, đĩa nhỏ phải luôn nằm trên đĩa lớn hơn.
  + Cho phép sử dụng cọc B làm cọc trung gian
- Phân tích : ta sẽ xét các trường hợp của n
  + Trường hợp đơn giản nhất, n=1, ta chỉ cần chuyển 1 đĩa từ cọc A sang cọc C.
  + Nhiều hơn một chút, n=2, ta chuyển đĩa nhỏ nhất sang cọc B, chuyển đĩa còn lại sang cọc C, và cuối cùng chuyển đĩa nhỏ ở cọc B sang cọc C.
  + Bây giờ ta xét n đĩa (n>2). Giả sử ta đã có cách chuyển n-1 đĩa từ một cọc sang một cọc khác. Như vậy, để chuyển n đĩa từ cọc nguồn sang cọc đích, ta cần chuyển n-1 đĩa từ cọc nguồn sang cọc trung gian. Sau đó chuyển đĩa lớn nhất từ cọc nguồn sang cọc đích. Cuối cùng, chuyển n-1 từ cọc trung gian về cọc đích.
- Nhận xét: Bài toán Tháp Hà Nội (Tower of Hanoi) với số đĩa là n có thể được giải với số bước tối thiểu là 2^n−1. Do đó, với trường hợp 3 đĩa, bài toán Tháp Hà Nội (Tower of Hanoi) có thể được giải sau 2^3−1 = 7 bước.
- Minh họa:
  
![image](https://github.com/minchangggg/DSA/assets/125820144/f4121413-0c3a-45ac-a7ab-ea35099805ec)

- Code

        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        
        void move(int num, char sourcePeg, char targetPeg);
        void TOH(int num, char sourcePeg, char auxiliaryPeg, char targetPeg);
        
        int main() {
            cout << "Enter the number of disks: ";
            int num = 0; cin >> num;
            char sourcePeg = 'A', auxiliaryPeg = 'B', targetPeg = 'C';
            TOH(num, sourcePeg, auxiliaryPeg, targetPeg);
            return (0);
        }
        
        void move(int num, char sourcePeg, char targetPeg){
            cout << "Move disk " << num << " from " << sourcePeg << " to " << targetPeg << endl;
        }
        
        void TOH(int num, char sourcePeg, char auxiliaryPeg, char targetPeg) {
            if (num == 1) move(num, sourcePeg, targetPeg);
            else {
                TOH(num - 1, sourcePeg, targetPeg, auxiliaryPeg);
                move(num, sourcePeg, targetPeg);
                TOH(num - 1, auxiliaryPeg, sourcePeg, targetPeg);
            }
        }

> Giải thích

        Di chuyển n-1 đĩa ở trên cùng ở sourcePeg đến auxiliaryPeg,
        Mặc dù auxiliaryPeg là chiếc đinh trung gian, nhưng để có thể mang được các đĩa này đến auxiliaryPeg, ta cần một chiếc đinh trung gian khác, đó chính là chiếc đinh targetPeg.
        Di chuyển chiếc đĩa lớn nhất ở dưới cùng, ứng với numberOfDisks, đến chiếc đinh targetPeg.
        Di chuyển n-1 chiếc đĩa ở auxiliaryPegsang targetPeg, và lần này thì chúng ta sử dụng sourcePeg làm trung gian nếu số lượng đinh vẫn còn lớn.

> Output

        Enter the number of disks: 3
        Move disk 1 from A to C
        Move disk 2 from A to B
        Move disk 1 from C to B
        Move disk 3 from A to C
        Move disk 1 from B to A
        Move disk 2 from B to C
        Move disk 1 from A to C

## 6. Bài toán Quân mã đi tuần
> https://nguyenvanhieu.vn/bai-toan-ma-di-tuan/
>
> https://spiderum.com/bai-dang/BAI-TOAN-QUAN-MA-DI-TUAN-VA-NHUNG-DIEU-THU-VI-AN-SAU-NO-8ms

Tại mỗi bước lần lượt cho quân mã thử tất cả các nước đi kế tiếp (tám nước đi kế tiếp). Với mỗi bước đi, kiểm tra xem nếu nước đi hợp lệ (chưa đi qua và ở trong bàn cờ) thì thử đi nước này. Nếu quân mã đã đi qua hết bàn cờ thì xuất kết quả. Ngược lại thì gọi đệ quy tiếp cho vị trí mới thử trên. Lưu ý là mỗi khi vị trí đã đi qua được đánh dấu chính bằng chính thứ tự nước đi trên bàn cờ. Sau khi không thử vị trí này thì phải bỏ đánh dấu để chọn giải pháp khác (trường hợp quay lui).
Nếu coi các ô của bàn cờ là các đỉnh của đồ thị và các cạnh là nối giữa hai đỉnh tương ứng với hai ô mã giao chân thì dễ thấy rằng hành trình của quân mã cần tìm sẽ là một đường đi Hamilton. Ta có thể xây dựng hành trình bằng thuật toán quay lui kết hợp với phương pháp duyệt ưu tiên Warnsdorff: Nếu gọi deg(x, y) là số ô kề với ô (x, y) và chưa đi qua (kề ở đây theo nghĩa đỉnh kề chứ không phải là ô kề cạnh) thì từ một ô ta sẽ không thử xét lần lượt các hướng đi có thể, mà ta sẽ ưu tiên thử hướng đi tới ô có deg nhỏ nhất trước. Trong trường hợp có tồn tại đường đi, phương pháp này hoạt động với tốc độ tuyệt vời: Với mọi n chẵn trong khoảng từ 6 tới 18, với mọi vị trí ô xuất phát, trung bình thời gian tính từ lúc bắt đầu tới lúc tìm ra một nghiệm < 1 giây. Tuy nhiên trong trường hợp n lẻ, có lúc không tồn tại đường đi, do phải duyệt hết mọi khả năng nên thời gian thực thi lại hết sức tồi tệ. (Có xét ưu tiên như trên hay xét thứ tự như trước kia thì cũng vậy thôi).

        #include<iostream>
        #include<stdio.h>
        #define MAX 8
        using namespace std;
        
        int A[MAX][MAX] = { 0 };//Khởi tạo mảng giá trị 0
        int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
        int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};
        int dem = 0;//Số bước đi
        int n;
        
        void xuat() {
        	for (int i = 0; i < n; i++) {
        		for (int j = 0; j < n; j++)
        			printf("%2d ", A[i][j]);
        		cout << endl;
        	}
        	cout << endl;
        }
        
        void diChuyen(int x, int y) {
        	++dem;//Tăng giá trị bước đi
        	A[x][y] = dem;//Đánh dấu đã đi
        	for (int i = 0; i < 8; i++)	{
        		//Kiểm tra xem mã đã đi hết bàn cờ chưa
        		if (dem == n * n) {
        			cout << "Cac buoc di la: n";
        			xuat();
        			exit(0);//kết thúc chương trình
        		}
        		//Nếu chưa đi hết bàn cờ thì tạo bước đi mới
        		int u = x + X[i];//tạo một vị trí x mới
        		int v = y + Y[i];//tạo một vịi trí y mới
        		//Nếu hợp lẹ thì tiến hành di chuyển
        		if (u >= 0 && u < n&&v >= 0 && v < n&& A[u][v] == 0)
        			diChuyen(u, v);
        	}
        	//Nếu không tìm được bước đi thì ta phải trả lại các giá trị ban đầu
        	--dem;
        	A[x][y] = 0;
        }
        int main() {
        	cout << "Nhap n: ";
        	cin >> n;
        	int a, b;
        	cout << "Nhap vi tri ban dau.nx: ";
        	cin>>a;
        	cout << "y: ";
        	cin >> b;
        	diChuyen(a, b);
        	//Nếu không tìm được bước đi thì sẽ thông báo
        	cout << "Khong tim thay duong di.";
        }

