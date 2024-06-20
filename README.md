# Độ phức tạp thuật toán (algorithm complexity)
> https://topdev.vn/blog/on-lai-ve-big-o-notation-va-do-phuc-tap/
>
> https://howkteam.vn/course/cau-truc-du-lieu-va-giai-thuat/do-phuc-tap-thoi-gian-bigo-la-gi-4270

Đánh giá một thuật toán
Độ phức tạp về thời gian (time complexity) và độ phức tạp về không gian (space complexity) là 2 yếu tố để quyết định một thuật toán có thích hợp để giải quyết một bài toán nào đó hay không.
Trong đó độ phức tạp về thời gian được quan tâm nhiều hơn khi các bạn tham gia vào các contest về lập trình.
Độ phức tạp thời gian là thời gian mà thuật toán của bạn cần để thực thi, nó là một hàm của input, tức là dựa vào đầu vào ta sẽ tính toán số lượng thao tác mà thuật toán cần thực thi từ đó tính ra được thời gian thực thi của thuật toán.

## I. TÍNH TOÁN ĐỘ PHỨC TẠP VÀ KÍ HIỆU BIG O

![image](https://github.com/minchangggg/DSA/assets/125820144/ba7be9e2-9d28-457c-9f68-d63dd3e8356f)

Ví dụ mô tả độ phức tạp của thuật toán là O(f(n)): O(n), O(1), O(log(n)), O(nlog(n)), O(n2), O(n!)...

![image](https://github.com/minchangggg/DSA/assets/125820144/b7a06d77-1e09-4fd4-a001-30f22c6a85b6)

Trong trường hợp hàm f(n) có chứa hằng số và các bậc khác nhau của n thì ta chọn bậc cao nhất để đại diện cho hàm f(n) => O(n2 +2n +3) được thay bằng O(n2)

![image](https://github.com/minchangggg/DSA/assets/125820144/f0f42eb2-484d-4642-808b-ab38419bbf57)

### 1. Độ phức tạp của các phép toán và nhập xuất là 1 
![image](https://github.com/minchangggg/DSA/assets/125820144/d3cea0f3-213f-4ee4-8d91-230d5b4e71d2)

### 2. Độ phức tạp của vòng lặp chính là số lượng của lặp của vòng lặp nhân với độ phức tạp của code bên trong vòng lặp.

`Các code sau đều có độ phức tạp là O(n)`

![image](https://github.com/minchangggg/DSA/assets/125820144/eaa1dcb2-ddde-4da8-843c-932284a3295c)

`Code sau có độ phức tạp là O(nlogn)`

![image](https://github.com/minchangggg/DSA/assets/125820144/f8e2b1fe-2060-4960-86ee-e6210920a9fc)

  
      a. Một mảng có n phần tử. Hãy tìm phần tử lớn nhất trong mảng
      Bài này tất nhiên chẳng có cách nào khác, bạn sẽ duyệt toàn bộ phần tử trong mảng (duyêt qua mảng n lần) để tìm ra phần tử lớn nhất. Độ phức tạp thuật toán ở đây có thể hiểu là O(n) (chạy qua n phần tử để tìm kiếm)
  
      b. Một mảng có n phần tử. Hãy sắp xếp mảng theo thứ tự tăng dần
      Bài này quá quen nhỉ. Bạn thường dùng 2 vòng lặp từ i->n và từ j->n để đổi chỗ. Lúc này độ phức tạp thuật toán là O(n^2)
      Tuy nhiên với 1 số giải thuật sắp xếp như quicksort, độ phức tạp chỉ là O(n*log(n)). 
      Bạn thử thay n=10, thì giải thuật bên trên có thể hiểu sẽ chạy xấp xỉ là 10*10=100 phép tính, nhưng giải thuật Quicksort thì chỉ dùng khoảng 10 phép tính. Với n rất nhỏ, 100 hay 1000 thì chương trình đều chạy có thời gian xấp xỉ bằng nhau. Thật ra kết quả là có chênh, nhưng quá nhỏ nên các bạn không thấy. Nhưng với n cực lớn, ví dụ 100000 phần tử, thì thuật toán có độ phức tạp O(n^2) với O(nlogn) là cực kì khác biệt.
  
      c. Cho một mảng có n phần tử đã sắp xếp. Hãy tìm xem có phần tử x hay không?
      Bài này nếu các bạn duyệt từ 1 tới n để tìm xem có x hay không, độ phức tạp vẫn là O(n)
      Tuy nhiên nếu để ý, do mảng này là mảng đã sắp xếp, nên bạn có thể áp dụng thuật toán tìm kiếm nhị phân. Tức là bạn chặt dãy ra làm 2, xem X lớn hay nhỏ hơn phần tử ở giữa, nếu nhỏ hơn thì tìm kiếm ở đoạn dưới, nếu lớn hơn thì tìm kiếm ở đoạn trên. Cứ như vậy bạn chặt dãy ra làm 2 liên tục, thì số phép tìm kiếm sẽ là log2 của n, sẽ nhanh hơn nhiều lần so với giải thuật tìm kiếm tuần tự bên trên.

<img width="600" alt="image" src="https://github.com/minchangggg/DSA/assets/125820144/fc57ad2c-c1a3-42a6-8823-c4b525a49511">

### 2. Chọn giải thuật phù hợp
- Như giải thích ở trên, độ phức tạp thuật toán có thể hiểu là số phép toán thực hiện của một hàm dựa trên kích thước tối đa của dữ liệu. Độ phức tạp thuật toán (trên cùng 1 máy) có thể hiểu là nó tỉ lệ thuận (1 cách tương đối) với thời gian chạy.
- Mình xem nhiều bài tập của các bạn thấy các bạn chọn giải thuật không phù hợp dẫn đến thời gian chạy cực lâu. Mình ví dụ nha:
  
      a. Tính tổng các số nguyên từ 1 -> n
      Bài này ai dùng công thức thì 1 dòng là ra: n*(n+1)/2. Giải thuật này có độ phức tạp là O(1) (1 phép toán)
      Với các bạn dùng vòng lặp từ 1 -> n để tính tổng, độ phức tạp là O(n). Với n bằng 1 tỷ, tương đương bạn thực hiện 1 tỷ lần phép toán cộng
      Bạn hiểu thời gian chạy chênh lêch lớn như thế nào rồi chứ?
  
      b. Bài toán kiểm tra số nguyên tố
      Bài này cũng đơn giản thôi. Nhưng nhiều bạn cũng chọn giải thuật phức tạp
      Các bạn chạy để kiểm tra từ 1->n, độ phức tạp là O(n). Các bạn chạy từ 1->sqrt(n) (căn bậc 2 của n) thì đã giảm rất nhiều phép toán, nếu bạn nào còn tăng bước nhảy lên bằng 2 (kiểm tra có chia hết cho 2, 3, 5, 7, 9, 11, ... thay vì 2, 3, 4, 5, 6, ....) thì số phép toán lại giảm thêm nữa.
      Do đó, ngay từ bài số nguyên tố, việc sử dụng vòng lặp để kiểm tra các bạn đã có thể tối ưu cực nhiều. Bạn có thể thử bài này với số n cực lớn và gọi đi gọi lại nhiều lần để đo độ chênh lệch thời gian nha.
  
      c. Bài toán tính tổng các số nguyên tố nhỏ hơn hay bằng n
      Bài này cũng giống bài trên. Độ phức tạp giải thuật của việc kiểm tra số nguyên tố giả sử đang là O(n)
      Nếu với mỗi 1 số từ 1 tới n, bạn lặp lại việc kiểm tra 1 cách thông thường, độ phức tạp thuật toán của giải thuật này là O(n^2)
      Bài này nếu cho n=1000000, đa phần sẽ ko chạy được. Do số phép toán cực nhiều.
      Đối với bài này, nếu bạn dùng sàng nguyên tố (ý tưởng là loại bỏ các hợp số), thì độ phức tạp thuật toán xấp xỉ O(nlogn). Chi tiết tham khảo ở đây nhé.

# Giới thiệu về STL
> https://cpp.daynhauhoc.com/11/0-gioi-thieu-ve-stl/
- Bắt đầu từ chương này trở đi, mình sẽ trình bày với bạn các các đặc trưng chỉ có riêng trong ngôn ngữ C++, hoàn toàn không liên quan gì đến ngôn ngữ C cả. Và đặc trưng đầu tiên mình muốn giới thiệu đến các bạn là bộ thư viện chuẩn (Standard Template Library).
- **Standard Template Library** là một tập hợp các lớp (classes) cung cấp cho lập trình viên những khuôn mẫu về tổ chức dữ liệu, thuật toán, bộ lặp. Nó cung cấp rất nhiều thuật toán cơ bản và cấu trúc dữ liệu cơ bản trong ngành khoa học máy tính.
- Standard Template Library cũng chỉ là một phần của C++ Standard Library, nó có thêm từ Template vì hầu hết các class trong tập thư viện này đều được định nghĩa dạng tổng quát (generic) với từ khóa template. Mình vẫn chưa đề cập đến khái niệm về template cho các bạn, tuy nhiên, chúng ta vẫn có thể tiếp cận các bài học trong chương này ở mức độ thực hành nên các bạn có thể yên tâm. Trong chương này, chúng ta sẽ tìm hiểu cách sử dụng các class trong Standard Template Library và các chức năng của chúng. Khi học đến bài học về template trong C++, các bạn sẽ hiểu được tại sao các class trong STL lại được khai báo như vậy.
- Như mình trình bày về khái niệm STL ở trên, chúng ta có thể chia STL thành 3 phần:
  
![image](https://github.com/minchangggg/DSA/assets/125820144/fae07bbb-ff00-4f47-be4e-09c0ea944624)

- Mỗi thành phần của STL đảm nhiệm một số chức năng có liên quan đến nhau. Trong mỗi bài học tiếp theo, chúng ta sẽ tìm hiểu từng thành phần cụ thể của STL.
- Một đặc điểm chung của các thành phần này là chúng đều được xây dựng sẵn, chúng ta không cần định nghĩa lại mà chỉ cần sử dụng trong chương trình.

## I. STL containers
- Trong bài học này, mình sẽ hướng dẫn các bạn cách sử dụng một số container class của STL. Trước các bài học trước đây, mình đã từng giới thiệu đến các bạn một class thuộc STL, đó là std::array (trong chương mảng một chiều) hay là std::string trong chương mảng kí tự. std::array thư viện khá đơn giản có thể dùng để thay thế cho mảng một chiều.
- Tuy nhiên, nhược điểm của std::array (cũng là nhược điểm của mảng một chiều) là kích thước bộ nhớ được cấp phát là cố định. Do đó, khả năng khai báo thiếu số lượng phần tử hoặc dư thừa quá mức cần thiết thường xuyên xảy ra. Để khắc phục nhược điểm này, STL đã hổ trợ cho chúng ta các container class khác dùng để lưu trữ, xử lý các phần tử với kích thước vùng nhớ tự động thay đổi để phù hợp với yêu cầu người dùng.
- Trước khi đi vào tìm hiểu các container class của STL, chúng ta nên phân chúng ra thành 3 loại container khác nhau:
  + **Sequence container**
    
        - Sequence container là tập hợp các container class nó duy trì trật tự của các phần tử bên trong container. Một đặc tính của Sequence container là các bạn có thể chọn ví trí muốn chèn thêm phần tử vào container. Một ví dụ điển hình là khi các bạn thêm một phần tử vào mảng một chiều, các phần tử còn lại vẫn giữ nguyên thứ tự của chúng như trước khi chèn.
        - Ngôn ngữ C++11 cung cấp cho chúng ta 6 sequence containers: std::vector, std::deque, std::array, std::list, std::forward_list, std::basic_string.

  + **Associative container**

        - Associative container là các container được thiết kế kèm theo cơ chế tự động sắp xếp dữ liệu đầu vào khi chúng được đưa vào container. Cơ chế tổ chức dữ liệu của các container này sẽ quyết định vị trí của các phần tử trong container. Thông thường, associative container thực hiện phép so sánh sử dụng toán tử <.
        - Một số associative container được sử dụng phổ biến là: std::set, std::map...
  
  + **Container adapter** 

        - Container adapter là các container được sử dụng cho các cấu trúc lưu trữ đặc biệt: std::stack, std::queue, ...

### 1. Sequence container
### a. std::vector
Cũng giống như std::array, vectors lưu trữ các phần tử liên tiếp nhau trên bộ nhớ ảo. Điều này có nghĩa những phần tử trong std::vector có thể truy cập thông qua các con trỏ có cùng kiểu dữ liệu với kiểu của std::vector. Đặc điểm khiến std::vector khác với std::array là nó có thể thay đổi kích thước container tự động khi các phương thức, các toán tử được định nghĩa bên trong class std::vector được sử dụng.

Khai báo một std::vector
Để sử dụng std::vector, chúng ta cần include thư viện vector vào file chương trình. Dưới đây là cú pháp khai báo cơ bản để tạo ra một đối tượng từ lớp std::vector:

std::vector< <data_type> > <vector_name>;
data_type của vector là một kiểu dữ liệu tổng quát, các bạn có thể chọn tùy ý dựa vào mục đích lưu trữ của chương trình, nó có thể là một kiểu dữ liệu built-in, cũng có thể là kiểu dữ liệu struct do các bạn tự định nghĩa ra. Mình lấy một ví dụ như sau:

#include <vector>

std::vector<__int32> vecInt32;
Như vậy là chúng ta đã có một đối tượng của lớp std::vector có thể lưu trữ các phần tử kiểu __int32 trong container. Lúc này, container của vecInt32 vẫn chưa có phần tử nào cả, chúng ta có thể kiểm chứng bằng cách sử dụng phương thức std::vector::size() để kiểm tra kích thước của container.

std::cout << "Size of vecInt32: " << vecInt32.size() << std::endl;
Kết quả cho ra màn hình là 0 (tương ứng với 0 phần tử hiện tại có trong container của vecInt32).

Một số phương thức khởi tạo cho đối tượng của lớp std::vector
Sau này khi học đến phần C++ Object oriented programming, các bạn sẽ biết rằng một class có thể có một hoặc nhiều phương thức khởi tạo giá trị cho các thành phần dữ liệu bên trong class đó. Class std::vector có đến hơn 10 phương thức khởi tạo khác nhau:

Tuy nhiên, mình chỉ hướng dẫn các bạn sử dụng một số phương thức khởi tạo đơn giản. Ví dụ:

std::vector<__int32> vec1(); //gọi phương thức khởi tạo mặc định, khởi tạo kích thước container là 0.

std::vector<__int32> vec2(5); //gọi phương thức khởi tạo std::vector(size_t _Count) với giá trị truyền vào là 5, khởi tạo kích thước container là 5 phần tử kiểu __int32.

std::vector<__int32> vec3(vec2); //gọi phương thức khởi tạo std::vector(const std::vector &other), khởi tạo một container giống với container của vector other.
Những phương thức khởi tạo còn lại thường ít được sử dụng.

Sử dụng các phương thức trong class std::vector
Sau khi các bạn khai báo (có thể có khởi tạo hoặc không) một đối tượng của lớp std::vector, lúc này chúng ta có thể sử dụng các phương thức (các hàm bên trong lớp) trong lớp std::vector để thao tác với container của đối tượng đó.

Modifiers
std::vector::push_back(const vector_type &value)
Khi mình viết std::vector::push_back, các bạn có thể hiểu phương thức push_back được định nghĩa bên trong khối lệnh có tên vector, và vector được định nghĩa bên trong khối lệnh của std.

Phương thức này cho phép thêm một phần tử vào sau phần tử có vị trí cuối cùng trong container, phần tử mới được thêm vào sẽ trở thành phần tử có chỉ số cao nhất trong container. Ví dụ:

std::vector<__int32> vecInt32;
for (int i = 1; i <= 10; i++)
{
    vecInt32.push_back(i);
}
Mỗi lần sử dụng phương thức push_back, kích thước của container sẽ tăng lên 1. Nếu số phần tử vượt quá kích thước của container, vector sẽ tự động cấp phát lại vùng nhớ đủ để chứa tất cả các phần tử.

std::vector::pop_back()
Gọi phương thức này sẽ xóa đi một phần tử tại chỉ số cuối cùng trong container. Ví dụ:

std::vector<__int32> vecInt32;

for (int i = 1; i <= 10; i++) {
	vecInt32.push_back(i);
}
//container = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }

vecInt32.pop_back();
//container = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }
Nếu các bạn sử dụng phương thức này khi container của vector rỗng, Visual studio (trong chế độ Debug) sẽ thông báo chương trình vi phạm điều kiện của assertion trong phương thức pop_back.



std::vector::insert
Để sử dụng phương này, chúng ta cần sử dụng thêm STL Iterator, đến bài học về STL Iterator mình sẽ trình bày rõ hơn về phương thức này. Các bạn có thể hiểu đơn giản là một iterator cũng là một con trỏ, nó trỏ vào container của std::vector giúp phương thức insert xác định được vị trí cần chèn phần tử.

std::vector<__int32> vecInt32;
std::vector<__int32>::iterator iter;

//iter point to the begin of vecInt32
iter = vecInt32.begin();

//insert new element into vecInt32's container
vecInt32.insert(iter, 10);

//container = { 10 }

iter = vecInt32.end();
vecInt32.insert(iter, 20);

//container = { 10, 20 }

iter = vecInt32.begin() + 1;
vecInt32.insert(iter, 15);

//container = { 10, 15, 20 }
Kích thước của container sẽ tự động thay đổi đủ để chứa tất cả các phần tử sau khi insert.

std::vector::erase(const_iterator position)
Phương thức này cho phép xóa một phần tử tại vị trí được trỏ đến bởi iterator position. Ví dụ:

std::vector<int> myvector;

// set some values (from 1 to 10)
for (int i=1; i<=10; i++) 
	myvector.push_back(i);

// erase the 6th element
myvector.erase (myvector.begin()+5);

//container = { 1, 2, 3, 4, 5, 7, 8, 9, 10 }
Element access
operator[size_type index]
Sử dụng toán tử [] cho vector sẽ trả về giá trị tại chỉ số index được truyền vào (Tương tự mảng một chiều).

std::vector<int> myvector(10); //10 zero-initialized elements

for (int i = 0; i < myvector.size(); i++)
	myvector[i] = i;
	
std::cout << myvector[4] << std::endl;
Các bạn lưu ý chỉ số bắt đầu của container cũng là 0 giống với mảng một chiều.

std::vector::at(size_type index)
Tương tự operator[].

std::vector<int> myvector(10); //10 zero-initialized elements

for (int i = 0; i < myvector.size(); i++)
	myvector[i] = i;
	
std::cout << myvector.at(4) << std::endl;
Capacity
std::vector::size()
Phương thức size trả về số lượng phần tử chứa trong container của vector.

std::vector<int> myints;
std::cout << "0. size: " << myints.size() << std::endl;

for (int i=0; i<10; i++) 
	myints.push_back(i);
	
std::cout << "1. size: " << myints.size() << std::endl;
std::vector::max_size()
Trả về số lượng phần tử tối đa mà vector có thể chứa, đồng nghĩa với kích thước vùng nhớ tối đa có thể cấp phát cho container của vector.

std::vector<int> myvector;

// set some content in the vector
for (int i = 0; i<100; i++) 
	myvector.push_back(i);

std::cout << "size: " << myvector.size() << std::endl;
std::cout << "max_size: " << myvector.max_size() << std::endl;
std::vector::capacity()
Trả về kích thước bộ nhớ đã cấp phát cho container của vector.

std::vector<int> myvector;

// set some content in the vector
for (int i = 0; i<100; i++) 
	myvector.push_back(i);

std::cout << "size: " << myvector.size() << std::endl;
std::cout << "capacity: " << (int)myvector.capacity() << std::endl;
Kích thước vùng nhớ được cấp phát cho container thường sẽ lớn hơn số lượng phần tử mà container đang chứa. Điều này đảm bảo khi người dùng thêm phần tử vào container, vector sẽ chưa cần tốn chi phí cấp phát lại vùng nhớ mới.

Mình vừa trình bày một số phương thức đơn giản thường được sử dụng của class std::vector. Các bạn có thể tự mình tìm hiểu các phương thức khác của class std::vector qua đường dẫn sau:

http://www.cplusplus.com/reference/vector/vector/

std::list
std::list containers mô phỏng lại cấu trúc dữ liệu doubly-linked lists; Doubly-linked list có thể lưu trữ các phần tử không liên tiếp nhau trên vùng nhớ nhưng vẫn đảm bảo được thứ tự của các phần tử khi truy xuất. Trật tự của các phần tử được giữ bởi những sự kết nối giữa các cặp phần tử.

Cấu trúc dữ liệu doubly-linked list cho phép người dùng thêm và xóa phần tử tại vị trí bất kỳ trong container, nhưng không hổ trợ truy cập ngẫu nhiên.

Khai báo một std::list
Để sử dụng std::list, chúng ta cần include thư viện list vào file chương trình. Dưới đây là cú pháp khai báo một đối tượng của lớp std::list:

std::list< <data_type> > list_name;
Trong ví dụ dưới đây mình tạo ra một std::list dùng để lưu trữ các phần tử số nguyên:

#include <list>

std::list<__int32> my_list;
Khởi tạo đối tượng của lớp std::list
Cũng tương tự như class std::vector, std::list cũng có một số phương thức khởi tạo riêng. Một số phương thức khởi tạo thường dùng như:

std::list<__int32> list1(); //gọi default constructor

std::list<__int32> list2(5); //gọi phương thức khởi tạo list(size_t _Count), khởi tạo danh sách có _Count phần tử

std::list<__int32> list3(list2); //gọi phương thức khởi tạo list(const list_type &other), khởi tạo danh sách có container giống với other
Sử dụng các phương thức của lớp std::list
Capacity
(Tương tự std::vector)

Element access
Đối với cấu trúc dữ liệu doubly-linked list, chúng ta chỉ có thể truy xuất giá trị ở vị trí đầu tiên và cuối cùng trong container, std::list hỗ trợ cho chúng ta 2 phương thức truy xuất.

std::list::front()
Phương thức trả về giá trị của phần tử đầu tiên trong list container.

std::list<__int32> my_list(5);
std::cout << my_list.front() << std::endl;
std::list::back()
Ngược lại với phương thức ở trên, phương thức back trả về giá trị của phần tử cuối cùng trong list container.

std::list<__int32> my_list(5);
std::cout << my_list.back() << std::endl;
Modifiers
std::list::push_back(const list_type &value)
Phương thức này cho phép thêm một phần tử vào sau phần tử có vị trí cuối cùng trong container, phần tử mới được thêm vào sẽ trở thành phần tử có chỉ số cao nhất trong container. Ví dụ:

std::list<int> mylist;
int myint;

std::cout << "Please enter some integers (enter 0 to end):" << std::endl;

do 
{
	std::cin >> myint;
	mylist.push_back (myint);
} while (myint);

std::cout << "mylist stores " << mylist.size() << " numbers." << std::endl;
std::list::pop_back()
Xóa một phần tử cuối cùng trong list container. Ví dụ:

std::list<int> mylist;
int sum (0);
mylist.push_back (100);
mylist.push_back (200);
mylist.push_back (300);

while (!mylist.empty())
{
	sum+=mylist.back();
	mylist.pop_back();
}

std::cout << "The elements of mylist summed " << sum << std::endl;
Phương thức std::list::empty() dùng để kiểm tra container của list có rỗng hay không, nếu số phần tử của list khác 0 thì trả về false, ngược lại trả về true. (Các class containers của STL đều có phương thức này).

std::list::push_front(const list_type &value)
Ngược lại với phương thức std::list::push_back, phương thức này dùng để thêm một phần tử có cùng kiểu với list vào vị trí đầu tiên trong container.

std::list<int> mylist;
mylist.push_front (200);
mylist.push_front (300);

//container = { 300, 200 }
std::list::pop_front()
Xóa một phần tử trong list container tại vị trí đầu tiên.

std::list<int> mylist;
mylist.push_back (100);
mylist.push_back (200);
mylist.push_back (300);

std::cout << "Popping out the elements in mylist: ";
while (!mylist.empty())
{
std::cout << ' ' << mylist.front();
mylist.pop_front();
}

std::cout << std::endl;
std::cout << "Final size of mylist is " << mylist.size() << std::endl;
Operations
std::list::sort()
Phương thức này sẽ sắp xếp lại dữ liệu bên trong container theo thứ tự tăng dần (mặc định là vậy).

std::list<__int32> my_list;
std::list<__int32>::iterator iter;
my_list.push_back(4);
my_list.push_back(6);
my_list.push_back(-2);
my_list.push_back(-1);
my_list.push_back(7);

//container = { 4, 6, -2, -1, 7 }

my_list.sort();

//container = { -2, -1, 4, 6, 7 }
Các bạn cũng có thể thay đổi điều kiện so sánh của phương thức sort bằng cách tự tạo một hàm so sánh 2 phần tử cùng kiểu dữ liệu với list. Ví dụ:

bool my_comparison(__int32 n1, __int32 n2)
{
	return n2 < n1;
}

int main()
{
	std::list<__int32> my_list;
	std::list<__int32>::iterator iter;
	my_list.push_back(4);
	my_list.push_back(6);
	my_list.push_back(-2);
	my_list.push_back(-1);
	my_list.push_back(7);
	
	//container = { 4, 6, -2, -1, 7 }

	my_list.sort(my_comparison);

	//container = { 7, 6, 4, -1, -2 }
	
	return 0;
}
Mình vừa liệt kê ra một vài phương thức thường dùng khi sử dụng std::list. Các bạn có thể tìm hiểu thêm một số phương thức khác của std::list tại đường dẫn

http://www.cplusplus.com/reference/list/list/

Vậy là mình đã cùng các bạn tìm hiểu 2 sequence container trong bộ thư viện STL của ngôn ngữ C++. Do giới hạn thời gian và để đảm bảo hiệu suất của khóa học, các container tiếp theo mình sẽ đưa đường dẫn để các bạn tự tìm hiểu các phương thức trong từng class container. Cách tự tìm hiểu cũng giống như mình làm cùng các bạn ở trên.

Associative container
std::set
std::set là class định nghĩa của một dạng container chỉ cho phép lưu trữ các phần tử có giá trị là duy nhất, phần tử có giá trị trùng lặp là không được cho phép. Những phần tử được thêm vào container sẽ được tự động sắp xếp dựa trên giá trị của chúng.

[](http://www.cplusplus.com/reference/set/set/)

Dưới đây là một đoạn chương trình mẫu sử dụng std::set

#include <iostream>
#include <set>

int main ()
{
	std::set<int> myset;
	std::set<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; i++) 
		myset.insert(i*10);    // set: 10 20 30 40 50

	it = myset.find(20);
	myset.erase (it);
	myset.erase (myset.find(40));

	std::cout << "myset contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	return 0;
}
std::map
std::map là class định nghĩa một loại container dùng để lưu trữ các phần tử theo cấu trúc kết hợp (key_value, mapped_value). Dữ liệu trong container được sắp xếp dựa trên key_value, do đó key_value không được trùng lặp. Với mỗi key_value sẽ ánh xạ đến một mapped_value duy nhất.

http://www.cplusplus.com/reference/map/map/

Các bạn lưu ý khi sử dụng std::map, mỗi khi thêm phần tử vào container thì phải thêm đủ một cặp giá trị . Ngôn ngữ C++ cung cấp cho chúng ta class std::pair giúp chúng ta nhóm 2 đối tượng có cùng (hoặc khác) kiểu dữ liệu thành một cặp tương ứng với cặp của std::map.

std::pair< data_type, data_type > pair_name;
Một ví dụ về sử dung std::map để quản lý thông tin nhân viên:

#include <iostream>
#include <string>
#include <map>

struct Employee
{
	std::string name;
	__int32 year_of_experience;
};

int main()
{
	std::map<__int32, Employee> listEmployee;

	listEmployee.insert(std::pair<__int32, Employee>(1, { "Le Tran Dat", 5 }));
	listEmployee.insert(std::pair<__int32, Employee>(2, { "Someone", 0 }));

	listEmployee[4] = { "new employee", 1 }; //operator[<key>] = <value>

	std::map<__int32, Employee>::iterator iter = listEmployee.find(3);
	if (iter != listEmployee.end())
	{
		std::cout << "Employee ID:        " << iter->first << std::endl;
		std::cout << "Employee name:      " << (iter->second).name << std::endl;
		std::cout << "Year of experience: " << (iter->second).year_of_experience << std::endl;
	}
	else
	{
		std::cout << "ID 3 is not exist" << std::endl;
	}

	return 0;
}
Container adapter
std::stack
Stack (hay còn gọi là ngăn xếp) là một dạng container có cơ chế tổ chức lưu trữ dữ liệu đặc biệt: LIFO (Last In First Out).



Phần tử được thêm vào sau cùng sẽ được lấy ra đầu tiên.

http://www.cplusplus.com/reference/stack/stack/

Dưới đây là một ví dụ ứng dụng cách tổ chức lưu trữ của cấu trúc dữ liệu Stack để chuyển đổi một số từ hệ thập phân sang hệ nhị phân:

#include <iostream>
#include <stack>

int main()
{
	//input
	__int32 decNumber;
	std::cin >> decNumber;

	//converting
	std::stack<bool> binary;
	while (decNumber)
	{
		binary.push((decNumber % 2 == 1));
		decNumber /= 2;
	}

	//output
	while (!binary.empty())
	{
		std::cout << binary.top();
		binary.pop(); //remove an element of stack
	}
	std::cout << std::endl;

	return 0;
}
Cấu trúc dữ liệu Stack còn có nhiều ứng dụng thực tiễn, ví dụ tạo ra chuỗi trạng thái cho phép người dùng trở lại trạng thái trước đó (undo).

std::queue
Queue (hay còn gọi là hàng đợi) là một cấu trúc dữ liệu hoạt động ngược lại so với cấu trúc dữ liệu Stack: FIFO (First In First Out). Chúng ta gặp cấu trúc dữ liệu này khá nhiều trong thực tế, ví dụ xếp hàng chờ mua hàng, người nào đến trước sẽ được mua hàng trước và ra khỏi hàng chờ sớm nhất.

http://www.cplusplus.com/reference/queue/queue/

Dưới đây là một ví dụ sử dụng std::queue:

#include <iostream>      
#include <queue>         

int main()
{
	std::queue<int> myqueue;
	int myint;

	std::cout << "Please enter some integers (enter 0 to end):" << std::endl;

	do {
		std::cin >> myint;
		myqueue.push(myint);
	} while (myint);

	std::cout << "myqueue contains: ";
	while (!myqueue.empty())
	{
		std::cout << ' ' << myqueue.front();
		myqueue.pop();
	}
	std::cout << std::endl;

	return 0;
}
Tổng kết
Trong bài học này, mình đã hướng dẫn các bạn sử dụng một số class container thuộc Standard Template Library (STL) và cách để tự tìm hiểu cách sử dụng chúng. Về mặt cơ bản, các class container chỉ là một tập các thư viện thực thi các cấu trúc dữ liệu thường sử dụng trong lập trình. Cấu trúc dữ liệu là cách thức tổ chức, định dạng dữ liệu trong bộ nhớ máy tính. Chọn đúng cấu trúc dữ liệu cho một bài toán nào đó có thể giúp lập trình viên giải quyết vấn đề dễ dàng hơn.

Hẹn gặp lại các bạn trong bài học tiếp theo trong khóa học lập trình C++ hướng thực hành.

Mọi ý kiến đóng góp hoặc thắc mắc có thể đặt câu hỏi trực tiếp tại diễn đàn

www.daynhauhoc.com

## 2. STL iterators

## 3. STL algorithms
