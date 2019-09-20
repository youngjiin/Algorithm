#include <iostream>
using namespace std;
int main(){
    int N,k;
    cin >> N >> k;
    int d[1001][1001];
    d[1][1]=1;
    d[1][0]=1;
    for(int i=2; i<=N; i++){
       for(int j=1; j<=k; j++){
           if(j==1)
               d[i][j] = i;
           else if(j==i)
               d[i][j] = 1;
           else
               d[i][j] = ((d[i-1][j]+d[i-1][j-1])%10007) ;
       } 
    }
    cout << d[N][k] << '\n';
    return 0;
}