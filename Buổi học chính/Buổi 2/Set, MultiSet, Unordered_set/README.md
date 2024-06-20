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

# [STL]. Multiset Trong C++
Multiset trong C++ là một container tương tự như set nhưng có thể lưu các giá trị trùng nhau.
<img width="703" alt="image" src="https://github.com/minchangggg/DSA/assets/125820144/efb09f9f-410b-4fae-afe4-3b6857357192">

## 1. Multiset trong C++
- Multiset trong C++ cũng được cài đặt bằng cấu trúc dữ liệu cây nhị phân tìm kiếm (binary search tree) tương tự như set, đặc điểm khác biệt nhất so với set đó là nó có thể lưu trữ các giá trị trùng nhau.
- Các tính chất của multiset : 
    + Các phần tử trong multiset có thứ tự mặc định theo thứ tự tăng dần
    + Các phần tử trong multiset có thể trùng nhau
    + Các phần tử trong multiset không thể thay đổi, chỉ có thể xóa hoặc thêm vào
    + Multiset không hỗ trợ truy cập phần tử thông qua chỉ số 
- Ví dụ : 

        #include <iostream>
        #include <algorithm>
        #include <set>
        using namespace std;
        
        int main(){
            multiset<int> ms;
            ms.insert(3);
            ms.insert(1);
            ms.insert(3);
            ms.insert(2);
            ms.insert(2);
            ms.insert(3);
            ms.insert(4);
            cout << "So phan tu trong multiset : " << ms.size() << endl;
            cout << "Cac phan tu trong multiset :\n";
            for(int x : ms) cout << x << ' ';
        }
  
> Output : 
> 
> So phan tu trong multiset : 7
>
> Cac phan tu trong multiset :
>
> 1 2 2 3 3 3 4

## 2. Hàm find(), count(), erase() trong multiset
- Các hàm của multiset tương tự như set tuy nhiên có sự khác nhau về 3 hàm là find(), count() và erase(). 
### a. Hàm find()
- Hàm này sẽ trả về iterator tới vị trí đầu tiên của phần tử trong multiset nếu giá trị tìm kiếm xuất hiện, ngược lại sẽ trả về iterator end()
  
![image](https://github.com/minchangggg/DSA/assets/125820144/4ae51397-429e-422f-9067-5488191a630b)

- Ví dụ trong mã nguồn dưới đây bạn sẽ thấy hàm find() trả về vị trí đầu tiên của số 3 trong multiset.

        #include <iostream>
        #include <algorithm>
        #include <set>
        
        using namespace std;
        
        int main(){
            multiset<int> ms = {1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4};
            multiset<int>::iterator it = ms.find(3);
            if(it != ms.end()){
                cout << "3 xuat hien trong multiset\n";
                cout << "Vi tri dau tien cua 3 trong multiset : " << distance(ms.begin(), it) << endl;
            }
            else{
                cout << "3 khong xuat hien trong multiset\n";
            }
        }
  
> Output : 
> 
> 3 xuat hien trong multiset
>
> Vi tri dau tien cua 3 trong multiset : 5

### b. Hàm count()
- Hàm count() trong set chỉ trả về giá trị là 0 hoặc 1 nhưng do multiset có thể lưu giá trị trùng nhau nên hàm count() trong multiset có thể trả về 0 hoặc 1 số khác 0, tương ứng số lần xuất hiện của giá trị đó trong multiset.

![image](https://github.com/minchangggg/DSA/assets/125820144/a887b416-168d-48c1-95e8-9213b604ae25)

- Ví dụ 2: 

        #include <iostream>
        #include <algorithm>
        #include <set>
        using namespace std;
        
        int main(){
            multiset<int> ms = {1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4};
            cout << "So lan xuat hien cua 3 : " << ms.count(3) << endl;
            cout << "So lan xuat hien cua 28 : " << ms.count(28) << endl;
            cout << "So lan xuat hien cua 1 : " << ms.count(1) << endl;
        }

> Output : 
> 
> So lan xuat hien cua 3 : 5
>
> So lan xuat hien cua 28 : 0
>
> So lan xuat hien cua 1 : 3

### c. Hàm erase() : 
- Khi sử dụng hàm erase() bạn cần lưu ý nếu bạn xóa thông qua giá trị thì nó sẽ xóa hết mọi phần tử có cùng giá trị đó, ngược lại nếu bạn chỉ muốn xóa 1 phần tử có giá trị đó trong multiset thì bạn cần xóa thông qua iterator.
- Tương tự như trong set bạn cần đảm bảo rằng giá trị bạn xóa tồn tại trong multiset
- Ví dụ 3 : Xóa phần tử thông qua giá trị
  
![image](https://github.com/minchangggg/DSA/assets/125820144/d126cf92-5131-4958-8029-a1ba6eaf231c)

        #include <iostream>
        #include <algorithm>
        #include <set>
        
        using namespace std;
        
        int main(){
            multiset<int> ms = {1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4};
            cout << "Multiset ban dau : \n";
            for(int x : ms){
                cout << x << " ";
            }
            ms.erase(3);
            cout << "\nMultiset sau khi xoa 3 : \n";
            for(int x : ms){
                cout << x << " ";
            }
        }
  
> Output : 
>
> Multiset ban dau : 
>
> 1 1 1 2 2 3 3 3 3 3 4 
>
> Multiset sau khi xoa 3 : 
>
> 1 1 1 2 2 4

- Ví dụ 4 : Xóa thông qua iterator

![image](https://github.com/minchangggg/DSA/assets/125820144/d0f363ff-0d66-4696-af84-aaec317923de)

        #include <iostream>
        #include <algorithm>
        #include <set>
        
        using namespace std;
        
        int main(){
            multiset<int> ms = {1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4};
            cout << "Multiset ban dau : \n";
            for(int x : ms){
                cout << x << " ";
            }
            multiset<int>::iterator it = ms.find(3);
            ms.erase(it);
            cout << "\nMultiset sau khi xoa 3 : \n";
            for(int x : ms){
                cout << x << " ";
            }
        }
  
> Output : 
> 
> Multiset ban dau : 
>
> 1 1 1 2 2 3 3 3 3 3 4 
>
> Multiset sau khi xoa 3 : 
>
> 1 1 1 2 2 3 3 3 3 4

# [STL]. Unordered_set Trong C++
Unordered_set trong C++ là một container tương tự set nhưng không có thứ tự tăng dần như set, bài học này mình sẽ giới thiệu bạn một cấu trúc dữ liệu được xây dựng sẵn rất tối ưu cho việc truy xuất phần tử thông qua giá trị.
## 1. Unordered_set trong C++ 
- Unordered_set là một container trong thư viện STL và có thể sử dụng trong các chuẩn C++ 11 tới các phiên bản mới hơn. 
- Thư viện chứa unordered_set là "unordered_set", bạn cần thêm vào chương trình để có thể sử dụng.
- Unordered_set được cài đặt bởi cấu trúc dữ liệu bảng băm - hash table vì thế rất tối ưu trong việc tìm kiếm giá trị của phần tử.
- Sự khác biệt lớn nhất giữa Unordered_set và set chính là thứ tự các phần tử trong container.
- Các tính chất của unordered_set : 
    + Các phần tử trong unordered_set đôi một khác nhau
    + unordered_set không duy trì bất kỳ thứ tự nào giữa các phần tử mà nó chứa
- Ngoài sự khác biệt về thứ tự, unordered_set khác với set và multiset ở độ phức tạp của các hàm tìm kiếm, chén, xóa..
    + Các hàm find(), erase(), insert() của set và multiset có độ phức tạp là O(logN)
    + Các hàm find(), erase(), insert() của unordered_set có độ phức tạp trong trường hợp trung bình là O(1) và trong trường hợp tệ nhất là O(N)
- Ví dụ: 

        #include <iostream>
        #include <unordered_set>
        
        using namespace std;
        
        int main(){
            unordered_set<int> se = {1, 3, 1, 1, 2, 3, 1, 4, 1};
            cout << "So phan tu trong set : " << se.size() << endl;
            cout << "Cac phan tu trong set :\n";
            for(int x : se){
                cout << x << " ";
            }
            cout << endl;
            if(se.find(3) == se.end()){
                cout << "NOT FOUND\n";
            }
            else{
                cout << "FOUND\n";
            }
        }
  
> Output : 
> 
> So phan tu trong set : 4
>
> Cac phan tu trong set :
>
> 4 2 3 1 
>
> FOUND
