#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool find(vector<int> num, vector<pair<int,int>> answer, int i){
    string target = to_string(i);
    int strike = 0;
    int ball =0;
    int count =0;
    for(int j=0; j<num.size(); j++){
        string target2 = to_string(num[j]);
        for(int k=0; k<3; k++){
            for(int h=0; h<3; h++){
                if(target2[k]==target[h]){
					if(k==h){
                        strike++;
                        break;
                    }
                    else{
                        ball++;                        
                        break;
                    }
				}
            }
        }
        
        if(strike == answer[j].first && ball == answer[j].second){
			count++;
			//cout << "numsize : "<<num.size()<<"i :"<<i<<" strike : "<< strike <<" ball : "<< ball <<" count : "<<count <<'\n';
		}  
        strike =0;
        ball =0;
    }
    if(count == num.size())
        return true;
    else
        return false;
}
int main(){
    int a;
    cin >> a;
    vector<int> num;
    vector<pair<int,int>> answer;
    while(a--){
        int n;
        cin >> n;
        num.push_back(n);
        int p,q;
        cin >> p >> q;
        answer.push_back(make_pair(p,q));
    }
    int count =0;
    for(int i=123; i<=987; i++){
        string number = to_string(i);
        if((number[0]!=number[1]) && (number[0]!=number[2]) && (number[1]!=number[2]) && (number[0]!='0') && (number[1]!='0') && (number[2]!='0'))
            if(find(num, answer,i))
                count ++;
    }
    cout << count <<'\n';
    
    return 0;
}