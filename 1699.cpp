#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int d[100001];
    d[0]= 0;
    for(int i=1; i<=N; i++){
		d[i]=i;
        for(int j=2; j*j<=i; j++){
            int da = d[i-(j*j)]+1; 
            d[i]=(da < d[i]?da:d[i]);
        }
    }
    cout << d[N] << '\n';
    return 0;
}