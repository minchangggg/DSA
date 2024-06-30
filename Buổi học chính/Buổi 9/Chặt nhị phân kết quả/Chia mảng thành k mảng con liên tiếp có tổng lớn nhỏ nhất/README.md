## Chia mảng thành k mảng con liên tiếp có tổng lớn nhỏ nhất
Bạn được cung cấp một mảng chứa n số nguyên dương. Nhiệm vụ của bạn là chia mảng thành k mảng con liên tiếp sao cho tổng lớn nhất trong một mảng con càng nhỏ càng tốt.
(Gợi ý sử dụng binary search on answer. Binary search trên tổng lớn nhất của một mảng)

`Input Format`

Dòng đầu tiên chứa 2 số nguyên n và k: kích thước của mảng và số mảng con trong phép chia.

Dòng tiếp theo chứa n số nguyên x1, x2, ... xn: phần tử của mảng 

`Constraints`

1 <= n <= 2.10^5; 1 <= k <= n; 1 <= xi <= 10^9

`Output Format`

In một số nguyên: tổng lớn nhất trong một mảng con trong phép chia tối ưu.

`Sample Input 0`

5 3

2 4 7 3 5

`Sample Output 0`

8
