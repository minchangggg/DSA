# I. [STL] Vector Trong C++
Vector trong C++ là một container kiểu mảng động, tương tự như mảng nhưng linh hoạt và hỗ trợ nhiều hàm có sẵn. 
## 1. Vector Và Khai Báo Vector
- Vector là một container có tính chất tương tự như 1 mảng động, nó tự thay đổi kích thước khi bạn thêm hay xóa các phần tử trong mảng.
- Ngoài ra nó hỗ trợ truy cập các phần tử trong mảng thông qua chỉ số như mảng 1 chiều.
- Vector có thể lưu các kiểu dữ liệu như int, long long, float, char, pair, hoặc thậm chí là một vector khác. Khi sử dụng vector bạn cần thêm thư viện "vector" vào chương trình của mình.
- Cú pháp khai báo vector : 

`vector<data_type> vector_name;`

- Sau đây là một vài cách khai báo vector thường gặp 

        #include <iostream>
        #include <vector>
        using namespace std;
        
        int main(){
            //Khai báo vector rỗng
            vector<int> v1;
            //Khai báo vector với các phần tử
            vector<int> v2 = {1, 2, 3, 4, 5};
            //Khai báo vector có sẵn n phần tử
            int n = 20;
            vector<int> v3(n);
            //Khai báo vector có sẵn n phần tử có cùng giá trị val
            int val = 0;
            vector<int> v4(n, val);
            return 0;
        }
  
## 2. Hàm size(), length(), push_back() và pop_back()

`size()` : Trả về số lượng phần tử trong vector. Độ phức tạp O(1)

`length()` : Trả về số lượng phần tử trong vector. Độ phức tạp O(1)

`push_back()` : Thêm phần tử vào cuối vector. Độ phức tạp O(1)

`pop_back()` : Xóa phần tử cuối cùng trong vector. Độ phức tạp O(1)

Để duyệt vector bạn có thể duyệt thông qua chỉ số, dùng ranged-base for loop.

**Ví dụ 1: Tạo và duyệt vector**

        #include <iostream>
        #include <vector>
        
        using namespace std;
        
        int main(){
            vector<int> v;
            v.push_back(1); // {1}
            v.push_back(2); // {1, 2}
            v.push_back(3); // {1, 2, 3}
            v.push_back(4); // {1, 2, 3, 4}
            cout << "Kich thuoc vector : " << v.size() << endl; // v.length()
            cout << "Duyet vector bang chi so : \n";
            for(int i = 0; i < v.size(); i++){
                cout << v[i] << ' ';
            }  
            cout << "\nDuyet vector bang ranged-base for loop :\n";
            for(int x : v){
                cout << x << ' ';
            }
            return 0;
        }

> Output : 
> 
> Kich thuoc vector : 4
> 
> Duyet vector bang chi so :
> 
> 1 2 3 4
> 
> Duyet vector bang ranged-base for loop :
>
> 1 2 3 4
 
**Ví dụ 2 : Vector string**

        #include <iostream>
        #include <vector>
        
        using namespace std;
        
        int main(){
            vector<string> v = {"28tech", "STL"};
            cout << "Kich thuoc vector : " << v.size() << endl;
            v.push_back("C++");
            v.push_back("Java");
            v.push_back("PHP");
            cout << "Kich thuoc vector : " << v.size() << endl;
            cout << "Duyet vector : ";
            for(int i = 0; i < v.size(); i++){
                cout << v[i] << " ";
            }
            v.pop_back(); // Xoa PHP
            cout << "\nKich thuoc vector : " << v.size() << endl;
        }

> Output : 
> 
> Kich thuoc vector : 2
>
> Kich thuoc vector : 5
>
> Duyet vector : 28tech STL C++ Java PHP 
> Kich thuoc vector : 4

## 3. Vector Và Mảng 1 Chiều**

Tất cả các bài toán sử dụng mảng 1 chiều bạn đều có thể sử dụng vector để thay thế, dưới đây mình sẽ hướng dẫn cách bạn nhập mảng 1 chiều từ bàn phím sử dụng vector.

### Cách 1: Khai báo vector rỗng và thêm phần tử được nhập từ bàn phím vào cuối vector

      #include <iostream>
      #include <vector>
      
      using namespace std;
      
      int main(){
          vector<int> v;
          int n, tmp; cout << "Nhap so luong phan tu : ";
          cin >> n;
          for(int i = 0; i < n; i++){
              cout << "Nhap phan tu thu " << i + 1 << " : ";
              cin >> tmp;
              v.push_back(tmp);
          }
          cout << "Day so vua nhap : \n";
          for(int i = 0; i < v.size(); i++){
              cout << v[i] << " ";
          }
          return 0;
      }

### Cách 2 : Khai báo vector có sẵn số lượng phần tử được nhập từ bàn phím

      #include <iostream>
      #include <vector>
      
      using namespace std;
      
      int main(){
          int n, tmp; cout << "Nhap so luong phan tu : ";
          cin >> n;
          vector<int> v(n);
          for(int i = 0; i < n; i++){
              cout << "Nhap phan tu thu " << i + 1 << " : ";
              cin >> v[i];
          }
          cout << "Day so vua nhap : \n";
          for(int i = 0; i < v.size(); i++){
              cout << v[i] << " ";
          }
          return 0;
      }

## 4. Vector Và Mảng 2 Chiều
Mỗi vector có thể sử dụng như mảng 1 chiều, nếu muốn sử dụng vector như mảng 2 chiều bạn cần sử dụng vector các vector. 
### Cách 1 :  Nhập từng dòng của mảng 2 chiều như 1 vector và thêm vào vector chính.

        #include <iostream>
        #include <vector>
        
        using namespace std;
        
        int main(){
            int n, m;
            cout << "Nhap hang, cot : ";
            cin >> n >> m;
            vector<vector<int>> v;
            for(int i = 0; i < n; i++){
                vector<int> row;
                for(int j = 0; j < m; j++){
                    cout << "Nhap phan tu hang " << i + 1 << ", cot " << j + 1 << " : ";
                    int tmp; cin >> tmp;
                    row.push_back(tmp);
                }   
                v.push_back(row);
            }
            cout << "\nMang 2 chieu vua nhap : \n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << v[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }
        
### Cách 2 : Khai báo sẵn vector có kích thước với hàng, cột được nhập từ bàn phím

        #include <iostream>
        #include <vector>
        
        using namespace std;
        
        int main(){
            int n, m;
            cout << "Nhap hang, cot : ";
            cin >> n >> m;
            vector<vector<int>> v(n, vector<int>(m));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << "Nhap phan tu hang " << i + 1 << ", cot " << j + 1 << " : ";
                    cin >> v[i][j];
                }   
            }
            cout << "\nMang 2 chieu vua nhap : \n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << v[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }

# II. Iterator
## 1. Iterator Và Vector 
- Có 4 iterator chính trong vector mà bạn cần nắm được : 
        + begin() : Iterator trỏ tới phần tử đầu tiên trong vector
        + end() : Iterator trỏ tới phần tử sau phần tử cuối cùng trong vector
        + rbegin() : Iterator ngược trỏ tới phần tử cuối cùng trong vector
        + rend() : Iterator ngược trỏ tới phần tử trước phần tử đầu tiên trong vector

![image](https://github.com/minchangggg/DSA/assets/125820144/9513bef9-a178-499f-9eb0-b1a1c3c901fd)

- Cú pháp khai báo iterator : 

`vector<data_type>::iterator iterator_name;`

`vector<data_type>reverse_iterator iterator_name;`

- Tương tự như con trỏ thì khi bạn muốn truy cập vào phần tử mà iterator trong vector đang trỏ tới bạn cần giải tham chiếu bằng toán tử * 

- Ví dụ 1 : 

                #include <iostream>
                #include <vector>
                
                using namespace std;
                
                int main(){
                    vector<int> v = {28, 100, 30, 20, 15};
                    vector<int>::iterator it1 = v.begin();
                    cout << "v[0] = " << *it1 << endl;
                    vector<int>::reverse_iterator it2 = v.rbegin();
                    cout << "v[4] = " << *it2 << endl;
                    return 0;
                }
  
> Output : 
>
> v[0] = 28
> v[4] = 15

- Ví dụ 2 : Duyệt vector bằng iterator 

                #include <iostream>
                #include <vector>
                
                using namespace std;
                
                int main(){
                    vector<int> v = {28, 100, 30, 20, 15};
                    cout << "Duyet vector bang iterator : \n";
                    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
                        cout << *it << " ";
                    }
                    cout << "\nDuyet nguoc vector bang iterator nguoc : \n";
                    for(vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it){
                        cout << *it << ' ';
                    }
                    return 0;
                }
  
> Output : 
> 
> Duyet vector bang iterator : 
>
> 28 100 30 20 15 
>
> Duyet nguoc vector bang iterator nguoc : 
>
> 15 20 30 100 28

Chú ý : Bạn có thể thay vector::iterator hay vector::reverse_iterator bằng kiểu auto, bạn có thể tham khảo thêm về kiểu auto C++ tại đây

- Ví dụ 3 : Iterator trỏ tới phần tử có chỉ số x trong mảng là begin() + x

                #include <iostream>
                #include <vector>
                
                using namespace std;
                
                int main(){
                    vector<int> v = {28, 100, 30, 20, 15};
                    vector<int>::iterator it1 = v.begin() + 2;
                    cout << "v[2] = " << *it1 << endl;
                    auto it2 = v.begin() + 4;
                    cout << "v[4] = " << *it2 << endl;
                }
  
> Output : 
> 
> v[2] = 30
>
> v[4] = 15

## 2. Các Toán Tử Với Iterator 
- Iterator hỗ trợ các toán tử ++, -- hoặc toán tử toán học để bạn có thể di chuyển iterator qua lại các phần tử trong vector.
- Ví dụ 1 : 

                #include <iostream>
                #include <vector>
                
                using namespace std;
                
                int main(){
                    vector<int> v = {100, 200, 300, 400, 500};
                    vector<int>::iterator it = v.begin();
                    cout << "v[0] = " << *it << endl;
                    ++it; // it1 => v[1]
                    cout << "v[1] = " << *it << endl;
                    it += 2; // it1 => v[3]
                    cout << "v[3] = " << *it << endl;
                    --it; // it1 => v[2]
                    cout << "v[2] = " << *it << endl;
                }
  
> Output : 
> 
> v[0] = 100
>
> v[1] = 200
>
> v[3] = 400
>
> v[2] = 300

- Ví dụ 2 : Bạn cũng có thể tính khoảng cách giữa 2 iterator hoặc tìm ra chỉ số của phần tử mà iterator đang trỏ tới bằng cách sử dụng toán tử hoặc dùng hàm distance()

                #include <iostream>
                #include <vector>
                
                using namespace std;
                
                int main(){
                    vector<int> v = {100, 200, 300, 400, 500};
                    vector<int>::iterator it = v.begin();
                    it += 3;
                    cout << "Chi so cua phan tu ma it dang tro toi : " << it - v.begin() << endl;
                    cout << "Chi so cua phan tu ma it dang tro toi : " << distance(v.begin(), it) << endl;
                }
  
> Output : 
>
> Chi so cua phan tu ma it dang tro toi : 3
>
> Chi so cua phan tu ma it dang tro toi : 3

# II. [STL] Các Hàm Thông Dụng Của Lớp Vector
## 1. Hàm Truy Cập Phần Tử
- Để truy cập vào các phần tử trong vector bạn có thể thông qua chỉ số, ngoài ra bạn có thể nhanh chóng truy cập vào phần tử ở đầu và cuối vector. 
- Tổng hợp các hàm truy cập phần tử trong vector :
  
        `Toán tử []`	Truy cập phần tử thông qua chỉ số
  
        `at(index)`	Truy cập phần tử thông qua chỉ số
  
        `front()`	Truy cập phần tử đầu tiên trong vector
  
        `back()`        Truy cập phần tử cuối cùng trong vector

- Ví dụ : 

                #include <iostream>
                #include <vector>
                
                using namespace std;
                
                int main(){
                    vector<int> v = {100, 200, 300, 400, 500};
                    cout << "Duyet vector : \n";
                    for(int i = 0; i < 5; i++){
                        cout << v.at(i) << " ";
                    }
                    cout << "\nPhan tu dau tien : " << v.front() << endl;
                    cout << "Phan tu cuoi cung : " << v.back() << endl;
                }
  
> Output : 
>
> Duyet vector : 
>
> 100 200 300 400 500 
>
> Phan tu dau tien : 100
>
> Phan tu cuoi cung : 500

## 2. Hàm Kích Thước
- Vector cung cấp các hàm kiểm tra số lượng phần tử, check rỗng, thay đổi kích thước của vector.
- Tổng hợp các hàm liên quan tới kích thước phần tử trong vector :
  
        `size()`	Trả về kích thước của vector
        `empty()`	Kiểm tra vector rỗng trả về true, ngược lại trả về false
        `max_size()`	Trả về kích thước tối đa của vector
        `resize()`	Thay đổi kích thước của vector
  
- Ví dụ : 

                #include <iostream>
                #include <vector>
                
                using namespace std;
                
                int main(){
                    vector<int> v = {100, 200, 300, 400, 500};
                    cout << "So luong phan tu : " << v.size() << endl;
                    cout << "Max size : " << v.max_size() << endl;
                    v.resize(3); // {100, 200, 300}
                    cout << "So luong phan tu : " << v.size() << endl;
                    v.resize(0);
                    cout << "Vector rong : " << boolalpha << v.empty() << endl;
                }
  
> Output : 
> 
> So luong phan tu : 5
>
> Max size : 4611686018427387903
>
> So luong phan tu : 3
>
> Vector rong : true

Chú ý : Theo kết quả trả về của hàm max_size() thì vector có thể lưu đến 4611686018427387903 phần tử, tuy nhiên đây chỉ là trên lý thuyết. Thông thường thì vector cũng chỉ lưu được số lượng phần tử tương tự như mảng 1 chiều (cỡ 107 phần tử) và còn phụ thuộc vào bộ nhớ cho phép.

## 3. Hàm Thêm, Chèn, Xóa
- Vector cung cấp các hàm giúp bạn có thể thêm phần tử hoặc xóa phần tử khỏi vector, các hàm này sẽ làm kích thước của vector bị thay đổi theo. 
- Tổng hợp các hàm thay đổi vector :

        `push_back()`	        Thêm phần tử vào cuối vector
  
        `emplace_back()`	Thêm phần tử vào cuối vector

        `pop_back()`	        Xóa phần tử cuối cùng trong vector

        `insert()`	        Chèn phần tử vào vị trí bất kỳ trong vector

        `erase()`	        Xóa phần tử khỏi vị trí bất kỳ trong vector

        `clear()`	        Xóa toàn bộ phần tử trong vector

        `assign()`	        Gán giá trị cho phần tử trong vector

        `swap()`	        Hoán đổi 2 vector


- Hàm push_back(), emplace_back(), pop_back() :  Để thêm phần tử vào cuối vector bạn có thể dùng push_back() hoặc emplace_back(), còn để xóa phần tử cuối trong vector bạn dùng pop_back(). Lưu ý rằng khi vector rỗng mà bạn cố tính pop_back() sẽ gây lỗi.
-> Độ phức tạp : O(1)

                #include <iostream>
                #include <vector>
                
                using namespace std;
                
                int main(){
                    vector<int> v = {1, 2, 3};
                    v.push_back(4);
                    v.emplace_back(5);
                    v.push_back(6);
                    cout << "Duyet vector : \n";
                    for(int x : v){
                        cout << x << " ";
                    }
                    v.pop_back();
                    cout << "\nDuyet vector : \n";
                    for(int x : v){
                        cout << x << " ";
                    }
                }
  
> Output : 
>
> Duyet vector : 
>
> 1 2 3 4 5 6 
>
> Duyet vector : 
>
> 1 2 3 4 5 
>

- Hàm insert() : giúp bạn chèn phần tử vào chỉ số bất kỳ trong mảng, tuy nhiên bạn phải insert thông qua iterator. 
- Ví dụ bạn chèn phần tử vào chỉ số 3 thì bạn cần insert thông qua iterator là v.begin() + 3
-> Độ phức tạp : O(N)

                #include <iostream>
                #include <vector>
                
                using namespace std;
                
                int main(){
                    vector<int> v = {1, 2, 3, 4, 5};
                    //Chen vao chi so 3
                    v.insert(v.begin() + 3, 28);
                    cout << "Duyet vector : \n";
                    for(int x : v){
                        cout << x << " ";
                    }
                    //Chen vao dau : 
                    v.insert(v.begin(), 1000);
                    cout << "\nDuyet vector : \n";
                    for(int x : v){
                        cout << x << " ";
                    }
                }
  
> Output : 
> 
> Duyet vector : 
>
> 1 2 3 28 4 5 
>
> Duyet vector : 
>
> 1000 1 2 3 28 4 5 
>

- Hàm erase() : Tương tự như hàm insert() thì hàm erase() giúp bạn xóa 1 phần tử trong vector thông qua chỉ số của nó.  Bạn cũng cần truyền vào hàm erase() iterator đến phần tử mà bạn cần xóa.
-> Độ phức tạp : O(N)

                #include <iostream>
                #include <vector>
                
                using namespace std;
                
                int main(){
                    vector<int> v = {1, 2, 3, 4, 5};
                    //xoa phan tu o chi so 3
                    v.erase(v.begin() + 3);
                    cout << "Duyet vector : \n";
                    for(int x : v){
                        cout << x << " ";
                    }
                    //xoa phan tu o dau
                    v.erase(v.begin());
                    cout << "\nDuyet vector : \n";
                    for(int x : v){
                        cout << x << " ";
                    }
                }
  
> Output : 
> 
> Duyet vector : 
>
> 1 2 3 5 
>
> Duyet vector : 
>
> 2 3 5 

- Hàm clear(): giúp xóa toàn bộ phần tử khỏi vector và vector sẽ trở thành rỗng 
-> Độ phức tạp O(N)

                #include <iostream>
                #include <vector>
                
                using namespace std;
                
                int main(){
                    vector<int> v = {1, 2, 3, 4, 5};
                    v.clear();
                    cout << "Vector size : " << v.size() << endl;
                    cout << "Vector rong : " << boolalpha << v.empty() << endl;
                }
  
> Output : 
>
> Vector size : 0
>
> Vector rong : true

- Hàm assign(): giúp bạn gán giá trị toàn bộ các phần tử trong vector hoặc 1 vài phần tử trong vector, bạn cũng có thể gán nội dung của mảng hay vector khác sang vector hiện tại. Hàm này sẽ làm thay đổi kích thước của vector.
-> Độ phức tạp : O(N)

                #include <iostream>
                #include <vector>
                
                using namespace std;
                
                int main(){
                    vector<int> v1;
                    //Gan 5 phan tu dau tien là 28
                    v1.assign(5, 28);
                    cout << "Vector v1 : ";
                    for(int x : v1){
                        cout << x << ' ';
                    }
                    vector<int> v2;
                    //gan 3 phan tu dau tien trong v1 => v2
                    v2.assign(v1.begin(), v1.begin() + 3);
                    cout << "\nVector v2 : ";
                    for(int x : v2){
                        cout << x << ' ';
                    }
                }
  
> Output : 
> 
> Vector v1 : 28 28 28 28 28 
>
> Vector v2 : 28 28 28

- Hàm swap(): giúp bạn có thể hoán đổi nội dung của 2 vector.
-> Độ phức tạp : O(N)

                #include <iostream>
                #include <vector>
                
                using namespace std;
                
                int main(){
                    vector<int> v1 = {1, 2, 3, 4, 5, 6};
                    vector<int> v2 = {100, 200, 300, 400, 500};
                    v1.swap(v2);
                    cout << "Vector v1 : ";
                    for(int x : v1){
                        cout << x << " ";
                    }
                    cout << endl;
                    cout << "Vector v2 : ";
                    for(int x : v2){
                        cout << x << " ";
                    }
                }
  
> Output : 
> 
> Vector v1 : 100 200 300 400 500 
>
> Vector v2 : 1 2 3 4 5 6 
