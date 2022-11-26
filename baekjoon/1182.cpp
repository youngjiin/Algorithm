#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, S;
    vector <int> a;
    cin >> N >> S ;
    int n2 = N;
    while(n2--){
        int num;
        cin >> num;
        a.push_back(num);
    }
    
    int n = 1<<N;   
    //-7 -3 -2 5 8  j1:i2번쨰 10:3번째 11:4번째
    //00001 00010 00011 00100 00101 00110 00111 01000
    int count =0;
    for(int i=1; i< n; i++){
        int sum = 0;
        for(int j=0; j< N; j++){
            if((i&(1<<j))!=0){
                sum+= a[N-j-1];   
            }
        }
        if(sum==S){
            count ++;
		}
    }
    cout << count << '\n';
    return 0;
}