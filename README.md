<img width="700" alt="image" src="https://github.com/minchangggg/DSA/assets/125820144/0b4ceb55-8ed5-4ad1-976b-d6158d9d9402">

> https://www.geeksforgeeks.org/learn-data-structures-and-algorithms-dsa-tutorial/?ref=lbp#dsa-full-form

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
