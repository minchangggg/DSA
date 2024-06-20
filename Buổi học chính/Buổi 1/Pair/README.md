# [C++]. Kiểu Pair
Pair trong C++ là một kiểu container lưu trữ dữ liệu theo cặp đem lại nhiều sự tiện lợi khi bạn cần lưu trữ dữ liệu theo cặp, ví dụ như : Tọa độ Oxy, thời gian bắt đầu và kết thúc của một công việc, đỉnh đầu và cuối của một cạnh trên đồ thị...
## 1. Kiểu Pair
- pair nằm trong thư viện "utility" được sử dụng để kết hợp 2 kiểu dữ liệu với nhau, nó cung cấp cách lưu trữ 2 giá trị đi kèm nhau nhưng chỉ sử dụng 1 biến.
- Nhìn chung pair giúp lưu trữ dữ liệu theo cặp và có những đặc điểm sau : 

  + Phần tử thứ nhất của pair được gọi là first, phần tử thứ 2 của pair được gọi là second
  + Bạn có thể so sánh, gán, copy pair như kiểu dữ liệu bạn thường gặp
  + Để truy cập vào phần tử thứ nhất và thứ 2 trong pair ta sử dụng toán tử dấu chấm
    
- Cú pháp khai báo :

  // Cách 1 : Giá trị của first và second là mặc định
  
  `pair<first_data_type, second_data_type> pair_name;`
  
  // Cách 2 : Giá trị của first là value1, second là value2
  
  `pair<first_data_type, second_data_type> pair_name = make_pair(value1, value2`
  
  // Cách 3 : Giá trị của first là value1, second là value2
  
  `pair<first_data_type, second_data_type> pair_name(value1, value2`
  
  // Cách 4 : Giá trị của first là value1, second là value2
  
  `pair<first_data_type, second_data_type> pair_name = {value1, value2`

- Thành phần first và second của pair có thể là các kiểu dữ liệu thường gặp như int, float, double, long long,char... hay cũng có thể chính là một pair khác. Ngoài ra nó còn có thể là các kiểu phức tạp hơn như string, vector<>, set, object... tuy nhiên nhưng kiến thức này bạn chưa gặp nên tạm thời bỏ qua.

- Ví dụ 1: Các kiểu khai báo pair
      
      int main(){
          pair<int, int> a = make_pair(28, 100);
          cout << a.first << ' ' << a.second << endl;
      
          pair<char, int> b = {'@', 28};
          cout << b.first << ' ' << b.second << endl;
      
          pair<char, char> c('%', '$');
          cout << c.first << ' ' << c.second << endl;
          return 0;
      }

> Output : 
> 
> 28 100
>
> @ 28
> 
> % $

- Ví dụ 2 : pair lồng nhau
      
      int main(){
          pair<int, pair<char, int> > p1 = make_pair(28, make_pair('@', 100));
          cout << p1.first << endl;
          cout << p1.second.first << ' ' << p1.second.second << endl;
      
          pair<pair<int, int>, pair<int, int>> p2 = {{10, 20}, {30, 40}};
          cout << p2.first.first << ' ' << p2.first.second << endl;
          cout << p2.second.first << ' ' << p2.second.second << endl;
          return 0;
      }

> Output : 
>
> 28
>
> @ 100
> 
> 10 20
>
> 30 40

## 2. Toán Tử Với Pair
- Bạn có thể sử dụng các toán tử so sánh, gán với kiểu pair này.
- Ví dụ 1 . Toán gán sẽ gán giá trị của first và second của 2 pair cho nhau

      int main(){
          pair<string, int> p = make_pair("28tech", 28);
          pair<string, int> p1 = p;
          cout << p1.first << ' ' << p1.second << endl;
          return 0;
      }

> Output : 
>    
> 28tech 28

- Ví dụ 2 : So sánh 2 pair sẽ so sánh giá trị first sau đó so sánh giá trị second

      #include <iostream>
      #include <utility>
      
      using namespace std;
      
      int main(){
          pair<int, int> p1 = {10, 20};
          pair<int, int> p2 = {10, 21};
          pair<int, int> p3 = {5, 35};
          cout << boolalpha << (p1 == p2) << endl;
          cout << boolalpha << (p1 != p2) << endl;
          cout << boolalpha << (p1 < p2) << endl;
          cout << boolalpha << (p1 > p3) << endl;
          return 0;
      }
  
> Output : 
> 
> false
>
> true
>
> true
>
> true

- Ví dụ 3 : swap 2 pair với nhau bằng hàm swap

    #include <iostream>
    #include <utility>
    
    using namespace std;
    
    int main(){
        pair<int, int> p1 = {10, 20};
        pair<int, int> p2 = {30, 40};
        cout << "Ban dau : \n";
        cout << "p1 = {" << p1.first << ", " << p1.second << "}\n";
        cout << "p2 = {" << p2.first << ", " << p2.second << "}\n";
        p1.swap(p2);
        cout << "Sau khi swap : \n";
        cout << "p1 = {" << p1.first << ", " << p1.second << "}\n";
        cout << "p2 = {" << p2.first << ", " << p2.second << "}\n";
        return 0;
    }

> Output : 

> Ban dau : 
>
> p1 = {10, 20}
>
> p2 = {30, 40}
>
> Sau khi swap : 
>
> p1 = {30, 40}
>
> p2 = {10, 20}
