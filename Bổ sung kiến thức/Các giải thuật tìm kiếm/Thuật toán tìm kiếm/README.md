> https://www.geeksforgeeks.org/searching-algorithms/?ref=lbp
>
> https://viblo.asia/p/bai-toan-tim-kiem-va-cac-thuat-toan-tim-kiem-thong-dung-djeZ1dEGKWz#_i-mo-dau-ve-bai-toan-tim-kiem-0
>
> https://codelearn.io/sharing/5-thuat-toan-tim-kiem-moi-ltv-nen-biet
>
> https://blog.28tech.com.vn/c-ham-qsort

# I. Các thuật toán tìm kiếm
+ Tìm kiếm tuyến tính(Linear Search) : là một giải thuật tìm kiếm rất cơ bản. Trong kiểu tìm kiếm này, một hoạt động tìm kiếm liên tiếp được diễn ra qua tất cả từng phần tử.
+ Tìm kiếm nhị phân(Binary Search): là một giải thuật tìm kiếm nhanh với độ phức tạp thời gian chạy là Ο(log n). Giải thuật tìm kiếm nhị phân làm việc dựa trên nguyên tắc chia để trị (Divide and Conquer).
> https://wiki.vnoi.info/algo/basic/Binary-Search
+ Tìm kiếm nội suy(Interpolation Search): là biến thể cải tiến của Tìm kiếm nhị phân (Binary Search). Để giải thuật tìm kiếm này làm việc chính xác thì tập dữ liệu phải được sắp xếp.
  
> Thuật toán Ternary Search
> Thuật toán Jump Search
> Thuật toán Exponential Search

## 1. Linear Search
> https://www.geeksforgeeks.org/linear-search/
>
> https://tek4.vn/khoa-hoc/cau-truc-du-lieu-va-thuat-toan/thuat-toan-tim-kiem-tuyen-tinh

![image](https://github.com/minchangggg/DSA/assets/125820144/77c80cab-1ed3-4af5-907e-8527d9b96eaf)

### a. Code
`Cách 1:`

        #include <bits/stdc++.h>
        using namespace std;
        
        bool linear_search(int arr[], int N, int x){
            for (int i = 0; i < N; i++)
                if (arr[i] == x) return true;
            return false;
        }
        
        int main(void){
            int arr[] = { 2, 3, 4, 10, 40 };
            int x = 10; int N = sizeof(arr) / sizeof(arr[0]);
            
            linear_search(arr, N, x) ? cout << "FOUND\n" : cout << "NOT FOUND\n";
            
            return 0;
        }

`Cách 2:` 

        #include <bits/stdc++.h>
        using namespace std;
        
        int linear_search(int arr[], int N, int x){
            for (int i = 0; i < N; i++)
                if (arr[i] == x) return i;
            return -1;
        }
        
        int main(void){
            int arr[] = { 2, 3, 4, 10, 40 };
            int x = 10; int N = sizeof(arr) / sizeof(arr[0]);
        
            int result = linear_search(arr, N, x);
            (result == -1)
                ? cout << "Element is not present in array"
                : cout << "Element is present at index " << result;
                
            return 0;
        }

> Output

        Element is present at index 3
### b. Ví dụ:
#### Ví dụ 1: Tìm vị trí đầu tiên của X trong mảng
        #include <iostream>
        using namespace std;
        
        int firstPos(int a[], int n, int x){
            for(int i = 0; i < n; i++){
                if(a[i] == x){
                    return i;
                }
            }
            return -1; // khong tim thay
        }
        
        int main(){
            int n = 10, x = 3;
            int a[10] = {6, 1, 2, 4, 3, 10, 9, 3, 8, 6};
            if(firstPos(a, n, x) != -1) cout << "Vi tri dau tien cua " << x << " : " << firstPos(a, n, x) << endl;
            else printf("NOT FOUND\n");
            return 0;
        }

> Output

        Vi tri dau tien cua 3 : 4
#### Ví dụ 2: Đếm số lần xuất hiện của X trong mảng
        #include <iostream>
        using namespace std;
        
        int count(int a[], int n, int x){
            int res = 0;
            for(int i = 0; i < n; i++){
                if(a[i] == x) ++res;
            }
            return res;
        }
        
        int main(){
            int n = 10, x = 3;
            int a[10] = {6, 1, 2, 4, 3, 10, 9, 3, 8, 6};
            cout << "So lan xuat hien cua " << x << " : " << count(a, n, x) << endl;
        }

> Output

        So lan xuat hien cua 3 : 2
## 2. Binary Search
> https://www.geeksforgeeks.org/binary-search/?ref=lbp
>
> https://tek4.vn/khoa-hoc/cau-truc-du-lieu-va-thuat-toan/thuat-toan-tim-kiem-nhi-phan

![image](https://github.com/minchangggg/DSA/assets/125820144/88fcbfcb-a970-413a-81e1-5861a0edd4af)

Binary Search có lợi thế lớn về độ phức tạp thời gian khi so sánh với Linear Search. Linear Search có độ phức tạp trường hợp xấu nhất là Ο(n) trong khi Binary Search là Ο(log n).
### a. Code
`Dùng vòng lặp`

        #include <bits/stdc++.h>
        using namespace std;
        
        int binarySearch(int arr[], int low, int high, int x){
            while (low <= high) {
                int mid = low + (high - low) / 2;
        
                // Check if x is present at mid
                if (arr[mid] == x) return mid;
        
                // If x greater, ignore left half
                if (arr[mid] < x) low = mid + 1;
        
                // If x is smaller, ignore right half
                else high = mid - 1;
            }
        
            // If we reach here, then element was not present
            return -1;
        }
        
        int main(void){
            int arr[] = { 2, 3, 4, 10, 40 };
            int x = 10; int n = sizeof(arr) / sizeof(arr[0]);
        
            int result = binarySearch(arr, 0, n - 1, x);
            (result == -1)
                ? cout << "Element is not present in array"
                : cout << "Element is present at index " << result;
                
            return 0;
        }

> Output

        Element is present at index 3

`Dùng đệ quy`

        #include <bits/stdc++.h>
        using namespace std;
        
        // A recursive binary search function. It returns location of x in given array arr[low..high] is present, otherwise -1
        int binarySearch(int arr[], int low, int high, int x){
            if (high >= low) {
                int mid = low + (high - low) / 2;
        
                // If the element is present at the middle itself
                if (arr[mid] == x) return mid;
        
                // If element is smaller than mid, then it can only be present in left subarray
                if (arr[mid] > x) return binarySearch(arr, low, mid - 1, x);
        
                // Else the element can only be present in right subarray
                return binarySearch(arr, mid + 1, high, x);
            }
        }
        
        int main(){
            int arr[] = { 2, 3, 4, 10, 40 };
            int query = 10; int n = sizeof(arr) / sizeof(arr[0]);
        
            int result = binarySearch(arr, 0, n - 1, query);
            (result == -1)
                ? cout << "Element is not present in array"
                : cout << "Element is present at index " << result;
                
            return 0;
        }

> Output

        Element is present at index 3

### b. Ví dụ
#### Ví dụ 1: Tìm vị trí đầu tiên của phần tử X trong mảng đã được sắp xếp 
`Độ phức tạp: O(logN)`

        int firstPos(int a[], int n, int x){
          int res = -1, left = 0, right = n - 1;
          while(left <= right){
            int mid = (left + right) / 2;
            if(a[mid] == x){
              res = mid; // cập nhật
              //Tìm thêm đáp án tốt hơn
              right = mid - 1;
            }
            else if(a[mid] < x) left = mid + 1;
            else right = mid - 1;
          }
          return res;
        }
#### Ví dụ 2: Tìm vị trí cuối cùng của phần tử X trong mảng đã được sắp xếp 
`Độ phức tạp: O(logN)`

        int lastPos(int a[], int n, int x){
          int res = -1, left = 0, right = n - 1;
          while(left <= right){
            int mid = (left + right) / 2;
            if(a[mid] == x){
              res = mid; // cập nhật
              //Tìm thêm đáp án tốt hơn
              left = mid + 1;
            }
            else if(a[mid] < x) left = mid + 1;
            else right = mid - 1;
          }
          return res;
        }
#### Ví dụ 3: Tìm vị trí đầu tiên của phần tử lớn hơn hoặc bằng X trong mảng đã được sắp xếp
`Độ phức tạp: O(logN)`

        int lower(int a[], int n, int x){
          int res = -1;
          int left = 0, right = n - 1;
          while(left <= right){
            int mid = (left + right) / 2;
            if(a[mid] >= x){
              res = mid; // cập nhật
              //Tìm thêm đáp án tốt hơn
              right = mid - 1;
            }
            else left = mid + 1;
          }
          return res;
        }
#### Ví dụ 4: Tìm vị trí cuối cùng của phần tử nhỏ hơn hoặc bằng X trong mảng đã được sắp xếp
`Độ phức tạp: O(logN)`
        
        int upper(int a[], int n, int x){
          int res = -1;
          int left = 0, right = n - 1;
          while(left <= right){
            int mid = (left + right) / 2;
            if(a[mid] <= x){
              res = mid; // cập nhật
              //Tìm thêm đáp án tốt hơn
              left = mid + 1;
            }
            else right = mid - 1;
          }
          return res;
        }
        
## 3. Interpolation Search
> https://www.geeksforgeeks.org/interpolation-search/?ref=lbp
>
> https://tek4.vn/khoa-hoc/cau-truc-du-lieu-va-thuat-toan/thuat-toan-tim-kiem-noi-suy

`Độ phức tạp thời gian chạy của Interpolation Search là Ο(log (log n)), trong khi của Binary Search là Ο(log n).`

- Đây là một trong những thuật toán tìm kiếm được sử dụng nhiều nhất, bởi nó nhanh hơn và chính xác hơn bất kì thuật toán tìm kiếm nào.
- Thuật toán tìm kiếm nội suy (Interpolation Search) là sự cải tiến của thuật toán tìm kiếm nhị phân (Binary Search). Tuy nhiên nó linh động hơn rất nhiều so với tìm kiếm nhị phân. Để giải thuật tìm kiếm này làm việc chính xác thì tập dữ liệu phải được sắp xếp.
- Nói một cách dễ hiểu hơn, tìm kiếm nhị phân chia nữa mảng bắt đầu từ đầu mảng đến cuối mảng. Tìm kiếm nội suy (Interpolation Search) sẽ tìm ra phần tử gần giá trị tìm kiếm nhất và bắt đầu tìm từ đó. Như vậy thời gian tìm kiếm nhanh hơn và phạm vi tìm kiếm được thu hẹp hơn rất nhiều.
- Ví dụ: Chúng ta có danh sách các sinh viên trong một lớp. Nếu chúng ta muốn tìm một bạn tên Tiến, thì chúng ta sẽ ưu tiên việc tìm kiếm từ cuối danh sách. Chứ không nên tìm kiếm từ đầu danh sách vì điều đó rất mất thời gian.
### a. Code
        int InterPolationSearch(int arr[], int n, int x){
          int left = 0, right = n-1;
          while (left <= right && x >= arr[left] && x <= arr[right]){
            double val1 = (double) (x - arr[left]) / (arr[right]-arr[left]);
            int val2 = (right-left);
            int Search = left + val1*val2;
           
            if (arr[Search] == x) return Search;
            else if (arr[Search] < x) left = Search + 1;
            else right = Search - 1;
          }
          return -1;
        }
        
### b. Giải thích thuật toán
        Giả xử chúng ta có:
          + Left, right là hai vị trí đầu và cuối.
          + T là tập.
          + X là giá trị cần tìm.

- Bước 1:Chúng ta sẽ sử dụng công thức tìm phần tử chính giữa của tập theo cách tìm kiếm
  + Tìm kiếm nhị phân: `Search = left + (right - left) * 1/2`
  + Tìm kiếm nội suy: `Search = left + (X- T[left]) * (right – left) / (T[right] – T[left])`
- Bước 2: Sau khi xác định được phần tử giữa (middle), chúng ta sẽ kiểm tra T[Search] nếu bằng X thì Search chính là vị trí cần tìm, thoát vòng lặp.
  + Nếu Search < X thì tăng left lên một đơn vị rồi quay lại bước 1.
  + Nếu Search > X thì giảm right xuống một đơn vị rồi quay lại bước 1.
### c. Ví dụ
        #include <bits/stdc++.h>
        using namespace std;
          
        int InterPolationSearch(int arr[], int n, int x) {
            int left = 0;
            int right = n-1;
            while (left <= right && x >= arr[left] && x <= arr[right]){
                double val1 = (double) (x - arr[left]) / (arr[right]-arr[left]);
                int val2 = (right-left);
                int Search = left + val1*val2;
        
                if (arr[Search] == x) return Search;
                else if (arr[Search] < x) left = Search + 1;
                else right = Search - 1;
            }
            return -1;
        }
         
        int main() {       
            int arr[] = {1, 3, 1, 8, 4, 6}; sort(arr, arr + 6); // 1 1 3 4 6 8
            int x = 4; // giá trị cần tìm
            int n = sizeof(arr) / sizeof(arr[0]);
            int result = InterPolationSearch(arr, n, x);
            (result == -1) 
            ? cout << "Element " << x << " is not present in array"
            : cout << "Element " << x << " is present at index " << result;
        }

# II. Các hàm tìm kiếm nhị phân trong STL C++
> https://viblo.asia/p/gioi-thieu-mot-so-ham-tim-kiem-co-san-trong-stl-c-Do754OvLlM6#_3-ham-lower_bound-4
## 1. Hàm binary_search
### a. Cú pháp:
- Dạng 1: `binary_search(l, r, val);`
- Dạng 2: `binary_search(l, r, val, comp);`
### b. Tác dụng: 
- Tìm kiếm xem giá trị val có xuất hiện trong đoạn [l,r−1] của đoạn cần tìm không (lưu ý đoạn tìm kiếm phải được sắp xếp theo một trật tự nhất định). Nếu tìm thấy val thì trả về true, ngược lại trả về false.
- Ở dạng 1, phép so sánh mặc định của hàm là <, nghĩa là hai phần tử a,b được xem là bằng nhau nếu như !(a < b) && !(b < a).
- Ở dạng 2, các bạn có thể tự viết một hàm so sánh kiểu boolean comp theo ý mình, khi đó hai phần tử a,b được xem là bằng nhau nếu như !(comp(a, b)) && !(comp(b, a)).
- Lưu ý, nếu như không gian tìm kiếm có kiểu của các phần tử là pair, thì phép so sánh sẽ ưu tiên thực hiện theo trường first trước, rồi mới tới trường second.
### c. Độ phức tạp của hàm: 
`O(log2(n))`, với n là kích thước không gian tìm kiếm.
### d. Ví dụ:

        #include <iostream>
        #include <algorithm>
        #include <vector>
        
        using namespace std;
        
        bool comp(int a, int b){
            return a > b;	
        }
        
        int main(){
            int a[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
            // Copy mảng a sang vector v. Sau đây v = {1, 2, 3, 4, 5, 4, 3, 2, 1}.
            vector < int > v(a, a + 9); 
        	
            sort(a, a + n); // a = {1, 1, 2, 2, 3, 3, 4, 4, 5}.
            
            if (binary_search(a, a + n, 5)) cout << "Tìm thấy phần tử 5" << endl;
            else cout << "Không tìm thấy phần tử 5" << endl;
        	
            sort(v.begin(), v.end(), comp); // v = {5, 4, 4, 3, 3, 2, 2, 1, 1}.
            if (binary_search(a, a + n, 6, comp)) cout << "Tìm thấy phần tử 6";
            else cout << "Không tìm thấy phần tử 6";
        
            return 0;
        }

> Output

        Tìm thấy phần tử 5
        Không tìm thấy phần tử 6
## 2. Hàm lower_bound
![image](https://github.com/minchangggg/DSA/assets/125820144/93e29cd7-ab95-499b-b426-4c6357293421)

### a. Cú pháp:
- Dạng 1: `lower_bound(l, r, val);`
- Dạng 2: `lower_bound(l, r, val, comp);`
### b. Tác dụng: 
- Trả về iterator hoặc con trỏ trỏ tới phần tử đầu tiên trong đoạn [l,r−1] mà **lớn hơn hoặc bằng** khóa tìm kiếm val. Nếu như không tìm thấy, hàm sẽ trả về iterator trỏ vào vị trí r. Đoạn tìm kiếm bắt buộc phải được sắp xếp theo đúng phép toán so sánh của hàm.
  + Ở dạng 1, phép toán so sánh mặc định là <. Nghĩa là hàm sẽ trả về iterator vào vị trí đầu tiên mà (*it >= val)
  + Ở dạng 2, phép toán so sánh sẽ được định nghĩa theo hàm boolean comp do người dùng tự viết. Hàm comp phải bao gồm hai tham số a và b - đại diện cho phần tử trong đoạn tìm kiếm và khóa tìm kiếm. Khi sử dụng hàm comp làm phép so sánh, hàm lower_bound sẽ trả về iterator vào vị trí đầu tiên mà (comp(*it, val) == false).
- Lưu ý, nếu như không gian tìm kiếm có kiểu của các phần tử là pair, thì phép so sánh sẽ ưu tiên thực hiện theo trường first trước, rồi mới tới trường second.
### c. Độ phức tạp của hàm 
`O(log2(n))`, với n là kích thước không gian tìm kiếm.
### d. Ví dụ
#### Ví dụ 1
        #include <iostream>
        #include <algorithm>
        #include <vector>
        
        using namespace std;
        
        bool comp(int a, int b){
            return a > b;	
        }
        
        int main(){
            int a[] = {10, 20, 30, 40, 50, 40, 30, 20, 10};
            vector < int > v(a, a + 9); 
        	
            sort(a, a + 9); // a = {10, 10, 20, 20, 30, 30, 40, 40, 50}
        	
            // Tìm vị trí của phần tử đầu tiên lớn hơn hoặc bằng 30 trong mảng a.
            // Muốn đưa ra vị trí là số nguyên thì lấy kết quả hàm trừ đi iterator a[0].
            int pos1 = lower_bound(a, a + 9, 30) - a;
            cout << "Vị trí đầu tiên lớn hơn hoặc bằng 30 là: " << pos1 << endl;
        
            sort(v.begin(), v.end(), comp); // v = {50, 40, 40, 30, 30, 20, 20, 10, 10};
            
            // Tìm vị trí đầu tiên nhỏ hơn hoặc bằng số 20 trong đoạn [0, 5] của vector v.
            // Tương tự, lấy hai iterator trừ cho nhau để ra được vị trí là số nguyên.
            int pos2 = lower_bound(v.begin(), v.begin() + 5, 20, comp) - v.begin();
            cout << "Vị trí đầu tiên nhỏ hơn hoặc bằng 20 là: " << pos2;
        	
            return 0;
        }

> Output

        Vị trí đầu tiên lớn hơn hoặc bằng 30 là: 4
        Vị trí đầu tiên lớn hơn hoặc bằng 20 là: 5
#### Ví dụ 2: lower_bound với mảng
        #include <bits/stdc++.h>
        using namespace std;
        
        int main(){
          int a[7] = {1, 2, 3, 3, 3, 4, 6};
          
          auto it1 = lower_bound(a, a + 7, 3);
          cout << *it1 << endl;
          cout << (it1 - a) << endl;
        
          auto it2 = lower_bound(a, a + 7, 8);
          (it2 == a + 7) ? cout << "NOT FOUND" : cout << *it2 << endl;
          cout << (it2 - a) << endl;
        }

> Output

        3
        2
        NOT FOUND
        7
#### Ví dụ 3: lower_bound với vector
        #include <bits/stdc++.h>
        using namespace std;
        int main(){
          vector<int> a = {1, 2, 3, 3, 3, 4, 6};
          
          auto it1 = lower_bound(a.begin(), a.end(), 3);
          (it1 == a.end()) ? cout << "NOT FOUND\n" : else cout << *it1 << endl;
          cout << (it1 - a.begin()) << endl;
        
          auto it2 = lower_bound(a.begin(), a.end(), 8);
          (it2 == a.end()) ? cout << "NOT FOUND\n" : cout << *it2 << endl;
          cout << (it2 - a.begin()) << endl;
        }

> Output

        3
        2
        NOT FOUND
        7
#### Ví dụ 4
        #include <bits/stdc++.h>
        using namespace std;
        int main(){
            vector<int> a = {1, 1, 3, 3, 3, 4, 6};
        
            auto it1 = lower_bound(a.begin(), a.end(), 2); // &a[2]
            --it1; // &a[1]
            cout << *it1 << endl; // 1
        
            auto it2 = lower_bound(a.begin(), a.end(), 7); // &a[7]
            --it2; // &a[6]
            cout << *it2 << endl; // 6
        }

> Output

        1
        6
#### Ví dụ 5
        #include <bits/stdc++.h>
        using namespace std;
        
        int main(){
            vector<int> a = {1, 1, 3, 3, 3, 4, 6}; // n = 7
        
            auto it1 = lower_bound(a.begin(), a.end(), 7); // &a[7]
            it1 -= 2; // &a[5]
            cout << *it1 << endl; // 4
        
            auto it2 = lower_bound(a.begin(), a.end(), 0); // &a[0]
            it2--; // ....
            cout << *it2 << endl; // gtri rác
        }
        
> Output

        4
        335575821
## 3. Hàm upper_bound
### a. Cú pháp:
- Dạng 1: `upper_bound(l, r, val);`
- Dạng 2: `upper_bound(l, r, val, comp);`
### b. Tác dụng 
- Trả về iterator hoặc con trỏ trỏ tới phần tử đầu tiên trong đoạn [l,r−1] mà **lớn hơn hẳn** khóa tìm kiếm **val**. Nếu như không tìm thấy, hàm sẽ trả về iterator trỏ vào vị trí r. Đoạn tìm kiếm bắt buộc phải được sắp xếp theo đúng phép toán so sánh của hàm.
  + Ở dạng 1, phép toán so sánh mặc định là <. Nghĩa là hàm sẽ trả về iterator vào vị trí đầu tiên mà (*it > val) (khác với lower_bound, các bạn chú ý phân biệt).
  + Ở dạng 2, phép toán so sánh sẽ được định nghĩa theo hàm boolean comp do người dùng tự viết. Hàm comp phải bao gồm hai tham số a và b - đại diện cho phần tử trong đoạn tìm kiếm và khóa tìm kiếm. Khi sử dụng hàm comp làm phép so sánh, hàm upper_bound sẽ trả về iterator vào vị trí đầu tiên mà (comp(*it, val) == false). Lưu ý, phần tử mà hàm upper_bound trả về sẽ không thể bằng với khóa val.
- Lưu ý, nếu như không gian tìm kiếm có kiểu của các phần tử là pair, thì phép so sánh sẽ ưu tiên thực hiện theo trường first trước, rồi mới tới trường second.
### c. Độ phức tạp của hàm: 
`O(log2(n))`, với n là kích thước không gian tìm kiếm.
### d. Ví dụ
#### Ví dụ 1
        #include <iostream>
        #include <algorithm>
        #include <vector>
        
        using namespace std;
        
        bool comp(int a, int b){
            return a > b;	
        }
        
        int main(){
            int a[] = {10, 20, 30, 40, 50, 40, 30, 20, 10};
            vector < int > v(a, a + 9);
        	
            sort(a, a + 9); // a = {10, 10, 20, 20, 30, 30, 40, 40, 50}
        	
            // Tìm vị trí của phần tử đầu tiên lớn hơn 30 trong mảng a.
            // Muốn đưa ra vị trí là số nguyên thì lấy kết quả hàm trừ đi iterator a[0].
            int pos1 = upper_bound(a, a + 9, 30) - a;
            cout << "Vị trí đầu tiên lớn hơn 30 là: " << pos1 << endl;
        
            // v = {50, 40, 40, 30, 30, 20, 20, 10, 10};
            sort(v.begin(), v.end(), comp);
            
            // Tìm vị trí đầu tiên nhỏ hơn hơn 50 trong đoạn [0, 5] của vector v.
            // Tương tự, lấy hai iterator trừ cho nhau để ra được vị trí là số nguyên.
            int pos2 = upper_bound(v.begin(), v.end(), 50, comp) - v.begin();
            cout << "Vị trí đầu tiên nhỏ hơn 50 là: " << pos2;
        	
            return 0;
        }

> Output

        Vị trí đầu tiên lớn hơn 30 là: 6
        Vị trí đầu tiên nhỏ hơn 50 là: 1
#### Ví dụ 2: upper_bound với mảng
        #include <bits/stdc++.h>
        using namespace std;
        int main(){
          int a[7] = {1, 2, 3, 3, 3, 4, 6};
          
          auto it1 = upper_bound(a, a + 7, 3);
          cout << *it1 << endl;
          cout << (it1 - a) << endl;
        
          auto it2 = upper_bound(a, a + 7, 8);
          (it2 == a + 7) ? cout << "NOT FOUND" : cout << *it2 << endl;
          cout << (it2 - a) << endl;
        }

> Output

        4
        5
        NOT FOUND
        7
#### Ví dụ 3: upper_bound với vector
        #include <bits/stdc++.h>
        using namespace std;
        int main(){
          vector<int> a = {1, 2, 3, 3, 3, 4, 6};
          
          auto it1 = upper_bound(a.begin(), a.end(), 3);
          (it1 == a.end()) ? cout << "NOT FOUND\n" : cout << *it1 << endl;
          cout << (it1 - a.begin()) << endl;
          
          auto it2 = upper_bound(a.begin(), a.end(), 6);
          (it2 == a.end()) ? cout << "NOT FOUND\n" : cout << *it2 << endl;
          cout << (it2 - a.begin()) << endl;
        }

> Output

        4
        5
        NOT FOUND
        7

## 4. Hàm equal_range
### a. Cú pháp:
- Dạng 1: `equal_range(l, r, val);`
- Dạng 2: `equal_range(l, r, val, comp);`
### b. Tác dụng: 
- Hàm equal_range trả về một biến kiểu pair có hai trường đều là iterator hoặc con trỏ trỏ vào khoảng có giá trị tương đương với khóa tìm kiếm val trong đoạn [l,r]. Thực tế, hàm này là sự kết hợp giữa lower_bound và upper_bound, nó sẽ trả về một cặp iterator (first, second) thỏa mãn:
  + Phần tử ở iterator first là phần tử đầu tiên lớn hơn hoặc bằng khóa val.
  + Phần tử ở iterator second là phần tử đầu tiên lớn khóa val.
- Nếu như không tồn tại khoảng nào như vậy, hàm sẽ trả về hai iterator bằng nhau: Hoặc cùng trỏ vào phần tử đầu tiên lớn hơn val, hoặc cùng trỏ vào iterator r nếu như val lớn hơn tất cả các phần tử trong đoạn tìm kiếm.
- Đoạn tìm kiếm cần được sắp xếp tuân theo phép so sánh của hàm trước khi sử dụng.
- Ở dạng 1, phép so sánh mặc định của hàm là <, nghĩa là áp dụng phép so sánh này với hàm lower_bound cho iterator first và upper_bound cho iterator second.
- Ở dạng 2, phép so sánh mặc định của hàm là hàm comp do người dùng tự viết, nghĩa là áp dụng hàm này làm phép so sánh cho hàm lower_bound cho iterator first và upper_bound cho iterator second.
- Lưu ý, nếu như không gian tìm kiếm có kiểu của các phần tử là pair, thì phép so sánh sẽ ưu tiên thực hiện theo trường first trước, rồi mới tới trường second.
### c. Độ phức tạp của hàm: 
`O(2×log2(n))`, với n là kích thước không gian tìm kiếm.
### d. Ví dụ:
        #include <iostream>
        #include <algorithm>
        #include <vector>
        #include <utility>
        
        using namespace std;
        
        bool comp(int a, int b){
            return a > b;
        }
        
        int main(){
            int a[] = {10, 20, 30, 30, 20, 10, 10, 20};
            // Biến tìm kiếm đối với mảng phải sử dụng con trỏ.
            pair < int* , int* > bounds_1;
            
            vector < int > v(a, a + 8);
            // Biến tìm kiếm đối với vector phải sử dụng iterator.
            pair < vector < int > :: iterator, vector < int > :: iterator > bounds_2;
        
            // a = {10, 10, 10, 20, 20, 20, 30, 30}.
            sort(a, a + 8);
        
            // Dùng phép toán so sánh mặc định với mảng a.
            // Tìm kiếm đoạn đầu tiên bằng 20.
            bounds_1 = equal_range(a, a + 8, 20); // Đoạn [3, 6].
            cout << bounds_1.first - a << ' ' << bounds_1.second - a << endl;
        
            // v = {30, 30, 20, 20, 20, 10, 10, 10}.
            sort(v.begin(), v.end(), comp);
        
            // Dùng phép toán so sánh comp với vector v.
            // Iterator first: Trỏ vào phần tử đầu tiên nhỏ hơn hoặc bằng 20.
            // Iterator second: Trỏ vào phần tử đầu tiên nhỏ hơn 20.
            bounds_2 = equal_range(v.begin(), v.end(), 20, comp); // Đoạn [2, 5].
            cout << bounds_2.first - v.begin() << ' ' << bounds_2.second - v.begin() << endl;
        
            return 0;
        }
        
> Output
        
        3 6
        2 5
