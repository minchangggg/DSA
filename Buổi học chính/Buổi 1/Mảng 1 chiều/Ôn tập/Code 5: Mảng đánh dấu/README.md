# Lý Thuyết Mảng Đánh Dấu

## Bài Toán : Cho mảng A[] gồm N phần tử là các số nguyên trong đoạn [0, 10^6]. Hãy đếm các giá trị khác nhau trong mảng ? 
- Để giải quyết bài toán trên bạn có thể dùng 1 mảng đánh dấu đủ lớn để đánh dấu sự xuất các giá trị trong mảng, vì các phần tử trong mảng đều nằm trong đoạn từ [0, 10^6] nên chỉ cần dùng một mảng số nguyên mà chỉ số của nó có thể đánh dấu được hết các giá trị [0, 106] là giải quyết được bài toán.
- Ý tưởng ở đây đó là bạn sẽ sử dụng chỉ số của mảng đánh dấu để đánh dấu giá trị tương ứng với chỉ số đó đã xuất hiện trong mảng. Ban đầu tất cả các phần tử trong mảng đánh dấu có giá trị là 0, khi bạn gặp một giá trị trong mảng thì sẽ chuyển phần tử trong mảng đánh dấu tại chỉ số đó thành 1.
- Ví dụ mảng đánh dấu là mark[] và khi gặp phần tử trong mảng A[] là 3 thì mark[3] = 1
- Sau khi đánh dấu xong các giá trị xuất hiện thì bạn chỉ cần duyệt mảng đánh dấu và xem phần tử nào trong mảng đánh dấu có giá trị là 1 để đếm hoặc liệt kê.

Code 

      #include <iostream>
      #include <math.h>
      using namespace std;
      
      int mark[1000001]; //Chỉ số của mark là từ 0 tới 10^6, ban đầu toàn bộ mảng mark[] = 0
      
      int main(){
          int n = 8;
          int a[8] = {3, 1, 3, 0, 2, 4, 1, 6};
          
          //đánh dấu
          for(int i = 0; i < n; i++)
              mark[a[i]] = 1; //Lấy a[i] làm chỉ số và chuyển mark[a[i]] = 1
          }
          
          int dem = 0;
          //Bạn có thể duyệt từ i = 0 tới giá trị max trong mảng cũng được
          for(int i = 0; i <= 1000000; i++){
              if(mark[i] == 1){
                  ++dem;
              }
          }
          cout << "So luong phan tu khac nhau : " << dem << endl;
          return 0;
      }

Output : 

> So luong phan tu khac nhau : 6

# Chú ý khi sử dụng mảng đánh dấu

- Mảng đánh dấu không thể sử dụng được với số âm, vì chỉ số trong mảng không thể là số âm
- Mảng đánh dấu không sử dụng được khi giá trị cần đánh dấu vượt chỉ số của mảng mà bạn có thể khai báo
- Thông thường bạn chỉ áp dụng được kỹ thuật này khi các phần tử trong mảng có giá trị trong đoạn [0, 107]
- Chú ý sử dụng mảng đánh dấu đủ lớn để không lỗi bộ nhớ, ví dụ bạn cần đánh dấu các phần tử trong đoạn [0, 103] thì mảng cỡ 1001 là đủ rồi, hoặc có thể lớn hơn
