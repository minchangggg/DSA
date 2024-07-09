> https://viblo.asia/p/thuat-toan-quay-lui-backtracking-bJzKmLbD59N
>
> https://howkteam.vn/course/cau-truc-du-lieu-va-giai-thuat/quay-lui-4282
>
> https://codedream.edu.vn/backtrack-duyet-quay-lui-phan-1/
>
> https://codedream.edu.vn/backtrack-duyet-quay-lui-phan-2/
>
> https://codedream.edu.vn/backtrack-duyet-quay-lui-phan-3/

# I. Backtrack
## 1. Tư tưởng Backtrack
- Backtrack là một kĩ thuật thiết kế giải thuật dựa trên đệ quy. Ý tưởng của Backtrack là tìm lời giải từng bước, mỗi bước chọn một trong số các lựa chọn khả dĩ và đệ quy. Người đầu tiên đề ra thuật ngữ này (backtrack) là nhà toán học người Mỹ D. H. Lehmer vào những năm 1950.
- Backtrack dùng để giải bài toán liệt kê các cấu hình. Mỗi cấu hình được xây dựng bằng từng phần tử. Mỗi phần tử lại được chọn bằng cách thử tất cả các khả năng.
- Các bước trong việc liệt kê cấu hình dạng X=x1,x2,…,xn
  + Xét tất cả các giá trị x1 có thể nhận, thử x1 nhận các giá trị đó. Với mỗi giá trị của x1
  + Xét tất cả giá trị x2 có thể nhận, lại thử x2 cho các giá trị đó. Với mỗi giá trị x2 lại xét khả năng giá trị của x3…tiếp tục như vậy cho tới bước n:
  + …
  + ….
  + Xét tất cả giá trị xn có thể nhận, thử cho xn nhận lần lượt giá trị đó.
  + Thông báo cấu hình tìm được.
- **Bản chất của quay lui là một quá trình tìm kiếm theo chiều sâu (Depth-First Search).**
- Mã giả thuật toán quay lui

        void backtracking(i) {
          if(i > n){
            if (nghiemThoaMan()) 
              print(X);
            return;
          } 
          for(j in D) {
            if (check(j, i)) { //Có thể đặt giá trị j vào vị trí i 
              X[i] = j; //Đặt j
              backtracking(i+1);
              X[i] = 0; //Bỏ chọn j 
            }
          } 
        }

## 2. Bài toán liệt kê các xâu nhị phân độ dài n
### a. Phát biểu bài toán
- Cho số n. Liệt kê các xâu nhị phân độ dài n (1≤n≤20) mà không có hai số 1 liền nhau theo thứ tự từ điển.
- Ví dụ: n=3 ta có các xâu nhị phân độ dài 3 mà không có hai số 1 liền nhau như sau:

        000
        001
        010
        100
        101

### b. Phân tích bài toán
- Bài toán yêu cầu xây dựng vector nghiệm có n phần tử, dạng: X=x1,x2,…,xn
- Trong đó
  + 0≤xi≤1
  + xi∗xi−1=0

### c. Code bài toán duyệt nhị phân bằng C++
        #include<bits/stdc++.h>
        using namespace std;
        #define ll long long
        #define pii pair<int,int>
        #define MAXN 21
        int n;
        int x[MAXN];
        
        //Hàm kiểm tra nghiệm X có thỏa mãn không xuất hiện 2 số 1 liền nhau hay không?
        bool check(){
            for(int i = 2; i <= n; i++)
                if(x[i]*x[i-1] == 1) return false;
            return true;
        }
        
        //Hàm in nghiệm X 
        void printX(){
            for(int i = 1; i <= n; i++)
                cout<<x[i];
            cout<<endl;
        }
        //Hàm quay lui
        void backtrack(int i){
          //Nếu i>n => đã điền xong các giá trị của vector nghiệm X 
          if(i>n){
            //Nếu nghiệm X thỏa mãn yêu cầu đề bài thì in ra màn hình 
            if (check()){
              printX(); 
            }
            return; 
          }
          //Thử các giá trị có thể đặt được của x[i] 
          for(int j = 0; j <= 1; j++){
            x[i] = j;
            //Đặt xong vị trí i thì gọi hàm quay lui để đặt vị trí i + 1 
            backtrack(i + 1);
          } 
        }
         
        int main() { 
          ios_base::sync_with_stdio(false); 
          cin.tie(NULL);
          cin>>n;
          //Xây dựng nghiệm bắt đầu từ vị trí 1 
          backtrack(1);
          return 0;
        }

### d. Mô tả thuật toán khi chạy
![image](https://github.com/minchangggg/DSA/assets/125820144/03d81e2d-f5fa-4ad1-b524-66057179d869)

### e. Cải tiến thuật toán
- Để cải tiến thuật toán duyệt, ta có thể đặt cận để cắt bớt 1 số nhánh mà biết chắc nếu đi sâu xuống cũng không có kết quả. Kỹ thuật này được gọi là duyệt nhánh cận
- Như bài toán trên, ngay trong hàm đệ quy, trước khi đặt giá trị xi bất kì, ta kiểm tra xem xi−1∗xi có bằng 0 hay không trước. Nếu xi−1∗xi=0 thì ta sẽ gọi backtrack(i+1) còn nếu không thì dù xây dựng tiếp hết dãy X thì kiểu gì nghiệm này cũng sẽ không được chấp nhận.

### f. Code bài toán duyệt nhị phân cải tiến
        #include<bits/stdc++.h>
        using namespace std;
        #define ll long long
        #define pii pair<int,int>
        #define MAXN 21
        int n;
        int x[MAXN];
        
        //Hàm in nghiệm X 
        void printX(){
            for(int i = 1; i <= n; i++)
                cout<<x[i];
            cout<<endl;
        }
        //Hàm quay lui
        void backtrack(int i){
          //Nếu i>n => đã điền xong các giá trị của vector nghiệm X 
          if(i>n){
            //nghiệm X chắc chắn thỏa mãn yêu cầu đề bài nên chỉ cần in ra màn hình 
            printX(); 
            return; 
          }
          //Thử các giá trị có thể đặt được của x[k] 
          for(int j = 0; j <= 1; j++)
            if(x[i-1] * j == 0){
            x[i] = j;
            //Đặt xong vị trí i thì gọi hàm quay lui để đặt vị trí i+1 
            backtrack(i+1);
          } 
        }
         
        int main() { 
          ios_base::sync_with_stdio(false); 
          cin.tie(NULL);
          cin>>n;
          //Xây dựng nghiệm bắt đầu từ vị trí 1 
          backtrack(1);
          return 0;
        }

### g. Mô tả thuật toán duyệt cải tiến khi chạy
![image](https://github.com/minchangggg/DSA/assets/125820144/c4f45cb0-4b85-4766-8cf1-c30dceaf6f30)

### h. Kết luận
- Bài toán trên các vector nghiệm X được sắp xếp theo thứ tự từ điển là do trong hàm backtrack, ta xét các trường hợp có thể đặt được cho mỗi phần tử xk theo thứ tự từ điển, đặt thử 0 trước, đặt thử 1 sau.
  + **Thuật toán duyệt nhị phân có độ phức tạp O(an∗n)**

        Trong đó: a là số lượng giá trị mà một phần tử xi có thể nhận, n là độ dài vector nghiệm X
        Lý do: thuật toán duyệt liệt kê tất cả các nghiệm có thể có của bài toán. Do có n phần tử, mỗi phần tử có a cách đặt. Vậy số lượng vector nghiệm tạo được bằng an. Mặt khác, mỗi một vector nghiệm tạo ra ta mất n phép toán để kiểm tra xem nghiệm đó có thỏa mãn hay không. Thuật toán duyệt nhị phân có độ phức tạp O(an∗n)

  + **Thuật toán duyệt nhị phân cải tiến có độ phức tạp O(an)**

        Lý do: thuật toán duyệt liệt kê tất cả các nghiệm có thể có của bài toán là an. Tuy nhiên, các nghiệm được kiểm soát từ trong hàm backtrack để đảm bảo chắc chắn tạo ra nghiệm đúng nên ta không mất n phép toán để kiểm tra nữa.

## 3. Bài toán liệt kê các hoán vị độ dài n
### a. Phát biểu bài toán
- Cho số n. Liệt kê các hoán vị độ dài n (1≤n≤10) theo thứ tự từ điển.
- Ví dụ: n=3 ta có các dãy hoán vị độ dài 3 như sau:
### b. Phân tích bài toán
- Bài toán yêu cầu xây dựng vector nghiệm có n phần tử, dạng: X=x1,x2,…,xn
- Trong đó:
  + 1≤xi≤n
  + xi≠xj với mọi 1≤i,j≤n
- Để kiểm tra điều kiện các số trong nghiệm X đôi một khác nhau, ta dùng một mảng d với ý nghĩa: d[i]=0 nếu số i chưa được điền, d[i]=1 nếu số i đã được điền. Vậy trong hàm backtrack, trước khi đặt một giá trị xk=i ta cần kiểm tra giá trị i đã được dùng hay chưa, và sau khi đặt thì sẽ đánh dấu là số i đã được đặt
### c. Code bài toán duyệt hoán vị bằng C++
        #include<bits/stdc++.h>
        using namespace std;
        #define ll long long
        #define pii pair<int,int>
        #define MAXN 11
        int n;
        int x[MAXN], d[MAXN];
        
        //Hàm in nghiệm X 
        void printX(){
            for(int i = 1; i <= n; i++)
                cout<<x[i]<<" ";
            cout<<endl;
        }
        //Hàm quay lui
        void backtrack(int i){
          if(i>n){ //Nếu i>n => đã điền xong các giá trị của vector nghiệm X 
            //Nghiệm X chắc chắn thỏa mãn do đã được kiểm soát bằng cận trước đó
            //Vậy nên ta không cần kiểm tra nữa mà in ra luôn 
            printX();
            return;
          }
          //Thử các trường hợp có thể đặt được của vị trí k 
          for(int j = 1; j <= n; j++)
            if(d[j] == 0){  //Nếu số j chưa được đặt trước đó 
              x[i] = j;
              d[j] = 1;//Đánh dấu số j đã được sử dụng
              backtrack(i+1);//Đặt xong vị trí i thì đặt tiếp i+1
              //Sau khi đi sâu xuống nhánh con và quay lui trở lại 
              //Đồng nghĩa với việc sắp tới sẽ đặt thử giá trị mới cho vị trí i
              //Vậy ta sẽ phải bỏ đánh dấu là số j đã được sử dụng 
              d[j] = 0;
            } 
        }
         
        int main() { 
          ios_base::sync_with_stdio(false); 
          cin.tie(NULL);
          cin>>n;
          //Xây dựng nghiệm bắt đầu từ vị trí 1 
          backtrack(1);
          return 0;
        }

### d. Mô tả thuật toán duyệt hoán vị khi chạy
![image](https://github.com/minchangggg/DSA/assets/125820144/f0553428-d523-464c-96e4-b9ec31bef552)

### e. Kết luận
- Bài toán trên các vector nghiệm X được sắp xếp theo thứ tự từ điển là do trong hàm backtrack, ta xét các trường hợp có thể đặt được cho mỗi phần tử xk theo thứ tự từ điển, đặt thử 0 trước, đặt thử 1,2,3…n sau.
- Nếu không đặt cận ngay trong hàm đệ quy thì thuật toán duyệt hoán vị sẽ có độ phức tạp là O(nn∗n) do có nn nghiệm được tạo ra (n phần tử, mỗi phần tử nhận giá trị 1..n) và hàm kiểm tra nghiệm có phải hoán vị hay không cũng có độ phức tạp là O(n)
Thuật toán duyệt hoán vị có độ phức tạp O(n!)
> Trong đó: n là độ dài vector nghiệm X
- Lý do: thuật toán duyệt liệt kê tất cả các nghiệm có thể có của bài toán. Do số lượng hoán vị độ dài n bằng n! nên số lượng vector

## 4. Một số dấu hiệu của việc dùng Backtrack
- **Mỗi phần tử có hai trạng thái: chọn hoặc không chọn, tương đương với 1 và 0 => Dùng duyệt nhị phân**
- **Hỏi thứ tự sắp xếp của các phần tử sao cho điều kiện nào đó tối ưu => Dùng duyệt hoán vị**

# II. Bài tập áp dụng
## 1. Bài toán liệt kê tập hợp
### a. Phát biểu bài toán
Liệt kê tất cả các tập hợp khác rỗng chứa các số từ 1 đến n, theo thứ tự từ điển.

> Input

3

> Output

1

1 2

1 2 3

1 3

2

2 3

3

### b. Phân tích bài toán
- Ta thấy, việc liệt kê tất cả các tập hợp giống như việc liệt kê tất cả các dãy nhị phân, trong đó bit thứ i trong dãy nhị phân là 0/1 tương ứng với không chọn/chọn số thứ i vào tập hợp.
- Với n=3 ta có bảng minh hoạ xâu nhị phân và các tập hợp:

![image](https://github.com/minchangggg/DSA/assets/125820144/77b0432f-b327-48a6-b84b-b9339c5f749f)

### c. Giải quyết bài toán
- Đến đây, việc giải quyết bài toán là vô cùng đơn giản. Ta chỉ việc duyệt ra các nghiệm X như cách duyệt nhị phân của bài viét trước, sau khi tạo được nghiệm X ta tiến hành tạo ra tập hợp tương ứng với nghiệm đó và cho vào mảng để lưu trữ (có thể sử dụng vector 2 chiều để lưu).
- Để in các tập hợp theo thứ tự từ điển, ta chỉ việc gọi hàm sort như bình thường, vector trong C++ sẽ tự động ưu tiên sắp xếp các mảng theo sự so sánh giống so sánh chuỗi ký tự.

### d. Code minh hoạ việc tạo tập hợp
        void makeSet() {
        	vector<int> a;
        	for(int i = 1; i <= n;i++) 
        		if(x[i] == 1)  a.push_back(i);
        		res.push_back(a);
        }

### e. Cải tiến
- Như đã nói ở bài viết trước, trong mọi bài toán backtrack ta nên luôn luôn tìm cách để tạo ra nghiệm đúng (kết quả) trong lúc hàm quay lui chạy mà không cần phải đợi duyệt xong nghiệm X mới xét lại từng phần tử để tổng hợp ra kết quả .
- Bài toán này cũng không ngoại lệ, ta cần duy trì một vector để lưu tập hợp tạo được. Với mỗi phần tử có X[i]=1, tức là chọn phần tử i thì ta sẽ thêm phần tử i vào cuối vector và duyệt đến vị trí kế tiếp. Sau khi duyệt xong thì lại bỏ phần tử cuối của vector đi.

### f. Code liệt kê tập hợp cải tiến
        #include <bits/stdc++.h>
        using namespace std;
        int n;
        vector<vector<int>> res;
        vector<int> a;
        void backtrack(int i){
          if(i > n){
            res.push_back(a);
            return;
          }
          //Không chọn phần tử i, vector giữ nguyên
          backtrack(i + 1);
        
          //Chọn phần tử i, vector thêm phần tử i vào cuối
          a.push_back(i);
          backtrack(i + 1);
          a.pop_back();
        }
        int main(){
            cin >> n;
            backtrack(1);
            sort(res.begin(), res.end());
            for(auto i: res){
                for(auto j: i){
                    cout << j << " ";
                }
                cout << "\n";
            }
        }

### g. Ảnh minh hoạ code khi chạy
![image](https://github.com/minchangggg/DSA/assets/125820144/ab07a12e-6fa7-44d3-bdd6-f3e2dca787f7)

## 2. Bài toán phân tích số thành tổng các số
### a. Phát biểu bài toán
- Cho số nguyên dương n (n≤50). Liệt kê tất cả các cách phân tích n thành tổng các số nguyên nhỏ hơn n, theo thứ tự từ điển.

> Input

5

> Output

1 1 1 1 1

1 1 1 2

1 1 3

1 2 2

1 4

2 3

### b. Phân tích bài toán
- Ở bài này, ta cần sinh ra các cách tạo tổng n thoả mãn: Số sau lớn hơn hoặc bằng số trước trong dãy phân tích
- Vì các cách tạo tổng có độ dài khác nhau, nên ở mỗi thời điểm backtrack ta chỉ cần quan tâm đến tổng hiện tại là bao nhiêu, và duy trì một vector để lưu các số trong quá trình phân tích
- Vậy ta có hàm backtrack(s) là đang có tổng là s, khi đó, ta sẽ thử các cách thêm các số trong khoảng a.back() đến n−s. Trong đó a.back() là phần tử cuối cùng trong vector lưu nghiệm.

### c. Code phân tích n thành tổng các số
        #include <bits/stdc++.h>
        using namespace std;
        int n;
        vector<vector<int>> res;
        vector<int> a;
        void backtrack(int s){
          if(s == n){
            res.push_back(a);
            return;
          }
          int mina;
          if (a.size() == 0) mina = 1;
          else mina = a.back();
          for(int i = mina; i <= min(n-s, n-1); i++){
            a.push_back(i);
            backtrack(s + i);
            a.pop_back();
          }
        }
        int main(){
            cin >> n;
            backtrack(0);
            sort(res.begin(), res.end());
            for(auto i: res){
                for(auto j: i){
                    cout << j << " ";
                }
                cout << "\n";
            }
        }

## 3. Bài toán biểu thức
### a. Phát biểu bài toán
- Cho xâu S (chỉ gồm các ký tự ‘0′ đến ‘9′, độ dài nhỏ hơn 10) và số nguyên M.
- Yêu cầu: Không thay đổi thứ tự của các ký tự trong xâu S. Hãy đếm số cách lấy ra một số ký tự trong xâu S và chèn vào trước nó các dấu ‘+′ hoặc ‘−‘ để thu được số M cho trước?

> Input

1234

6

> Output

4

> Giải thích

Có 4 cách tạo tổng là 6:

        1+2+3
        1−2+3+4
        −1+3+4
        2+4

### b. Phân tích bài toán
- Mỗi ký tự trong xâu S sẽ có 3 lựa chọn:
  + Không lấy số này
  + Lấy số này và đặt dấu ‘−‘ vào trước
  + Lấy số này và đặt dấu ‘+′ vào trước
- Ta có hàm backtrack(i,sum) mang ý nghĩa: Xét đến phần tử thứ i của xâu S, tổng đã tạo được là sum

### c. Code bài toán biểu thức
        #include <bits/stdc++.h>
        using namespace std;
        string s;
        int n, m, ans;
        
        void backtrack(int i, int sum) {
            if (i == n) {
                if (sum == m) ++ans;
                return;
            }
            backtrack(i + 1, sum + (s[i] - 48));
            backtrack(i + 1, sum - (s[i] - 48));
            backtrack(i + 1, sum);
        }
        
        int main() {
            cin >> s >> m;
            n = s.length();
            ans = 0;
            backtrack(0, 0);
            cout << ans;
        
            return 0;
        }

## 4. Bài toán biểu diễn số ở hệ nhị phân
### a. Phát biểu bài toán
- Một số tự nhiên khi biểu diễn trong hệ đếm nhị phân thì chỉ có 2 chữ số 0 và 1.
- Yêu cầu: Cho trước số n và số k . Hãy cho biết trong các số từ 1 đến n có bao nhiêu số mà khi biểu diễn trong hệ đếm 2 có đúng k chữ số 1.

### b. Phân tích bài toán
#### Thuật toán ngây thơ
- Xét từng số trong khoảng từ 1 tới n, với mỗi số ta đổi số đó sang hệ nhị phân và đếm xem có bao nhiêu số 1 trong biểu diễn.
- Cách này có thể dẫn đến TLE một số test lớn, do độ phức tạp là O( 10^7 ∗ 20 ).
#### Thuật toán backtrack
- Ta có, tương ứng mỗi xâu nhị phân sẽ có một số nguyên ở hệ cơ số 10 biểu diễn nó. Thay vì xét các số ở hệ cơ số 10 như ở thuật toán trước, ta sinh nhị phân để tạo ra tất cả các số nguyên đó.
- Nói là sinh nhị phân, nhưng thực chất, ở đây ta không cần phải lưu xâu đó, chỉ cần duy trì số lượng số 1 và tính được luôn xâu đó ở hệ cơ số 10 là số nào.
- Để kiểm soát số được tạo ra phải nhỏ hơn số n. Gọi độ dài của xâu biểu diễn số n dưới dạng nhị phân là m. Các xâu nhị phân được xây dựng phải có độ dài bằng m
- Ta có hàm backtrack(i,cnt1,dec), xây dựng đến vị trí thứ i của xâu nhị phân, số lượng số 1 đã tạo được là cnt1, giá trị của xâu nhị phân ở dạng thập phân là dec
- Đến đây dễ dàng có thể đặt thêm nhánh cận để giảm số trường hợp không thoả mãn:
  + cnt1>k => return;
  + dec>n => return;

### c. Code bài toán biểu diễn số ở hệ nhị phân
        #include<bits/stdc++.h>
        using namespace std;
        long long n, k, res, m;
        void backtrack(int i, int cnt1, int dec){
          if (cnt1 > k) return;
          if (dec > n) return;
          if (i > m){
            if (cnt1 == k && dec <= n){
              res ++;
            }
            return;
          }
          backtrack(i + 1, cnt1, dec * 2);
          backtrack(i + 1, cnt1 + 1, dec * 2 + 1);
        }
        int main() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cin >> n >> k;
            long long t = n;
            while(t!=0){
              t/=2;
              m++;
            }
            backtrack(1, 0, 0);
            cout << res;
            return 0;
        }

# III. Chia đôi tập
## 1. Tư tưởng Backtrack: Duyệt chia đôi tập hợp
- Ở hai phần trước Backtrack – duyệt – quay lui cho người mới bắt đầu (Phần 1) – Sinh nhị phân, sinh hoán vị và Backtrack – duyệt – quay lui cho người mới bắt đầu (Phần 2) – Bài tập áp dụng , chúng ta đã đề cập đến việc duyệt toàn bộ các véc tơ nghiệm thoả mãn tiêu chí tối ưu hoặc là đếm số lượng các nghiệm thoả mãn yêu cầu nào đó. Tuy nhiên, phương pháp này còn hạn chế do độ phức tạp lớn O(|D|n) với D là tập các giá trị mà các phần tử của nghiệm X có thể nhận được, |D| là số phần tử của tập.
- Ở phương pháp Backtrack – duyệt – quay lui: chia đôi tập, ý tưởng là ta sẽ chia đôi nghiệm X ra để duyệt, sau đó kết hợp lại bằng tìm kiếm nhị phân để tìm ra nghiệm đúng.
- Giả thiết: Nghiệm X có n phần tử, dạng: X=x1,x2,…,xn
- Bước 1: Chia X thành 2 nửa:
  + X1=x1,x2,…,xn/2;
  + X2=xn/2+1,xn/2+2,…,xn
- Bước 2: Ta tiến hành duyệt như bình thường. Với mỗi nghiệm X1,X2 được sinh ra, ta cần lưu lại những giá trị cần thiết để có thể kiểm tra được điều kiện X thoả mãn.
- Bước 3: Sort lại các giá trị đã lưu được ở tập 1
- Bước 4: Với mỗi giá trị tìm được ở tập 2, ta tìm kiếm nhị phân các nghiệm tương ứng thoả mãn ở tập 1 để tìm kết quả.
  
## 2. Bài toán tổng Vector
### a. Phát biểu bài toán
- Cho n (1≤n≤40) vector có dạng (x,y). Đếm số cách chọn một số vector sao cho tổng các vector đã chọn bằng vector (U,V)

> Sample Input

4 2 5

0 0

-1 2

2 5

3 3

> Sample Output

4

> Giải thích

Có 4 cách chọn sao cho tổng các vector bằng (2,5):

        (0,0)+(2,5)
        (−1,2)+(3,3)
        (0,0)+(−1,2)+(3,3)+(2,5)
        
### b. Phân tích bài toán theo cách duyệt toàn bộ
- Bài toán yêu cầu xây dựng vector nghiệm có n phần tử, dạng: X=x1,x2,…,xn
- Trong đó 0≤xi≤1 tương ứng là chọn/không chọn vector thứ i
- Điều kiện để X thoả mãn: `∑ni=1ai∗xi=U và ∑ni=1ai∗yi=V` 

### c. Phân tích bài toán theo cách duyệt cải tiến
- Ở bài trước ta đã thống nhất việc: thay vì duyệt ra nghiệm X rồi mới quay lại tính tổng để kiểm tra, ta sẽ tính tổng các vector đã chọn ngay trong lúc duyệt. Vậy có thể mô tả thuật toán duyệt như sau:

        void backtrack(int i, int sumx, int sumy){ 
          if(i > n){
            if(sumx == U && sumy == V) res++;
            return;
          }
          //Không chọn vector thứ i thì sumx, sumy giữ nguyên
          backtrack(i + 1, sumx, sumy);
          //Chọn vector thứ i thì sumx, sumy cộng thêm a[i], b[i]
          backtrack(i + 1, sumx + a[i], sumy + b[i]);
        }

### d. Phân tích bài toán theo cách duyệt chia đôi tập hợp
- Với cách duyệt toàn bộ ta thấy: để kiểm tra mỗi nghiệm xem có thoả mãn hay không, ta cần biết tổng các vector đã chọn là bao nhiêu?
- Vậy các giá trị cần lưu lại sau khi duyệt mỗi nửa của thuật toán duyệt chia đôi chính là tổng của các vector đã chọn.
- Các bước làm
#### Bước 1: Xét ví dụ bên trên, ta sẽ sinh ra hai tập, mỗi tập tương ứng 2 phần tử của nghiệm X.
- Ở tập thứ nhất: X1=x1,x2
  + Gọi X1 là danh sách các giá trị lưu được tương ứng với từng nghiệm của X1.
  + X1=[{0,0},{−1,2},{0,0},{−1,2}]

![image](https://github.com/minchangggg/DSA/assets/125820144/2ab82d9a-e954-4851-bb94-e76597f414df)

- Ở tập thứ hai: X2=x3,x4
  + Gọi X2 là danh sách các giá trị lưu được tương ứng với từng nghiệm của X2.
  + X2=[{0,0},{3,3},{2,5},{5,8}]

![image](https://github.com/minchangggg/DSA/assets/125820144/2eddc498-05e2-44bc-849b-5bb7d4466ae2)

#### Bước 2: Tìm kiếm
- Tiến hành sắp xếp lại các giá trị lưu được ở danh sách X1 theo thứ tự tăng dần. => X1=[{−1,2},{−1,2},{0,0},{0,0}]
- Xét từng phần tử của X2
  + **Phần tử 1: (0,0) – Không chọn cả hai vector 3,4**

        + Để cả hai nửa đạt được tổng là (U,V) ta cần tìm những cách chọn ở nửa thứ nhất sao cho cách chọn đó sinh ra tổng (U−0,V−0) hay (2−0,5−0)=(2,5).
        + Đến đây ta sẽ Tìm kiếm nhị phân trên X1 để đếm xem có bao nhiêu giá trị 2,5 là xong.
        + Trong trường hợp này, không có phần tử nào có giá trị (2,5) ở X1 cả. Nên ta không có cách nào để tạo được tổng (2,5) nếu không chọn cả hai vector 3,4.
  
  + **Phần tử 2: (3,3) – Không chọn vector 3, chọn vector 4**

        + Để cả hai nửa đạt được tổng là (U,V) ta cần tìm những cách chọn ở nửa thứ nhất sao cho cách chọn đó sinh ra tổng (U−3,V−3) hay (2−3,5−3)=(−1,2).
        + Trong trường hợp này, có 2 giá trị (−1,2) ở X1. Nên sẽ có hai cách chọn tương ứng với nghiệm X khi được ghép lại là: 0101,1101

  + **Phần tử 3: (2,5) – Chọn vector 3, không chọn vector 4**

        + Để cả hai nửa đạt được tổng là (U,V) ta cần tìm những cách chọn ở nửa thứ nhất sao cho cách chọn đó sinh ra tổng (U−2,V−5) hay (2−2,5−5)=(0,0).
        + Trong trường hợp này, có 2 giá trị (0,0) ở X1. Nên sẽ có hai cách chọn tương ứng với nghiệm X khi được ghép lại là: 0010,1010

  + **Phần tử 4: (5,8) – Chọn vector 3, 4**

        + Để cả hai nửa đạt được tổng là (U,V) ta cần tìm những cách chọn ở nửa thứ nhất sao cho cách chọn đó sinh ra tổng (U−5,V−8) hay (2−5,5−8)=(−3,−3).
        + Trong trường hợp này, không có phần tử nào có giá trị (−3,−3) ở X1 cả. Nên ta không có cách nào để tạo được tổng (−3,−3) nếu chọn cả hai vector 3,4.

- Vậy kết quả là 4

### e. Code bài Vector C++
        #include <bits/stdc++.h>
        using namespace std;
        #define pii pair<int,int>
        
        string N;
        int n, u,v, x[31], a[31], b[31];
        vector<pii> x1,x2;
        
        
        // X = x1,x2,x3,...,xn
        //t là vị trí cuối cùng của tập
        void backtrack(int i, int sumx, int sumy, int t){
          if (i > t){
            if(t == n/2) 
              x1.push_back({sumx,sumy});
            else
              x2.push_back({sumx,sumy});
            return;
          }
          backtrack(i + 1, sumx, sumy, t);
          backtrack(i + 1, sumx + a[i], sumy + b[i], t);
        
        }
        //trả về số lần xuất hiện của cặp x trong vector x1 => O(2^(n/2))
        int find(pii x){
          int cnt = 0;
          for(int i = 0; i < x1.size(); i++)
            if(x == x1[i]) 
              cnt++;
          return cnt;
        }
        int find1(pii v){
          vector<pii>::iterator low,up;
          //vị trí đầu tiên xh cặp v
          low = lower_bound (x1.begin(), x1.end(), v); 
          //vị trí đầu tiên > cặp v
          up = upper_bound (x1.begin(), x1.end(), v); 
          return up - low;
        }
        int main() {
          cin >> n;
          
          for(int i = 1; i <= n; i++) 
            cin >> a[i] >> b[i];
          cin >> u >> v;
          backtrack(1, 0, 0, n/2);
          backtrack(n/2+1, 0, 0, n);
          sort(x1.begin(), x1.end());
          int res = 0;
          for(int i = 0; i < x2.size(); i++){
            int xx = u - x2[i].first;
            int yy = v - x2[i].second;
            res += find1({xx,yy});
          }
          cout<<res;
          return 0;
        }

### f. Đánh giá độ phức tạp của thuật toán
- Thuật toán backtrack chia đôi có độ phức tạp O(an/2∗log(an/2))
- Mỗi tập X1,X2 sẽ có tối đa an/2 phần tử. Tại mỗi phần tử ta chặt nhị phân để tìm kiếm trong tập còn lại mất chi phí log(a^(n/2))

## 3. Bài toán 34 đồng xu
> Nguồn bài: 34 đồng xu – VNOJ

### a. Phát biểu bài toán
- Cho 34 đồng xu có giá trị như sau:
  + xu[1] có giá trị 2
  + xu[2] có giá trị 3
  + xu[3] có giá trị 5
  + xu[i] có giá trị bằng xu[i−1]+xu[i−2]+xu[i−3]
- Mỗi đồng xu chỉ được dùng tối đa 1 lần, hãy tìm cách sử dụng nhiều đồng xu nhất để tạo ra số tiền là X.
- Ví dụ
  + Với số tiền là 5 ta sử dụng tối đa là 2 đồng xu có giá trị là 2 và 3
  + Với số tiền là 8 ta sử dụng tối đa là 2 đồng xu có giá trị là 5 và 3

### b. Phân tích bài toán theo cách duyệt chia đôi tập hợp
- Với cách duyệt toàn bộ ta thấy: để kiểm tra mỗi nghiệm (cách chọn các đồng xu) xem có thoả mãn hay không, ta cần biết tổng số tiền của các đồng đã chọn là bao nhiêu, đồng thời cần biết, số lượng đồng xu đã sử dụng
- **Vậy các giá trị cần lưu lại sau khi duyệt mỗi nửa của thuật toán duyệt chia đôi chính là tổng của các đồng xu, số lượng đồng xu đã chọn.**
- **Chuẩn bị trước**
  + Mảng xu[i] lưu giá trị của đồng xu thứ i với 1≤i≤34
  + Hai danh sách X1,X2 lưu các nghiệm của hai tập sau khi duyệt chia đôi
  + Sắp xếp lại danh sách X1 để chuẩn bị cho việc tìm kiếm.
- Với mỗi số tiền X ta cần: Thử từng cặp giá trị (sum,cnt) đã lưu được trong danh sách X2, cần tìm cặp (sum′,cnt′) trong danh sách X1 sao cho:
  + sum+sum′=X
  + cnt+cnt′ lớn nhất
- Vì sau khi sắp xếp lại, các phần tử có cùng tổng (sum) sẽ đứng cạnh nhau, phần tử có số lượng xu (cnt) nhỏ nhất sẽ xếp đầu tiên, phần tử có số lượng xu lớn nhất sẽ xếp cuối cùng.
- **Vậy phần tử cần tìm là phần tử ngay phía trước của phần tử đầu tiên có tổng xu lớn hơn X−sum, tức là phần tử đầu tiên lớn hơn hoặc bằng cặp ((X–sum)+1,0)**
- Có thể dùng hàm **lower_bound** như sau: `prev(L1.lower_bound(X–sum+1,0))`

### c. Code bài 34 đồng xu
        #include <bits/stdc++.h>
        using namespace std;
        #define pii pair<int,int>
        
        int n;
        int xu[35];
        vector<pii> x1,x2;
        
        
        // X = x1,x2,x3,...,xn
        //t là vị trí cuối cùng của tập
        void backtrack(int i, int sum, int cnt, int t){
          if (i > t){
            if(t == n/2) 
              x1.push_back({sum, cnt});
            else
              x2.push_back({sum, cnt});
            return;
          }
          backtrack(i + 1, sum, cnt, t);
          backtrack(i + 1, sum + xu[i], cnt + 1, t);
        
        }
        
        int main() {
          n = 34;
          xu[1] = 2;
          xu[2] = 3;
          xu[3] = 5;
          for(int i = 4; i <= n; i++) 
            xu[i] = xu[i - 1] + xu[i - 2] + xu[i - 3]; 
          backtrack(1, 0, 0, n/2);
          backtrack(n/2+1, 0, 0, n);
          sort(x1.begin(), x1.end());
          int test;
          cin >> test;
          for(int i = 1; i <= test; i++){
            int x, res = -1;
            cin >> x;
            for (auto v : x2){
              if (v.first <= x){
                vector<pii>::iterator low = lower_bound(x1.begin(), x1.end(), make_pair(x - v.first + 1,0));
                if ( low != x1.begin() && (*prev(low)).first + v.first == x){
                  res = max(res, v.second + (*prev(low)).second);
                }
              }
                    
            }
            cout << "Case #" << i << ": " << res << '\n';
          }
          return 0;
        }

## 4. Dấu hiệu của việc dùng Backtrack chia đôi tập
- n≤30–40
- Có thể lưu lại tham số nào đó để có thể tìm kiếm trong tập còn lại.

