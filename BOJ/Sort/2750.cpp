#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k;
    cin >> n;

    int *array = new int[n];
    
    for(int i=0; i<n; i++){
        cin >> k;
        array[i] = k;
    }
    
    sort(array, array+n);

    for(int i=0; i<n; i++){
        cout << array[i] << "\n";
    }
}