#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
    int cycle;
    string cmd;
    string arr;
    int arrlen;
    cin >> cycle ;
    while(cycle--){
        deque<int> tokens;
        cin >> cmd;
        cin >> arrlen;
        cin >> arr;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]!='[' || arr[i]!=']' || arr[i]!=',' || arr[i]!=' '){
                int a = (int)arr[i];
                tokens.push_front(a);
            }
        }
        bool error = false;
        deque<int> tokens2;
        for(int i=0; i<cmd.size(); i++){
            if(cmd[i]=='R'){
                for(int j=0; j<tokens.size(); j++){
                    int a = tokens.back();
                    tokens2.pop_back();
                    tokens2.push_back(a);
                }
                tokens = tokens2;
            }else{
                if(!tokens.empty()){
                    tokens.pop_front();
                }
                else{
                    cout << "error" <<endl;
                    error = true;
                    break;
                }
            }
        }
        if(!error){
            cout << "[" ;
            for(int i=0; i<tokens.size(); i++){
				int a = tokens.front();
                cout << a;
				tokens.pop_front();
                if(i!=tokens.size()){
                    cout <<",";
                }
            }
            cout << "]" ;
        }
    }
    return 0;
}