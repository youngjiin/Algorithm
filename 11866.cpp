#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K; //1000
	cin >> N >> K;
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	cout << '<';

	vector<int>::iterator it = v.begin();
	int  i = 1;
	while (v.size() != 1) {
		if (i % K == 0) {
			cout << *it << ", ";
			it = v.erase(it);
			if (it == v.end()) it = v.begin();
		}
		else if (++it == v.end()) it = v.begin();
		i++;
	}
	cout << *it << '>';
	return 0;
}
