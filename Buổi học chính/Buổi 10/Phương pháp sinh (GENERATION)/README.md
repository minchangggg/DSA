> https://trieutuanhiep.blogspot.com/2015/08/thuat-toan-phuong-phap-sinh-generation.html
# I. Giới thiệu chung
## 1. Phương pháp sinh dùng để làm gì ?
- Giả sử nếu muốn liệt kê tất cả các chỉnh hợp không lặp chập 5 của X ( hay gọi là liệt kê tất cả các cấu hình của bài toán) thì phải làm như thế nào ?
- Chày cối đếm tay và viết vào máy ? điều này có thể thực hiện nếu chỉ có ít phần tử chứ cho liệt kê mà tập có 30 phần tử thì rất phức tạp.
- Vậy cách giải quyết ví dụ là gì ? câu trả lời là phương pháp sinh.
### 2. Mục đích của phương pháp sinh là gì ? 
- Phương pháp sinh được sử dụng trong bài toán liệt kê, ví dụ như người ta cần liệt kê tổ hợp chập k của n phần tử (liệt kê các cấu hình của bài toán) hay hoán vị của một tập số, hay khi người cần làm một bài toán mà không thể áp dụng các phương pháp thông minh như quy hoạch động, chia để trị thì phương pháp liệt kê để xét vét cạn là sự lựa chọn cuối cùng. 
### 3. Phương pháp sinh hoạt động như thế nào ?
- Phương pháp sinh là phương pháp từ cấu hình đầu tiên ta sinh ra các cấu hình tiếp theo đến khi nào hết nghiệm thì thôi.
- Ví dụ: trong ví dụ trên, từ cấu hình 123456 PPS sẽ đẻ ra tiếp cấu hình 23456 cho đến khi hết nghiệm của bài toán
### 4. Các bài toán phổ biến áp dụng phương pháp sinh:
![image](https://github.com/minchangggg/DSA/assets/125820144/b0c7eed8-df1c-4424-a86e-7ec83ef2433a)
### 5. Điều kiện để áp dụng được phương pháp sinh : 
- Không phải bài nào cũng có thể làm theo phương pháp sinh, có 2 điều kiện để sử dụng được phương pháp sinh :
  + Thứ nhất phải xác định được cấu hình đầu và cấu hình cuối
  + Thứ hai phải xác định được cấu hình tiếp theo bằng 1 công thức nhất định

- Việc xác định cấu hình đầu tiên và cấu hình cuối cùng là do yêu cầu đặt ra của từng bài toán và do cách xác định của từng người lập trình. Yêu cầu quan trọng hơn khi sử dụng phương pháp sinh là làm sao từ cấu hình đang có ta có thể đưa ra được cấu hình tiếp theo hoặc là khẳng định đó là cấu hình cuối cùng. Ta tạm gọi bài toán từ cấu hình ban đầu sinh ra cấu hình tiếp theo có thủ tục là sinh_kế_tiếp. Khi đó bài toán sử dụng phương pháp sinh được viết như sau:

![image](https://github.com/minchangggg/DSA/assets/125820144/67fc9e75-7980-474c-87d0-28f9f2733f56)

# II. Sinh xâu nhị phân
## a. Phân tích bài toán
![image](https://github.com/minchangggg/DSA/assets/125820144/27f4c5f1-798e-4c8f-bd9a-8240161c4ba8)

- Một dãy nhị phân có độ dài n là một dãy x[1..n] trong đó x[i] ∈{0,1}
- Ví dụ 1 dãy nhị phân có độ dài = 3 :

![image](https://github.com/minchangggg/DSA/assets/125820144/5743e913-c927-41c4-bdcf-1c655860d543)

- Chúng ta có thể liên hệ giữa số chuỗi nhị phân này với định nghĩa chỉnh hợp như sau: Cho tập X gồm 2 phần tử {0;1} mỗi bộ( dãy ) gồm n phần tử từ 2 phần tử đã cho ta được 1 chỉnh hợp lặp chập n của 2. như vậy **số cấu hình (hay dãy số nhị phân) có độ dài n = 2^n**. Với n = 3 thì số cấu hình (hay số dãy nhị phân) = 8 ( như trên hình ban đầu ). Ta nhận thấy cấu hình đầu tiên sẽ là 00…0 và cấu hình cuối cùng sẽ là 11…1.
- Nhận xét rằng nếu cấu hình x[1..n] là cấu hình đang có và không phải cấu hình cuối cùng cần liệt kê thì dãy kế tiếp sẽ nhận được bằng cách cộng thêm 1 (theo cơ số 2 có nhớ) vào cấu hình hiện tại. Như vậy, phương pháp sinh đã được thỏa mãn 2 điều kiện đó là : biết được cấu hình đầu-cuối và thuật toán sinh được cấu hình tiếp theo từ cấu hình trước nó.
- Chúng ta sẽ sử dụng phương pháp sinh để sinh ra các cấu hình thỏa mãn đề bài như sau :

        Xét từ cuối dãy đi lên, gặp số 0 đầu tiên : 
        * nếu thấy thì thay số 0 bằng số 1 và đặt tất cả phần tử sau vị trí đó = 0.
        * nếu không thấy thì dãy toàn số 1, đây là cấu hình cuối cùng.

### b. Code
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
                for(int i = 1; i <= n; i++) cout << a[i];
                cout << endl;
                sinh();
            }
        }

> Output

        000
        001
        010
        011
        100
        101
        110
        111

# III. Sinh tổ hợp chập K của N phần tử

# IV. Sinh hoán vị

# V. Sinh phân hoạch

# Sinh tập con bằng toán tử bit



