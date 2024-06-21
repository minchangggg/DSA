> https://hackmd.io/@2SchoolGuideline/H1HY_VKbp#M%E1%BA%A3ng-c%E1%BB%99ng-d%E1%BB%93n-v%C3%A0-m%E1%BA%A3ng-hi%E1%BB%87u-Prefix-sum-array-and-difference-array


## I Mảng cộng dồn - Prefix sum array

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

### d. Ví dụ  
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
![image](https://github.com/minchangggg/DSA/assets/125820144/0a385746-a7a5-4233-95af-f9e153d55ab7)

![image](https://github.com/minchangggg/DSA/assets/125820144/fa71d66e-4506-4fda-811e-9d1967b1e68e)

`Input mẫu`

3 4

4 2 1 0

6 9 7 1

9 6 7 3

3

1 1 2 3

1 4 3 4

2 2 3 2

`Output mẫu:`

29

4

15

### b. Cách tiếp cận 1: Duyệt trâu 
- Ta duyệt từ vị trí 𝑥1 𝑦1 đến vị trí 𝑥2 𝑦2 để tính 𝑆 cho mỗi truy vấn và in ra kết quả. 
- Độ phức tạp của thuật toán: Với mỗi truy vấn trong 𝑄 truy vấn, ta duyệt qua mảng 2 chiều 𝐴 kích thước 𝑁 × 𝑀 , từ đó có độ phức tạp của thuật toán là 𝑂 ( 𝑁 × 𝑀 × 𝑄 ) .
- VD:
  
                long long Solve(int x1, int x2, int y1, int y2){
                    long long sum = 0;
                    for (int i = x1; i <= x2; ++i){
                        for (int j = y1; j <= y2; ++j) sum += A[i][j];
                    }
                    return sum;
                }

### c. Cách tiếp cận 2: Mảng cộng dồn 2 chiều
![image](https://github.com/minchangggg/DSA/assets/125820144/27e41268-2cb2-46f2-aeb8-78607fcc5c59)

`Xây dựng mảng cộng dồn 2 chiều`

![image](https://github.com/minchangggg/DSA/assets/125820144/4736c1eb-20f1-4d88-91c1-defcc8adcd0c)

![image](https://github.com/minchangggg/DSA/assets/125820144/0920212d-a825-479f-804f-d112d75a9d86)

![image](https://github.com/minchangggg/DSA/assets/125820144/360339a6-88ff-4d07-abd2-0363a4b200a1)

`Sử dụng mảng cộng dồn 2 chiều để tính truy vấn`

![image](https://github.com/minchangggg/DSA/assets/125820144/30ce7276-5e32-4b23-a418-1b3d14bce7ac)

![image](https://github.com/minchangggg/DSA/assets/125820144/44f52ff8-9ba3-4c8b-8e2d-983acd87da56)

`Độ phức tạp của thuật toán`
Đầu tiên ta tính giá trị của mảng 2 chiều 𝑝𝑟𝑒𝑓 kích thước 𝑁×𝑀 trong 𝑂(𝑁×𝑀) và sau đó với 𝑄 truy vấn ta tính mỗi truy vấn trong 𝑂(1) , từ đó có độ phức tạp của thuật toán là 𝑂(𝑁×𝑀 + 𝑄) .
 
Code 1:
       
                void Calc(){
                    for (int i = 1; i <= n; ++i){
                        for (int j = 1; j <= m; ++j) {
                            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + A[i][j];
                        }
                    }
                }
                
                long long Solve(int x1, int x2, int y1, int y2){
                    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
                }
                
Code 2: 

![image](https://github.com/minchangggg/DSA/assets/125820144/c61e4574-a02f-4276-b4e4-e77523c78b49)

### d. Ví dụ
`Input`

Dòng đầu tiên chứa ba số nguyên dương m,n và Q - kích thước ma trận và số truy vấn. 

Trên m dòng tiếp theo, dòng thứ i chứa n số nguyên 𝑎(𝑖,1), 𝑎(𝑖,2), … ,𝑎(𝑖,𝑛) phân tách nhau bởi dấu cách - thể hiện hàng i của ma trận. 

Trên Q dòng tiếp theo, mỗi dòng chứa bốn số nguyên dương 𝑥1, 𝑦1, 𝑥2, 𝑦2 thể hiện một truy vấn.

`Constraints`

![image](https://github.com/minchangggg/DSA/assets/125820144/51c422f1-277e-48a6-bf7e-d72c09801747)

`Sample Input`

5 4 3

1 3 2 4

5 7 8 9

1 4 2 5

2 4 -8 9

-5 -1 -2 -3

1 1 3 3

2 3 5 4

1 1 5 4

`Sample Output`

33

20

47

**Code 1: dùng vector**

                #include <bits/stdc++.h>
                using namespace std;
                using ll = long long;
                
                ll query(int x1, int y1, int x2, int y2, vector < vector < long long > >& sum) {
                    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
                }
                
                int main(){
                    #ifndef HAHA
                    freopen ("input.txt", "r", stdin);
                    freopen ("output.txt", "w", stdout);
                    #endif
                    
                    int m, n, q; cin >> m >> n >> q;
                    vector <vector<ll>> sum(m + 1, vector <ll> (n + 1, 0));
                
                    for (int i = 1; i <= m; ++i) {
                        for (int j = 1; j <= n; ++j) {
                            int x; cin >> x;
                            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + x;
                        }
                    }
                
                    while (q--) {
                        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
                        cout << query(x1, y1, x2, y2, sum) << endl;
                    }
                    
                    return 0;
                }

![image](https://github.com/minchangggg/DSA/assets/125820144/48d5ff1b-ed95-4dde-bef0-17ff9495b170)

**Code 2: dùng mảng 2 chiều**

![image](https://github.com/minchangggg/DSA/assets/125820144/865b7888-5083-4a7b-bc0e-f1bf1269d78e)

## II Mảng hiệu - difference array
### Đặt vấn đề
Cho mảng A[ ] có N phần tử, có Q thao tác mỗi thao tác sẽ tăng các phần tử trong đoạn từ chỉ số L tới R của mảng A[ ] lên K đơn vị. Hãy xác định mảng A[ ] sau Q thao tác.

`Input Format`

Dòng đầu tiên là N và Q (số truy vấn)

Dòng thứ hai chứa N phần tử trong mảng A[]

Trên Q dòng tiếp theo, mỗi dòng là 3 số L, R, K

`Constraints`

1 <= N <= 10^6

1 <= Q <= 10^5

0 <= L <= R <= N-1; 0 <= A[i], K <= 1000

`Output Format`

In ra mảng sau Q thao tác

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

### Cách tiếp cận 1:
![image](https://github.com/minchangggg/DSA/assets/125820144/d981aaab-53f1-4240-ba57-479efeb4544d)

### Cách tiếp cận 2:
![image](https://github.com/minchangggg/DSA/assets/125820144/307494d6-9d4a-40c6-8734-b6c5b4af864e)

![image](https://github.com/minchangggg/DSA/assets/125820144/4208beaa-a01f-4884-a1c2-7cf5dc2905c6)

![image](https://github.com/minchangggg/DSA/assets/125820144/d677176a-671d-4e4c-b1e5-7c8a3d6b078d)

### Code

                #include <bits/stdc++.h>
                using namespace std;
                using ll = long long;
                
                int main(){
                    #ifndef HAHA
                    freopen ("input.txt", "r", stdin);
                    freopen ("output.txt", "w", stdout);
                    #endif
                    
                    int n, q; cin >> n >> q;
                    int a[n]; for(int &x : a) cin >> x;
                
                    int D[n + 2]; D[0] = a[0];
                    for(int i = 1; i < n; i++){
                        D[i] = a[i] - a[i - 1];
                    }
                
                    while(q--){
                        int l, r, k; cin >> l >> r >> k;
                        D[l] += k;
                        D[r + 1] -= k;
                    }
                
                    ll F[n]; F[0] = D[0];
                    for(int i = 1; i < n; i++){
                        F[i] = F[i-1] + D[i];
                    }
                
                    for(int i = 0; i < n; i++){
                        cout << F[i] << ' ';
                    }
                    
                    return 0;
                }

![image](https://github.com/minchangggg/DSA/assets/125820144/0fff332e-bc5a-4bf4-9061-ae26b2eb5198)
