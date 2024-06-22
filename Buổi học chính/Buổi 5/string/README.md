# I. String trong C++
## 1. String
- String trong C++ được sử dụng để lưu chuỗi (xâu) ký tự, nó như một mảng char động, có thể thay đổi kích thước một cách linh hoạt cũng như hỗ trợ chèn, xóa, sửa đổi...
- Khai báo string bạn có thể khai báo một xâu ký tự rỗng hoặc xâu có sẵn nội dung. Cú pháp : 

      //Khai báo xâu rỗng
      string name_string; 
      
      //Khai báo xâu rỗng
      string name_string = "";
      
      //Khai báo xâu có nội dung 
      string name_string = "data";

- Bạn có thể khai báo string, in ra màn hình nội dung string và sử dụng hàm size() để in ra số lượng ký tự trong string.

        #include <iostream>
        #include <string>
        using namespace std;
        
        using ll = long long;
        
        int main(){
            string s1;
            string s2 = "";
            string s3 = "28tech";
            cout << "Noi dung s1 : " << s1 << endl;
            cout << "So luong ky tu s1 : " << s1.size() << endl;
            cout << "Noi dung s2 : " << s2 << endl;
            cout << "So luong ky tu s2 : " << s2.size() << endl;
            cout << "Noi dung s3 : " << s3 << endl;
            cout << "So luong ky tu s3 : " << s3.size() << endl;
        }

> Output : 

        Noi dung s1 : 
        So luong ky tu s1 : 0
        Noi dung s2 : 
        So luong ky tu s2 : 0
        Noi dung s3 : 28tech
        So luong ky tu s3 : 6

## 2. Duyệt String
- String tương tự như 1 mảng động, bạn có thể truy xuất các phần tử (ký tự) trong xâu thông qua chỉ số được đánh từ 0.
- Nếu bạn muốn duyệt từng ký tự trong string thì bạn có thể dùng 3 cách : 
    + Duyệt thông qua chỉ số
    + Duyệt bằng ranged-base for loop
    + Duyệt bằng Iterator 

- Ví dụ string s = "28tech!@#" : 

![image](https://github.com/minchangggg/DSA/assets/125820144/6bf4930b-8fb7-40d5-8ff4-babb3bba67df)

### a. Duyệt string bằng chỉ số 

        #include <iostream>
        #include <string>
        using namespace std;
        
        using ll = long long;
        
        int main(){
            string s = "28tech!@#";
            for(int i = 0; i < (int)s.size(); i++){
                cout << "s["<<i<<"] = " << s[i] << endl;
            }
        }

> Output : 

        s[0] = 2
        s[1] = 8
        s[2] = t
        s[3] = e
        s[4] = c
        s[5] = h
        s[6] = !
        s[7] = @
        s[8] = #

### b. Duyệt bằng ranged-base for loop : 

        #include <iostream>
        #include <string>
        using namespace std;
        
        using ll = long long;
        
        int main(){
            string s = "28tech!@#";
            for(char x : s){
                cout << x << ' ';
            }
        }

> Output : 

        2 8 t e c h ! @ # 

### c. Duyệt bằng Iterator 

        #include <iostream>
        #include <string>
        using namespace std;
        
        using ll = long long;
        
        int main(){
            string s = "28tech!@#";
            for(string::iterator it = s.begin(); it != s.end(); ++it){
                cout << *it << ' ';
            }
        }

> Output : 

        2 8 t e c h ! @ # 

## 3. Nhập Xâu Ký Tự Từ Bàn Phím
### 3.1. Trong trường hợp xâu ký tự của bạn không chứa khoảng trắng (dấu cách, tab) thì bạn có thể dùng cin

![image](https://github.com/minchangggg/DSA/assets/125820144/0b132662-13f7-4e81-b780-1abbb91b76bb)

### 3.2. Khi bạn muốn đọc xâu ký tự đến hết dòng (đọc hết cả dấu cách, tab) thì bạn cần dùng hàm getline()
- Cú pháp :   `getline(cin, string, delimiter);`

`a. Nếu getline() không có tham số thứ 3 thì mặc định nó sẽ là dấu enter.` 

![image](https://github.com/minchangggg/DSA/assets/125820144/1ea16cd1-fe32-41c9-bd30-dfce03969feb)

![image](https://github.com/minchangggg/DSA/assets/125820144/e3a383e1-842a-4fe0-a284-cef745bcaee6)

- Nguyên nhân : 
  + Hàm getline() khi bạn nhập xâu s sẽ dừng nhập cho tới khi nó gặp được ký tự xuống dòng (enter), những ký tự nó đọc được từ luồng vào cin cho tới kí tự enter đó sẽ được gán cho string s.
  + Khi bạn nhập cin >> n sau đó ấn enter, thì giá trị mà bạn vừa nhập sẽ được gán cho n tuy nhiên ký tự enter ở cuối bạn nhập sẽ nằm trong luồng vào cin, khi hàm getline() đọc từ luồng cin thì sẽ gặp ký tự enter này do cin ở câu lệnh trên để lại.
  + Do getline() sẽ dừng nhập khi gặp enter nên nó sẽ dừng ngay tại lúc đó mà chưa hề nhập được ký tự nào và dẫn đến xâu s của bạn là một xâu rỗng
  + Vậy nếu trước hàm getline() mà trong luồng cin có thừa kí tự enter(thông thường do cin ở câu lệnh trước đó để lại) thì sẽ xảy ra trôi lệnh.
  + Lưu ý: rằng nếu bạn dùng câu lệnh getline() sau một câu lệnh getline() thì bạn sẽ không bị trôi lệnh vì hàm getline() sẽ xử lý ký tự enter ở cuối dòng chứ không để lại trong luồng vào như câu lệnh cin.

- Cách khắc phục : 
  + Khi bạn biết nguyên nhân getline() bị trôi lệnh là do đọc phải ký tự enter thừa trong luồng vào từ bàn phím nên để xử lý việc này bạn chỉ cần loại bỏ được ký tự enter này trước khi dùng getline().
  + Bạn có thể dùng hàm cin.ignore(1) hoặc cin.ingore() để loại bỏ đi 1 ký tự trong luồng cin, khi đó ký tự enter sẽ bị loại bỏ và hàm getline() sẽ đợi bạn nhập nội dung sau đó ấn enter.
  + Ngoài ra bạn cũng có thể sử dụng hàm getchar() vì hàm này sẽ đọc 1 ký tự trong luồng cin và đọc được ký tự enter thừa.

![image](https://github.com/minchangggg/DSA/assets/125820144/c59351fe-95f3-4542-9959-3ba29829d193)

`b. Trong trường hợp bạn thêm tham số thứ 3 cho getline() thì nó sẽ đọc từ luồng cin cho tới khi gặp kí tự là tham số thứ 3 mà bạn truyền vào hàm.`

        #include <iostream>
        #include <string>
        using namespace std;
        
        using ll = long long;
        
        int main(){
            string s;
            cout << "Nhap xau s : \n";
            getline(cin, s, ',');
            cout << "Xau vua nhap : " << s << endl;
            return 0;
        }

> input : 

        28tech.C++,string

> output : 

        Xau vua nhap : 28tech.C++

## 4. So sánh và cộng xâu
- Quy tắc so sánh 2 xâu theo thứ tự từ điển : 
  + Nếu 2 xâu có cùng độ dài và giống nhau mọi ký tự thì bằng nhau, ví dụ "28tech" và "28tech"
  + Nếu 2 xâu khác nhau thì ký tự đầu tiên khác nhau của 2 xâu sẽ quy định xâu nào có từ điển lớn hơn, nhỏ hơn. Ví dụ "28techzabc" và "28techaz" thì chữ thứ 7 của 2 xâu này khác nhau và 'z' lớn hơn 'a' theo từ điển nên xâu "28techzabc" lớn hơn "28techaz" về mặt từ điển
  + Nếu 2 xâu không có ký tự khác nhau đầu tiên thì xâu nào dài hơn sẽ có từ điển lớn hơn, ví dụ "28tech" và "28techblog" thì "28techblog" có từ điển lớn hơn
  + Chữ cái in hoa và in thường có thứ tự từ điển khác nhau và thứ tự từ điển của ký tự được quy định bởi mã ASCII
- Một vài ví dụ về thứ tự từ điển của 2 xâu ký tự :
  + "28tech" > "28Techzzz"
  + "1234" > "zzz"
  + "lan" < "lan di hoc lap trinh"
  + "28tech" > "27tech"
  + "28tech java" < "28tech@"
  
![image](https://github.com/minchangggg/DSA/assets/125820144/542e9d08-7bd1-4624-b7ef-2a3e7d5ed136)

- Ví dụ : 

        #include <iostream>
        #include <string>
        using namespace std;
        
        int main(){
        	cout << boolalpha << ("28tech" == "28tech") << endl;
        	cout << boolalpha << ("28tech" != "28tech") << endl;
        	cout << boolalpha << ("28techabc" < "28techza") << endl;
        	cout << boolalpha << ("28Tech" < "28tech") << endl;
        	cout << boolalpha << ("28 tech" < "28@tech") << endl;
        	return 0;
        }
  
> Output : 

        true
        false
        true
        true
        true

- Ví dụ:

        #include <iostream>
        #include <string>
        
        using namespace std;
        
        int main(){
            string s = "28tech";
  
            s += " blog"; //Nối toàn bộ xâu
            cout << s << endl;
  
            s += '@'; //Nối 1 ký tự
            cout << s << endl;
  
            s += " C++";
            cout << s << endl;
        }
  
> Output : 

        28tech blog
        28tech blog@
        28tech blog@ C++

# II. Các Hàm String Xử Lý Xâu
> Hàm push_back() và pop_back()

> Hàm append()

> Hàm insert()

> Hàm erase()

> Hàm substr()

> Hàm find()

## 1. Hàm push_back() và pop_back() 
- Hàm push_back() sẽ thêm 1 ký tự vào cuối string và pop_back() sẽ xóa đi ký tự cuối cùng trong string.
- Lưu ý là hàm này sẽ thêm 1 ký tự chứ không phải là thêm 1 chuỗi ký tự, nếu bạn cố tính push_back 1 chuỗi ký tự sẽ gây lỗi.
- Độ phức tạp của 2 hàm này đều là O(1)
- Ví dụ : 

        #include <iostream>
        #include <string>
        
        using namespace std;
        
        int main(){
            string s = "28tech";
            s.push_back('@');
            cout << s << endl;
            s.push_back('#');
            cout << s << endl;
            s.pop_back();
            cout << s << endl;
        }
        
> Output : 

        28tech@
        28tech@#
        28tech@
        
## 2. Hàm append()
- Hàm append() có chức năng nối chuỗi hoặc nối ký tự vào cuối của string. Bạn có thể lựa chọn nối toàn bộ chuỗi khác vào chuỗi hiện tại hoặc nối 1 vài ký tự liên tiếp của xâu khác vào xâu hiện tại.
- Độ phức tạp : O(N)
- Ví dụ : 

        #include <iostream>
        #include <string>
        
        using namespace std;
        
        int main(){
            string s = "28tech";
  
            //Nối toàn bộ xâu
            s.append("blog");
            cout << s << endl;
  
            string t = "0123456789";
            //Nối 5 kí tự tính từ chỉ số 1 của xâu t vào s
            s.append(t, 1, 5);
            cout << s << endl;
        }
  
> Output : 

        28techblog
        28techblog12345
        
## 3. Hàm insert()
- Hàm insert() giúp bạn chèn một xâu khác vào vị trí bất kỳ trong xâu hiện tại thông qua chỉ số chèn.
- Cú pháp : s.insert(index, string t);
- Trong đó xâu t được chèn vào chỉ số index của xâu s, hàm này có tương đối nhiều cách dùng tuy nhiên chèn vào vị trí xác định trong xâu là phổ biến nhất.
- Độ phức tạp : O(N)
- Ví dụ : 

        #include <iostream>
        #include <string>
        
        using namespace std;
        
        int main(){
            string s = "28tech";
            
            s.insert(2, "####"); //Chen vao chi so 2 cua xau s 
            cout << s << endl;
  
            s.insert(0, "blog "); //Chen vao dau xau s
            cout << s << endl;
        }
  
> Output : 

        28####tech
        blog 28####tech

## 4. Hàm erase
- Hàm erase() giúp bạn có thể xóa đi 1 vài ký tự của xâu hiện tại thông qua chỉ số.
- Cú pháp :
  + s.erase(pos) : Xóa tất cả các ký tự trong xâu s từ chỉ số pos tới cuối xâu
  + s.erase(pos, n) : Xóa n ký tự trong xâu s tính từ chỉ số pos
- Độ phức tạp : O(N)
- Ví dụ : 

        #include <iostream>
        #include <string>
        using namespace std;
        
        int main(){
            string s = "28tech.com.vn";
            //Xoa tu chi so 6 toi het xau
            s.erase(6);
            cout << s << endl;
  
            string t = "28tech.com.vn";
            //Xoa 4 ki tu tinh tu chi so 2
            t.erase(2, 4);
            cout << t << endl;
        }
  
> Output : 

        28tech
        28.com.vn

- Ví dụ :
  
        #include <bits/stdc++.h>
        using namespace std;
        
        int main(){
            string s = "28@@@tech";
            s.erase(2, 3); //Xóa 3 kí tự từ chỉ số 2
            cout << s << endl;
            string t = "28@@@tech";
            t.erase(2); //Xóa mọi kí tự từ chỉ số 2
            cout << t << endl;
        }

> Output : 

        28tech
        28

## 5. Hàm substr()
- Hàm substr() giúp bạn có thể tách xâu con của xâu hiện tại, hàm này trả về xâu con tách được.
- Cú pháp : 
  + s.substr(pos) : Trả về xâu con của xâu s tính từ chỉ số pos
  + s.substr(pos, n) : Trả về xâu con gồm n ký tự tính từ chỉ số pos của xâu s
- Độ phức tạp : O(N)
- Ví dụ : 

        #include <iostream>
        #include <string>
        
        using namespace std;
        
        int main(){
            string s = "28tech.com.vn";
            //Xau con tu chi so 2 toi het xau
            string sub1 = s.substr(2);
            cout << sub1 << endl;
  
            string t = "28tech.com.vn";
            //Xau con tu chi so 0 co do dai 6
            string sub2 = t.substr(0, 6);
            cout << sub2 << endl;
        }
  
> Output : 

        tech.com.vn
        28tech
        
## 6. Hàm find()
- Hàm find() giúp bạn tìm kiếm sự xuất hiện của xâu con trong xâu hiện tại.
- Hàm này sẽ trả về chỉ số đầu tiên của xâu con nếu xâu này tồn tại trong xâu đang tìm kiếm, ngược lại sẽ trả về giá trị là string::npos 
- Độ phức tạp : O(N)
- Ví dụ :
  
![image](https://github.com/minchangggg/DSA/assets/125820144/0018e9ac-da38-4ec2-ade1-f58869d41552)

- Ví dụ :
  
        #include <iostream>
        #include <string>
        
        using namespace std;
        
        int main(){
            string s = "28tech.com.vn 28tech";
            if(s.find("28tech") == string::npos){
                cout << "NOT FOUND\n";
            }
            else{
                cout << "FOUND\n";
                cout << s.find("28tech");
            }
        }
  
> Output : 

        FOUND
        0

## 7. Hàm Compare()
- Hàm compare() trong C++ được sử dụng để so sánh 2 xâu, hàm này sẽ trả về số nhỏ hơn, lớn hơn hoặc bằng 0 tùy vào từ điển của 2 xâu sử dụng. Khi hàm này trả về 0 nghĩa là 2 xâu này giống nhau.
- Ví dụ : 

        #include <iostream>
        #include <string>
        using namespace std;
        
        int main(){
        	string s = "28tech", t = "28Tech", p = "28tech";
        	cout << s.compare(p) << endl;
        	cout << s.compare(t) << endl;
        	cout << t.compare(p) << endl;
        	return 0;
        }
  
> Output : 

        0
        1
        -1
        
# III. Nhắc lại các hàm kiểm tra kí tự
![image](https://github.com/minchangggg/DSA/assets/125820144/a135dcc1-800d-4ec1-808b-a5add4e89e6f)
## 1. Hàm Chuyển Đổi in Hoa và in Thường
- Lưu ý : **Nếu bạn muốn thay đổi string thông qua hàm bạn cần sử dụng tham chiếu.**

        #include <iostream>
        #include <string>
        #include <ctype.h>
        
        using namespace std;
        
        void to_lower(string &s){
        	for(int i = 0; i < s.size(); i++){
        		s[i] = tolower(s[i]);
        	}
        }
        
        void to_upper(string &s){
        	for(int i = 0; i < s.size(); i++){
        		s[i] = toupper(s[i]);
        	}
        }
        
        int main(){
        	string s = "28tech BLOG";
        	to_lower(s);
        	cout << s << endl;
        	to_upper(s);
        	cout << s << endl;
        }
        
> Output : 

        28tech blog
        28TECH BLOG

- Bạn cũng có thể viết hàm để trả về string ở dạng in thường hoặc in hoa.

        #include <iostream>
        #include <string>
        #include <ctype.h>
        
        using namespace std;
        
        string to_lower(string s){
        	for(int i = 0; i < s.size(); i++){
        		if(s[i] >= 'A' && s[i] <= 'Z'){
        			s[i] += 32;
        		}
        	}
        	return s;
        }
        
        string to_upper(string s){
        	for(int i = 0; i < s.size(); i++){
        		if(s[i] >= 'a' && s[i] <= 'z'){
        			s[i] -= 32;
        		}
        	}
        	return s;
        }

        int main(){
        	string s = "28tech BLOG";
        	cout << to_lower(s) << endl;
        	cout << to_upper(s) << endl;
        }
  
> Output : 

        28tech blog
        28TECH BLOG
        
## 2. Hàm Chuyển Đổi Hoa Thường Bằng Hàm transform()
- Trong C++ thì bạn có thể sử dụng hàm có sẵn transform() để chuyển đổi xâu thành in hoa hoặc in thường.
  
        #include <iostream>
        #include <string>
        #include <algorithm>
        
        using namespace std;
        
        int main(){
        	string s = "28tech BLOG strING";
        	transform(s.begin(), s.end(), s.begin(), ::tolower);
        	cout << "Lowercase : " << s << endl;
        	transform(s.begin(), s.end(), s.begin(), ::toupper);
        	cout << "Uppercase : " << s << endl;
        }

> Output : 

        Lowercase : 28tech blog string
        Uppercase : 28TECH BLOG STRING

- Tuy nhiên cú pháp của nó hơi dài dòng và khó nhớ, thông thường mình sẽ dùng range-based for loop và hàm toupper(), tolower() kết hợp tham chiếu để chuyển xâu thành in hoa hoặc in thường.

        #include <iostream>
        #include <string>
        #include <algorithm>
        
        using namespace std;
        
        int main(){
        	string s = "28tech BLOG strING";
        	for(char &x : s) 
        		x = tolower(x);
        	cout << "Lowercase : " << s << endl;
        	for(char &x : s)
        		x = toupper(x);
        	cout << "Uppercase : " << s << endl;
        }

> Output : 

        Lowercase : 28tech blog string
        Uppercase : 28TECH BLOG STRING

## 3. Hàm Phân Loại Kí Tự
![image](https://github.com/minchangggg/DSA/assets/125820144/416b7248-b98b-41c6-9549-ceaea7d3f9d9)

# IV. Chuyển Đổi Giữa Số Và String Trong C++
## 1. Chuyển Đổi Xâu Thành Số
![image](https://github.com/minchangggg/DSA/assets/125820144/5007b202-4f86-4561-b7c8-43755571cbb7)

- Chủ yếu sử dụng 3 hàm : stoi(), stoll() và stod()
- `Xây dựng hàm stoll()`
  
            long long my_stoll (string s) {
                long long res = 0;
                for (int i = 0; i < s.size(); i++) {
                    res = res * 10 + ( s[i] - '0' );
                }
                return res;
            }

- Ví dụ:
  
![image](https://github.com/minchangggg/DSA/assets/125820144/0bca561a-ffd4-420c-a67d-23ff8aaba1c5)

## 2. Chuyển Đổi Số Thành Xâu
- Hàm to_string() trong C++ sẽ giúp bạn chuyển đối số thành xâu.
- Lưu ý hàm này chỉ hỗ trợ từ C++11 trở lên, nếu bạn làm việc với các chuẩn C++11 hoặc mới hơn hay làm bài trên các website chấm bài online thì có thể dùng hàm này một cách thoải mái.
- `Xây dựng hàm to_string()`

            string my_to_string (long long n) {
                string res = "";
                while (n!=0) {
                    res += n % 10 + '0';
                    n /= 10;
                }
                reverse(res.begin(), res.end());
                return res;
            }
  
- Ví dụ:
  
![image](https://github.com/minchangggg/DSA/assets/125820144/3021fdf4-6d86-4050-bf60-3d4812b8d4f4)

# V. Stringstream Trong C++ Và Ứng Dụng
Stringstream trong C++ là một công cụ hữu ích với các bài toán xử lý xâu ký tự, đặc biệt với các bài toán tách từ trong xâu.
## 1. Tách các từ bằng stringstream theo dấu cách
![image](https://github.com/minchangggg/DSA/assets/125820144/1d0de517-b00b-4db1-bbdb-1722e638526a)

- Thông thường khi chuẩn hóa hay xử lý xâu ký tự thì bạn cần tách riêng lẻ các từ trong xâu theo dấu cách hoặc một ký tự khác ví dụ như dấu . , ! ... 
- **stringstream nằm trong thư viện sstream**, nó có chức năng **biến xâu string của bạn thành luồng** (tương tự như luồng vào từ bàn phím là **cin**). Từ đó bạn có thể đọc từng từ trong luồng stringstream ra và xử lý.
- Ví dụ sau mình sẽ tách từng từ trong xâu ra, sau khi tách xong bạn có thể chuẩn hóa, đếm từ ... với từ bạn tách được.

            #include <iostream>
            #include <string>
            #include <sstream>
            
            using namespace std;
            
            int main(){
                  string s = "28tech    hoc  lap trinh";
                  stringstream ss(s); //Khai báo stringstream ss và gán cho nó nội dung của s
  
                  string word;
                  int dem = 0;
                  while(ss >> word){
                        ++dem;
                        cout << "Tu thu " << dem << " tach duoc : " << word << endl;
                  }
                  return 0;
            }
  
> Output : 

            Tu thu 1 tach duoc : 28tech
            Tu thu 2 tach duoc : hoc
            Tu thu 3 tach duoc : lap
            Tu thu 4 tach duoc : trinh
        
- Giải thích mã nguồn : 
      + Ban đầu bạn **khai báo 1 biến stringstream** và **khởi tạo giá trị cho nó bằng nội dung xâu bạn muốn tách từ**
      + Dùng **toán tử >> để nhập 1 từ trong luồng stringstream cho biến word**, vòng lặp kia sẽ **lặp cho tới khi luồng stringstream của bạn không còn từ nào nữa thì nó sẽ dừng lặp**.
      + Giữa các từ có nhiều dấu cách sẽ được bỏ qua hết, tương tự như bạn nhập cin từ bàn phím thì số lượng dấu cách giữa các từ không có ý nghĩa.

## 2. Tách các từ bằng stringstream theo kí tự
- Trong trường hợp bạn muốn **tách theo 1 ký tự khác, ví dụ như là dấu -** thay vì dấu cách như mặc định bạn có thể **sử dụng hàm getline()**, hoặc bạn có thể thay cách dấu - thành dấu cách và xử lý như tách từ bằng dấu cách.

        #include <iostream>
        #include <string>
        #include <sstream>
        
        using namespace std;
        
        int main(){
        	string s = "28tech-hoc-lap-trinh";
        	stringstream ss(s); //Khai báo stringstream ss và gán cho nó nội dung của s
  
        	string word;
        	int dem = 0;
        	while(getline(ss, word, '-')){
        		++dem;
        		cout << "Tu thu " << dem << " tach duoc : " << word << endl;
        	}
        	return 0;
        }

> Output : 

        Tu thu 1 tach duoc : 28tech
        Tu thu 2 tach duoc : hoc
        Tu thu 3 tach duoc : lap
        Tu thu 4 tach duoc : trinh
        
## 3. Tách từ theo nhiều ký tự khác nhau
- Giả sử bạn cần **tách các xâu theo 1 loạt ký tự khác nhau (delimiter)** thì bạn nên **chuyển hết các ký tự này thành dấu cách** rồi tách xâu bằng stringstream.
- Muốn tách xâu theo các ký tự : dấu chấm '.', dấu phẩy ',', dấu cách ' ', dấu hỏi chấm '?', và dấu chấm than '!' ta triển khai như sau:

        #include <iostream>
        #include <string>
        #include <sstream>
        
        using namespace std;
        
        int main(){
        	string s = "28tech,hoc.lap!!trinh???C++ dsa";
  
        	//Thay hết delimiter bằng dấu cách
        	for(int i = 0; i < s.size(); i++){
        		if(s[i] == '?' || s[i] == '!' || s[i] == '.' || s[i] == ','){
        			s[i] = ' ';
        		}
        	}

        	stringstream ss(s); //Khai báo stringstream ss và gán cho nó nội dung của s
  
        	string word;
        	int dem = 0;
        	while(ss >> word){
        		++dem;
        		cout << "Tu thu " << dem << " tach duoc : " << word << endl;
        	}
        	return 0;
        }
  
> Output : 

            Tu thu 1 tach duoc : 28tech
            Tu thu 2 tach duoc : hoc
            Tu thu 3 tach duoc : lap
            Tu thu 4 tach duoc : trinh
            Tu thu 5 tach duoc : C++
            Tu thu 6 tach duoc : dsa

## 4. Tách các số từ xâu

            #include <bits/stdc++.h>
            using namespace std;
            int main(){
                string s = "abc123zzz28tech9992ac";
                for(char &x : s){
                    if(!isdigit(x)) x = ' ';
                }
                stringstream ss(s);
                string word;
                while(ss >> word){
                    cout << word << endl;
                }
            }

> Output :

            123
            28
            9992

## 5. Bài tập áp dụng stringstream
### Bài tập 1 : Đếm số lượng từ trong xâu ký tự, giữa các từ có thể có nhiều dấu cách
- Đối với bài toán này bạn có thể xử lý xâu bằng cách gặp ký tự khác dấu cách thì đếm 1 từ và xử lý nốt các ký tự còn lại của từ đó hoặc dùng stringtream

        #include <iostream>
        #include <string>
        #include <sstream>
        
        using namespace std;
        
        int main(){
        	string s = "28tech 28tech com vn blog AI    python";
        	stringstream ss(s);
  
        	string word;
        	int cnt = 0;
        	while(ss >> word){
        		++cnt;
        	}
        	cout << "So luong tu trong xau : " << cnt << endl;
        }

> Output : 

        So luong tu trong xau : 7
        
- Nếu bạn không muốn sử dụng stringstream thì có thể cài đặt như sau : 

            #include <iostream>
            #include <string>
            #include <sstream>
            
            using namespace std;
            
            int main(){
                string s = "28tech 28tech com vn blog AI    python";
                int cnt = 0;
                for(int i = 0; i < s.size(); i++){
                    if(s[i] != ' '){
                        ++cnt;
                        //duyet not cac ki tu cua tu bat dau tu chi so i
                        while(i < s.size() && s[i] != ' '){
                            ++i;
                        }
                        --i;
                    }
                }
                cout << "So luong tu trong xau : " << cnt << endl;
            }

> Output : 

        So luong tu trong xau : 7
        
### Bài tập 2 : Chuẩn hóa từ và loại bỏ dấu cách thừa giữa các từ trong xâu, ví dụ "  ngUYEN   VaN   tech28" thì chuẩn hóa thành "Nguyen Van Tech28"
- Cách làm là bạn hãy tách các từ ra, chuẩn hóa từng từ rồi nối chung lại với nhau để tạo thành xâu chuẩn hóa. 
- Thay vì bạn cứ loay hoay xét từ và xóa dấu cách thừa thì việc tách ra, chuẩn hóa và gộp lại sẽ dễ và nhanh hơn nhiều.

`Cách 1: tự nghĩ`

            #include <iostream>
            #include <string>
            #include <sstream>
            
            using namespace std;
            
            int main(){
                string s = "  ngUYEN   VaN   tech28";
                stringstream ss(s);
            
                string temp, word = "";
                while (ss >> temp) {
                    for (int i = 0; i < temp.size(); i++) { 
                        if (i==0) temp[i] = toupper(temp[i]);
                        else temp[i] = tolower(temp[i]);
                    }
                    word += temp;
                    word += ' ';
                }
                word.pop_back(); 
                cout << word;   
            }

> Output :

            Nguyen Van Tech28

`Cách 2: của web`

        #include <iostream>
        #include <string>
        #include <ctype.h>
        #include <sstream>
        
        using namespace std;
        
        int main(){
        	string s = "   NgUYeN   vAN   tECH28  ";
        	string res = "";
        	stringstream ss(s);
        	string word;
        	while(ss >> word){
        		//Ki tu dau tien cua tung tu thi viet hoa
        		res += toupper(word[0]);
        		//Cac ki tu con lai thi viet thuong
        		for(int j = 1; j < word.size(); j++){
        			res += tolower(word[j]);
        		}
        		//Them dau cach giua cac tu
        		res += " ";
        	}
        	//Loai bo ki tu dau cach thua sau tu cuoi cung
        	res.pop_back(); 
        	cout << "Xau chuan hoa : " << res << endl;
        }

> Output : 

        Xau chuan hoa : Nguyen Van Tech28

# VI. Bài tập ví dụ 
## 1. Bài toán số lớn
![image](https://github.com/minchangggg/DSA/assets/125820144/58b54fc7-3c9e-47fc-9554-a317d478e632)
## 2. Các bài toán liên quan tới tần suất xuất hiện của kí tự trong xâu
### Cách 1: Sử dụng mảng đếm
            #include <bits/stdc++.h>
            using namespace std;
            
            int main(){
                string s = "abcdabcdzzzza";
                int cnt[256] = {0};
                for(char x : s){
                    cnt[x]++;
                }
                for(int i = 0; i < 256; i++){
                    if(cnt[i]) cout << (char)i << ' ' << cnt[i] << endl;
                }
            }

![image](https://github.com/minchangggg/DSA/assets/125820144/83e504d4-87df-4e09-a379-2c75c58be254)
### Cách 2: Sử dụng map

            #include <bits/stdc++.h>
            using namespace std;
            
            int main(){
                string s = "abcdabcdzzzza";
                map<char, int> mp;
                for(char x : s) mp[x]++;
                for(auto it : mp) cout << it.first << ' ' << it.second << endl;
                
            }

![image](https://github.com/minchangggg/DSA/assets/125820144/dd6c92f0-7ec2-4114-bd63-95cdb92f4390)
## 3. String với mảng, vector, set, map:
### a. Sắp xếp các tử trong mảng hoặc vector theo thứ tự từ điển tăng dần, giảm dần
            #include <bits/stdc++.h>
            using namespace std;
            
            int main(){
                string a[] = {"28tech", "dev", "dsa", "c++", "python"};
                sort(a, a + 5);
                for(string x : a) cout << x << ' ';
                
                cout << endl;
            
                vector<string> v = {"28tech", "dev", "dsa", "c++", "python"};
                sort(begin(v), end(v), greater<string>());
                for(string x : v) cout << x << ' ';   
                cout << endl;
                sort(begin(v), end(v), less<string>());
                for(string x : v) cout << x << ' ';  
            }

> Output:

            28tech c++ dev dsa python 
            python dsa dev c++ 28tech 
            28tech c++ dev dsa python 
                        
![image](https://github.com/minchangggg/DSA/assets/125820144/0d030fb9-6625-48bd-be7b-7ba3486420dc)
### b. Lọc ra số lượng từ khác nhau trong mảng
            #include <bits/stdc++.h>
            using namespace std;
            
            int main(){
                string a[] = {"28tech", "dev", "dsa", "c++", "python", "c++", "dev", "Python"};
                set<string> se;
                for(string x : a) se.insert(x);
                
                cout << se.size() << endl;
                for(string x : se) cout << x << ' ';
            }

> Output:

            6
            28tech Python c++ dev dsa python
            
![image](https://github.com/minchangggg/DSA/assets/125820144/40ab6db5-6aa5-42f0-9fee-48e647945b7a)
### Đếm số lần xuất hiện các từ trong mảng
            #include <bits/stdc++.h>
            using namespace std;
            
            int main(){
                string a[] = {"28tech", "dev", "dsa", "c++", "python", "c++", "dev", "Python"};
                map<string, int> mp;
                for(string x : a) mp[x]++;
                
                for(auto it : mp) cout << it.first << ' ' << it.second << endl;
                
            }

> Output:

            28tech 1
            Python 1
            c++ 2
            dev 2
            dsa 1
            python 1

![image](https://github.com/minchangggg/DSA/assets/125820144/aec2cfc2-167c-4872-bc8b-18929973e334)

