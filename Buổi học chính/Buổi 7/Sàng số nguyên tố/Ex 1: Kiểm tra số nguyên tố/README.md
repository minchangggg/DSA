# Kiểm tra số nguyên tố 
`Input`

Số nguyên n (0 <= n <= 10^9)

`Output`

In ra YES nếu n là số nguyên tố, ngược lại in NO

`Ví dụ`

        Input      Output
        4          NO
        13         YES

### Cách chưa tối ưu, dựa trên định nghĩa số nguyên tố

                bool isPrime (int x) {
                        if(x<2) return false;
                
                        for(int i=2; i<=x/2; i++) {
                                if(x%i==0) return false;
                    }
                    
                        return true;
                }

Lưu ý: Trong vòng lặp điểm dừng sẽ là (n/2) thay vì (n-1) vì theo lý thuyết thì một số không bao giờ chia hết cho số lớn hơn một nửa của nó. Ví dụ số 9 thì số một nửa của nó là số (9 : 2 = 4), như vậy ta chỉ cần kiểm tra các số từ 2,3,4 mà thôi, còn các số 5,6,7,8 chắc chẵn 9 sẽ không chia hết.
### Kết quả
![image](https://github.com/minchangggg/DSA/assets/125820144/1253e75f-65f8-4409-a324-58c56aaff295)
