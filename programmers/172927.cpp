#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    // minerals를 (dia, iron, ston) 각 갯수의 벡터로 환산 후 sort 
    // dia, iron, ston 곡괭이 순으로 하나씩 더해나가기 
    
    vector<vector<int>> mineral_vec;
    for (int i = 0; i < minerals.size(); i+=5) {
        // 5개씩 묶어서 더하기 
        vector<int> min_vec(3);
        for (int j = 0; j < 5 && i + j < minerals.size(); j++) { // 5까지 확인하기
            if (minerals[i+j] == "diamond") {
                min_vec[0]++;
            } else if (minerals[i+j] == "iron") {
                min_vec[1]++;                
            } else {
                min_vec[2]++;
            }
        }
        mineral_vec.push_back(min_vec);
    }
    
    // 앞에서부터 가능하므로.. 도려내기 
    int num_picks = accumulate(picks.begin(), picks.end(), 0);
    if (num_picks * 5 < minerals.size()) {
        mineral_vec.erase(mineral_vec.begin() + num_picks, mineral_vec.end());
    }
    
    vector<vector<int>> graph(3, vector<int>(3));
    graph[0][0] = 1;
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][0] = 5;
    graph[1][1] = 1;
    graph[1][2] = 1;
    graph[2][0] = 25;
    graph[2][1] = 5;
    graph[2][2] = 1;
    
    map<string, int> mineral_map;
    mineral_map["diamond"] = 0;
    mineral_map["iron"] = 1;
    mineral_map["stone"] = 2;

    sort(mineral_vec.begin(), mineral_vec.end(), [](vector<int> data1, vector<int> data2){
        if (data1[0] == data2[0]) {
            if (data1[1] == data2[1]) {
                return (data1[2] > data2[2]);
            }
            return (data1[1] > data2[1]);
        }
        return (data1[0] > data2[0]);
    }); // 내림차순 정렬
    
    
    int cost = 0;
    for (vector<int> min_vec : mineral_vec) {
        if (picks[0] > 0) {
            cost += graph[0][0] * min_vec[0];
            cost += graph[0][1] * min_vec[1];
            cost += graph[0][2] * min_vec[2];
            picks[0]--;
        } else if (picks[1] > 0) {
            cost += graph[1][0] * min_vec[0];
            cost += graph[1][1] * min_vec[1];
            cost += graph[1][2] * min_vec[2];
            picks[1]--;
        } else if (picks[2] > 0){
            cost += graph[2][0] * min_vec[0];
            cost += graph[2][1] * min_vec[1];
            cost += graph[2][2] * min_vec[2];
            picks[2]--;            
        } else {
            break;
        }
    }
    return cost;
}

// 백트래킹으로 하면 시간초과 나서 내림차순 정렬로 문제 해결.. 
// 백트래킹 시간초과 왜 나는지 확인 후 수정 예정.. 