> https://200lab.io/blog/de-quy-la-gi/
>
> https://viblo.asia/p/de-quy-va-giai-thuat-de-quy-gGJ5969JKX2
>
> https://topdev.vn/blog/de-quy-la-gi/
>
> https://howkteam.vn/course/cau-truc-du-lieu-va-giai-thuat/de-quy-4281

# I. Hàm Đệ Quy
## 1. Định Nghĩa Hàm Đệ Quy
### a. Định nghĩa
- Hàm đệ quy được định nghĩa là hàm gọi lại chính nó. Có rất nhiều thuật toán và cấu trúc dữ liệu dựa trên kỹ thuật đệ quy này : Quick sort, Merge sort, DFS, Cây Phân Đoạn...
  
![image](https://github.com/minchangggg/DSA/assets/125820144/f21f4665-b67e-4a31-b663-b84b076435c3)

### b. Thành phần của một hàm đệ quy
- Một hàm đệ quy gồm 2 phần:
  + Phần cơ sở: Điều kiện để thoát khỏi đệ quy. Nếu như không có phần này, hàm đệ quy sẽ thực hiện mãi mãi gây ra tràn bộ nhớ Stack.
  + Phần đệ quy: Thân hàm có chứa phần gọi đệ quy, thực hiện cho đến khi thỏa mãn điều kiện ở phần cơ sở.
    
- Ví dụ : 

        #include <stdio.h>
        
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
### c. Bộ nhớ Stack
- Nguyên tắc hoạt động của bộ nhớ Stack là LIFO (Last in - First out hay còn gọi là vào sau - ra trước ). Khi một biến được khai báo trong hàm, nó sẽ được đẩy vào Stack, khi hàm đó kết thúc thì tất cả những biến đó sẽ được đẩy ra, giải phóng khỏi Stack. Hình dưới là minh họa cách hoạt động của bộ nhớ Stack.

![image](https://github.com/minchangggg/DSA/assets/125820144/e405cebf-ef0e-4cc9-8637-526c48665b93)

- Nhận xét đệ quy:
  + Ưu điểm: Thuận lợi cho việc biểu diễn bài toán, như ở ví dụ trên, nhìn vào hàm là chúng ta có thể thấy ngay nó biểu diễn dãy số fibonacci, hay tính giai thừa.
  + Nhược điểm: Tốn nhiều bộ nhớ, nếu không phần cơ sở (điểm dừng) thì sẽ gây ra việc tràn bộ nhớ stack. Bên cạnh đó việc sử dụng đệ quy tốn nhiều thời gian hơn vòng lặp.
## 2. Ví Dụ Về Đệ Quy
### a. Ví dụ 1 : 

        #include <stdio.h>
        
        void dequy(int n){
           if(n > 0){
              printf("Loi goi ham khi n = %d\n", n);
              dequy(n - 1);
           }
           printf("Ham khi n = %d ket thuc !\n", n);
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

        #include <stdio.h>
        
        int sum(int n){
           if(n == 0){
              return 0;
           }
           else{
              return n + sum(n - 1);
           }
        }
        
        int main(){
           printf("%d", sum(3));
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
  + Bài toán cơ sở - bài toán con nhỏ nhất mà bạn đã biết giá trị
  + Công thức truy hồi 
- Khi code đệ quy bạn chỉ cần kiểm tra xem lời gọi đệ quy của bạn đã gọi tới bài toán cơ sở chưa, đây sẽ là điểm dừng cho lời gọi đệ quy. Nếu chưa phải bài toán con nhỏ nhất thì bạn sẽ trả về công thức truy hồi thông qua lời gọi đệ quy
### Ví dụ 1 : Tìm số Fibonacci bằng đệ quy
- Bài toán cơ sở : F0 = 0, F1 = 1
- Công thức truy hồi : Fn = Fn-1 và Fn-2 với n > 1
- Lưu ý là code này chạy rất chậm nếu n lớn
- Code :

        #include <stdio.h>
        
        int F(int n){
           if(n == 0 || n == 1){
              return n;
           }
           else{
              return F(n - 1) + F(n - 2);
           }
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

        #include <stdio.h>
        
        long long factorial(int n){
           if(n == 0){
              return 1;
           }
           else{
              return n * factorial(n - 1);
           }
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
  
        #include <stdio.h>
        
        int sum(int n){
           if(n < 10){
              return n;
           }
           else{
              return n % 10 + sum(n / 10);
           }
        }
        
        int main(){
           printf("%d", sum(12345));
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

        #include <stdio.h>
        
        int F(int n){
           if(n == 0 || n == 1){
              return n;
           }
           else{
              return F(n - 1) + F(n - 2);
           }
        }
        
        int main(){
           printf("%d", F(12));
           return 0;
        }

> Output :

        144

### b. Tổ hợp chập K của N 
- Tổ hợp chập K của N (C(n, k)) được tính đệ quy dựa vào bài toán cơ sở và công thức truy hồi sau :
  + Bài toán cơ sở : C(n, 0) = 1 và C(n, n) = 1
  + Công thức truy hồi : C(n, k) = C(n - 1, k - 1) + C(n - 1, k) 
- Code : 

        #include <stdio.h>
        
        int C(int n, int k){
           if(n == k || k == 0){
              return 1;
           }
           else{
              return C(n - 1, k - 1) + C(n - 1, k);
           }
        }
        
        int main(){
           printf("%d", C(12, 2));
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

        #include <stdio.h>
        
        void dec_to_bin(long long n){
           if(n < 2){
              printf("%d", n);
           }
           else{
              dec_to_bin(n / 2);
              printf("%d", n % 2);
           }
        }
        
        int main(){
           dec_to_bin(37);
           printf("\n");
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

        #include <stdio.h>
        
        void dec_to_hex(long long n){
           if(n < 16){
              if(n < 10){
                 printf("%d", n);
              }
              else{
                 printf("%c", (55 + n));
              }
           }
           else{
              dec_to_hex(n / 16);
              int r = n % 16;
              if(r < 10){
                 printf("%d", r);
              }
              else{
                 printf("%c", (55 + r));
              }
           }
        }
        
        int main(){
           dec_to_hex(762);
           printf("\n");
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

        #include <stdio.h>
        
        int D(long long n){
           if(n < 10){
              return 1;
           }
           else{
              return 1 + D(n / 10);
           }
        }
        
        int main(){
           long long n = 28282828;
           printf("%d", D(n));
           return 0;
        }

> Output :
        
        8

### Bài 2 : Tính tổng chữ số của số N
- Bài toán cơ sở : S(N) = N nếu N < 10
- Công thức truy hồi : S(N) = N % 10 + S(N / 10) nếu N ≥ 10
- Code : 

        #include <stdio.h>
        
        int S(long long n){
           if(n < 10){
              return n;
           }
           else{
              return n % 10 + S(n / 10);
           }
        }
        
        int main(){
           long long n = 28282828;
           printf("%d", S(n));
           return 0;
        }

> Output :

        40

### Bài 3. Tính tổng chữ số chẵn (lẻ) của N
- Bài toán cơ sở : S(N) = 0 nếu N lẻ, N nếu N chẵn với N < 10
- Công thức truy hồi : S(N) = S(N / 10) nếu N lẻ, N % 10 + S(N / 10) nếu N chẵn với N ≥ 10
- Code : 

        #include <stdio.h>
        
        int S(long long n){
           if(n < 10){
              if(n % 2 == 1) return 0;
              else return n;
           }
           else{
              if(n % 2 == 1) return S(n / 10);
              else return n % 10 + S(n / 10);
           }
        }
        
        int main(){
           long long n = 12345678;
           printf("%d", S(n));
           return 0;
        }

> Output : 
        
        20

### Bài 4. Tìm chữ số lớn nhất (nhỏ nhất) của N
- Bài toán cơ sở : F(N) = N nếu N < 10
- Công thức truy hồi : F(N) = max(N % 10, F(N / 10)) với N ≥ 10
- Code : 

        #include <stdio.h>
        
        int F(long long n){
           if(n < 10){
              return n;
           }
           else{
              int tmp = F(n / 10);
              return n % 10 > tmp ? n % 10 : tmp;
           }
        }
        
        int main(){
           long long n = 12349567;
           printf("%d", F(n));
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

        #include <stdio.h>
        
        double S(int n){
           if(n == 1){
              return 1;
           }
           else{
              return (double)1 / n + S(n - 1);
           }
        }
        
        int main(){
           int n = 10;
           printf("%.2lf", S(n));
           return 0;
        }

> Output :
        
        2.93
## 5. Các Bài Toán Liên Quan Tới Mảng
### Bài 1. Tính tổng các số chẵn trong mảng 
- Code : 

        #include <stdio.h>
        
        int even_sum(int a[], int n){
           if(n == 0){
              return 0;
           }
           else{
              if(a[n - 1] % 2 == 0){
                 return a[n - 1] + even_sum(a, n - 1);
              }
              else{
                 return even_sum(a, n - 1);
              }
           }
        }
        
        int main(){
           int n = 6;
           int a[6] = {1, 2, 3, 4, 5, 6};
           printf("%d\n", even_sum(a, n));
           return 0;
        }

> Output :
        
        12

### Bài 2 . Kiểm tra mảng đối xứng
- Code : 

        #include <stdio.h>
        
        int doixung(int a[], int left, int right){
           if(left > right){
              return 1;
           }
           else{
              if(a[left] != a[right]){
                 return 0;
              }
              else{
                 return doixung(a, left + 1, right - 1);
              }
           }
        }
        
        int main(){
           int n = 6;
           int a[6] = {1, 2, 3, 3, 2, 1};
           printf("%d\n", doixung(a, 0, n - 1));
           return 0;
        }

> Output : 

        1

### Bài 3. In ra mảng từ trái qua phải
- Code : 

        #include <stdio.h>
        
        void left_to_right(int a[], int n){
           if(n > 0){
              left_to_right(a, n - 1);
              printf("%d ", a[n - 1]);
           }
        }
        
        int main(){
           int n = 6;
           int a[6] = {1, 2, 3, 4, 5, 6};
           left_to_right(a, 6);
           return 0;
        }

> Output : 
        
        1 2 3 4 5 6

### Bài 4. In ra mảng từ phải qua trái
- Code : 

        #include <stdio.h>
        
        void left_to_right(int a[], int n){
           if(n > 0){
              printf("%d ", a[n - 1]);
              left_to_right(a, n - 1);
           }
        }
        
        int main(){
           int n = 6;
           int a[6] = {1, 2, 3, 4, 5, 6};
           left_to_right(a, 6);
           return 0;
        }

> Output : 
        
        6 5 4 3 2 1


## 5. Bài toán “Tháp Hà Nội” (Tower of Ha Noi)
- Đây là một bài toán rất nổi tiếng và kinh điển, rất thích hợp để minh họa cho thuật toán đệ quy. Sau đây là nội dung bài toán : Có 3 chiếc cọc được đánh dấu lần lượt là A, B, C và n chiếc đĩa. Các đĩa này có kích thước khác nhau và mỗi đĩa đều có một lỗ ở giữa để cắm vào cọc. Ban đầu, các đĩa đều nằm ở cọc A, trong đó, đĩa nhỏ luôn nằm trên đĩa lớn hơn.

![image](https://github.com/minchangggg/DSA/assets/125820144/27b8899c-3f68-4aaf-9fb3-83a8f93cdfa8)

- Yêu cầu : chuyển n đĩa từ cọc A sang cọc đích C với các điều kiện sau :
  + Mỗi lần chỉ chuyển được 1 đĩa
  + Trong quá trình chuyển, đĩa nhỏ phải luôn nằm trên đĩa lớn hơn.
  + Cho phép sử dụng cọc B làm cọc trung gian
- Phân tích : ta sẽ xét các trường hợp của n
  + Trường hợp đơn giản nhất, n=1, ta chỉ cần chuyển 1 đĩa từ cọc A sang cọc C.
  + Nhiều hơn một chút, n=2, ta chuyển đĩa nhỏ nhất sang cọc B, chuyển đĩa còn lại sang cọc C, và cuối cùng chuyển đĩa nhỏ ở cọc B sang cọc C.
  + Bây giờ ta xét n đĩa (n>2). Giả sử ta đã có cách chuyển n-1 đĩa từ một cọc sang một cọc khác. Như vậy, để chuyển n đĩa từ cọc nguồn sang cọc đích, ta cần chuyển n-1 đĩa từ cọc nguồn sang cọc trung gian. Sau đó chuyển đĩa lớn nhất từ cọc nguồn sang cọc đích. Cuối cùng, chuyển n-1 từ cọc trung gian về cọc đích.
