#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//답은 맞는데 왜 틀린지 모르겠다

char check(int a, int t, int g, int c, int MAX){
    if(MAX == a){
        return 'A';
    }else if(MAX == t){
        return 'T';
    }else if(MAX == g){
        return 'G';
    }else{
        return 'C';
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;
    int a,t,g,c;
    int sum = 0;
    int MAX;
    string dna="";
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
        MAX = max(a,max(t,max(g,c)));
        sum += (n - MAX);
        dna += check(a,t,g,c,MAX);
    }
    printf("%s\n%d",dna.c_str(),sum);
    return 0;
}
