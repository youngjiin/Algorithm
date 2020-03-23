#include <iostream>

using namespace std;

int main(){
    int d[100000];
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> d[i];
        if(i>0){
            d[i]=(d[i]>d[i]+d[i-1])?d[i]:d[i]+d[i-1];
        }
    }
    int max= -1000;
    for(int i=0; i<n; i++){
        if(max<d[i]){
            max = d[i];
        }
    }
    cout << max << '\n';
    return 0;
}