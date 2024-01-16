#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& ladder, int max_depth, int height, int width, int count);
bool good_ladder(const vector<vector<int>>& ladder);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num_node, num_edge, height;
    cin >> num_node >> num_edge >> height;

    vector<vector<int>> ladder(height, vector<int>(num_node));
    for (int i = 0; i < num_edge; i++) {
        int hei, node;
        cin >> hei >> node;
        ladder[hei-1][node-1] = 1;
    }

    for (int max_depth = 0; max_depth <= 3; max_depth++) {
        dfs(ladder, max_depth, 0, 0, 0);
    }
    cout << -1 << '\n';
    return 0;
}

void dfs(vector<vector<int>>& ladder, int max_depth, int height, int width, int count) {
    if (count == max_depth) {
        if (good_ladder(ladder)) {
            cout << max_depth << '\n';
            exit(0);
        }
        return;
    }
    for (int h = height; h < ladder.size(); h++) {
        for (int w = 0; w < ladder[0].size()-1; w++) {  // 사이즈 줄일 수 있는거 최대한 줄이기
            if (ladder[h][w] == 0) {
                if (ladder[h][w+1] == 1 || (w > 0 && ladder[h][w-1] == 1)) {
                    continue;
                }
                ladder[h][w] = 1;
                dfs(ladder, max_depth, h, w, count+1);
                ladder[h][w] = 0;
            }
        }
    }
    return ;
}

bool good_ladder(const vector<vector<int>>& ladder) {
    int node_size = ladder[0].size();
    vector<int> nodes(node_size);
    for (int i = 0; i < node_size; i++) {
        nodes[i] = i;
    }

    for (int h = 0; h < ladder.size(); h++) {
        for (int w = 0; w <ladder[0].size()-1; w++) {
            if (ladder[h][w] == 1) {    // ladder[h][w] = w, w+1이 연결되어있음
                swap(nodes[w], nodes[w+1]);
            }
        }
    }

    for (int i = 0; i < node_size; i++) {
        if (nodes[i] != i) {
            return false;
        }
    }
    return true;
}
// 1. 매번 사다리가 조건맞는지 확인
// 2. 백트래킹 사용 -> cnt를 하나씩 늘려나감
// 3. 질문 : 비효율성 어디서 더 줄일 수 있는지