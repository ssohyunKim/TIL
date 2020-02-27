#include <iostream>
#include <vector>
using namespace std;

int ans[100][100001];
vector<pair<int,int> > profit;
int n, w, v, k;
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k; // n:물품의 수, k:버틸 수 있는 무게
    
    for(int i=0; i<n; i++){
        cin >> w >> v;
        profit.push_back(make_pair(w,v));
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){
            // 처음이고, 무게가 넣을 수 있으면 넣는다.
            if(i==0){
                if(profit[i].first <= j){
                    ans[i][j] = profit[i].second;
                }
                continue;
            }
            //넣으려는 물건이 무게조건을 충족했을 때는 이전물건의 가치와 이전물건에 현재 물건을 넣었을때의 가치 중에 큰 값을 가진다.
            if(profit[i].first <= j){
                ans[i][j] = max(ans[i-1][j], ans[i-1][j-profit[i].first] + profit[i].second);
            }else{ // 무게조건을 충족하지 못하면 이전 물건의 가치로 한다.
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    cout << ans[n-1][k] << "\n";
}
// + 다른 풀이)
// #include <iostream>
// #include <algorithm>
// using namespace std;
//  int d[101][100001];
//  int w[101],v[101];

// int main() {
//      int n,k,i,j;
//      cin >> n >> k;
//      for(int i=1; i<=n; i++)
// 	        cin>>w[i]>>v[i];
//      for(i=1; i<=n; i++){
//           for(j=1; j<=k; j++){
//                 if(w[i]>j){
//                     d[i][j] = d[i-1][j];
//                 }else{
//                     d[i][j]=max(d[i-1][j],d[i-1][j-w[i]]+v[i]);
//                 }
//            }
//       } 
//       cout << d[n][k];
//       return 0;
// }