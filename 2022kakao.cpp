#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
//신고를 K번이상 당하면 그 당사자한테 메일이 가는데 순서대로 메일이 가는 개수 return (동일신고 중복x)

void split(string origin, string* s1, string* s2) { //문자열 자르기
    int i = 0;
    while (origin[i] != ' ') {
        i++;
    }
    *s1 = origin.substr(0, i);
    *s2 = origin.substr(i + 1);
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, int> index; //hashtable
    int getnum[1000] = { 0, }; //몇번 신고당했는지
    bool choose[1000][1000] = { false, }; //누가 누구신고했는지
    
    vector<int> list_p[1000];//신고한 사람들 목록
    for (int i = 0; i < id_list.size(); i++) {
        index.insert({ id_list[i], i });
        answer.push_back(0);
    }

    for (int i = 0; i < report.size(); i++) {
        string s1 = "", s2 = "";
        split(report[i], &s1, &s2);
        int first = index[s1], second = index[s2];
        if (!choose[first][second]) { //이전에 신고한적 없으면
            getnum[second]++; //신고 개수 더해줌
            list_p[second].push_back(first); //신고한사람 리스트에 넣어줌
        }
        choose[first][second] = true;
    }
    for(int i=0; i<id_list.size(); i++){
        if(getnum[i] >= k){
            for(int j=0; j < list_p[i].size(); j++){ //신고한사람 리스트에 +1씩 더해줌
                answer[list_p[i][j]]++;
            }
        }
    }
    

    return answer;
}
