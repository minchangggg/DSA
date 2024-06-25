> https://trieutuanhiep.blogspot.com/2015/08/thuat-toan-phuong-phap-sinh-generation.html

# ( GENERATION )
## Phương pháp sinh dùng để làm gì ?
- mình cũng sẽ ví dụ luôn cho dễ hiểu. với dữ liệu đề như trên, nếu mình muốn liệt kê tất cả các chỉnh hợp không lặp chập 5 của X ( hay gọi là liệt kê tất cả các cấu hình của bài toán) thì phải làm như thế nào ?
- chày cối đếm tay và viết vào máy ? :D điều này có thể thực hiện nếu chỉ có ít phần tử chứ cho liệt kê mà tập có 30 phần tử thì nổ não :D
- vậy cách giải quyết ví dụ là gì ? câu trả lời là phương pháp sinh.
## vậy mục đích của phương pháp sinh là gì ? 
- phương pháp sinh dùng có thể áp dụng để giải bài toán liệt kê tổ hợp, hay nói cách khác là liệt kê các cấu hình của bài toán.
## phương pháp sinh hoạt động như thế nào ?
- rất đơn giản, nó sẽ "đẻ" ra các cấu hình tiếp theo từ các cấu hình trước đó cho đến khi nào hết nghiệm thì thôi. :D
- ví dụ: trong ví dụ trên, từ cấu hình 123456 PPS sẽ đẻ ra tiếp cấu hình 23456 cho đến khi hết nghiệm của bài toán
## điều kiện để áp dụng được phương pháp sinh : 
- có 2 điều kiện để sử dụng được phương pháp sinh :
  + Xác định được trật tự các nghiệm. Biết được nghiệm đầu và nghiệm cuối cùng.
  + Xây dựng được thuật toán từ một nghiệm (cấu hình) chưa phải là nghiệm cuối cùng ta đều sinh ra một cấu hình đứng sau nó.
- cấu trúc của thuật toán sinh như sau :

        while(chưa phải là cấu hình cuối cùng){
         <đưa ra cấu hình hiện tại>;
         <sinh cấu hình kế tiếp>;
        }
