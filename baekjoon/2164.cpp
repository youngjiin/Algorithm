#include <iostream>
#include <queue>
using namespace std; 

int main(){
    int n;
    cin >> n ;
    queue<int> q;
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    while(n!=1){
        q.pop();
        int a = q.front();
        q.pop();
        q.push(a);
        n--;
    }
    cout << q.front() << endl;
    return 0;
}