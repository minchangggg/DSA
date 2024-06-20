# [STL]. Set Trong C++
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
      
## 2. Một số hàm cơ bản của set
- Hàm	Chức năng

`size()`	Số lượng phần tử trong set

`insert()`	Thêm phần tử vào trong set

`empty()`	Kiểm tra set rỗng, nếu đúng trả về true, ngược lại trả về false

`clear()`	Xóa toàn bộ phần tử trong set


(Để thêm 1 phần tử vào trong set bạn sử dụng hàm insert(), hàm này có độ phức tạp là O(logN) và lưu ý rằng nếu trong set của bạn đã tồn tại giá trị nào đó thì bạn không thể thêm nó vào nữa vì set không thể lưu giá trị trùng nhau)

- Ví dụ 1: 

        #include <iostream>
        #include <algorithm>
        #include <set>
        using namespace std;
        
        int main(){
            set<int> se; // {}
            se.insert(3); // {3}
            se.insert(1); // {1, 3}
            se.insert(1); // {1, 3}
            se.insert(2); // {1, 2, 3}
            se.insert(3); // {1, 2, 3}
            se.insert(2); // {1, 2, 3}
            se.insert(4); // {1, 2, 3, 4}
            cout << "So luong phan tu trong set : \n";
            cout << se.size() << endl;
        }
  
> Output : 
>
> So luong phan tu trong set : 
>
> 4

Nhận xét : Các phần tử trong set không trùng nhau và được sắp xếp theo thứ tự tăng dần

- Ví dụ 2 : 

            #include <iostream>
            #include <algorithm>
            #include <set>
            
            using namespace std;
            
            int main(){
                set<string> se; // {}
                se.insert("tech28"); // {tech28}
                se.insert("c++"); // {c++, tech28}
                se.insert("c++"); // {c++, tech28}
                se.insert("tech28"); // {c++, tech28}
                se.insert("stl"); // {c++, stl, tech28}
                se.insert("stl"); // {c++, stl, tech28}
                se.insert("stl"); // {c++, stl, tech28}
                cout << "So luong phan tu trong set : \n";
                cout << se.size() << endl;
            }

> Output : 
> 
> So luong phan tu trong set : 
>
> 3

## 3. Duyệt set
- Để duyệt set bạn có thể dụng range-based for loop hoặc duyệt thông qua iterator, tương tự như vector hay các container khác trong thư viện STL thì set cũng có iterator
- Ví dụ 1: Duyệt set 

            #include <iostream>
            #include <algorithm>
            #include <set>
            
            using namespace std;
            
            int main(){
                set<int> se; // {}
                se.insert(3); // {3}
                se.insert(1); // {1, 3}
                se.insert(1); // {1, 3}
                se.insert(2); // {1, 2, 3}
                se.insert(3); // {1, 2, 3}
                se.insert(2); // {1, 2, 3}
                se.insert(4); // {1, 2, 3, 4}
                cout << "Duyet set bang range-based for loop : \n";
                for(int x : se){
                    cout << x << ' ';
                }
                cout << "\nDuyet set bang iterator : \n";
                for(set<int>::iterator it = se.begin(); it != se.end(); ++it){
                    cout << *it << " ";
                }
            }

> Output : 
> 
> Duyet set bang range-based for loop : 
>
> 1 2 3 4 
>
> Duyet set bang iterator : 
>
> 1 2 3 4

Truy cập vào các giá trị đặc biệt (nhỏ nhất, lớn nhất) trong set thông qua iterator : 

begin() : Iterator trỏ tới phần tử đầu tiên trong set
rbegin() : Iterator ngược trỏ tới phần tử cuối cùng trong set 
Ví dụ 2 : 

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    set<int> se; // {}
    se.insert(3); // {3}
    se.insert(1); // {1, 3}
    se.insert(1); // {1, 3}
    se.insert(2); // {1, 2, 3}
    se.insert(3); // {1, 2, 3}
    se.insert(2); // {1, 2, 3}
    se.insert(4); // {1, 2, 3, 4}
    cout << "Phan tu nho nhat : " << *se.begin() << endl;
    cout << "Phan tu lon nhat : " << *se.rbegin() << endl;
}
Output : 

Phan tu nho nhat : 1
Phan tu lon nhat : 4
Chú ý : Iterator trong set chỉ hỗ trợ toán tử ++ hoặc --  chứ không hỗ trợ toán tử += và -= như iterator của vector

# [STL]. Các Hàm Thông Dụng Của Set Trong C++
Sau khi đã làm quen và có thể sử dụng set ở bài học trước thì mình sẽ tiếp tục hướng dẫn các bạn các hàm phổ biến trong set thông qua các ví dụ trực quan. Thông qua bài học này thì việc sử dụng set sẽ trở nên dễ dàng hơn bao giờ hết.

NỘI DUNG : 

Hàm find()
Hàm count()
Hàm erase()
Hàm lower_bound()
Hàm upper_bound()

1. Hàm find()

Hàm find() có chức năng tìm kiếm một phần tử trong set, hàm này rất hiệu quả và dễ dùng.

Hàm này sẽ trả về iterator tới phần tử nếu tìm thấy, ngược lại sẽ trả về iterator end() của set

Độ phức tạp : O(logN)

Khi gặp bài toán cần tìm kiếm nhanh bạn có thể nghĩ tới set như một giải pháp tối ưu.

Mã nguồn : 

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    set<int> se = {3, 1, 2, 4, 5, 6}; // {1, 2, 3, 4, 5, 6}
    if(se.find(3) != se.end()){
        cout << "3 xuat hien trong set\n";
    }
    else{
        cout << "3 khong xuat hien trong set\n";
    }
    if(se.find(28) != se.end()){
        cout << "28 xuat hien trong set\n";
    }
    else{
        cout << "28 khong xuat hien trong set\n";
    }
}
Output : 

3 xuat hien trong set
28 khong xuat hien trong set
2. Hàm count()

Hàm count() trả về số lần xuất hiện của phần tử trong set, do đó hàm này sẽ có giá trị trả về là 0 hoặc 1 tùy theo giá trị đếm có xuất hiện trong set hay không.

Bạn có thể sử dụng hàm count() thay cho hàm find() vì độ phức tạp của chúng là như nhau.

Độ phức tạp : O(logN)

Mã nguồn : 

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    set<int> se = {3, 1, 2, 4, 5, 6}; // {1, 2, 3, 4, 5, 6}
    if(se.count(3) != 0){
        cout << "3 xuat hien trong set\n";
    }
    else{
        cout << "3 khong xuat hien trong set\n";
    }
    if(se.count(28) != 0){
        cout << "28 xuat hien trong set\n";
    }
    else{
        cout << "28 khong xuat hien trong set\n";
    }
}
Output : 

3 xuat hien trong set
28 khong xuat hien trong set
3. Hàm erase()

Hàm erase() giúp bạn có thể xóa một giá trị ra khỏi set, ngoài ra bạn cũng có thể xóa thông qua iterator trỏ tới giá trị đó trong set.

Lưu ý nếu bạn cố xóa 1 phần tử không nằm trong set sẽ gây lỗi, nên trước khi xóa hãy đảm bảo giá trị bạn xóa có mặt trong set

Độ phức tạp : O(logN)

Mã nguồn : 

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    set<int> se = {3, 1, 2, 4, 5, 6}; // {1, 2, 3, 4, 5, 6}
    //xoa thong qua gia tri
    se.erase(3);
    cout << "Set sau khi xoa 3 :\n";
    for(int x : se){
        cout << x << " ";
    }
    //xoa thong qua iterator
    set<int>::iterator it = se.find(5);
    if(it != se.end()){
        se.erase(it);
    }
    cout << "\nSet sau khi xoa 5 : \n";
    for(int x : se){
        cout << x << " ";
    }
}
Output : 

Set sau khi xoa 3 :
1 2 4 5 6 
Set sau khi xoa 5 : 
1 2 4 6 
4. Hàm lower_bound()

Hàm lower_bound() trả về iterator tới phần tử có giá trị nhỏ nhất lớn hơn hoặc bằng giá trị cần tìm kiếm.

Trong trường hợp tất cả các phần tử trong set không có phần tử nào lớn hơn hoặc bằng giá trị mà bạn tìm kiếm thì hàm này trả về iterator end() của set.

Độ phức tạp : O(logN)

Mã nguồn : 

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    set<int> se = {1, 2, 3, 5, 7, 9, 10};
    set<int>::iterator it1 = se.lower_bound(6);
    if(it1 == se.end()){
        cout << "Tat ca phan tu trong set < 6\n";
    }
    else{
        cout << *it1 << " la gia tri nho nhat >= 6\n";
    }
    set<int>::iterator it2 = se.lower_bound(28);
    if(it2 == se.end()){
        cout << "Tat ca phan tu trong set < 28\n";
    }
    else{
        cout << *it2 << " la gia tri nho nhat >= 28\n";
    }
}
Output : 

7 la gia tri nho nhat >= 6
Tat ca phan tu trong set < 28
5. Hàm upper_bound()

Tương tự như lower_bound(), hàm upper_bound() trả về iterator tới phần tử có giá trị nhỏ nhất lớn hơn giá trị cần tìm kiếm.

Trong trường hợp tất cả các phần tử trong set không có phần tử nào lớn hơn giá trị mà bạn tìm kiếm thì hàm này trả về iterator end() của set.

Độ phức tạp : O(logN)

Mã nguồn : 

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    set<int> se = {1, 2, 3, 5, 7, 9, 10};
    set<int>::iterator it1 = se.upper_bound(5);
    if(it1 == se.end()){
        cout << "Tat ca phan tu trong set <= 5\n";
    }
    else{
        cout << *it1 << " la gia tri nho nhat > 5\n";
    }
    set<int>::iterator it2 = se.upper_bound(10);
    if(it2 == se.end()){
        cout << "Tat ca phan tu trong set <= 10\n";
    }
    else{
        cout << *it2 << " la gia tri nho nhat > 10\n";
    }
}
Output : 

7 la gia tri nho nhat > 5
Tat ca phan tu trong set <= 10
