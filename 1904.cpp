#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int d[1000000];
    d[0] = 1;
    d[1] = 2;
    for(int i=2; i<n; i++){
        d[i] = d[i-1] + d[i-2];
        d[i]%=15746;
    }
    
    cout << d[n-1] <<'\n';
    return 0;
}