#include <iostream>
#include <algorithm>

#define MAX 9
using namespace std;

int n, m;
int num[MAX];
int pick[MAX];
bool visited[MAX];

// N개의 자연수 중에서 M개를 고른 수열
// 같은 수를 여러 번 골라도 된다.
// 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
// 수열은 사전 순으로 증가하는 순서로 출력해야 한다.

void dfs(int cnt) {
   if(cnt == m){
      for(int i=0; i<m; i++){
         cout << pick[i] << " ";
      }
      cout << "\n";
      return;
   }
   for(int i=0; i<n; i++){
       pick[cnt] = num[i];
       dfs(cnt+1);
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   
   cin >> n >> m;
   for(int i=0; i<n; i++){
      cin >> num[i];
   }
   
   sort(num, num+n);
   
   dfs(0);
   
   return 0;
} 