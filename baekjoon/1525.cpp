#include <iostream>
#include <unordered_map>
#include <queue>
#include <math.h>
using namespace std;

int ans_puzzle =123456789;
int false_puzzle =123456870;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int check(int tmp_puzzle){
	if(tmp_puzzle == ans_puzzle) return -1;
	if(tmp_puzzle == false_puzzle) return -2;
	int i=0;
	while(tmp_puzzle%10 !=9){
		tmp_puzzle /= 10;
		i++;
	}
	return i;
}

int main(){
	unordered_map<int, int> hash;
	queue<int> q;
	int tmp;
	int puzzle =0;
	for(int i=0; i<9; i++){
		cin >> tmp;
		if(tmp ==0) tmp =9;
		puzzle = puzzle*10 + tmp;
	}
	
	q.push(puzzle);
	hash[puzzle]=0;
	int tmp_puzzle;
	while(!q.empty()){
		tmp_puzzle = q.front();
		q.pop();

		int index = check(tmp_puzzle); 
		if(index==-1)break;
		if(index==-1)break;
		int tmp_i = 2-(index/3);
		int tmp_j = 2-(index%3);
		
		for(int i=0; i<4; i++){
			int cx = tmp_i+dx[i];
			int cy = tmp_j+dy[i];
			if(cx >=0 && cx<3 && cy>=0 && cy<3){
				int future = (2-cx)*3 + (2-cy);
				int pow_future = pow(10,future);
				int pow_index = pow(10,index);
				tmp = tmp_puzzle/pow_future;
				tmp %= 10;
				int future_puzzle = tmp_puzzle - tmp*pow_future + 9*pow_future - 9*pow_index + tmp*pow_index;
				if(hash.find(future_puzzle) == hash.end()){
					hash[future_puzzle] = hash[tmp_puzzle]+1;
					q.push(future_puzzle);
				}
			}
		}

	}
	if(tmp_puzzle==ans_puzzle)
		cout << hash[tmp_puzzle] << endl;
	else
		cout << -1 << endl;
	return 0;
}
