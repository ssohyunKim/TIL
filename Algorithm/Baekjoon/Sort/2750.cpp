#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int n,k;
    cin >> n;

    int *array = new int[n];
    
    for(int i=0; i<n; i++){
        cin >> k;
        array[i] = k;
    }
    
    sort(array, array+n);

    for(int i=0; i<n; i++){
        cout << array[i] << endl;
    }
}