#include <iostream>
#include <vector>
using namespace std;

int main(){
    int d[10001];
    vector<int> a;
    int n,k;
    cin >> n >> k;
    int nn = n;
    while(n--){
        int m;
        cin >> m;
        a.push_back(m) ; 
    }
    d[0] = 0;
    for(int i=1; i<=k; i++){
        d[i] = 10001;
    }
    for(int i=0; i<nn; i++){
        for(int j=a[i]; j<=k; j++){
            d[j] = (d[j]<d[j-a[i]]+1)?(d[j]):(d[j-a[i]]+1);
        }
    }
    if(d[k]==10001){
        cout << "-1" <<'\n';
    }
    else
        cout << d[k] << '\n';
    
    
    
    return 0;
}