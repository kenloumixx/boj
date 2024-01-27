#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int bfs(vector<string>& maps, vector<vector<int>>& visited, int h, int w);

vector<int> solution(vector<string> maps) {
    vector<vector<int>> visited((int)maps.size(), vector<int>((int)maps[0].length()));
    vector<int> answer;
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].length(); j++) {
            if (maps[i][j] != 'X' && visited[i][j] == 0) {
                answer.push_back(bfs(maps, visited, i, j));
            }
        }
    }
    if (answer.size() == 0) {
        vector<int> zero = {-1};
        return zero;
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int bfs(vector<string>& maps, vector<vector<int>>& visited, int h, int w) {
    queue<vector<int>> bfs_queue; // h, w, acc_cost;
    bfs_queue.push({h, w});
    int total_cost = 0;
    while (!bfs_queue.empty()) {
        vector<int> node = bfs_queue.front();
        bfs_queue.pop();
        int node_h = node[0];
        int node_w = node[1];
        if (visited[node_h][node_w] == 1) {
            continue;
        }
        visited[node_h][node_w] = 1;
        total_cost += maps[node_h][node_w]-'0';
        vector<int> move_h = {1, -1, 0, 0};
        vector<int> move_w = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            int new_h = node_h + move_h[i];
            int new_w = node_w + move_w[i];
            if (0 > new_h || new_h >= maps.size() || 0 > new_w || new_w >= maps[0].length() || maps[new_h][new_w] == 'X') {
                continue;
            }
            bfs_queue.push({new_h, new_w});
        }
    }
    return total_cost;
}



// 이동조건 : X가 아니고 visited에 없을 때 bfs 실행 