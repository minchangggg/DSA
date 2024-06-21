# I. [STL] Map Trong C++
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

![image](https://github.com/minchangggg/DSA/assets/125820144/b2af0a15-faec-4000-8802-5d8de96e46d5)

- Ứng dụng

![image](https://github.com/minchangggg/DSA/assets/125820144/9c611d8f-8745-4351-849c-759d5cfd826c)

## 2. Một số hàm cơ bản của map
`insert()` : Thêm phần tử vào trong map với độ phức tạp 

`size()`   : Trả về số phần tử trong map 

`clear()`  : Xóa toàn bộ phần tử trong map

`empty()`  : Kiểm tra vector rỗng

Lưu ý là khi thêm 1 phần tử vào trong map thì bạn cần thêm 1 cặp (pair) key - value vào map. Và nếu bạn thêm các cặp mà key đã tồn tại trong map thì map sẽ không thêm vào nữa để đảm bảo tính chất.

**Ví dụ 1:** 

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

**Ví dụ 2:**

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
      
> Output : 
>
> 4
>
> Value tuong ung cua key 1 : 100
>
> Value tuong ung cua key 5 : 10

## 3. Duyệt map
### Cách 1 : Duyệt map bằng range based for loop

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

> Output : 
> 
> key = 1, value = 2
>
> key = 2, value = 4
>
> key = 3, value = 5

### Cách 2 : Duyệt map bằng iterator

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

> Output : 
> 
> key = 1, value = 2
>
> key = 2, value = 4
>
> key = 3, value = 5

### Duyệt ngược map : 
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

> Output : 
>
> key = 3, value = 5
>
> key = 2, value = 4
>
> key = 1, value = 2

Nếu bạn muốn truy cập vào **phần tử đầu tiên** trong map thì thông qua **iterator begin()**, còn nếu muốn truy cập vào **phần tử cuối cùng** trong map thì thông qua **iterator rbegin()**

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
        
> Output : 
>
> 1 2
>
> 3 5

# II. [STL] Các Hàm Thông Dụng Của Map Trong C++
Hàm find()
Hàm count()
Hàm erase()
Hàm lower_bound()
Hàm upper_bound()

## 1. Hàm find()
- Hàm find() được sử dụng để tìm giá trị key trong map, độ phức tạp của hàm này là O(logN). 
- Giá trị trả về của hàm find() là iterator, nếu giá trị mà bạn tìm kiếm xuất hiện trong danh sách tập key của map thì hàm này sẽ trả về iterator tới cặp phần tử có key tương ứng, trường hợp key bạn tìm kiếm không xuất hiện trong map thì hàm trả về iterator end() của map.
- Hàm này có độ phức tạp rất tốt nên bạn có thể sử dụng map trong các bài toán tìm kiếm nhanh.
- Ví dụ: 

        #include <iostream>
        #include <map>
        
        using namespace std;
        
        int main(){
            map<int, int> mp;
            mp.insert(make_pair(1, 2));
            mp.insert(make_pair(2, 3));
            mp.insert(make_pair(3, 5));
            map<int, int>::iterator it1 = mp.find(2);
            map<int, int>::iterator it2 = mp.find(5);
            if(it1 != mp.end()){
                cout << "FOUND\n";
            }
            else cout << "NOT FOUND\n";
            if(it2 != mp.end()){
                cout << "FOUND\n";
            }
            else cout << "NOT FOUND\n";
            return 0;
        }
  
> Output : 
> 
> FOUND
>
> NOT FOUND

## 2. Hàm count()
- Hàm count() trả về số lần xuất hiện của 1 giá trị mà bạn tìm kiếm trong tập các key. Và vì mỗi key trong map chỉ xuất hiện 1 lần nên hàm này trả về 1 nếu key bạn tìm kiếm xuất hiện trong map, ngược lại trả về 0.
- Độ phức tạp là O(logN) và dễ dùng hơn hàm find() nên bạn có thể sử dụng hàm này để thay thế cho hàm find() trong việc tìm kiếm.
- Ví dụ:

        #include <iostream>
        #include <map>
        
        using namespace std;
        
        int main(){
            map<int, int> mp;
            mp.insert(make_pair(1, 2));
            mp.insert(make_pair(2, 3));
            mp.insert(make_pair(3, 5));
            if(mp.count(2) != 0){
                cout << "FOUND\n";
            }
            else cout << "NOT FOUND\n";
            if(mp.count(4) == 1){
                cout << "FOUND\n";
            }
            else cout << "NOT FOUND\n";
            return 0;
        }

> Output : 
> 
> FOUND
>
> NOT FOUND

## 3. Hàm erase()
- Hàm erase() có chức năng xóa 1 cặp phần tử trong map thông qua key, có 2 cách sử dụng hàm này là xóa thông qua giá trị hoặc xóa thông qua iterator.
- Độ phức tạp của hàm này là O(logN) nhưng khi sử dụng bạn cần hết sức lưu ý nếu bạn xóa 1 key không xuất hiện trong map sẽ gây lỗi.
- Ví dụ 1 : Xóa thông qua giá trị
        
        #include <iostream>
        #include <map>
        
        using namespace std;
        
        int main(){
            map<int, int> mp;
            mp.insert(make_pair(1, 2));
            mp.insert(make_pair(2, 3));
            mp.insert(make_pair(3, 5));
            if(mp.count(2)){
                mp.erase(2);
            }
            cout << "Map sau khi xoa key 2 : \n";
            for(pair<int, int> it : mp){
                cout << it.first << " " << it.second << endl;
            }
            return 0;
        }

> Output :
> 
> Map sau khi xoa key 2 : 
>
> 1 2
>
> 3 5

- Ví dụ 2: Xóa thông qua iterator

        #include <iostream>
        #include <map>
        using namespace std;
        
        int main(){
            map<int, int> mp;
            mp.insert(make_pair(1, 2));
            mp.insert(make_pair(2, 3));
            mp.insert(make_pair(3, 5));
            map<int, int>::iterator it = mp.find(2);
            if(it != mp.end()){
                mp.erase(it);
            }
            cout << "Map sau khi xoa key 2 : \n";
            for(pair<int, int> it : mp){
                cout << it.first << " " << it.second << endl;
            }
            return 0;
        }

> Output : 
> 
> Map sau khi xoa key 2 : 
>
> 1 2
>
> 3 5

## 4. Hàm lower_bound()
- Hàm lower_bound() ngoài sử dụng với mảng hay vector đã được sắp xếp thì còn có thể áp dụng với set & map. Hàm này trả về iterator tới giá trị nhỏ nhất trong map có key lớn hơn hoặc bằng giá trị tìm kiếm. 
- Ví dụ map của bạn có tập key là {1, 3, 6, 8, 9, 12} và bạn tìm kiếm giá trị X = 7 thì hàm này sẽ trả về iterator tới phần tử có key là 8 trong map, tương tự nếu bạn tìm X = 3 thì sẽ trả về iterator tới phần tử có key là 3. 
- Nếu trong trường hợp map của bạn không có key nào lớn hơn hoặc bằng giá trị key tìm kiếm thì hàm trả về iterator end() của map.
- Độ phức tạp là O(logN) 
- Ví dụ:
        
        #include <iostream>
        #include <map>
        using namespace std;
        
        int main(){
            map<int, int> mp;
            mp.insert(make_pair(1, 2));
            mp.insert(make_pair(3, 3));
            mp.insert(make_pair(5, 5));
            mp.insert(make_pair(6, 8));
            mp.insert(make_pair(10, 12));
            map<int, int>::iterator it1 = mp.lower_bound(4);
            if(it1 == mp.end()){
                cout << "Khong tim thay key >= 4" << endl;
            }
            else{
                cout << "Key nho nhat >= 4 la : " << (*it1).first << endl;
            }
            map<int, int>::iterator it2 = mp.lower_bound(14);
            if(it2 == mp.end()){
                cout << "Khong tim thay key >= 14" << endl;
            }
            else{
                cout << "Key nho nhat >= 14 la : " << (*it2).first << endl;
            }
            return 0;
        }

> Output : 
> 
> Key nho nhat >= 4 la : 5
>
> Khong tim thay key >= 14

## 5. Hàm upper_bound()
- Tương tự như hàm lower_bound() thì hàm upper_bound() được dùng để tìm giá trị nhỏ nhất lớn hơn giá trị key mà bạn tìm kiếm. 
- Ví dụ map của bạn có tập key là {1, 3, 6, 8, 9, 12} và bạn tìm kiếm giá trị X = 7 thì hàm này sẽ trả về iterator tới phần tử có key là 8 trong map, tương tự nếu bạn tìm X = 3 thì sẽ trả về iterator tới phần tử có key là 6. 
- Nếu trong trường hợp map của bạn không có key nào lớn hơn giá trị key tìm kiếm thì hàm trả về iterator end() của map.
- Độ phức tạp là O(logN)
- Ví dụ: 

        #include <iostream>
        #include <map>
        
        using namespace std;
        
        int main(){
            map<int, int> mp;
            mp.insert(make_pair(1, 2));
            mp.insert(make_pair(3, 3));
            mp.insert(make_pair(5, 5));
            mp.insert(make_pair(6, 8));
            mp.insert(make_pair(10, 12));
            map<int, int>::iterator it1 = mp.upper_bound(5);
            if(it1 == mp.end()){
                cout << "Khong tim thay key > 5" << endl;
            }
            else{
                cout << "Key nho nhat >= 5 la : " << (*it1).first << endl;
            }
            map<int, int>::iterator it2 = mp.upper_bound(14);
            if(it2 == mp.end()){
                cout << "Khong tim thay key > 14" << endl;
            }
            else{
                cout << "Key nho nhat >= 14 la : " << (*it2).first << endl;
            }
            return 0;
        }
  
> Output : 
> 
> Key nho nhat >= 5 la : 6
>
> Khong tim thay key > 14

# III. [STL] Multimap Trong C++
## 1. Multimap trong C++
- Tương tự như map thì multimap cũng lưu các phần tử là cặp key - value, nó có các hàm tương tự như map nhưng có 1 vài điểm khác biệt khi sử dụng.
- Multimap vẫn lưu các phần tử theo thứ tự key tăng dần nhưng các key có thể trùng nhau. Và vì các key có thể trùng nhau nên multimap không hỗ trợ việc bạn truy cập value thông qua key bằng cú pháp map[key] như map.
- Các tính chất của multimap : 
  + Các phần tử trong map có thể có key trùng nhau
  + Multimap lưu các phần tử theo thứ tự tăng dần về key
  + Multimap không hỗ trợ truy cập value thông qua key bằng cú pháp map[key]
  + Multimap không hỗ trợ chỉ số như mảng hay vector mà chỉ số của multimap chính là key
- Ví dụ: 

        #include <iostream>
        #include <map>
        using namespace std;
        
        int main(){
            multimap<int, int> mp;
            mp.insert(make_pair(1, 2));
            mp.insert(make_pair(1, 3));
            mp.insert(make_pair(1, 4));
            mp.insert(make_pair(2, 2));
            mp.insert(make_pair(2, 3));
            mp.insert(make_pair(2, 4));
            mp.insert(make_pair(3, 1));
            mp.insert(make_pair(3, 1));
            cout << "Map size : " << mp.size() << endl;
            for(pair<int, int> it : mp){
                cout << it.first << " " << it.second << endl;
            }
            return 0;
        }
  
> Output : 
> 
> Map size : 8
>
> 1 2
>
> 1 3
>
> 1 4
>
> 2 2
>
> 2 3
>
> 2 4
> 
> 3 1
>
> 3 1

## 2. Hàm find(), erase(), count() trong multimap
- Về độ phức tạp của 3 hàm find(), erase() và count() trong multimap thì tương tự như map là O(logN). Tuy nhiên có một vài điểm khác biệt các bạn cần lưu ý.
### Hàm find() :
- Do multimap có thể lưu trữ nhiều cặp phần tử có cùng key nên khi bạn tìm kiếm key sử dụng hàm find() thì sẽ trả về iterator tới cặp phần tử đầu tiên có key tương ứng trong map.
- Ví dụ multimap đang lưu các cặp phần tử {(1, 2), (1, 3), (2, 3), (2, 1), (2, 4), (5, 6)) và bạn tìm kiếm key là 2 thì hàm find() sẽ trả về iterator tới cặp phần tử (2, 3) là cặp phần tử có key 2 xuất hiện đầu tiên trong map.
- Ví dụ: 

        #include <iostream>
        #include <map>
        
        using namespace std;
        
        int main(){
            multimap<int, int> mp;
            mp.insert(make_pair(1, 2));
            mp.insert(make_pair(1, 3));
            mp.insert(make_pair(2, 3));
            mp.insert(make_pair(2, 1));
            mp.insert(make_pair(2, 4));
            mp.insert(make_pair(5, 6));
            multimap<int, int>::iterator it = mp.find(2);
            cout << (*it).first << " " << (*it).second << endl;
            return 0;
        }
  
> Output : 
> 
> 2 3

### Hàm erase() : 
- Hàm erase() nếu bạn xóa thông qua giá trị của key sẽ xóa toàn bộ cặp phần tử có key tương ứng trong multimap. Để xóa đi 1 cặp phần tử duy nhất thì bạn nên xóa thông qua iterator.
- Ví dụ: 

        #include <iostream>
        #include <map>
        using namespace std;
        
        int main(){
            multimap<int, int> mp;
            mp.insert(make_pair(1, 2));
            mp.insert(make_pair(1, 3));
            mp.insert(make_pair(2, 3));
            mp.insert(make_pair(2, 1));
            mp.insert(make_pair(2, 4));
            mp.insert(make_pair(5, 6));
            mp.erase(2);
            cout << "Map sau khi xoa : \n";
            for(pair<int, int> it : mp){
                cout << it.first << " " << it.second << endl;
            }
            return 0;
        }
  
> Output : 
> 
> Map sau khi xoa : 
>
> 1 2
>
> 1 3
>
> 5 6

### Hàm count() : 
- Hàm count() trong multimap khi bạn sử dụng để đếm số lần xuất hiện của key trả về giá trị tương ứng với số cặp phần tử có key tương ứng. Nếu key bạn đếm không xuất hiện thì hàm này trả về 0.
- Ví dụ:  

        #include <iostream>
        #include <map>
        
        using namespace std;
        
        int main(){
            multimap<int, int> mp;
            mp.insert(make_pair(1, 2));
            mp.insert(make_pair(1, 3));
            mp.insert(make_pair(2, 3));
            mp.insert(make_pair(2, 1));
            mp.insert(make_pair(2, 4));
            mp.insert(make_pair(5, 6));
            cout << "Key 2 xuat hien : " << mp.count(2) << " lan\n";
            cout << "key 28 xuat hien : " << mp.count(28) << " lan\n";
            return 0;
        }

> Output : 
> 
> Key 2 xuat hien : 3 lan
>
> key 28 xuat hien : 0 lan

# IV. [STL] Unordered_map Trong C++
Unordered_map là một associative container được bổ sung cho map và multimap với sự cải thiện về tốc độ của các hàm như find(), count(), erase().
## 1. Unordered_map trong C++
- Tương tự như map thì unordered_map được sử dụng để lưu trữ dữ liệu theo cặp key - value. Các hàm của map thì unordered_map đều có nhưng khác nhau về độ phức tạp.
- unordered_map được cài đặt bởi cấu trúc dữ liệu bảng băm - hash table. Bạn cần thêm thư viện "unordered_map" vào để có thể sử dụng container này.
- Các tính chất của unordered_map :
  + unordered_map lưu trữ phần tử với các key là riêng biệt
  + Các phần tử trong unordered_map không có thứ tự
- Ví dụ: 

        #include <iostream>
        #include <map>
        #include <unordered_map>
        
        using namespace std;
        
        int main(){
            unordered_map<string, string> mp;
            mp["28tech"] = "28tech.com.vn";
            mp["USA"] = "Trump";
            mp["Russia"] = "Putin";
            for(pair<string, string> it : mp){
                cout << it.first << " " << it.second << endl;
            }
            return 0;
        }

> Output : 
> 
> Russia Putin
>
> USA Trump
>
> 28tech 28tech.com.vn

## 2. Các hàm find(), count(), erase()
- Cách dùng 3 hàm phổ biến này của unordered_map tương tự như map, điều khác biệt duy nhất đó là vì unordered_map được cài đặt bởi bẳng băm thay vì cây đỏ đen Red-black tree như map nên sẽ có sự khác nhau về độ phức tạp. 
- Độ phức tạp trung bình của 3 hàm này là O(1), tuy nhiên trong trường hợp tệ nhất (Worst case) thì nó có thể là O(N). 
- Hàm insert trong unordered_map cũng tương tự như vậy về độ phức tạp. 
- Ví dụ: 

        #include <iostream>
        #include <map>
        #include <unordered_map>
        
        using namespace std;
        
        int main(){
            unordered_map<string, string> mp;
            mp["28tech"] = "28tech.com.vn";
            mp["USA"] = "Trump";
            mp["Russia"] = "Putin";
            mp.erase("USA");
            for(pair<string, string> it : mp){
                cout << it.first << " " << it.second << endl;
            }
            return 0;
        }
  
> Output : 
> 
> Russia Putin
>
> 28tech 28tech.com.vn
