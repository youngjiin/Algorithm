#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, K ;
    cin >> N >> K;
    int w[101];
    int v[101];
    int n = N;
    while( n --){
        cin >> w[N-n] >> v[N-n] ;
    }
    int d[101][100001] = {0};
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            d[i][j] = d[i-1][j];
            if(j-w[i]>=0)
                d[i][j] = max(d[i][j], d[i-1][j-w[i]]+v[i]);
        }
    }
    cout <<d[N][K]<<'\n';
    return 0;
}