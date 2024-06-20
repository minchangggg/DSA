# [STL]. Set Trong C++
![image](https://github.com/minchangggg/DSA/assets/125820144/68e8cc1c-50eb-4d38-b637-bf08eecd89c7)

## 1. Tính chất của set trong C++
- Set là một container được xây dựng sẵn, bạn cũng có thể gọi nó là cấu trúc dữ liệu hay thư viện cũng được. 
- Đây là một cấu trúc dữ liệu đã được xây dựng sẵn, để sử dụng bạn cần thêm thư viện set vào chương trình của mình.
- Set được cài đặt bởi cấu trúc dữ liệu cây nhị phân tìm kiếm (binary search tree).
- Sau đây là những tính chất quan trọng của set mà bạn cần ghi nhớ : 
    + Các phần tử trong set có giá trị khác nhau, không có 2 phần tử có cùng giá trị
    + Các phần tử trong set được tự động sắp xếp theo thứ tự tăng dần
    + Tìm kiếm phần tử trong set chỉ mất độ phức tạp O(logN)
    + Set không thể truy cập phần tử thông qua chỉ số như mảng hay vector, string.
    + Set đặc biệt phù hợp với những bài toán liên quan tới việc loại bỏ giá trị trùng nhau hoặc tìm kiếm nhanh.
- Cú pháp khai báo set trong C++ :
  
        #include <set>
        
          ...
      
        set<data_type> set_name;

- Ứng dụng
    
![image](https://github.com/minchangggg/DSA/assets/125820144/839a6ae8-6ca4-4061-bdfb-3cfb5f997a12)
  
## 2. Một số hàm cơ bản của set
- Hàm Chức năng

`size()`	Số lượng phần tử trong set

`insert()`	Thêm phần tử vào trong set

`empty()`	Kiểm tra set rỗng, nếu đúng trả về true, ngược lại trả về false

`clear()`	Xóa toàn bộ phần tử trong set

(Để thêm 1 phần tử vào trong set bạn sử dụng hàm insert(), hàm này có độ phức tạp là O(logN) và lưu ý rằng nếu trong set của bạn đã tồn tại giá trị nào đó thì bạn không thể thêm nó vào nữa vì set không thể lưu giá trị trùng nhau)

![image](https://github.com/minchangggg/DSA/assets/125820144/a26d0d52-a9c9-4612-b673-ba6e017b5537)

![image](https://github.com/minchangggg/DSA/assets/125820144/8c66f109-af3a-4817-a866-4da9637eed74)

![image](https://github.com/minchangggg/DSA/assets/125820144/027d58cc-0ca6-4641-9223-a1d2d8dc05df)

## 3. Duyệt set
- Để duyệt set bạn có thể dụng range-based for loop hoặc duyệt thông qua iterator, tương tự như vector hay các container khác trong thư viện STL thì set cũng có iterator

<img width="679" alt="image" src="https://github.com/minchangggg/DSA/assets/125820144/ef7bf700-556b-4eb5-8720-1e8c8cef43ac">

Chú ý : Iterator trong set chỉ hỗ trợ toán tử ++ hoặc --  chứ không hỗ trợ toán tử += và -= như iterator của vector

## Các Hàm Thông Dụng Của Set Trong C++

        Hàm find()
        Hàm count()
        Hàm erase()
        Hàm lower_bound()
        Hàm upper_bound()

### a. Hàm find()
![image](https://github.com/minchangggg/DSA/assets/125820144/08a480a8-6d5b-4e21-8cd8-561c9e37aa19)
 
        #include <iostream>
        #include <algorithm>
        #include <set>
        
        using namespace std;
        
        int main(){
            set<int> se = {3, 1, 2, 4, 5, 6}; // {1, 2, 3, 4, 5, 6}
            
            if(se.find(3) != se.end()) cout << "3 xuat hien trong set\n";
            else cout << "3 khong xuat hien trong set\n";
            
            if(se.find(28) != se.end()) cout << "28 xuat hien trong set\n";
            else cout << "28 khong xuat hien trong set\n";
        }
        
> Output : 
> 
> 3 xuat hien trong set
>
> 28 khong xuat hien trong set

### b. Hàm count()
![image](https://github.com/minchangggg/DSA/assets/125820144/1619fabf-dcc8-4dc5-973e-b5c81bf1d1a8)

        #include <iostream>
        #include <algorithm>
        #include <set>
        using namespace std;
        
        int main(){
            set<int> se = {3, 1, 2, 4, 5, 6}; // {1, 2, 3, 4, 5, 6}
            
            if(se.count(3) != 0) cout << "3 xuat hien trong set\n";
            else cout << "3 khong xuat hien trong set\n";
            
            if(se.count(28) != 0) cout << "28 xuat hien trong set\n";
            else cout << "28 khong xuat hien trong set\n";
        }
        
> Output : 
>
> 3 xuat hien trong set
>
> 28 khong xuat hien trong set

### c. Hàm erase()
![image](https://github.com/minchangggg/DSA/assets/125820144/75818922-7ac5-4151-87d9-05572d0fd829)

        #include <iostream>
        #include <algorithm>
        #include <set>
        using namespace std;
        
        int main(){
            set<int> se = {3, 1, 2, 4, 5, 6}; // {1, 2, 3, 4, 5, 6}

            //xoa thong qua gia tri
            se.erase(3); 
            cout << "Set sau khi xoa 3 :\n";
            for(int x : se) cout << x << " ";
            
            //xoa thong qua iterator
            set<int>::iterator it = se.find(5); // auto it = se.find(5);
            if(it != se.end()) se.erase(it);
            cout << "\nSet sau khi xoa 5 : \n";
            for(int x : se) cout << x << " ";
        }

> Output : 
>
> Set sau khi xoa 3 :
>
> 1 2 4 5 6 
>
> Set sau khi xoa 5 : 
>
> 1 2 4 6 

### d. Hàm lower_bound()
- Hàm lower_bound() trả về iterator tới phần tử có **giá trị nhỏ nhất lớn hơn hoặc bằng giá trị cần tìm kiếm**.
- Trong trường hợp tất cả các phần tử trong set không có phần tử nào lớn hơn hoặc bằng giá trị mà bạn tìm kiếm thì hàm này **trả về iterator end()** của set.
- Độ phức tạp : O(logN)
- Ví dụ: 

        #include <iostream>
        #include <algorithm>
        #include <set>
        using namespace std;
        
        int main(){
            set<int> se = {1, 2, 3, 5, 7, 9, 10};
            set<int>::iterator it1 = se.lower_bound(6); // auto it1 = se.lower_bound(6);
            if(it1 == se.end()) cout << "Tat ca phan tu trong set < 6\n";
            else cout << *it1 << " la gia tri nho nhat >= 6\n";

            set<int>::iterator it2 = se.lower_bound(28);
            if(it2 == se.end()) cout << "Tat ca phan tu trong set < 28\n";
            else cout << *it2 << " la gia tri nho nhat >= 28\n";
        }

> Output : 
> 
> 7 la gia tri nho nhat >= 6
>
> Tat ca phan tu trong set < 28

### e. Hàm upper_bound()
- Tương tự như lower_bound(), hàm upper_bound() trả về iterator tới phần tử có giá trị nhỏ nhất lớn hơn giá trị cần tìm kiếm.
- Trong trường hợp tất cả các phần tử trong set không có phần tử nào lớn hơn giá trị mà bạn tìm kiếm thì hàm này trả về iterator end() của set.
- Độ phức tạp : O(logN)
- Ví dụ: 

        #include <iostream>
        #include <algorithm>
        #include <set>
        
        using namespace std;
        
        int main(){
            set<int> se = {1, 2, 3, 5, 7, 9, 10};
            set<int>::iterator it1 = se.upper_bound(5); // auto it1 = se.upper_bound(5);
            if(it1 == se.end()) cout << "Tat ca phan tu trong set <= 5\n";
            else cout << *it1 << " la gia tri nho nhat > 5\n";

            set<int>::iterator it2 = se.upper_bound(10);
            if(it2 == se.end()) cout << "Tat ca phan tu trong set <= 10\n";
            else cout << *it2 << " la gia tri nho nhat > 10\n";
        }
        
> Output : 
> 
> 7 la gia tri nho nhat > 5
>
> Tat ca phan tu trong set <= 10
