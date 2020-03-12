#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000

int arr[MAX];
int n,m;
bool check = false;

void BinarySearch(int key){
    int first = 0;
    int last = n-1;
    int mid = 0;

    while(first <= last){
        mid = (first+last)/2;
        if(arr[mid] == key){
            check = true;
            return;
        }else if(arr[mid] > key){
            last = mid -1;
        }else{
            first = mid +1;
        }
    }
    check = false;
    return;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int num;
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> num;
        BinarySearch(num);
        
        if(check){
            cout << 1 << "\n";
        }else{
            cout << 0 << "\n";
        }
    }
    return 0;
}

