#include <iostream>
using namespace std;
char chess[51][51];
int findNum(int w, int h, int beforenum){
    int minnum =0 ;
    int minnum2 =0 ;
    
    for(int i=w; i<w+8; i++){
        for(int j=h; j<h+8; j++){
            if((i-w+j-h)%2==0 && chess[i][j]=='B')
                minnum++;
            else if((i-w+j-h)%2==1 && chess[i][j]=='W')
                minnum++;
            if((i-w+j-h)%2==0 && chess[i][j]=='W')
                minnum2++;
            else if((i-w+j-h)%2==1 && chess[i][j]=='B')
                minnum2++;
        }
    }
    minnum = minnum<minnum2?minnum:minnum2;
    return minnum<beforenum?minnum:beforenum;
}
int main(){
    int M,N;
    cin >> M >> N;
    
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> chess[i][j] ;
        }
    }
    
    int num =64; // 8 8
    for(int i=0; i<=M-8; i++){
        for(int j=0; j<=N-8; j++){
            num = findNum(i,j,num);
        }
    }
    cout << num <<'\n';
    return 0;
}