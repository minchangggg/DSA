# [STL]. Map Trong C++
![image](https://github.com/minchangggg/DSA/assets/125820144/e6dd6596-4512-4efc-b1c2-f7fbb7690b17)

Map là một container lưu trữ dữ liệu tương tự như một từ điển, mỗi phần tử trong map là một cặp key - value. Thành thạo map trong thư viện STL của C++ giúp bạn code tối ưu hơn, xử lý được bài toán một cách gọn gàng và dễ dàng hơn. 
## 1. Tính chất của map
- Map là một cấu trúc dữ liệu được xây dựng sẵn trong C++, nó lưu trữ dữ liệu theo cặp khóa (key) và giá trị (value). Mỗi phần tử trong map là một ánh xạ từ key sang value. Ví dụ đơn giản bạn có thể hình dung map có thể lưu trữ các sinh viên và mã sinh viên tương ứng của họ và giúp bạn truy vấn nhanh tên sinh viên thông qua mã sinh viên. 
- Để sử dụng được map bạn cần thêm thư viện "map" vào chương trình của mình. 
- Các tính chất quan trọng của map : 
  + Các key trong map là riêng biệt, không có 2 key trùng nhau
  + Map duy trì thứ tự các phần tử theo giá trị key tăng dần
  + Map tìm kiếm giá trị key với độ phức tạp O(logN)
  + Map không hỗ trợ truy cập thông qua chỉ số như mảng hay vector, string.
  + Mỗi phần tử trong map chính là 1 pair
  + Set rất tối ưu trong các bài toán liên quan tới giá trị khác nhau trong mảng, tìm kiếm nhanh, các bài toán liên quan tới tần suất. 
- Cú pháp khai báo : 

    #include <map>
    
    map<key_data_type, value_data_type> map_name;


2. Một số hàm cơ bản của map

Trong bài viết này mình hướng dẫn các bạn các hàm cơ bản để có thể thao tác và duyệt map trước, chi tiết hơn về các hàm của map bạn xem ở bài học tiếp theo.

Các hàm cơ bản trong map : 

insert() : Thêm phần tử vào trong map với độ phức tạp 
size() : Trả về số phần tử trong map 
clear() : Xóa toàn bộ phần tử trong map
empty() : Kiểm tra vector rỗng
Lưu ý là khi thêm 1 phần tử vào trong map thì bạn cần thêm 1 cặp (pair) key - value vào map. Và nếu bạn thêm các cặp mà key đã tồn tại trong map thì map sẽ không thêm vào nữa để đảm bảo tính chất.

Ví dụ 1: 

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    map<int, int> mp;
    mp.insert(make_pair(1, 2)); // ok
    mp.insert(make_pair(1, 5)); // not ok
    mp.insert(make_pair(2, 4)); // ok
    mp.insert(make_pair(2, 5)); // not ok
    mp.insert(make_pair(2, 1)); // not ok
    mp.insert(make_pair(3, 1)); // ok
    cout << mp.size() << endl; // 3
}
Ngoài cách sử dụng hàm insert bạn còn có thể sử dụng cú pháp map[key] = value để thêm cặp key, value vào trong map. Tuy nhiên nếu key đã xuất hiện trong map thì câu lệnh này sẽ thay đổi giá trị value của key đó, bạn cũng có thể truy xuất giá tri của value thông qua key bằng cú pháp map[key].

Ví dụ 2: 

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    map<int, int> mp;
    mp.insert(make_pair(1, 2)); // ok
    mp.insert(make_pair(1, 5)); // not ok
    mp.insert(make_pair(2, 4)); // ok
    mp.insert(make_pair(2, 5)); // not ok
    mp.insert(make_pair(2, 1)); // not ok
    mp.insert(make_pair(3, 1)); // ok
    mp[5] = 10; // them moi
    mp[1] = 100; // thay doi value cua key 1 thanh 100
    cout << mp.size() << endl;
    cout << "Value tuong ung cua key 1 : " << mp[1] << endl; // 100
    cout << "Value tuong ung cua key 5 : " << mp[5] << endl; // 10
}
Output : 

4
Value tuong ung cua key 1 : 100
Value tuong ung cua key 5 : 10
3. Duyệt map

Bạn có thể sử dụng range based for loop để duyệt map hoặc duyệt map bằng iterator. Nếu bạn chưa biết về range based for loop có thể tham khảo tại đây, tương tự nếu chưa biết iterator bạn có thể tham khảo tại đây

Cách 1 : Duyệt map bằng range based for loop

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    map<int, int> mp;
    mp.insert(make_pair(1, 2)); // ok
    mp.insert(make_pair(2, 4)); // ok
    mp.insert(make_pair(3, 5)); // ok
    for(pair<int, int> it : mp){
        cout << "key = " << it.first << ", value = " << it.second << endl;
    }
}

Output : 

key = 1, value = 2
key = 2, value = 4
key = 3, value = 5


Cách 2 : Duyệt map bằng iterator

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    map<int, int> mp;
    mp.insert(make_pair(1, 2)); // ok
    mp.insert(make_pair(2, 4)); // ok
    mp.insert(make_pair(3, 5)); // ok
    map<int,int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++){
        cout << "key = " << (*it).first << ", value = " << (*it).second << endl; 
    }
}

Output : 

key = 1, value = 2
key = 2, value = 4
key = 3, value = 5


Duyệt ngược map : 

Khi duyệt ngược từ cuối của map bạn có 2 cách đó là sử dụng reverse_iterator hoặc bạn có thể đưa các phần tử trong map lưu vào 1 vector rồi sau đó in ngược lại từ cuối của vector.

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    map<int, int> mp;
    mp.insert(make_pair(1, 2)); // ok
    mp.insert(make_pair(2, 4)); // ok
    mp.insert(make_pair(3, 5)); // ok
    map<int,int>::reverse_iterator it;
    for(it = mp.rbegin(); it != mp.rend(); it++){
        cout << "key = " << (*it).first << ", value = " << (*it).second << endl; 
    }
}

Output : 

key = 3, value = 5
key = 2, value = 4
key = 1, value = 2
Nếu bạn muốn truy cập vào phần tử đầu tiên trong map thì thông qua iterator begin(), còn nếu muốn truy cập vào phần tử cuối cùng trong map thì thông qua iterator rbegin()

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    map<int, int> mp;
    mp.insert(make_pair(1, 2)); // ok
    mp.insert(make_pair(2, 4)); // ok
    mp.insert(make_pair(3, 5)); // ok
    map<int, int>::iterator it1 = mp.begin(); // auto ?
    cout << (*it1).first << " " << (*it1).second << endl;
    map<int, int>::reverse_iterator it2 = mp.rbegin(); // auto ?
    cout << (*it2).first << " " << (*it2).second << endl;
}
Output : 

1 2
3 5
