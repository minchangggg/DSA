# Pascal Triangle

        #include <bits/stdc++.h>
        using namespace std;
        
        using ll = long long;
        
        ll C[1001][1001];
        
        void pascalTriangle () {
            for (int i = 0; i <= 1000; i++) {
                for (int j = 0; j <= i; j++) {
                    if ( j == 0 || j == i ) C[i][j] = 1;
                    else C[i][j] = C[i-1][j-1] + C[i-1][j];
                }
            }
        }
        
        int main() {
            pascalTriangle();
            for (int i = 0; i <= 10; i++) {
                for (int j = 0; j <= i; j++) {
                    cout << C[i][j] << ' ';
                }  
                cout << endl;
            }
        }

![image](https://github.com/minchangggg/DSA/assets/125820144/fd164159-3ee1-4559-af17-8a7a8096ed91)
