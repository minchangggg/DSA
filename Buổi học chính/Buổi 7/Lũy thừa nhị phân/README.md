# Lũy Thừa Nhị Phân
Lũy thừa nhị phân là một thuật toán hiệu quả để tính lũy thừa với độ phức tạp O(logN). 
## 1. Lũy Thừa Nhị Phân Sử Dụng Đệ Quy
- Lũy thừa nhị phân - Binary exponentiation là một thuật toán giúp bạn tính a^n với độ phức tạp là O(logN) thay vì duyệt vòng lặp từ 1 tới n. 
- Dựa theo công thức sau (ảnh : CP-Algorithm) :
  
![image](https://github.com/minchangggg/DSA/assets/125820144/4c7fa873-9c0c-4316-a567-87d001b6f8ba)

![image](https://github.com/minchangggg/DSA/assets/125820144/e590f615-2123-44da-83ed-fcfb2d2a54a0)

- Mã nguồn : tính lũy thừa bậc n của a 

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

- Mã nguồn : tính đồng dư (lũy thừa bậc n của a) cho c 

        #include <iostream>
        #define ll long long
        using namespace std;
        
        ll binpow(int a, int n, int c){
        	if(n == 0) return 1;
  
        	ll X = binpow(a, n/2, c); // a^(n/2)
  
        	if(n % 2 == 1) return ((X%c) * (X%c) % c) * (a%c) % c; // n lẻ
        	else return (X%c) * (X%c) % c; // n chẵn
        }
        
        int main(){
        	cout << binpow(2, 10, 3) << endl;
        	cout << binpow(2, 50, ) << endl;
        	return 0;
        }
## 2. Lũy Thừa Nhị Phân Sử Dụng Vòng Lặp
![image](https://github.com/minchangggg/DSA/assets/125820144/69cc2bf8-803c-4338-ab26-a90ddd32e083)

![image](https://github.com/minchangggg/DSA/assets/125820144/63cf56db-0322-4446-b682-c7bbcf3c2bad)

![image](https://github.com/minchangggg/DSA/assets/125820144/66841b7d-07ad-44a0-a634-4bd85e8b34de)

![image](https:3) << endl;
        	return 0;
        }
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
