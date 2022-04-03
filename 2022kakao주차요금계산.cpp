#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <set>
#include <iostream>
using namespace std;

int get_ftime(int In_htime, int In_mtime, int h_time, int m_time){
	if(m_time - In_mtime < 0){
        h_time--;
        m_time+=60;
    }
    int du_h = h_time - In_htime;
    int du_m = m_time - In_mtime;
    int f_time = du_h*60 + du_m;
    return f_time;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    //가격 계산 : 기본요금 + ((총 시간 - 기본 시간) / 단위 시간)*단위 요금
    // 총시간- 기본시간 < 0 => 기본요금
    // 차량번호가 작은차부터 차례로 담아서 Return
    int base_time = fees[0];
    int base_fee = fees[1];
    int stand_time = fees[2];
    int stand_fee = fees[3];
    
    unordered_map<int,pair<pair<int,int>,int>> num2index; // <차량번호, <<들어온시간,들어온분>,시간>>
    unordered_map<int, int> InorOut; // <차량번호, in or out>
    // out 이면 -1 로 reset
    for(int i=0; i<records.size(); i++){
        int car_num = stoi(records[i].substr(6, 4));
        int h_time = stoi(records[i].substr(0,2));
        int m_time = stoi(records[i].substr(3,2));
        
        if(records[i][11] == 'I'){
            if(num2index.find(car_num)!=num2index.end()){
                num2index[car_num].first.first = h_time;
                num2index[car_num].first.second = m_time;
            }else{
                num2index[car_num] = {{h_time, m_time}, 0};
            }
            InorOut[car_num] = 0;    
        }else{
            int In_htime = num2index[car_num].first.first;
            int In_mtime = num2index[car_num].first.second;
            int f_time = get_ftime(In_htime, In_mtime, h_time, m_time);
            
            num2index[car_num].second += f_time;
	    InorOut[car_num] = 1;
        }
        
    }
    
    set<pair<int,int>> s;
    for(auto it = InorOut.begin(); it!=InorOut.end(); it++){
	int car_num = (*it).first;
        int f_time = num2index[car_num].second;
        if((*it).second == 0){
	    int h_time = 23;
	    int m_time = 59;
	    int In_htime = num2index[car_num].first.first;
            int In_mtime = num2index[car_num].first.second;
	    f_time += get_ftime(In_htime, In_mtime, h_time, m_time);
	}
        int fee = base_fee;
        if(f_time - base_time>0){
            fee += ceil(float(f_time - base_time) / float(stand_time))*stand_fee;
        }
        s.insert({car_num, fee});
    }
    
    for(auto it = s.begin(); it!=s.end(); it++){
	answer.push_back((*it).second);
    }
    return answer;
}
