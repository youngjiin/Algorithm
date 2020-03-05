#include <iostream>
#include <queue>
using namespace std;

int main(void){
    int t;
    cin>>t;
    while(t--){
        int N, M, cnt =0;
        queue <pair<int,int>> q;
        priority_queue <int> pq;
        
        cin >> N >> M;
        for(int i=0; i<N; i++){
            int a;
            cin >> a;
            q.push({i,a}); // 0 , 1
            pq.push(a); // 1
        }
        while(!q.empty()){
            int nowidx =q.front().first; //index, �߿䵵
            int nowval =q.front().second;
            q.pop();
            
            if(pq.top()==nowval){
                pq.pop();
                cnt++;
                if(nowidx==M){
                    cout << cnt << endl;
                    break;
                }
            }
            else{
                q.push({nowidx, nowval});
            }
        }
    }
}