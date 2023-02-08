#include <iostream>
#include <queue>

using namespace std;

int n, m, result;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int graph[100][100];
int visited[100][100];

bool check(){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(graph[i][j] == 1){
				graph[i][j] = 1;
				cnt++;
			}
			else{
				graph[i][j] = 0;
			}
		}
	}
	if(cnt == 0) return false;
	return true;
}

int cnt_cheeses(){
    int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(graph[i][j] == 1) cnt++;
		}
	}
    return cnt;
}

void bfs(int pos_x, int pos_y){
	queue<pair<int, int>> q;
	q.push({pos_x, pos_y});
	graph[pos_x][pos_y] = -1;

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(graph[nx][ny] > 0) graph[nx][ny]++;
			else if(graph[nx][ny] == 0) {
				graph[nx][ny] = -1;
				q.push({nx, ny});
			}
		}
	}
}

int main(int argc, char** argv)
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> graph[i][j];
		}
	}

    int last = 0;
	while(check()){
        last = cnt_cheeses();
		bfs(0, 0);
		result++;
	}
	cout << result << '\n' << last << '\n';
	return 0;
}