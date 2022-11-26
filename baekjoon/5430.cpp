#include <iostream>
#include <string>
#include <deque>
#include <sstream>
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
		string a="";
		for(int i=0; i<arr.size(); i++){
			if(arr[i]!=',' && arr[i]!='[' && arr[i]!=']'){
				a += arr[i];
			}
			else{
				if(a!=""){
					tokens.push_front(stoi(a));
					//cout << tokens.front() <<endl;
				}
				a = "";
			}
		}	
        bool error = false;
        deque<int> tokens2;
        int Rcount =0;

        for(int i=0; i<cmd.size(); i++){
            if(cmd[i]=='R'){
				Rcount++;
            }else{
                if(!tokens.empty()){
                    if(Rcount%2==0)
                        tokens.pop_back();
                    else
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
			int s = tokens.size();
            for(int i=0; i<s; i++){
                if(Rcount%2 == 0){
                    int a = tokens.back();
                    cout << a;
				    tokens.pop_back();
                }
				else{
                    int a = tokens.front();
                    cout << a;
				    tokens.pop_front();
                }
                if(i!=s-1){
                    cout <<",";
                }
            }
            cout << "]" <<endl;
        }
    }
    return 0;
}