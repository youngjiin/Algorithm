#include <iostream>
#include <unordered_map>
#include <string>
#define MAX_N 100001
using namespace std;
string index[MAX_N];
int main() {
	int N, M;
	cin >> N >> M;
	unordered_map<string, int> hash_s;
	
	for (int i = 1; i <= N; i++) {
		char tmp[20];
		scanf("%s", tmp);
		string s(tmp);
		hash_s.insert({ s, i });
		index[i] = s;
	}
	for (int i = 0; i < M; i++) {
		char tmp[20];
		scanf("%s", tmp);
		string s(tmp);
		if (isdigit(s[0])) {
			cout << index[stoi(s)] << "\n";
		}
		else {
			cout << hash_s[s] << "\n";
		}
	}
	return 0;
}
