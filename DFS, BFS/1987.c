#include <stdio.h>

int graph[21][21];
int chk[26] = {0, };
int cnt, result;

// ╩С, го, аб, ©Л
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int compare(int x, int y) {
	if (x > y)
		return x;
	else
		return y;
}
void dfs(int x, int y, int n, int m) {
	int word = (int)graph[x][y] - 65;
	chk[word] = 1;

	// ╩С, го, аб, ©Л ╟к╩Г
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx <= -1 || ny <= -1 || nx >= n || ny >= m)
			continue;
		else {
			int tmp = (int)graph[nx][ny] - 65;

			if (chk[tmp] == 0) {
				cnt += 1;
				result = compare(result, cnt);
				dfs(nx, ny, n, m);
			}
		}
	}
	cnt -= 1;
	chk[word] = 0;
}
int main(void) {
	int n, m;
	char str[21];
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++)
			graph[i][j] = str[j];
	}

	dfs(0, 0, n, m);
	printf("%d\n", result + 1);
}