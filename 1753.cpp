#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& visited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num_verts, num_edges;
    cin >> num_verts >> num_edges;

    int start;
    cin >> start;
    
    vector<vector<pair<int, int>>> graph(num_verts+1);   // cost, vert
    vector<int> visited(num_verts+1, 1000000000);   // 초기 cost를 크게 잡기 
    for (int i = 0; i < num_edges; i++) {
        int vert1, vert2, cost;
        cin >> vert1 >> vert2 >> cost;
        graph[vert1].push_back(make_pair(cost, vert2));
    }

    dijkstra(start, graph, visited);

    for (int i = 1; i < visited.size(); i++) {
        if (visited[i] == 1000000000) {
            cout << "INF" << '\n';
        } else {
            cout << visited[i] << '\n';
        }
    }
    return 0;
}

void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& visited) {
    // queue에 담음
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijk_queue; // cost 기준 priority queue
    dijk_queue.push(make_pair(0, start));   // cost : 시작점으로부터의 거리
    visited[start] = 0;
    // 시작점부터 갈 수 있는 점들을 확인
    while (!dijk_queue.empty()) {
        pair<int, int> vert = dijk_queue.top(); // distance 기준
        dijk_queue.pop();
        int vert_cost = vert.first;
        int vert_node = vert.second;
        for (int i = 0; i < graph[vert_node].size(); i++) {
            pair<int, int> sub_vert = graph[vert_node][i];
            int sub_cost = sub_vert.first;
            int sub_node = sub_vert.second;
            if (sub_cost + vert_cost < visited[sub_node]) { // 초기 cost보다 작을 때에만 queue에 다시 넣는다
                visited[sub_node] = sub_cost + vert_cost;
                dijk_queue.push(make_pair(visited[sub_node], sub_node));
            }
        }
    }

}