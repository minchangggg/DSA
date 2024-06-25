> https://blog.28tech.com.vn/c-ham-binarysearch-lowerbound-upperbound-trong-c

![image](https://github.com/minchangggg/DSA/assets/125820144/7a4d91b1-24b8-4e96-a8a7-b6fd32409a2d)

# Hàm binary_search, lower_bound, upper_bound trong C++
Trong C++ cũng cung cấp sẵn thuật toán tìm kiếm nhị phân cũng như biến thể của nó là lower_bound & upper_bound. Đây là hai hàm mà nếu biết sử dụng và ứng dụng nó bạn sẽ giải quyết được rất nhiều bài toán về tìm kiếm một cách tối ưu. 

## 1.Tìm kiếm tuyến tính (Linear Search):
![image](https://github.com/minchangggg/DSA/assets/125820144/4a6aa703-c9a7-4378-9e38-4d519bcedb95)

## 2.Tìm kiếm nhị phân (Binary Search):
![image](https://github.com/minchangggg/DSA/assets/125820144/ec9181d1-557a-48e4-a84e-b043e56f4734)

- Hàm binary_search() được cài đặt bằng thuật toán tìm kiếm nhị phân, bạn có thể áp dụng hàm này trên mảng, vector, string đã được sắp xếp theo thứ tự tăng dần. Để sử dụng hàm này bạn cần thêm thư viện "algorithm" vào chương trình của mình.
- Giá trị trả về : Hàm trả về true nếu giá trị tìm kiếm xuất hiện trong mảng, ngược lại trả về false.
- Bạn có thể sử dụng hàm này luôn nếu đã code thành thạo thuật toán tìm kiếm nhị phân ở bài trước. 
- Độ phức tạp : O(logN) 
- Cú pháp : 

        //Cú pháp áp dụng với mảng a[] gồm n phần tử và giá trị tìm kiếm x
        binary_search(a, a + n, x)
        
        //Cú pháp áp dụng với vector, string và giá trị tìm kiếm x
        binary_search(v.begin(), v.end(), x)
        binary_search(s.begin(), s.end(), x)

- Mã nguồn : 

        #include <iostream>
        #include <algorithm>
        using namespace std;
        
        int main(){
            int a[10] = {1, 2, 3, 5, 5, 6, 8, 9, 14, 21};
            int n = 10, X = 5;
            if(binary_search(a, a + n, X)){
                cout << "FOUND\n";
            }
            else{
                cout << "NOT FOUND\n";
            }
            vector<int> v = {1, 2, 3, 4, 5, 6, 6, 6, 8, 9};
            if(binary_search(v.begin(), v.end(), X)){
                cout << "FOUND\n";
            }
            else{
                cout << "NOT FOUND\n";
            }
        }
  
> Output : 

        FOUND
        FOUND

- Ngoài ra bạn cũng có thể tìm kiếm trên đoạn chỉ số [L, R] của mảng hoặc vector
- Cú pháp : 

        //Cú pháp áp dụng với mảng a[] 
        binary_search(a + L, a + R + 1, x)
        
        //Cú pháp áp dụng với vector
        binary_search(v.begin() + L, v.begin() + R + 1, x)

- Mã nguồn : 

        #include <iostream>
        #include <algorithm>
        using namespace std;
        
        int main(){
            int a[10] = {1, 2, 3, 5, 5, 6, 8, 9, 14, 21};
            int n = 10, X = 5;
            if(binary_search(a + 5, a + 8, X)){
                cout << "FOUND\n";
            }
            else{
                cout << "NOT FOUND\n";
            }
            vector<int> v = {1, 2, 3, 4, 5, 6, 6, 6, 8, 9};
            if(binary_search(v.begin() + 2, v.begin() + 7, X)){
                cout << "FOUND\n";
            }
            else{
                cout << "NOT FOUND\n";
            }
        }

> Output : 

        NOT FOUND
        FOUND

## 3. Vị trí đầu tiên trong mảng tăng dần:
![image](https://github.com/minchangggg/DSA/assets/125820144/83206d9d-e847-4681-972b-110c5777d51d)
## 4. Vị trí cuối cùng trong mảng tăng dần:
![image](https://github.com/minchangggg/DSA/assets/125820144/043015c5-7962-4043-a71d-10810a71a350)
## 5. Vị trí đầu tiên lớn hơn hoặc bằng X trong mảng tăng dần:
![image](https://github.com/minchangggg/DSA/assets/125820144/6ffb5abc-ae99-4284-8db6-1f6e6e25ee0e)
## 6. Vị trí cuối cùng nhỏ hơn hoặc bằng X trong mảng tăng dần:
![image](https://github.com/minchangggg/DSA/assets/125820144/6c30a815-60d8-4a94-a96a-8cf2465935cc)
## 7. Hàm lower_bound
![image](https://github.com/minchangggg/DSA/assets/125820144/d06ba91f-b425-492f-b5e1-d9d320bd4e8e)

- Hàm lower_bound() được dùng để tìm giá trị nhỏ nhất lớn hơn hoặc bằng giá trị X mà bạn tìm kiếm trong mảng hoặc vector tăng dần, ngoài ra nó còn có thể áp dụng với set & map. 
- Hàm này tương đối khó dùng vì nó cần bạn thành thạo kiến thức về con trỏ và iterator. 
- Giá trị trả về : 

Đối với mảng thì hàm này trả về con trỏ tới giá trị nhỏ nhất ≥ giá trị tìm kiếm, nếu không tìm thì hàm trả về con trỏ tới a + n
Đối với vector thì hàm trả về iterator tới giá trị nhỏ nhất ≥ giá trị tìm kiếm, nếu không tìm thì hàm trả về iterator end() 
Độ phức tạp : O(logN)

- Cú pháp : 
        //Cú pháp áp dụng trên mảng a[] gồm n phần tử và giá trị tìm kiếm X
        lower_bound(a, a + n, X)
        
        //Cú pháp áp dụng trên vector và giá trị tìm kiếm X
        lower_bound(v.begin(), v.end(), X)

![image](https://github.com/minchangggg/DSA/assets/125820144/b1034bd8-0455-41c0-b6e5-acf72b98ab47)

![image](https://github.com/minchangggg/DSA/assets/125820144/1fec4368-98b6-4e6f-a0d5-7122eb23b8b2)

### Mã nguồn 1 : Lower_bound áp dụng trên mảng đã tăng dần

        #include <iostream>
        #include <algorithm>
        using namespace std;
        
        int main(){
            int a[10] = {1, 2, 3, 5, 5, 5, 8, 9, 14, 21};
            int n = 10, X = 5, Y = 22;
            int *it1 = lower_bound(a, a + n, X);
            if(it1 == a + n){
                cout << "Khong tim duoc gia tri >= 5" << endl; 
            }
            else{
                cout << "Gia tri nho nhat >= 5 : " << *it1 << endl;
                cout << "Chi so cua gia tri tim duoc : " << it1 - a << endl;
            }
            int *it2 = lower_bound(a, a + n, Y);
            if(it2 == a + n){
                cout << "Khong tim duoc gia tri >= 22" << endl; 
            }
            else{
                cout << "Gia tri nho nhat >= 22 : " << *it2 << endl;
                cout << "Chi so cua gia tri tim duoc : " << it2 - a << endl;
            }
            
        }

> Output : 

        Gia tri nho nhat >= 5 : 5
        Chi so cua gia tri tim duoc : 3
        Khong tim duoc gia tri >= 22

### Mã nguồn 2 : Lower_bound áp dụng trên vector đã tăng dần

        #include <iostream>
        #include <algorithm>
        using namespace std;
        
        int main(){
            vector<int> v = {1, 2, 3, 5, 5, 5, 8, 9, 14, 21};
            int X = 5, Y = 22;
            vector<int>::iterator it1 = lower_bound(v.begin(), v.end(), X);
            if(it1 == v.end()){
                cout << "Khong tim duoc gia tri >= 5" << endl; 
            }
            else{
                cout << "Gia tri nho nhat >= 5 : " << *it1 << endl;
                cout << "Chi so cua gia tri tim duoc : " << it1 - v.begin() << endl;
            }
            vector<int>::iterator it2 = lower_bound(v.begin(), v.end(), Y);
            if(it2 == v.end()){
                cout << "Khong tim duoc gia tri >= 22" << endl; 
            }
            else{
                cout << "Gia tri nho nhat >= 22 : " << *it2 << endl;
                cout << "Chi so cua gia tri tim duoc : " << it2 - v.begin() << endl;
            }
        }

> Output : 

        Gia tri nho nhat >= 5 : 5
        Chi so cua gia tri tim duoc : 3
        Khong tim duoc gia tri >= 22

- Chú ý : Bạn cũng có thể áp dụng hàm lower_bound trên đoạn chỉ số [L, R], cú pháp tương tự như hàm binary_search

## 3. Hàm upper_bound
![image](https://github.com/minchangggg/DSA/assets/125820144/2b50b49f-2af5-41fc-b6a3-fbc2c36ce4f4)

- Hàm upper_bound() cách dùng, cú pháp, giá trị trả về, độ phức tạp đều giống hàm upper_bound chỉ khác duy nhất là hàm này tìm giá trị nhỏ nhất > giá trị X mà bạn tìm kiếm trong mảng tăng dần. 
- Cú pháp : 

        //Cú pháp áp dụng trên mảng a[] gồm n phần tử và giá trị tìm kiếm X
        upper_bound(a, a + n, X)
        
        //Cú pháp áp dụng trên vector và giá trị tìm kiếm X
        upper_bound(v.begin(), v.end(), X)

![image](https://github.com/minchangggg/DSA/assets/125820144/7c3538bc-fe9b-4d74-b716-b7a7add16328)

![image](https://github.com/minchangggg/DSA/assets/125820144/e04ca3b4-5508-4f11-8b34-5f4e37e0d124)

### Mã nguồn 1 : upper_bound áp dụng trên mảng đã tăng dần

        #include <iostream>
        #include <algorithm>
        using namespace std;
        
        int main(){
            int a[10] = {1, 2, 3, 5, 5, 5, 8, 9, 14, 21};
            int n = 10, X = 5, Y = 22;
            int *it1 = upper_bound(a, a + n, X);
            if(it1 == a + n){
                cout << "Khong tim duoc gia tri > 5" << endl; 
            }
            else{
                cout << "Gia tri nho nhat > 5 : " << *it1 << endl;
                cout << "Chi so cua gia tri tim duoc : " << it1 - a << endl;
            }
            int *it2 = upper_bound(a, a + n, Y);
            if(it2 == a + n){
                cout << "Khong tim duoc gia tri > 22" << endl; 
            }
            else{
                cout << "Gia tri nho nhat > 22 : " << *it2 << endl;
                cout << "Chi so cua gia tri tim duoc : " << it2 - a << endl;
            }
            
        }

> Output : 

        Gia tri nho nhat > 5 : 8
        Chi so cua gia tri tim duoc : 6
        Khong tim duoc gia tri > 22
        
### Mã nguồn 2 : upper_bound áp dụng trên vector đã tăng dần

        #include <iostream>
        #include <algorithm>
        using namespace std;
        
        int main(){
            vector<int> v = {1, 2, 3, 5, 5, 5, 8, 9, 14, 21};
            int X = 5, Y = 22;
            vector<int>::iterator it1 = upper_bound(v.begin(), v.end(), X);
            if(it1 == v.end()){
                cout << "Khong tim duoc gia tri > 5" << endl; 
            }
            else{
                cout << "Gia tri nho nhat > 5 : " << *it1 << endl;
                cout << "Chi so cua gia tri tim duoc : " << it1 - v.begin() << endl;
            }
            vector<int>::iterator it2 = lower_bound(v.begin(), v.end(), Y);
            if(it2 == v.end()){
                cout << "Khong tim duoc gia tri > 22" << endl; 
            }
            else{
                cout << "Gia tri nho nhat > 22 : " << *it2 << endl;
                cout << "Chi so cua gia tri tim duoc : " << it2 - v.begin() << endl;
            }
        }

> Output : 

        Gia tri nho nhat > 5 : 8
        Chi so cua gia tri tim duoc : 6
        Khong tim duoc gia tri > 22
