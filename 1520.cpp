#include <iostream>
using namespace std;

int map[500][500];
int dp[500][500];
bool visit[500][500];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n, m;

int dfs(int x, int y) {
	if (x == 0 && y == 0) return dp[0][0];
	if (visit[x][y]) return dp[x][y];

	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		if ((x + dx[i]) < n && (y + dy[i]) < m && (x + dx[i]) >= 0 && (y + dy[i]) >= 0) {
			if (map[x][y] < map[x+dx[i]][y+dy[i]]) {
				dp[x][y] += dfs(x + dx[i],y + dy[i]);
			}
		}
	}

	return dp[x][y];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			dp[i][j] = 0;
			visit[i][j] = false;
		}
	}
	dp[0][0] = 1;
    cout << dfs(n-1,m-1);
	return 0;
}
