#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int bfs(vector<string>& maps, int start_h, int start_w, int end_h, int end_w);

int solution(vector<string> maps) {
    vector<int> start(2);
    vector<int> end(2);
    vector<int> lever(2);

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] == 'S') {
                start[0] = i;
                start[1] = j;
            } else if (maps[i][j] == 'E') {
                end[0] = i;
                end[1] = j;
            } else if (maps[i][j] == 'L') {
                lever[0] = i;
                lever[1] = j;
            }
        }
    }
    // lever 향해가기 
    int output1 = bfs(maps, start[0], start[1], lever[0], lever[1]);
    
    // end 향해가기 
    int output2 = bfs(maps, lever[0], lever[1], end[0], end[1]);
    if (output1 == -1 || output2 == -1) {
        return -1;
    } else {
        return output1 + output2;
    }
}

int bfs(vector<string>& maps, int start_h, int start_w, int end_h, int end_w) {
    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].length()));
    queue<vector<int>> bfs_queue;
    bfs_queue.push({start_h, start_w, 0});
    while (!bfs_queue.empty()) {
        vector<int> node = bfs_queue.front();
        bfs_queue.pop();
        if (node[0] == end_h && node[1] == end_w) {
            return node[2];
        }
        if (visited[node[0]][node[1]] == 1) {
            continue;
        }
        visited[node[0]][node[1]] = 1;
        vector<int> moving_h = {1, -1, 0, 0};
        vector<int> moving_w = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            int new_h = node[0] + moving_h[i];
            int new_w = node[1] + moving_w[i];
            if (0 > new_h || new_h >= maps.size() || 0 > new_w || new_w >= maps[0].size() || maps[new_h][new_w] == 'X') {
                continue;
            }
            bfs_queue.push({new_h, new_w, node[2]+1});
        }
    }
    return -1;
}




// 레버까지 bfs 후 
// 레버에서부터 출구까지 bfs