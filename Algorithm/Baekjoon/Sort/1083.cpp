#include<iostream>

using namespace std;

int a[50];
int n, s;

void newSort() {
   for (int i = 0;i < n;i++) {
      int max = a[i];  // 가장 큰 값을 저장하기 위한 변수
      int l = i;	   // 가장 큰 값일 때, 그 때의 인덱스 값을 저장하기 위한 변수 
      for (int j = i+1; j <= i + s; j++) {  
         if (j == n) break;	
         if (max < a[j]) {
            max = a[j];
            l = j;
         }
      }
      if (l != i) {
         for (int k = l; k > i; k--) { // 한 칸씩 밀어준다.
            a[k] = a[k - 1];
         }
         a[i] = max;
         s -= (l - i);
      }

      if (s == 0) break;
   }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    cin >> s;
     
    newSort();

    for (int i = 0;i < n;i++){
        cout << a[i] << ' ';
    }
    return 0;
}
