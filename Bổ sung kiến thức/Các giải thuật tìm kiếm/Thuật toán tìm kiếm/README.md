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

### Code
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
### Ví dụ 1: Tìm vị trí đầu tiên của X trong mảng
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
### Ví dụ 2: Đếm số lần xuất hiện của X trong mảng
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
### Code
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

### Ví dụ 1: Tìm vị trí đầu tiên của phần tử X trong mảng đã được sắp xếp 
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
### Ví dụ 2: Tìm vị trí cuối cùng của phần tử X trong mảng đã được sắp xếp 
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
### Ví dụ 3: Tìm vị trí đầu tiên của phần tử lớn hơn hoặc bằng X trong mảng đã được sắp xếp
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
### Ví dụ 4: Tìm vị trí cuối cùng của phần tử nhỏ hơn hoặc bằng X trong mảng đã được sắp xếp
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
