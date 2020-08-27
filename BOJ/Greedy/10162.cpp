//10162. 전자레인지
#include <iostream>
#include <vector>

using namespace std;

int T;
int share;
int answer=0;
vector<int> v;
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   cin >> T;

   //A: 300초, B: 60초, C: 10초
   while (1) {
      if (T % 10 != 0) {
         v.push_back(-1);
         break;
      }
      if (T == 0) break;

      share = T / 300;
      v.push_back(share);
      T = T - (share * 300);

      share = T / 60;
      v.push_back(share);
      T = T - (share * 60);

      share = T / 10;
      v.push_back(share);
      T = T - (share * 10);
   }

   for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
   }

   return 0;
}