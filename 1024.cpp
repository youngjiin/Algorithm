#include <iostream>
using namespace std;

int main(){
    int N, L;
    cin >> N >> L;
    int ans = -1, i=0;
    for(i = L; i<=100; i++){
        int t = (i*i-1)/2;    
        if((N-t)%i == 0 && (N-t)/i>=0){
            ans = (N-t)/i;
            break;
        }
    }
    for(int j = 0; j<i; j++){
        cout << ans+j <<' ';
        if(ans == -1) break;
    }
}
