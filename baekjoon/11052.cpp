#include <iostream>
using namespace std;
int main(){
    int num[1001];
    int d[1001];
    int N;
    cin >> N;
    int n = N;
    while(n--){
        cin >> num[N-n];
    }
    d[0]=0;
    d[1]=num[1];
    for(int i=2; i<=N; i++){
        d[i] = num[1]*i > num[i] ? num[1]*i : num[i] ;
        for(int j=1; j<=(i/2); j++){ //i가 끝일때
            d[i] = d[i] > (d[i-j]+d[j]) ? d[i]: (d[i-j]+d[j]);
        }
    }
    cout << d[N] <<'\n';
    return 0;
}