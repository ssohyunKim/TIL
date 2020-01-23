#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int money;
    int n = 0;
    
    cin >> money;
    
    money = 1000 - money;
    
    int a[6] = {500, 100, 50, 10, 5, 1};
    
    for(int i=0; i<6; i++){
        if(money == 0){
            break;
        }
        if(money < a[i]){
            continue;
        }
        n += money/a[i];
        money = money - a[i]*(money/a[i]);
    }

// 또 다른 풀이
//    for(int i=0; i<6; i++){
//        if(a[i] <= money){
//            money -= a[i];
//            n++;
//            i--;
//            if(money == 0){
//                break;
//            }
//        }
//    }
    
    cout << n << "\n";
    return 0;
}