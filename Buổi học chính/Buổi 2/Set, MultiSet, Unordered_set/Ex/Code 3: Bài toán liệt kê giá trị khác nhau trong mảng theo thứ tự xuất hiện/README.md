## Cho dãy A[] gồm n phần tử, liệt kê các giá trị xuất hiện trong dãy theo thứ tự xuất hiện, mỗi giá trị chỉ xuất hiện 1 lần
- Giải thuật : Duyệt qua mảng và duy trì set như 1 tập hợp các giá trị đã được in ra trước đó, khi gặp phần tử trong mảng bạn kiểm tra nếu chưa xuất hiện trong set thì sẽ in ra và đưa giá trị này vào set. Việc dùng set sẽ giúp bạn tìm kiếm nhanh hơn những giá trị đã được in ra.
- Độ phức tạp : O(NlogN)
  
`Input Format`

Dòng đầu tiên là số nguyên N. 

Dòng tiếp theo gồm N số nguyên A[i]

`Constraints`

1≤ N ≤ 10^5; 0 ≤ A[i], X ≤ 10^9;

`Output Format`

In ra số lượng phần tử khác nhau trong mảng.

`Sample Input 0`

8 
3 2 1 3 2 1 4 4 

`Sample Output 0`

3 2 1 4 

![image](https://github.com/minchangggg/DSA/assets/125820144/514e35a4-b59d-4c07-b3ca-5f838e6e6438)
