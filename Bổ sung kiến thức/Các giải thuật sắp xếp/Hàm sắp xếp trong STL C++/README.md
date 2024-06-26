> https://viblo.asia/p/gioi-thieu-mot-so-ham-tim-kiem-co-san-trong-stl-c-Do754OvLlM6
## I. Hàm soft() trong thư viện STL
![image](https://github.com/minchangggg/DSA/assets/125820144/f6da83cb-47ee-464e-9c36-ffab61d9dde9)
## 1. Khai báo thư viện
- Để sử dụng hàm sort(), chúng ta cần khai báo thư viện algorithm: `#include<algorithm>`
## 2. Truy cập địa chỉ của phần tử trong mảng và vector
- Các hàm thao tác trên đoạn trong thư viện <algorithm> đều sử dụng các tham số là các địa chỉ. Mỗi biến được tạo ra trong khi lập trình đều có địa chỉ cụ thể trong bộ nhớ, và các biến địa chỉ sẽ giúp chúng ta truy cập tới địa chỉ của biến đó. Đối với mảng và vector, ta có cách truy cập nhanh tới địa chỉ của các phần tử như sau:
+ Đối với mảng: **{Tên_mảng} + {Vị_trí};**
+ Đối với vector: **{Tên_vector}.begin() + {Vị_trí};**
## 3. Sắp xếp cơ bản
- Hàm sort() trong C++ là hàm thuật toán thuộc thư viện algorithm, bạn có thể sử dụng ngay hàm này khi cần sắp xếp mà không cần cài đặt lại từ đầu. 
- Hàm sort() được cài đặt trong C++ là hàm intro - sort, đây là sự kết hợp của 2 thuật toán sắp xếp rất hiệu quả là quick sort và heap sort 
- Độ phức tạp của hàm sort() là O(NlogN). Bạn có thể sử dụng hàm này để sắp xếp mảng, vector, string. 
- Mặc định thì hàm này sẽ sắp xếp mảng của bạn tăng dần về giá trị số hoặc từ điển, nếu muốn sắp xếp giảm dần bạn cần thêm tham số greater()
## a. Cú pháp sort mảng 
### Sắp xếp toàn bộ mảng a có n phần tử

![image](https://github.com/minchangggg/DSA/assets/125820144/fb91192d-749b-4dec-93e4-7b6a8040d4f3)

### Sắp xếp mảng giảm dần

![image](https://github.com/minchangggg/DSA/assets/125820144/fae74b64-bcc1-4f6b-9c38-1dc8ac8bd10d)

### Sắp xếp mảng a từ chỉ số x tới chỉ số y

![image](https://github.com/minchangggg/DSA/assets/125820144/2343da9d-f5a9-4246-9d12-6c3ba5c7c70f)

- Ví dụ 1 : 

                #include<iostream>
                #include<algorithm>
                using namespace std;
                
                int main() {
                    int a[6] = {5, 4, 3, 2, 1, 0};
                    sort(a, a + 6);  // thu được 0 1 2 3 4 5
                    for (int x: a) cout << x << ' ';
                    cout << endl;
                    
                    int b[6] = {5, 4, 3, 2, 1, 0};
                    sort(b, b + 6, greater<int>()); // thu được 5 4 3 2 1 0
                    for (int x: b) cout << x << ' ';
                    cout << endl;
                
                    int c[6] = {5, 4, 3, 2, 1, 0};
                    sort(c + 2, c + 5);  // thu được 5 4 (1 2 3) 0
                    for (int x: c) cout << x << ' ';
                    
                    return 0;
                }

> Output : 

                0 1 2 3 4 5 
                5 4 3 2 1 0 
                5 4 1 2 3 0 

- Ví dụ 3:
  
                #include <bits/stdc++.h>
                using namespace std;
                 
                int main() {
                    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
                    int n = sizeof(arr) / sizeof(arr[0]);
                 
                    sort(arr, arr + n, greater<int>());
                 
                    cout << "Array after sorting : \n";
                    for (int i = 0; i < n; ++i)
                        cout << arr[i] << " ";
                 
                    return 0;
                }

> Output:

                Array after sorting : 
                9 8 7 6 5 4 3 2 1 0 
                
**Nếu bạn có mảng string hay mảng char thì hàm sort() sẽ sắp xếp mặc định theo thứ tự từ điển tăng dần.**

- Ví dụ 3 : 

                #include <iostream>
                #include <algorithm>
                
                using namespace std;
                
                int main(){
                    char a[8] = {'2', '8', 't', 'e', 'c', 'h', 'a', 'z'};
                  
                    sort(a, a + 8);
                    for(char x : a) cout << x << ' ';
                    cout << endl;
                    
                    sort(a, a + 8, greater<char>());
                    for(char x : a) cout << x << ' ';
                }

> Output : 

                2 8 a c e h t z 
                z t h e c a 8 2 


## b. Cú pháp sort vector 
![image](https://github.com/minchangggg/DSA/assets/125820144/41fa99fe-a3d3-465f-8c8d-7efa9338f23d)

- Ví dụ:

                #include <iostream>
                #include <algorithm>
                #include <vector>
                
                using namespace std;
                
                int main(){
                	vector<int> v = {3, 1, 2, 5, 4};
                    
                	sort(v.begin(), v.end());
                	for (int x : v) cout << x << ' ';
                        cout << endl;
                
                	sort(v.begin(), v.end(), greater<int>());
                	for (int x : v) cout << x << ' ';
                }

# II. Hàm stable_sort() Trong C++ 
C++ có sẵn 2 hàm sắp xếp đó là sort() và stable_sort()
## 1. Tính chất ổn định - stable của thuật toán sắp xếp
- Các thuật toán sắp xếp chia thành 2 loại là ổn định và không ổn định
   + Các thuật toán sắp xếp không ổn định có thể kể đến như : sắp xếp nhanh quicksort, sắp xếp vun đống heap sort, sắp xếp chọn selection sort.
   + Các thuật toán sắp xếp ổn định bao gồm : sắp xếp trộn merge sort, sắp xếp chèn insertion sort, tim sort, sắp xếp đếm phân phối counting sort.
- Vậy tính ổn định của thuật toán sắp xếp là gì ? 
   + Tính ổn định của thuật toán sắp xếp có thể hiểu đơn giản là khi bạn sắp xếp các phần tử trong mảng mà có cùng giá trị sắp xếp (ví dụ như giá trị về độ lớn, tổng chữ số ..) thì những phần tử này sẽ đứng cạnh nhau và duy trì thứ tự giống như thứ tự giữa chúng trong mảng ban đầu.
   + Ví dụ bạn có dãy số (111, 9, 3000, 18, 81, 1002, 2002) và muốn sắp xếp các phần tử này theo tổng chữ số tăng dần bằng thuật toán sắp xếp có tính chất stable thì mảng sẽ được sắp xếp theo thứ tự (111, 3000, 1002, 2002, 9, 18, 81) trong đó (111, 3000, 1002) có cùng tổng chữ số là 3 và chúng giữ đúng thứ tự ban đầu như thứ tự xuất hiện. Tương tự với cụm (9, 18, 81) có cùng tổng chữ số là 9.
- Trong một số ngôn ngữ lập trình thì hàm sắp xếp được cài đặt bởi các thuật toán sắp xếp có tính ổn định, ví dụ như Java, Python, JS. Trong C++ thì hàm sort() mà bạn đã học ở bài trước không có tính ổn định, C++ cung cấp thêm hàm stable_sort() có tính chất stable, hàm này được cài đặt bởi thuật toán sắp xếp trộn Merge sort.
## 2. Hàm stable_sort() trong C++
- Khi làm bài tập về sắp xếp nếu đề bài có thêm yêu cầu trong trường hợp các phần tử trong mảng, danh sách có cùng giá trị sắp xếp thì cần giữ nguyên thứ tự xuất hiện giữa các phần tử này thì khi đó bạn cần nghĩ ngay tới hàm stable_sort()
- Cách sử dụng hàm stable_sort() giống với hàm sort(), chỉ khác nhau ở thuật toán mà họ đã cài đặt chúng.
- Ví dụ 1: Sắp xếp dãy số theo tổng chữ số tăng dần và giữ nguyên thứ tự xuất hiện giữa chúng nếu có cùng tổng chữ số

                #include <iostream>
                #include <algorithm>
                
                using namespace std;
                
                int tong(int n){
                    int sum = 0;
                    while(n){
                        sum += n % 10;
                        n /= 10;
                    }
                    return sum;
                }
                
                bool cmp(int a, int b){
                    return tong(a) < tong(b);
                }
                
                int main(){
                    int a[11] = {10002, 19, 3000, 111, 81, 45, 1002, 21, 10071, 203, 401};
                    stable_sort(a, a + 11, cmp);
                    for(int x : a) cout << x << " ";    
                }
                
> Output : 
                 
                10002 3000 111 1002 21 203 401 81 45 10071 19

-> Nhận xét : Bạn chỉ cần xây dựng hàm so sánh để sắp xếp theo tổng chữ số tăng dần còn khi các số trong mảng có cùng tổng chữ số thì hàm stable_sort() sẽ giữ thứ tự tương đối giữa chúng.

- Ví dụ 2:

                #include <bits/stdc++.h>
                using namespace std;
                 
                struct Interval { // An interval has start time and end time
                    int start, end; 
                };
                 
                // Compares two intervals according to starting times.
                bool compareInterval(Interval i1, Interval i2) {
                    return (i1.start < i2.start);
                }
                 
                int main() {
                    // Given intervals are sorted according to end time
                    Interval arr[] = { { 1, 3 }, { 2, 4 }, { 1, 7 }, { 2, 19 } };
                    int n = sizeof(arr) / sizeof(arr[0]);
                 
                    // sort the intervals in increasing order of start time 
                    // such that the start time intervals appear in same order as in input.
                    stable_sort(arr, arr + n, compareInterval);
                 
                    cout << "Intervals sorted by start time : \n";
                    for (auto x : arr) cout << "[" << x.start << ", " << x.end << "] ";
                 
                    return 0;
                }

![image](https://github.com/minchangggg/DSA/assets/125820144/d55e6586-a944-41f8-9de5-71d996d1e53f)

# III. Xây Dựng Comparison Function Cho Hàm Sort Trong C++
![image](https://github.com/minchangggg/DSA/assets/125820144/74431d15-eeb4-4088-a01a-282142e59eb2)
## 1. Xây dựng comparison function 
- Hàm so sánh khi sử dụng hàm sort chính là tham số thứ 3 mà bạn sẽ truyền vào hàm khi sắp xếp mảng, vector. 
- Hàm này có kiểu trả về là true hoặc false và có 2 tham số với kiểu dữ liệu tương ứng với mảng mà bạn muốn sắp xếp.
- Tên của hàm so sánh bạn tự đặt, thông thường mình hay đặt là cmp.
- Cú pháp hàm so sánh :

![image](https://github.com/minchangggg/DSA/assets/125820144/94b708c6-6b45-4445-a6d7-242264a9636d)

- x và y ở đây bạn có thể coi như đó là 2 giá trị trong mảng mà bạn cần sắp xếp, khi sắp xếp thì hàm sort cần so sánh giá trị giữa 2 phần tử này. Bạn chỉ cần kiểm tra xem thứ tự của x và y có thỏa mãn x sẽ đứng trước y theo thứ tự sắp xếp của mảng không thì bạn trả về true, ngược lạ trả về false.
- Ví dụ như bạn muốn sắp xếp mảng tăng dần, vậy thì x nhỏ hơn y sẽ đứng trước y,  khi đó bạn kiểm tra nếu x < y thì bạn trả về true, ngược lại trả về false.

### a. Sắp xếp mảng tăng dần
                #include <iostream>
                #include <algorithm>
                
                using namespace std;
                
                bool cmp (int a, int b){
                    if(a < b) return true;
                    else return false;
                }
                
                int main(){
                    int a[12] = {1, 3, 3, 3, 2, 1, 2, 4, 2, 4, 0, 2};
                    sort(a, a + 12, cmp);
                    for (int x : a) cout << x << ' ';
                }

> Output : 

                0 1 1 2 2 2 2 3 3 3 4 4
### b. Sắp xếp mảng giảm dần 
                #include <iostream>
                #include <algorithm>
                
                using namespace std;
                
                bool cmp (int a, int b){
                    if(a > b) return true;
                    else return false;
                }
                
                int main(){
                    int a[12] = {1, 3, 3, 3, 2, 1, 2, 4, 2, 4, 0, 2};
                    sort(a, a + 12, cmp);
                    for (int x : a) cout << x << ' ';
                }

> Output : 

                4 4 3 3 3 2 2 2 2 1 1 0 
### c. Sắp xếp theo trị tuyệt đối tăng dần
                #include <iostream>
                #include <algorithm>
                
                using namespace std;
                
                bool cmp(int a, int b){
                    // if (abs(a) < abs(b)) return true;
                    // else return false;
                    return abs(a) < abs(b);
                }
                
                int main(){
                    int a[5] = {-9, 2, 4, -3, 1};
                    sort(a, a + 5, cmp);
                    for(int x : a) cout << x << ' ';
                }

> Output : 

                1 2 -3 4 -9 
### d. Sắp xếp mảng theo tổng chữ số tăng dần
                #include <bits/stdc++.h>
                using namespace std;
                
                int sum(int n){
                    int res = 0;
                    while(n){
                        res += n % 10; n /= 10;
                    }
                    return res;
                }
                
                bool cmp(int a, int b){
                    // if(sum(a) < sum(b)) return true;
                    // else return false;
                    return sum(a) < sum(b);
                }
                
                int main(){
                    int a[7] = {1000000, 212, 40, 9, 10001, 30, 449};
                    sort(a, a + 7, cmp);
                    for(int x : a)
                    cout << x << ' ';
                }

> Output : 

                1000000 10001 30 40 212 9 449 
### e. Sắp xếp theo bảng chữ cái kết hợp độ dài tăng dần:
                #include <iostream>
                #include <algorithm>
                
                using namespace std;
                
                bool cmp(string str1,string str2) {
                    return str1.length() < str2.length();
                }
                
                int main() {
                    string str[5] = {"c", "abc", "ac", "bb", "aaaa"};
                    sort(str, str + 5, cmp); 
                    for (string x : str) cout << x << ' ';
                    return 0;
                }

> Output :

                c ac bb abc aaaa        
## 2. Sắp xếp mảng với nhiều hơn 2 tiêu chí
- Thông thường khi sắp xếp mảng sẽ có những giá trị có cùng thứ tự sắp xếp và khi đó họ sẽ yêu cầu bạn thêm 1 tiêu chí phụ nữa.
- Ví dụ sắp xếp danh sách sinh viên theo gpa giảm dần, nếu 2 sinh viên có cùng gpa thì sinh viên nào có tên từ điển nhỏ hơn sẽ đứng trước.
### a. Ví dụ 1 : Sắp xếp mảng theo tổng chữ số tăng dần, nếu 2 số có cùng tổng chữ số thì số lớn hơn sẽ đứng trước.
                #include <iostream>
                #include <algorithm>
                
                using namespace std;
                
                int tong(int n){
                    int ans = 0;
                    while(n){
                        ans += n % 10;
                        n /= 10;
                    }
                    return ans;
                }
                
                bool cmp(int a, int b){
                    if(tong(a) != tong(b)) return tong(a) < tong(b); 
                    else return a > b;
                }
                
                int main(){
                    int a[9] = {111, 9, 3000, 20001, 18, 81, 405, 200, 1001};
                    sort(a, a + 9, cmp);
                    for (int x : a) cout << x << ' ';
                }

> Output : 

                1001 200 20001 3000 111 405 81 18 9
### b. Sắp xếp sao cho số chẵn đứng trước, lẻ đứng sau, chẵn giảm dần, lẻ tăng dần
                #include <iostream>
                #include <algorithm>
                
                using namespace std;
                // Sắp xếp sao cho số chẵn đứng trước, lẻ đứng sau, chẵn giảm dần, lẻ tăng dần
                bool cmp(int a, int b){
                    int r1 = a % 2, r2 = b % 2;
                
                    // chẵn đứng trước, lẻ đứng sau
                    if(r1 == 0 && r2 == 1) return true;
                    if(r1 == 1 && r2 == 0) return false;
                
                    // chẵn giảm dần, lẻ tăng dần
                    if(r1 == 0 && r2 == 0) return a > b;
                    if(r1 == 1 && r2 == 1) return a < b;
                }
                
                int main(){
                    int a[10] = {1, 2, 10, 9, 6, 5, 8, 7, 4, 3};
                    sort(a, a + 10, cmp);
                    cout << "Mang sau khi sap xep : \n";
                    for (int x : a) cout << x << ' ';
                }

> Output :

                10 8 6 4 2 1 3 5 7 9
### c. Sắp xếp các điểm trong hệ tọa độ Oxy sao cho hoành độ tăng dần, nếu hoành độ bằng nhau thì sắp xếp theo tung độ giảm dần
- Ở đây mình sẽ dùng pair để lưu điểm trong hệ tọa độ Oxy.

                #include <iostream>
                #include <algorithm>
                
                using namespace std;
                
                bool cmp(pair<int, int> x, pair<int, int> y){
                    if(x.first != y.first) return x.first < y.first;
                    else return x.second > y.second;
                }
                
                int main(){
                    pair<int, int> a[7] = {{3, 1}, {3, 2}, {1, 4}, {4, 3}, {3, 3}, {1, 1}, {4, 2}};
                    sort(a, a + 7, cmp);
                    for (auto x : a) cout << "(" << x.first << "," << x.second << ")" << ' ';
                }

> Output : 

                (1,4) (1,1) (3,3) (3,2) (3,1) (4,3) (4,2) 
### d. Sắp xếp theo tổng chữ số tăng dần, nếu 2 số có cùng tổng chữ số thì số nào được nhập trước sẽ xếp trước (Dùng stable_sort)
                #include <iostream>
                #include <algorithm>
                
                using namespace std;
                
                int sum(int n){
                    int res = 0;
                    while(n){
                        res += n % 10;
                        n /= 10;
                    }
                    return res;
                }
                
                bool cmp(int a, int b){
                    return sum(a) < sum(b);
                }
                
                int main(){
                    int a[5] = {22, 6, 4, 9, 33};
                    stable_sort(a, a + 5, cmp);
                    for(int x : a) cout << x << ' ';
                }

> Output :

                22 4 6 33 9

# IV. Ví dụ
                #include <algorithm>
                #include <iostream>
                using namespace std;
                 
                template <class T>
                class Comparator { // we pass an object of this class as third arg to sort function...
                public:
                    bool operator()(T x1, T x2) {
                        return x1 < x2;
                    }
                };
                 
                template <class T> bool funComparator(T x1, T x2) { // return type is bool
                    return x1 <= x2;
                }
                 
                void show(int a[], int array_size) {
                    for (int i = 0; i < array_size; i++) {
                        cout << a[i] << " ";
                    }
                }
                 
                int main() {
                    int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
                    int asize = sizeof(a) / sizeof(int);
                
                    cout << "The array before sorting is : "; show(a, asize);
                
                    cout << "\nThe array after sorting is(asc) :"; 
                    sort(a, a + asize); show(a, asize);
                
                    cout << "\nThe array after sorting is(desc) :";
                    sort(a, a + asize, greater<int>()); show(a, asize);
                    
                    cout << "\nThe array after sorting is(asc but our comparator class) :";
                    sort(a, a + asize, Comparator<int>()); show(a, asize);
                
                    cout << "\nThe array after sorting is(asc but our comparator function) :";
                    sort(a, a + asize, funComparator<int>); show(a, asize);
                 
                    return 0;
                }
