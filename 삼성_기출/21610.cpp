#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int water[50][50];
int cloud_map[50][50];
vector<pair<int, int>> cloud;

void create_cloud(int x, int y){
    cloud.push_back({x, y});
}

void init_cloud(){
    create_cloud(n - 2, 0);
    create_cloud(n - 2, 1);
    create_cloud(n - 1, 0);
    create_cloud(n - 1, 1);
}

void move_cloud(int d, int s){
    int nx = (dx[d] * s) + (n * 50);
    int ny = (dy[d] * s) + (n * 50);
    for(int i = 0; i < cloud.size(); i++){
        cloud[i].first = (nx + cloud[i].first) % n;
        cloud[i].second = (ny + cloud[i].second) % n;
    }
}

void increase_water(){
    for(int i = 0; i < cloud.size(); i++){
        int x = cloud[i].first;
        int y = cloud[i].second;
        water[x][y]++;
    }
}

void delete_cloud(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cloud_map[i][j] = 0;
        }
    }
    for(int i = 0; i < cloud.size(); i++){
        int x = cloud[i].first;
        int y = cloud[i].second;
        cloud_map[x][y] = 1;
    }
    cloud.clear();
}

void copy_bug(){
    vector<pair<pair<int, int>, int>> increase_water;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cloud_map[i][j] == 1){
                int cnt = 0;
                for(int d = 1; d <= 8; d += 2){
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if(water[nx][ny] > 0) cnt++;
                }
                increase_water.push_back({{i, j}, cnt});
            }
        }
    }
    for(int i = 0; i < increase_water.size(); i++){
        int x = increase_water[i].first.first;
        int y = increase_water[i].first.second;
        int cost = increase_water[i].second;
        water[x][y] += cost;
    }
}

void generate_cloud(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(water[i][j] >= 2 && !cloud_map[i][j]){
                create_cloud(i, j);
                water[i][j] -= 2;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> water[i][j];
        }
    }

    init_cloud();
    for(int i = 0; i < m; i++){
        int d, s;
        cin >> d >> s;

        move_cloud(d - 1, s);
        increase_water();
        delete_cloud();
        copy_bug();
        generate_cloud();
    }

    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result += water[i][j];
        }
    }
    cout << result << '\n';
    return 0;
}