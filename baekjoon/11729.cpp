#include <iostream>
using namespace std;

void hanoi(int N, int start, int to, int via) {
	if (N == 1) {
		cout << start << ' ' << to << '\n';
	    return;
    }
    hanoi(N - 1, start, via, to);
	cout << start << ' ' << to << '\n';
	hanoi(N - 1, via, to, start);
}

int main() {
	int n;
	cin >> n;
    cout << (1<<n)-1 <<'\n';
	hanoi(n,1,3,2);
	return 0;
}
