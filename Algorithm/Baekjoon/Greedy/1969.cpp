#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;
    int a,t,g,c;
    int sum = 0;
    int MAX;
    cin >> n >> m;
    
    char arr[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int j=0; j<m; j++){
        a=0;t=0;g=0;c=0;
        for(int i=0; i<n; i++){
            switch (arr[i][j]) {
                case 'A':
                    a++;
                    break;
                case 'T':
                    t++;
                    break;
                case 'G':
                    g++;
                    break;
                case 'C':
                    c++;
                    break;
            }
        }
        cout << max(a,max(t,max(g,c))) << "\n";
        MAX = max(a,max(t,max(g,c)));
        sum += (n - MAX);
    }
    cout << sum; //haming distance의 합
    return 0;
}
