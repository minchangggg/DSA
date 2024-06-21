> https://hackmd.io/@2SchoolGuideline/H1HY_VKbp#M%E1%BA%A3ng-c%E1%BB%99ng-d%E1%BB%93n-v%C3%A0-m%E1%BA%A3ng-hi%E1%BB%87u-Prefix-sum-array-and-difference-array

![image](https://github.com/minchangggg/DSA/assets/125820144/33900f9e-bbe9-40ea-847c-d1176abe2d6e)
# Mảng cộng dồn - Prefix sum array
Mảng cộng dồn (tiền tố) là một mảng giúp các bạn có thể nhanh chóng tính toán tổng các phần tử trong các đoạn liên tiếp từ chỉ số left tới chỉ số right.

## 1. Mảng cộng dồn trên mảng một chiều
### a. Bài toán ví dụ

![image](https://github.com/minchangggg/DSA/assets/125820144/925e04f3-ddda-40bf-b66a-7d2ab5a33928)

`Input mẫu:`

6

0 2 0 9 1 9 4 5

3

1 4

2 5

6 6

`Output mẫu:`

11

12

5

### b. Cách tiếp cận 1: Duyệt trâu
- Ta sử dụng thuật toán duyệt trâu (hay còn gọi là vét cạn): duyệt từ vị trí 𝑙 đến vị trí 𝑟 để tính 𝑆 cho mỗi truy vấn và in ra kết quả.

![image](https://github.com/minchangggg/DSA/assets/125820144/cb1ddd56-2b9a-4c12-b863-4d080b6f98e7)

- Độ phức tạp của thuật toán: Với mỗi truy vấn trong 𝑄 truy vấn, ta duyệt qua mảng 1 chiều 𝐴 kích thước 𝑁, từ đó có độ phức tạp của thuật toán là 𝑂 (𝑁×𝑄).     
- Ta có thể thấy với độ phức tạp trên thì sẽ không thể giải quyết bài toán trong giới hạn thời gian của đề bài, vì vậy cần tìm cách giải tối ưu hơn.
- Gợi ý: Bằng cách tính một số tổng của các phần tử trong 𝐴, ta có thể sử dụng mối liên hệ về mặt toán học của các tổng đó để nhanh chóng tính toán tổng 𝑆 trong mỗi truy vấn, các tổng này liên quan đến vị trí của các phần tử trong 𝐴 cũng như 𝑙 và 𝑟.

### c. Cách tiếp cận 2: Mảng cộng dồn 1 chiều
`Xây dựng mảng cộng dồn 1 chiều`

![image](https://github.com/minchangggg/DSA/assets/125820144/142bc5ae-b415-4f90-898e-ac4071625065)

`Sử dụng mảng cộng dồn 1 chiều để tính truy vấn`

![image](https://github.com/minchangggg/DSA/assets/125820144/6fece820-308c-40fd-a39e-3287f11c6a7b)

`Độ phức tạp của thuật toán` 

Đầu tiên ta tính giá trị của mảng 1 chiều 𝑝𝑟𝑒[i] kích thước 𝑁 trong 𝑂(𝑁) và sau đó với 𝑄 truy vấn ta tính mỗi truy vấn trong 𝑂(1), từ đó có độ phức tạp của thuật toán là 𝑂(𝑁+𝑄) .

### d. Code 
Cho một dãy số A gồm 𝑛 phần tử 𝑎1, 𝑎2, … , 𝑎𝑛. Cần trả lời 𝑄 truy vấn, mỗi truy vấn có dạng (l,r), yêu cầu đưa ra tổng của các số có vị trí thuộc đoạn [l,r] của dãy số.

`Input Format`

Dòng đầu tiên chứa hai số nguyên dương n và Q - độ dài dãy số và số truy vấn. 

Dòng thứ hai chứa n số nguyên 𝑎1, 𝑎2, … , 𝑎𝑛 ​ phân tách nhau bởi dấu cách. 

Trên Q dòng tiếp theo, mỗi dòng chứa hai số nguyên dương l và r thể hiện một truy vấn.

`Constraints`

![image](https://github.com/minchangggg/DSA/assets/125820144/510776d8-1622-4cb4-b3f6-66011973fe62)

`Output Format`

Ứng với mỗi truy vấn, in ra một số nguyên là tổng các số trong đoạn [l,r] tương ứng. Kết quả mỗi truy vấn in ra trên một dòng.

`Sample Input`

5 3

1 2 3 4 5

1 5

2 4

3 3

`Sample Output`

15

9

3

**Code 1:** đối với `1 <= l < r <=n`

        #include <bits/stdc++.h>
        using namespace std;
        
        using ll = long long;
        
        ll query(int l, int r, vector <long long> sum) {
            return sum[r] - sum[l - 1];
        }
        
        int main(){
            #ifndef HAHA
            freopen ("input.txt", "r", stdin);
            freopen ("output.txt", "w", stdout);
            #endif
            
            int n, q; cin >> n >> q;
            ll A[n]; vector <ll> sum(n + 1, 0);
            
            for (int i = 1; i <= n; ++i) {
                cin >> A[i];
                sum[i] = sum[i - 1] + A[i];
            }
        	
            while (q--) {
                int l, r; cin >> l >> r;
                cout << query(l, r, sum) << endl;
            }
        
            return 0;
        }

![image](https://github.com/minchangggg/DSA/assets/125820144/dacdac94-ffa0-49ac-a745-6ef8f5d66ba0)

**Code 2:** đối với `0 <= l < r <n`

        #include <bits/stdc++.h>
        #define query( l, r, sum) sum[r] - sum[l - 1]
    
        using namespace std;
        using ll = long long;
        
        int main(){
            #ifndef HAHA
            freopen ("input.txt", "r", stdin);
            freopen ("output.txt", "w", stdout);
            #endif
            
            int n, q; cin >> n >> q; 
            ll a[n], sum[n]; 
            
            for (int i = 0; i < n; i++) {
                cin >> a[i];
                if (i==0) sum[0] = a[0]; 
                else sum[i] = sum[i-1] + a[i];
            }
        	
            while (q--) { 
                int l, r; // 0 <= l < r < n
                cin >> l >> r;
                
                if (l == 0) cout << sum[r] << endl;
                else cout << query(l, r, sum) << endl;
            }
            
            return 0;
        }

![image](https://github.com/minchangggg/DSA/assets/125820144/40343308-7bb0-4d25-bbd4-8084d76edb30)

## 2. Mảng cộng dồn trên mảng hai chiều
### a. Bài toán ví dụ
