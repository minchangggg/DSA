## Tổng lớn nhất
- Tèo đang làm ác bài toán với truy vấn tổng trên đoạn, mỗi truy vấn yêu cầu các bạn tính tổng các phần tử từ chỉ số L tới chỉ số R, tuy nhiên bài toán này đã quá quen thuộc và dễ dàng có thể dùng mảng cộng dồn để giải quyết vì thế Tèo đưa ra thêm 1 yêu cầu cho bài toán.
- Cho trước các truy vấn tổng từ chỉ số L tới chỉ số R, bây giờ bạn đã biết trước tất cả Q truy vấn bạn được phép thay đổi thứ tự các phần tử trong mảng 1 lần duy nhất trước khi thực hiện các truy vấn. Hãy thay đổi mảng sao cho tổng các truy vấn trên đoạn đạt được giá trị lớn nhất. Một cách rõ ràng hơn, bạn hãy tính tổng mọi mảng con trong từng truy vấn sau đó cộng lại để đạt giá trị lớn nhất.

`Input Format`

Dòng 1 là N và Q

Dòng 2 là N phần tử trong mảng A[]

Q dòng tiếp theo mỗi dòng là 2 số L, R

`Contraints`

1 <= N,Q <= 2.10^5

1 <= A[i] <= 10^5

0 <= L <= R <= N

`Output Format`

In ra tổng lớn nhất có thể đạt được

`Sample Input 0`

6 2

5 2 5 3 5 1

2 5

2 4  

`Sample Output 0`

33
