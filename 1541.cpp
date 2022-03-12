#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    string s;
    cin >> s;
    int answer =0;
    queue<int> cal;
    string m;
    bool minus = false;
    int minus_index = 1;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '-' || s[i] == '+'){
            if(s[i] == '+' && !minus){
                minus_index++;
            }
            else{
                minus = true;
            }
            cal.push(stoi(m));
            m = "";
        }else{
            m+= s[i];
            if(i==s.size()-1)
                cal.push(stoi(m));
        }
    }
    for(int i=0; !cal.empty(); i++){
        int temp = cal.front();
        cal.pop();
        if(minus_index <= i)
            answer -= temp;
        else
            answer += temp;
    }
    cout << answer;
    return 0;
}
