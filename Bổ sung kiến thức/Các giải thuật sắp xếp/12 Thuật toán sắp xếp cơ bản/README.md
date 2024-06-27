> https://github.com/dungbachviet/SortingAlgorithms

- Sắp xếp là quá trình bố trí lại các phần tử trong một tập hợp theo một trình tự nào đó nhằm mục đích giúp quản lý và tìm kiếm các phần tử dễ dàng và nhanh chóng hơn.
- Tại sao phải sắp xếp?
	+ Để có thể sử dụng thuật toán tìm nhị phân
	+ Để thực hiện thao tác nào đó được nhanh hơn
# I. Các phương pháp sắp xếp thông dụng
# 1.Thuật toán Bubble Sort (Sắp xếp nổi bọt)
> https://www.geeksforgeeks.org/bubble-sort-algorithm/
## a. Mã nguồn minh họa :
	void bubbleSort(int a[], int n){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n - i - 1; j++){
				if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
			}
		}
	}

> Hoặc:
  
	void bubbleSort(double *unsortedArray, int size) {
		for (int turn = 0; turn < size - 1; turn++) {
			for (int bubbleindex = 0; bubbleindex < size - 1 - turn; bubbleindex++) {
				if (unsortedArray[bubbleindex] > unsortedArray[bubbleindex + 1])
					swap(&unsortedArray[bubbleindex], &unsortedArray[bubbleindex + 1]);
			}
		}
	}
  
## b. Ý tưởng của giải thuật :
![Bản sao của Blue-Pink Cute Class Schedule (2)](https://github.com/minchangggg/DSA/assets/125820144/1fd8691e-c087-4e59-a304-423ff0042580)

- Thuật toán này mang một tư tưởng lan truyền, có nghĩa là : với mỗi một quá trình lan truyền (quá trình duyệt và hoán vị các phần tử gần kề liên tiếp), giải thuật sẽ xác định được một phần từ lớn nhất rồi cố định nó ở cuối mảng.
- Lúc này, phần tử ở cuối mảng sẽ không còn đóng bất kỳ một vai trò nào nữa trong quá trình sắp xếp tiếp theo. Khi đó, để dễ hiểu ta có thể giả định, mảng mới chỉ còn lại từ phần từ đầu tiên đến phần từ thứ n – 1 ( không xét phần tử cuối). Sau đó tiếp tục quá trình “lan truyền nổi bọt” trong mảng mới này để liên tục tìm ra phần tử lớn nhất và gắn nó cố định tại trí cuối cùng. Như vậy, sau mỗi quá trình lan truyền, số phần tử trong mảng liên tục giảm đi một, nhưng đồng thời ta cũng đã cố định được một phần tử lớn nhất nằm ở cuối mỗi mảng. Sau n – 1 quá trình lan truyền như vậy, chúng ta sẽ thu được một mảng đã được sắp xếp và quá trình lan truyền hoàn toàn kết thúc
## c. Độ phức tạp của giải thuật :
- Do phải trải qua (n-1) quá trình lan truyền, với mỗi quá trình lan truyền sẽ tương ứng với số lần duyệt tối đa qua các phần từ là : (n-1) + (n-2) + … + 1. Vì vậy độ phức tạp của giải thuật trên là : O(n^2)
## d. Nhận xét và đánh giá :
- Ưu điểm:
  + Thể hiện được tính ổn định và tại chỗ
  + Đơn giản, dễ hiểu… được sử dụng làm ví dụ minh họa trong quá trình giảng dạy
- Nhược điểm :
  + Hiệu suất chậm nhất trong các thuật toán sắp xếp.
  + Không hiệu quả với những dữ liệu lớn.
- Tối ưu và so sánh: Giải pháp tối ưu cho giải thuật trên đó là sử dụng biến hasSwapped nằm bên ngay trong vòng lặp thứ 2. Nếu đầu vào là đã được sắp xếp thì độ phức tạp thời gian chỉ còn là O(n). Một cách tương tự, trong trường hợp dãy số đầu được sắp xếp giảm dần
## e. Ví dụ
		#include <bits/stdc++.h>
		using namespace std;
		
		void bubbleSort(int arr[], int n) {
		    bool swapped;
		    for (int i = 0; i < n - 1; i++) {
		        swapped = false;
		        for (int j = 0; j < n - i - 1; j++) {
		            if (arr[j] > arr[j + 1]) {
		                swap(arr[j], arr[j + 1]);
		                swapped = true;
		            }
		        }
		        if (swapped == false) break;
		    }
		}
		
		int main() {
		    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
		    int N = sizeof(arr) / sizeof(arr[0]);
		    bubbleSort(arr, N);
		    cout << "Sorted array:";
		    for (int x : arr) cout << " " << x;
		    return 0;
		}

> Output

		Sorted array: 11 12 22 25 34 64 90

# 2.Thuật toán Insertion Sort (Sắp xếp chèn)
> https://www.geeksforgeeks.org/insertion-sort-algorithm/
## a. Mã nguồn minh họa :
	void insertionSort(int a[], int n){
		for(int i = 1; i < n; i++){
			int pos = i - 1, x = a[i];
			while(pos >= 0 && a[pos] > x){
				a[pos + 1] = a[pos];
				--pos;
			}
			a[pos + 1] = x;
		}
	}

> Hoặc:

        // algorithm for Insertion Sort
        void insertionSort(double *unsortedArray, int size) {
        	for (int turn = 1; turn < size; turn++) {
        		double rememberedValue = unsortedArray[turn];
        		int insertionIndex = turn;
        		while (insertionIndex >= 1 && unsortedArray[insertionIndex - 1] > rememberedValue) {
        			unsortedArray[insertionIndex] = unsortedArray[insertionIndex - 1];
        			insertionIndex--;
        		}
        		unsortedArray[insertionIndex] = rememberedValue;
        
        	}
        }  
	
## b. Ý tưởng của giải thuật :
![image](https://github.com/minchangggg/DSA/assets/125820144/988bae3a-fc1c-4c31-bea3-0bba3774ee42)

- Giải thuật này xuất phát từ các thao tác sắp xếp của những người chơi bài. Tư tưởng đó được thể hiện như sau :
    + Từ một tập bài gồm n quân bài của người chơi, họ cần phải sắp xếp thứ tự các quân bài trên tay theo một thứ tự tăng dần. Lúc này, họ sẽ duyệt từ quân bài thứ 2 tới quân bài cuối cùng (thứ n). Đối với quân bài thứ 2, họ cần phải so sánh quân bài này với các quân bài phía trước nó, tức lúc này là quân bài thứ 1. Rõ ràng, các quân bài phía trước quân bài thứ 2 đều đã được sắp xếp ( do chỉ có 1 quân bài phía trước). Công việc của người chơi lúc này là chỉ cần chèn quân bài thứ 2 vào vị trí thích hợp trong số các quân bài phía trước sao cho sau thao tác chèn này, các quân bài phía trước cũng phải được sắp xếp theo một thứ tự tăng dần
    + Tiếp tục với việc xét quân bài thứ 3, ta tiến hành so sánh quân bài này với dãy các quân bài đã được sắp xếp ở phía trước nó. Sau đó tiến hành thực hiện thao tác chèn quân bài này vào ví trí thích hợp trong dãy các quân bài phía trước để tạo thành một dãy con được sắp xếp tăng dần.
    + Một cách hoàn toàn tương tự với các quân bài thứ 4, 5 … n.
    + Kết thúc quá trình này, ta sẽ thu được một dãy số được sắp xếp tăng dần
## c. Độ phức tạp của thuật toán
- Trường hợp tốt nhất: O(n) , Nếu danh sách đã được sắp xếp, trong đó n là số phần tử trong danh sách.
- Trường hợp trung bình: O(n^2) , Nếu danh sách được sắp xếp ngẫu nhiên
- Trường hợp xấu nhất: O(n^2) , Nếu danh sách theo thứ tự ngược lại
## d. Nhận xét và đánh giá
- Ưu điểm :
  + Làm việc tốt trong trường hợp mảng có ít phần tử
  + Giải thuật có tính chất ổn định và tại chỗ
  + Được sử dụng như một sự hỗ trợ trong một vài giai đoạn con ở một số thuật toán sắp xếp khác
  + Đơn giản, dễ hiểu và dễ cài đặt
  + Là thuật toán sắp xếp tốt nhất đối với dãy đã gần được sắp xếp , nghĩa là mỗi phần tử đã đứng ở vị trí rất gần vị trí trong thứ tự cần sắp xếp
- Nhược điểm :
  + Độ phức tạp trung bình vẫn còn khá lớn O(n^2) so với các thuật toán sắp xếp nhanh nhất hiện nay như QuickSort
- Sự tối ưu, so sánh và mở rộng :
  + Thuật toán tuy đã giải quyết được tình huống dãy số đầu vào đã được sắp xếp tăng dần ( tức nó chỉ mất O(n) thời gian sắp xếp). Nhưng còn với trường hợp dãy số đầu vào lại được sắp xếp theo thứ tự giảm dần, trong tình huống này giải thuật vẫn sẽ mất thời gian O(n^2) (thậm chí đây được xếp vào tình huống đầu vào tồi nhất). Để tối ưu giải thuật, xin đề xuất một giải pháp với cách sử dụng biến hasSwapped (như giải pháp tối ưu trong Selection Sort) để phát hiện dãy đầu vào đã được sắp xếp giảm dần mất O(n) thời gian,sau đó tốn thêm O(n/2) thời gian để đảo ngược dãy số đầu vào đó.
  + Một giải pháp tối ưu khá hay được đề xuất tiếp theo đó là : Thay vì trong giai đoạn chèn 1 quân bài vào dãy các quân bài phía trước nó bằng giải pháp tìm kiếm tuần tự, ta sẽ sử dụng giải thuật tìm kiếm nhị phân trong chính quá trình chèn đó. Điều này sẽ giúp tiết kiệm được thời gian cho thao tác tìm kiếm và thao tác chèn một cách đáng kể từ O(i) xuống còn O(log(i)) với i là chỉ số cần chèn tại đó
  + Điều gì sẽ xảy ra nếu giải thuật này được cài bằng danh sách liên kết : Liệu nó sẽ bất lợi hay có lợi?
  + Trong tình huống này, việc sử dụng danh sách liên kết để cài đặt chỉ có lợi khi mà dữ liệu cần sắp xếp đến một cách liên tục (đó có thể là dữ liệu online). Vì vậy, với cách cài đặt Danh sách Liên kết, ta có thể chủ động cấp phát vùng nhớ tùy thích
  + Nhưng khi cài đặt bằng Danh sách liên kết cũng sẽ nảy sinh vài vấn đề : Do việc truy cập vào 1 phần tử trong danh sách liên kết không mang tính trực truy tức phải mất thời gian tuyến tính. Điều này, có thể làm giảm hiệu suất của giải thuật
  + Tuy nhiên, trong thực tế để cài đặt Danh sách Liên kết cho giải thuật này, mọi người có thể tham khảo tại đây : http://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/
## e. Ví dụ
	#include <bits/stdc++.h>
	using namespace std;
	
	void insertionSort(int arr[], int n) {
	    for (int i = 1; i < n; i++) {
		int key = arr[i]; int j = i - 1;
		// Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
		while (j >= 0 && arr[j] > key) {
		    arr[j + 1] = arr[j];
		    --j;
		}
		arr[j + 1] = key;
	    }
	}
	
	int main() {
	    int arr[] = { 12, 11, 13, 5, 6 };
	    int N = sizeof(arr) / sizeof(arr[0]);
	
	    insertionSort(arr, N);
	    for (int x : arr) cout << x << " ";
	
	    return 0;
	}

> Output

	5 6 11 12 13 
 
# 3. Thuật toán Selection Sort (Sắp xếp chọn)
> https://www.geeksforgeeks.org/selection-sort-algorithm-2/
## a. Code minh họa
	void selectionSort(int a[], int n){
		for(int i = 0; i < n; i++){
			int min_pos = i;
			for (int j = i + 1; j < n; j++){
				if (a[j] < a[min_pos]) min_pos = j;
			}
			swap(a[min_pos], a[i]);
		}
	}
 
> Hoặc
  
        void selectionSort(double *unsortedArray, int size) {
        	for (int index = 0; index < size - 1; index++) {
        		int minIndex = index;
        		for (int findMinIndex = index + 1; findMinIndex < size; findMinIndex++) {
        			if (unsortedArray[findMinIndex] < unsortedArray[minIndex])
        				minIndex = findMinIndex;
        		}	
        		swap(&unsortedArray[minIndex], &unsortedArray[index]);
        	}
        }
        
## b Ý tưởng giải thuật
![image](https://github.com/minchangggg/DSA/assets/125820144/a7fe03c5-17c2-4689-9494-86b02e8bb183)

Với một mảng số ban đầu chưa được sắp xếp gồm size phần tử. Ý tưởng của thuật toán được mô tả thông qua các bước chính như sau :
   + Chọn 1 phần tử đầu tiên của dãy số, giả sử phần tử này là nhỏ nhất, sau đó lưu lại chỉ số phần tử đó
   + Duyệt để so sánh phần tử nhỏ nhất này với các phần tử còn lại (tức các phần tử tiếp theo của dãy số). Nếu phát hiện có bất kỳ phần tử nào nhỏ hơn phần tử cần so sánh, tiến hành thay đổi giá trị của chỉ số lưu trữ phần tử nhỏ nhất
   + Sau khi duyệt xong toàn bộ mảng, kết quả chúng ta tìm được đó là : vị trí (chỉ số) của phần tử nhỏ nhất trong mảng đó. Lúc này, thực hiện hoán đổi vị trí của : phần tử đầu tiên trong mảng và vị trí của phần tử nhỏ nhất (đã xác định tử bước trên)
   + Sau khi hoán đổi, phần tử nhỏ nhất sẽ luôn nằm “cố định” ở đầu mảng và phần tử này sẽ không còn đóng góp vai trò nào cho những lần sắp xếp tiếp theo. Do phần tử đầu tiên đã cố định, quá trình sắp xếp chỉ còn tác động lên size - 1 tiếp theo (không xét phần tử thứ nhất). Và thực hiện lặp lại một cách tương tự quá trình trên từ bước 1 tới bước cuối cùng … Sau mỗi quá trình lặp lại đó, ta sẽ lần lượt xác định và cố định ra được phần tử nhỏ thứ 2, phần tử nhỏ thứ 3 …, phần tử nhỏ thứ size – 1. Tới đây giải thuật kết thúc !
## c Độ phức tạp của thuật toán :
- Thuật toán sử dụng 2 vòng for:
  + Vòng for thứ nhất chạy từ index = 0 tới size – 2.
  + Vòng for thứ hai chạy từ index + 1 tới cuối mảng Như vậy, đối với 1 dãy số gồm n phần tử , số lần duyệt qua từng phần tử trong mảng sẽ là : (n-1) + (n-2) + … + 1 .  
- Vì vậy độ phức tạp của thuật toán trong tình huống tồi tệ nhất sẽ là : O(n^2)
## d. Nhận xét thuật toán
- Ưu điểm : 
  + Selection Sort là một giải thuật đã hạn chế được khá nhiều số hoán vị (đổi chỗ 2 phần tử trong mảng) so với giải thuật Sắp xếp Nổi bọt (do nó sử dụng biến chỉ số để lưu lại phần tử nhỏ nhất,… để đến cuối cùng mới tiến hành hoán vị)
  + Giải thuật này có tính chất ổn định : Tức vị trí tương đối của các phần tử "bằng nhau về giá trị" trong mảng vẫn được giữ nguyên trước và khi sắp xếp (nghĩa là nếu có 2 phần tử bằng nhau trong mảng, phần tử 1 nằm bên bên trái phần tử 2 thì sau khi sắp xếp thứ tự này vẫn không thay đổi)
  + Không đòi hỏi thêm không gian nhớ phụ, nên giải thuật mang tính chất “ Tại chỗ”
  + Trong thực tế, giải thuật này có thể được sử dụng như một giải pháp hỗ trợ cho một giai đoạn nào đó trong những giải thuật sắp xếp khác
- Nhược điểm :
  + Độ phức tạp của giải thuật tuy đã được cải thiện nhưng nhìn chung vẫn còn khá lớn so với các thuật toán sắp xếp hiệu quả khác (như QuickSort, MergeSort)
  + Chưa giải quyết được vấn đề khi mà đầu vào của dãy số đã được sắp xếp (nghĩa là nếu đầu vào là một dãy số đã được sắp xếp thì thuật toán này vẫn cứ "máy móc" để sắp xếp lại)
- Giải pháp tối ưu : Trong tình huống dãy số đầu vào đã được sắp xếp, giải pháp được đưa ra sẽ là : Sử dụng một biến hasSwapped để duyệt từ đầu tới cuối mảng, để phát hiện xem dãy số đã được sắp xếp tăng dần hay giảm dần hay chưa? Nếu hasSwapped = 0 khi duyệt theo chiều thuận tức dãy đã được sắp xếp tăng dần. Nếu hasSwapped = 0 khi duyệt theo chiều nghịch, tức dãy đã được sắp xếp giảm dần, vì thế chỉ cần đảo ngược lại dãy số đó để có một thứ tự đúng!
## e. Ví dụ
	#include <bits/stdc++.h>
	using namespace std;
	
	void selectionSort(int arr[], int n) {
	    for (int i = 0; i < n - 1; i++) {
	        int min_idx = i;
	        for (int j = i + 1; j < n; j++) {
	            if (arr[j] < arr[min_idx]) min_idx = j;
	        }
	        if (min_idx != i) swap(arr[min_idx], arr[i]);
	    }
	}
	
	int main() {
	    int arr[] = { 64, 25, 12, 22, 11 };
	    int n = sizeof(arr) / sizeof(arr[0]);
	
	    selectionSort(arr, n);
	    cout << "Sorted array: ";
	    for (int x : arr) cout << x << ' ';
	    return 0;
	}

> Output

	Sorted array: 11 12 22 25 64 

# 4.Thuật toán Merge Sort (Sắp xếp trộn)
> https://www.geeksforgeeks.org/merge-sort/?ref=header_search
## a. Mã nguồn minh họa (python)
### Source 1
`Thao tác trộn`

		void merge(int a[], int l, int m, int r){
			int n1 = m - l + 1, n2 = r - m;
			int x[n1], y[n2];
			for(int j = l; j <= m; j++) x[j - l] = a[j];
			for(int j = m + 1; j <= r; j++) y[j - m - 1] = a[j];
			int i = 0, j = 0, cnt = l;
			while(i < n1 && j < n2){
				if(x[i] <= y[j]) a[cnt++] = x[i++];
				else a[cnt++] = y[j++];
			}
			while(i < n1) a[cnt++] = x[i++];
			while(j < n2) a[cnt++] = y[j++];
		}

`Hàm merge soft và main`

		void mergeSort(int a[], int l, int r){
			if(l < r){
				int m = (l + r) / 2;
				mergeSort(a, l, m);
				mergeSort(a, m + 1, r);
				merge(a, l, m , r);
			}
		}
		int main(){
			int n; cin >> n;
			int a[n];
			for(int &x : a) cin >> x;
			mergeSort(a, 0, n - 1);
			for(int x : a) cout << x << ' ';
		}

### Source 2
## b Ý tưởng giải thuật
![Bản sao của Blue-Pink Cute Class Schedule (3)](https://github.com/minchangggg/DSA/assets/125820144/53f8474a-8452-461c-b539-9a78b6aa678b)

		- Divide:
		[38, 27, 43, 10] được chia thành [38, 27] và [43, 10] .
		[38, 27] được chia thành [38] và [27] .
		[43, 10] được chia thành [43] và [10] .
		
		- Conquer:
		[38] đã được sắp xếp.
		[27] đã được sắp xếp.
		[43] đã được sắp xếp.
		[10] đã được sắp xếp.
		
		- Merge:
		Hợp nhất [38] và [27] để có được [27, 38] .
		Hợp nhất [43] và [10] để có được [10,43] .
		Hợp nhất [27, 38] và [10,43] để có danh sách được sắp xếp cuối cùng [10, 27, 38, 43]
		
		-> Do đó, danh sách được sắp xếp là [10, 27, 38, 43] .

- Phân tích ý tưởng: Thuật toán Merge Sort - sắp xếp trộn sử dụng ý tưởng Divide and Conquer(chia để trị) đối với một dãy cho trước. Có thể hiểu đơn giản Divide and Conquer(chia để trị) là việc thực hiện chia một sự việc thành nhiều sự việc với quy mô nhỏ hơn nhưng vẫn giữ nguyên tính chất và mục đích ban đầu rồi thực hiện các thao tác.
- Nguyên lí thực hiện: Bao gồm ba bước chính là
   + Thực hiện chia dãy.
   + Sắp xếp các dãy con.
   + Gộp các dãy con lại.
- Thực hiện thuật toán: Đối với thuật toán Merge Sort - sắp xếp trộn, chúng ta sẽ thực hiện chia đôi liên tục dãy lớn thành các dãy con, cho đến khi ta thu được các các dãy chỉ bao gồm một phần tử. Sau đó sắp xếp lại các phần tử bắt đầu từ những dãy con nhỏ nhất. Cuối cùng thực hiện thao gộp lần lượt ngược lại các dãy con để trở về dãy với số phần tử như ban đầu đã được sắp xếp. 
## c. Độ phức tạp của giải thuật 
- Ta có độ phức tạp của thuật toán : T(n) = 2T(n/2) + O(n)
- Từ công thức trên + áp dụng với Định lý Thợ rút gọn (Trang 48, Sách Cấu trúc dữ liệu và giải thuật, Nguyễn Đức Nghĩa), ta dễ dàng tìm được độ phức tạp của giải thuật trên là : O(n*log(n))
## d. Nhận xét và đánh giá
- Ưu điểm
   + Đơn giản và dễ hiểu, thời gian sắp xếp với độ phức tạp đã được giảm xuống một cách đáng kể (O(nlog(n)) so với các giải thuật Sắp xếp Chèn, Nổi bọt, Chọn
Giải thuật Sắp xếp Trộn giữ được tính ổn định tương đối của các phần tử
- Nhược điểm
   + Giải thuật Sắp xếp Trộn do cần phải sử dụng thêm vùng nhớ bên ngoài ( vùng nhớ dùng thêm này tỉ lệ với số lượng phần tử n) nên giải thuật không có tính chất tại chỗ
Độ phức tạp của giải thuật đều như nhau khi xét trên cả 3 trường hợp : Tốt nhất, Trung bình và Tồi nhất
- Tối ưu thuật toán và các bài toán ứng dụng thực tế
   + Một cách tối ưu được để xuất cho giải thuật sắp xếp Trộn đó là sử dụng cấu trúc dữ liệu Danh sách Liên kết thay vì sử dụng mảng. Bởi vì điểm mạnh của DSLK đó là khả năng đáp ứng một tập dữ liệu đến một cách liên tục (dữ liệu thực tế). Hơn nữa, các thao tác chèn, sửa, xóa một phần tử trong danh sách liên kết chỉ tốn thời gian O(1), nhanh chóng hơn so với thời gian tuyến tính khi chèn, sửa, xóa một phần tử trong mảng. Áp dụng tính chất của DSLK vào giải thuật Sắp xếp Trộn, sẽ giúp tiết kiệm được vùng nhớ ( tức ko cần sử dụng vùng nhớ ngoài – giữ được tính chất “tại chỗ” của giải thuật), đồng thời giải quyết được các bài toán với luồng dữ liệu đến liên tục (online) trong thực tế cuộc sống
   + Sử dụng thêm biến hasSwapped trong từng đoạn nhỏ mảng ( có nghĩa sử dụng điều kiện này kết hợp làm điều kiện neo trong đệ quy), điều này giúp nhanh chóng nhận biết một số đoạn nhỏ trong mảng đã được sắp xếp rồi, từ đó hạn chế được tối đa số bước đệ quy lãng phí tiếp sau. Tương tự cũng nên kiểm tra xem đoạn nhỏ mảng đó có đang là sắp xếp giảm dần (từ đó ta chỉ việc đảo ngược vị trí các phần tử trong mảng).
     
> Một số bài toán thực tế có thể áp dụng giải thuật Merge Sort :
> 
> Bài toán đếm số đảo ngược : http://www.geeksforgeeks.org/counting-inversions/
>
> Bài toán liên quan tới lĩnh vực sắp xếp tại vùng nhớ ngoài (not sorting in RAM) : https://en.wikipedia.org/wiki/External_sorting
## e. Ví dụ 
		#include <bits/stdc++.h>
		using namespace std;
		
		// Merges two subarrays of array[]: First subarray is arr[begin..mid], Second subarray is arr[mid+1..end]
		void merge(int array[], int const left, int const mid, int const right) {
		    // Create temp arrays leftArray[] and rightArray[]
		    int const subArrayOne = mid - left + 1; // tính cả mid 
		    int const subArrayTwo = right - mid; // ko có mid 
		    auto *leftArray = new int[subArrayOne], 
		            *rightArray = new int[subArrayTwo];
		
		    // Copy data to temp arrays leftArray[] and rightArray[]
		    for (auto i = 0; i < subArrayOne; i++) leftArray[i] = array[left + i];
		    for (auto j = 0; j < subArrayTwo; j++) rightArray[j] = array[(mid + 1) + j];
		
		    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
		    int indexOfMergedArray = left;
		
		    // Merge the temp arrays back into array[left..right]
		    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
		            array[indexOfMergedArray++] = leftArray[indexOfSubArrayOne++];
		        }
		        else {
		            array[indexOfMergedArray++] = rightArray[indexOfSubArrayTwo++];
		        }
		    }
		
		    // Copy the remaining elements of left[], if there are any
		    while (indexOfSubArrayOne < subArrayOne) {
		        array[indexOfMergedArray++] = leftArray[indexOfSubArrayOne++];
		    }
		
		    // Copy the remaining elements of right[], if there are any
		    while (indexOfSubArrayTwo < subArrayTwo) {
		        array[indexOfMergedArray++] = rightArray[indexOfSubArrayTwo++];
		    }
		
		    delete[] leftArray; delete[] rightArray;
		}
		
		// begin is for left index and end is right index of the sub-array of arr to be sorted
		void mergeSort(int array[], int const begin, int const end) {
		    if (begin >= end) return;
		    int mid = begin + (end - begin) / 2;
		    mergeSort(array, begin, mid);
		    mergeSort(array, mid + 1, end);
		    merge(array, begin, mid, end);
		}
		
		void printArray(int A[], int size) {
		    for (int i = 0; i < size; i++) cout << A[i] << " ";
		}
		
		int main() {
		    int arr[] = { 12, 11, 13, 5, 6, 7 };
		    int arr_size = sizeof(arr) / sizeof(arr[0]);
		
		    cout << "Given array is ";
		    printArray(arr, arr_size);
		
		    mergeSort(arr, 0, arr_size - 1);
		    cout << "\nSorted array is ";
		    printArray(arr, arr_size);
		    return 0;
		}

> Output

		Given array is 12 11 13 5 6 7 
		Sorted array is 5 6 7 11 12 13 

# 5.Thuật toán Heap Sort (Sắp xếp vun đống)
> https://www.geeksforgeeks.org/heap-sort/?ref=header_search
>
> https://www.youtube.com/watch?v=Dr6DdLDsE-4&list=PLoaAbmGPgTSNMAzkKBHkh2mLuBk54II5L&index=47
## a. Mã nguồn minh họa :
		void updateHeapAt(double *heapedArray, int size, int updatedPosition) {
			int largestIndex = updatedPosition; // index of the largest element
			int leftChildIndex = largestIndex * 2 + 1;
			int rightChildIndex = largestIndex * 2 + 2;
			// Check if the value of any one of its two children has larger than the largest value saved in the parent variable largestIndex 
			if (leftChildIndex < size && heapedArray[leftChildIndex] > heapedArray[largestIndex])
				largestIndex = leftChildIndex;
				
			if (rightChildIndex < size && heapedArray[rightChildIndex] > heapedArray[largestIndex])
				largestIndex = rightChildIndex;
		
			// if having no change in variable largestIndex, it stops and doesn't call the recursive function
			if (largestIndex != updatedPosition) {
				// when the largest value is at one of its two children, carry out the swap and update the heap at a lower level
				swap(&heapedArray[updatedPosition], &heapedArray[largestIndex]);
				updateHeapAt(heapedArray, size, largestIndex);
			}
		}
		
		void heapSort(double *unsortedArray, int size) {
			// build the new max heap from an unsorted array
			for (int buildHeapIndex = (size / 2) - 1; buildHeapIndex >= 0; buildHeapIndex--) {
				updateHeapAt(unsortedArray, size, buildHeapIndex);
			}
		
			// After creating the maximum heap, it is the high time for converting from the max heap to ascending sorted array
			for (int sizeOfUpdatedHeap = size - 1; sizeOfUpdatedHeap >= 1; sizeOfUpdatedHeap--) {
				// Swap between the first element and the last element in the heap to move gradually the largest element to the end of the array
				swap(&unsortedArray[0], &unsortedArray[sizeOfUpdatedHeap]);
				// After swapping the two elements above, it is necessary to update the remaining heap
				updateHeapAt(unsortedArray, sizeOfUpdatedHeap, 0);
			}
		}
## b. Ý tưởng giải thuật và nguyên tắc hoạt động
### Ý tưởng giải thuật
- Tư tưởng của giải thuật xuất phát từ cơ sở Cây vun đống Max ( hay Cây vun đống Min). Một cách tương tự nhau, ta sẽ lựa chọn cây vun đống Max để minh họa giải thuật Sắp xếp vun đống
- Cây vun đống Max ở đây được quan niệm là cây nhị phân hoàn chỉnh, tức với mỗi nút cha sẽ luôn bao gồm 2 con (trừ hàng ở độ sâu cuối cùng), và các con luôn được phân bố một cách trái nhất có thể. Do cây vun đống được đề xuất minh họa trong giải thuật này là Max Heap Tree, nên có thêm tính chất Maximum được thể hiện như sau : Nút cha phải lớn hơn hoặc bằng hai nút con ( còn các nút con cùng cấp thì không có ràng buộc với nhau). Như vậy, mỗi nhánh mà được đại diện bởi bất cứ nút nào đó trong cây cũng sẽ phải là một nhánh Max Heap.
- Cây vun đống có thể được cài đặt sử dụng Mảng hoặc Danh sách Liên kết. Để đơn giản trong sự minh họa, chúng ta sẽ lựa chọn Mảng cho quá trình cài đặt giải thuật
- Tiếp theo đó, ta sẽ làm gì với cây Max Heap Tree này, khi biết được một tính chất vô cùng quan trọng của nó : Giá trị của cha luôn lớn hơn hoặc bằng giá trị của mỗi con. Điều đó, cho thấy phần tử gốc sẽ là phần tử lớn nhất trong dãy. Ta tiến hành hoán đổi phần tử gốc với 1 phần tử cuối cùng của lá (nút cuối cùng), lúc này, nút lá (“thấp bé nhỏ con”) được đưa lên đầu (root, rễ cây), đồng thời tách biệt và cất giữ phần tử lớn nhất ở một nơi nào đó. Tại thời điểm này, cây hiện tại không còn mang tính chất Max Heap (bởi vì lá được đưa lên gốc có thể nhỏ hơn 2 con của nút cha bị thay thế). Tại đây ta cần phải tiến hành xây dựng một giải thuật mang tên updateHeapAt(...) giúp cập nhật lại cây trên để đưa nó trở về đúng dạng cây Max Heap Tree . Hàm này sẽ sử dụng tính chất quan trọng từ cây “bị sai lệch” trên, đó là : 2 nhánh con của phần tử gốc hiện tại vẫn mang tính chất Max Heap. Sau khi, đi qua hàm này, cây trên sẽ được cập nhật về đúng dạng Max Heap... Rồi ta lại hoán đổi gốc của cây với phần tử lá cuối cùng, đồng thời lại tách biệt phần tử lớn nhất ra khỏi cây, rồi lại cập nhật lại cây ... Các quá trình cứ diễn ra một cách tuần hoàn cho tới khi cây chỉ còn duy nhất một phần tử (đó cũng sẽ chính là phần tử nhỏ nhất trong dãy số ). .... Kết thúc giải thuật Heap Sort, chúng ta sẽ thu được một mảng dãy số đã được sắp xếp như ý muốn !
- Khi cài đặt cây Max Heap theo dạng mảng số, có một tính chất sau cần chú ý:
   + LeftChildIndex = 2 * ParentIndex + 1
   + RightChildIndex = 2 * ParentIndex + 2
- Vì input hay mỗi dãy số ban đầu (được lưu trữ dưới dạng mảng) là ngẫu nhiên, chưa được có tính chất Max Heap, vì thế ta cần có phải có một bước đầu để chuyển hóa cây trên thành một cây mang đặc điểm Max Heap ( thủ tục này được được tạo trong hàm heapSort(...) )
- Như vậy, hàm heapSort sẽ bao quát những công việc sau :
- Khởi tạo một cây Max Heap Tree từ một dãy ngẫu nhiên
- Từ cây Max Heap Tree, tiến hành trích lấy phần tử lớn nhất ở root, và thay thế vị trí root bởi nút lá cuối cùng. Sau đó, gọi hàm updateHeapAt(...) cập nhật lại cây trên tại root mới đó, rồi lại trích lấy phần tử root, và thay thế vị trí root bởi lá,...Quá trình diễn ra một cách tương tự, cho tới khi cây chỉ còn 1 phần tử. Và phần tử đó sẽ là phần tử nhỏ nhất trong mảng. Kết quả, ta thu được một mảng gồm các số đã được sắp xếp tăng dần !
### Nguyên tắc hoạt động 
- Thuật toán Heap sort sẽ hoạt động dựa trên các nguyên tắc sau:
   + Phần tử lớn nhất được đặt ở nút gốc theo thuộc tính Max Heap
   + Loại bỏ phần tử gốc và đặt nó ở cuối mảng nhị phân. Đặt phần tử cuối cùng của cây nhị phân vào chỗ trống.
   + Giảm kích thước của Heap đi 1 đơn vị
   + Tạo cấu trúc dữ liệu Heap cho phần tử gốc để nút gốc chứa phần tử có giá trị lớn nhất.
   + Lặp lại quá trình này cho đến khi tất cả các phần tử của danh sách được sắp xếp đúng.

![image](https://github.com/minchangggg/DSA/assets/125820144/d93cd487-0756-44f3-b666-959b94a75167)

`Loại bỏ phần tử gốc 14 và đặt ở cuối mảng nhị phân.`

![image](https://github.com/minchangggg/DSA/assets/125820144/0e22c0bb-9669-4dcf-9e79-37fb328aa980)

`Tạo cấu trúc dữ liệu Heap cho phần tử gốc 12.`

![image](https://github.com/minchangggg/DSA/assets/125820144/4ccd90ec-5b3a-480a-a94a-bb433a78e3f6)

`Hoán đổi để loại bỏ phần tử gốc 12.`

![image](https://github.com/minchangggg/DSA/assets/125820144/c9d46e1e-1cbb-4360-8808-e86bfdfab1ed)

`Xóa bỏ phần tử gốc 12.`

![image](https://github.com/minchangggg/DSA/assets/125820144/fda44de0-3005-4afc-b4bb-abdedd5c615a)

`Tiếp tục tạo cấu trúc dữ liệu Heap.`

![image](https://github.com/minchangggg/DSA/assets/125820144/08bf00c4-dbf0-4669-b695-121ccefd9dd4)

`Lại hoán đổi để loại bỏ nút gốc 11.`

![image](https://github.com/minchangggg/DSA/assets/125820144/be9135b5-30ad-4d31-8f20-7bf6434f754d)

`Xóa bỏ nút gốc 11.`

![image](https://github.com/minchangggg/DSA/assets/125820144/e2cc880f-4c6a-4836-b454-46b1fb6653d5)

`Lại tạo cấu trúc Heap`

![image](https://github.com/minchangggg/DSA/assets/125820144/8f8c595a-5121-47a1-95f7-1bcb83d2f213)

`Hoán đổi để loại bỏ nút gốc 8.`

![image](https://github.com/minchangggg/DSA/assets/125820144/d294c2c7-f9c5-4e84-810c-3729bd137649)

`Xóa nút gốc 8.`

![image](https://github.com/minchangggg/DSA/assets/125820144/10aaf023-5831-4785-bd3b-e2cb9d557968)

`Tạo Heap`

![image](https://github.com/minchangggg/DSA/assets/125820144/7adeee6e-c25d-461e-b6c4-14dc390ba964)

`Hoán đổi để loại bỏ nút gốc 7.`

![image](https://github.com/minchangggg/DSA/assets/125820144/8ac6cad6-4951-43ef-9ad3-c2be2b1ba274)

`Xóa nút gốc 7`

![image](https://github.com/minchangggg/DSA/assets/125820144/aade5954-1f54-47aa-8030-798c43b86d0a)

`Các phần tử đã được sắp xếp đúng`

### c. Độ phức tạp của giải thuật :
- Thủ tục updateHeapAt (...) có độ phức tạp là O(log(n)) : Do số lần duyệt của thủ tục này cỡ bằng độ sâu của cây nhị phân
- Đối với thủ tục heapSort, ta có thể đánh giá độ phức tạp một cách tương đối như sau :
   + Vòng for đầu tiên : O(log(n/2) + log(n/2 + 1) + ... + log(n)) <= O(n.log(n))
   + Vòng for thứ hai : O(log(n) + log(n-1) + ... + log(1)) <= O(n.log(n))

-> Như vậy, độ phức tạp của giải thuật Heap Sort là : O(n.log(n))
## d. Nhận xét và đánh giá
- Ưu điểm :
   + Khá nhanh (O(n.log(n)), tuy nhiên trong thực nghiệm lại kém hơn so với giải thuật QuickSort và MergeSort.
   + Cấu trúc dữ liệu dạng vun đống được sử dụng rộng rãi trong nhiều bài toán
   + Heap Sort là một giải thuật sắp xếp tại chỗ
- Nhược điểm :
   + Với cách cài đặt trên, giải thuật này chưa có tính chất ổn định. Tuy nhiên, có thể cài đặt giải thuật trên để nó có tính chất ổn định, hãy tham khảo từ nguồn sau đây: http://www.geeksforgeeks.org/stability-in-sorting-algorithms/
   + Hơi phức tạp trong cài đặt giải thuật
- Sự tối ưu và ứng dụng thực tế
> Một số ứng dụng của Sắp xếp vun đống có thể kể tới :
>
> Sort a nearly sorted array : http://www.geeksforgeeks.org/nearly-sorted-algorithm/
>
> K largest (or smallest) elements in an array : http://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
>
> Applications of Heap Data Structure : http://www.geeksforgeeks.org/applications-of-heap-data-structure/
## e. Ví dụ
		#include <iostream>
		using namespace std;
		
		// To heapify a subtree rooted with node i which is an index in arr[]. 
		// n is size of heap
		void heapify(int arr[], int N, int i) {
		    int largest = i; // Initialize largest as root
		    int l = 2 * i + 1; // left = 2*i + 1
		    int r = 2 * i + 2; // right = 2*i + 2
		
		    // If left child is larger than root
		    if (l < N && arr[l] > arr[largest]) largest = l;
		
		    // If right child is larger than largest so far
		    if (r < N && arr[r] > arr[largest]) largest = r;
		
		    // If largest is not root
		    if (largest != i) {
		        swap(arr[i], arr[largest]);
		        // Recursively heapify the affected sub-tree
		        heapify(arr, N, largest);
		    }
		}
		
		// Main function to do heap sort
		void heapSort(int arr[], int N) {
		    // Build heap (rearrange array)
		    for (int i = N / 2 - 1; i >= 0; i--) heapify(arr, N, i);
		
		    // One by one extract an element from heap
		    for (int i = N - 1; i > 0; i--) {
		        swap(arr[0], arr[i]); // Move current root to end
		
		        heapify(arr, i, 0); // call max heapify on the reduced heap
		    }
		}
		
		int main() {
		    int arr[] = { 12, 11, 13, 5, 6, 7 };
		    int N = sizeof(arr) / sizeof(arr[0]);
		    heapSort(arr, N);
		
		    cout << "Sorted array is ";
		    for (int x : arr) cout << x << ' ';
		}

> Output

		Sorted array is 5 6 7 11 12 13 
# 6. Thuật toán Quick Sort (Sắp xếp nhanh)
> https://www.geeksforgeeks.org/quick-sort-algorithm/
> 
> https://www.youtube.com/watch?v=x1BMc7MEjnk&list=PLoaAbmGPgTSNMAzkKBHkh2mLuBk54II5L&index=44
## a. Mã nguồn minh họa :
### Source 1
`Thao tác phân hoạch bằng Lomuto partition:`

int partition(int a[], int l, int r){
	int pivot = a[r];
	int i = l - 1;
	for(int j = l; j < r; j++){
		if(a[j] <= pivot){
			++i;
			swap(a[i], a[j]);
		}
	}
	++i;
	swap(a[i], a[r]);
	return i;
}

`Hàm quick soft và main:`

	void quicksort(int a[], int l, int r){
		if(l < r){
			int m = (l + r) / 2;
			int p = partition(a, l, r);
			quicksort(a, l, p - 1);
			quicksort(a, p + 1, r);
		}
	}
	int main(){
		int n; cin >> n;
		int a[n];
		for(int &x : a) cin >> x;
		quicksort(a, 0, n - 1);
		for(int x : a) cout << x << ' ';
	}

### Source 2
    public static void swap(double[] unsortedArray, int index1, int index2) {
        double intermediate = unsortedArray[index1];
        unsortedArray[index1] = unsortedArray[index2];
        unsortedArray[index2] = intermediate;
    }
    
    // Partition with the first element as the pivot
    public static int firstPivotPartition(double[] unsortedArray, int left, int right) {
        int lastOfFirstPartitionIndex = left;
        int firstOfSecondPartitionIndex = right + 1;
        double pivot = unsortedArray[left];
        
        while(lastOfFirstPartitionIndex < firstOfSecondPartitionIndex) {
            ++lastOfFirstPartitionIndex;
            while((lastOfFirstPartitionIndex <= right) && (unsortedArray[lastOfFirstPartitionIndex] <= pivot))
                lastOfFirstPartitionIndex++;
            
            --firstOfSecondPartitionIndex;
            while((firstOfSecondPartitionIndex > left) && (unsortedArray[firstOfSecondPartitionIndex] > pivot)) 
                firstOfSecondPartitionIndex--;
            
            if(lastOfFirstPartitionIndex <= right) // avoid arising the exception ArrayIndexOutOfBoundsException when lastOfFirstPartitionIndex > right
                swap(unsortedArray, lastOfFirstPartitionIndex, firstOfSecondPartitionIndex);
        }
        if(lastOfFirstPartitionIndex <= right) // avoid arising the exception ArrayIndexOutOfBoundsException when lastOfFirstPartitionIndex > right
            swap(unsortedArray, lastOfFirstPartitionIndex, firstOfSecondPartitionIndex);
        swap(unsortedArray, firstOfSecondPartitionIndex, left);
        
        return firstOfSecondPartitionIndex;
    }
    
    // Partition with the middle element as the pivot
    public static int middlePivotPartition(double[] unsortedArray, int left, int right) {
        int middle = (left + right) / 2;
        swap(unsortedArray, middle, left);
        double pivot = unsortedArray[left];
        int lastOfFirstPartitionIndex = left + 1;
        int firstOfSecondPartitionIndex = right;
  
        while(lastOfFirstPartitionIndex <= firstOfSecondPartitionIndex) { // must have sign '=' when sorting an array that contains 2 elements
            
            while((lastOfFirstPartitionIndex <= firstOfSecondPartitionIndex) && (unsortedArray[lastOfFirstPartitionIndex] <= pivot))
                lastOfFirstPartitionIndex++;
            
            while(unsortedArray[firstOfSecondPartitionIndex] > pivot) 
                firstOfSecondPartitionIndex--;
                 
            if(lastOfFirstPartitionIndex <= firstOfSecondPartitionIndex) {
                swap(unsortedArray, lastOfFirstPartitionIndex, firstOfSecondPartitionIndex);
                ++lastOfFirstPartitionIndex;
                --firstOfSecondPartitionIndex;
            }
        }
        swap(unsortedArray, left, firstOfSecondPartitionIndex);

        return firstOfSecondPartitionIndex;
    }
    
    // partition with the last element as the pivot
    public static int lastPivotPartition(double[] unsortedArray, int left, int right) {
        double pivot = unsortedArray[right];
        int lastOfFirstPartition = left - 1;
        
        for(int lastOfSecondPartition = left; lastOfSecondPartition <= right - 1; lastOfSecondPartition++ ) {
            if(unsortedArray[lastOfSecondPartition] <= pivot) {
                lastOfFirstPartition++;
                swap(unsortedArray, lastOfFirstPartition, lastOfSecondPartition);
            }
        }
        swap(unsortedArray, lastOfFirstPartition + 1, right);
        
        return lastOfFirstPartition + 1;
    }
    
    // Quick Sort algorithm using the first element as the pivot
    public static void firstQuickSort(double[] unsortedArray, int left, int right) {
        if(left < right) {
            int pointOfPartition = firstPivotPartition(unsortedArray, left, right);
            firstQuickSort(unsortedArray, left, pointOfPartition - 1);
            firstQuickSort(unsortedArray, pointOfPartition + 1, right);
        }
    }    

     // Quick Sort algorithm using the middle element as the pivot
    public static void middleQuickSort(double[] unsortedArray, int left, int right) {
        if(left < right) {
            int pointOfPartition = middlePivotPartition(unsortedArray, left, right);
            middleQuickSort(unsortedArray, left, pointOfPartition - 1);
            middleQuickSort(unsortedArray, pointOfPartition + 1, right);
        }
    }
    
    // Quick Sort algorithm using the last element as the pivot
    public static void lastQuickSort(double[] unsortedArray, int left, int right) {
        if(left < right) {
            int pointOfPartition = lastPivotPartition(unsortedArray, left, right);
            lastQuickSort(unsortedArray, left, pointOfPartition - 1);
            lastQuickSort(unsortedArray, pointOfPartition + 1, right);
        }
    }
## b. Tư tưởng của giải thuật
Giải thuật Quick Sort với tư tưởng chính :

- Lựa chọn một phần tử trong mảng đóng vai trò như một pivot, sau đó từ giá trị pivot này tiến hành phân lớp mảng thành 2 phần với một phần chỉ toàn gồm các phần tử nhỏ hơn hoặc bằng pivot, trong khi phần còn lại chứa các phần tử lớn hơn pivot.
- Từ hai nửa còn lại ( không xét tới phần tử pivot, bởi vì vị trí của nó đã là cố định), ta tiến hành gọi một cách đệ quy hàm quickSort(...) trên từng nửa đó. Kết quả cuối cùng ta thu được, đó là mảng ban đầu đã được sắp xếp Vấn đề của thao tác lựa chọn Pivot :
- Có một câu hỏi được đặt ra đó là làm sao để lựa chọn 1 phần tử pivot tốt nhất có thể (tức giá trị của nó nằm ở mức trung bình so với các phần tử còn lại). Dưới đây là một vài đề xuất lựa chọn pivot mà chúng ta có thể tham khảo :
   + Lựa chọn pivot nằm ở đầu mảng
   + Lựa chọn Pivot nằm ở cuối mảng
   + Lựa chọn Pivot một cách bất kỳ và tùy ý
   + Lựa chọn Pivot tại chỉ số index = (left + right) / 2
- Phía trên mình đã trình bày các cách cài đặt của từng sự lựa chọn Pivot thông qua ngôn ngữ Java, với một vài điểm chú ý có thể kể tới như sau :
   + Giải thuật lựa chọn Pivot nằm đầu và cuối mảng được xây dựng theo hai cách mang 2 tư tưởng khá khác biệt
   + Giải thuật lựa chọn pivot bất kỳ, hay lựa chọn pivot nằm ở chỉ số trung bình... được quy về cách lựa chọn pivot nằm ở đầu và cuối mảng ( chỉ với một thao tác đơn giản là hoán vị tương ứng pivot đó với phần tử ở đầu (hoặc cuối) mảng). Trong giải thuật này, mình xin để xuất đưa về cách cài đặt chọn pivot ở đầu mảng
## c. Độ phức tạp của giải thuật
- Độ phức tạp của giải thuật QuickSort là : T(n) = T(k) + T(n-k-1) + O(n) , với k là số phần tử bên nửa trái. Từ đó, trong từng trường hợp :
   + Tồi tệ nhất, ứng với k = 0 : T(n) = T(0) + T(n-1) + O(n) = T(n-1) + O(n) = O(n^2)
   + Tốt nhất, ứng với k = n/2 T(n) = 2T(n/2) + O(n) = O(nlog(n))
   + Trung bình : T(n) = O(nlog(n))
## d. Nhận xét và đánh giá
- Mặc dù, thuật toán có độ phức tạp O(n^2) đối với trường hợp tồi tệ nhất. Tuy nhiên trong thực nghiệm, độ phức tạp trung bình của giải thuật ổn định ở mức O(n.log(n))
- Là một trong số những giải thuật có tốc độ nhanh, hiệu quả và phổ biến top đầu lớp các giải thuật sắp xếp ( QuickSort, HeapSort, MergeSort)
- Giải thuật có tính “tại chỗ”, nhưng không ổn định
- Hoạt động tối ưu hơn khi cài đặt sử dụng mảng
- Có sự hạn chế khi cài đặt giải thuật sử dụng cấu trúc dữ liệu Danh sách Liên kết (bởi vì trong giải thuật Quick Sort có khá nhiều thao tác so sánh, và cần phải thường xuyên truy xuất phần tử … nên cần tiêu tốn một khoảng thời gian tuyến tính để tìm phần tử đó trong dánh sách liên kết)
- Tối ưu và các bài toán ứng dụng
   + Tối ưu 1 : Sử dụng phương pháp Quick 3 chiều, có nghĩa là sau khi lựa được giá trị pivot, ta sẽ chia mảng thành 3 phần, gồm các phần tử nhỏ hơn pivot, bằng pivot và lớn hơn pivot ( details at following link : http://www.geeksforgeeks.org/quick-sort/)
   + Tối ưu 2 : Đối với việc lựa chọn pivot luôn nằm ở cực trái ( hoặc cực phải) của mảng mang tới nguy cơ dẫn tới các trường hợp tồi tệ nhất, tức : Mảng đã được sắp xếp theo đúng thứ tự, hoặc mảng đã được sắp xếp theo thứ tự ngược lại, hoặc tất cả các phần tử của mảng đều bằng nhau. Để hạn chế được các tình huống trên, ta sẽ lựa chọn pivot theo những cách khác, như: pivot nằm ở index trung bình, pivot có index ngẫu nhiên, … Sau đó ta có thể dễ dàng quy các bài toán này về bài toán chọn pivot nằm ở cực trái hoặc cực phải
   + Tối ưu 3 : Mặc dù thuật toán QuickSort có tính ổn định, tuy nhiên nó vẫn sử dụng bộ nhớ để lưu các lời gọi đệ quy, trong các trường hợp tồi tệ nó có thể tốn tới lượng bộ nhớ O(n) tức tuyến tính với số lượng phần tử của dãy số. Một số giải pháp tối ưu : Khử đệ quy (http://www.geeksforgeeks.org/iterative-quick-sort/), sử dụng lời gọi đệ quy đuôi (tail call, details at this link : http://www.geeksforgeeks.org/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/)
   + Tối ưu 4 : Sử dụng một ưu điểm của giải thuật Insertion Sort, đó là nó sẽ tỏ ra nổi bật khi sắp xếp một lượng dữ liệu nhỏ. Vì vậy, ta sẽ áp dụng Insertion Sort vào những giai đoạn khi mà kích thước của mảng đạt tới (<= 7 phần tử) trong giải thuật Quick Sort
- Một số cài đặt Quick Sort sử dụng Danh sách liên kết :
   + Sử dụng danh sách liên kết đơn : http://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
   + Sử dụng danh sách liên kết đôi: http://www.geeksforgeeks.org/quicksort-for-linked-list/
## e. Ví dụ
		#include <bits/stdc++.h>
		using namespace std;
		
		int partition(int arr[],int low,int high) {
		    //choose the pivot
		    int pivot=arr[high];
		    //Index of smaller element and Indicate
		    //the right position of pivot found so far
		    int i=(low-1);
		
		    for(int j=low;j<=high-1;j++) {
		        //If current element is smaller than the pivot
		        if(arr[j]<pivot) {
		            i++; //Increment index of smaller element
		            swap(arr[i],arr[j]);
		        }
		    }
		    swap(arr[i+1],arr[high]);
		    return (i+1);
		}
		
		// The Quicksort function Implement   
		void quickSort(int arr[],int low,int high) {
		    // when low is less than high
		    if(low<high) {
		        // pi is the partition return index of pivot
		        int pi=partition(arr,low,high);
		
		        //Recursion Call smaller element than pivot goes left and higher element goes right
		        quickSort(arr,low,pi-1);
		        quickSort(arr,pi+1,high);
		    }
		}     
		 
		int main() {
		    int arr[]={10,7,8,9,1,5};
		    int n=sizeof(arr)/sizeof(arr[0]);
		
		    quickSort(arr,0,n-1);
		    cout<<"Sorted Array: ";
		    for(int x : arr) cout<< x << ' ';
		
		    return 0;
		}

> Output

		Sorted Array: 1 5 7 8 9 10 
# 7.Thuật toán Counting Sort (Sắp xếp đếm phân phối)
## a. Mã nguồn minh họa :
### Source 1
- Điều kiện áp dụng: Có thể khai báo được mảng đếm có số lượng phần tử lớn hơn giá trị lớn nhất của phần tử trong mảng

		int dem[1000001]; // 0 <= a[i] <= 10^6
			void countingSort(int a[], int n){
			int K = -1e9;
			for(int i = 0; i < n; i++){
				dem[a[i]]++;
				K = max(K, a[i]);
			}
			for(int i = 0; i <= K; i++){
				if(dem[i]){
					for(int j = 0; j < dem[i]; j++) cout << i << ' ';
				}
			}
		}
### Source 2
		void countingSort(char *unsortedString) {
			int lenOfString = strlen(unsortedString);
			// create a new array for couting the number of occurences of a character
			int countingArray[RANGE];
			char *temporaryString = new char[lenOfString + 1]; // plus 1 to contain a NULL character at the end of string
			memset(temporaryString, '\0', lenOfString);
			memset(countingArray, 0, sizeof(countingArray)); // same as :  int countingArray[RANGE] = { 0 };
			
			// count the number of occurences of a character
			for (int charIndex = 0; charIndex < lenOfString; charIndex++) {
				++countingArray[unsortedString[charIndex]];
			}
		
			// modify the array above : each value of an element contains its actual position in the sorted string
			for (int index = 1; index < RANGE; index++) {
				countingArray[index] += countingArray[index - 1];
			}
			// From the above array, create a new string arranged in alphabetical order
			char currentChar;
			for (int charIndex = 0; charIndex < lenOfString; charIndex++) {
				currentChar = unsortedString[charIndex];
				temporaryString[countingArray[currentChar] - 1] = currentChar;
				--countingArray[currentChar];
			}
			temporaryString[lenOfString] = '\0';
			// copy all of the characters from the temporary string to the original string
			//strcpy_s(unsortedString, strlen(temporaryString), temporaryString); // ? don't work???
		
			for (int charIndex = 0; charIndex < lenOfString; charIndex++) {
				unsortedString[charIndex] = temporaryString[charIndex];
			}
			unsortedString[lenOfString] = '\0';
		}
## b. Ý tưởng của giải thuật
Giải thuật được xuất phát từ ý tưởng “Đếm” áp dụng cho dãy số nguyên được thể hiện như sau :

- Chọn một miền giá trị bao phủ được tất cả các giá trị của từng phần tử trong mảng, sau đó tạo mới một mảng trung gian có sức chứa bằng đúng số vạch chia đơn vị trong miền giá trị (được lựa chọn trên). Gán giá trị cho tất cả phần tử trong mảng bằng 0
- Như vậy, giá trị của mỗi phần tử từ dãy số ban đầu sẽ được thể hiện bằng giá trị của chỉ số trong mảng trung gian. Tiếp theo, tiến hành duyệt từng phần tử của mảng gốc, ứng với mỗi phần tử xuất hiện trong mảng gốc này sẽ được cộng thêm 1 vào phần tử có chỉ số bằng với giá trị của phần tử trong mảng gốc. Sau khi duyệt xong toàn bộ mảng gốc, mảng trung gian lúc này sẽ chứa số lần xuất hiện của các phần tử trong mảng gốc trong dãy số ban đầu
- Tiếp tục khai thác và chế biến mảng trung gian để nó trở nên hữu ích hơn bằng cách duyệt từng phần tử của mảng trung gian, từ phần tử thứ 2 trở đi. Sau đó cộng dồn phần tử hiện tại với phần tử trước đó và gán lại vào phần tử hiện tại. Cứ như vậy, tới khi duyệt hết mảng, ta sẽ thu được một mảng trung gian vô cũng hữu ích, lúc này giá trị của trong mỗi phần tử trung gian sẽ cho biết giá trị index thực sự của giá trị gốc đó trong mảng khi đã được sắp xếp
- Thao tác cuối cùng, chỉ đơn giản là duyệt lại mảng gốc, kết hợp với mảng trung gian để lấy ra các phần tử tương ứng theo thứ tự đã được sắp xếp!!!
## c. Độ phức tạp của giải thuật :
Thủ tục countingSort yêu cầu duyệt qua n phần tử từ dãy số gốc, và m phần tử (số vạch chia trong miền giá trị bao phủ). Do vậy, độ phức tạp sẽ là : O(n+m)
## d. Nhận xét và đánh giá :
- Thuật toán chỉ hiệu quả khi mà miền giá trị của dữ liệu không lớn hơn quá nhiều so với tổng số phần tử trong mảng gốc. Nó sẽ không hiệu quả nếu miền giá trị là một hàm mũ, lũy thừa so với số phần tử cần phải sắp xếp. Vì vậy, cần phải cân nhắc kỹ
Không sử dụng phương pháp sắp xếp dựa trên quá trình so sánh, mà sử dụng chủ yếu vào bộ nhớ lưu trữ
- Tối ưu và ứng dụng thực tế :
   + Giải thuật được sử dụng như một giai đoạn trong giải thuật Radix Sort
   + Giải thuật cũng có thể được mở rộng để làm việc với các số nguyên âm, hay sắp xếp các chuỗi ký tự

# II. Các phương pháp sắp xếp khác
# 8. Thuật toán Radix Sort (Sắp xếp theo cơ số)
## a. Mã nguồn minh họa
		int maximum(int *unsortedArray, int size) {
			int maximumValue = unsortedArray[0];
			for (int index = 1; index < size; index++) {
				if (maximumValue < unsortedArray[index]) maximumValue = unsortedArray[index];
			}
			return maximumValue;
		}
		
		void countingSort(int *unsortedArray, int size, int divisionUnit) {
			int countingKeysArray[10] = { 0 };
			int *sortedArray = new int[size];
			int key;
		
			// Count the number of occurence of each key
			for (int index = 0; index < size; index++) {
				key = (unsortedArray[index] / divisionUnit) % 10;
				++countingKeysArray[key];
			}
		
			// Determine actual positions of all elements in the array
			for (int key = 1; key < 10; key++) {
				countingKeysArray[key] += countingKeysArray[key - 1];
			}
			
			// Create an new sorted array from the above array
			// Must go down from size - 1 to 0 because it helps to maintain
			//relative stability of the sorted array at the previous times
			for (int index = size - 1; index >= 0; index--) {
				key = (unsortedArray[index] / divisionUnit) % 10;
				sortedArray[countingKeysArray[key] - 1] = unsortedArray[index];
				--countingKeysArray[key];
			}
		
			// Save these sorted sequences to the original array 
			for (int index = 0; index < size; index++) {
				unsortedArray[index] = sortedArray[index];
			}
			delete [] sortedArray;
		}
		void radixSort(int *unsortedArray, int size) {
			// Find the maximum value in the unsorted array
			int maximumValue = maximum(unsortedArray, size);
		
			// Devoke the countingSort function for each division unit (1, 10, 100, 1000 ... | divisionUnit < maximumValue)
			for (int divisionUnit = 1; divisionUnit <= maximumValue; divisionUnit *= 10) {
				countingSort(unsortedArray, size, divisionUnit);
			}
		}
## b. Ý tưởng của giải thuật :
- Giải thuật sắp xếp theo cơ số 10 với tư tưởng chính sau:
- Tiến hành sắp xếp tất cả các phần tử trong dãy số ban đầu lần lượt từ hàng đơn vị, hàng chục, hàng trăm,… như các so sánh của con người
Với mỗi thao tác sắp xếp các phần tử là theo một hàng nhất định (đơn vị, chục, trăm…) và miền giá trị ở mỗi hàng là khá nhỏ (từ 0 đến 9), nên trong giải thuật trên tác giả lựa chọn Sắp xếp Đếm (Counting Sort) cho từng quá trình sắp xếp này.
- Như vậy, quá trình trên sử dụng Counting Sort để sắp xếp dãy số từ hàng đơn vị, hàng chục, hàng trăm, … đến hàng cao nhất. Kết thúc quá trình sắp xếp, ta thu được dãy số đã được sắp xếp như mong đợi !
## c. Độ phức tạp của thuật toán :
- Gọi k là số lượng chữ số trong số lớn nhất của dãy số, do thuật toán áp dụng giải thuật Counting Sort để sắp xếp trên từng chữ số. Vì thế độ phức tạp của thuật toán là : d * O(n + b) = O(d * (n+ b)), với b là hệ số (trong giải thuật trên ta chọn hệ số là 10 tức miền giá trị từ 0 đến 9)
## d. Nhận xét và đánh giá :
- Mặc dù giải thuật trên khá nhanh. Tuy nhiên vẫn chưa thể đánh bại giải thuật sắp xếp dựa trên so sánh (như QuickSort, HeapSort, Merge Sort)
# 9.Thuật toán Bucket Sort( Sắp xếp phân cụm)
## a. Mã nguồn minh họa
		void bucketSort(double *unsortedArray, int size) {
			vector<double> *buckets = new vector<double>[size];
			
			// put elements into proper buckets
			int bucketIndex;
			for (int index = 0; index < size; index++) {
				bucketIndex = size * unsortedArray[index];
				buckets[bucketIndex].push_back(unsortedArray[index]);
			}
		
			// using insertion algorithm to sort elements in each bucket ascendingly 
			for (int bucketIndex = 0; bucketIndex < size; bucketIndex++) {
				sort(buckets[bucketIndex].begin(), buckets[bucketIndex].end());
			}
		
			// Copy elements from buckets into the original array
			int originalArrayIndex = 0;
			int sizeOfEachBucket;
			for (int bucketIndex = 0; bucketIndex < size; bucketIndex++) {
				sizeOfEachBucket = buckets[bucketIndex].size();
				for (int insideBucketIndex = 0; insideBucketIndex < sizeOfEachBucket; insideBucketIndex++) {
					unsortedArray[originalArrayIndex] = buckets[bucketIndex][insideBucketIndex];
					++originalArrayIndex;
				}
			}
		}
## b. Ý tưởng của giải thuật
- Giải thuật phân cụm được áp dụng cho lớp bài toán sắp xếp phần tử mà các phần tử trong dãy có sự phân bố đều đặn trong miền giá trị của nó. Giải thuật này được trình bày cụ thể trong bài toán sắp xếp dãy số có miền giá trị từ 0 đến 1, và các phần tử có sự phân bố đều đặn trên miền đó
- Tạo ra n vector hay n mảng được gọi là bucket
- Duyệt các phần tử trong mảng gốc, với mỗi phần tử này ta sẽ đưa nó vào trong một bucket phù hợp (như thế nào là phù hợp? nghĩa là : phần tử có giá trị x sẽ được đưa vào buckets (cụm) có chỉ số là (int) x * n . Như vậy có thể trong một buket có thể chứa nhiều hơn một phần tử (tư tưởng bảng băm)
- Sử dụng ưu thế của giải thuật sắp xếp chèn cho một lượng nhỏ các phần tử. Ta tiến hành thực hiện giải thuật Insertion Sort trên từng cụm bucket. Quá trình này hoàn tất đồng nghĩa với việc tất cả các phần tử trong mỗi bucket đều đã được xếp thứ tự
- Công việc đơn giản cuối cùng chỉ còn là : Duyệt từ bucket đầu tiên tới bucket cuối cùng để lấy ra các phần tử và ghi đè lần lượt vào mảng ban đầu. Kết quả : Mảng ban đầu đã được sắp xếp !
## c. Độ phức tạp của giải thuật
- Trong thủ tục bucketSort, độ phức tạp của từng bước được thể hiện như sau :
- Bước đưa các phần tử vào các bucket phù hợp : O(n)
- Sắp xếp các phần tử trên từng cụm buckets sử dụng Insertion Sort : O(n) (trong trường hợp các phần tử trong dãy số phải được phân bố đều đặn ) Như vậy độ phức tạp của bài toán : O(n)
## d. Nhận xét và đánh giá :
- Giải thuật cho phép độ phức tạp thời gian sắp xếp dãy số theo thời gian tuyến tính trong trường hợp dãy số ban đầu phải được phân bố đều đặn trên miền giá trị của chúng
# 10.Thuật toán Shell Sort (Tối ưu Insertion Sort)
## a. Mã nguồn minh họa
		void shellSort(double *unsortedArray, int size) {
			int interval = 1;
			int comparingIndex, currentIndex;
			double comparingValue;
		
			// Using Knuth's Formular to calculate the interval ( is initialized by 1)
			while (interval <= (size / 3)) {
				interval = interval * 3 + 1;
			}
		
			// 'Interval' specifies the distance in comparison. This algorithm's idea is similar to Insertion Algorithm, but with a specified distance for comparing
			while (interval > 0) {
				for (comparingIndex = interval; comparingIndex < size; comparingIndex++) {
					comparingValue = unsortedArray[comparingIndex];
					for (currentIndex = comparingIndex; currentIndex >= interval && unsortedArray[currentIndex - interval] > comparingValue; currentIndex -= interval) {
						unsortedArray[currentIndex] = unsortedArray[currentIndex - interval];
					}
					unsortedArray[currentIndex] = comparingValue;
				}
				// reduce the comparing distance until it equals to zero 
				interval = (interval - 1) / 3;
			}
		}
## b. Ý tưởng của giải thuật :
- Đây là một giải thuật giúp tối ưu hơn giải thuật Insertion Sort. Ý tưởng của giải thuật được thể hiện như sau :
- Bình thường trong giải thuật Insertion Sort (trong ví dụ Người chơi bài), người chơi bài sẽ so sánh quân bài hiện tại với lần lượt các quân bài phía trước. Một để xuất tối ưu được đưa ra đó là, thay vì cứ thao tác cứ "chăm chăm" so sánh với các phần từ liền kề phía trước, họ nảy sinh một ý tưởng : Tại sao không tiến hành so sánh ngắt quãng (interval) (tức phần tử hiện tại được so sánh với các phần tử phía trước (giống như Insertion sort) nhưng khoảng cách giữa chúng phải là bội của interval (quãng)). Mọi thao tác trong giải thuật này cơ bản sẽ giống hệt với giải thuật Insertion Sort. Tuy nhiên có một điểm khác đặc biệt, đó là bước interval sẽ liên tục giảm sau mỗi lần lặp (quy tắc giảm được tuân theo một công thức đã được thực nghiệm xác định), vậy interval sẽ giảm tới khi nào? Nó sẽ giảm tới khi interval = 1 (tức quãng nhỏ nhất có thể), lúc này bài toán thuần túy trở về nguyên gốc giải thuật insertion sort. Tuy nhiên, bước cuối cùng này chủ yếu mang tính kiểm nghiệm và rà soát một lần nữa, chứ ko làm tiêu tốn quá nhiều các thao tác hoán vị !!!
- Chú ý : Ta cần phải khởi tạo giá trị interval theo công thức của Knuth nhằm đảm bảo thuật toán sẽ làm việc một cách hiệu quả (interval = interval * 3 + 1)
## c. Độ phức tạp của giải thuật
- Dù đã có sự cải tiến tuy nhiên độ phức tạp của thuật toán trên vẫn cỡ O(n^2)
## d. Nhận xét và đánh giá
- Đây là giải thuật tối ưu hóa giải thuật Insertion Sort
- Sử dụng công thức Knuth để tỉm ra interval phù hợp (interval = interval * 3 + 1)
# 11. Thuật toán Comb Sort ( cải tiến giải thuật Bubble Sort)
## a. Mã nguồn minh họa :
		void combSort(double *unsortedArray, int size) {
			int startingPointOfGap = size; // means first point of sequences is compared
			bool hasSwapped = true; // keep track of an array until it is sorted ascendingly (means have not any swapping in the array comparison process)
			// when 2 conditions occur simultaneously : 
			//not have any swapping ( means the arrays has been sorted successfully) 
			// and startingPointOfGap == 1 (this condition can not ignore, when this variable equals to 1, it will waits hasSwapped variable until that variable equals to false to stop while loop)
			while (startingPointOfGap != 1 || hasSwapped == true) {
				startingPointOfGap = getNextGap(startingPointOfGap); // shrink gradually the gap
				hasSwapped = false;
				for (int comparingIndex = startingPointOfGap; comparingIndex < size; comparingIndex++) {
					if (unsortedArray[comparingIndex] < unsortedArray[comparingIndex - startingPointOfGap]) {
						swap(&unsortedArray[comparingIndex], &unsortedArray[comparingIndex - startingPointOfGap]);
						hasSwapped = true;
					}
				}
			}
		}
		
		int getNextGap(int gap) {
			// The gap will be shinked by the following formular (based on practical experience)
			gap = (gap * 10) / 13;
			if (gap < 1) return 1;
			return gap;
		}
		
		// swap two values
		void swap(double *num1, double *num2) {
			double intermediateValue = *num1;
			*num1 = *num2;
			*num2 = intermediateValue;
		}
## b. Ý tưởng của giải thuật :
- Giải thuật này là một sự cải tiến cho giải thuật Sắp xếp Nổi bọt (Bubble Sort). Tư tưởng chủ đạo của giải thuật này được thể hiện một cách cụ thể như sau :
- Đối với giải thuật sắp xếp nổi bọt, quá trình so sánh và hoán vị được thực hiện trên các phần tử liền kề, liên tiếp. Sự sáng tạo trong phương pháp tối ưu của giải thuật này được thể hiện bằng việc sử dụng phương pháp so sánh ngắt quãng (như trong giải thuật Shell Sort), ta gọi các quãng này là gap. Ban đầu gap được khởi tạo bằng kích cỡ của mảng, trong quá trình lặp ta cần phải thu nhỏ, hay làm giảm giá trị của gap bằng một hệ số đã được kiểm định là : 1.3 (tức là cứ sau mỗi lần lặp, giá trị của gap sẽ giảm đi 1.3 lần). Các thao tác lúc này diễn ra cơ bản rất giống với Insertion Sort. Nó cứ tiếp diễn, cho tới khi gap = 1, lúc này giải thuật đã thực sự “quy chụp” về đúng giải thuật Insertion Sort với quãng so sánh = 1.
- Tuy nhiên, do việc giảm gap khá nhanh, nên tác giả giải thuật đã lồng ghép vào đó một biến hasSwapped. Biến này có ý nghĩa vô cùng quan trọng. Vậy nó quan trọng như thế nào? Nếu không có nó liệu kết quả có còn đúng đắn? Nhìn vào giải thuật trên, cụ thể điều kiện lặp trong vòng while, ta phát hiện thấy : Vòng while sẽ chỉ dừng khi phải thỏa mãn đồng thời cả 2 điều kiện sau : quãng gap phải giảm về 1 đồng thời không còn bất kỳ sự hoán đổi nào trong lần duyệt trước. Điều này là hoàn toàn đúng đắn ( do tính hội tụ nhanh của gap, nên bắt buộc phải có một biến hasSwapped để kiểm soát tính “đã sắp xếp” của dãy số ban đầu)
## c. Độ phức tạp của giải thuật
- Dù có một sự cải tiến đáng kể, nhưng độ phức tạp của giải thuật vẫn cỡ O(n^2)
## d. Nhận xét và đánh giá
- Giải thuật là một sự cải tiến từ giải thuật Bubble Sort truyền thống với tư duy “so sánh theo quãng” khá hay
- Hãy chú tới nhân tố giúp “hội tụ” hay co hẹp giá trị của gap (quãng) là : 1.3 (theo thực nghiệm)
# 12. Thuật toán Pigeonhole Sort (Sắp xếp nhốt chim vào lồng)
## a. Mã nguồn minh họa
		void pigeonHoleSort(int *unsortedArray, int size) {
			// Find the maximum and minimum in the original array
			int maxValue = unsortedArray[0], minValue = unsortedArray[0];
			for (int index = 0; index < size; index++) {
				if (maxValue < unsortedArray[index]) 
					maxValue = unsortedArray[index];		
				if (minValue > unsortedArray[index]) 
					minValue = unsortedArray[index];		
			}
		
			// Calculate the maximum range as following formular 
			int range = maxValue - minValue + 1;
			vector<int> *holes = new vector<int>[range]; // create new holes to put the birds there
			int pigeonValue;
			// put birds into proper cages
			for (int pigeonIndex = 0; pigeonIndex < size; pigeonIndex++) {
				pigeonValue = unsortedArray[pigeonIndex];
				holes[pigeonValue - minValue].push_back(pigeonValue);
			}
			// From the pigeon cages, put those pigeons into original array ascendingly 
			int originalArrayIndex = 0;
			for (int holeIndex = 0; holeIndex < range; holeIndex++) {
				vector<int>::iterator insideHolePointer;
				for (insideHolePointer = holes[holeIndex].begin(); insideHolePointer != holes[holeIndex].end(); ++insideHolePointer) {
					unsortedArray[originalArrayIndex] = *insideHolePointer;
					++originalArrayIndex;
				}
			}
		
			delete[] holes;
		
		}
## b. Ý tưởng của thuật toán :
- Thuật toán xuất phát từ ý tưởng nhốt chim vào lồng áp dụng cho các số nguyên được thể hiện như sau :
- Đầu tiên, duyệt toàn bộ các phần tử trong mảng để tìm ra phần tử lớn nhất và nhỏ nhất trong mảng. Trừ hai giá trị này cho nhau, ta thu được một miền giá trị.
- Từ miền giá trị này, ta tạo ra một tập các lồng chim, có số lượng bằng số vạch chia đơn vị trong miền giá trị đó
- Duyệt dãy số ban đầu (tức tập các con chim bồ câu có gắn các số ngẫu nhiên ), với mỗi giá trị số trên từng con chim, ta sẽ tương ứng nhốt nó vào một chiếc lồng thích hợp (lồng thích hợp là chiếc lồng có chỉ số index bằng với giá trị số trên con chim đó). Sau khi duyệt xong toàn bộ, tất cả các chú chim đã được nhốt vào lồng. Như vậy, các con chim bồ câu có cùng giá trị sẽ nằm trong cùng một lồng. Từ các lồng trên, ta sẽ biết được vị trí chính xác của mỗi con chim bồ câu theo một thứ tự sắp xếp tăng dần
- Công việc còn lại chỉ đơn giản là mở từ lồng thứ nhất đến lồng cuối cùng để đưa lần lượt từng chú chim bồ câu nối đuôi nhau đi ra ngoài. Thứ tự bước ra ngoài của các con chim bồ câu đó chính là thứ tự sắp xếp tăng dần mà ta cần tìm !!!
## c. Độ phức tạp của giải thuật :
- Do bài toán cần phải duyệt qua m chiếc lồng, và n chú chim. Nên độ phức tạp của giải thuật sẽ là : O(n+m)
## d. Nhận xét và đánh giá
- Yêu cầu của giải thuật Nhốt chim vào lồng : Số lượng các phần tử và miền giá trị của chúng phải khá gần nhau
