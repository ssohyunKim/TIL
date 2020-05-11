#include <iostream>
using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m, sum, ans=0;

//     cin >> n >> m;

//     int a[n];
//     for(int i=0; i<n; i++){
//         cin >> a[i];
//     }

//     for(int i=0; i<n; i++){
//         sum = 0;
//         for(int j=i; j<n; j++){
//             sum += a[j];
//             if(sum > m) break; //시간복잡도 줄인다. 
//             if(sum == m)
//                 ans+=1;
//         }
//     }

//     cout << ans <<"\n";

//     return 0;
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, ans = 0;
    
    cin >> n >> m;

    int left=0, right=0;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int sum = a[0];

    while(left <= right && right < n){
        if(sum < m){
            right ++;
            sum += a[right];
        }else if(sum == m){
            ans += 1;
            right += 1;
            sum += a[right];
        }else if(sum > m){
            sum -= a[left];
            left ++;
        }
    }

    cout << ans <<"\n";

    return 0;
}