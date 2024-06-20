## Cho mảng A[] gồm N phần tử, hãy dịch các phần tử trong mảng sang trái K vị trí, khi dịch trái thì phần tử đầu tiên của dãy sẽ xoay vòng trở thành phần tử cuối cùng.

    VD: Mảng ban đầu là 1 2 3 4 5
    - Dịch trái xoay vòng 1 lần => 2 3 4 5 1
    - Dịch trái xoay vòng 2 lần => 3 4 5 1 2
    - Dịch trái xoay vòng 3 lần => 4 5 1 2 3
    - Dịch trái xoay vòng 4 lần => 5 1 2 3 4
    - Dịch trái xoay vòng 5 lần => 1 2 3 4 5
    - Dịch trái xoay vòng 6 lần => trở về giống như dịch trái xoay vòng 1 lần
    - Dịch trái xoay vòng 7 lần => trở về giống như dịch trái xoay vòng 2 lần

`Input Format`

    Dòng đầu tiên là số nguyên dương N; Dòng thứ 2 gồm N số nguyên viết cách nhau một vài khoảng trắng; 
    Dòng thứ 3 là số nguyên K

`Constraints`

    1 <= N <= 1000; 
    1 <= K <= 1000; 
    0 <= A[i] <= 100

`Output Format`

    In ra mảng sau khi xoay trái

`Sample Input 0`

    8 6
    16 66 96 73 11 13 99 82

`Sample Output 0`
  
    99 82 16 66 96 73 11 13
