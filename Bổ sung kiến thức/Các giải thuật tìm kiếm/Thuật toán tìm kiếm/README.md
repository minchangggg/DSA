> https://www.geeksforgeeks.org/searching-algorithms/?ref=lbp
>
> https://viblo.asia/p/bai-toan-tim-kiem-va-cac-thuat-toan-tim-kiem-thong-dung-djeZ1dEGKWz#_i-mo-dau-ve-bai-toan-tim-kiem-0
>
> https://codelearn.io/sharing/5-thuat-toan-tim-kiem-moi-ltv-nen-biet
>
> https://blog.28tech.com.vn/c-ham-qsort

# Các thuật toán tìm kiếm
+ Tìm kiếm tuyến tính(Linear Search) : là một giải thuật tìm kiếm rất cơ bản. Trong kiểu tìm kiếm này, một hoạt động tìm kiếm liên tiếp được diễn ra qua tất cả từng phần tử.
+ Tìm kiếm nhị phân(Binary Search): là một giải thuật tìm kiếm nhanh với độ phức tạp thời gian chạy là Ο(log n). Giải thuật tìm kiếm nhị phân làm việc dựa trên nguyên tắc chia để trị (Divide and Conquer).
> https://wiki.vnoi.info/algo/basic/Binary-Search
+ Tìm kiếm nội suy(Interpolation Search): là biến thể cải tiến của Tìm kiếm nhị phân (Binary Search). Để giải thuật tìm kiếm này làm việc chính xác thì tập dữ liệu phải được sắp xếp.
  
        Thuật toán Linear Search
        Thuật toán Binary Search
        Thuật toán Ternary Search
        Thuật toán Jump Search
        Thuật toán Exponential Search

![image](https://github.com/minchangggg/DSA/assets/125820144/9342ac8e-e07b-4795-9973-23303ebc8a79)























# 1. Linear Search
> https://www.geeksforgeeks.org/linear-search/

![image](https://github.com/minchangggg/DSA/assets/125820144/77c80cab-1ed3-4af5-907e-8527d9b96eaf)

## b. Code
### Ví dụ 1

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

Hoặc 

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
### Ví dụ 2: Tìm vị trí đầu tiên của X trong mảng
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
### Ví dụ 3: Đếm số lần xuất hiện của X trong mảng
        #include <iostream>
        
        using namespace std;
        
        int count(int a[], int n, int x){
            int res = 0;
            for(int i = 0; i < n; i++){
                if(a[i] == x){
                    ++res;
                }
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
# 2. Binary Search
> https://www.geeksforgeeks.org/binary-search/?ref=lbp

![image](https://github.com/minchangggg/DSA/assets/125820144/88fcbfcb-a970-413a-81e1-5861a0edd4af)

Binary Search có lợi thế lớn về độ phức tạp thời gian khi so sánh với Linear Search. Linear Search có độ phức tạp trường hợp xấu nhất là Ο(n) trong khi Binary Search là Ο(log n).
## a. Code
### Dùng vòng lặp
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
### Dùng đệ quy
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
## b. Ví dụ 
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
# 3. Interpolation Search
Tìm kiếm nội suy (Interpolation Search) là biến thể cải tiến của Tìm kiếm nhị phân (Binary Search). Để giải thuật tìm kiếm này làm việc chính xác thì tập dữ liệu phải được sắp xếp.
## b. Code
- Hàm tìm kiếm interpolationSearch được viết như sau: đầu vào là 1 mảng số Int, key đầu ra sẽ là kết quả vị trí key trong mảng nếu có.

        func interpolationSearch(_ a: [Int], key: Int) -> Int? {
            let lowerBound = 0
            var midIndex = -1
            var upperBound = a.count - 1
            
            while lowerBound != upperBound && a[lowerBound] != a[upperBound] {
                midIndex = lowerBound + ((upperBound - lowerBound) / (a[upperBound] - a[lowerBound])) * (key - a[lowerBound])
                
                if a[midIndex] == key {
                    return midIndex
                } else {
                    if a[midIndex] < key {
                        upperBound = midIndex + 1
                    } else if a[midIndex] > key {
                        upperBound = midIndex - 1
                    }
                }
            }   
            return nil
        }
