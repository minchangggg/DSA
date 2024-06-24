# Lũy Thừa Nhị Phân
Lũy thừa nhị phân là một thuật toán hiệu quả để tính lũy thừa với độ phức tạp O(logN). 
## 1. Lũy Thừa Nhị Phân Sử Dụng Đệ Quy
- Lũy thừa nhị phân - Binary exponentiation là một thuật toán giúp bạn tính a^n với độ phức tạp là O(logN) thay vì duyệt vòng lặp từ 1 tới n. 
- Dựa theo công thức sau (ảnh : CP-Algorithm) :
  
![image](https://github.com/minchangggg/DSA/assets/125820144/4c7fa873-9c0c-4316-a567-87d001b6f8ba)

![image](https://github.com/minchangggg/DSA/assets/125820144/e590f615-2123-44da-83ed-fcfb2d2a54a0)

- Mã nguồn : 

        #include <iostream>
        #define ll long long
        using namespace std;
        
        ll binpow(int a, int n){
        	if(n == 0) return 1;
  
        	ll X = binpow(a, n/2); // a^(n/2)
  
        	if(n % 2 == 1) return X * X * a; // n lẻ
        	else return X * X; // n chẵn
        }
        
        int main(){
        	cout << binpow(2, 10) << endl;
        	cout << binpow(2, 50) << endl;
        	return 0;
        }
  
## 2. Lũy Thừa Nhị Phân Sử Dụng Vòng Lặp
![image](https://github.com/minchangggg/DSA/assets/125820144/69cc2bf8-803c-4338-ab26-a90ddd32e083)

![image](https://github.com/minchangggg/DSA/assets/125820144/63cf56db-0322-4446-b682-c7bbcf3c2bad)

![image](https://github.com/minchangggg/DSA/assets/125820144/66841b7d-07ad-44a0-a634-4bd85e8b34de)

![image](https://github.com/minchangggg/DSA/assets/125820144/586cc4eb-4be2-404a-9c31-30f0361e6777)

- Mã nguồn : 

        #include <iostream>
        #define ll long long
        using namespace std;
        
        ll binpow(ll a, ll n){
        	ll res = 1;
        	while(n != 0){
        		//Neu bit cuoi cung cua n la bit 1 
        		if(n % 2 == 1) res *= a;
        		//Dich bit 
        		n /= 2;
        		//Nhan a voi a
        		a *= a;
        	}
        	return res;
        }
        
        int main(){
        	cout << binpow(2, 10) << endl;
        	cout << binpow(2, 50) << endl;
        	return 0;
        }
  
- Ví dụ : a = 5, n = 29

        Vòng lặp 1 : n = 29 = 11101, bit cuối là 1 nên res *= a = 5, n / 2 = 14, a = a * a = 52
        Vòng lặp 2 : n = 14 = 1110, bit cuối là 0 nên không cần nhân 52 vào kết quả, res = 5, n = n / 2 = 7, a = a * a = 54
        Vòng lặp 3 : n = 7 = 111, bit cuối là 1 nên res *= a = 55, n = n / 2 = 3, a = a * a = 58
        Vòng lặp 4 : n = 3 = 11, bit cuối là 1 nên res *= a = 513, n = n / 2 = 1, a = a * a = 516
        Vòng lặp 5 : n = 1 = 1, bit cuối là 1 nên res *= a = 529, n = n / 2 = 0, a = a * a = 532
        Dừng vòng lặp khi n = 0
  
- Bạn cũng có thể cài đặt bằng cách sử dụng toán tử bit như sau : 

        #include <iostream>
        #define ll long long
        using namespace std;
        
        ll binpow(ll a, ll n){
        	ll res = 1;
        	while(n != 0){
        		//Neu bit cuoi cung cua n la bit 1 
        		if(n & 1){
        			res *= a;
        		}
        		//Dich phai 1 bit 
        		n >>= 1;
        		//Nhan a voi a
        		a *= a;
        	}
        	return res;
        }
        
        int main(){
        	cout << binpow(2, 10) << endl;
        	cout << binpow(2, 50) << endl;
        	return 0;
        }
  
- Mỗi vòng lặp n sẽ bị giảm 2 lần nên số vòng lặp cần phải thực hiện tương ứng với số bit của n ở dạng nhị phân là ⌈log2n⌉. Độ phức tạp của thuật toán là O(log2N), cực kỳ nhanh 

## 3. Lũy Thừa Chia Dư
- Vì độ phức tạp của thuật toán lũy thừa nhị phân chỉ là O(log2N) nên bạn có thể tính lũy thừa với số mũ rất lớn, ví dụ 1018. Vì kết quả của lũy thừa quá lớn nên thường được chia dư cho một số cho trước, mục này mình sẽ hướng dẫn cách bạn tính (a^b)%c. 
- Mã nguồn : 

        #include <iostream>
        #define ll long long
        using namespace std;
        
        ll binpow(ll a, ll n, ll c){
        	ll res = 1;
        	a %= c;
        	while(n != 0){
        		//Neu bit cuoi cung cua n la bit 1 
        		if(n % 2 == 1){
        			res *= (a % c);
        			res %= c;
        		}
        		//Dich phai 1 bit 
        		n /= 2;
        		//Nhan a voi a
        		a *= (a % c);
        		a %= c;
        	}
        	return res;
        }

        int main(){
        	cout << binpow(2, 1000000000000000, 10) << endl;
        	cout << binpow(11928128125, 5000000000, 10) << endl;
        	return 0;
        }
