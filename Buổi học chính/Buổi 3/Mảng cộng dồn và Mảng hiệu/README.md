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

### 2. Cách tiếp cận 1: Duyệt trâu
- Ta sử dụng thuật toán duyệt trâu (hay còn gọi là vét cạn): duyệt từ vị trí 𝑙 đến vị trí 𝑟 để tính 𝑆 cho mỗi truy vấn và in ra kết quả.

![image](https://github.com/minchangggg/DSA/assets/125820144/cb1ddd56-2b9a-4c12-b863-4d080b6f98e7)

- Độ phức tạp của thuật toán: Với mỗi truy vấn trong 𝑄 truy vấn, ta duyệt qua mảng 1 chiều 𝐴 kích thước 𝑁, từ đó có độ phức tạp của thuật toán là 𝑂 (𝑁×𝑄).     
- Ta có thể thấy với độ phức tạp trên thì sẽ không thể giải quyết bài toán trong giới hạn thời gian của đề bài, vì vậy cần tìm cách giải tối ưu hơn.
- Gợi ý: Bằng cách tính một số tổng của các phần tử trong 𝐴, ta có thể sử dụng mối liên hệ về mặt toán học của các tổng đó để nhanh chóng tính toán tổng 𝑆 trong mỗi truy vấn, các tổng này liên quan đến vị trí của các phần tử trong 𝐴 cũng như 𝑙 và 𝑟.
