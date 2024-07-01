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
![image](https://github.com/minchangggg/DSA/assets/125820144/ef11f53e-71d7-423a-b0cd-1473b53c394d)

## a. Phân tích bài toán
- Xét về bản chất thì thuật toán sinh các chuỗi nhị phân có độ dài là k thực chất là liệt kê các chỉnh hợp lặp chập k của 2 (vì tập nguồn của chúng ta có 2 phần tử là 0 và 1). 
- Vậy thì nếu tập nguồn của chúng ta không phải là 2 phần tử nữa, mà là n phần tử thì sao ?
- Khi đó, bài toán mới của chúng ta sẽ là : Cho tập X có n phần tử {1,2,…,n}. hãy liệt kê các chỉnh hợp lặp chập k của n.
- Ví dụ : với n = 2 và k = 3 nhập từ bàn phím thì các cấu hình của bài toán là : (111) ; (112) ; (121) ; (122) ; (211) ; (212) ; (221) ; (222).
- Theo công thức của chỉnh hợp lặp thì số các cấu hình = n^k = 2^3 = 8.
- Và nhìn vào ví dụ trên, chúng ta cũng sẽ thấy cấu hình đầu là toàn số 1 và cấu hình cuối toàn số n. và  ta dễ dàng tìm ra thuật toán như sau :
- Xét từ cuối dãy về đầu, gặp chữ số có giá trị chưa bằng n :
  + Tăng chữ số đó lên 1 đơn vị
  + Gán tất cả phần tử sau vị trí đó = 1.
- Thuật toán dừng lại khi sinh được cấu hình cuối gồm các phần tử có giá trị đều = n.

### b. Code
`In thuận`

        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        
        // Các biến toàn cục và hàm khởi tạo cấu hình đầu tiên
        int n, k, a[100]; // lưu cấu hình
        bool final = false; // check cấu hình cuối
        
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
            n = 5, k = 3;
            init();
            while(!final){
                for(int i = 1; i <= k; i++){ cout << a[i];
            }
            cout << endl;
            sinh();
            }
        }

> Output

        123
        124
        125
        134
        135
        145
        234
        235
        245
        345

`In ngược`

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
            n = 5, k = 3;
            init();
            while(!final){
                vector<int> tmp(a + 1, a + k + 1);
                res.push_back(tmp);
                sinh();
            }
        
            // In thuận
            for(auto x : res){
                for(auto y : x){
                    cout << y << ' ';
                }
                cout << endl;
            }
        
            cout << endl;
        
            // In ngược
            for(int i = res.size()-1; i >= 0; i--){
                for(auto x : res[i]){
                    cout << x << ' ';
                }
                cout << endl;
            }
        }

> Output

        1 2 3 
        1 2 4 
        1 2 5 
        1 3 4 
        1 3 5 
        1 4 5 
        2 3 4 
        2 3 5 
        2 4 5 
        3 4 5 
        
        3 4 5 
        2 4 5 
        2 3 5 
        2 3 4 
        1 4 5 
        1 3 5 
        1 3 4 
        1 2 5 
        1 2 4 
        1 2 3 
# IV. Sinh hoán vị
## a. Phân tích bài toán
![image](https://github.com/minchangggg/DSA/assets/125820144/b3151efc-caea-46cd-bc0f-1049957fce31)
## b. Code 
        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        
        // Các biến toàn cục và hàm khởi tạo cấu hình đầu tiên
        int n, X[100]; // lưu cấu hình
        bool final = false; // check cấu hình cuối
        
        void init(){ 
            for(int i = 1; i <= n; i++){
                X[i] = i;
            }
        }
        
        void sinh(){
            int i = n;
            while(i >= 1 && X[i] > X[i + 1]){
                --i;
            }
            if(i == 0){
                final = true;
            }
            else{
                int j = n;
                while(X[i] > X[j]) --j;
                swap(X[i], X[j]);
                reverse(X + i + 1, X + n + 1);
            }
        }
        
        int main(){
            n = 4;
            init();
            while(!final){
                for(int i = 1; i <= n; i++){
                    cout << X[i];
                }
                cout << endl;
                sinh();
            }
        }

> Output

        1234
        1243
        1324
        1342
        1423
        1432
        2134
        2143
        2314
        2341
        2413
        2431
        3124
        3142
        3214
        3241
        3412
        3421
        4123
        4132
        4213
        4231
        4312
        4321
## c. Hàm next_permutation và prev_permutation
Trong C++ cũng cung cấp 2 hàm next_permutation để sinh ra cấu hình kế tiếp và prev_permutation để sinh ra cấu hình liền trước. Các bạn có thể sử dụng nó và kết hợp với mảng hoặc vector để sinh hoán vị.
### next_permutation
![image](https://github.com/minchangggg/DSA/assets/125820144/53f23f6c-a3c0-406b-84e3-ec040ba82297)
### prev_permutation
![image](https://github.com/minchangggg/DSA/assets/125820144/a49f1f34-961a-4001-b301-b5ba5137848f)
# V. Sinh phân hoạch
## a. Phân tích bài toán
![image](https://github.com/minchangggg/DSA/assets/125820144/88e20a96-d685-469e-a227-5e33ec50ff11)
## b. Code 
        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        
        // Các biến toàn cục và hàm khởi tạo cấu hình đầu tiên
        int n, X[100], cnt; // lưu cấu hình
        bool final = false; // check cấu hình cuối
        
        void init(){ 
            cnt = 1;
            X[1] = n;
        }
        
        void sinh(){
            int i = cnt;
            while(i >= 1 && X[i] == 1){
                --i;
            }
            if(i==0) final = true;
            else{
                int d = cnt-i + 1; // số lượng đơn vị cần phải bù vào 
                --X[i];
                cnt = i;
                int q = d / X[i]; // d gấp bnh lần X[i]
                int r = d % X[i]; // tính số dư bao nhiêu để đặt vào vị trí cuối cùng
                if(q != 0){
                    for(int j = 1; j <= q; i++){
                        X[i+j] = X[i];
                        ++cnt;
                    }
                }
                if(r != 0) {
                    ++cnt;
                    X[cnt] = r;
                }
            }
        }
        
        int main(){
            n = 6;
            init();
            
            while(!final){
                for(int i = 1; i <= cnt; i++) cout << X[i] << ' ';
                cout << endl; 
                sinh();
            }
        }
# VI. Sinh tập con bằng toán tử bit
  + 1 << n = 2^n => duy nhất bit thứ k = 1. VD: 2^0 = 1; 2^1 = 10, 2^2 = 100...(chuyển đổi nhị phân thông thường)
  + 2 << n = 2.(2^n) 
## a. Phân tích bài toán
![image](https://github.com/minchangggg/DSA/assets/125820144/cb34da21-1848-414e-8288-55677b614897)
## b. Code 
        #include <bits/stdc++.h>
        using namespace std;
        int main(){
          int a[] = {1, 2, 3};
          int n = 3;
          for(int i = 0; i < (1 << n); i++){ // i = 0 -> 2^n -1
            for(int j = 0; j < n; j++){ // duyệt từng bit
              if(i & (1 << j)) cout << a[j] << ' ';
            }
            cout << endl;
          }
        }
